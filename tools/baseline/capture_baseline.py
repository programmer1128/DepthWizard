#!/usr/bin/env python3
"""Capture a reproducible baseline of DepthWizard outputs for frozen fixtures.

Two input modes:
  backend    upload each fixture to a running backend, wait for its raster
             exports, and download the GLB, rasters and building index;
  artifacts  inspect outputs already on disk (<dir>/<fixture>/mesh.glb,
             heights.tif, dtm.tif, ndsm.tif, confidence.tif, buildings.tif,
             buildings.json, summary.json), without a backend.

For every fixture it records artifact hashes, a deterministic GLB report,
raster reports (pixel digests), Khronos glTF validation and, when a viewer
URL is given, fixed-camera screenshots. compare_baselines.py diffs two
captures.

Examples:
  capture_baseline.py --label before-phase2 --backend http://127.0.0.1:8081 \\
      --diagnostics-dir ~/Desktop/DepthWizard/drogon_service/gis_service/build-integration/reconstruction_diagnostics \\
      --viewer http://localhost:5173
  capture_baseline.py --label offline --artifacts ./saved_outputs
"""

import argparse
import datetime
import json
import os
import platform
import shutil
import sys
import time
import urllib.error
import urllib.request
import uuid as uuidlib
from pathlib import Path

import baseline_lib as lib


def upload(backend, image_path, timeout):
    boundary = f"----DepthWizardBaseline{uuidlib.uuid4().hex}"
    data = Path(image_path).read_bytes()
    body = (f"--{boundary}\r\nContent-Disposition: form-data; name=\"image\"; "
            f"filename=\"{Path(image_path).name}\"\r\nContent-Type: image/tiff\r\n\r\n").encode()
    body += data + f"\r\n--{boundary}--\r\n".encode()
    request = urllib.request.Request(
        f"{backend.rstrip('/')}/api/v1/processor", data=body, method="POST",
        headers={"Content-Type": f"multipart/form-data; boundary={boundary}"})
    started = time.monotonic()
    with urllib.request.urlopen(request, timeout=timeout) as response:
        result = json.loads(response.read())
    return result, time.monotonic() - started


def download(url, target, timeout=300):
    with urllib.request.urlopen(url, timeout=timeout) as response, open(target, "wb") as handle:
        shutil.copyfileobj(response, handle)


def wait_for_exports(backend, job, timeout):
    deadline = time.monotonic() + timeout
    url = f"{backend.rstrip('/')}/api/v1/processor/exports/{job}"
    while True:
        with urllib.request.urlopen(url, timeout=60) as response:
            status = json.loads(response.read())
        if status.get("status") in ("ready", "failed") or time.monotonic() > deadline:
            return status
        time.sleep(3)


def collect_from_backend(args, fixture, source, work, record):
    result, seconds = upload(args.backend, source, args.upload_timeout)
    record["uuid"] = result.get("uuid")
    record["timings_s"] = {"upload_to_glb_url": round(seconds, 3)}
    if not result.get("glb_url"):
        raise RuntimeError(f"backend returned no glb_url: {result}")
    download(result["glb_url"], work / "mesh.glb")

    started = time.monotonic()
    status = wait_for_exports(args.backend, record["uuid"], args.export_timeout)
    record["timings_s"]["exports"] = round(time.monotonic() - started, 3)
    record["export_status"] = {k: v for k, v in status.items() if not k.endswith("_url")}
    for key, name in lib.EXPORT_URLS.items():
        if status.get(key):
            download(status[key], work / name)

    if args.diagnostics_dir and record["uuid"]:
        summary = lib.expand(args.diagnostics_dir) / record["uuid"] / "summary.json"
        deadline = time.monotonic() + 60  # written by the same background worker
        while not summary.exists() and time.monotonic() < deadline:
            time.sleep(2)
        if summary.exists():
            shutil.copy(summary, work / "summary.json")


def collect_from_artifacts(args, fixture, work, record):
    source_dir = lib.expand(args.artifacts) / fixture["name"]
    if not source_dir.is_dir():
        raise FileNotFoundError(f"no artifacts directory {source_dir}")
    for name in ["mesh.glb", "summary.json", *lib.EXPORT_URLS.values()]:
        if (source_dir / name).exists():
            shutil.copy(source_dir / name, work / name)
    record["uuid"] = None


