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
#include "../Vegetation/VegetationCanopyBuilder.h"
#include "../Vegetation/VegetationTreeCandidateGenerator.h"
#include "../Vegetation/VegetationTreeInstancer.h"
#include "../Vegetation/VegetationTreePackaging.h"
#include "../Vegetation/DenseForestProxyGenerator.h"
#include "../Vegetation/ExternalVegetationAssetLoader.h"
#include "../Vegetation/VegetationExternalPackaging.h"
#include "../Vegetation/VegetationCoverGenerator.h"
#include "../Vegetation/ForestTreeScatter.h"
#include "../Vegetation/VegetationHeightSampler.h"
#include "GeoTransformMapping.h"

using depthwizard::PresentationStyle;

GlbBuildResult SceneMeshService::generateGlb(
     const SceneInput& scene,
     const GeoreferencedSurfaceBundle& surface,
     const BuildingCollection& buildings,
     const SpatialMetadata& metadata,
     const MeshBuildConfig& config,
     const VegetationCanopyInput* vegetation)
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

     // Stage 5A: external assets (small bush, forest patch) when requested and
     // valid; otherwise the procedural stage-5 prototypes, unchanged.
     const VegetationAssetPrototypeProvider* assets = nullptr;
     if (vegetation != nullptr && vegetation->config.trees &&
         vegetation->config.assetMode == VegetationAssetMode::EXTERNAL)
     {
         assets = &VegetationAssetPrototypeProvider::instance();
         if (assets->bush() == nullptr)
         {
             result.geometryWarnings.push_back("External vegetation assets unavailable (" + assets->error() +
                                               "); using the procedural tree prototypes.");
             assets = nullptr;
         }
         else if (!assets->error().empty())
             result.geometryWarnings.push_back("Forest-patch asset unavailable (" + assets->error() +
                                               "); no forest patches.");
     }
     // External assets at individual-tree resolution: real shrubs fill the
     // vegetation the image shows, and the smooth canopy mound (which would
     // bury them and read as terrain contours) is not drawn.
     const bool coverActive = assets != nullptr && vegetation->semantics != nullptr && vegetation->mask != nullptr &&
         std::max(depthwizard::geo::columnSpacing(metadata), depthwizard::geo::rowSpacing(metadata)) <=
             vegetation->config.individualTreeMaxGsdMetres;

     // Vegetation canopy overlay: built after the scientific geometry, from
     // read-only inputs, and appended as its own node. Nothing above changes.
     std::vector<AppendedMeshNode> appendedNodes;
     if (vegetation != nullptr && vegetation->config.canopy && !coverActive)
     {
         VegetationCanopyMesh canopy = VegetationCanopyBuilder::build(
             *vegetation, surface, metadata, frame, terrainConfig, config.presentation);
         // Reuse the original optical image when the style already embeds it.
         int opticalTexture = -1;
         for (std::size_t index = 0; index < sceneMesh.textures.size(); ++index)
             if (sceneMesh.textures[index].semantic == TextureSemantic::OPTICAL_ORIGINAL)
             {
                 opticalTexture = static_cast<int>(index);
                 break;
             }
         if (!canopy.empty() && opticalTexture < 0 && hasOpticalImage && sceneMesh.texture == std::nullopt)
         {
             TextureAsset optical;
             optical.bytes = scene.rgbTextureBytes;
             optical.mimeType = scene.textureMimeType;
             optical.semantic = TextureSemantic::OPTICAL_ORIGINAL;
             sceneMesh.textures.push_back(std::move(optical));
             opticalTexture = static_cast<int>(sceneMesh.textures.size() - 1);
         }
         if (!canopy.empty() && opticalTexture < 0)
         {
             canopy.stats.skippedReason = "no optical image for the canopy texture";
             result.geometryWarnings.push_back("Vegetation canopy skipped: no optical image to texture it.");
         }
         else if (!canopy.empty())
         {
             CompressedPrimitive compressedCanopy = DracoCompressor::compress(canopy.primitive, config.draco);
             if (!compressedCanopy.success)
             {
                 canopy.stats.skippedReason = "compression failed";
                 result.geometryWarnings.push_back("Failed to compress the vegetation canopy: " +
                                                   compressedCanopy.errorMessage);
             }
             else
             {
                 const VegetationCanopyStats& s = canopy.stats;
                 const VegetationHeights& heights = *vegetation->heights;
                 const VegetationClassificationStats& c = vegetation->classification->stats;
                 AppendedMeshNode node;
                 node.name = "VEGETATION_CANOPY";
                 node.primitive = std::move(compressedCanopy);
                 node.material = depthwizard::presentation::textured(
                     depthwizard::presentation::material("Vegetation_Canopy_Optical", MaterialRole::VEGETATION_CANOPY,
                                                         {1.0, 1.0, 1.0, 1.0}, 0.0, 0.9, true),
                     opticalTexture, TextureSemantic::OPTICAL_ORIGINAL);
                 node.extras = {
                     {"geometrySemantic", std::string("VEGETATION_CANOPY")},
                     {"positionSource", std::string("SEMANTIC_VEGETATION")},
                     {"heightSource", std::string("NDSM")},
                     {"baseSource", std::string(s.presentationMode == "flat_urban" ? "FLAT_GROUND" : "TERRAIN_SURFACE")},
                     {"visualizationProxy", true},
                     {"scientificSurface", false},
                     {"speciesInferred", false},
                     {"externalGeographicDataUsed", false},
                     {"presentationMode", s.presentationMode},
                     {"displayHeightScale", static_cast<double>(s.displayHeightScale)},
                     {"metricHeightP05", static_cast<double>(heights.p05)},
                     {"metricHeightP50", static_cast<double>(heights.p50)},
                     {"metricHeightP95", static_cast<double>(heights.p95)},
                     {"metricHeightMax", static_cast<double>(s.metricHeightMax)},
                     {"displayHeightMin", static_cast<double>(s.displayHeightMin)},
                     {"displayHeightMax", static_cast<double>(s.displayHeightMax)},
                     {"gridStridePixels", static_cast<double>(s.stride)},
                     {"denseConfirmedPixels", static_cast<double>(c.denseConfirmed)},
                     {"denseRecoveredUnknownPixels", static_cast<double>(c.denseRecovered)},
                     {"denseGapClosedPixels", static_cast<double>(c.denseGap)},
                     {"deterministicSeed", static_cast<double>(vegetation->config.seed)},
                 };
                 appendedNodes.push_back(std::move(node));
             }
         }
         if (vegetation->output != nullptr) *vegetation->output = std::move(canopy);
     }

     // Tree visualization proxies (stage 5): EXT_mesh_gpu_instancing nodes
     // appended after everything else, from the stage-4 candidates.
     InstancedPackage treePackage;
     const bool haveCandidates = vegetation != nullptr && vegetation->treeCandidates != nullptr &&
                                 vegetation->treeCandidates->enabled && !vegetation->treeCandidates->candidates.empty();
     const double extent = std::max(metadata.width * depthwizard::geo::columnSpacing(metadata),
                                    metadata.height * depthwizard::geo::rowSpacing(metadata));
     if (assets != nullptr)
     {
         // Fine resolution: dense canopy becomes individually grounded library
         // trees; coarse imagery keeps the forest-patch proxies.
         ForestTrees forestTrees;
         const bool fine = std::max(depthwizard::geo::columnSpacing(metadata), depthwizard::geo::rowSpacing(metadata)) <=
                           vegetation->config.individualTreeMaxGsdMetres;
         if (fine && vegetation->config.forestProxies && assets->forestTrees() != nullptr && vegetation->mask != nullptr &&
             vegetation->classification != nullptr && vegetation->heights != nullptr)
         {
             ForestTreeScatterInput scatter;
             scatter.mask = vegetation->mask;
             scatter.classification = vegetation->classification;
             scatter.heights = vegetation->heights;
             scatter.surface = &surface;
             scatter.metadata = &metadata;
             scatter.frame = frame;
             scatter.terrainConfig = terrainConfig;
             scatter.presentation = config.presentation;
             scatter.config = vegetation->config;
             for (const ExternalVegetationAsset& tree : assets->forestTrees()->prototypes)
                 scatter.prototypeRadii.push_back(tree.horizontalRadius);
             scatter.chunkSizeMetres = VegetationTreeInstancer::chunkSize(vegetation->config, extent);
             forestTrees = ForestTreeScatter::generate(scatter);
         }
         DenseForestProxies forest;
         if (!fine && vegetation->config.forestProxies && assets->forest() != nullptr && vegetation->mask != nullptr &&
             vegetation->classification != nullptr && vegetation->heights != nullptr)
         {
             DenseForestProxyInput forestInput;
             forestInput.mask = vegetation->mask;
             forestInput.classification = vegetation->classification;
             forestInput.heights = vegetation->heights;
             forestInput.surface = &surface;
             forestInput.metadata = &metadata;
             forestInput.frame = frame;
             forestInput.terrainConfig = terrainConfig;
             forestInput.presentation = config.presentation;
             forestInput.config = vegetation->config;
             forestInput.prototypeRadius = assets->forest()->horizontalRadius;
             forestInput.chunkSizeMetres = VegetationTreeInstancer::chunkSize(vegetation->config, extent);
             forest = DenseForestProxyGenerator::generate(forestInput);
         }
         else
             forest.disabledReason = !vegetation->config.forestProxies ? "DEPTHWIZARD_VEGETATION_FOREST_PROXIES=0"
                 : fine ? (forestTrees.enabled ? "fine resolution: dense canopy drawn as " +
                                                     std::to_string(forestTrees.trees.size()) + " library trees"
                                               : forestTrees.disabledReason.empty() ? std::string("forest tree library unavailable")
                                                                                    : forestTrees.disabledReason)
                        : "forest asset or vegetation inputs unavailable";
         VegetationTreeInstances trees;
         if (haveCandidates)
             trees = VegetationTreeInstancer::build(*vegetation->treeCandidates, frame, vegetation->config, extent);
         const bool garden = config.presentation == ScenePresentation::FLAT_URBAN;
         VegetationExternalPackaging::selectAssets(trees, !forest.empty() || !forestTrees.empty(), garden && coverActive);
         VegetationCover cover;
         if (coverActive)
         {
             VegetationCoverInput coverInput;
             coverInput.mask = vegetation->mask;
             coverInput.semantics = vegetation->semantics;
             coverInput.surface = &surface;
             coverInput.metadata = &metadata;
             coverInput.opticalBytes = &scene.rgbTextureBytes;
             coverInput.frame = frame;
             coverInput.terrainConfig = terrainConfig;
             coverInput.presentation = config.presentation;
             coverInput.displayHeightScale = VegetationHeightSampler::displayHeightScale(
                 config.presentation, vegetation->buildingDisplayHeightScale);
             coverInput.config = vegetation->config;
             coverInput.chunkSizeMetres = VegetationTreeInstancer::chunkSize(vegetation->config, extent);
             if (!forestTrees.empty()) coverInput.forestDense = vegetation->classification;
             for (const TreeInstance& i : trees.instances)
                 if (i.rendered) coverInput.occupied.push_back({i.translation[0], i.translation[2], i.scale[0]});
             cover = VegetationCoverGenerator::generate(coverInput);
         }
         const float prominence = cover.enabled && cover.mode == VegetationCoverMode::NATURAL
                                      ? VegetationCoverGenerator::kNaturalProminence : 1.0f;
         treePackage = VegetationExternalPackaging::package(trees, forest, *assets->bush(), assets->forest(),
                                                            vegetation->config.seed, &cover, prominence, &forestTrees,
                                                            assets->forestTrees());
         if (vegetation->coverOutput != nullptr) *vegetation->coverOutput = std::move(cover);
         if (vegetation->treeOutput != nullptr) *vegetation->treeOutput = std::move(trees);
         if (vegetation->forestOutput != nullptr) *vegetation->forestOutput = std::move(forest);
     }
     else if (vegetation != nullptr && vegetation->config.trees && haveCandidates)
     {
         VegetationTreeInstances trees = VegetationTreeInstancer::build(
             *vegetation->treeCandidates, frame, vegetation->config, extent);
         treePackage = VegetationTreePackaging::package(
             trees, ProceduralTreePrototypeProvider::instance(), vegetation->config.seed);
         if (vegetation->treeOutput != nullptr) *vegetation->treeOutput = std::move(trees);
     }

     //Binary Packaging
     size_t buildingCount = bldgMesh.emittedBuildingIds.size();
    
     GlbBuildResult packagedResult = GltfPackager::buildSceneToMemory(
         sceneMesh, compressedPrimitives, buildingCount, appendedNodes,
         treePackage.empty() ? nullptr : &treePackage);
 
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
