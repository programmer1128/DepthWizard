"""Pydantic v2 models for the depthwizard.roofgraph.v1 contract.

The wire format is snake_case: exactly the property names in
contracts/roofgraph-v1.schema.json, which HybridRoofGraphImporter.cc reads.
Field names are therefore serialized as they are. The two aliases are
"schema" (which would shadow BaseModel.schema) and "height_class_m", exposed
in Python as height_class_hint_m to make its advisory status explicit.

The models validate strictly, like the C++ importer in Strict mode, with one
canonicalization: rings with the wrong winding are reversed and a
RoofGraphRepairWarning is issued. Error messages start with the same stable
codes the C++ importer uses ("out_of_bounds: ...").

Use parse_roofgraph / parse_roofgraph_json to read untrusted documents and
RoofGraphDocument.to_json to write them.
"""

import json
import math
import re
import warnings
from typing import Annotated, Any, Dict, List, Literal, Optional, Tuple

from pydantic import BaseModel, BeforeValidator, ConfigDict, Field, ValidationError, field_validator, model_validator

from . import geometry

SCHEMA_ID = "depthwizard.roofgraph.v1"
COORDINATE_CONVENTION = "pixel_edge_column_row"
MAX_RING_VERTICES = 10000
MAX_DOCUMENT_BYTES = 64 << 20

ERROR_CODES = frozenset({
    "json_syntax", "document_too_large", "document_type", "schema", "raster_size", "coordinate_convention",
    "buildings", "metadata", "field_type", "missing_id", "duplicate_id", "ring_type", "too_many_vertices",
    "non_finite", "out_of_bounds", "closing_vertex", "repeated_vertex", "too_few_vertices", "degenerate_ring",
    "self_intersection", "invalid_hole", "score_range", "height_hint", "adjacency", "provenance",
})


class RoofGraphRepairWarning(UserWarning):
    """A value was canonicalized (ring winding reversed)."""


class RoofGraphContractError(ValueError):
    """A document violates the contract; errors are 'code: location: message' strings."""

    def __init__(self, errors: List[str]):
        self.errors = list(errors)
        super().__init__("\n".join(self.errors))


def _fail(code: str, message: str):
    raise ValueError(f"{code}: {message}")


def _is_number(value: Any) -> bool:
    return isinstance(value, (int, float)) and not isinstance(value, bool)


def _finite(value: Any, what: str) -> float:
    try:
        number = float(value)
    except OverflowError:
        number = math.inf
    if not math.isfinite(number):
        _fail("non_finite", f"{what} is not finite")
    return number


# --- Field validators -------------------------------------------------------

def _point(value: Any) -> Tuple[float, float]:
    if not isinstance(value, (list, tuple)) or len(value) != 2 or not all(_is_number(v) for v in value):
        _fail("ring_type", "points must be [column, row] pairs of numbers")
    return _finite(value[0], "point"), _finite(value[1], "point")


def _ring(value: Any) -> List[Tuple[float, float]]:
    if not isinstance(value, (list, tuple)):
        _fail("ring_type", "a ring must be an array of [column, row] points")
    if len(value) > MAX_RING_VERTICES:
        _fail("too_many_vertices", f"a ring has {len(value)} vertices; the limit is {MAX_RING_VERTICES}")
    ring = [_point(point) for point in value]
    problem = geometry.ring_problem(ring)
    if problem:
        _fail(problem[0], f"ring {problem[1]}")
    return ring


def _oriented(ring: List[Tuple[float, float]], positive: bool) -> List[Tuple[float, float]]:
    if (geometry.signed_area(ring) > 0.0) != positive:
        warnings.warn(RoofGraphRepairWarning(
            f"winding: ring reversed to the contract winding ({'positive' if positive else 'negative'} "
            "image-space area)"), stacklevel=2)
        ring = ring[::-1]
    return ring


def _outer_ring(value: Any) -> List[Tuple[float, float]]:
    return _oriented(_ring(value), True)


def _hole_ring(value: Any) -> List[Tuple[float, float]]:
    return _oriented(_ring(value), False)


def _corner_xy(value: Any) -> Tuple[float, float]:
    if not isinstance(value, (list, tuple)) or len(value) != 2 or not all(_is_number(v) for v in value):
        _fail("field_type", "corner 'xy' must be [column, row]")
    return _finite(value[0], "corner 'xy'"), _finite(value[1], "corner 'xy'")


