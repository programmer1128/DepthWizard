"""Unit tests for the Phase 0 baseline scripts.

Run from the repository root:
  python3 -m unittest discover -s tools/baseline/tests -v
"""

import contextlib
import copy
import io
import shutil
import sys
import tempfile
import unittest
from pathlib import Path
from unittest import mock

sys.path.insert(0, str(Path(__file__).resolve().parent.parent))

import baseline_lib as lib  # noqa: E402
import capture_baseline  # noqa: E402
import check_provenance  # noqa: E402
import compare_baselines  # noqa: E402

SAMPLE_GLB = Path("~/Desktop/frontend_service/test_8_output.glb").expanduser()
SAMPLE_RASTER = Path("~/Documents/new_backend_height.tif").expanduser()

RASTER = {
    "width": 4, "height": 2, "geotransform": [0, 0.5, 0, 0, 0, -0.5], "crs_sha256": "c" * 64,
    "bands": [{"pixel_sha256": "a" * 64, "valid_pixels": 8, "mean": 3.0}],
}
GLB = {
    "counts": {"meshes": 1, "nodes": 1, "materials": 1, "textures": 0, "images": 0, "samplers": 0},
    "extensions_used": ["KHR_draco_mesh_compression"], "extensions_required": [], "images": [],
    "primitives": [{
        "mesh": 0, "primitive": 0, "mode": 4, "draco": True, "attributes": ["POSITION", "_FEATURE_ID_0"],
        "vertex_count": 30, "index_count": 30, "triangle_count": 10, "line_count": 0,
        "material": {"name": "roof"}, "bounds": {"min": [0, 0, 0], "max": [10, 5, 10]},
    }],
    "totals": {"vertices": 30, "triangles": 10, "lines": 0,
               "bounds": {"min": [0, 0, 0], "max": [10, 5, 10]}},
    "building_ids": [1, 2, 3],
}


def compare_args(**overrides):
    values = {"bounds_tolerance": 0.01, "screenshot_mean_threshold": 1.0,
              "screenshot_fraction_threshold": 0.005}
    values.update(overrides)
    return mock.Mock(**values)


class CompareRasterTest(unittest.TestCase):
    def test_identical_reports_have_no_findings(self):
        self.assertEqual(compare_baselines.compare_raster(RASTER, copy.deepcopy(RASTER)), [])

    def test_pixel_and_georeference_changes_are_reported(self):
        candidate = copy.deepcopy(RASTER)
        candidate["bands"][0]["pixel_sha256"] = "b" * 64
        candidate["geotransform"][1] = 0.6
        findings = compare_baselines.compare_raster(RASTER, candidate)
        self.assertEqual(len(findings), 2)
        self.assertTrue(any("pixels changed" in f for f in findings))
        self.assertTrue(any(f.startswith("geotransform") for f in findings))

    def test_missing_on_one_side_is_a_finding(self):
        self.assertEqual(compare_baselines.compare_raster(None, None), [])
        self.assertEqual(compare_baselines.compare_raster(RASTER, None), ["present in only one baseline"])


class CompareGlbTest(unittest.TestCase):
    def test_identical_reports_have_no_findings(self):
        self.assertEqual(compare_baselines.compare_glb(GLB, copy.deepcopy(GLB), 0.01), [])

    def test_bounds_within_tolerance_are_equal(self):
        candidate = copy.deepcopy(GLB)
        candidate["primitives"][0]["bounds"]["max"][1] = 5.005
        candidate["totals"]["bounds"]["max"][1] = 5.005
        self.assertEqual(compare_baselines.compare_glb(GLB, candidate, 0.01), [])
        self.assertEqual(len(compare_baselines.compare_glb(GLB, candidate, 0.001)), 2)

    def test_building_ids_counts_and_materials_are_reported(self):
        candidate = copy.deepcopy(GLB)
        candidate["building_ids"] = [1, 2, 4]
        candidate["primitives"][0]["triangle_count"] = 12
        candidate["primitives"][0]["material"] = {"name": "roof", "base_color_texture": {"texture": 0}}
        findings = compare_baselines.compare_glb(GLB, candidate, 0.01)
        self.assertTrue(any("1 removed [3], 1 added [4]" in f for f in findings))
        self.assertTrue(any("triangle_count" in f for f in findings))
        self.assertTrue(any("material" in f for f in findings))


