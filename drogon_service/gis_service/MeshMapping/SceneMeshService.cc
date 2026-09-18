#include "SceneMeshService.h"
#include "LocalFrameTransformer.h"
#include "TerrainMesher.h"
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

     //Generate Independent Geometry
     TerrainMesh terrain = TerrainMesher::generate(surface, metadata, frame, config.terrain);
     BuildingMesh bldgMesh = BuildingMesher::generate(buildings, frame, config.building);

     //Assemble into Unified Scene
     SceneMesh sceneMesh = SceneAssembler::assemble(terrain, bldgMesh, scene, frame);

     //Compress Primitives Independently via Draco
     std::vector<CompressedPrimitive> compressedPrimitives;
    
     // Compress Terrain
     CompressedPrimitive compTerrain = DracoCompressor::compress(sceneMesh.terrainPrimitive, config.draco);
     if (!compTerrain.success) 
     {
         result.geometryWarnings.push_back("Failed to compress Terrain: " + compTerrain.errorMessage);
     } 
     else 
     {
         compressedPrimitives.push_back(std::move(compTerrain));
         result.vertexCount += sceneMesh.terrainPrimitive.positions.size() / 3;
         result.triangleCount += sceneMesh.terrainPrimitive.indices.size() / 3;
     }

     // Compress Roofs
     CompressedPrimitive compRoofs = DracoCompressor::compress(sceneMesh.roofPrimitive, config.draco);
     if (!compRoofs.success) {
         result.geometryWarnings.push_back("Failed to compress Roofs: " + compRoofs.errorMessage);
     } 
     else 
     {
         compressedPrimitives.push_back(std::move(compRoofs));
         result.vertexCount += sceneMesh.roofPrimitive.positions.size() / 3;
         result.triangleCount += sceneMesh.roofPrimitive.indices.size() / 3;
     }

     // Compress Walls (The Holographic Extrusions)
     CompressedPrimitive compWalls = DracoCompressor::compress(sceneMesh.wallPrimitive, config.draco);
     if (!compWalls.success) {
         result.geometryWarnings.push_back("Failed to compress Walls: " + compWalls.errorMessage);
     } 
     else 
     {
         compressedPrimitives.push_back(std::move(compWalls));
         result.vertexCount += sceneMesh.wallPrimitive.positions.size() / 3;
         result.triangleCount += sceneMesh.wallPrimitive.indices.size() / 3;
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
    
     // Carry over any geometry warnings triggered during compression
     packagedResult.geometryWarnings.insert(
         packagedResult.geometryWarnings.end(),
         result.geometryWarnings.begin(),
         result.geometryWarnings.end()
     );

     return packagedResult;
}