def _score(value: Any) -> float:
    if not _is_number(value):
        _fail("field_type", "scores must be numbers")
    score = _finite(value, "score")
    if not 0.0 <= score <= 1.0:
        _fail("score_range", f"score {score!r} is outside [0, 1]")
    return score


def _height_hint(value: Any) -> float:
    if not _is_number(value):
        _fail("height_hint", "'height_class_m' must be a number or null")
    hint = _finite(value, "'height_class_m'")
    if hint < 0.0:
        _fail("height_hint", "'height_class_m' must not be negative")
    return hint


def _id(value: Any) -> str:
    if not isinstance(value, str) or not value:
        _fail("missing_id", "'id' must be a non-empty string")
    return value


def _text(value: Any) -> str:
    if not isinstance(value, str):
        _fail("field_type", "expected a string")
    return value


def _non_empty_text(value: Any) -> str:
    if not isinstance(value, str) or not value:
        _fail("field_type", "expected a non-empty string")
    return value


def _raster_size(value: Any) -> int:
    if not _is_number(value) or not float(value).is_integer() or value <= 0:
        _fail("raster_size", "raster dimensions must be positive integers")
    return int(value)


def _geo_transform(value: Any) -> Tuple[float, ...]:
    if (not isinstance(value, (list, tuple)) or len(value) != 6 or not all(_is_number(v) for v in value)
            or not all(math.isfinite(float(v)) for v in value)):
        _fail("metadata", "'geo_transform' must be 6 finite numbers")
    gt = tuple(float(v) for v in value)
    if gt[1] * gt[5] - gt[2] * gt[4] == 0.0:
        _fail("metadata", "'geo_transform' has a zero determinant")
    return gt


def _gsd(value: Any) -> float:
    if not _is_number(value) or not math.isfinite(float(value)) or float(value) <= 0.0:
        _fail("metadata", "'gsd' must be a finite number greater than 0")
    return float(value)


Point = Annotated[Tuple[float, float], BeforeValidator(_point)]
OuterRing = Annotated[List[Tuple[float, float]], BeforeValidator(_outer_ring)]
HoleRing = Annotated[List[Tuple[float, float]], BeforeValidator(_hole_ring)]
CornerXY = Annotated[Tuple[float, float], BeforeValidator(_corner_xy)]
UnitScore = Annotated[float, BeforeValidator(_score)]
HeightHint = Annotated[float, BeforeValidator(_height_hint)]
Identifier = Annotated[str, BeforeValidator(_id)]
Text = Annotated[str, BeforeValidator(_text)]
NonEmptyText = Annotated[str, BeforeValidator(_non_empty_text)]
RasterSize = Annotated[int, BeforeValidator(_raster_size)]
GeoTransform = Annotated[Tuple[float, float, float, float, float, float], BeforeValidator(_geo_transform)]
GroundSampleDistance = Annotated[float, BeforeValidator(_gsd)]


def _require_object(value: Any, code: str, what: str) -> Any:
    if not isinstance(value, dict) and not isinstance(value, BaseModel):
        _fail(code, f"{what} must be an object")
    return value


class _Contract(BaseModel):
    # Unknown fields are tolerated and dropped, as in the C++ importer.
    model_config = ConfigDict(extra="ignore", validate_by_name=True, validate_by_alias=True,
                              serialize_by_alias=True)


# --- Models -----------------------------------------------------------------

class RoofGraphMetadata(_Contract):
    scene_id: Optional[Text] = None
    crs: Optional[Text] = None
    geo_transform: Optional[GeoTransform] = None
    gsd: Optional[GroundSampleDistance] = None

    @model_validator(mode="before")
    @classmethod
    def _object(cls, value: Any) -> Any:
        return _require_object(value, "metadata", "'metadata'")


class RoofGraphScores(_Contract):
    """Scores in [0, 1]. sam2/kibs/combined are None when that expert did not run."""
    semantic: UnitScore = 0.0
    ndsm: UnitScore = 0.0
    sam2: Optional[UnitScore] = None
    kibs: Optional[UnitScore] = None
    combined: Optional[UnitScore] = None

    @model_validator(mode="before")
    @classmethod
    def _object(cls, value: Any) -> Any:
        return _require_object(value, "field_type", "'scores'")


class CornerHint(_Contract):
    xy: CornerXY
    # Advisory KIBS height class. Never a building or roof height: the
    # corrected nDSM in the backend is the only height authority.
    height_class_hint_m: Optional[HeightHint] = Field(None, alias="height_class_m")
    score: UnitScore = 0.0
    corner_type: Text = "unknown"

    @model_validator(mode="before")
    @classmethod
    def _object(cls, value: Any) -> Any:
        return _require_object(value, "field_type", "a corner")


