#include "SceneAssembler.h"
#include <algorithm>

SceneMesh SceneAssembler::assemble(
     const TerrainMesh& terrain,
     const BuildingMesh& buildings,
     const SceneInput& sceneInput,
     const LocalSceneFrame& frame)
{
     SceneMesh sceneMesh;
     sceneMesh.localFrame = frame; // Attach the mathematical anchor

     //Assign the Primitives
     sceneMesh.terrainPrimitive = terrain.terrainPrimitive;
     sceneMesh.roofPrimitive = buildings.roofPrimitive;
     sceneMesh.wallPrimitive = buildings.wallPrimitive;
     sceneMesh.edgePrimitive = buildings.edgePrimitive;

     //Compute Global Scene Bounding Box
     auto mergeBounds = [](AxisAlignedBounds& global, const AxisAlignedBounds& local) 
     {
         if (!local.isInitialized) 
         {
             return;
         }
        
         if (!global.isInitialized) 
         {
             global = local;
             return;
         }
        
         global.minX = std::min(global.minX, local.minX);
         global.minY = std::min(global.minY, local.minY);
         global.minZ = std::min(global.minZ, local.minZ);
        
         global.maxX = std::max(global.maxX, local.maxX);
         global.maxY = std::max(global.maxY, local.maxY);
         global.maxZ = std::max(global.maxZ, local.maxZ);
     };

     mergeBounds(sceneMesh.sceneBounds, sceneMesh.terrainPrimitive.localBounds);
     mergeBounds(sceneMesh.sceneBounds, sceneMesh.roofPrimitive.localBounds);
     mergeBounds(sceneMesh.sceneBounds, sceneMesh.wallPrimitive.localBounds);
     mergeBounds(sceneMesh.sceneBounds, sceneMesh.edgePrimitive.localBounds);

     //Declare Global Materials
     // This tells the glTF packager exactly which materials to instantiate
     sceneMesh.materials = {
         MaterialRole::TERRAIN_TEXTURE,
         MaterialRole::BUILDING_ROOF,
         MaterialRole::BUILDING_WALL,
         MaterialRole::BUILDING_EDGE
     };

     //Attach the Original Optical Texture
     if (!sceneInput.rgbTextureBytes.empty()) 
     {
         TextureAsset texAsset;
         texAsset.bytes = sceneInput.rgbTextureBytes;
         texAsset.mimeType = sceneInput.textureMimeType; // Passes "image/jpeg" or "image/png" directly
         sceneMesh.texture = std::move(texAsset);
     }

     return sceneMesh;
}