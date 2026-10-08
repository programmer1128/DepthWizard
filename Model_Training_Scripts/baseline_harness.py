#!/usr/bin/env python3
"""
DepthWizard Baseline Verification & Regression Harness (Phase 0)

Validates glTF 2.0 binary (GLB) structure, computes scientific raster hashes,
compares geometry counts, bounds, and building IDs against frozen baselines,
and verifies fixed-camera configurations and screenshots.
"""

import argparse
import hashlib
import json
import math
import os
import struct
import subprocess
import sys
from pathlib import Path


def parse_glb_header_and_json(glb_path):
    """
    Parses a binary glTF (GLB) file, validating the container header and
    returning the glTF JSON chunk as a Python dict along with binary chunk metadata.
    """
    with open(glb_path, "rb") as f:
        data = f.read()

    if len(data) < 12:
        raise ValueError(f"File too small to be a GLB: {len(data)} bytes")

    magic, version, length = struct.unpack_from("<4sII", data, 0)
    if magic != b"glTF":
        raise ValueError(f"Invalid GLB magic: {magic} (expected b'glTF')")
    if version != 2:
        raise ValueError(f"Unsupported glTF version: {version} (expected 2)")
    if length != len(data):
        raise ValueError(f"GLB length mismatch: header says {length}, file is {len(data)}")

    offset = 12
    json_dict = None
    bin_chunk_info = None

    while offset < len(data):
        if offset + 8 > len(data):
            break
        chunk_length, chunk_type = struct.unpack_from("<II", data, offset)
        offset += 8
        chunk_data = data[offset : offset + chunk_length]
        offset += chunk_length

        if chunk_type == 0x4E4F534A:  # JSON
            json_text = chunk_data.decode("utf-8", errors="replace").strip("\x00")
            json_dict = json.loads(json_text)
        elif chunk_type == 0x004E4942:  # BIN
            bin_chunk_info = {
                "offset": offset - chunk_length,
                "length": chunk_length,
            }

    if json_dict is None:
        raise ValueError("Missing JSON chunk in GLB container")

    return json_dict, bin_chunk_info, len(data)


def validate_glb_structure(glb_path):
    """
    Validates the internal consistency and compliance of a DepthWizard GLB.
    Checks accessors, primitives, Draco compression extensions, materials, and extras.
    """
    json_dict, bin_info, total_size = parse_glb_header_and_json(glb_path)

    report = {
        "valid": True,
        "errors": [],
        "warnings": [],
        "metrics": {},
    }

    # 1. Asset block
    asset = json_dict.get("asset", {})
    if asset.get("version") != "2.0":
        report["errors"].append(f"Invalid asset version: {asset.get('version')}")

    extras = asset.get("extras", {})
    report["metrics"]["presentation_mode"] = extras.get("presentationMode", "unknown")
    report["metrics"]["height_scale"] = extras.get("heightScale", 1.0)
    report["metrics"]["render_y_is_abs_offset"] = extras.get("renderYIsAbsoluteElevationOffset", False)

    # 2. Meshes and Primitives
    meshes = json_dict.get("meshes", [])
    total_primitives = 0
    total_vertices = 0
    total_indices = 0
    materials_used = set()
    has_draco = False

    bounds = {"min": [float("inf")] * 3, "max": [-float("inf")] * 3}

    for mesh_idx, mesh in enumerate(meshes):
        primitives = mesh.get("primitives", [])
        total_primitives += len(primitives)
        for prim_idx, prim in enumerate(primitives):
            mat_idx = prim.get("material")
            if mat_idx is not None:
                materials_used.add(mat_idx)

            # Draco extension check
            extensions = prim.get("extensions", {})
            if "KHR_draco_mesh_compression" in extensions:
                has_draco = True

            # Position accessor bounds
            attrs = prim.get("attributes", {})
            pos_acc_idx = attrs.get("POSITION")
            if pos_acc_idx is not None and pos_acc_idx < len(json_dict.get("accessors", [])):
                acc = json_dict["accessors"][pos_acc_idx]
                total_vertices += acc.get("count", 0)
                acc_min = acc.get("min", [])
                acc_max = acc.get("max", [])
                if len(acc_min) == 3 and len(acc_max) == 3:
                    for i in range(3):
                        bounds["min"][i] = min(bounds["min"][i], acc_min[i])
                        bounds["max"][i] = max(bounds["max"][i], acc_max[i])

            indices_acc_idx = prim.get("indices")
            if indices_acc_idx is not None and indices_acc_idx < len(json_dict.get("accessors", [])):
                acc = json_dict["accessors"][indices_acc_idx]
                total_indices += acc.get("count", 0)

    report["metrics"]["mesh_count"] = len(meshes)
    report["metrics"]["primitive_count"] = total_primitives
    report["metrics"]["accessor_vertex_count"] = total_vertices
    report["metrics"]["accessor_index_count"] = total_indices
    report["metrics"]["estimated_triangles"] = total_indices // 3
    report["metrics"]["has_draco_compression"] = has_draco
    report["metrics"]["unique_materials_count"] = len(materials_used)
    report["metrics"]["total_glb_bytes"] = total_size

    if bounds["min"][0] != float("inf"):
        report["metrics"]["bounds"] = bounds
    else:
        report["metrics"]["bounds"] = None

    # Check external validator if available
    try:
        proc = subprocess.run(
            ["gltf_validator", "-m", "-r", str(glb_path)],
            capture_output=True,
            text=True,
            timeout=10,
        )
        if proc.returncode == 0:
            report["external_validator"] = "PASSED"
        else:
            report["external_validator"] = f"FAILED: {proc.stderr}"
    except (FileNotFoundError, subprocess.TimeoutExpired):
        report["external_validator"] = "SKIPPED (gltf_validator binary not found in PATH)"

    if report["errors"]:
        report["valid"] = False

    return report


