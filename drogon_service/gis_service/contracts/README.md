# DepthWizard RoofGraph Contract (`depthwizard.roofgraph.v1`)

## 1. Overview and Purpose

The `depthwizard.roofgraph.v1` contract defines the canonical, versioned data interchange format between:
1. **Drogon C++ GIS Backend**: Semantic instance segmentation, calibrated GAMUS nDSM height authority, DTM/DSM fusion, and watertight LoD2 mesh generation.
2. **SAM 2.1 Microservice**: Prompted polygon boundary refinement and instance separation.
3. **KIBS Microservice**: Deep roof-section decomposition, adjacency topology, and corner height-class priors.
4. **Hybrid Expert Router & Fusion Layer**: Confidence-gated routing between native C++ reconstruction and ML-assisted proposals.

This contract prevents microservices from communicating through undocumented, model-specific, or lossy ad-hoc formats.

---

## 2. Coordinate System & Conventions

### Explicit Declaration
All spatial boundaries in the document are expressed in 2D image coordinates `(column, row)`. Every document must explicitly declare its coordinate frame:
- `"coordinate_convention": "pixel_edge_column_row"` (Default & Canonical)
- `"coordinate_convention": "pixel_centre_column_row"` (Tolerated for legacy compatibility)

### Elimination of the Legacy +0.5 Shift
In legacy `Sat2Lod2Importer`, coordinates were silently shifted by `+0.5` under the assumption that inputs were pixel-centre indices. 

In `depthwizard.roofgraph.v1`:
- Canonical coordinates refer to **pixel edges**, where `(0.0, 0.0)` represents the exact top-left corner of the raster extent.
- The projection to geographic/projected coordinates is direct:
  $$\text{easting} = \text{gt}[0] + \text{col} \times \text{gt}[1] + \text{row} \times \text{gt}[2]$$
  $$\text{northing} = \text{gt}[3] + \text{col} \times \text{gt}[4] + \text{row} \times \text{gt}[5]$$
  **No implicit or silent `+0.5` offset is applied.**
- When `"pixel_centre_column_row"` is explicitly supplied, `HybridRoofGraphImporter` logs a warning and shifts coordinates by `+0.5` to convert to canonical pixel-edge coordinates.

---

## 3. Invariants and Validation Rules

1. **Finite Raster-Bounded Coordinates**:
   - All coordinate values must be finite floating-point numbers (`!std::isnan`, `!std::isinf`).
   - All vertices must lie within raster bounds: $0.0 \le \text{column} \le \text{raster\_width}$ and $0.0 \le \text{row} \le \text{raster\_height}$.
2. **Open Rings (No Closing Duplicate Vertex)**:
   - Serialized rings must **not** repeat the initial vertex at the end (e.g. a quadrilateral is serialized with 4 vertices, not 5).
   - In strict validation mode, duplicate closing vertices cause rejection; in lenient mode, they are stripped with a recorded warning.
3. **Minimum Unique Vertices**:
   - Every ring (footprints, roofprints, holes, section polygons) must contain at least 3 unique, non-collinear vertices.
4. **Winding Orientation**:
   - Outer rings must have Counter-Clockwise (CCW) winding in $(c, r)$ Cartesian space ($\text{signed\_area} > 0$).
   - Hole rings (inner courtyards) must have Clockwise (CW) winding ($\text{signed\_area} < 0$).
5. **Simplicity and Non-Self-Intersection**:
   - Rings must be simple polygons with no non-adjacent edge intersections.
6. **Unique Identifiers**:
   - Every building candidate must have a unique `id` across the document.
   - Every roof section must have a unique `id` within the building.
7. **Bounded Confidence & Metric Scores**:
   - All scores (`semantic`, `ndsm`, `sam2`, `kibs`, `combined`, corner scores, section scores) must reside in $[0.0, 1.0]$.
8. **Height Authority Invariant**:
   - `height_class_m` in corner hints is strictly advisory (a discrete prior from KIBS).
   - GAMUS-calibrated nDSM is the **sole metric height authority** for physical 3D elevation.
9. **Extensibility & Forward Compatibility**:
   - Unknown JSON fields are tolerated by both Pydantic (`extra="allow"`) and C++ JsonCpp parsers.

---

## 4. Document Structure Reference

```json
{
  "schema": "depthwizard.roofgraph.v1",
  "raster_width": 1024,
  "raster_height": 1024,
  "coordinate_convention": "pixel_edge_column_row",
  "metadata": {
    "scene_id": "tile_reconstruction_01",
    "crs": "EPSG:32632",
    "geo_transform": [500000.0, 0.5, 0.0, 2000000.0, 0.0, -0.5],
    "gsd": 0.5
  },
  "buildings": [
    {
      "id": "candidate-101",
      "footprint_proposal": [[100.0, 100.0], [300.0, 100.0], [300.0, 300.0], [100.0, 300.0]],
      "roofprint_proposal": [[102.0, 98.0], [302.0, 98.0], [302.0, 298.0], [102.0, 298.0]],
      "holes": [
        [[160.0, 160.0], [160.0, 240.0], [240.0, 240.0], [240.0, 160.0]]
      ],
      "scores": {
        "semantic": 0.98,
        "ndsm": 0.91,
        "sam2": 0.94,
        "kibs": 0.85,
        "combined": 0.93
      },
      "roof_sections": [
        {
          "id": "101-facet-0",
          "polygon": [[102.0, 98.0], [302.0, 98.0], [302.0, 298.0], [102.0, 298.0]],
          "holes": [],
          "corners": [
            {"xy": [102.0, 98.0], "height_class_m": 12.0, "score": 0.88, "corner_type": "eave_corner"}
          ],
          "type_hint": "flat",
          "adjacent_sections": [],
          "score": 0.92
        }
      ],
      "provenance": [
        {
          "stage": "semantic_detection",
          "source": "native_ndsm",
          "timestamp": "2026-10-02T10:00:00Z"
        }
      ]
    }
  ]
}
```

---

## 5. Directory Map

- `drogon_service/gis_service/contracts/roofgraph-v1.schema.json`: JSON Schema (Draft 2020-12).
- `drogon_service/gis_service/contracts/examples/`: Shared valid and invalid fixture JSON files.
- `drogon_service/gis_service/BuildingReconstruction/HybridRoofGraphTypes.h`: C++ domain structures.
- `drogon_service/gis_service/BuildingReconstruction/HybridRoofGraphImporter.{h,cc}`: C++ parser, validator, and serializer.
- `drogon_service/gis_service/test/HybridRoofGraphImporter_test.cc`: C++ unit and round-trip tests.
- `ml_services/common/contracts.py`: Pydantic v2 data models with validators.
- `ml_services/common/geometry.py`: Geometric utilities (shoelace formula, winding, self-intersection, coordinate conversion).
- `ml_services/common/validation.py`: Schema & invariant validation helpers.
- `ml_services/common/tests/test_contracts.py`: Python pytest suite.
