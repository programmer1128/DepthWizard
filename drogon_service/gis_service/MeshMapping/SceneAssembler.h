#pragma once
#include "../structures/MeshStructs.h"
#include "../structures/IngestionStructs.h"

class SceneAssembler 
{
     public:
     static SceneMesh assemble(
         const TerrainMesh& terrain,
         const BuildingMesh& buildings,
         const SceneInput& sceneInput,
         const LocalSceneFrame& frame);
};