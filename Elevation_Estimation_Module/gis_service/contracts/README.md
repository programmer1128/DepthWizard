# RoofGraph contract (`depthwizard.roofgraph.v1`)

The one format for proposal geometry passed between the C++ backend and the
SAM2/KIBS services. These three implementations must agree:

| Implementation | File |
|---|---|
| JSON Schema (structure only) | `roofgraph-v1.schema.json` |
| C++ parser, validator and serializer | `BuildingReconstruction/HybridRoofGraphTypes.h`, `HybridRoofGraphImporter.{h,cc}` |
| Python models | `ml_services/common/contracts.py`, `geometry.py`, `validation.py` |

The schema checks structure only. The C++ importer and the Pydantic models
also enforce the geometric rules below, using the same arithmetic.

## Wire format

Keys are snake_case and match the schema's property names. Nothing is
camelCased. In Python, `schema` is exposed as `schema_id`, and
`height_class_m` as `height_class_hint_m`. Both serialize back to their wire
names.

```json
{
  "schema": "depthwizard.roofgraph.v1",
  "raster_width": 1024,
  "raster_height": 1024,
  "coordinate_convention": "pixel_edge_column_row",
  "metadata": {"scene_id": "tile-43", "crs": "EPSG:32632",
               "geo_transform": [500000.0, 0.5, 0.0, 2000000.0, 0.0, -0.5], "gsd": 0.5},
  "buildings": [{
    "id": "candidate-17",
    "footprint_proposal": [[100.0, 100.0], [300.0, 100.0], [300.0, 300.0], [100.0, 300.0]],
    "roofprint_proposal": [[102.0, 98.0], [302.0, 98.0], [302.0, 298.0], [102.0, 298.0]],
    "holes": [[[160.0, 160.0], [160.0, 240.0], [240.0, 240.0], [240.0, 160.0]]],
    "scores": {"semantic": 0.98, "ndsm": 0.91, "sam2": 0.94},
    "roof_sections": [{
      "id": "17-0",
      "polygon": [[102.0, 98.0], [302.0, 98.0], [302.0, 298.0], [102.0, 298.0]],
      "holes": [],
      "corners": [{"xy": [102.0, 98.0], "height_class_m": 12.0, "score": 0.88, "corner_type": "eave_corner"}],
      "type_hint": "flat",
      "adjacent_sections": [],
      "score": 0.92
    }],
    "provenance": [{"stage": "sam2_refinement", "source": "sam2.1-hiera-base-plus",
                    "timestamp": "2026-10-02T10:00:02Z", "details": {"candidates": 3}}]
  }]
}
```

### Required fields

- **Document:** `schema`, `raster_width`, `raster_height`, `coordinate_convention` and `buildings`.
- **Building:** `id` and `footprint_proposal`.
- **Roof section:** `id` and `polygon`.
- **Corner:** `xy`.
- **Provenance entry:** `stage` and `source`.

### Optional fields

- **Absent unless given:** `metadata` and its keys, `roofprint_proposal`, `scores.sam2`, `scores.kibs`, `scores.combined`, `height_class_m`, `timestamp` and `details`.
- **`sam2`, `kibs`, `combined`:** absent or `null` means the expert did not run. `0.0` means it ran and scored zero.
- **`roofprint_proposal`:** absent, `null` or `[]` means no roofprint was proposed. It is never silently replaced by the footprint.
- **Everything else** has a default: an empty array, `0.0`, or `"unknown"`.

Unknown keys are accepted and dropped by both parsers. A new field needs a new
schema version.

## Coordinates

- Coordinates are `(column, row)` in pixel-edge units. `(0, 0)` is the
  top-left corner of the raster and `(raster_width, raster_height)` is the
  bottom-right corner. Every vertex must lie inside `[0, W] x [0, H]`.
- `pixel_edge_column_row` is the only accepted convention. Any other value,
  including `pixel_centre_column_row`, is rejected rather than converted.
  Nothing is ever shifted by half a pixel. (Sat2Lod2Importer adds `+0.5`
  because SAT2LoD2 reports pixel-centre indices; that importer is separate
  and unchanged.)
- Projection is direct: `easting = gt[0] + column*gt[1] + row*gt[2]` and
  `northing = gt[3] + column*gt[4] + row*gt[5]`.
- **For producers:** a mask outline from `cv2.findContours` holds the indices
  of boundary pixel centres, half a pixel inside the true edge. Do not emit it
  as-is, and do not add 0.5. Trace pixel edges instead, for example with
  `rasterio.features.shapes(mask, transform=Affine.identity())`, which follows
  pixel boundaries.

## Geometry rules

A ring is an array of `[column, row]` number pairs. Each ring is checked in
this order:

1. **Open ring.** The first vertex is not repeated at the end, and no two
   consecutive vertices are equal.
2. **Enough vertices.** At least 3 distinct vertices, and at most 10000.
3. **Not flat.** The vertices are not all collinear.
4. **Simple.** Edges that are not adjacent never cross or touch, and adjacent
   edges never fold back onto each other.
