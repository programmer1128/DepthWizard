#!/usr/bin/env python3
"""Compare two baselines captured by capture_baseline.py.

Every difference is classified:
  science     DSM/DTM/nDSM/confidence pixels or georeferencing changed;
              rendering work must never cause this.
  geometry    GLB primitives, counts, bounds, materials, building IDs or the
              building label raster changed.
  validation  more glTF validator errors than the base.
  render      fixed-camera screenshots differ beyond the thresholds.

Exit status is 1 when a class that is not explicitly allowed changed, so a
phase can gate on e.g. --allow-geometry-change --allow-render-change while
still guaranteeing unchanged science.

Example:
  compare_baselines.py baselines/before-phase2 baselines/after-phase2 --allow-render-change
"""

import argparse
import sys
from pathlib import Path

import baseline_lib as lib

CLASSES = ("science", "geometry", "validation", "render")


def load(path):
    path = Path(path)
    return lib.load_json(path) if path.exists() else None


def compare_raster(base, candidate):
    if base is None or candidate is None:
        return [] if base is candidate else ["present in only one baseline"]
    findings = []
    for key in ("width", "height", "geotransform", "crs_sha256"):
        if base.get(key) != candidate.get(key):
            findings.append(f"{key}: {base.get(key)} -> {candidate.get(key)}")
    for index, (a, b) in enumerate(zip(base.get("bands", []), candidate.get("bands", []))):
        if a.get("pixel_sha256") != b.get("pixel_sha256"):
            findings.append(f"band {index + 1} pixels changed (valid {a.get('valid_pixels')} -> "
                            f"{b.get('valid_pixels')}, mean {a.get('mean')} -> {b.get('mean')})")
    if len(base.get("bands", [])) != len(candidate.get("bands", [])):
        findings.append("band count changed")
    return findings


def bounds_differ(a, b, tolerance):
    if a is None or b is None:
        return a is not b
    return any(abs(x - y) > tolerance
               for key in ("min", "max") for x, y in zip(a[key], b[key]))


def compare_glb(base, candidate, tolerance):
    if base is None or candidate is None:
        return [] if base is candidate else ["GLB present in only one baseline"]
    findings = []
    for key in ("counts", "extensions_used", "extensions_required", "images"):
        if base.get(key) != candidate.get(key):
            findings.append(f"{key}: {base.get(key)} -> {candidate.get(key)}")
    base_primitives, candidate_primitives = base["primitives"], candidate["primitives"]
    if len(base_primitives) != len(candidate_primitives):
        findings.append(f"primitive count {len(base_primitives)} -> {len(candidate_primitives)}")
    for a, b in zip(base_primitives, candidate_primitives):
        label = f"primitive {a['mesh']}.{a['primitive']}"
        for key in ("mode", "draco", "attributes", "vertex_count", "index_count",
                    "triangle_count", "line_count", "material"):
            if a.get(key) != b.get(key):
                findings.append(f"{label} {key}: {a.get(key)} -> {b.get(key)}")
        if bounds_differ(a.get("bounds"), b.get("bounds"), tolerance):
            findings.append(f"{label} bounds: {a.get('bounds')} -> {b.get('bounds')}")
    for key in ("vertices", "triangles", "lines"):
        if base["totals"].get(key) != candidate["totals"].get(key):
            findings.append(f"total {key}: {base['totals'].get(key)} -> {candidate['totals'].get(key)}")
    if bounds_differ(base["totals"].get("bounds"), candidate["totals"].get("bounds"), tolerance):
        findings.append(f"scene bounds: {base['totals'].get('bounds')} -> {candidate['totals'].get('bounds')}")
    removed = sorted(set(base["building_ids"]) - set(candidate["building_ids"]))
    added = sorted(set(candidate["building_ids"]) - set(base["building_ids"]))
    if removed or added:
        findings.append(f"building IDs: {len(removed)} removed {removed[:10]}, {len(added)} added {added[:10]}")
    return findings


def compare_screenshots(base_dir, candidate_dir, mean_threshold, fraction_threshold):
    findings, notes = [], []
    base_shots = {p.name: p for p in (base_dir / "screenshots").glob("*.png")}
    candidate_shots = {p.name: p for p in (candidate_dir / "screenshots").glob("*.png")}
    if not base_shots and not candidate_shots:
        return findings, ["no screenshots in either baseline"]
    if not lib.node_tools_available():
        return findings, ["node tools unavailable; screenshots not compared"]
    for name in sorted(set(base_shots) | set(candidate_shots)):
        if name not in base_shots or name not in candidate_shots:
            findings.append(f"{name}: present in only one baseline")
            continue
        diff = lib.node_tool("image_diff.mjs", base_shots[name], candidate_shots[name])
        if not diff.get("comparable"):
            findings.append(f"{name}: image sizes differ")
        elif diff["mean_abs_diff"] > mean_threshold or diff["differing_pixel_fraction"] > fraction_threshold:
            findings.append(f"{name}: mean diff {diff['mean_abs_diff']:.2f}, "
                            f"{100 * diff['differing_pixel_fraction']:.2f}% pixels differ")
        else:
            notes.append(f"{name}: within thresholds (mean {diff['mean_abs_diff']:.3f})")
    return findings, notes


