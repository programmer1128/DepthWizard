"""Tests for the depthwizard.roofgraph.v1 Python models.

Run from the repository root:
  python -m pytest ml_services
Regenerate the Python-serialized fixture read by the C++ tests:
  python -m ml_services.common.tests.test_contracts --write-fixture
"""

import json
import math
import sys
import warnings
from pathlib import Path

import pytest

from ml_services.common import geometry
from ml_services.common.contracts import (
    MAX_RING_VERTICES,
    BuildingProposal,
    CornerHint,
    ProvenanceEntry,
    RoofGraphContractError,
    RoofGraphDocument,
    RoofGraphMetadata,
    RoofGraphRepairWarning,
    RoofGraphScores,
    RoofSection,
    load_json,
    parse_roofgraph,
    parse_roofgraph_json,
)
from ml_services.common.validation import CONTRACTS_DIR, load_schema, validate_against_json_schema, validate_roofgraph_dict

EXAMPLES = CONTRACTS_DIR / "examples"
PYTHON_FIXTURE = EXAMPLES / "valid_python_serialized.json"
VALID = sorted(EXAMPLES.glob("valid_*.json"))
INVALID = sorted(EXAMPLES.glob("invalid_*.json"))
# Invalid fixtures whose defect is structural, so the JSON Schema alone rejects them.
SCHEMA_DETECTABLE = {
    "invalid_boolean_coordinate.json", "invalid_camel_case_keys.json", "invalid_missing_convention.json",
    "invalid_nan_coordinates.json", "invalid_negative_height_hint.json", "invalid_pixel_centre_convention.json",
    "invalid_provenance_string.json", "invalid_score_type.json", "invalid_scores_range.json",
    "invalid_too_few_vertices.json",
}


def rect(left, top, right, bottom):
    """Positive image-space area: the outer-ring winding."""
    return [(left, top), (right, top), (right, bottom), (left, bottom)]


def hole(left, top, right, bottom):
    """Negative image-space area: the hole winding."""
    return [(left, top), (left, bottom), (right, bottom), (right, top)]


def minimal(**building):
    data = {"schema": "depthwizard.roofgraph.v1", "raster_width": 100, "raster_height": 100,
            "coordinate_convention": "pixel_edge_column_row",
            "buildings": [dict({"id": "b", "footprint_proposal": rect(10, 10, 50, 40)}, **building)]}
    return data


def codes(error: RoofGraphContractError):
    return {message.split(":", 1)[0] for message in error.errors}


def python_fixture() -> RoofGraphDocument:
    """A document built with the Python models; C++ must reserialize it unchanged."""
    return RoofGraphDocument.create(
        raster_width=640, raster_height=480,
        metadata=RoofGraphMetadata(scene_id="python-producer", crs="EPSG:32643",
                                   geo_transform=(712000.0, 0.3, 0.0, 3142000.0, 0.0, -0.3), gsd=0.3),
        buildings=[
            BuildingProposal(
                id="sam2-7",
                footprint_proposal=rect(20.25, 30.5, 140.0, 90.75),
                roofprint_proposal=rect(21.0, 28.0, 141.5, 88.0),
                holes=[hole(60.0, 45.0, 90.0, 70.0)],
                scores=RoofGraphScores(semantic=0.875, ndsm=0.8125, sam2=0.9375),
                roof_sections=[
                    RoofSection(id="sam2-7-0", polygon=rect(21.0, 28.0, 81.0, 88.0), type_hint="flat",
                                adjacent_sections=["sam2-7-1"], score=0.5,
                                corners=[CornerHint(xy=(21.0, 28.0), height_class_hint_m=9.0, score=0.75)]),
                    RoofSection(id="sam2-7-1", polygon=rect(81.0, 28.0, 141.5, 88.0),
                                adjacent_sections=["sam2-7-0"]),
                ],
                provenance=[ProvenanceEntry(stage="sam2_refinement", source="sam2.1-hiera-base-plus",
                                            timestamp="2026-10-02T12:00:00Z",
                                            details={"box_prompt": [18, 26, 144, 93], "candidates": 3,
                                                     "note": None})],
            ),
            BuildingProposal(id="native-8", footprint_proposal=rect(300, 200, 360, 260),
                             scores=RoofGraphScores(semantic=1.0, ndsm=0.0)),
        ])


# --- Shared fixtures (the same files the C++ tests read) ----------------------

@pytest.mark.parametrize("path", VALID, ids=lambda p: p.name)
def test_valid_fixtures_parse_and_are_in_canonical_form(path):
    raw = json.loads(path.read_text())
    with warnings.catch_warnings():
        warnings.simplefilter("error", RoofGraphRepairWarning)
        document = parse_roofgraph_json(path.read_text())
    assert document.to_dict() == raw
    assert validate_against_json_schema(raw) == []


