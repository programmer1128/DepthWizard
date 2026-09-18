#pragma once
#include "BuildingReconstructionConfig.h"
#include "../structures/GeographicStructs.h"
#include "../structures/SurfaceStructs.h"

class BuildingReconstructionService 
{
     public:
     static BuildingCollection reconstruct(
         const SemanticScene& semantics,
         const GeoreferencedSurfaceBundle& surface,
         const SpatialMetadata& metadata,
         const BuildingReconstructionConfig& config = BuildingReconstructionConfig());
};