def compare_fixture(base_dir, candidate_dir, args):
    result = {name: [] for name in CLASSES}
    notes = []
    for product in lib.SCIENTIFIC_PRODUCTS:
        for finding in compare_raster(load(base_dir / "reports" / f"{product}.json"),
                                      load(candidate_dir / "reports" / f"{product}.json")):
            result["science"].append(f"{product}: {finding}")
    for product in lib.GEOMETRY_PRODUCTS:
        for finding in compare_raster(load(base_dir / "reports" / f"{product}.json"),
                                      load(candidate_dir / "reports" / f"{product}.json")):
            result["geometry"].append(f"{product} raster: {finding}")
    result["geometry"] += compare_glb(load(base_dir / "reports" / "glb.json"),
                                      load(candidate_dir / "reports" / "glb.json"), args.bounds_tolerance)

    base_validation = load(base_dir / "reports" / "gltf_validation.json")
    candidate_validation = load(candidate_dir / "reports" / "gltf_validation.json")
    if base_validation and candidate_validation:
        if candidate_validation["errors"] > base_validation["errors"]:
            result["validation"].append(
                f"glTF validator errors {base_validation['errors']} -> {candidate_validation['errors']}")
        notes.append(f"validator: {candidate_validation['errors']} errors, "
                     f"{candidate_validation['warnings']} warnings")
    elif candidate_validation is None:
        notes.append("candidate has no glTF validation report")

    findings, screenshot_notes = compare_screenshots(base_dir, candidate_dir,
                                                     args.screenshot_mean_threshold,
                                                     args.screenshot_fraction_threshold)
    result["render"] += findings
    notes += screenshot_notes
    return result, notes


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument("base")
    parser.add_argument("candidate")
    parser.add_argument("--bounds-tolerance", type=float, default=0.01, help="metres")
    parser.add_argument("--screenshot-mean-threshold", type=float, default=1.0,
                        help="mean absolute RGB difference (0-255)")
    parser.add_argument("--screenshot-fraction-threshold", type=float, default=0.005,
                        help="fraction of pixels differing by more than 16")
    for name in CLASSES:
        parser.add_argument(f"--allow-{name}-change", action="store_true")
    parser.add_argument("--json", help="write the full comparison here")
    args = parser.parse_args()

    base, candidate = Path(args.base), Path(args.candidate)
    report = {"base": str(base), "candidate": str(candidate), "fixtures": {}}
    failed = False
    names = sorted({p.name for p in base.iterdir() if (p / "record.json").exists()} |
                   {p.name for p in candidate.iterdir() if (p / "record.json").exists()})
    for name in names:
        base_record = load(base / name / "record.json")
        candidate_record = load(candidate / name / "record.json")
        if not base_record or not candidate_record:
            print(f"{name}: present in only one baseline")
            failed = True
            continue
        if base_record["status"] != "captured" or candidate_record["status"] != "captured":
            print(f"{name}: not compared (base {base_record['status']}, candidate {candidate_record['status']})")
            continue
        if base_record.get("source_sha256") != candidate_record.get("source_sha256"):
            print(f"{name}: different source images; not comparable")
            failed = True
            continue
        result, notes = compare_fixture(base / name, candidate / name, args)
        report["fixtures"][name] = {"findings": result, "notes": notes}
        changed = [cls for cls in CLASSES if result[cls]]
        verdict = "identical" if not changed else "changed: " + ", ".join(changed)
        print(f"\n== {name}: {verdict}")
        for cls in CLASSES:
            for finding in result[cls]:
                allowed = getattr(args, f"allow_{cls}_change")
                print(f"  [{cls}{' (allowed)' if allowed else ''}] {finding}")
                failed |= not allowed
        for note in notes:
            print(f"  note: {note}")

    if args.json:
        lib.write_json(args.json, report)
    print("\nRESULT:", "FAIL" if failed else "PASS")
    return 1 if failed else 0


if __name__ == "__main__":
    sys.exit(main())