@pytest.mark.parametrize("path", INVALID, ids=lambda p: p.name)
def test_invalid_fixtures_are_rejected_with_their_code(path):
    raw = load_json(path.read_text())
    expected = raw["x_expected_error"]
    with pytest.raises(RoofGraphContractError) as caught:
        parse_roofgraph(raw)
    assert expected in codes(caught.value), caught.value.errors
    valid, errors, _ = validate_roofgraph_dict(raw)
    assert not valid
    if path.name in SCHEMA_DETECTABLE:
        assert validate_against_json_schema(raw), "the JSON Schema should reject this fixture"


def test_shared_fixture_corpus_is_complete():
    assert {p.name for p in VALID} >= {"valid_building_minimal.json", "valid_building_complex.json",
                                       PYTHON_FIXTURE.name}
    assert len(INVALID) >= 20


def test_python_serialized_fixture_is_current():
    """C++ (EveryValidFixtureReserializesToItsCanonicalForm) reads this file."""
    assert json.loads(PYTHON_FIXTURE.read_text()) == python_fixture().to_dict()


# --- Wire format --------------------------------------------------------------

def test_serialization_uses_the_snake_case_schema_property_names():
    data = python_fixture().to_dict()
    assert "schema" in data and "schema_id" not in data
    assert json.loads(python_fixture().model_dump_json(exclude_none=True))["schema"] == "depthwizard.roofgraph.v1"

    schema = load_schema()
    declared = set(schema["properties"])
    for definition in schema["$defs"].values():
        declared |= set(definition.get("properties", {}))
    declared |= set(schema["properties"]["metadata"]["properties"])

    def keys(value):
        if isinstance(value, dict):
            for key, item in value.items():
                yield key
                if key != "details":
                    yield from keys(item)
        elif isinstance(value, list):
            for item in value:
                yield from keys(item)

    emitted = set(keys(data))
    assert emitted <= declared, emitted - declared
    assert all(key == key.lower() for key in emitted)


def test_camel_case_documents_are_rejected():
    data = minimal()
    data["rasterWidth"] = data.pop("raster_width")
    with pytest.raises(RoofGraphContractError) as caught:
        parse_roofgraph(data)
    assert "raster_size" in codes(caught.value)


def test_constant_fields_are_required_when_parsing():
    for key in ("schema", "coordinate_convention", "buildings", "raster_width"):
        data = minimal()
        data.pop(key)
        with pytest.raises(RoofGraphContractError):
            parse_roofgraph(data)


# --- Coordinate convention ------------------------------------------------------

def test_pixel_edge_coordinates_are_never_shifted():
    data = minimal(footprint_proposal=rect(0, 0, 100, 100))
    document = parse_roofgraph(data)
    assert document.buildings[0].footprint_proposal == [(0.0, 0.0), (100.0, 0.0), (100.0, 100.0), (0.0, 100.0)]
    assert document.to_dict()["buildings"][0]["footprint_proposal"] == [[0.0, 0.0], [100.0, 0.0],
                                                                        [100.0, 100.0], [0.0, 100.0]]


def test_pixel_centre_convention_is_rejected_not_converted():
    data = minimal()
    data["coordinate_convention"] = "pixel_centre_column_row"
    with pytest.raises(RoofGraphContractError) as caught:
        parse_roofgraph(data)
    assert "coordinate_convention" in codes(caught.value)


# --- Height authority -----------------------------------------------------------

def test_height_class_is_an_optional_advisory_hint():
    assert CornerHint(xy=(1, 1)).height_class_hint_m is None
    corner = CornerHint.model_validate({"xy": [1, 1], "height_class_m": 12.5})
    assert corner.height_class_hint_m == 12.5
    assert corner.model_dump(mode="json", exclude_none=True) == {
        "xy": [1.0, 1.0], "height_class_m": 12.5, "score": 0.0, "corner_type": "unknown"}
    assert "height_class_m" not in CornerHint(xy=(1, 1)).model_dump(mode="json", exclude_none=True)
    for bad in (-1.0, "12", True, math.nan, math.inf):
        with pytest.raises(Exception):
            CornerHint.model_validate({"xy": [1, 1], "height_class_m": bad})
    height_fields = [name for name in BuildingProposal.model_fields if "height" in name] + \
                    [name for name in RoofSection.model_fields if "height" in name]
    assert height_fields == []


# --- Strict values ----------------------------------------------------------------

@pytest.mark.parametrize("bad, code", [("0.9", "field_type"), (True, "field_type"), (math.nan, "non_finite"),
                                       (1.5, "score_range"), (-0.1, "score_range")])
def test_scores_are_strict_numbers_in_unit_range(bad, code):
    with pytest.raises(RoofGraphContractError) as caught:
        parse_roofgraph(minimal(scores={"semantic": bad}))
    assert code in codes(caught.value)


def test_expert_scores_are_absent_when_the_expert_did_not_run():
    document = parse_roofgraph(minimal(scores={"semantic": 0.5, "ndsm": 0.25, "sam2": None}))
    assert document.buildings[0].scores.sam2 is None
    assert document.to_dict()["buildings"][0]["scores"] == {"semantic": 0.5, "ndsm": 0.25}


