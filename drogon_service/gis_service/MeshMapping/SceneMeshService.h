#pragma once
#include "MeshBuildConfig.h"
#include "../structures/IngestionStructs.h"
#include "../structures/SurfaceStructs.h"
#include "../structures/GeographicStructs.h"
#include "../structures/ExportStructs.h"
#include "../structures/MeshStructs.h"

class SceneMeshService 
{
     public:
     static GlbBuildResult generateGlb(
     const SceneInput& scene,
     const GeoreferencedSurfaceBundle& surface,
     const BuildingCollection& buildings,
     const SpatialMetadata& metadata,
     const MeshBuildConfig& config,
     const MeshPrimitive* externalBuildingMesh = nullptr); // <-- Add this parameter
};