"""Validation helpers for depthwizard.roofgraph.v1 documents."""

import json
import warnings
from pathlib import Path
from typing import Any, Dict, List, Optional, Tuple

import jsonschema

from .contracts import RoofGraphContractError, RoofGraphRepairWarning, parse_roofgraph

CONTRACTS_DIR = Path(__file__).resolve().parents[2] / "drogon_service" / "gis_service" / "contracts"
DEFAULT_SCHEMA_PATH = CONTRACTS_DIR / "roofgraph-v1.schema.json"


def load_schema(schema_path: Optional[Path] = None) -> Dict[str, Any]:
    with open(schema_path or DEFAULT_SCHEMA_PATH, encoding="utf-8") as handle:
        return json.load(handle)


def validate_against_json_schema(data: Any, schema_path: Optional[Path] = None) -> List[str]:
    """Structural JSON Schema check. Geometry rules are not expressible there."""
    validator = jsonschema.Draft202012Validator(load_schema(schema_path))
    return [f"json_schema: {'.'.join(str(p) for p in error.absolute_path) or 'document'}: {error.message}"
            for error in sorted(validator.iter_errors(data), key=lambda e: list(map(str, e.absolute_path)))]


def validate_roofgraph_dict(data: Any, schema_path: Optional[Path] = None) -> Tuple[bool, List[str], List[str]]:
    """JSON Schema plus the full contract (geometry included).

    Returns (is_valid, errors, warnings); warnings report canonicalizations
    such as reversed ring winding.
    """
    errors = validate_against_json_schema(data, schema_path)
    with warnings.catch_warnings(record=True) as caught:
        warnings.simplefilter("always", RoofGraphRepairWarning)
        try:
            parse_roofgraph(data)
        except RoofGraphContractError as error:
            errors.extend(error.errors)
    notes = [str(w.message) for w in caught if issubclass(w.category, RoofGraphRepairWarning)]
    return not errors, errors, notes