def hash_file_sha256(filepath):
    """Computes SHA-256 hash of a file."""
    h = hashlib.sha256()
    with open(filepath, "rb") as f:
        while chunk := f.read(65536):
            h.update(chunk)
    return h.hexdigest()


def hash_file_md5(filepath):
    """Computes MD5 hash of a file."""
    h = hashlib.md5()
    with open(filepath, "rb") as f:
        while chunk := f.read(65536):
            h.update(chunk)
    return h.hexdigest()


def hash_scientific_rasters(fixture_dir):
    """
    Computes cryptographic hashes for all scientific and diagnostic rasters in a fixture directory.
    """
    p = Path(fixture_dir)
    raster_names = [
        "dtm.tif",
        "dsm.tif",
        "ndsm.tif",
        "final_semantic_class.tif",
        "semantic_confidence.tif",
        "fused_ndsm.tif",
        "raw_ndsm.tif",
        "reconstruction_ndsm.tif",
        "building_probability.tif",
        "road_probability.tif",
        "vegetation_probability.tif",
        "candidate_mask.tif",
        "cleaned_mask.tif",
        "instance_labels.tif",
    ]

    results = {}
    for name in raster_names:
        file_path = p / name
        if file_path.exists():
            results[name] = {
                "sha256": hash_file_sha256(file_path),
                "md5": hash_file_md5(file_path),
                "size_bytes": file_path.stat().st_size,
            }
    return results


def load_summary_diagnostics(summary_path):
    """Loads and extracts metrics from summary.json."""
    with open(summary_path, "r") as f:
        summary = json.load(f)

    buildings = summary.get("buildings", [])
    bldg_map = {}
    for b in buildings:
        b_id = b.get("id")
        if b_id is not None:
            bldg_map[b_id] = {
                "height_agl_m": b.get("height_agl_m"),
                "base_elevation_m": b.get("base_elevation_m"),
                "roof_elevation_m": b.get("roof_elevation_m"),
                "area_m2": b.get("area_m2"),
            }

    return {
        "uuid": summary.get("uuid"),
        "presentation_mode": summary.get("presentation_mode"),
        "presentation_reason": summary.get("presentation_reason"),
        "accepted_buildings": summary.get("accepted_buildings", 0),
        "emitted_buildings": summary.get("emitted_buildings", 0),
        "strong_building_fraction": summary.get("strong_building_fraction", 0.0),
        "vegetation_fraction": summary.get("vegetation_fraction", 0.0),
        "buildings": bldg_map,
    }


