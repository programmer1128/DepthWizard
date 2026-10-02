#!/usr/bin/env python3
"""Static provenance check: every network host in the code must be declared.

Scans source files for URLs, matches each host against
provenance_manifest.json, and fails on undeclared hosts or on URLs naming a
forbidden human-mapped data source (OSM, Google/Mapbox/Cesium buildings,
cadastre, ...). It also checks that the SAT2LoD2 integration keeps its OSM
step disabled. This complements, not replaces, network logs of a real run.

Example:
  check_provenance.py                       # default scan roots
  check_provenance.py --root path/to/code   # scan specific trees
"""

import argparse
import fnmatch
import re
import sys
from pathlib import Path
from urllib.parse import urlparse

import baseline_lib as lib

URL = re.compile(r"https?://[^\s\"'<>`)\]\\,;]+")
URL_TAIL = re.compile(r"[^\s\"'<>`)\]\\,;]+")
# Closing and reopening quote of an adjacent string literal on the next line,
# as in C++ "https://bucket.s3.region." "amazonaws.com/...".
CONTINUATION = re.compile(r"\"[ \t]*\r?\n[ \t]*\"")
EXTENSIONS = {".cc", ".cpp", ".h", ".hpp", ".py", ".js", ".mjs", ".html", ".css"}
SKIP_DIRS = {"node_modules", "dist", ".git", "__pycache__", "third_party"}
# Vendored single-header libraries carry upstream documentation links only.
SKIP_FILES = {"tiny_obj_loader.h"}


def default_roots():
    roots = [lib.REPO / "drogon_service" / "gis_service"]
    for optional in ("~/Desktop/frontend_service/src", "~/Desktop/frontend_service/index.html"):
        path = lib.expand(optional)
        if path.exists():
            roots.append(path)
    sat2lod2 = lib.expand("~/LOD2BuildingModel")
    for name in ("pipeline.py", "server.py", "sat2lod2_worker.py", "model_deploy.py"):
        if (sat2lod2 / name).exists():
            roots.append(sat2lod2 / name)
    return roots


def iter_files(root):
    root = Path(root)
    if root.is_file():
        yield root
        return
    for path in root.rglob("*"):
        if (path.suffix in EXTENSIONS and path.is_file() and path.name not in SKIP_FILES
                and not any(part in SKIP_DIRS or part.startswith("build") for part in path.parts)):
            yield path


def host_of(url):
    """Hostname of a URL, or "" for templates such as "http://${host}"."""
    try:
        return urlparse(url).hostname or ""
    except ValueError:
        return ""


def classify(url, manifest):
    lowered = url.lower()
    for forbidden in manifest["forbidden_substrings"]:
        if forbidden in lowered:
            return "forbidden", forbidden
    host = host_of(url)
    if not host or "..." in host:
        # "https://host[:port]", "https://...modal.run": comments, not endpoints.
        return "placeholder", url
    for entry in manifest["allowed_hosts"]:
        if fnmatch.fnmatch(host, entry["pattern"]):
            return entry["phase"], entry["role"]
    return "undeclared", host


def scan(roots, manifest):
    findings = []
    for root in roots:
        for path in iter_files(root):
            text = path.read_text(encoding="utf-8", errors="replace")
            for match in URL.finditer(text):
                url, end = match.group(), match.end()
                while (continuation := CONTINUATION.match(text, end)):
                    tail = URL_TAIL.match(text, continuation.end())
                    if not tail:
                        break
                    url, end = url + tail.group(), tail.end()
                category, detail = classify(url, manifest)
                findings.append({"file": str(path), "line": text.count("\n", 0, match.start()) + 1,
                                 "url": url, "category": category, "detail": detail})
    return findings


def check_sat2lod2_osm_disabled(pipeline):
    """SAT2LoD2's OSM refinement must be called with osm_name='none'."""
    if not pipeline.exists():
        return None
    text = pipeline.read_text(encoding="utf-8")
    return re.search(r"osm_name\s*=\s*['\"]none['\"]", text) is not None


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument("--manifest", default=str(lib.HERE / "provenance_manifest.json"))
    parser.add_argument("--root", action="append", help="file or directory to scan (repeatable)")
    parser.add_argument("--sat2lod2-pipeline", default="~/LOD2BuildingModel/pipeline.py")
    parser.add_argument("--verbose", action="store_true", help="list every declared URL too")
    args = parser.parse_args()

    manifest = lib.load_json(args.manifest)
    roots = [Path(r) for r in args.root] if args.root else default_roots()
    findings = scan(roots, manifest)

    failures = [f for f in findings if f["category"] in ("forbidden", "undeclared")]
    by_category = {}
    for finding in findings:
        by_category.setdefault(finding["category"], set()).add(host_of(finding["url"]))
    print("Scanned:", ", ".join(str(r) for r in roots))
    for category in sorted(by_category):
        print(f"  {category:15s} {', '.join(sorted(h or '?' for h in by_category[category]))}")
    if args.verbose:
        for finding in findings:
            print(f"    {finding['category']:12s} {finding['file']}:{finding['line']} {finding['url']}")
    for failure in failures:
        print(f"FAIL {failure['category']}: {failure['file']}:{failure['line']} {failure['url']} ({failure['detail']})")

    osm_disabled = check_sat2lod2_osm_disabled(lib.expand(args.sat2lod2_pipeline))
    if osm_disabled is False:
        print("FAIL SAT2LoD2 pipeline.py does not pass osm_name='none'")
    elif osm_disabled is None:
        print("note: SAT2LoD2 pipeline.py not found; OSM check skipped")
    else:
        print("SAT2LoD2 OSM refinement disabled (osm_name='none')")

    failed = bool(failures) or osm_disabled is False
    print("RESULT:", "FAIL" if failed else "PASS")
    return 1 if failed else 0


if __name__ == "__main__":
    sys.exit(main())
