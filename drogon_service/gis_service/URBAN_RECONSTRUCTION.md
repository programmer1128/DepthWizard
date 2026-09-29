# Urban reconstruction and presentation

## Run the new urban view

Build from `gis_service` and restart the backend with the rebuilt executable
(keep the existing model servers and MinIO configuration):

```sh
cmake --build build-integration -j4
ctest --test-dir build-integration --output-on-failure
```

Use the existing upload endpoint. The backend selects presentation automatically:

```sh
curl -X POST 'http://localhost:8080/api/v1/processor' \
  -F 'image=@/home/aritra/Documents/nyc_test.tif'
```

Use your configured port if different. Open the new `glb_url`; previously
downloaded GLBs are not updated. The old `view` query parameter is no longer
used. The initial response remains only `uuid` and `glb_url`; the frontend just
loads the GLB. The backend logs its decision and records it in `summary.json`.

`ScenePresentationSelector` requires broadly distributed, high-confidence
building evidence and at least three reconstructed objects to select urban
presentation. Vegetation-dominant scenes, major supported ground relief,
localized/sparse buildings and insufficient observations retain terrain.
This is a conservative presentation heuristic, not a guarantee of scene type.
Its thresholds are centralized in that service and should be validated on
held-out urban, mixed, forest and mountain imagery. Imperfect semantics can
also affect this decision; the diagnostics expose the evidence and reason.

## What each view means

`flat_urban` is a presentation mode: terrain is local Y=0; building roof Y is
estimated height above ground in metres, with no height exaggeration. Walls
overlap the zero ground slightly. There is no skirt or bottom cap. It is not an
absolute elevation view.

`metric` uses reference-derived terrain, absolute roof elevations and sampled
wall bases. Reference-surface contamination and model errors remain estimation
uncertainties; morphological filtering is not proof of true bare-earth terrain.

Both modes export the same scientific DSM, DTM and nDSM. GLB asset extras carry
`presentationMode`, `renderYIsAbsoluteElevationOffset` and `heightScale`.
Do not convert clicked flat-mode Y to absolute elevation using elevationOrigin.
Use the existing UUID raster queries or per-building diagnostic elevations.
Metric exports are unchanged, not independently verified ground truth.

## Reconstruction stages

1. Strong semantic roofs are accepted. UNKNOWN candidates can only grow a
   bounded 4.5 m distance from strong evidence and cannot cross known non-building
   classes or stronger non-building probability. No standalone building is
   created just because noisy nDSM is high.
2. Urban morphology preserves thin roofs (`openingRadiusMetres=0`) and uses a
   9 m rectangular closing radius to reconnect tree-occluded portions of a
   complex. Confident road/ground/water evidence remains a barrier and is
   reapplied after morphology so alleys survive. Elevated vegetation pixels
   are traversable only when they also retain credible building evidence.
3. `BuildingInstanceSplitter` labels edge-connected components, finds sizeable
   high-probability cores separated by probability valleys or edge-preserving
   filtered nDSM steps, and floods integer instance labels within the original
   mask. It is enabled by default. The defaults use a 3 m calibrated nDSM step
   and 25 m² of supported seed area. An optional, slightly blurred grayscale
   copy of the uploaded image increases the cost of crossing strong optical
   edges while assigning ambiguous pixels. A calibrated nDSM jump above 65%
   of the 3 m roof-step setting receives a 1000-cost crossing penalty during
   multi-source flooding. This moves the ownership boundary toward supported
   roof cliffs when both sides have markers; the flood remains within the
   original building mask and preserves all of its pixels. It does not normalize distance
   against the largest building in the scene.
   Every original mask pixel keeps a label. Poorly supported cuts, excessive
   markers and single-core components retain the original component.

4. Each instance is vectorized and gets its own robust height estimate. Under
   Tactical LoD1 configuration, `regularizeRectangularFootprints` forces candidate
   building footprints directly into crisp Oriented Bounding Boxes (OBB via
   `cv::minAreaRect`), immediately clearing internal courtyards and returning a
   clean 4-vertex prism footprint. When rectangular regularization is disabled,
   the full Manhattan and CGAL edge-regularization pipeline operates with
   GEOS polygon simplification, area bounds, and neighbour exclusion safeguards.
   Robust roof height estimation exclusively uses the 85th percentile peak of
   the nDSM samples, scaled by `heightScaleMultiplier = 2.25f` to ensure towering
   skylines and prominent vertical relief.
