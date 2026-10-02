# DepthWizard Phase 0 Representative Fixtures

This directory contains the frozen baseline fixtures and verification artifacts for the DepthWizard Hybrid LoD2 reconstruction and rendering pipeline.

## 1. Fixture Overview

As required by Section 4 of the `HYBRID_RENDERING_IMPLEMENTATION_PLAYBOOK.md`, five representative fixtures are preserved:

| Fixture ID | Category | Characteristics | Key Test Role |
|---|---|---|---|
| `dense_flat_urban` | Commercial / Urban core | Dense multi-height flat roofs (15–45m), narrow alleys, rectilinear boundaries | Party wall separation, rectangular regularization, flat height accuracy |
| `residential_pitched_urban` | Suburban residential | Detached homes (6–12m), gable/hip pitches, lawns, roads | LoD2 roof-plane fitting, pitch vs flat fallback, no over-segmentation |
| `sparse_urban` | Industrial / Commercial | Isolated large footprints, extensive parking/ground | Noise suppression, perimeter isolation without neighbor interference |
| `hilly_urban` | Sloped terrain settlement | Buildings on steep terrain gradient (30–90m DTM relief) | Sloped ground wall base sampling, metric presentation, skirt generation |
| `vegetation_heavy` | Park / Forest mixed zone | Dense tree canopy (>55% vegetation), tree-occluded buildings | Presentation selector retaining terrain, road/vegetation barrier integrity |

## 2. Directory Layout per Fixture

Each fixture directory (`fixtures/<fixture_id>/`) contains:

```text
fixtures/<fixture_id>/
  source_rgb.tif           # 3-band Byte GeoTIFF optical source image
  source_rgb.png           # Encoded optical image (used for texture sampling)
  dtm.tif                  # 1-band Float32 bare-earth terrain elevation (meters)
  dsm.tif                  # 1-band Float32 digital surface model (meters)
  ndsm.tif                 # 1-band Float32 normalized digital surface model (h_AGL)
  final_semantic_class.tif # 1-band Byte semantic classes (0=UNKNOWN, 1=GROUND, 2=BUILDING, 3=ROAD, 4=VEG, 5=WATER)
  semantic_confidence.tif  # 1-band Float32 classification confidence [0.0, 1.0]
  building_probability.tif # 1-band Float32 building probability
  road_probability.tif     # 1-band Float32 road probability
  vegetation_probability.tif # 1-band Float32 vegetation probability
  candidate_mask.tif       # 1-band Byte thresholded building candidate mask
  cleaned_mask.tif         # 1-band Byte post-morphology building mask
  instance_labels.tif      # 1-band Int32 building instance labels
  native_baseline.glb      # glTF 2.0 Binary mesh generated with native C++ pipeline (Phase 0 baseline)
  sat2lod2_baseline.glb    # glTF 2.0 Binary mesh generated with Sat2LoD2 imported parts
  summary.json             # Reconstruction diagnostics summary with building stats and elevations
  metadata.json            # Spatial metadata, raster dimensions, GSD, and CRS definition
  fixed_camera_view.json   # Presets for fixed-camera verification (wide, oblique, close-up)
  screenshot_wide.png      # Rendered fixed-camera wide perspective view
  screenshot_oblique.png   # Rendered fixed-camera oblique perspective view
  screenshot_closeup.png   # Rendered fixed-camera close-up perspective view
```

## 3. Provenance and Compliance

Refer to `PROVENANCE_MANIFEST.json` in this directory for the full runtime data policy.
- **Height Authority**: The GAMUS-calibrated nDSM is the sole metric elevation authority.
- **No External GIS**: OSM, cadastral records, CityGML, and commercial 3D APIs are strictly prohibited from runtime reconstruction.
- **Reference LiDAR**: Permitted exclusively for offline ground-truth benchmarking; never passed into inference.

## 4. Running Baseline Verification

Run the Python verification harness to validate GLB compliance and compare against baseline:

```bash
# Validate a single fixture GLB
python3 scripts/baseline_harness.py validate-glb fixtures/dense_flat_urban/native_baseline.glb

# Compute and check scientific raster hashes
python3 scripts/baseline_harness.py hash-rasters fixtures/dense_flat_urban/

# Run complete regression comparison between candidate and baseline
python3 scripts/baseline_harness.py compare fixtures/dense_flat_urban/ <candidate_dir>/

# Verify all baseline fixtures
python3 scripts/baseline_harness.py verify-all-baselines fixtures
```
