#pragma once
#include "BuildingReconstructionConfig.h"
#include "BuildingReconstructionTypes.h"
#include "../structures/GeographicStructs.h"
#include "../structures/SurfaceStructs.h"

class BuildingReconstructionService 
{
     public:
     static BuildingCollection reconstruct(
         const SemanticScene& semantics,
         const GeoreferencedSurfaceBundle& surface,
         const SpatialMetadata& metadata,
         const BuildingReconstructionConfig& config = BuildingReconstructionConfig(),
         BuildingReconstructionDiagnostics* diagnostics = nullptr,
         const RasterGrid<float>* reconstructionNdsm = nullptr,
         const std::vector<uint8_t>* opticalImageBytes = nullptr);
};