5. LoD2 block decomposition and parametric pitched/hip roof fitting are disabled
   by default (`enableLod2BlockDecomposition = false`, `enableLod2RoofFitting = false`)
   to produce clean, flat-topped LoD1 CAD prisms. Complex roof pitches and multi-tier
   decompositions can be re-enabled on demand for scenes requiring fine-grained LoD2 roofs.
6. Terrain, colored walls and roofs become separate Draco primitives.
   Buildings have no photographic UV texture; PBR materials and hard normals
   provide face shading. The GLB's terrain texture conceals the photographic
   roof beneath emitted buildings plus a 1 m fringe; the original optical
   image and scientific rasters are unchanged. Urban scenes have no pedestal; terrain scenes retain
   skirts down to a common base 2 m below the scene's sampled minimum.

## SAT2LoD2 footprints (optional microservice)

When the SAT2LoD2 service is running, it replaces the native footprints:

```sh
cd ~/LOD2BuildingModel
~/.conda/envs/sat2lod2/bin/uvicorn server:app --port 8000
```

The backend sends it the corrected nDSM, the building class mask and the
optical image, then imports `buildings.json` (`Sat2Lod2Importer`). OpenStreetMap
refinement is disabled (`osm_name='none'`): only image and model evidence is used.

- SAT2LoD2 contributes 2D geometry only: each segment's outline and its
  rectangle decomposition, in pixel-centre coordinates of the uploaded raster.
- The semantic mask cannot see party walls, so one segment is often a whole
  city block. The building separations come from SAT2LoD2's rectangles (split
  on optical edges and nDSM steps): every rectangle becomes its own building
  part. Never extrude the segment outline over them, as that merges the block
  into one slab.
- Taller rectangles are placed first and stay intact (among equal heights the
  smaller goes first, so a tower is not swallowed by its podium); lower ones
  are clipped around them. Neighbours keep a `sat2lod2PartGapMetres` gap
  (default 0.3 m). Parts smaller than `minDecomposedBlockAreaSquareMetres` or
  narrower than 2 m are dropped.
- Footprint areas no rectangle covers stay empty by default. SAT2LoD2's
  rectangles sit inside the semantic mask and its outlines have courtyards
  filled (`binary_fill_holes`), so filling the remainder frames every block,
  welds neighbours together and paves courtyards. Setting
  `sat2lod2MinResidualAreaSquareMetres` > 0 fills remainder pieces that are at
  least that large, 3 m wide and 70% building-class pixels.
- Every part's height is measured after clipping from the backend nDSM by
  `BuildingHeightEstimator` (the native 85th-percentile estimate and
  `heightScaleMultiplier`). Parts within `sat2lod2TierSnapMetres` (default 1 m)
  in one segment share a roof level. SAT2LoD2's own heights only describe roof
  shape.
- Segments without rectangles are extruded from their outline, snapped to a
  rectilinear shape along its facade direction (`sat2lod2MinFootprintEdgeMetres`,
  default 2.5 m), or simplified and CGAL-regularized when not credibly
  rectilinear (IoU below `minimumFootprintMaskIoU`).
- Roofs are flat. SAT2LoD2's gable/hip labels are honoured only with
  `enableLod2RoofFitting`: on a smooth monocular nDSM it labels most flat
  Manhattan roofs as pitched.
- Native buildings covering at most 10% SAT2LoD2 area are kept, since SAT2LoD2
  drops small segments whose rectangle fit fails.

If the service is down, fails or exceeds `DEPTHWIZARD_SAT2LOD2_TIMEOUT_S`
(default 900 s), native reconstruction is used. `DEPTHWIZARD_SAT2LOD2=0`
disables the call and `DEPTHWIZARD_SAT2LOD2_URL` changes its address. The
backend log reports `building_source=sat2lod2|native`.

