#pragma once
#include "TerrainMeshConfig.h"
#include "BuildingMeshConfig.h"
#include "PresentationStyle.h"
#include "../CompressionLib/DracoCompressor.h"

enum class ScenePresentation { METRIC, FLAT_URBAN };

struct MeshBuildConfig 
{
     ScenePresentation presentation{ScenePresentation::METRIC};
     depthwizard::PresentationStyle presentationStyle{depthwizard::PresentationStyle::SCIENTIFIC};
     TerrainMeshConfig terrain;
     BuildingMeshConfig building;
     DracoCompressionConfig draco;
};
