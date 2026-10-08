#pragma once
#include "BuildingReconstructionTypes.h"
#include "BuildingReconstructionConfig.h"
#include "../structures/GeographicStructs.h"

class BuildingInstanceExtractor 
{
     public:
     static ComponentExtractionResult extract(
         const BuildingMaskResult& maskResult,
         const SemanticScene& semantics,
         const SpatialMetadata& metadata,
         const BuildingReconstructionConfig& config,
         const RasterGrid<float>* ndsm = nullptr,
         const RasterGrid<uint8_t>* opticalGray = nullptr);
};
