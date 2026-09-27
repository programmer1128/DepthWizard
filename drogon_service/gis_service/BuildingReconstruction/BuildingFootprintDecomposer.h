#pragma once

#include "BuildingReconstructionConfig.h"
#include "../structures/GeographicStructs.h"

#include <string>
#include <vector>

struct FootprintDecompositionResult
{
    bool success{false};
    bool accepted{false};
    std::string errorMessage;
    std::vector<DecomposedBuildingBlock> blocks;
    float coverageRatio{0.0f};
    float maskIoU{0.0f};
    std::vector<std::string> warnings;
};

class BuildingFootprintDecomposer
{
public:
    // Independent C++ implementation of orientation-aligned, maximal
    // rectangle decomposition. It operates on the already validated footprint
    // and falls back safely when rectangular blocks do not explain the mask.
    static FootprintDecompositionResult decompose(
        const FootprintPolygon<PixelPoint>& footprint,
        const SpatialMetadata& metadata,
        const BuildingReconstructionConfig& config);
};