`server.py` runs every job as a fresh `sat2lod2_worker.py` process in its own
session, one job at a time. `SAT2LOD2_JOB_TIMEOUT_S` (default 600 s, below the
backend's 900 s) kills the job and all its workers and returns 504, so the
backend falls back to native reconstruction. Inside a job, each segment's
rectangle decomposition has `SAT2LOD2_SEGMENT_BUDGET_S` (default 90 s); a
segment that exceeds it, or whose decomposition raises, keeps no rectangles and
is extruded from its Manhattan footprint.

Two deadlocks of SAT2LoD2's forked `multiprocessing.Pool` looked like an
infinite loop at "Step3 ... 35%"; neither was algorithmic:
- OpenCV's OpenMP pool does not survive fork. `pipeline.py` disables OpenCV
  threading before import, or workers hang in `cv2.warpAffine`.
- Workers forked inside uvicorn inherited its SIGTERM handler, so the
  `Pool.terminate()` at the end of every `with Pool(...)` block could not
  kill them and waited forever after Step 3 had finished. Jobs now run in a
  separate process, and pool workers also reset SIGTERM/SIGINT to defaults.
Never call `run_reconstruction` from inside the server process.

These are heuristic instances, not guaranteed property/building identities.
Two equal-height touching roofs with no semantic boundary can remain one block.
Multiple roof levels of one real building may become separate render objects.
Missing model evidence cannot safely be replaced with invented buildings.

## Reference methods and limits

- [Sat3DGen](https://github.com/qianmingduowan/Sat3DGen) constrains learned
  volumetric density during model training. Its gravity and depth losses are
  not mesh postprocessors, and its public inference path requires PyTorch,
  CUDA, and trained weights. This backend keeps explicit building geometry
  and uses the uploaded optical image, semantic probabilities, and nDSM as
  deterministic boundary evidence.
- [Sat2City v2](https://ai4city-hkust.github.io/Sat2City-v2/) trains a
  satellite-conditioned mesh generator on paired imagery and textured meshes.
  Its project page currently labels the code as forthcoming, so there is no
  C++ implementation to adapt.
- [3DMeshGen](https://github.com/sergyDwhiz/3DMeshGen) demonstrates basic
  polygon extrusion. `BuildingMesher` already extrudes rings and handles
  courtyards, roof facets, and setbacks; the useful architectural principle
  here is retaining hard footprint walls rather than meshing raw depth pixels.
- [terrain-builder](https://github.com/AlpineMapsOrg/terrain-builder) builds
  tiled terrain assets from orthophotos and heightmaps. Tiling is relevant to
  future large-area throughput, but it does not recover building footprints.
- [DSMtoPointcloud](https://github.com/tersite1/DSMtoPointcloud) converts a
  depth raster to a point cloud and smooth surface mesh. Applying Poisson
  reconstruction to buildings would blur the vertical walls that this pipeline
  represents explicitly.

The quality ceiling remains the uploaded image's semantic mask and inferred
nDSM. Strong optical edges can improve the division of a merged candidate,
but they cannot recover a building whose roof was never segmented or infer a
physically accurate height absent reliable depth evidence. No external
building polygons are consumed by this reconstruction stage.

## Viewer requirements

Supply a directional light and suitable ambient/environment illumination for
PBR materials. Shadows require renderer shadow maps plus light and mesh shadow
settings; changing the GLB material alone cannot enable them. Do not replace
these materials with unlit materials or smooth normals across wall corners.
Do not apply non-uniform model scaling if displaying metric dimensions.

Buildings remain opaque, untextured PBR using the restored darker palette:
wall RGB (0.015, 0.10, 0.42), metallic 0, roughness 0.6;
roof RGB (0.025, 0.24, 0.72), metallic 0, roughness 0.65. These are
linear glTF base-color factors, not sRGB swatches. Terrain texture and its matte
material are unchanged. `KHR_materials_unlit` is absent globally and per material.
The backend produces geometry/materials; lighting, exposure and shadow rendering
remain responsibilities of any glTF renderer, not reconstruction view selection.

## Optical/building alignment

Raster ingestion preserves the source's top-to-bottom row order in the embedded
JPEG. glTF's texture origin is also top-left: terrain uses `u=pixelX/width` and
`v=pixelY/height`, with no V flip. Positions use those same pixel coordinates
through the full GDAL affine transform and local scene frame. Building polygons
already use GDAL pixel-edge coordinates, so both layers share one spatial frame.
Interior terrain nodes sample pixel centres; perimeter nodes extend to the
outer image edges with nearest-sample heights. Decimation preserves the same
mapping and image extent. The texture sampler clamps at the edges rather than
repeating the opposite side of the photograph.

Earlier GLBs used flipped V and width-minus-one/height-minus-one normalization.
Those artifacts must be regenerated. Do not compensate with an extra frontend
texture flip or a per-building translation. Regression tests now check affine
position/UV agreement both before and after Draco compression, including a
rotated/sheared grid and decimation of a non-square image.

For the inspected Washington artifact, 50 candidates were accepted and emitted
without geometry/height rejections. The texture flip was verified directly from
the embedded image and decoded UVs. Missing semantic roof boundaries remain an
upstream inference-quality issue; this is separate from the fixed registration
bug and does not establish the model's accuracy on a labelled evaluation set.

## Per-UUID diagnostics

Enabled by default. The existing bounded background export worker writes to
`reconstruction_diagnostics/<uuid>/` relative to the backend working directory.
Set `DEPTHWIZARD_DIAGNOSTICS_DIR` to an absolute directory to make its location
independent of startup location. Set `DEPTHWIZARD_DIAGNOSTICS=0` to disable.
The terminal logs the absolute completed folder. The exports status endpoint
`GET /api/v1/processor/exports/<uuid>` includes `diagnostics_status`, separately
from TIFF upload state; diagnostic failures also appear in its errors array.

Files are:

- `building_probability.tif`: raw stitched building probability.
- `road_probability.tif`, `vegetation_probability.tif`, `semantic_confidence.tif`:
  evidence used by the automatic presentation policy.
- `final_semantic_class.tif`: enum IDs, documented in the summary.
- `candidate_mask.tif`: thresholded/recovered pixels before morphology.
- `cleaned_mask.tif`: accepted pixels after morphology/area filtering.
- `instance_labels.tif`: integer instance IDs before geometry rejection.
- `raw_ndsm.tif`: stitched model heights before bias correction/fusion.
- `reconstruction_ndsm.tif`: bias-corrected model heights supplied directly
  to instance splitting, roof fitting, and height estimation.
- `fused_ndsm.tif`: corrected/semantically gated heights.
- `dtm.tif`: unflattened reference-derived terrain used for metric geometry.
- `summary.json`: accepted/emitted counts, stage rejections, per-building
  heights and absolute base/roof elevations, confidence and mesh warnings;
  automatic presentation reason, fractions and supported ground relief.

## Semantic-model validation still required

The deployed semantic worker feeds the normalized RGB CHW tensor received
from the backend directly into ONNX Runtime; its older ImageProcessor helper
is not invoked in this network path. The backend normalizes once using RGB
ImageNet mean/std. Do not add a second normalization or change channels to
compensate for a missing roof without an exact reference comparison.

The original GAMUS semantic checkpoint/validation code that produced the
reported IoU is not present in the supplied model source tree. Therefore an
original-PyTorch-versus-ONNX parity result cannot be asserted. Compare the same
518x518 RGB crop, padding, GSD, normalized float32 tensor and class order in
both pipelines when that validation implementation is available. Compare raw
per-class logits before softmax and tiling, then probabilities. Do not compare
single-tile logits directly with already blended full-scene probabilities.
Matching poor predictions indicate a model/data issue; differing predictions
indicate export or input/output contract issues. Missing D.C. roof evidence is
not corrected merely by changing the scene's presentation.

Rasters retain the scene CRS and affine transform. Open them with the input
image in QGIS to inspect alignment, merges, missing roofs and height errors.
The summary is published last. Diagnostics are local, not public MinIO objects.
They contain scene information and accumulate on disk: configure storage access
and retention for your deployment. No automatic deletion is performed.

## Validation boundary

Regression tests cover strong-seed recovery, road barriers, narrow buildings,
supported height/probability splits, no-evidence fallback, courtyard geometry,
PBR/UV separation, flat-mode heights and unchanged scientific raster values.
They do not establish NYC accuracy or the trained model's geographic generality.
Evaluate boundary/instance accuracy and height errors against held-out reference
data separately from appearance. A competitor's tall extrusions are not height
ground truth, and a semantic IoU score is not an instance or elevation metric.