class RoofSection(_Contract):
    id: Identifier
    polygon: OuterRing
    holes: List[HoleRing] = Field(default_factory=list)
    corners: List[CornerHint] = Field(default_factory=list)
    type_hint: Text = "unknown"
    adjacent_sections: List[NonEmptyText] = Field(default_factory=list)
    score: UnitScore = 0.0

    @model_validator(mode="before")
    @classmethod
    def _object(cls, value: Any) -> Any:
        return _require_object(value, "field_type", "a roof section")

    @model_validator(mode="after")
    def _holes_inside(self) -> "RoofSection":
        problem = geometry.hole_problem(self.polygon, self.holes)
        if problem:
            _fail(problem[0], f"section '{self.id}' {problem[1]}")
        return self


class ProvenanceEntry(_Contract):
    stage: NonEmptyText
    source: NonEmptyText
    timestamp: Optional[Text] = None
    details: Any = None

    @model_validator(mode="before")
    @classmethod
    def _object(cls, value: Any) -> Any:
        if not isinstance(value, (dict, BaseModel)):
            _fail("provenance", "entries must be objects with non-empty 'stage' and 'source'")
        if isinstance(value, dict) and not all(isinstance(value.get(k), str) and value.get(k)
                                               for k in ("stage", "source")):
            _fail("provenance", "entries must have non-empty string 'stage' and 'source'")
        return value


class BuildingProposal(_Contract):
    id: Identifier
    footprint_proposal: OuterRing
    roofprint_proposal: Optional[OuterRing] = None  # None: no roofprint was proposed
    holes: List[HoleRing] = Field(default_factory=list)  # Footprint courtyards
    scores: RoofGraphScores = Field(default_factory=RoofGraphScores)
    roof_sections: List[RoofSection] = Field(default_factory=list)
    provenance: List[ProvenanceEntry] = Field(default_factory=list)

    @model_validator(mode="before")
    @classmethod
    def _object(cls, value: Any) -> Any:
        return _require_object(value, "field_type", "a building")

    @field_validator("roofprint_proposal", mode="before")
    @classmethod
    def _empty_roofprint(cls, value: Any) -> Any:
        return None if isinstance(value, (list, tuple)) and len(value) == 0 else value

    @model_validator(mode="after")
    def _topology(self) -> "BuildingProposal":
        problem = geometry.hole_problem(self.footprint_proposal, self.holes)
        if problem:
            _fail(problem[0], f"building '{self.id}' footprint {problem[1]}")
        section_ids = {section.id for section in self.roof_sections}
        for section in self.roof_sections:
            seen = set()
            for other in section.adjacent_sections:
                if other == section.id:
                    _fail("adjacency", f"section '{section.id}' lists itself as adjacent")
                if other not in section_ids:
                    _fail("adjacency", f"section '{section.id}' references '{other}', "
                                       f"which is not a section of building '{self.id}'")
                if other in seen:
                    _fail("adjacency", f"section '{section.id}' lists '{other}' more than once")
                seen.add(other)
        return self


