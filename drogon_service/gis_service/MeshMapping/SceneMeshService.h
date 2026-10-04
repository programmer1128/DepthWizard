#pragma once
#include "MeshBuildConfig.h"
#include "../structures/IngestionStructs.h"
#include "../structures/SurfaceStructs.h"
#include "../structures/GeographicStructs.h"
#include "../structures/ExportStructs.h"
#include "../structures/MeshStructs.h"

struct VegetationCanopyInput;

class SceneMeshService 
{
     public:
     // `vegetation` (optional, DEPTHWIZARD_VEGETATION): when it yields a
     // canopy, a separately named VEGETATION_CANOPY node is appended after the
     // base scene. Without it the GLB is produced exactly as before.
     static GlbBuildResult generateGlb(
     const SceneInput& scene,
     const GeoreferencedSurfaceBundle& surface,
     const BuildingCollection& buildings,
     const SpatialMetadata& metadata,
     const MeshBuildConfig& config = MeshBuildConfig(),
     const VegetationCanopyInput* vegetation = nullptr);
};