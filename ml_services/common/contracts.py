"""Pydantic models for the canonical depthwizard.roofgraph.v1 exchange contract."""

from enum import Enum
import math
from typing import Any, Dict, List, Literal, Optional, Tuple, Union

from pydantic import BaseModel, ConfigDict, Field, field_validator, model_validator

from .geometry import has_self_intersection, strip_closing_vertex, is_ccw, is_cw


class CoordinateConvention(str, Enum):
    """Declared coordinate frame for pixel coordinates."""
    PIXEL_EDGE_COLUMN_ROW = "pixel_edge_column_row"
    PIXEL_CENTRE_COLUMN_ROW = "pixel_centre_column_row"


Point2D = Tuple[float, float]
Ring = List[Point2D]


def _validate_finite_point(pt: Tuple[float, float], field_name: str = "point") -> Tuple[float, float]:
    if len(pt) != 2:
        raise ValueError(f"{field_name} must have exactly 2 elements [column, row]")
    c, r = float(pt[0]), float(pt[1])
    if not math.isfinite(c) or not math.isfinite(r):
        raise ValueError(f"{field_name} coordinates must be finite numbers, got ({c}, {r})")
    return (c, r)


def _validate_ring(ring: List[Tuple[float, float]], ring_name: str = "ring") -> List[Tuple[float, float]]:
    if not ring:
        raise ValueError(f"{ring_name} cannot be empty")
    cleaned_points = [_validate_finite_point(pt, ring_name) for pt in ring]
    
    # Check for disallowed implicit closing vertex
    if len(cleaned_points) >= 2:
        c0, r0 = cleaned_points[0]
        c_last, r_last = cleaned_points[-1]
        if math.isclose(c0, c_last, abs_tol=1e-7) and math.isclose(r0, r_last, abs_tol=1e-7):
            raise ValueError(
                f"{ring_name} has duplicate closing vertex ({c_last}, {r_last}); "
                f"depthwizard.roofgraph.v1 serialized rings must be open (no closing vertex)."
            )

    if len(cleaned_points) < 3:
        raise ValueError(f"{ring_name} must contain at least 3 unique vertices, got {len(cleaned_points)}")

    return cleaned_points


class RoofGraphScores(BaseModel):
    """Confidence and support scores in [0, 1]."""
    model_config = ConfigDict(extra="allow")

    semantic: float = Field(0.0, ge=0.0, le=1.0, description="Semantic building class confidence")
    ndsm: float = Field(0.0, ge=0.0, le=1.0, description="nDSM height evidence support")
    sam2: Optional[float] = Field(0.0, ge=0.0, le=1.0, description="SAM 2.1 boundary model score/stability")
    kibs: Optional[float] = Field(0.0, ge=0.0, le=1.0, description="KIBS roof decomposition confidence")
    combined: Optional[float] = Field(None, ge=0.0, le=1.0, description="Fused router confidence")


class CornerHint(BaseModel):
    """Advisory corner location and height class prior."""
    model_config = ConfigDict(extra="allow")

    xy: Tuple[float, float]
    height_class_m: Optional[float] = Field(
        None, ge=0.0, description="Advisory height class in metres (non-authoritative prior)"
    )
    score: float = Field(0.0, ge=0.0, le=1.0, description="Corner confidence score")
    corner_type: Optional[str] = Field("unknown", description="Corner type hint")

    @field_validator("xy")
    @classmethod
    def validate_xy(cls, v: Tuple[float, float]) -> Tuple[float, float]:
        return _validate_finite_point(v, "CornerHint.xy")


class RoofSection(BaseModel):
    """Decomposed roof facet/section polygon and topology hints."""
    model_config = ConfigDict(extra="allow")

    id: str = Field(..., min_length=1, description="Roof section unique ID")
    polygon: Ring = Field(..., min_length=3, description="Outer boundary of roof section (open ring)")
    holes: List[Ring] = Field(default_factory=list, description="Optional interior holes")
    corners: List[CornerHint] = Field(default_factory=list, description="Advisory corner keypoints")
    type_hint: str = Field("unknown", description="Roof section type (flat, gable, hip, etc.)")
    adjacent_sections: List[str] = Field(default_factory=list, description="IDs of adjacent sections")
    score: float = Field(0.0, ge=0.0, le=1.0, description="Section confidence score")

    @field_validator("polygon")
    @classmethod
    def validate_polygon(cls, v: Ring) -> Ring:
        return _validate_ring(v, "RoofSection.polygon")

    @field_validator("holes")
    @classmethod
    def validate_holes(cls, v: List[Ring]) -> List[Ring]:
        return [_validate_ring(hole, f"RoofSection.holes[{i}]") for i, hole in enumerate(v)]


class ProvenanceEntry(BaseModel):
    """Traceable stage provenance for a building proposal."""
    model_config = ConfigDict(extra="allow")

    stage: str = Field(..., description="Pipeline stage (e.g. sam2_refinement, kibs_decomposition)")
    source: str = Field(..., description="Module or model checkpoint producing geometry")
    timestamp: Optional[str] = Field(None, description="ISO 8601 UTC timestamp")
    details: Optional[Any] = Field(None, description="Diagnostic parameters, prompts, or timing")