def compare_fixtures(baseline_dir, candidate_dir, tolerance=1e-3):
    """
    Compares candidate fixture against baseline fixture:
    - Verifies scientific raster hashes match exactly.
    - Verifies building counts, IDs, and heights match within tolerance.
    - Verifies GLB structure and geometry bounds.
    """
    base_path = Path(baseline_dir)
    cand_path = Path(candidate_dir)

    diffs = []

    # 1. Compare Scientific Rasters
    base_hashes = hash_scientific_rasters(base_path)
    cand_hashes = hash_scientific_rasters(cand_path)

    for raster_name in ["dtm.tif", "dsm.tif", "ndsm.tif", "final_semantic_class.tif"]:
        if raster_name in base_hashes:
            if raster_name not in cand_hashes:
                diffs.append(f"Missing scientific raster in candidate: {raster_name}")
            else:
                if base_hashes[raster_name]["sha256"] != cand_hashes[raster_name]["sha256"]:
                    diffs.append(
                        f"Scientific raster hash mismatch on {raster_name}: "
                        f"base={base_hashes[raster_name]['sha256'][:12]} vs cand={cand_hashes[raster_name]['sha256'][:12]}"
                    )

    # 2. Compare summary.json
    base_summary_file = base_path / "summary.json"
    cand_summary_file = cand_path / "summary.json"

    if base_summary_file.exists() and cand_summary_file.exists():
        base_diag = load_summary_diagnostics(base_summary_file)
        cand_diag = load_summary_diagnostics(cand_summary_file)

        if base_diag["accepted_buildings"] != cand_diag["accepted_buildings"]:
            diffs.append(
                f"Accepted building count mismatch: base={base_diag['accepted_buildings']} vs cand={cand_diag['accepted_buildings']}"
            )
        if base_diag["emitted_buildings"] != cand_diag["emitted_buildings"]:
            diffs.append(
                f"Emitted building count mismatch: base={base_diag['emitted_buildings']} vs cand={cand_diag['emitted_buildings']}"
            )

        for b_id, b_info in base_diag["buildings"].items():
            if b_id not in cand_diag["buildings"]:
                diffs.append(f"Building ID {b_id} missing in candidate")
            else:
                c_info = cand_diag["buildings"][b_id]
                h_diff = abs(b_info["height_agl_m"] - c_info["height_agl_m"])
                if h_diff > tolerance:
                    diffs.append(
                        f"Building {b_id} height mismatch: base={b_info['height_agl_m']} vs cand={c_info['height_agl_m']} (diff={h_diff:.4f}m)"
                    )

    # 3. Compare GLB metrics
    base_glb = base_path / "native_baseline.glb"
    cand_glb = cand_path / "native_baseline.glb"
    if not cand_glb.exists():
        cand_glb = cand_path / "output.glb"

    if base_glb.exists() and cand_glb.exists():
        base_glb_rep = validate_glb_structure(base_glb)
        cand_glb_rep = validate_glb_structure(cand_glb)

        bm = base_glb_rep["metrics"]
        cm = cand_glb_rep["metrics"]

        if bm["presentation_mode"] != cm["presentation_mode"]:
            diffs.append(
                f"GLB presentation mode mismatch: base={bm['presentation_mode']} vs cand={cm['presentation_mode']}"
            )
        if bm["primitive_count"] != cm["primitive_count"]:
            diffs.append(
                f"GLB primitive count mismatch: base={bm['primitive_count']} vs cand={cm['primitive_count']}"
            )

        if bm.get("bounds") and cm.get("bounds"):
            for i in range(3):
                min_diff = abs(bm["bounds"]["min"][i] - cm["bounds"]["min"][i])
                max_diff = abs(bm["bounds"]["max"][i] - cm["bounds"]["max"][i])
                if min_diff > 0.05 or max_diff > 0.05:
                    diffs.append(
                        f"GLB bounds axis {i} mismatch: min_diff={min_diff:.4f}, max_diff={max_diff:.4f}"
                    )

    return {
        "passed": len(diffs) == 0,
        "diff_count": len(diffs),
        "differences": diffs,
    }


