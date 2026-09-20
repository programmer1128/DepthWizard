#pragma once
#include "BuildingReconstructionTypes.h"
#include "../structures/GeographicStructs.h"

class BuildingInstanceExtractor
{
public:
    static ComponentExtractionResult extract(
        const BuildingMaskResult &maskResult,
        const SemanticScene &semantics,
        const SpatialMetadata &metadata,
        const BuildingReconstructionConfig &config);
};