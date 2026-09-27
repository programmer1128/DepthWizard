#include "SceneAssembler.h"
#include <algorithm>

SceneMesh SceneAssembler::assemble(
     const TerrainMesh& terrain,
     const BuildingMesh& buildings,
     const SceneInput& sceneInput,
     const LocalSceneFrame& frame,
     const std::vector<uint8_t>& overrideTextureBytes)
{
     SceneMesh sceneMesh;
     sceneMesh.localFrame = frame;

     sceneMesh.terrainPrimitive = terrain.terrainPrimitive;
     sceneMesh.roofPrimitive = buildings.roofPrimitive;
     sceneMesh.wallPrimitive = buildings.wallPrimitive;

     auto mergeBounds = [](AxisAlignedBounds& global, const AxisAlignedBounds& local) 
     {
         if (!local.isInitialized) return;
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

     sceneMesh.materials = {
         MaterialRole::TERRAIN_TEXTURE,
         MaterialRole::BUILDING_ROOF,
         MaterialRole::BUILDING_WALL
     };

     // Prioritize the inpainted texture, fallback to original if inpainting was bypassed
     if (!overrideTextureBytes.empty()) 
     {
         TextureAsset texAsset;
         texAsset.bytes = overrideTextureBytes;
         texAsset.mimeType = "image/jpeg";
         sceneMesh.texture = std::move(texAsset);
     }
     else if (!sceneInput.rgbTextureBytes.empty()) 
     {
         TextureAsset texAsset;
         texAsset.bytes = sceneInput.rgbTextureBytes;
         texAsset.mimeType = sceneInput.textureMimeType;
         sceneMesh.texture = std::move(texAsset);
     }

     return sceneMesh;
}