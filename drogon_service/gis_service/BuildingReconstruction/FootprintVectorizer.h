#pragma once
#include "BuildingReconstructionTypes.h"
#include "../structures/GeographicStructs.h"
#include "BuildingReconstructionConfig.h"

class FootprintVectorizer 
{
     public:
     static FootprintVectorizationResult vectorize(
         const ComponentStats& stats,
         const RasterGrid<int32_t>& labelRaster,
         const SpatialMetadata& metadata,
         const BuildingReconstructionConfig& config);
        
     private:
     // Topological Math Helpers
     static double calculateSignedArea(const std::vector<ProjectedPoint>& pts);
     static bool doIntersect(const ProjectedPoint& p1, const ProjectedPoint& q1, const ProjectedPoint& p2, const ProjectedPoint& q2);
     static bool hasSelfIntersections(const std::vector<ProjectedPoint>& ring);
     static bool isPointInPolygon(const ProjectedPoint& pt, const std::vector<ProjectedPoint>& polygon);
     static bool ringsIntersect(const std::vector<ProjectedPoint>& ringA, const std::vector<ProjectedPoint>& ringB);
};