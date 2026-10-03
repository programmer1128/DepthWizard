#include "SceneMeshService.h"
#include "LocalFrameTransformer.h"
#include "TerrainMesher.h"
#include "TerrainSurfaceComposer.h"
#include "BuildingMesher.h"
#include "TerrainTextureComposer.h"
#include "FacadeAtlasGenerator.h"
#include "PresentationMaterials.h"
#include "SceneAssembler.h"
#include "../FileGenerators/GltfPackager.h"

using depthwizard::PresentationStyle;

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

     // Presentation styles change materials, textures and UVs only; geometry,
     // heights and exported rasters are identical in every style.
     const bool hasOpticalImage = !scene.rgbTextureBytes.empty() && !scene.textureMimeType.empty();
     PresentationStyle style = config.presentationStyle;
     if (style == PresentationStyle::ORTHOPHOTO_REALISTIC && !hasOpticalImage)
     {
         result.geometryWarnings.push_back(
             "Orthophoto presentation needs the optical image; using terra massing.");
         style = PresentationStyle::TERRA_MASSING;
     }
     buildingConfig.presentationStyle = style;
     buildingConfig.generateVertexColors = style == PresentationStyle::SCIENTIFIC;
     buildingConfig.generateRoofUVs = style == PresentationStyle::ORTHOPHOTO_REALISTIC;
     buildingConfig.generateWallUVs = style == PresentationStyle::ORTHOPHOTO_REALISTIC;
     buildingConfig.neutralFacades = config.neutralFacades;

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
     if (bldgMesh.roofUvOutOfBoundsVertexCount > 0)
     {
         result.geometryWarnings.push_back(
             std::to_string(bldgMesh.roofUvOutOfBoundsVertexCount) +
             " roof vertices lie outside the optical image; their texture is edge-clamped.");
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
     sceneMesh.presentationStyle = depthwizard::toString(style);

     if (style == PresentationStyle::SCIENTIFIC)
     {
         sceneMesh.materialDescriptors = depthwizard::presentation::scientificMaterials();
     }
     else
     {
         // glTF multiplies COLOR_0 into the base colour: drop the solid grey
         // terrain colours so the texture or material colour shows as-is.
         sceneMesh.terrainPrimitive.colors.reset();

         std::optional<int> repairedGround;
         if (hasOpticalImage)
         {
             TextureAsset optical;
             optical.bytes = scene.rgbTextureBytes;
             optical.mimeType = scene.textureMimeType;
             optical.semantic = TextureSemantic::OPTICAL_ORIGINAL;

             // Exact footprints (zero clearance), never the dilated terrain
             // clearance mask; buildingTextureHaloMetres alone adds the halo.
             TextureAsset ground = TerrainTextureComposer::concealAcceptedRoofs(
                 optical,
                 TerrainSurfaceComposer::buildExactFootprintMask(buildings, metadata),
                 metadata,
                 config.terrain.buildingTextureHaloMetres);
             ground.semantic = TextureSemantic::OPTICAL_GROUND_REPAIRED;
             sceneMesh.textures.push_back(std::move(ground));
             repairedGround = static_cast<int>(sceneMesh.textures.size() - 1);

             if (style == PresentationStyle::ORTHOPHOTO_REALISTIC)
             {
                 sceneMesh.textures.push_back(std::move(optical));
                 const int roofTexture = static_cast<int>(sceneMesh.textures.size() - 1);
                 sceneMesh.textures.push_back(
                     depthwizard::FacadeAtlasGenerator::generateAtlasPng(config.neutralFacades));
                 const int facadeTexture = static_cast<int>(sceneMesh.textures.size() - 1);
                 sceneMesh.materialDescriptors = depthwizard::presentation::orthophotoMaterials(
                     *repairedGround, roofTexture, facadeTexture);
                 sceneMesh.syntheticFacades = true;
             }
         }
         if (style == PresentationStyle::TERRA_MASSING)
             sceneMesh.materialDescriptors = depthwizard::presentation::terraMaterials(repairedGround);
     }

     if (const std::string problem = depthwizard::presentation::bindingProblem(sceneMesh); !problem.empty())
     {
         result.geometryWarnings.push_back("Material binding error: " + problem + ".");
         return result;
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
