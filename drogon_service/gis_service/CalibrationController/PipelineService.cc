#include "PipelineService.h"

#include "../BuildingReconstruction/BuildingReconstructionService.h"
#include "../BuildingReconstruction/City3dOrchestrator.h"
#include "../BuildingReconstruction/Sat2Lod2Importer.h"
#include "Sat2Lod2ModalTransport.h"
#include "../DataHandlers/MiniIOClient.h"
#include "../FileGenerators/BackgroundTiffExportService.h"
#include "../HeightService/BuildingQueryIndex.h"
#include "../utils/FeatureFlags.h"
#include "../ImagePreprocessing/ImagePreprocessingService.h"
#include "../ImagePreprocessing/RasterIngestService.h"
#include "../ImageTilingService/TilingService.h"
#include "../MeshMapping/SceneMeshService.h"
#include "../MeshMapping/LocalFrameTransformer.h"
#include "../MeshMapping/ScenePresentationPolicy.h"
#include "../MeshMapping/ScenePresentationSelector.h"
#include "../MeshMapping/TerrainSurfaceComposer.h"
#include "../Vegetation/VegetationCanopyBuilder.h"
#include "../Vegetation/VegetationClassifier.h"
#include "../Vegetation/VegetationDiagnostics.h"
#include "../Vegetation/VegetationExtractor.h"
#include "../Vegetation/VegetationHeightSampler.h"
#include "../Vegetation/VegetationTreeCandidateGenerator.h"
#include "../Vegetation/VegetationTreeDiagnostics.h"
#include "../Vegetation/VegetationTreeInstancer.h"
#include "../Vegetation/DenseForestProxyGenerator.h"
#include "../ReferenceTerrainService/MetricReferenceOrchestrator.h"
#include "../SemanticContext/GroundSurfaceService.h"
#include "../SemanticContext/SemanticPostProcessor.h"
#include "../SurfaceFusion/NdsmGroundBiasCorrector.h"
#include "../SurfaceFusion/SurfaceFusionService.h"

#include <cpl_vsi.h>
#include <drogon/utils/Utilities.h>
#include <ogr_spatialref.h>
#include <trantor/utils/Logger.h>

#include <cmath>
#include <limits>
#include <stdexcept>
#include <string>
#include <utility>
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <json/json.h>
#include <optional>
#include <opencv2/imgcodecs.hpp>
#include <chrono>

#include "../FileGenerators/TiffExporter.h"

// RasterIngestService mounts the upload in GDAL's in-memory filesystem.
// Keep it mounted while preprocessing and reference extraction read it, then
// remove it on both the successful and exception paths.
class VsiInputFileGuard
{
public:
    explicit VsiInputFileGuard(std::string path) : path_(std::move(path)) {}
    VsiInputFileGuard(const VsiInputFileGuard&) = delete;
    VsiInputFileGuard& operator=(const VsiInputFileGuard&) = delete;

    ~VsiInputFileGuard()
    {
        if (!path_.empty())
            VSIUnlink(path_.c_str());
    }

private:
    std::string path_;
};

template <typename T>
static void requireGridShape(const RasterGrid<T>& grid,
                             int width,
                             int height,
                             const char* name)
{
    if (!grid.isValid() || grid.width != width || grid.height != height)
        throw std::runtime_error(std::string("PipelineService: invalid ") +
                                 name + " grid shape");
}

// The present mesh and building-height algorithms use projected XY metres.
// Reprojection of geographic or feet-based inputs belongs in ingestion.
static void validateScene(const SceneInput& scene)
{
    if (!scene.spatialMetadata)   
    {
         throw std::runtime_error("PipelineService: GeoTIFF lacks spatial metadata");
    }

    const SpatialMetadata& metadata = *scene.spatialMetadata;
    if (!metadata.isGeoreferenced || metadata.width != scene.width ||
        metadata.height != scene.height || metadata.projectionRef.empty())
     {
         throw std::runtime_error("PipelineService: inconsistent spatial metadata");
     }
       

     OGRSpatialReference spatialReference;
     if (spatialReference.SetFromUserInput(metadata.projectionRef.c_str()) != OGRERR_NONE ||
         !spatialReference.IsProjected() ||
         std::abs(spatialReference.GetLinearUnits() - 1.0) > 1e-6)
     {
         throw std::runtime_error(
            "PipelineService: the working GeoTIFF CRS must be projected in metres");
     }
}

// Fail before dispatch if preprocessing cannot provide one RGB tensor and
// one usable validity mask covering the complete uploaded image.
static void validatePreprocessing(const SceneInput& scene,
                                  const ImageQualityResult& quality)
{
     requireGridShape(quality.validPixelMask, scene.width, scene.height,
                     "preprocessing valid mask");

     const auto& tensor = quality.normalizedRgbTensor;
     const size_t pixels = static_cast<size_t>(scene.width) * scene.height;
     if (tensor.width != scene.width || tensor.height != scene.height ||
         tensor.channels != 3 || tensor.layout != TensorLayout::CHW ||
         tensor.data.size() != pixels * 3)
     {
         throw std::runtime_error("PipelineService: invalid normalized RGB tensor");
     }
        
     if (!std::isfinite(quality.qualityScore) || quality.qualityScore <= 0.0f)  
     {
         throw std::runtime_error("PipelineService: no usable optical pixels");
     }
}