class CompareBaselinesCliTest(unittest.TestCase):
    """End-to-end gate on synthetic baseline directories."""

    def setUp(self):
        self.root = Path(tempfile.mkdtemp())
        self.addCleanup(shutil.rmtree, self.root)
        self.base = self.make_baseline("base", RASTER, GLB)

    def make_baseline(self, label, raster, glb, status="captured"):
        fixture = self.root / label / "urban"
        lib.write_json(fixture / "record.json", {"status": status, "source_sha256": "s" * 64})
        lib.write_json(fixture / "reports" / "heights.json", raster)
        lib.write_json(fixture / "reports" / "glb.json", glb)
        lib.write_json(fixture / "reports" / "gltf_validation.json", {"errors": 0, "warnings": 2})
        return self.root / label

    def run_cli(self, candidate, *flags):
        argv = ["compare_baselines.py", str(self.base), str(candidate), *flags]
        output = io.StringIO()
        with mock.patch.object(sys, "argv", argv), contextlib.redirect_stdout(output):
            code = compare_baselines.main()
        return code, output.getvalue()

    def test_identical_baselines_pass(self):
        code, output = self.run_cli(self.make_baseline("same", RASTER, GLB))
        self.assertEqual(code, 0, output)
        self.assertIn("identical", output)

    def test_science_change_fails_even_when_geometry_and_render_are_allowed(self):
        raster = copy.deepcopy(RASTER)
        raster["bands"][0]["pixel_sha256"] = "d" * 64
        code, output = self.run_cli(self.make_baseline("science", raster, GLB),
                                    "--allow-geometry-change", "--allow-render-change")
        self.assertEqual(code, 1, output)
        self.assertIn("[science]", output)

    def test_geometry_change_passes_only_when_allowed(self):
        glb = copy.deepcopy(GLB)
        glb["building_ids"] = [1, 2]
        candidate = self.make_baseline("geometry", RASTER, glb)
        self.assertEqual(self.run_cli(candidate)[0], 1)
        code, output = self.run_cli(candidate, "--allow-geometry-change")
        self.assertEqual(code, 0, output)
        self.assertIn("(allowed)", output)

    def test_new_validator_errors_fail(self):
        candidate = self.make_baseline("invalid", RASTER, GLB)
        lib.write_json(candidate / "urban" / "reports" / "gltf_validation.json", {"errors": 3, "warnings": 2})
        code, output = self.run_cli(candidate)
        self.assertEqual(code, 1, output)
        self.assertIn("[validation]", output)

    def test_skipped_fixtures_are_not_compared(self):
        code, output = self.run_cli(self.make_baseline("skipped", RASTER, GLB, status="skipped"))
        self.assertEqual(code, 0, output)
        self.assertIn("not compared", output)


class ProvenanceTest(unittest.TestCase):
    manifest = lib.load_json(lib.HERE / "provenance_manifest.json")

    def test_forbidden_sources_are_rejected_before_host_matching(self):
        for url in ("https://overpass-api.de/api/interpreter",
                    "https://tile.openstreetmap.org/1/1/1.png",
                    "https://api.mapbox.com/v4/mapbox.mapbox-streets-v8",
                    "https://tile.googleapis.com/v1/3dtiles/root.json"):
            self.assertEqual(check_provenance.classify(url, self.manifest)[0], "forbidden", url)

    def test_declared_and_undeclared_hosts(self):
        self.assertEqual(check_provenance.classify(
            "https://portal.opentopography.org/API/globaldem", self.manifest)[0], "validation")
        self.assertEqual(check_provenance.classify("http://127.0.0.1:8081/api", self.manifest)[0], "runtime")
        self.assertEqual(check_provenance.classify("https://example.net/data", self.manifest),
                         ("undeclared", "example.net"))

    def test_scan_finds_urls_with_line_numbers(self):
        with tempfile.TemporaryDirectory() as directory:
            source = Path(directory) / "client.cc"
            source.write_text('// ok\nconst char* u = "https://overpass-api.de/api";\n')
            findings = check_provenance.scan([Path(directory)], self.manifest)
        self.assertEqual([(f["line"], f["category"]) for f in findings], [(2, "forbidden")])

    def test_adjacent_string_literals_are_joined(self):
        with tempfile.TemporaryDirectory() as directory:
            source = Path(directory) / "dem.cc"
            source.write_text('auto u =\n    "https://copernicus-dem-30m.s3.eu-central-1."\n'
                              '    "amazonaws.com/tile.tif";\n')
            findings = check_provenance.scan([Path(directory)], self.manifest)
        self.assertEqual(len(findings), 1)
        self.assertEqual(findings[0]["line"], 2)
        self.assertEqual(findings[0]["url"],
                         "https://copernicus-dem-30m.s3.eu-central-1.amazonaws.com/tile.tif")
        self.assertEqual(findings[0]["category"], "runtime")

    def test_placeholders_do_not_fail_but_forbidden_text_still_does(self):
        self.assertEqual(check_provenance.classify("https://...modal.run", self.manifest)[0], "placeholder")
        self.assertEqual(check_provenance.classify("https://host[:port", self.manifest)[0], "placeholder")
        self.assertEqual(check_provenance.classify("https://...openstreetmap", self.manifest)[0], "forbidden")

    def test_sat2lod2_osm_check(self):
        with tempfile.TemporaryDirectory() as directory:
            pipeline = Path(directory) / "pipeline.py"
            self.assertIsNone(check_provenance.check_sat2lod2_osm_disabled(pipeline))
            pipeline.write_text("run(osm_name='none')\n")
            self.assertTrue(check_provenance.check_sat2lod2_osm_disabled(pipeline))
            pipeline.write_text("run(osm_name='osm_buildings.shp')\n")
            self.assertFalse(check_provenance.check_sat2lod2_osm_disabled(pipeline))


