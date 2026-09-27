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
   edges while assigning ambiguous pixels. It does not normalize distance
   against the largest building in the scene.
   Every original mask pixel keeps a label. Poorly supported cuts, excessive
   markers and single-core components retain the original component.

4. Each instance is vectorized and gets its own robust height estimate. The
   optional exterior dilation is disabled by default. Metric RDP simplification
   starts at 4 m and backs off when it violates area or ring topology. Supported
   rectangles require at least 84% box fill, supported corners, and 96% convex
   hull solidity. The existing Manhattan fitter and CGAL closed-contour
   regularizer each work within a 3 m corner adjustment budget. GEOS-backed
   topology-preserving simplification can remove remaining small steps from the
   complete polygon while retaining its courtyards. Every candidate must still
   pass area, courtyard, mask IoU, and neighbouring-instance checks. The exact
   observed boundary remains the fallback.
5. LoD2 decomposition uses up to three rectangular blocks by default. A 92%
   coverage setting admits supported L/T forms, while a connected-residual
   check rejects missing wings. Complex courtyards and shapes that need more
   blocks retain a continuous outer footprint.
6. Terrain, colored walls and roofs become separate Draco primitives.
   Buildings have no photographic UV texture; PBR materials and hard normals
   provide face shading. The GLB's terrain texture conceals the photographic
   roof beneath emitted buildings plus a 1 m fringe; the original optical
   image and scientific rasters are unchanged. Urban scenes have no pedestal; terrain scenes retain
   skirts down to a common base 2 m below the scene's sampled minimum.

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