// Model A returns a full-resolution metric nDSM, its own confidence and its
// own validity mask. These values must never be confused with Model B output.
static void validateNdsmInference(const NdsmInferenceBundle& inference,
                                  int width,
                                  int height)
{
     requireGridShape(inference.globalMetricNdsm, width, height, "nDSM");
     requireGridShape(inference.globalNdsmConfidence, width, height,
                     "nDSM confidence");
     requireGridShape(inference.globalValidMask, width, height,
                     "nDSM valid mask");
}

// Model B independently returns six CHW logit planes, semantic confidence and
// a semantic validity mask on the source-image grid.
static void validateSemanticInference(const SemanticInferenceBundle& inference,
                                      int width,
                                      int height)
{
     if (inference.semanticSchemaId != DEPTHWIZARD_SEMANTIC_SCHEMA_ID)
     {
         throw std::runtime_error("PipelineService: incompatible semantic schema");
     }

     requireGridShape(inference.globalConfidence, width, height,
                     "semantic confidence");
     requireGridShape(inference.globalValidMask, width, height,
                     "semantic valid mask");

     const SemanticLogits& logits = inference.globalSemanticLogits;
     if (logits.classCount != 6 || logits.layout != TensorLayout::CHW)
     {
         throw std::runtime_error("PipelineService: incompatible semantic contract");
     }

     requireGridShape(logits.otherLogits, width, height, "other logits");
     requireGridShape(logits.groundLogits, width, height, "ground logits");
     requireGridShape(logits.lowVegetationLogits, width, height,
                     "low vegetation logits");
     requireGridShape(logits.buildingLogits, width, height, "building logits");
     requireGridShape(logits.roadLogits, width, height, "road logits");
     requireGridShape(logits.waterLogits, width, height, "water logits");
}

static void applyPreprocessingMask(NdsmInferenceBundle& inference,
                                   const ImageQualityResult& quality)
{
     const size_t pixels = inference.globalMetricNdsm.data.size();

     for (size_t i = 0; i < pixels; ++i)
     {
         if (inference.globalValidMask.data[i] == 0 ||
             quality.validPixelMask.data[i] == 0)
         {
             inference.globalValidMask.data[i] = 0;
             inference.globalMetricNdsm.data[i] =
                 std::numeric_limits<float>::quiet_NaN();
             inference.globalNdsmConfidence.data[i] = 0.0f;
             continue;
         }

         const float height = inference.globalMetricNdsm.data[i];
         const float confidence = inference.globalNdsmConfidence.data[i];
         if (!std::isfinite(height) || !std::isfinite(confidence) ||
             confidence < 0.0f || confidence > 1.0f)
         {
             throw std::runtime_error("PipelineService: invalid nDSM output values");
         }
     }
}

static void applyPreprocessingMask(SemanticInferenceBundle& inference,
                                   const ImageQualityResult& quality)
{
     SemanticLogits& logits = inference.globalSemanticLogits;
     const size_t pixels = inference.globalValidMask.data.size();

     for (size_t i = 0; i < pixels; ++i)
     {
         if (inference.globalValidMask.data[i] == 0 ||
             quality.validPixelMask.data[i] == 0)
         {
             inference.globalValidMask.data[i] = 0;
             inference.globalConfidence.data[i] = 0.0f;
             logits.otherLogits.data[i] = 0.0f;
             logits.groundLogits.data[i] = 0.0f;
             logits.lowVegetationLogits.data[i] = 0.0f;
             logits.buildingLogits.data[i] = 0.0f;
             logits.roadLogits.data[i] = 0.0f;
             logits.waterLogits.data[i] = 0.0f;
             continue;
         }

         const float confidence = inference.globalConfidence.data[i];
         if (!std::isfinite(confidence) || confidence < 0.0f || confidence > 1.0f ||
             !std::isfinite(logits.otherLogits.data[i]) ||
             !std::isfinite(logits.groundLogits.data[i]) ||
             !std::isfinite(logits.lowVegetationLogits.data[i]) ||
             !std::isfinite(logits.buildingLogits.data[i]) ||
             !std::isfinite(logits.roadLogits.data[i]) ||
             !std::isfinite(logits.waterLogits.data[i]))
         {
             throw std::runtime_error(
                 "PipelineService: invalid semantic output values");
         }
     }
}

// GLB publication remains on the request path: the frontend must receive a
// usable URL, not just a promise that mesh generation will finish later.
static std::string uploadGlb(const std::string& jobId,
                             const GlbBuildResult& glb)
{
     if (glb.compressedGlbByteBuffer.empty())
     {
         throw std::runtime_error("PipelineService: scene mesher returned an empty GLB");
     }

     const std::string objectKey = "mesh_" + jobId + ".glb";
     
     if (!MinioClient::uploadBuffer("terrain-assets", objectKey,
                                   glb.compressedGlbByteBuffer,
                                   "model/gltf-binary"))
     {
         throw std::runtime_error("PipelineService: GLB upload failed");
     }

     std::string url = MinioClient::generatePresignedUrl(
        "terrain-assets", objectKey);
     if (url.empty())
     {
         throw std::runtime_error("PipelineService: GLB URL generation failed");
     }

     return url;
}

