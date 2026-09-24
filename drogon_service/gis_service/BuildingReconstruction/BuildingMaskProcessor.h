#pragma once
#include "BuildingReconstructionTypes.h"
#include "../structures/GeographicStructs.h"
#include "BuildingReconstructionConfig.h"

class BuildingMaskProcessor 
{
     public:
     static BuildingMaskResult createCleanMask(
         const SemanticScene& semantics,const RasterGrid<uint8_t>& validMask,
         const SpatialMetadata& metadata,
         const BuildingReconstructionConfig& config);

     static BuildingMaskResult createCleanMask(
         const SemanticScene& semantics,
         const RasterGrid<float>& metricNdsm,
         const RasterGrid<uint8_t>& validMask,
         const SpatialMetadata& metadata,
         const BuildingReconstructionConfig& config);
};
