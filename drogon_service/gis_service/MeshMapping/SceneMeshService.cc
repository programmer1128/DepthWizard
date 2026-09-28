#include "SceneMeshService.h"
#include "LocalFrameTransformer.h"
#include "TerrainMesher.h"
#include "TerrainSurfaceComposer.h"
#include "TerrainTextureComposer.h"
#include "BuildingMesher.h"
#include "SceneAssembler.h"
#include "../FileGenerators/GltfPackager.h"
#include <iostream>
#include <unordered_set>
#include <algorithm>

GlbBuildResult SceneMeshService::generateGlb(
     const SceneInput& scene,
     const GeoreferencedSurfaceBundle& surface,
     const MeshPrimitive& externalBuildingMesh,
     const SpatialMetadata& metadata,
     const MeshBuildConfig& config)
{
     GlbBuildResult result;
     auto terrainConfig = config.terrain;
     const bool flat = config.presentation == ScenePresentation::FLAT_URBAN;
     if (flat) terrainConfig.elevationSource = TerrainElevationSource::FLAT_PRESENTATION;
     terrainConfig.generateSkirt = !flat;

     // Establish Mathematical Anchor
     LocalSceneFrame frame = LocalFrameTransformer::create(metadata, surface);

     // Generate Terrain Mesh
     TerrainMesh terrain = TerrainMesher::generate(
         surface,
         metadata,
         frame,
         terrainConfig);

     SceneMesh sceneMesh;
     sceneMesh.localFrame = frame;
     sceneMesh.presentationMode = flat ? "flat_urban" : "metric";
     sceneMesh.terrainPrimitive = std::move(terrain.terrainPrimitive);
     sceneMesh.wallPrimitive = externalBuildingMesh;

     sceneMesh.sceneBounds = sceneMesh.terrainPrimitive.localBounds;
     if (externalBuildingMesh.localBounds.isInitialized)
     {
         if (!sceneMesh.sceneBounds.isInitialized)
         {
             sceneMesh.sceneBounds = externalBuildingMesh.localBounds;
         }
         else
         {
             sceneMesh.sceneBounds.minX = std::min(sceneMesh.sceneBounds.minX, externalBuildingMesh.localBounds.minX);
             sceneMesh.sceneBounds.minY = std::min(sceneMesh.sceneBounds.minY, externalBuildingMesh.localBounds.minY);
             sceneMesh.sceneBounds.minZ = std::min(sceneMesh.sceneBounds.minZ, externalBuildingMesh.localBounds.minZ);
             sceneMesh.sceneBounds.maxX = std::max(sceneMesh.sceneBounds.maxX, externalBuildingMesh.localBounds.maxX);
             sceneMesh.sceneBounds.maxY = std::max(sceneMesh.sceneBounds.maxY, externalBuildingMesh.localBounds.maxY);
             sceneMesh.sceneBounds.maxZ = std::max(sceneMesh.sceneBounds.maxZ, externalBuildingMesh.localBounds.maxZ);
         }
     }

     sceneMesh.materials = {
         MaterialRole::TERRAIN_TEXTURE,
         MaterialRole::BUILDING_WALL
     };

     if (!scene.rgbTextureBytes.empty())
     {
         TextureAsset texAsset;
         texAsset.bytes = scene.rgbTextureBytes;
         texAsset.mimeType = scene.textureMimeType;
         sceneMesh.texture = std::move(texAsset);
     }

     // Compress Primitives Independently via Draco
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
         result.terrainTriangleCount = sceneMesh.terrainPrimitive.indices.size() / 3;
     }

     // Compress Buildings directly from externalBuildingMesh
     if (!externalBuildingMesh.indices.empty())
     {
         CompressedPrimitive compBuildings = DracoCompressor::compress(externalBuildingMesh, config.draco);
         if (!compBuildings.success)
         {
             result.geometryWarnings.push_back("Failed to compress Buildings: " + compBuildings.errorMessage);
             return result;
         }
         else
         {
             compressedPrimitives.push_back(std::move(compBuildings));
             result.vertexCount += externalBuildingMesh.positions.size() / 3;
             result.triangleCount += externalBuildingMesh.indices.size() / 3;
             result.wallTriangleCount = externalBuildingMesh.indices.size() / 3;
         }
     }

     // Abort if no geometry survived compression
     if (compressedPrimitives.empty())
     {
         result.geometryWarnings.push_back("Errror: All primitives failed compression. Cannot generate GLB.");
         return result;
     }

     // Binary Packaging
     size_t buildingCount = externalBuildingMesh.indices.empty() ? 0 : 1;

     GlbBuildResult packagedResult = GltfPackager::buildSceneToMemory(
         sceneMesh, compressedPrimitives, buildingCount);

     packagedResult.vertexCount = result.vertexCount;
     packagedResult.triangleCount = result.triangleCount;
     packagedResult.terrainTriangleCount = result.terrainTriangleCount;
     packagedResult.roofTriangleCount = result.roofTriangleCount;
     packagedResult.wallTriangleCount = result.wallTriangleCount;
     packagedResult.buildingCount = buildingCount;

     packagedResult.geometryWarnings.insert(
         packagedResult.geometryWarnings.end(),
         result.geometryWarnings.begin(),
         result.geometryWarnings.end()
     );

     return packagedResult;
}

