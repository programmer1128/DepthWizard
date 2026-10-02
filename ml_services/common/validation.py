"""Validation utilities for depthwizard.roofgraph.v1 contract."""

import json
from pathlib import Path
from typing import Any, Dict, List, Optional, Tuple

import jsonschema

from .contracts import RoofGraphDocument
from .geometry import (
    has_self_intersection,
    is_ccw,
    is_cw,
    signed_area,
    strip_closing_vertex,
)

DEFAULT_SCHEMA_PATH = Path(__file__).resolve().parents[2] / "drogon_service" / "gis_service" / "contracts" / "roofgraph-v1.schema.json"


def load_schema(schema_path: Optional[Path] = None) -> Dict[str, Any]:
    """Load JSON Schema from disk."""
    path = schema_path or DEFAULT_SCHEMA_PATH
    if not path.is_file():
        raise FileNotFoundError(f"JSON schema not found at {path}")
    with open(path, "r", encoding="utf-8") as f:
        return json.load(f)


def validate_against_json_schema(data: Dict[str, Any], schema_path: Optional[Path] = None) -> List[str]:
    """Validate raw dictionary against depthwizard.roofgraph.v1 JSON Schema.
    
    Returns a list of validation error messages (empty if valid).
    """
    schema = load_schema(schema_path)
    validator = jsonschema.Draft202012Validator(schema)
    errors = []
    for err in sorted(validator.iter_errors(data), key=lambda e: e.path):
        loc = ".".join(str(p) for p in err.path) if err.path else "root"
        errors.append(f"[{loc}] {err.message}")
    return errors


def validate_roofgraph_dict(
    data: Dict[str, Any],
    schema_path: Optional[Path] = None,
    check_geometry: bool = True
) -> Tuple[bool, List[str], List[str]]:
    """Complete validation of a roofgraph dictionary against schema, Pydantic, and geometry invariants.
    
    Returns:
        (is_valid, list_of_errors, list_of_warnings)
    """
    errors: List[str] = []
    warnings: List[str] = []

    # 1. JSON Schema validation
    try:
        schema_errors = validate_against_json_schema(data, schema_path)
        errors.extend(schema_errors)
    except Exception as e:
        errors.append(f"Schema loading or validation failure: {e}")

    # 2. Pydantic validation
    doc: Optional[RoofGraphDocument] = None
    try:
        doc = RoofGraphDocument.model_validate(data)
    except Exception as e:
        errors.append(f"Pydantic contract validation error: {e}")

    if doc is not None and check_geometry:
        # 3. Geometric invariants and winding checks
        for b in doc.buildings:
            # Check footprint winding (outer ring should be CCW in image coordinate space)
            if not is_ccw(b.footprint_proposal):
                warnings.append(
                    f"Building '{b.id}' footprint outer ring has CW winding; will be normalized to CCW."
                )

            # Check footprint self-intersection
            if has_self_intersection(b.footprint_proposal):
                errors.append(
                    f"Building '{b.id}' footprint outer ring self-intersects."
                )

            # Check roofprint winding and self-intersection
            if b.roofprint_proposal:
                if not is_ccw(b.roofprint_proposal):
                    warnings.append(
                        f"Building '{b.id}' roofprint outer ring has CW winding; will be normalized to CCW."
                    )
                if has_self_intersection(b.roofprint_proposal):
                    errors.append(
                        f"Building '{b.id}' roofprint outer ring self-intersects."
                    )

            # Check holes winding (holes should be CW in coordinate space)
            for i, hole in enumerate(b.holes):
                if not is_cw(hole):
                    warnings.append(
                        f"Building '{b.id}' hole[{i}] has CCW winding; should be CW."
                    )
                if has_self_intersection(hole):
                    errors.append(
                        f"Building '{b.id}' hole[{i}] self-intersects."
                    )

            # Check roof sections
            for s in b.roof_sections:
                if not is_ccw(s.polygon):
                    warnings.append(
                        f"Building '{b.id}' section '{s.id}' has CW winding; should be CCW."
                    )
                if has_self_intersection(s.polygon):
                    errors.append(
                        f"Building '{b.id}' section '{s.id}' polygon self-intersects."
                    )

    is_valid = len(errors) == 0
    return is_valid, errors, warnings
