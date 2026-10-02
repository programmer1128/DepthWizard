"""Tests for depthwizard.roofgraph.v1 contract and Python models."""

import json
from pathlib import Path
import pytest

from ml_services.common.contracts import (
    CoordinateConvention,
    CornerHint,
    RoofGraphScores,
    RoofSection,
    ProvenanceEntry,
    BuildingProposal,
    RoofGraphDocument,
)
from ml_services.common.geometry import (
    signed_area,
    is_ccw,
    is_cw,
    ensure_ccw,
    ensure_cw,
    strip_closing_vertex,
    remove_redundant_vertices,
    has_self_intersection,
    centre_to_edge,
    edge_to_centre,
)
from ml_services.common.validation import validate_roofgraph_dict, validate_against_json_schema

EXAMPLES_DIR = Path(__file__).resolve().parents[3] / "drogon_service" / "gis_service" / "contracts" / "examples"


def test_valid_minimal_fixture():
    with open(EXAMPLES_DIR / "valid_building_minimal.json") as f:
        data = json.load(f)
    is_valid, errors, warnings = validate_roofgraph_dict(data)
    assert is_valid, f"Validation failed with errors: {errors}"
    assert len(errors) == 0

    doc = RoofGraphDocument.model_validate(data)
    assert doc.raster_width == 512
    assert doc.coordinate_convention == CoordinateConvention.PIXEL_EDGE_COLUMN_ROW
    assert len(doc.buildings) == 1
    b = doc.buildings[0]
    assert b.id == "building-1"
    assert len(b.footprint_proposal) == 4
    assert b.scores.semantic == 0.95
    assert len(b.roof_sections) == 1


def test_valid_complex_fixture():
    with open(EXAMPLES_DIR / "valid_building_complex.json") as f:
        data = json.load(f)
    is_valid, errors, warnings = validate_roofgraph_dict(data)
    assert is_valid, f"Validation failed with errors: {errors}"
    assert len(errors) == 0

    doc = RoofGraphDocument.model_validate(data)
    assert doc.raster_width == 1024
    assert len(doc.buildings) == 2
    b1, b2 = doc.buildings[0], doc.buildings[1]
    assert len(b1.holes) == 1
    assert len(b2.roof_sections) == 2
    assert b2.roof_sections[0].adjacent_sections == ["102-south-pitch"]
    assert b2.roof_sections[1].adjacent_sections == ["102-north-pitch"]


def test_python_round_trip_serialization():
    with open(EXAMPLES_DIR / "valid_building_complex.json") as f:
        data = json.load(f)
    doc = RoofGraphDocument.model_validate(data)
    serialized = doc.model_dump(by_alias=True, exclude_none=True)
    doc2 = RoofGraphDocument.model_validate(serialized)
    assert doc.model_dump() == doc2.model_dump()


def test_rejects_duplicate_building_ids():
    with open(EXAMPLES_DIR / "invalid_duplicate_ids.json") as f:
        data = json.load(f)
    is_valid, errors, warnings = validate_roofgraph_dict(data)
    assert not is_valid
    assert any("Duplicate building ID" in e for e in errors)


def test_rejects_out_of_bounds_coordinates():
    with open(EXAMPLES_DIR / "invalid_out_of_bounds.json") as f:
        data = json.load(f)
    is_valid, errors, warnings = validate_roofgraph_dict(data)
    assert not is_valid
    assert any("outside raster bounds" in e for e in errors)


def test_rejects_out_of_range_scores():
    with open(EXAMPLES_DIR / "invalid_scores_range.json") as f:
        data = json.load(f)
    is_valid, errors, warnings = validate_roofgraph_dict(data)
    assert not is_valid
    assert len(errors) > 0


def test_rejects_self_intersecting_polygons():
    with open(EXAMPLES_DIR / "invalid_self_intersection.json") as f:
        data = json.load(f)
    is_valid, errors, warnings = validate_roofgraph_dict(data)
    assert not is_valid
    assert any("self-intersects" in e for e in errors)


def test_rejects_redundant_closing_vertex():
    with open(EXAMPLES_DIR / "invalid_closing_vertex.json") as f:
        data = json.load(f)
    is_valid, errors, warnings = validate_roofgraph_dict(data)
    assert not is_valid
    assert any("duplicate closing vertex" in e for e in errors)


def test_rejects_too_few_vertices():
    with open(EXAMPLES_DIR / "invalid_too_few_vertices.json") as f:
        data = json.load(f)
    is_valid, errors, warnings = validate_roofgraph_dict(data)
    assert not is_valid
    assert len(errors) > 0


def test_coordinate_convention_centre_to_edge_and_back():
    centre_coords = [(10.0, 10.0), (20.0, 10.0), (20.0, 20.0)]
    edge_coords = centre_to_edge(centre_coords)
    assert edge_coords == [(10.5, 10.5), (20.5, 10.5), (20.5, 20.5)]
    recovered = edge_to_centre(edge_coords)
    assert recovered == centre_coords


def test_geometry_winding_and_signed_area():
    # CCW square: (0,0) -> (10,0) -> (10,10) -> (0,10)
    ccw_ring = [(0.0, 0.0), (10.0, 0.0), (10.0, 10.0), (0.0, 10.0)]
    area = signed_area(ccw_ring)
    assert area == 100.0
    assert is_ccw(ccw_ring)
    assert not is_cw(ccw_ring)

    cw_ring = list(reversed(ccw_ring))
    assert signed_area(cw_ring) == -100.0
    assert is_cw(cw_ring)
    assert not is_ccw(cw_ring)

    assert ensure_ccw(cw_ring) == ccw_ring
    assert ensure_cw(ccw_ring) == cw_ring


def test_strip_closing_vertex():
    open_ring = [(0.0, 0.0), (10.0, 0.0), (10.0, 10.0)]
    closed_ring = [(0.0, 0.0), (10.0, 0.0), (10.0, 10.0), (0.0, 0.0)]

    cleaned, stripped = strip_closing_vertex(closed_ring)
    assert stripped is True
    assert cleaned == open_ring

    cleaned_noop, stripped_noop = strip_closing_vertex(open_ring)
    assert stripped_noop is False
    assert cleaned_noop == open_ring


def test_non_authoritative_height_class_hint():
    corner = CornerHint(xy=(15.0, 25.0), height_class_m=12.5, score=0.95)
    assert corner.height_class_m == 12.5
    corner_no_hint = CornerHint(xy=(15.0, 25.0), score=0.8)
    assert corner_no_hint.height_class_m is None
