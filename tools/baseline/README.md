# Phase 0 baseline harness

This harness records what the pipeline produces today, so that later
rendering phases (RoofGraph, materials, SAM2/KIBS, hybrid fusion) can show
two things: the scientific height products did not change, and every
geometry or visual change was intended. It never changes reconstruction,
height estimation or inference.

## What a baseline contains

`baselines/<label>/` (git-ignored) holds `baseline.json` and one directory per fixture.

**`baseline.json`** records:
- the git commit, branch and dirty-file count of the backend, frontend and SAT2LoD2 repositories;
- the feature-flag environment;
- the `baseline_inspect` hash;
- the status of each fixture.

**`<fixture>/`** holds:
- `record.json`: source hash, job UUID, timings, artifact hashes and validator summary;
- `mesh.glb`, `heights.tif`, `dtm.tif`, `ndsm.tif`, `confidence.tif`, `buildings.tif`, `buildings.json` and `summary.json` (reconstruction diagnostics), when the backend produced them;
- `reports/glb.json` from `baseline_inspect glb`, covering:
  - per-primitive mode, Draco flag, attributes, vertex, triangle and line counts, and bounds;
  - material and texture bindings;
  - `_FEATURE_ID_0` building IDs;
- `reports/<raster>.json` from `baseline_inspect raster`, covering size, geotransform, CRS hash and per-band statistics, plus a pixel SHA-256 that ignores NaN payloads and the sign of zero;
- `reports/gltf_validation.json` from the Khronos glTF validator;
- `screenshots/{overview,oblique,top}.png`, fixed-camera viewer captures (only with `--viewer`).

## One-time setup

```bash
cd ~/Desktop/DepthWizard
cmake --build drogon_service/gis_service/build-integration --target baseline_inspect
(cd tools/baseline/node && npm ci)          # validator, puppeteer-core, pngjs; uses system Chrome
```

Python scripts use only the standard library (Python ≥ 3.8).

## Capture a baseline from the running pipeline

Start the backend with all hybrid flags unset (the defaults). Its log line
`PipelineService: <uuid> feature flags: presentation_style=scientific sam2=0 kibs=0 hybrid_fusion=0`
confirms the configuration it used.

```bash
cd ~/Desktop/DepthWizard/drogon_service/gis_service/build-integration
DEPTHWIZARD_DIAGNOSTICS_DIR=$PWD/reconstruction_diagnostics ./gis_service    # terminal 1

cd ~/Desktop/frontend_service && npx vite --port 5173                      # terminal 2 (optional, for screenshots)

cd ~/Desktop/DepthWizard                                                   # terminal 3
python3 tools/baseline/capture_baseline.py --label phase0-$(git rev-parse --short HEAD) \
    --backend http://127.0.0.1:8081 \
    --diagnostics-dir drogon_service/gis_service/build-integration/reconstruction_diagnostics \
    --viewer http://localhost:5173
```

Each fixture is a full pipeline run, so it calls the Modal nDSM, semantic and
SAT2LoD2 endpoints. Use `--only urban_dense_nyc` to capture one fixture.

## Capture offline from saved outputs

Lay the saved outputs out as `<dir>/<fixture>/mesh.glb`, `heights.tif`, and so on, then run:

```bash
python3 tools/baseline/capture_baseline.py --label saved --artifacts <dir> [--viewer http://localhost:5173]
```

## Compare two baselines

```bash
python3 tools/baseline/compare_baselines.py baselines/<before> baselines/<after> [--json diff.json]
```

Each difference is classified as one of four types:

| Type | Fails when | Allow with |
|---|---|---|
| science | any DSM/DTM/nDSM/confidence pixel digest, size, geotransform or CRS changes | `--allow-science-change` (never for rendering work) |
| geometry | primitive counts, bounds (beyond `--bounds-tolerance`, default 0.01 m), materials, texture bindings, building IDs, or the building label raster change | `--allow-geometry-change` |
| validation | the glTF validator reports more errors than the base | `--allow-validation-change` |
| render | a screenshot's mean RGB difference exceeds 1.0, or more than 0.5 % of its pixels differ by more than 16 | `--allow-render-change` |

The exit status is 0 only when every change falls in an allowed type. With
flags off, the expected result between two captures of the same commit is
`science` and `geometry` identical.

Screenshot noise between repeated SwiftShader captures of the same GLB, measured on 2026-10-02:
- mean difference ≤ 0.003;
- ≤ 0.02 % of pixels above threshold.

## Provenance check

```bash
python3 tools/baseline/check_provenance.py [--verbose]
```

This scans the backend, the frontend `src/` and `index.html`, and the SAT2LoD2 integration files for URLs. Each host must match an entry in `provenance_manifest.json`, whose roles are runtime, validation, frontend_asset, build and documentation.

The check fails on:
- undeclared hosts;
- any URL containing a forbidden human-mapped source (OSM/Overpass, Google/Mapbox/Cesium tiles, Overture, cadastre, and so on);
- a SAT2LoD2 `pipeline.py` that no longer passes `osm_name='none'`.

This is a static check. It complements network logs of a real run but does not replace them.

## Feature flags (Phase 0: defined, logged, not implemented)

| Variable | Values | Default |
|---|---|---|
| `DEPTHWIZARD_PRESENTATION_STYLE` | `scientific`, `terra`, `orthophoto` | `scientific` |
| `DEPTHWIZARD_SAM2` | `0`, `1` | `0` |
| `DEPTHWIZARD_KIBS` | `0`, `1` | `0` |
| `DEPTHWIZARD_HYBRID_FUSION` | `0`, `1` | `0` |

These are parsed by `drogon_service/gis_service/utils/FeatureFlags.{h,cc}`.
- Invalid values fall back to the default with a warning.
- Non-default values are logged as "not implemented yet; ignored", so behaviour stays identical.
- These are separate from the existing `DEPTHWIZARD_PRESENTATION` (`flat_urban` or `metric`), which is unchanged.

## Fixtures

`fixtures.json` pins each fixture's source image by SHA-256. A capture refuses
a source whose hash no longer matches, and records slots marked `missing` as
skipped.

| Name | Scene | Source | Status |
|---|---|---|---|
| urban_dense_nyc | dense flat-roof urban, courtyards, towers | `~/Documents/nyc_test.tif` (EPSG:32618, 0.5 m) | available |
| urban_dense_washington | dense urban, large footprints | `~/Documents/washington_test.tif` | available |
| vegetation_mountain | terrain and vegetation, no buildings | `~/Documents/Test8.tif` (EPSG:3857, 10 m) | available |
| residential_pitched | pitched-roof houses | — | missing |
| sparse_urban | sparse buildings on open ground | — | missing |
| hilly_urban | buildings on sloped terrain | — | missing |

To add a fixture, pick an image that comes from imagery only (not derived from
any mapped vector data). Then set its `source`, `sha256` (`sha256sum`), `crs`,
`gsd_m` and `size`, and change `status` to `available`. Recapture the base
baseline afterwards, because comparisons only cover fixtures captured on both
sides.

## Tests

```bash
python3 -m unittest discover -s tools/baseline/tests -v
cd drogon_service/gis_service/build-integration && ctest -R baseline_harness --output-on-failure
```