GlbBuildResult SceneMeshService::generateGlb(
     const SceneInput& scene,
     const GeoreferencedSurfaceBundle& surface,
     const BuildingCollection& buildings,
     const SpatialMetadata& metadata,
     const MeshBuildConfig& config)
{
     GlbBuildResult result;
     auto terrainConfig = config.terrain;
     auto buildingConfig = config.building;
     const bool flat = config.presentation == ScenePresentation::FLAT_URBAN;
     if (flat) terrainConfig.elevationSource = TerrainElevationSource::FLAT_PRESENTATION;
     terrainConfig.generateSkirt = !flat;
     buildingConfig.flatPresentation = flat;

     //Establish Mathematical Anchor
     LocalSceneFrame frame = LocalFrameTransformer::create(metadata, surface);

     // Build a render-only mask from buildings that survived semantic,
     // topology, and physical validation. The scientific DSM remains intact.
     const RasterGrid<uint8_t> acceptedBuildingMask =
         TerrainSurfaceComposer::buildAcceptedBuildingMask(
             buildings,
             metadata,
             config.terrain.buildingTerrainClearanceMetres);

     // Default scene mode uses DTM throughout the continuous terrain.
     // Missing/rejected objects cannot become textured DSM mounds. The
     // scientific DSM stays in surface for exports and measurement.
     TerrainMesh terrain = TerrainMesher::generate(
         surface,
         acceptedBuildingMask,
         metadata,
         frame,
         terrainConfig);
     BuildingMesh bldgMesh = BuildingMesher::generate(buildings, frame, buildingConfig);
     for (uint32_t id : bldgMesh.rejectedBuildingIds)
     {
         result.geometryWarnings.push_back(
             "Building " + std::to_string(id) + " failed roof triangulation.");
     }

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
     sceneMesh.presentationMode = flat ? "flat_urban" : "metric";
     if (sceneMesh.texture.has_value() && !bldgMesh.emittedBuildingIds.empty())
     {
         // The DTM ground must not display a second photographic copy of the
         // accepted roofs around their untextured walls. Repair only the GLB
         // texture; the uploaded image and scientific rasters stay unchanged.
         const std::unordered_set<uint32_t> emittedIds(
             bldgMesh.emittedBuildingIds.begin(),
             bldgMesh.emittedBuildingIds.end());
         BuildingCollection emittedBuildings;
         for (const auto& building : buildings.buildings)
             if (emittedIds.contains(building.buildingId))
                 emittedBuildings.buildings.push_back(building);
         const RasterGrid<uint8_t> exactFootprints =
             TerrainSurfaceComposer::buildAcceptedBuildingMask(
                 emittedBuildings, metadata, 0.0f);
         sceneMesh.texture = TerrainTextureComposer::concealAcceptedRoofs(
             *sceneMesh.texture, exactFootprints, metadata,
             terrainConfig.buildingTextureHaloMetres);
     }

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
             return result;
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
             return result;
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
     size_t buildingCount = bldgMesh.emittedBuildingIds.size();
    
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