drogon::Task<Json::Value> PipelineService::executeCalibration(
    const drogon::HttpFile& imageFile)
{
     const std::string jobId = drogon::utils::getUuid();

     // Hybrid-rendering flags, logged per job so every baseline records the
     // configuration it ran. Presentation styles apply to the GLB only.
     const HybridFeatureFlags featureFlags = HybridFeatureFlags::fromEnvironment();
     LOG_INFO << "PipelineService: " << jobId << " feature flags: " << featureFlags.summary();
     for (const std::string& warning : featureFlags.warnings)
         LOG_WARN << "PipelineService: " << warning;
     for (const std::string& request : featureFlags.unimplementedRequests())
         LOG_WARN << "PipelineService: " << request << " is not implemented yet; ignored.";

     // Start a SAT2LoD2 container now: a cold Modal start overlaps with
     // ingestion, preprocessing and model inference instead of adding to them.
     std::optional<Sat2Lod2Endpoint> satEndpoint;
     try
     {
         satEndpoint = Sat2Lod2ModalTransport::endpointFromEnvironment();
         if (satEndpoint->enabled && !satEndpoint->local)
             Sat2Lod2ModalTransport::wakeUp(satEndpoint->url);
     }
     catch (const std::exception& error)
     {
         LOG_WARN << "PipelineService: SAT2LoD2 disabled: " << error.what();
     }

     try
     {
         // 1. Ingest the GeoTIFF. The optical bytes guide reconstruction;
         //    the scene also holds a temporary GDAL path and georeferencing.
         SceneInput scene = RasterIngestService::ingestGeoTiff(jobId, imageFile);
         VsiInputFileGuard inputFile(scene.inputPath);
         validateScene(scene);
         const SpatialMetadata& metadata = *scene.spatialMetadata;

         // 2. Normalize RGB for the models and identify unusable source pixels.
         ImageQualityResult quality = ImagePreprocessingService::process(scene);
         validatePreprocessing(scene, quality);

         // 3. Build one shared tile plan, execute the two independent models,
         //    and stitch each branch using its own validity and confidence.
         DualModelInferenceBundle inference =
             co_await TilingService::generateStitchedInference(scene, quality);
         validateNdsmInference(inference.ndsm, scene.width, scene.height);
         validateSemanticInference(inference.semantics, scene.width, scene.height);
         applyPreprocessingMask(inference.ndsm, quality);
         applyPreprocessingMask(inference.semantics, quality);

         // 4. Fetch and align the low-resolution DEM. This supplies absolute
         //    ground elevation; the AI nDSM supplies above-ground height.
         ReferenceTerrainBundle reference =
             co_await MetricReferenceOrchestrator::prepareReferenceTerrain(scene);
         requireGridShape(reference.correctedTerrainPrior, scene.width,
                         scene.height, "reference DTM");
         requireGridShape(reference.validMask, scene.width,
                         scene.height, "reference valid mask");

         // 5. Decode semantic classes, locate trustworthy ground pixels, and
         //    remove any residual ground bias from the predicted metric nDSM.
         SemanticScene semantics = SemanticPostProcessor::buildScene(
             inference.semantics.globalSemanticLogits,
             inference.semantics.globalConfidence,
             inference.semantics.globalValidMask);
        
         GroundMask ground = GroundSurfaceService::buildGroundMask(
            semantics, quality, reference);
     
        NdsmCorrectionResult correction = NdsmGroundBiasCorrector::correct(
            inference.ndsm.globalMetricNdsm,
            ground,
            inference.ndsm.globalNdsmConfidence);

         // 6. Fuse terrain and corrected above-ground height into metric DSM.
         GeoreferencedSurfaceBundle surface =
             SurfaceFusionService::composeMetricSurface(
                 correction.correctedMetricNdsm,
                 reference,
                 semantics,
                 correction.confidence,
                 metadata);
         requireGridShape(surface.dsm, scene.width, scene.height, "DSM");
         requireGridShape(surface.dtm, scene.width, scene.height, "DTM");
         requireGridShape(surface.validMask, scene.width, scene.height,
                         "surface valid mask");

         scene.localFrame = LocalFrameTransformer::create(metadata, surface);

         // 7. SAT2LoD2 regularizes footprints and decomposes them into
         //    rectangles. It receives the corrected nDSM as its "DSM", so its
         //    bases sit at 0 m; its heights only describe roof shape, and
         //    Sat2Lod2Importer re-measures every block from our nDSM.
         std::string satBuildingsPath;
         std::optional<Json::Value> satBuildingsDocument;
         const std::filesystem::path satWorkDir =
             std::filesystem::temp_directory_path() / ("lod2_" + jobId);
         if (satEndpoint && satEndpoint->enabled)
         {
             try
             {
                 const std::string& satUrl = satEndpoint->url;
                 const bool localTransport = satEndpoint->local;
                 std::filesystem::create_directories(satWorkDir);
                 const std::string dsmPath = (satWorkDir / "ndsm.tif").string();
                 const std::string orthoPath =
                     (satWorkDir / (localTransport ? "ortho.jpg" : "ortho.tif")).string();
                 const std::string labelPath = (satWorkDir / "label.tif").string();

                 if (!TiffExporter::writeFloatTiff(
                         dsmPath, correction.correctedMetricNdsm.data,
                         metadata.width, metadata.height,
                         const_cast<double*>(metadata.geoTransform.data()),
                         metadata.projectionRef.c_str()))
                     throw std::runtime_error("Cannot export SAT2LoD2 nDSM TIFF");

                 std::vector<float> buildingMask(semantics.finalClassMap.data.size(), 0.0f);
                 for (std::size_t i = 0; i < semantics.finalClassMap.data.size(); ++i)
                     if (semantics.finalClassMap.data[i] == SemanticClass::BUILDING)
                         buildingMask[i] = 255.0f; // SAT2LoD2 foreground value
                 if (!TiffExporter::writeFloatTiff(
                         labelPath, buildingMask,
                         metadata.width, metadata.height,
                         const_cast<double*>(metadata.geoTransform.data()),
                         metadata.projectionRef.c_str()))
                     throw std::runtime_error("Cannot export SAT2LoD2 label TIFF");

                 if (localTransport)
                 {
                     std::ofstream orthoFile(orthoPath, std::ios::binary);
                     orthoFile.write(
                         reinterpret_cast<const char*>(scene.rgbTextureBytes.data()),
                         static_cast<std::streamsize>(scene.rgbTextureBytes.size()));
                     if (!orthoFile)
                         throw std::runtime_error("Cannot export SAT2LoD2 optical JPEG");
                 }
                 else
                 {
                     const cv::Mat optical = cv::imdecode(
                         scene.rgbTextureBytes, cv::IMREAD_COLOR);
                     // Uncompressed: OpenCV's default LZW needs the Python
                     // imagecodecs package, which SAT2LoD2's reader lacks.
                     if (optical.empty() || optical.cols != metadata.width ||
                         optical.rows != metadata.height ||
                         !cv::imwrite(orthoPath, optical,
                                      {cv::IMWRITE_TIFF_COMPRESSION, 1}))
                         throw std::runtime_error("Cannot export SAT2LoD2 optical TIFF");
                 }

                 const char* timeoutSetting = std::getenv("DEPTHWIZARD_SAT2LOD2_TIMEOUT_S");
                 const double timeoutSeconds = timeoutSetting ? std::atof(timeoutSetting) : 900.0;
                 drogon::HttpRequestPtr req;
                 if (localTransport)
                 {
                     Json::Value pyRequest;
                     pyRequest["dsm_path"] = dsmPath;
                     pyRequest["ortho_path"] = orthoPath;
                     pyRequest["label_path"] = labelPath;
                     pyRequest["output_dir"] = (satWorkDir / "out").string();
                     req = drogon::HttpRequest::newHttpJsonRequest(pyRequest);
                     req->setPath("/api/v1/reconstruct");
                     req->setMethod(drogon::Post);
                 }
                 else
                     req = Sat2Lod2ModalTransport::makeRequest(
                         dsmPath, orthoPath, labelPath);
                 LOG_INFO << "PipelineService: awaiting SAT2LoD2 "
                          << (localTransport ? "local" : "Modal") << " reconstruction";
                 auto pyResponse = co_await Sat2Lod2ModalTransport::send(
                     satUrl, req, timeoutSeconds > 0.0 ? timeoutSeconds : 900.0);
                 if (localTransport)
                 {
                     if (!pyResponse || pyResponse->statusCode() != 200 ||
                         !pyResponse->getJsonObject() ||
                         !(*pyResponse->getJsonObject())["buildings_path"].isString())
                         throw std::runtime_error("SAT2LoD2 did not return buildings_path");
                     satBuildingsPath =
                         (*pyResponse->getJsonObject())["buildings_path"].asString();
                     LOG_INFO << "PipelineService: received local SAT2LoD2 buildings at "
                              << satBuildingsPath;
                 }
                 else
                 {
                     satBuildingsDocument =
                         Sat2Lod2ModalTransport::readBuildings(pyResponse);
                     LOG_INFO << "PipelineService: received Modal SAT2LoD2 building document";
                 }
             }
             catch (const std::exception& error)
             {
                 LOG_WARN << "PipelineService: SAT2LoD2 unavailable: "
                          << error.what() << "; using native reconstruction";
             }
         }

         const char* diagnosticsSetting = std::getenv("DEPTHWIZARD_DIAGNOSTICS");
         const bool captureDiagnostics = !diagnosticsSetting || std::string(diagnosticsSetting) != "0";
         BuildingReconstructionDiagnostics stages;
         BuildingReconstructionConfig config;
         // The detailed result keeps the authoritative instance labels that
         // City3D inputs are cut from.
         BuildingReconstructionResult reconstruction = BuildingReconstructionService::reconstructDetailed(
             semantics, surface, metadata, config,
             captureDiagnostics ? &stages : nullptr,
             &correction.correctedMetricNdsm, &scene.rgbTextureBytes);
         BuildingCollection buildings = std::move(reconstruction.buildings);

         bool usingSat2Lod2 = false;
         if (satBuildingsDocument || !satBuildingsPath.empty())
         {
             Sat2Lod2ImportResult imported = satBuildingsDocument
                 ? Sat2Lod2Importer::import(
                     *satBuildingsDocument, semantics, surface, metadata, config,
                     correction.correctedMetricNdsm)
                 : Sat2Lod2Importer::importFile(
                     satBuildingsPath, semantics, surface, metadata, config,
                     correction.correctedMetricNdsm);
             for (const std::string& warning : imported.warnings)
                 LOG_WARN << "PipelineService: " << jobId << ": " << warning;
             if (!imported.buildings.buildings.empty())
             {
                 const std::size_t keptNative = Sat2Lod2Importer::appendUncoveredNative(
                     imported.buildings, buildings, metadata);
                 LOG_INFO << "PipelineService: SAT2LoD2 segments=" << imported.segmentCount
                          << "; parts=" << imported.buildings.buildings.size() - keptNative
                          << "; rectangle_parts=" << imported.buildings.lod2BlockCount
                          << "; residual_parts=" << imported.residualPartCount
                          << "; irregular=" << imported.irregularCount
                          << "; skipped=" << imported.skippedSegmentCount
                          << "; native_kept=" << keptNative
                          << "; native_replaced=" << buildings.buildings.size() - keptNative;
                 buildings = std::move(imported.buildings);
                 usingSat2Lod2 = true;
             }
         }
         std::error_code cleanupError;
         std::filesystem::remove_all(satWorkDir, cleanupError);

         // City3D (DEPTHWIZARD_CITY3D=1): per-building expert on native
         // geometry. Shadow mode measures only; selected mode attaches
         // validated shells. Any failure keeps that building native.
         std::optional<City3dRunSummary> city3dSummary;
         City3dConfig city3dConfig;
         if (featureFlags.city3d)
         {
             city3dConfig = City3dConfig::fromEnvironment();
             if (usingSat2Lod2)
             {
                 // SAT2LoD2 renumbers buildings, so instance labels no longer match.
                 city3dSummary.emplace();
                 city3dSummary->skippedReason = "sat2lod2_geometry";
             }
             else
             {
                 city3dSummary = City3dOrchestrator::run(
                     buildings, reconstruction.instanceLabels, semantics, surface,
                     correction.correctedMetricNdsm, metadata, config.heightScaleMultiplier,
                     city3dConfig, jobId);
             }
             city3dSummary->mode = toString(featureFlags.city3dMode);
             for (const City3dBuildingOutcome& outcome : city3dSummary->outcomes)
             {
                 if (outcome.route == "not_eligible") continue;
                 LOG_INFO << "PipelineService: City3D " << jobId << " building " << outcome.buildingId
                          << " route=" << outcome.route << " reason=" << outcome.reason
                          << " worker_status=" << outcome.workerStatus
                          << " points=" << outcome.points << " elapsed_ms=" << outcome.elapsedMs;
             }
             std::size_t attached = 0;
             if (featureFlags.city3dMode == City3dMode::Selected)
                 attached = City3dOrchestrator::attachAcceptedShells(buildings, *city3dSummary);
             LOG_INFO << "PipelineService: City3D " << jobId << " mode=" << city3dSummary->mode
                      << (city3dSummary->skippedReason.empty() ? "" : " skipped=" + city3dSummary->skippedReason)
                      << " eligible=" << city3dSummary->eligibleCount
                      << " accepted=" << city3dSummary->acceptedShells.size()
                      << " attached=" << attached << " total_ms=" << city3dSummary->totalMs;
             std::filesystem::create_directories(city3dConfig.workRoot / jobId, cleanupError);
             Json::StreamWriterBuilder summaryWriter;
             summaryWriter["indentation"] = "  ";
             std::ofstream(city3dConfig.workRoot / jobId / "summary.json")
                 << Json::writeString(summaryWriter, City3dOrchestrator::toJson(*city3dSummary)) << "\n";
         }

         MeshBuildConfig meshConfig;
         meshConfig.presentationStyle = featureFlags.presentationStyle;
         meshConfig.neutralFacades = featureFlags.neutralFacades;
         const ScenePresentationDecision sceneDecision = ScenePresentationSelector::select(
             semantics, surface, buildings);
         // DEPTHWIZARD_PRESENTATION: auto (default) lets the selector decide;
         // flat_urban and metric are explicit operator overrides. Render-only.
         const ScenePresentationPolicySetting presentationPolicy = scenePresentationPolicyFromEnvironment();
         if (presentationPolicy.warning)
             LOG_WARN << "PipelineService: " << jobId << ": " << *presentationPolicy.warning;
         const ScenePresentation presentation =
             resolveScenePresentation(presentationPolicy.policy, sceneDecision);
         meshConfig.presentation = presentation;

         LOG_INFO << "PipelineService: automatic scene policy for " << jobId
                  << "; requested_presentation=" << toString(presentationPolicy.policy)
                  << "; selected_presentation=" << toString(sceneDecision.presentation)
                  << "; resolved_presentation=" << toString(presentation)
                  << "; " << sceneDecision.reason
                  << "; strong_building_fraction=" << sceneDecision.strongBuildingFraction
                  << "; vegetation_fraction=" << sceneDecision.vegetationFraction
                  << "; supported_ground_relief_m=" << sceneDecision.groundReliefMetres
                  << "; accepted_buildings=" << buildings.buildings.size()
                  << "; building_source=" << (usingSat2Lod2 ? "sat2lod2" : "native");
         // Vegetation overlay (DEPTHWIZARD_VEGETATION, default 0): a canopy
         // node appended after the unchanged scene. With the flag off nothing
         // below runs and the GLB is produced exactly as before. Every input
         // is read-only; the state lives here so the canopy input outlives
         // the GLB build.
         const VegetationConfig vegetationConfig = VegetationConfig::fromEnvironment();
         for (const std::string& warning : vegetationConfig.warnings)
             LOG_WARN << "PipelineService: " << jobId << ": " << warning;
         std::optional<VegetationMask> vegetationMask;
         std::optional<VegetationHeights> vegetationHeights;
         std::optional<VegetationClassification> vegetationClasses;
         std::optional<VegetationTreeCandidates> vegetationTrees;
         VegetationCanopyMesh vegetationCanopy;
         VegetationTreeInstances vegetationTreeInstances;
         DenseForestProxies vegetationForest;
         VegetationCover vegetationCover;
         bool forestRequested = false;
         bool coverRequested = false;
         VegetationCanopyInput canopyInput;
         const VegetationCanopyInput* vegetationForGlb = nullptr;
         double vegetationMs = 0.0;
         if (vegetationConfig.enabled())
         {
             const auto vegetationStarted = std::chrono::steady_clock::now();
             vegetationMask = VegetationExtractor::extract(
                 semantics, surface, TerrainSurfaceComposer::buildExactFootprintMask(buildings, metadata),
                 metadata, vegetationConfig);
             vegetationHeights = VegetationHeightSampler::sample(*vegetationMask, surface, vegetationConfig);
             vegetationClasses = VegetationClassifier::classify(*vegetationMask, vegetationConfig);
             vegetationMs = std::chrono::duration<double, std::milli>(
                 std::chrono::steady_clock::now() - vegetationStarted).count();
             LOG_INFO << "PipelineService: " << jobId << " " << vegetationConfig.summary();
             for (const std::string& line : VegetationDiagnostics::summaryLines(
                      *vegetationMask, *vegetationHeights, vegetationMs))
                 LOG_INFO << "PipelineService: " << jobId << " " << line;
             const bool usable = vegetationMask->inputsAvailable && vegetationMask->stats.cleanedPixels() > 0;
             // auto: only with dense vegetation to show; 1: whenever usable.
             const bool canopyRequested = vegetationConfig.canopy && usable &&
                 (vegetationConfig.mode == VegetationMode::ON || vegetationClasses->stats.densePixels > 0);
             // Stage 4: individual-tree candidates (diagnostics only; nothing
             // is rendered yet, so the GLB is unchanged).
             if (vegetationConfig.trees && usable)
             {
                 VegetationTreeInput treeInput;
                 treeInput.mask = &*vegetationMask;
                 treeInput.classification = &*vegetationClasses;
                 treeInput.heights = &*vegetationHeights;
                 treeInput.semantics = &semantics;
                 treeInput.surface = &surface;
                 treeInput.metadata = &metadata;
                 treeInput.frame = scene.localFrame;
                 treeInput.terrainConfig = meshConfig.terrain;
                 if (presentation == ScenePresentation::FLAT_URBAN)
                     treeInput.terrainConfig.elevationSource = TerrainElevationSource::FLAT_PRESENTATION;
                 treeInput.presentation = presentation;
                 treeInput.buildingDisplayHeightScale = config.heightScaleMultiplier;
                 treeInput.config = vegetationConfig;
                 treeInput.recoveryNdsm = &correction.correctedMetricNdsm;
                 vegetationTrees = VegetationTreeCandidateGenerator::generate(treeInput);
                 for (const std::string& line : VegetationTreeDiagnostics::summaryLines(*vegetationTrees))
                     LOG_INFO << "PipelineService: " << jobId << " " << line;
             }
             // Stage 5: render the candidates as instanced proxies.
             const bool treesRequested = vegetationTrees && vegetationTrees->enabled &&
                                         !vegetationTrees->candidates.empty();
             // Stage 5A: forest patches may appear without tree candidates
             // (coarse metric forest), so they need the vegetation input too.
             forestRequested = vegetationConfig.trees && usable && vegetationConfig.forestProxies &&
                               vegetationConfig.assetMode == VegetationAssetMode::EXTERNAL &&
                               presentation == ScenePresentation::METRIC && vegetationClasses->stats.densePixels > 0;
             // Shrub cover (external assets, individual-tree resolution).
             coverRequested = vegetationConfig.trees && vegetationMask->inputsAvailable &&
                              vegetationConfig.assetMode == VegetationAssetMode::EXTERNAL &&
                              vegetationClasses->stats.individualTreesResolvable;
             if (canopyRequested || treesRequested || forestRequested || coverRequested)
             {
                 canopyInput.mask = &*vegetationMask;
                 canopyInput.classification = &*vegetationClasses;
                 canopyInput.heights = &*vegetationHeights;
                 canopyInput.config = vegetationConfig;
                 canopyInput.config.canopy = canopyRequested;
                 canopyInput.buildingDisplayHeightScale = config.heightScaleMultiplier;
                 canopyInput.output = &vegetationCanopy;
                 canopyInput.treeCandidates = treesRequested ? &*vegetationTrees : nullptr;
                 canopyInput.treeOutput = &vegetationTreeInstances;
                 canopyInput.forestOutput = &vegetationForest;
                 canopyInput.semantics = &semantics;
                 canopyInput.coverOutput = &vegetationCover;
                 vegetationForGlb = &canopyInput;
             }
             LOG_INFO << "PipelineService: " << jobId << " [Vegetation] usable=" << usable
                      << ", display_height_scale=" << VegetationHeightSampler::displayHeightScale(
                             presentation, config.heightScaleMultiplier)
                      << ", canopy_requested=" << canopyRequested
                      << ", tree_candidates=" << (vegetationTrees ? vegetationTrees->candidates.size() : 0)
                      << ", trees_requested=" << treesRequested << ", asset_mode=" << toString(vegetationConfig.assetMode)
                      << ", forest_requested=" << forestRequested << ", cover_requested=" << coverRequested;
         }

         const auto glbStarted = std::chrono::steady_clock::now();
         GlbBuildResult glb = SceneMeshService::generateGlb(
            scene, surface, buildings, metadata, meshConfig, vegetationForGlb);
         const double glbMs = std::chrono::duration<double, std::milli>(
             std::chrono::steady_clock::now() - glbStarted).count();

         if (vegetationConfig.enabled() && vegetationClasses)
         {
             for (const std::string& line : VegetationDiagnostics::canopyLines(*vegetationClasses, vegetationCanopy))
                 LOG_INFO << "PipelineService: " << jobId << " " << line;
             if (!vegetationTreeInstances.empty())
                 for (const std::string& line : VegetationTreeDiagnostics::instanceLines(vegetationTreeInstances))
                     LOG_INFO << "PipelineService: " << jobId << " " << line;
             if (forestRequested)
                 for (const std::string& line : VegetationTreeDiagnostics::forestLines(vegetationForest))
                     LOG_INFO << "PipelineService: " << jobId << " " << line;
             if (coverRequested)
                 LOG_INFO << "PipelineService: " << jobId << " " << VegetationTreeDiagnostics::coverLine(vegetationCover);
             if (vegetationConfig.diagnostics)
             {
                 const char* root = std::getenv("DEPTHWIZARD_DIAGNOSTICS_DIR");
                 const std::filesystem::path folder =
                     std::filesystem::path(root && *root ? root : "reconstruction_diagnostics") / jobId / "vegetation";
                 const cv::Mat optical = cv::imdecode(scene.rgbTextureBytes, cv::IMREAD_COLOR);
                 bool written = VegetationDiagnostics::write(folder, vegetationConfig, semantics, *vegetationMask,
                                                             *vegetationHeights, optical, vegetationMs) &&
                                VegetationDiagnostics::writeCanopy(folder, *vegetationClasses, *vegetationMask,
                                                                   vegetationCanopy, optical);
                 if (vegetationTrees)
                     written = VegetationTreeDiagnostics::write(folder, *vegetationTrees, vegetationMask->scale,
                                                                surface.ndsm, vegetationHeights->ceilingMetres,
                                                                optical) && written;
                 if (!vegetationTreeInstances.empty())
                     written = VegetationTreeDiagnostics::writeInstances(folder, vegetationTreeInstances) && written;
                 if (forestRequested)
                     written = VegetationTreeDiagnostics::writeForest(folder, vegetationForest) && written;
                 if (coverRequested)
                     written = VegetationTreeDiagnostics::writeCover(folder, vegetationCover, optical) && written;
                 // Same-run comparison: the GLB without vegetation, built from
                 // identical inputs (local diagnostics only).
                 const auto baseStarted = std::chrono::steady_clock::now();
                 const GlbBuildResult withoutVegetation =
                     SceneMeshService::generateGlb(scene, surface, buildings, metadata, meshConfig);
                 const double baseMs = std::chrono::duration<double, std::milli>(
                     std::chrono::steady_clock::now() - baseStarted).count();
                 const auto writeGlb = [&](const char* name, const std::vector<uint8_t>& bytes)
                 {
                     std::ofstream file(folder / name, std::ios::binary);
                     file.write(reinterpret_cast<const char*>(bytes.data()), static_cast<std::streamsize>(bytes.size()));
                     return static_cast<bool>(file);
                 };
                 written = writeGlb("without_vegetation.glb", withoutVegetation.compressedGlbByteBuffer) &&
                           writeGlb("with_vegetation.glb", glb.compressedGlbByteBuffer) && written;
                 LOG_INFO << "PipelineService: " << jobId << " [Vegetation] glb_build_ms with=" << glbMs
                          << " without=" << baseMs << " bytes_with=" << glb.compressedGlbByteBuffer.size()
                          << " bytes_without=" << withoutVegetation.compressedGlbByteBuffer.size();
                 // Stage 5 rollback paths from the same inputs: canopy only
                 // (the stage-3 output) and trees only.
                 if (vegetationForGlb && canopyInput.config.canopy && (canopyInput.treeCandidates || forestRequested || coverRequested))
                 {
                     VegetationCanopyInput canopyOnly = canopyInput;
                     VegetationCanopyMesh canopyScratch;
                     canopyOnly.output = &canopyScratch;
                     canopyOnly.treeCandidates = nullptr;
                     canopyOnly.treeOutput = nullptr;
                     canopyOnly.forestOutput = nullptr;
                     canopyOnly.coverOutput = nullptr;
                     canopyOnly.config.trees = false;   // No bushes, procedural trees or forest patches
                     VegetationCanopyInput treesOnly = canopyInput;
                     treesOnly.config.canopy = false;
                     treesOnly.output = nullptr;
                     treesOnly.treeOutput = nullptr;
                     if (canopyInput.config.assetMode == VegetationAssetMode::EXTERNAL)
                     {
                         VegetationCanopyInput procedural = canopyInput;
                         VegetationCanopyMesh proceduralCanopy;
                         procedural.config.assetMode = VegetationAssetMode::PROCEDURAL;
                         procedural.output = &proceduralCanopy;
                         procedural.treeOutput = nullptr;
                         procedural.forestOutput = nullptr;
                         procedural.coverOutput = nullptr;
                         written = writeGlb("procedural_with_vegetation.glb", SceneMeshService::generateGlb(
                                       scene, surface, buildings, metadata, meshConfig, &procedural).compressedGlbByteBuffer) &&
                                   written;
                     }
                     treesOnly.forestOutput = nullptr;
                     treesOnly.coverOutput = nullptr;
                     written = writeGlb("canopy_only.glb", SceneMeshService::generateGlb(
                                   scene, surface, buildings, metadata, meshConfig, &canopyOnly).compressedGlbByteBuffer) &&
                               writeGlb("trees_only.glb", SceneMeshService::generateGlb(
                                   scene, surface, buildings, metadata, meshConfig, &treesOnly).compressedGlbByteBuffer) &&
                               written;
                 }
                 if (!written)
                     LOG_WARN << "PipelineService: " << jobId << ": cannot write vegetation diagnostics to " << folder;
             }
         }

         LOG_INFO << "PipelineService: mesh summary for " << jobId
                  << "; presentation=" << toString(presentation)
                  << "; emitted_buildings=" << glb.buildingCount
                  << "; terrain_triangles=" << glb.terrainTriangleCount
                  << "; roof_triangles=" << glb.roofTriangleCount
                  << "; wall_triangles=" << glb.wallTriangleCount
                  << "; glb_bytes=" << glb.compressedGlbByteBuffer.size();

         for (const std::string& warning : glb.geometryWarnings)
         {
             LOG_WARN << "PipelineService: " << jobId << ": " << warning;
         }

         // City3D comparison files (local only): in shadow mode the returned
         // GLB is native, so also mesh the accepted shells for comparison.
         if (city3dSummary && !city3dSummary->acceptedShells.empty())
         {
             const std::filesystem::path city3dDirectory = city3dConfig.workRoot / jobId;
             const auto writeGlb = [&](const std::string& name, const std::vector<uint8_t>& bytes)
             {
                 std::ofstream file(city3dDirectory / name, std::ios::binary);
                 file.write(reinterpret_cast<const char*>(bytes.data()), static_cast<std::streamsize>(bytes.size()));
             };
             if (featureFlags.city3dMode == City3dMode::Shadow)
             {
                 BuildingCollection compared = buildings;
                 City3dOrchestrator::attachAcceptedShells(compared, *city3dSummary);
                 const GlbBuildResult comparison = SceneMeshService::generateGlb(
                     scene, surface, compared, metadata, meshConfig);
                 writeGlb("native_baseline.glb", glb.compressedGlbByteBuffer);
                 writeGlb("city3d_comparison.glb", comparison.compressedGlbByteBuffer);
                 LOG_INFO << "PipelineService: City3D " << jobId << " comparison GLB "
                          << comparison.compressedGlbByteBuffer.size() << " bytes in " << city3dDirectory;
             }
             else
                 writeGlb("city3d_selected.glb", glb.compressedGlbByteBuffer);
         }

         // 8. Upload the finished GLB before replying to the frontend.
         std::string glbUrl = uploadGlb(jobId, glb);

         // Height queries answer per building, keyed by the IDs the GLB
         // carries in _FEATURE_ID_0. Build before diagnostics take them.
         BuildingQueryIndex buildingIndex = BuildingQueryIndex::build(
             buildings, metadata, config.heightScaleMultiplier,
             usingSat2Lod2 ? "sat2lod2" : "native");

         std::optional<ReconstructionDiagnosticPayload> diagnostics;
         if (captureDiagnostics)
         {
             diagnostics.emplace();
             diagnostics->buildingProbability = std::move(semantics.buildingProbability);
             diagnostics->roadProbability = std::move(semantics.roadProbability);
             diagnostics->vegetationProbability = std::move(semantics.vegetationProbability);
             diagnostics->semanticConfidence = std::move(semantics.semanticConfidence);
             diagnostics->finalClasses.width = scene.width;
             diagnostics->finalClasses.height = scene.height;
             diagnostics->finalClasses.data.reserve(semantics.finalClassMap.data.size());
             for (const auto cls : semantics.finalClassMap.data)
                 diagnostics->finalClasses.data.push_back(static_cast<uint8_t>(cls));
             diagnostics->rawNdsm = std::move(inference.ndsm.globalMetricNdsm);
             diagnostics->reconstructionNdsm =
                 std::move(correction.correctedMetricNdsm);
             diagnostics->stages = std::move(stages);
             diagnostics->buildings = std::move(buildings);
             diagnostics->presentationMode = toString(presentation);
             diagnostics->presentationPolicy = toString(presentationPolicy.policy);
             diagnostics->presentationReason = sceneDecision.reason;
             diagnostics->strongBuildingFraction = sceneDecision.strongBuildingFraction;
             diagnostics->vegetationFraction = sceneDecision.vegetationFraction;
             diagnostics->supportedGroundReliefMetres = sceneDecision.groundReliefMetres;
             diagnostics->emittedBuildings = glb.buildingCount;
             diagnostics->meshWarnings = glb.geometryWarnings;
         }

         // 9. Give the raster matrices to the background worker. Its queue
         //    owns them after this move; no request-local references survive.
         if (!BackgroundTiffExportService::instance().enqueue(
                jobId, std::move(surface), std::move(diagnostics),
                std::move(buildingIndex)))
         {
             throw std::runtime_error(
                "PipelineService: background GeoTIFF export queue is full or stopped");
         }

        //  for (const std::string& warning : quality.warnings)
        //     LOG_WARN << "PipelineService: " << jobId << ": " << warning;
        // for (const std::string& warning : reference.warnings)
        //     LOG_WARN << "PipelineService: " << jobId << ": " << warning;
        // for (const std::string& warning : glb.geometryWarnings)
        //     LOG_WARN << "PipelineService: " << jobId << ": " << warning;
         if (!correction.warning.empty())
             LOG_WARN << "PipelineService: " << jobId << ": " << correction.warning;
 
         LOG_INFO << "PipelineService: GLB ready for " << jobId
                  << "; raster exports queued; buildings="
                  << glb.buildingCount;
 
         // The initial response has only the two fields needed for rendering.
         // The frontend can query raster progress later using this UUID.
         Json::Value response(Json::objectValue);
         response["uuid"] = jobId;
         response["glb_url"] = std::move(glbUrl);
         co_return response;
     }
     catch (const std::exception& error)
     {
         LOG_ERROR << "PipelineService: job " << jobId
                   << " failed: " << error.what();
         throw;
     }
}

drogon::Task<std::string> PipelineService::executeCalibrationNormalImage(
    const drogon::HttpFile& imageFile)
{
    (void)imageFile;
    // Metric nDSM does not reconstruct natural terrain in a non-georeferenced
    // image. Keep this route explicit until its relative-surface path exists.
    throw std::runtime_error(
        "Non-georeferenced reconstruction is unavailable until the relative-surface pipeline is integrated");
    co_return std::string{};
}
