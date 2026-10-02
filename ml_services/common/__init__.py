"""DepthWizard ML services common contracts and geometry."""

from .contracts import (
    COORDINATE_CONVENTION,
    SCHEMA_ID,
    BuildingProposal,
    CornerHint,
    ProvenanceEntry,
    RoofGraphContractError,
    RoofGraphDocument,
    RoofGraphMetadata,
    RoofGraphRepairWarning,
    RoofGraphScores,
    RoofSection,
    parse_roofgraph,
    parse_roofgraph_json,
)

__all__ = [
    "COORDINATE_CONVENTION",
    "SCHEMA_ID",
    "BuildingProposal",
    "CornerHint",
    "ProvenanceEntry",
    "RoofGraphContractError",
    "RoofGraphDocument",
    "RoofGraphMetadata",
    "RoofGraphRepairWarning",
    "RoofGraphScores",
    "RoofSection",
    "parse_roofgraph",
    "parse_roofgraph_json",
]
