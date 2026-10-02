"""Shared helpers for the DepthWizard Phase 0 baseline harness (stdlib only)."""

import hashlib
import json
import os
import shutil
import subprocess
from pathlib import Path

HERE = Path(__file__).resolve().parent
REPO = HERE.parent.parent
NODE_DIR = HERE / "node"
DEFAULT_INSPECT = REPO / "drogon_service" / "gis_service" / "build-integration" / "baseline_inspect"

# Scientific rasters must never change because of rendering work.
SCIENTIFIC_PRODUCTS = ("heights", "dtm", "ndsm", "confidence")
# Geometry used by height queries; may change legitimately in later phases.
GEOMETRY_PRODUCTS = ("buildings",)
# Export-status URL key -> artifact file name.
EXPORT_URLS = {
    "dsm_url": "heights.tif",
    "dtm_url": "dtm.tif",
    "ndsm_url": "ndsm.tif",
    "confidence_url": "confidence.tif",
    "buildings_url": "buildings.tif",
    "buildings_index_url": "buildings.json",
}
# Environment variables that select the reconstruction and presentation path.
FLAG_VARIABLES = (
    "DEPTHWIZARD_PRESENTATION_STYLE", "DEPTHWIZARD_SAM2", "DEPTHWIZARD_KIBS",
    "DEPTHWIZARD_HYBRID_FUSION", "DEPTHWIZARD_PRESENTATION", "DEPTHWIZARD_SAT2LOD2",
    "DEPTHWIZARD_SAT2LOD2_URL", "DEPTHWIZARD_SAT2LOD2_TRANSPORT",
)


def expand(path):
    return Path(os.path.expanduser(str(path))).resolve()


def sha256_file(path):
    digest = hashlib.sha256()
    with open(path, "rb") as handle:
        for block in iter(lambda: handle.read(1 << 20), b""):
            digest.update(block)
    return digest.hexdigest()


def load_json(path):
    with open(path, encoding="utf-8") as handle:
        return json.load(handle)


def write_json(path, value):
    path = Path(path)
    path.parent.mkdir(parents=True, exist_ok=True)
    with open(path, "w", encoding="utf-8") as handle:
        json.dump(value, handle, indent=2, sort_keys=True)
        handle.write("\n")


def run_json(command, cwd=None, timeout=600):
    """Runs a command that prints JSON on stdout; raises with its stderr."""
    completed = subprocess.run(command, cwd=cwd, capture_output=True, text=True, timeout=timeout)
    if completed.returncode != 0:
        raise RuntimeError(f"{command[0]} failed ({completed.returncode}): {completed.stderr.strip()[:500]}")
    return json.loads(completed.stdout)


def inspect(inspect_binary, kind, path):
    return run_json([str(inspect_binary), kind, str(path)])


def node_tools_available():
    return shutil.which("node") is not None and (NODE_DIR / "node_modules").is_dir()


def node_tool(script, *arguments, timeout=600):
    return run_json(["node", str(NODE_DIR / script), *map(str, arguments)], cwd=NODE_DIR, timeout=timeout)


def git_state(path):
    """Commit, branch and number of uncommitted files, or None outside git."""
    path = expand(path)

    def git(*arguments):
        return subprocess.run(["git", "-C", str(path), *arguments], capture_output=True, text=True)

    if not path.exists() or git("rev-parse", "--show-toplevel").returncode != 0:
        return None
    status = git("status", "--porcelain").stdout
    return {
        "path": str(path),
        "commit": git("rev-parse", "HEAD").stdout.strip(),
        "branch": git("rev-parse", "--abbrev-ref", "HEAD").stdout.strip(),
        "dirty_files": len([line for line in status.splitlines() if line.strip()]),
    }

