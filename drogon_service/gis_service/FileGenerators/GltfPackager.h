#pragma once
#include "../structures/MeshStructs.h"
#include "../structures/ExportStructs.h"
#include "../CompressionLib/DracoCompressor.h"
#include <vector>

class GltfPackager 
{
     public:
     static GlbBuildResult buildSceneToMemory(
         const SceneMesh& scene,
         const std::vector<CompressedPrimitive>& compressedPrimitives,
         size_t totalBuildingCount);
};