class FixtureManifestTest(unittest.TestCase):
    def test_available_fixtures_are_pinned(self):
        fixtures = lib.load_json(lib.HERE / "fixtures.json")["fixtures"]
        names = [f["name"] for f in fixtures]
        self.assertEqual(len(names), len(set(names)))
        for fixture in fixtures:
            if fixture["status"] == "available":
                self.assertRegex(fixture["sha256"], r"^[0-9a-f]{64}$", fixture["name"])
                self.assertTrue(fixture["source"], fixture["name"])


@unittest.skipUnless(lib.DEFAULT_INSPECT.exists() and SAMPLE_GLB.exists() and SAMPLE_RASTER.exists(),
                     "needs the built baseline_inspect and local sample outputs")
class CaptureArtifactsModeTest(unittest.TestCase):
    """capture_baseline.py --artifacts on real outputs, compared with itself."""

    def test_capture_twice_and_compare_identical(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            source = root / "source.tif"
            source.write_bytes(b"fixture image")
            lib.write_json(root / "fixtures.json", {"fixtures": [
                {"name": "sample", "status": "available", "source": str(source),
                 "sha256": lib.sha256_file(source)},
                {"name": "uncurated", "status": "missing", "source": None, "sha256": None},
            ]})
            artifacts = root / "artifacts" / "sample"
            artifacts.mkdir(parents=True)
            shutil.copy(SAMPLE_GLB, artifacts / "mesh.glb")
            shutil.copy(SAMPLE_RASTER, artifacts / "heights.tif")

            for label in ("a", "b"):
                argv = ["capture_baseline.py", "--label", label, "--out-root", str(root / "out"),
                        "--fixtures", str(root / "fixtures.json"), "--artifacts", str(root / "artifacts")]
                with mock.patch.object(sys, "argv", argv), contextlib.redirect_stdout(io.StringIO()):
                    self.assertEqual(capture_baseline.main(), 0)

            record = lib.load_json(root / "out" / "a" / "sample" / "record.json")
            self.assertEqual(record["status"], "captured")
            self.assertEqual(lib.load_json(root / "out" / "a" / "uncurated" / "record.json")["status"], "skipped")
            glb = lib.load_json(root / "out" / "a" / "sample" / "reports" / "glb.json")
            self.assertGreater(glb["totals"]["triangles"], 0)
            self.assertTrue((root / "out" / "a" / "sample" / "reports" / "heights.json").exists())
            self.assertEqual(lib.load_json(root / "out" / "a" / "baseline.json")["schema"],
                             "depthwizard.baseline.capture.v1")

            argv = ["compare_baselines.py", str(root / "out" / "a"), str(root / "out" / "b")]
            output = io.StringIO()
            with mock.patch.object(sys, "argv", argv), contextlib.redirect_stdout(output):
                self.assertEqual(compare_baselines.main(), 0, output.getvalue())

    def test_changed_source_image_is_an_error(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            source = root / "source.tif"
            source.write_bytes(b"changed")
            lib.write_json(root / "fixtures.json", {"fixtures": [
                {"name": "sample", "status": "available", "source": str(source), "sha256": "0" * 64}]})
            argv = ["capture_baseline.py", "--label", "x", "--out-root", str(root / "out"),
                    "--fixtures", str(root / "fixtures.json"), "--artifacts", str(root)]
            with mock.patch.object(sys, "argv", argv), contextlib.redirect_stdout(io.StringIO()):
                self.assertEqual(capture_baseline.main(), 1)
            record = lib.load_json(root / "out" / "x" / "sample" / "record.json")
            self.assertEqual(record["status"], "error")
            self.assertIn("source changed", record["reason"])


if __name__ == "__main__":
    unittest.main()
