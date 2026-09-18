#pragma once
#include "TerrainMeshConfig.h"
#include "BuildingMeshConfig.h"
#include "../CompressionLib/DracoCompressor.h"

struct MeshBuildConfig 
{
     TerrainMeshConfig terrain;
     BuildingMeshConfig building;
     DracoCompressionConfig draco;
};