5. **Non-zero area.**

Winding:
- Outer rings (`footprint_proposal`, `roofprint_proposal`, section `polygon`) have positive shoelace area on `(column, row)`. Because rows grow downwards, a positive ring looks clockwise on screen.
- Holes have negative area.
- A ring with the wrong winding is reversed with a `winding` warning; this is the only silent-safe repair.

Holes:
- Building `holes` belong to the footprint.
- Each hole lies strictly inside its outer ring, touching neither it nor another hole.
- Holes never overlap each other.

Native `FootprintPolygon<PixelPoint>` rings are oriented so that they are
counter-clockwise in projected space. For north-up rasters that is the
reverse of the contract's winding. Use `HybridRoofGraphImporter::projectPolygon`,
which projects and re-orients, rather than copying rings across.

Building IDs are unique within the document. Section IDs are unique across the
whole document. `adjacent_sections` may only name other sections of the same
building, each at most once.

## Height authority

The contract carries no metric height. `height_class_m` is an optional,
advisory KIBS class: it must be finite and ≥ 0. In C++ it is
`std::optional<double> heightClassHintMetres`; in Python it is
`height_class_hint_m`. No importer function reads it into a building or roof
height. Heights come only from the backend's corrected nDSM. All scores are
finite numbers in `[0, 1]`; strings and booleans are rejected.

## Error codes

Every error starts with a stable code. C++ and Python use the same codes.

| Code | Meaning |
|---|---|
| `json_syntax` | Invalid JSON. Includes `NaN`/`Infinity` tokens, duplicate keys and trailing data. |
| `document_too_large` | The document is larger than 64 MiB. |
| `document_type` | The root is not an object. |
| `schema` | `schema` is not `depthwizard.roofgraph.v1`. |
| `raster_size` | A raster dimension is not a positive integer. |
| `coordinate_convention` | Missing, or not `pixel_edge_column_row`. |
| `buildings` | `buildings` is not an array. |
| `field_type` | A value has the wrong JSON type. |
| `missing_id` | A building or section has no ID. |
| `duplicate_id` | A building or section ID is repeated. |
| `ring_type` | A ring is not an array of `[column, row]` pairs. |
| `too_many_vertices` | A ring has more than 10000 vertices. |
| `non_finite` | A number is NaN or infinite. |
| `out_of_bounds` | A vertex or corner is outside `[0, W] x [0, H]`. |
| `closing_vertex` | A ring repeats its first vertex at the end. |
| `repeated_vertex` | A ring repeats consecutive vertices. |
| `too_few_vertices` | A ring has fewer than 3 distinct vertices. |
| `degenerate_ring` | A ring has zero area. |
| `self_intersection` | A ring is not simple. |
| `invalid_hole` | A hole is outside its outer ring, touches it, or overlaps another hole. |
| `score_range` | A score is outside `[0, 1]`. |
| `height_hint` | `height_class_m` is negative or not a number. |
| `adjacency` | An adjacency entry names the section itself, an unknown section, or the same section twice. |
| `provenance` | A provenance entry is not an object, or lacks `stage` or `source`. |
| `metadata` | A metadata value is invalid. |

## Strict and Repair modes (C++)

`RoofGraphValidationMode::Strict` is the default. It fails the document on any
violation and returns no buildings.

`RoofGraphValidationMode::Repair` fixes what it can without inventing data:
- It clamps vertices to the raster.
- It strips closing and repeated vertices.
- It replaces a self-intersecting ring with its largest valid part.
- It clamps scores.
- It drops an invalid hole, corner, hint, adjacency entry, section or building.
- It records every change as a warning.

Document-level codes (the first seven in the table) fail in both modes. The
Python models implement Strict mode, plus winding canonicalization.

## Canonical form and cross-language round trip

`HybridRoofGraphImporter::toJson` and `RoofGraphDocument.to_dict()` both
produce the canonical form:
- every non-optional field is written;
- absent optional fields are omitted;
- rings are open and use the contract winding.

All `examples/valid_*.json` files are stored in canonical form. Both test
suites require that parsing and re-serializing each one gives the same JSON
value. `examples/valid_python_serialized.json` is written by the Python models,
and the C++ suite re-serializes it unchanged. Each `examples/invalid_*.json`
file has one defect, and its `x_expected_error` key names the code that both
suites must report.

```bash
# C++
cmake --build drogon_service/gis_service/build-integration --target hybrid_roofgraph_importer_test
drogon_service/gis_service/build-integration/test/hybrid_roofgraph_importer_test
# Python (pip install -r ml_services/common/requirements.txt)
python -m pytest ml_services
python -m ml_services.common.tests.test_contracts --write-fixture   # after changing python_fixture()
```

## Scope

Phase 1 defines the contract only. Converting proposals into
`BuildingInstance`s (routing, fusion, height estimation, meshing) belongs to
Phase 6 and later. That conversion must keep the string IDs traceable and
take heights from the nDSM.
