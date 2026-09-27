#include "SceneMeshService.h"
#include "LocalFrameTransformer.h"
#include "TerrainMesher.h"
#include "TerrainSurfaceComposer.h"
#include "BuildingMesher.h"
#include "SceneAssembler.h"
#include "../FileGenerators/GltfPackager.h"
#include <iostream>

GlbBuildResult SceneMeshService::generateGlb(
     const SceneInput& scene,
     const GeoreferencedSurfaceBundle& surface,
     const BuildingCollection& buildings,
     const SpatialMetadata& metadata,
     const MeshBuildConfig& config)
{
     GlbBuildResult result;

     LocalSceneFrame frame = LocalFrameTransformer::create(metadata, surface);

     const RasterGrid<uint8_t> acceptedBuildingMask =
         TerrainSurfaceComposer::buildAcceptedBuildingMask(
             buildings,
             metadata,
             config.terrain.buildingTerrainClearanceMetres);

     TerrainMesh terrain = TerrainMesher::generate(
         surface,
         acceptedBuildingMask,
         metadata,
         frame,
         config.terrain);
         
     BuildingMesh bldgMesh = BuildingMesher::generate(buildings, frame, config.building);

     if (!buildings.buildings.empty() &&
         (bldgMesh.roofPrimitive.indices.empty() ||
          bldgMesh.wallPrimitive.indices.empty()))
     {
         result.geometryWarnings.push_back(
             "Accepted buildings produced no complete roof/wall geometry.");
         return result;
     }

     // =========================================================================
     // TEXTURE INPAINTING INTERCEPT (Telea Algorithm)
     // Delegates directly to the composer. Metadata is passed to calculate 
     // dynamic GSD-based kernel sizing.
     // =========================================================================
     std::vector<uint8_t> inpaintedTextureBytes;
     if (!scene.rgbTextureBytes.empty() && acceptedBuildingMask.isValid() && !buildings.buildings.empty())
     {
         inpaintedTextureBytes = TerrainSurfaceComposer::inpaintBuildingTextures(
             scene.rgbTextureBytes, acceptedBuildingMask, metadata);
     }

     // Assemble into Unified Scene using the override parameter cleanly
     SceneMesh sceneMesh = SceneAssembler::assemble(terrain, bldgMesh, scene, frame, inpaintedTextureBytes);

     // Compress Primitives Independently via Draco
     std::vector<CompressedPrimitive> compressedPrimitives;
    
     CompressedPrimitive compTerrain = DracoCompressor::compress(sceneMesh.terrainPrimitive, config.draco);
     if (!compTerrain.success) 
     {
         result.geometryWarnings.push_back("Failed to compress Terrain: " + compTerrain.errorMessage);
         return result;
     } 
     else 
     {
         compressedPrimitives.push_back(std::move(compTerrain));
         result.vertexCount += sceneMesh.terrainPrimitive.positions.size() / 3;
         result.triangleCount += sceneMesh.terrainPrimitive.indices.size() / 3;
         result.terrainTriangleCount = sceneMesh.terrainPrimitive.indices.size() / 3;
     }

     if (!sceneMesh.roofPrimitive.indices.empty())
     {
         CompressedPrimitive compRoofs = DracoCompressor::compress(sceneMesh.roofPrimitive, config.draco);
         if (!compRoofs.success) {
             result.geometryWarnings.push_back("Failed to compress Roofs: " + compRoofs.errorMessage);
         }
         else
         {
             compressedPrimitives.push_back(std::move(compRoofs));
             result.vertexCount += sceneMesh.roofPrimitive.positions.size() / 3;
             result.triangleCount += sceneMesh.roofPrimitive.indices.size() / 3;
             result.roofTriangleCount = sceneMesh.roofPrimitive.indices.size() / 3;
         }
     }

     if (!sceneMesh.wallPrimitive.indices.empty())
     {
         CompressedPrimitive compWalls = DracoCompressor::compress(sceneMesh.wallPrimitive, config.draco);
         if (!compWalls.success) {
             result.geometryWarnings.push_back("Failed to compress Walls: " + compWalls.errorMessage);
         }
         else
         {
             compressedPrimitives.push_back(std::move(compWalls));
             result.vertexCount += sceneMesh.wallPrimitive.positions.size() / 3;
             result.triangleCount += sceneMesh.wallPrimitive.indices.size() / 3;
             result.wallTriangleCount = sceneMesh.wallPrimitive.indices.size() / 3;
         }
     }

     if (compressedPrimitives.empty()) 
     {
         result.geometryWarnings.push_back("Error: All primitives failed compression. Cannot generate GLB.");
         return result;
     }

     size_t buildingCount = buildings.buildings.size();
     GlbBuildResult packagedResult = GltfPackager::buildSceneToMemory(
         sceneMesh, compressedPrimitives, buildingCount);
 
     packagedResult.vertexCount = result.vertexCount;
     packagedResult.triangleCount = result.triangleCount;
     packagedResult.terrainTriangleCount = result.terrainTriangleCount;
     packagedResult.roofTriangleCount = result.roofTriangleCount;
     packagedResult.wallTriangleCount = result.wallTriangleCount;
    
     packagedResult.geometryWarnings.insert(
         packagedResult.geometryWarnings.end(),
         result.geometryWarnings.begin(),
         result.geometryWarnings.end()
     );

     return packagedResult;
}