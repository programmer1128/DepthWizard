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
         const BuildingReconstructionConfig& config);
        
     private:
     static float calculateRobustMedian(std::vector<float>& samples);
};