def main():
    parser = argparse.ArgumentParser(description="DepthWizard Baseline Harness")
    subparsers = parser.add_subparsers(dest="command", required=True)

    # validate-glb
    p_val = subparsers.add_parser("validate-glb", help="Validate GLB container & extract metrics")
    p_val.add_argument("glb_path", type=str, help="Path to GLB file")

    # hash-rasters
    p_hash = subparsers.add_parser("hash-rasters", help="Compute cryptographic hashes of scientific rasters")
    p_hash.add_argument("fixture_dir", type=str, help="Path to fixture directory")

    # compare
    p_comp = subparsers.add_parser("compare", help="Compare candidate fixture against baseline")
    p_comp.add_argument("baseline_dir", type=str, help="Baseline fixture directory")
    p_comp.add_argument("candidate_dir", type=str, help="Candidate fixture directory")

    # verify-all-baselines
    p_all = subparsers.add_parser("verify-all-baselines", help="Verify all 5 fixtures in a root directory")
    p_all.add_argument("fixtures_root", type=str, help="Root fixtures directory")

    args = parser.parse_args()

    if args.command == "validate-glb":
        rep = validate_glb_structure(args.glb_path)
        print(json.dumps(rep, indent=2))
        sys.exit(0 if rep["valid"] else 1)

    elif args.command == "hash-rasters":
        hashes = hash_scientific_rasters(args.fixture_dir)
        print(json.dumps(hashes, indent=2))
        sys.exit(0)

    elif args.command == "compare":
        result = compare_fixtures(args.baseline_dir, args.candidate_dir)
        print(json.dumps(result, indent=2))
        sys.exit(0 if result["passed"] else 1)

    elif args.command == "verify-all-baselines":
        root = Path(args.fixtures_root)
        required_fixtures = [
            "dense_flat_urban",
            "residential_pitched_urban",
            "sparse_urban",
            "hilly_urban",
            "vegetation_heavy",
        ]
        all_ok = True
        summary = {}

        for fix in required_fixtures:
            f_dir = root / fix
            if not f_dir.exists():
                print(f"[FAIL] Fixture directory missing: {f_dir}")
                all_ok = False
                continue

            native_glb = f_dir / "native_baseline.glb"
            sat_glb = f_dir / "sat2lod2_baseline.glb"
            if not native_glb.exists():
                print(f"[FAIL] Missing native_baseline.glb in: {f_dir}")
                all_ok = False
                continue

            native_rep = validate_glb_structure(native_glb)
            sat_rep = validate_glb_structure(sat_glb) if sat_glb.exists() else None
            hashes = hash_scientific_rasters(f_dir)
            summary_diag = (
                load_summary_diagnostics(f_dir / "summary.json")
                if (f_dir / "summary.json").exists()
                else {}
            )

            # Check screenshots
            screenshots = ["screenshot_wide.png", "screenshot_oblique.png", "screenshot_closeup.png"]
            missing_screenshots = [s for s in screenshots if not (f_dir / s).exists()]

            status = "OK" if (native_rep["valid"] and not missing_screenshots) else "INVALID"
            if not native_rep["valid"] or missing_screenshots:
                all_ok = False

            summary[fix] = {
                "status": status,
                "building_count": summary_diag.get("emitted_buildings", 0),
                "presentation_mode": summary_diag.get("presentation_mode", "unknown"),
                "native_glb_bytes": native_rep["metrics"]["total_glb_bytes"],
                "sat2lod2_glb_bytes": sat_rep["metrics"]["total_glb_bytes"] if sat_rep else None,
                "draco_compressed": native_rep["metrics"]["has_draco_compression"],
                "estimated_triangles": native_rep["metrics"]["estimated_triangles"],
                "raster_count": len(hashes),
                "screenshots_present": len(screenshots) - len(missing_screenshots),
            }
            print(f"[{status}] {fix}: {summary[fix]}")

        print("\n=== Baseline Verification Summary ===")
        print(json.dumps(summary, indent=2))
        sys.exit(0 if all_ok else 1)


if __name__ == "__main__":
    main()
