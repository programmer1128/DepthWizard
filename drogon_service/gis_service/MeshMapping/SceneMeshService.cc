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

     //Establish Mathematical Anchor
     LocalSceneFrame frame = LocalFrameTransformer::create(metadata, surface);

     // Build a render-only mask from buildings that survived semantic,
     // topology, and physical validation. The scientific DSM remains intact.
     const RasterGrid<uint8_t> acceptedBuildingMask =
         TerrainSurfaceComposer::buildAcceptedBuildingMask(
             buildings,
             metadata,
             config.terrain.buildingTerrainClearanceMetres);

     // Generate independent geometry. Beneath accepted buildings the terrain
     // uses DTM, preventing a textured molten DSM mound from competing with
     // the sharp solid roof/wall primitives.
     TerrainMesh terrain = TerrainMesher::generate(
         surface,
         acceptedBuildingMask,
         metadata,
         frame,
         config.terrain);
     BuildingMesh bldgMesh = BuildingMesher::generate(buildings, frame, config.building);

     // An accepted building must materialize as both a roof and wall mesh.
     // Returning a terrain-only GLB in this state would silently recreate the
     // molten/textured result while claiming that buildings were reconstructed.
     if (!buildings.buildings.empty() &&
         (bldgMesh.roofPrimitive.indices.empty() ||
          bldgMesh.wallPrimitive.indices.empty()))
     {
         result.geometryWarnings.push_back(
             "Accepted buildings produced no complete roof/wall geometry.");
         return result;
     }

     //Assemble into Unified Scene
     SceneMesh sceneMesh = SceneAssembler::assemble(terrain, bldgMesh, scene, frame);

     //Compress Primitives Independently via Draco
     std::vector<CompressedPrimitive> compressedPrimitives;
    
     // Compress Terrain
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
         result.terrainTriangleCount =
             sceneMesh.terrainPrimitive.indices.size() / 3;
     }

     // Compress Roofs
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
             result.roofTriangleCount =
                 sceneMesh.roofPrimitive.indices.size() / 3;
         }
     }

     // Compress Walls (The Holographic Extrusions)
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
             result.wallTriangleCount =
                 sceneMesh.wallPrimitive.indices.size() / 3;
         }
     }

     // Abort if no geometry survived compression
     if (compressedPrimitives.empty()) 
     {
         result.geometryWarnings.push_back("Errror: All primitives failed compression. Cannot generate GLB.");
         return result;
     }

     //Binary Packaging
     size_t buildingCount = buildings.buildings.size();
    
     GlbBuildResult packagedResult = GltfPackager::buildSceneToMemory(
         sceneMesh, compressedPrimitives, buildingCount);
 
     // Merge metadata and pass back to PipelineService
     packagedResult.vertexCount = result.vertexCount;
     packagedResult.triangleCount = result.triangleCount;
     packagedResult.terrainTriangleCount = result.terrainTriangleCount;
     packagedResult.roofTriangleCount = result.roofTriangleCount;
     packagedResult.wallTriangleCount = result.wallTriangleCount;
    
     // Carry over any geometry warnings triggered during compression
     packagedResult.geometryWarnings.insert(
         packagedResult.geometryWarnings.end(),
         result.geometryWarnings.begin(),
         result.geometryWarnings.end()
     );

     return packagedResult;
}
