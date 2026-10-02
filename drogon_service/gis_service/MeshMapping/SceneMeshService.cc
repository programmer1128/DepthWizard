#include "SceneMeshService.h"
#include "LocalFrameTransformer.h"
#include "TerrainMesher.h"
#include "TerrainSurfaceComposer.h"
#include "BuildingMesher.h"
#include "TerrainTextureComposer.h"
#include "FacadeAtlasGenerator.h"
#include "SceneAssembler.h"
#include "../FileGenerators/GltfPackager.h"

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
     buildingConfig.presentationStyle = config.presentationStyle;
     if (config.presentationStyle == depthwizard::PresentationStyle::ORTHOPHOTO_REALISTIC)
     {
         buildingConfig.generateRoofUVs = true;
         buildingConfig.generateWallUVs = true;
     }

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
     BuildingMesh bldgMesh = BuildingMesher::generate(buildings, frame, buildingConfig, &metadata);
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

     // Multi-texture & PBR material setup based on presentation style
     const bool hasOpticalImage = !scene.rgbTextureBytes.empty() && !scene.textureMimeType.empty();
     TextureAsset opticalAsset;
     if (hasOpticalImage)
     {
         opticalAsset.bytes = scene.rgbTextureBytes;
         opticalAsset.mimeType = scene.textureMimeType;
         opticalAsset.semantic = TextureSemantic::OPTICAL_ORIGINAL;
     }

     if (config.presentationStyle == depthwizard::PresentationStyle::ORTHOPHOTO_REALISTIC)
     {
         sceneMesh.presentationStyle = "ORTHOPHOTO_REALISTIC";
         if (hasOpticalImage)
         {
             // Zero geometric clearance mask for texture concealment
             const RasterGrid<uint8_t> exactBuildingMask =
                 TerrainSurfaceComposer::buildAcceptedBuildingMask(
                     buildings,
                     metadata,
                     0.0f);

             TextureAsset repairedOpt = TerrainTextureComposer::concealAcceptedRoofs(
                 opticalAsset,
                 exactBuildingMask,
                 metadata,
                 config.terrain.buildingTextureHaloMetres);
             repairedOpt.semantic = TextureSemantic::OPTICAL_GROUND_REPAIRED;

             TextureAsset origOpt = opticalAsset;
             origOpt.semantic = TextureSemantic::OPTICAL_ORIGINAL;

             TextureAsset facadeAtlas = depthwizard::FacadeAtlasGenerator::generateAtlasPng(false);
             facadeAtlas.semantic = TextureSemantic::FACADE_ATLAS;

             sceneMesh.textures = {repairedOpt, origOpt, facadeAtlas};

             // Material descriptors
             MaterialDescriptor terrainMat;
             terrainMat.name = "Terrain_Repaired_Optical";
             terrainMat.role = MaterialRole::TERRAIN_TEXTURE;
             terrainMat.textureSemantic = TextureSemantic::OPTICAL_GROUND_REPAIRED;
             terrainMat.textureIndex = 0;
             terrainMat.baseColorFactor = {1.0f, 1.0f, 1.0f, 1.0f};
             terrainMat.metallicFactor = 0.0f;
             terrainMat.roughnessFactor = 0.85f;
             terrainMat.doubleSided = false;

             MaterialDescriptor roofMat;
             roofMat.name = "Building_Roof_Optical";
             roofMat.role = MaterialRole::BUILDING_ROOF;
             roofMat.textureSemantic = TextureSemantic::OPTICAL_ORIGINAL;
             roofMat.textureIndex = 1;
             roofMat.baseColorFactor = {1.0f, 1.0f, 1.0f, 1.0f};
             roofMat.metallicFactor = 0.05f;
             roofMat.roughnessFactor = 0.60f;
             roofMat.doubleSided = true;

             MaterialDescriptor wallMat;
             wallMat.name = "Building_Wall_FacadeAtlas";
             wallMat.role = MaterialRole::BUILDING_WALL;
             wallMat.textureSemantic = TextureSemantic::FACADE_ATLAS;
             wallMat.textureIndex = 2;
             wallMat.baseColorFactor = {1.0f, 1.0f, 1.0f, 1.0f};
             wallMat.metallicFactor = 0.10f;
             wallMat.roughnessFactor = 0.50f;
             wallMat.doubleSided = true;

             sceneMesh.materialDescriptors = {terrainMat, roofMat, wallMat};
         }
     }
     else if (config.presentationStyle == depthwizard::PresentationStyle::TERRA_MASSING)
     {
         sceneMesh.presentationStyle = "TERRA_MASSING";
         if (hasOpticalImage)
         {
             const RasterGrid<uint8_t> exactBuildingMask =
                 TerrainSurfaceComposer::buildAcceptedBuildingMask(
                     buildings,
                     metadata,
                     0.0f);

             TextureAsset repairedOpt = TerrainTextureComposer::concealAcceptedRoofs(
                 opticalAsset,
                 exactBuildingMask,
                 metadata,
                 config.terrain.buildingTextureHaloMetres);
             repairedOpt.semantic = TextureSemantic::OPTICAL_GROUND_REPAIRED;

             sceneMesh.textures = {repairedOpt};

             MaterialDescriptor terrainMat;
             terrainMat.name = "Terrain_Repaired_Optical";
             terrainMat.role = MaterialRole::TERRAIN_TEXTURE;
             terrainMat.textureSemantic = TextureSemantic::OPTICAL_GROUND_REPAIRED;
             terrainMat.textureIndex = 0;
             terrainMat.baseColorFactor = {1.0f, 1.0f, 1.0f, 1.0f};
             terrainMat.metallicFactor = 0.0f;
             terrainMat.roughnessFactor = 0.85f;
             terrainMat.doubleSided = false;

             MaterialDescriptor roofMat;
             roofMat.name = "Building_Roof_TerraMassing";
             roofMat.role = MaterialRole::BUILDING_ROOF;
             roofMat.textureIndex = -1;
             roofMat.baseColorFactor = {0.95f, 0.94f, 0.90f, 1.0f};
             roofMat.metallicFactor = 0.0f;
             roofMat.roughnessFactor = 0.80f;
             roofMat.doubleSided = true;

             MaterialDescriptor wallMat;
             wallMat.name = "Building_Wall_TerraMassing";
             wallMat.role = MaterialRole::BUILDING_WALL;
             wallMat.textureIndex = -1;
             wallMat.baseColorFactor = {0.70f, 0.69f, 0.67f, 1.0f};
             wallMat.metallicFactor = 0.0f;
             wallMat.roughnessFactor = 0.85f;
             wallMat.doubleSided = true;

             sceneMesh.materialDescriptors = {terrainMat, roofMat, wallMat};
         }
         else
         {
             MaterialDescriptor terrainMat;
             terrainMat.name = "Terrain_Grey";
             terrainMat.role = MaterialRole::TERRAIN_TEXTURE;
             terrainMat.textureIndex = -1;
             terrainMat.baseColorFactor = {0.26, 0.26, 0.26, 1.0};
             terrainMat.unlit = true;

             MaterialDescriptor roofMat;
             roofMat.name = "Building_Roof_TerraMassing";
             roofMat.role = MaterialRole::BUILDING_ROOF;
             roofMat.textureIndex = -1;
             roofMat.baseColorFactor = {0.95f, 0.94f, 0.90f, 1.0f};
             roofMat.metallicFactor = 0.0f;
             roofMat.roughnessFactor = 0.80f;
             roofMat.doubleSided = true;

             MaterialDescriptor wallMat;
             wallMat.name = "Building_Wall_TerraMassing";
             wallMat.role = MaterialRole::BUILDING_WALL;
             wallMat.textureIndex = -1;
             wallMat.baseColorFactor = {0.70f, 0.69f, 0.67f, 1.0f};
             wallMat.metallicFactor = 0.0f;
             wallMat.roughnessFactor = 0.85f;
             wallMat.doubleSided = true;

             sceneMesh.materialDescriptors = {terrainMat, roofMat, wallMat};
         }
     }
     else
     {
         sceneMesh.presentationStyle = "SCIENTIFIC";
         MaterialDescriptor terrainMat;
         terrainMat.name = "Terrain_Grey";
         terrainMat.role = MaterialRole::TERRAIN_TEXTURE;
         terrainMat.textureIndex = -1;
         terrainMat.baseColorFactor = {0.26, 0.26, 0.26, 1.0};
         terrainMat.unlit = true;

         MaterialDescriptor roofMat;
         roofMat.name = "Building_Roof";
         roofMat.role = MaterialRole::BUILDING_ROOF;
         roofMat.textureIndex = -1;
         roofMat.baseColorFactor = {1.0f, 1.0f, 1.0f, 1.0f};
         roofMat.metallicFactor = 0.10f;
         roofMat.roughnessFactor = 0.40f;
         roofMat.doubleSided = true;

         MaterialDescriptor wallMat;
         wallMat.name = "Building_Wall";
         wallMat.role = MaterialRole::BUILDING_WALL;
         wallMat.textureIndex = -1;
         wallMat.baseColorFactor = {1.0f, 1.0f, 1.0f, 1.0f};
         wallMat.metallicFactor = 0.10f;
         wallMat.roughnessFactor = 0.40f;
         wallMat.doubleSided = true;

         MaterialDescriptor edgeMat;
         edgeMat.name = "Building_Edge_Highlight";
         edgeMat.role = MaterialRole::BUILDING_EDGE;
         edgeMat.textureIndex = -1;
         edgeMat.baseColorFactor = {1.0f, 1.0f, 1.0f, 1.0f};
         edgeMat.metallicFactor = 0.0f;
         edgeMat.roughnessFactor = 0.10f;

         sceneMesh.materialDescriptors = {terrainMat, roofMat, wallMat, edgeMat};
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
