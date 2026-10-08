#pragma once
#include "../structures/MeshStructs.h"
#include "../structures/SurfaceStructs.h"

class LocalFrameTransformer 
{
     public:
     static LocalSceneFrame create(
         const SpatialMetadata& metadata,
         const GeoreferencedSurfaceBundle& surface);

     // Helpers to apply the transformation safely
     static LocalPoint toLocal(const ProjectedPoint& pt, const LocalSceneFrame& frame);
     static float toLocalElevation(float elevation, const LocalSceneFrame& frame);
};