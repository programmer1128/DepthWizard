#pragma once
#include "BuildingReconstructionTypes.h"
#include "../structures/GeographicStructs.h"
#include "../structures/SurfaceStructs.h"
#include "BuildingReconstructionConfig.h"

class BuildingHeightEstimator 
{
     public:
     static BuildingHeightEstimate estimate(
         const FootprintPolygon<PixelPoint>& pixelFootprint,
         const GeoreferencedSurfaceBundle& surface,
         const SemanticScene& semantics,
         const SpatialMetadata& metadata,
         const BuildingReconstructionConfig& config,
         const RasterGrid<float>* reconstructionNdsm = nullptr,
         const RasterGrid<int32_t>* instanceLabels = nullptr,
         int32_t instanceId = 0);
        
     private:
     static float calculateRobustPeak(std::vector<float>& samples);
     static float calculateRobustRoofHeight(std::vector<float>& samples);
};
