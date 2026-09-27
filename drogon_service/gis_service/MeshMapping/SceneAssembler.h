#pragma once
#include "../structures/MeshStructs.h"
#include "../structures/IngestionStructs.h"
#include <vector>
#include <cstdint>

class SceneAssembler 
{
     public:
     static SceneMesh assemble(
         const TerrainMesh& terrain,
         const BuildingMesh& buildings,
         const SceneInput& sceneInput,
         const LocalSceneFrame& frame,
         const std::vector<uint8_t>& overrideTextureBytes = std::vector<uint8_t>());
};