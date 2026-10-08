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
     // Plain concrete facade atlas (no synthetic windows); orthophoto style only.
     bool neutralFacades{false};
     TerrainMeshConfig terrain;
     BuildingMeshConfig building;
     DracoCompressionConfig draco;
};
