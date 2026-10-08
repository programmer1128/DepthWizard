#pragma once

#include "BuildingReconstructionConfig.h"
#include "../structures/GeographicStructs.h"

#include <vector>

class BuildingRoofModeler
{
public:
    // Fits conservative flat/gable/hip parameters from metric nDSM evidence.
    // Unsupported or noisy blocks are explicitly downgraded to FLAT.
    static void fit(
        std::vector<DecomposedBuildingBlock>& blocks,
        const RasterGrid<float>& reconstructionNdsm,
        const RasterGrid<uint8_t>& validMask,
        const SpatialMetadata& metadata,
        float fallbackHeightAboveGround,
        const BuildingReconstructionConfig& config);
};