def test_non_finite_coordinates_are_rejected():
    with pytest.raises(RoofGraphContractError) as caught:
        parse_roofgraph(minimal(footprint_proposal=[(10, 10), (math.inf, 10), (50, 40)]))
    assert "non_finite" in codes(caught.value)


def test_strict_json_decoding():
    for text in ('{"a": 1, "a": 2}', '{"x": NaN}', '[Infinity]', '{} trailing', '{'):
        with pytest.raises(RoofGraphContractError) as caught:
            load_json(text)
        assert codes(caught.value) == {"json_syntax"}


def test_vertex_limit():
    ring = [(5000 + 4000 * math.cos(2 * math.pi * i / (MAX_RING_VERTICES + 1)),
             5000 + 4000 * math.sin(2 * math.pi * i / (MAX_RING_VERTICES + 1))) for i in range(MAX_RING_VERTICES + 1)]
    data = minimal(footprint_proposal=ring)
    data["raster_width"] = data["raster_height"] = 10000
    with pytest.raises(RoofGraphContractError) as caught:
        parse_roofgraph(data)
    assert "too_many_vertices" in codes(caught.value)


# --- Winding and topology ---------------------------------------------------------

def test_wrong_winding_is_reversed_with_a_warning():
    data = json.loads(json.dumps(minimal(footprint_proposal=rect(10, 10, 50, 40)[::-1],
                                         holes=[rect(20, 20, 30, 30)])))
    with pytest.warns(RoofGraphRepairWarning):
        document = parse_roofgraph(data)
    building = document.buildings[0]
    assert geometry.signed_area(building.footprint_proposal) > 0
    assert geometry.signed_area(building.holes[0]) < 0
    valid, errors, notes = validate_roofgraph_dict(data)
    assert valid, errors
    assert len(notes) == 2 and all(note.startswith("winding:") for note in notes)


def test_roofprint_is_kept_distinct_from_the_footprint():
    document = parse_roofgraph(minimal(roofprint_proposal=[]))
    assert document.buildings[0].roofprint_proposal is None
    assert "roofprint_proposal" not in document.to_dict()["buildings"][0]
    document = parse_roofgraph(minimal(roofprint_proposal=rect(12, 8, 52, 38)))
    assert document.buildings[0].roofprint_proposal == rect(12, 8, 52, 38)


def test_section_ids_are_unique_across_the_document():
    data = minimal(roof_sections=[{"id": "s", "polygon": rect(10, 10, 50, 40)}])
    data["buildings"].append({"id": "c", "footprint_proposal": rect(60, 10, 90, 40),
                              "roof_sections": [{"id": "s", "polygon": rect(60, 10, 90, 40)}]})
    with pytest.raises(RoofGraphContractError) as caught:
        parse_roofgraph(data)
    assert "duplicate_id" in codes(caught.value)


# --- Geometry primitives (identical to the C++ importer) --------------------------

def test_segment_intersection_counts_touching():
    assert geometry.segments_intersect((0, 0), (10, 10), (0, 10), (10, 0))
    assert geometry.segments_intersect((0, 0), (10, 0), (10, 0), (20, 5))   # Shared endpoint.
    assert geometry.segments_intersect((0, 0), (10, 0), (5, 0), (15, 0))    # Collinear overlap.
    assert not geometry.segments_intersect((0, 0), (10, 0), (0, 1), (10, 1))


def test_ring_problems():
    assert geometry.ring_problem(rect(0, 0, 10, 10)) is None
    assert geometry.ring_problem(rect(0, 0, 10, 10) + [(0, 0)])[0] == "closing_vertex"
    assert geometry.ring_problem([(0, 0), (0, 0), (10, 0), (10, 10)])[0] == "repeated_vertex"
    assert geometry.ring_problem([(0, 0), (5, 0), (10, 0)])[0] == "degenerate_ring"
    assert geometry.ring_problem([(0, 0), (10, 10), (10, 0), (0, 10)])[0] == "self_intersection"
    assert geometry.ring_problem([(0, 0), (5, 5), (10, 0), (10, 10), (5, 5), (0, 10)])[0] == "self_intersection"
    assert geometry.ring_problem([(0, 0), (10, 0), (5, 0), (5, 5)])[0] == "self_intersection"  # Spike.


def test_hole_problems():
    outer = rect(0, 0, 100, 100)
    assert geometry.hole_problem(outer, [hole(10, 10, 20, 20), hole(30, 30, 40, 40)]) is None
    assert geometry.hole_problem(outer, [hole(90, 90, 110, 110)])[0] == "invalid_hole"
    assert geometry.hole_problem(outer, [hole(0, 10, 20, 20)])[0] == "invalid_hole"      # Touches the shell.
    assert geometry.hole_problem(outer, [hole(10, 10, 50, 50), hole(20, 20, 30, 30)])[0] == "invalid_hole"


if __name__ == "__main__" and "--write-fixture" in sys.argv:
    PYTHON_FIXTURE.write_text(python_fixture().to_json(indent=2) + "\n")
    print(f"wrote {PYTHON_FIXTURE}")