def analyse(args, work, record):
    reports = work / "reports"
    reports.mkdir(exist_ok=True)
    record["artifacts"] = {p.name: lib.sha256_file(p) for p in sorted(work.iterdir())
                           if p.is_file() and p.name != "record.json"}

    glb = work / "mesh.glb"
    if glb.exists():
        lib.write_json(reports / "glb.json", lib.inspect(args.inspect, "glb", glb))
        if lib.node_tools_available():
            validation = lib.node_tool("validate_glb.mjs", glb)
            lib.write_json(reports / "gltf_validation.json", validation)
            record["gltf_validation"] = {k: validation[k] for k in ("errors", "warnings", "infos", "validator")}
        else:
            record["gltf_validation"] = {"status": "unavailable",
                                         "reason": "run npm ci in tools/baseline/node"}
    for product in (*lib.SCIENTIFIC_PRODUCTS, *lib.GEOMETRY_PRODUCTS):
        raster = work / f"{product}.tif"
        if raster.exists():
            lib.write_json(reports / f"{product}.json", lib.inspect(args.inspect, "raster", raster))

    if args.viewer and glb.exists():
        if not lib.node_tools_available():
            record["screenshots"] = {"status": "unavailable", "reason": "node tools not installed"}
        else:
            shots = lib.node_tool("screenshot.mjs", "--viewer", args.viewer, "--glb", glb,
                                  "--out", work / "screenshots", "--cameras", args.cameras,
                                  "--chrome", args.chrome, timeout=args.screenshot_timeout)
            record["screenshots"] = shots
    else:
        record["screenshots"] = {"status": "skipped", "reason": "no --viewer given"}


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument("--label", required=True, help="name of this baseline (directory under --out-root)")
    parser.add_argument("--out-root", default=str(lib.REPO / "baselines"))
    parser.add_argument("--fixtures", default=str(lib.HERE / "fixtures.json"))
    parser.add_argument("--only", help="comma-separated fixture names")
    mode = parser.add_mutually_exclusive_group(required=True)
    mode.add_argument("--backend", help="backend base URL, e.g. http://127.0.0.1:8081")
    mode.add_argument("--artifacts", help="directory of saved outputs, one subdirectory per fixture")
    parser.add_argument("--diagnostics-dir", help="backend DEPTHWIZARD_DIAGNOSTICS_DIR, to copy summary.json")
    parser.add_argument("--viewer", help="running frontend URL for screenshots, e.g. http://localhost:5173")
    parser.add_argument("--cameras", default="overview,oblique,top")
    parser.add_argument("--chrome", default="/usr/bin/google-chrome")
    parser.add_argument("--inspect", default=str(lib.DEFAULT_INSPECT), help="baseline_inspect binary")
    parser.add_argument("--upload-timeout", type=float, default=1500)
    parser.add_argument("--export-timeout", type=float, default=600)
    parser.add_argument("--screenshot-timeout", type=float, default=900)
    parser.add_argument("--frontend-repo", default="~/Desktop/frontend_service")
    parser.add_argument("--sat2lod2-repo", default="~/LOD2BuildingModel")
    args = parser.parse_args()

    if not Path(args.inspect).exists():
        sys.exit(f"baseline_inspect not found at {args.inspect}; build it: "
                 "cmake --build drogon_service/gis_service/build-integration --target baseline_inspect")

    out = lib.expand(args.out_root) / args.label
    if out.exists():
        sys.exit(f"{out} already exists; choose a new --label")
    out.mkdir(parents=True)

    fixtures = lib.load_json(args.fixtures)["fixtures"]
    wanted = set(args.only.split(",")) if args.only else None
    summary = []
    for fixture in fixtures:
        if wanted and fixture["name"] not in wanted:
            continue
        work = out / fixture["name"]
        work.mkdir()
        record = {"fixture": fixture, "mode": "backend" if args.backend else "artifacts"}
        try:
            if fixture.get("status") != "available" or not fixture.get("source"):
                raise LookupError(f"fixture slot is {fixture.get('status')}; curate a source first")
            source = lib.expand(fixture["source"])
            if not source.exists():
                raise FileNotFoundError(f"source {source} not found")
            actual = lib.sha256_file(source)
            record["source_sha256"] = actual
            if fixture.get("sha256") and actual != fixture["sha256"]:
                raise ValueError(f"source changed: sha256 {actual} != manifest {fixture['sha256']}")
            if args.backend:
                collect_from_backend(args, fixture, source, work, record)
            else:
                collect_from_artifacts(args, fixture, work, record)
            analyse(args, work, record)
            record["status"] = "captured"
        except (LookupError, FileNotFoundError) as error:
            record["status"] = "skipped"
            record["reason"] = str(error)
        except (urllib.error.URLError, RuntimeError, ValueError, OSError) as error:
            record["status"] = "error"
            record["reason"] = str(error)
        lib.write_json(work / "record.json", record)
        summary.append({"fixture": fixture["name"], "status": record["status"],
                        "reason": record.get("reason")})
        print(f"{fixture['name']:28s} {record['status']:9s} {record.get('reason') or ''}")

    lib.write_json(out / "baseline.json", {
        "schema": "depthwizard.baseline.capture.v1",
        "label": args.label,
        "created_utc": datetime.datetime.now(datetime.timezone.utc).isoformat(timespec="seconds"),
        "mode": "backend" if args.backend else "artifacts",
        "backend": args.backend,
        "git": {
            "depthwizard": lib.git_state(lib.REPO),
            "frontend": lib.git_state(args.frontend_repo),
            "sat2lod2": lib.git_state(args.sat2lod2_repo),
        },
        # The backend reads its own environment; this records the capture
        # shell's. Start the backend with the same values, and check its log
        # line "feature flags: ..." for the configuration it actually used.
        "flags_in_capture_environment": {name: os.environ.get(name) for name in lib.FLAG_VARIABLES},
        "tools": {
            "baseline_inspect_sha256": lib.sha256_file(args.inspect),
            "python": platform.python_version(),
            "node_tools": lib.node_tools_available(),
        },
        "fixtures": summary,
    })
    print(f"baseline written to {out}")
    return 0 if all(item["status"] != "error" for item in summary) else 1


if __name__ == "__main__":
    sys.exit(main())
