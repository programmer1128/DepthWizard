#pragma once
#include "TerrainMeshConfig.h"
#include "LocalFrameTransformer.h"
#include "../structures/MeshStructs.h"
#include "../structures/SurfaceStructs.h"

class TerrainMesher 
{
     public:
     static TerrainMesh generate(
         const GeoreferencedSurfaceBundle& surface,
         const SpatialMetadata& metadata,
         const LocalSceneFrame& frame,
         const TerrainMeshConfig& config = TerrainMeshConfig());

     static TerrainMesh generate(
         const GeoreferencedSurfaceBundle& surface,
         const RasterGrid<uint8_t>& acceptedBuildingMask,
         const SpatialMetadata& metadata,
         const LocalSceneFrame& frame,
         const TerrainMeshConfig& config = TerrainMeshConfig());
};
