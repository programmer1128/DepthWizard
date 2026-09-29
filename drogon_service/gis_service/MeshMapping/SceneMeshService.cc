#include "SceneMeshService.h"
#include "LocalFrameTransformer.h"
#include "TerrainMesher.h"
#include "TerrainSurfaceComposer.h"
#include "BuildingMesher.h"
#include "SceneAssembler.h"
#include "../FileGenerators/GltfPackager.h"

GlbBuildResult SceneMeshService::generateGlb(
     const SceneInput& scene,
     const GeoreferencedSurfaceBundle& surface,
     const BuildingCollection& buildings,
     const SpatialMetadata& metadata,
     const MeshBuildConfig& config,
     const MeshPrimitive* externalBuildingMesh) // <-- Add this parameter
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
     // Missing/rejected objects cannot become DSM mounds. The
     // scientific DSM stays in surface for exports and measurement.
     TerrainMesh terrain = TerrainMesher::generate(
         surface,
         acceptedBuildingMask,
         metadata,
         frame,
         terrainConfig);
     BuildingMesh bldgMesh = BuildingMesher::generate(buildings, frame, buildingConfig);
     // Fuse the external SAT2LoD2 buildings with the native semantic walls
     // Fuse the external SAT2LoD2 buildings with the native semantic walls
     if (externalBuildingMesh != nullptr && !externalBuildingMesh->indices.empty()) {
         // Count native vertices before appending
         size_t nativeVertCount = bldgMesh.wallPrimitive.positions.size() / 3;
         size_t externalVertCount = externalBuildingMesh->positions.size() / 3;
         uint32_t indexOffset = static_cast<uint32_t>(nativeVertCount);

         // 1. Pad Native Normals to match Positions
         if (externalBuildingMesh->normals.has_value()) {
             if (!bldgMesh.wallPrimitive.normals.has_value()) {
                 bldgMesh.wallPrimitive.normals.emplace();
             }
             // Fill missing native normals with a default outward vector
             while (bldgMesh.wallPrimitive.normals->size() < nativeVertCount * 3) {
                 bldgMesh.wallPrimitive.normals->push_back(0.0f);
                 bldgMesh.wallPrimitive.normals->push_back(1.0f);
                 bldgMesh.wallPrimitive.normals->push_back(0.0f);
             }
             bldgMesh.wallPrimitive.normals->insert(bldgMesh.wallPrimitive.normals->end(),
                                                    externalBuildingMesh->normals->begin(),
                                                    externalBuildingMesh->normals->end());
         }

         // 2. Pad Native Colors to match Positions
         if (externalBuildingMesh->colors.has_value()) {
             if (!bldgMesh.wallPrimitive.colors.has_value()) {
                 bldgMesh.wallPrimitive.colors.emplace();
             }
             // Fill missing native fallback buildings with a default Cyan MapFlow color
             while (bldgMesh.wallPrimitive.colors->size() < nativeVertCount * 4) {
                 bldgMesh.wallPrimitive.colors->push_back(0.0f);   // R
                 bldgMesh.wallPrimitive.colors->push_back(0.80f);  // G
                 bldgMesh.wallPrimitive.colors->push_back(0.95f);  // B
                 bldgMesh.wallPrimitive.colors->push_back(1.0f);   // A
             }
             bldgMesh.wallPrimitive.colors->insert(bldgMesh.wallPrimitive.colors->end(),
                                                   externalBuildingMesh->colors->begin(),
                                                   externalBuildingMesh->colors->end());
         }

         // 3. Append Positions (Must be done AFTER padding so nativeVertCount is accurate)
         bldgMesh.wallPrimitive.positions.insert(bldgMesh.wallPrimitive.positions.end(),
                                                 externalBuildingMesh->positions.begin(),
                                                 externalBuildingMesh->positions.end());

         // The native wall primitive carries one feature ID per vertex. Keep
         // that attribute aligned when SAT vertices have no feature IDs.
         if (bldgMesh.wallPrimitive.featureIds.has_value()) {
             if (externalBuildingMesh->featureIds.has_value()) {
                 bldgMesh.wallPrimitive.featureIds->insert(
                     bldgMesh.wallPrimitive.featureIds->end(),
                     externalBuildingMesh->featureIds->begin(),
                     externalBuildingMesh->featureIds->end());
             } else {
                 bldgMesh.wallPrimitive.featureIds->insert(
                     bldgMesh.wallPrimitive.featureIds->end(),
                     externalVertCount, 0.0f);
             }
         }

         // 4. Safely offset and append indices to prevent vertex collisions
         for (auto idx : externalBuildingMesh->indices) {
             bldgMesh.wallPrimitive.indices.push_back(idx + indexOffset);
         }
     }
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
