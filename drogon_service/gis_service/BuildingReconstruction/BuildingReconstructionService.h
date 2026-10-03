#pragma once
#include "BuildingReconstructionConfig.h"
#include "BuildingReconstructionTypes.h"
#include "../structures/GeographicStructs.h"
#include "../structures/SurfaceStructs.h"

// Buildings plus the authoritative instance-label raster they were extracted
// from (pixel value == BuildingInstance::buildingId, 0 = background).
struct BuildingReconstructionResult
{
     BuildingCollection buildings;
     RasterGrid<int32_t> instanceLabels;
};

class BuildingReconstructionService 
{
     public:
     static BuildingReconstructionResult reconstructDetailed(
         const SemanticScene& semantics,
         const GeoreferencedSurfaceBundle& surface,
         const SpatialMetadata& metadata,
         const BuildingReconstructionConfig& config = BuildingReconstructionConfig(),
         BuildingReconstructionDiagnostics* diagnostics = nullptr,
         const RasterGrid<float>* reconstructionNdsm = nullptr,
         const std::vector<uint8_t>* opticalImageBytes = nullptr);

     // Unchanged compatibility wrapper around reconstructDetailed().
     static BuildingCollection reconstruct(
         const SemanticScene& semantics,
         const GeoreferencedSurfaceBundle& surface,
         const SpatialMetadata& metadata,
         const BuildingReconstructionConfig& config = BuildingReconstructionConfig(),
         BuildingReconstructionDiagnostics* diagnostics = nullptr,
         const RasterGrid<float>* reconstructionNdsm = nullptr,
         const std::vector<uint8_t>* opticalImageBytes = nullptr);
};