class RoofGraphDocument(_Contract):
    schema_id: Literal["depthwizard.roofgraph.v1"] = Field(alias="schema")
    raster_width: RasterSize
    raster_height: RasterSize
    coordinate_convention: Literal["pixel_edge_column_row"]
    metadata: Optional[RoofGraphMetadata] = None
    buildings: List[BuildingProposal]

    @classmethod
    def create(cls, raster_width: int, raster_height: int, buildings: List[BuildingProposal],
               metadata: Optional[RoofGraphMetadata] = None) -> "RoofGraphDocument":
        """Builds a document with the fixed schema id and coordinate convention."""
        return cls(schema_id=SCHEMA_ID, coordinate_convention=COORDINATE_CONVENTION,
                   raster_width=raster_width, raster_height=raster_height,
                   buildings=buildings, metadata=metadata)

    @model_validator(mode="before")
    @classmethod
    def _object(cls, value: Any) -> Any:
        return _require_object(value, "document_type", "the document")

    @model_validator(mode="after")
    def _document_invariants(self) -> "RoofGraphDocument":
        width, height = float(self.raster_width), float(self.raster_height)

        def inside(points, what):
            for column, row in points:
                if not (0.0 <= column <= width and 0.0 <= row <= height):
                    _fail("out_of_bounds", f"{what} point ({column}, {row}) is outside "
                                           f"[0, {width}] x [0, {height}]")

        building_ids, section_ids = set(), set()
        for building in self.buildings:
            if building.id in building_ids:
                _fail("duplicate_id", f"building id '{building.id}' is used more than once")
            building_ids.add(building.id)
            inside(building.footprint_proposal, f"building '{building.id}' footprint_proposal")
            inside(building.roofprint_proposal or [], f"building '{building.id}' roofprint_proposal")
            for hole in building.holes:
                inside(hole, f"building '{building.id}' hole")
            for section in building.roof_sections:
                if section.id in section_ids:
                    _fail("duplicate_id", f"section id '{section.id}' is used more than once in the document")
                section_ids.add(section.id)
                inside(section.polygon, f"section '{section.id}' polygon")
                for hole in section.holes:
                    inside(hole, f"section '{section.id}' hole")
                inside([corner.xy for corner in section.corners], f"section '{section.id}' corner")
        return self

    def to_dict(self) -> Dict[str, Any]:
        """Canonical form, identical to HybridRoofGraphImporter::toJson."""
        data = self.model_dump(mode="json", by_alias=True, exclude_none=True)
        if not data.get("metadata"):
            data.pop("metadata", None)
        return data

    def to_json(self, indent: Optional[int] = None) -> str:
        return json.dumps(self.to_dict(), indent=indent, allow_nan=False)


# --- Parsing ----------------------------------------------------------------

_CODED = re.compile(r"(?:Value error, )?([a-z_]+): (.*)", re.S)
_TOP_LEVEL_CODES = {"schema": "schema", "raster_width": "raster_size", "raster_height": "raster_size",
                    "coordinate_convention": "coordinate_convention", "metadata": "metadata"}


def _code_for(error: Dict[str, Any]) -> str:
    location = [part for part in error["loc"] if isinstance(part, (str, int))]
    if location and location[0] in _TOP_LEVEL_CODES:
        return _TOP_LEVEL_CODES[location[0]]
    if location == ["buildings"]:
        return "buildings"
    names = [part for part in location if isinstance(part, str)]
    if names and names[-1] == "id":
        return "missing_id"
    if names and names[-1] in ("footprint_proposal", "polygon") and error["type"] == "missing":
        return "ring_type"
    return "field_type"


def contract_errors(error: ValidationError) -> List[str]:
    """ValidationError entries as 'code: location: message' strings."""
    messages = []
    for entry in error.errors(include_url=False):
        location = ".".join(str(part) for part in entry["loc"]) or "document"
        match = _CODED.fullmatch(entry["msg"])
        if match and match.group(1) in ERROR_CODES:
            code, text = match.group(1), match.group(2)
        else:
            code, text = _code_for(entry), entry["msg"]
        message = f"{code}: {location}: {text}"
        if message not in messages:
            messages.append(message)
    return messages


def parse_roofgraph(data: Any) -> RoofGraphDocument:
    """Validates a decoded document; raises RoofGraphContractError."""
    try:
        return RoofGraphDocument.model_validate(data)
    except ValidationError as error:
        raise RoofGraphContractError(contract_errors(error)) from None


def _reject_duplicate_keys(pairs):
    keys = [key for key, _ in pairs]
    if len(keys) != len(set(keys)):
        raise ValueError(f"duplicate key in object: {sorted(k for k in keys if keys.count(k) > 1)[0]!r}")
    return dict(pairs)


def _reject_constant(token: str):
    raise ValueError(f"{token} is not valid JSON")


def load_json(text: Any) -> Any:
    """Decodes JSON as strictly as the C++ reader: no NaN/Infinity tokens, no duplicate keys."""
    if isinstance(text, (bytes, bytearray)):
        text = text.decode("utf-8")
    if len(text.encode("utf-8")) > MAX_DOCUMENT_BYTES:
        raise RoofGraphContractError([f"document_too_large: the document exceeds {MAX_DOCUMENT_BYTES} bytes"])
    try:
        return json.loads(text, object_pairs_hook=_reject_duplicate_keys, parse_constant=_reject_constant)
    except ValueError as error:
        raise RoofGraphContractError([f"json_syntax: invalid JSON: {error}"]) from None


def parse_roofgraph_json(text: Any) -> RoofGraphDocument:
    return parse_roofgraph(load_json(text))