class BuildingProposal(BaseModel):
    """Building candidate containing ground footprint and optional roofprint proposals."""
    model_config = ConfigDict(extra="allow")

    id: str = Field(..., min_length=1, description="Unique building ID")
    footprint_proposal: Ring = Field(..., min_length=3, description="Ground footprint outer ring")
    roofprint_proposal: Optional[Ring] = Field(
        None, description="Roof boundary outer ring; matches footprint if omitted or empty"
    )
    holes: List[Ring] = Field(default_factory=list, description="Inner courtyards/cutouts")
    scores: RoofGraphScores = Field(default_factory=RoofGraphScores)
    roof_sections: List[RoofSection] = Field(default_factory=list)
    provenance: List[Union[ProvenanceEntry, str]] = Field(default_factory=list)

    @field_validator("footprint_proposal")
    @classmethod
    def validate_footprint(cls, v: Ring) -> Ring:
        return _validate_ring(v, "BuildingProposal.footprint_proposal")

    @field_validator("roofprint_proposal")
    @classmethod
    def validate_roofprint(cls, v: Optional[Ring]) -> Optional[Ring]:
        if v is None or len(v) == 0:
            return v
        return _validate_ring(v, "BuildingProposal.roofprint_proposal")

    @field_validator("holes")
    @classmethod
    def validate_holes(cls, v: List[Ring]) -> List[Ring]:
        return [_validate_ring(hole, f"BuildingProposal.holes[{i}]") for i, hole in enumerate(v)]


class RoofGraphDocument(BaseModel):
    """Top-level document for depthwizard.roofgraph.v1 contract."""
    model_config = ConfigDict(extra="allow")

    schema_version: Literal["depthwizard.roofgraph.v1"] = Field(
        "depthwizard.roofgraph.v1", alias="schema", description="Schema identifier"
    )
    raster_width: int = Field(..., gt=0, description="Raster width in pixels")
    raster_height: int = Field(..., gt=0, description="Raster height in pixels")
    coordinate_convention: CoordinateConvention = Field(
        CoordinateConvention.PIXEL_EDGE_COLUMN_ROW,
        description="Declared coordinate frame: pixel_edge_column_row or pixel_centre_column_row",
    )
    metadata: Optional[Dict[str, Any]] = Field(None, description="Optional georeferencing metadata")
    buildings: List[BuildingProposal] = Field(default_factory=list)

    @model_validator(mode="after")
    def validate_document_invariants(self) -> "RoofGraphDocument":
        width = float(self.raster_width)
        height = float(self.raster_height)

        # 1. Unique building IDs
        seen_building_ids = set()
        for b in self.buildings:
            if b.id in seen_building_ids:
                raise ValueError(f"Duplicate building ID found in document: '{b.id}'")
            seen_building_ids.add(b.id)

            # Check bounds for footprint
            for c, r in b.footprint_proposal:
                if c < 0.0 or c > width or r < 0.0 or r > height:
                    raise ValueError(
                        f"Building '{b.id}' footprint vertex ({c}, {r}) is outside "
                        f"raster bounds [0, {width}] x [0, {height}]"
                    )

            # Check bounds for roofprint if present
            if b.roofprint_proposal:
                for c, r in b.roofprint_proposal:
                    if c < 0.0 or c > width or r < 0.0 or r > height:
                        raise ValueError(
                            f"Building '{b.id}' roofprint vertex ({c}, {r}) is outside "
                            f"raster bounds [0, {width}] x [0, {height}]"
                        )

            # Check holes bounds
            for hole in b.holes:
                for c, r in hole:
                    if c < 0.0 or c > width or r < 0.0 or r > height:
                        raise ValueError(
                            f"Building '{b.id}' hole vertex ({c}, {r}) is outside "
                            f"raster bounds [0, {width}] x [0, {height}]"
                        )

            # Check section IDs uniqueness within building
            seen_section_ids = set()
            for s in b.roof_sections:
                if s.id in seen_section_ids:
                    raise ValueError(
                        f"Duplicate roof section ID '{s.id}' found in building '{b.id}'"
                    )
                seen_section_ids.add(s.id)

                for c, r in s.polygon:
                    if c < 0.0 or c > width or r < 0.0 or r > height:
                        raise ValueError(
                            f"Building '{b.id}' section '{s.id}' vertex ({c}, {r}) is outside "
                            f"raster bounds [0, {width}] x [0, {height}]"
                        )

                for corner in s.corners:
                    c, r = corner.xy
                    if c < 0.0 or c > width or r < 0.0 or r > height:
                        raise ValueError(
                            f"Building '{b.id}' section '{s.id}' corner ({c}, {r}) is outside "
                            f"raster bounds [0, {width}] x [0, {height}]"
                        )

            # Validate adjacency references
            for s in b.roof_sections:
                for adj_id in s.adjacent_sections:
                    if adj_id not in seen_section_ids:
                        raise ValueError(
                            f"Section '{s.id}' in building '{b.id}' references nonexistent "
                            f"adjacent section '{adj_id}'"
                        )

        return self
