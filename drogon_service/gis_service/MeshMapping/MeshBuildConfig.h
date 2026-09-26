#pragma once
#include "TerrainMeshConfig.h"
#include "BuildingMeshConfig.h"
#include "../CompressionLib/DracoCompressor.h"

enum class ScenePresentation { METRIC, FLAT_URBAN };

struct MeshBuildConfig 
{
     ScenePresentation presentation{ScenePresentation::METRIC};
     TerrainMeshConfig terrain;
     BuildingMeshConfig building;
     DracoCompressionConfig draco;
};
