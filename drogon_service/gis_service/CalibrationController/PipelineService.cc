#include "PipelineService.h"

#include "../BuildingReconstruction/BuildingReconstructionService.h"
#include "../DataHandlers/MiniIOClient.h"
#include "../FileGenerators/BackgroundTiffExportService.h"
#include "../ImagePreprocessing/ImagePreprocessingService.h"
#include "../ImagePreprocessing/RasterIngestService.h"
#include "../ImageTilingService/TilingService.h"
#include "../MeshMapping/SceneMeshService.h"
#include "../MeshMapping/ScenePresentationSelector.h"
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

     try
     {
         // 1. Ingest the GeoTIFF. The scene holds the optical GLB texture,
         //    a temporary GDAL path, and the authoritative georeferencing.
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

         // 7. Turn building pixels into individual footprints and heights,
         //    then assemble terrain, roofs, and walls into one Draco GLB.
         const char* diagnosticsSetting = std::getenv("DEPTHWIZARD_DIAGNOSTICS");
         const bool captureDiagnostics = !diagnosticsSetting || std::string(diagnosticsSetting) != "0";
         BuildingReconstructionDiagnostics stages;
         BuildingCollection buildings = BuildingReconstructionService::reconstruct(
             semantics, surface, metadata, BuildingReconstructionConfig{},
             captureDiagnostics ? &stages : nullptr);

         LOG_INFO << "PipelineService: reconstruction summary for " << jobId
                  << "; semantic_candidates=" << buildings.semanticCandidateCount
                  << "; recovered_candidate_pixels="
                  << buildings.recoveredCandidatePixelCount
                  << "; component_rejected=" << buildings.componentRejectedCount
                  << "; vectorization_rejected="
                  << buildings.vectorizationRejectedCount
                  << "; physics_rejected=" << buildings.physicsRejectedCount
                  << "; accepted_buildings=" << buildings.buildings.size();
         
         MeshBuildConfig meshConfig;
         const ScenePresentationDecision sceneDecision = ScenePresentationSelector::select(
             semantics, surface, buildings);
         const auto presentation = sceneDecision.presentation;
         meshConfig.presentation = presentation;
         LOG_INFO << "PipelineService: automatic scene policy for " << jobId
                  << "; " << sceneDecision.reason
                  << "; strong_building_fraction=" << sceneDecision.strongBuildingFraction
                  << "; vegetation_fraction=" << sceneDecision.vegetationFraction
                  << "; supported_ground_relief_m=" << sceneDecision.groundReliefMetres;
         GlbBuildResult glb = SceneMeshService::generateGlb(
            scene, surface, buildings, metadata, meshConfig);

         LOG_INFO << "PipelineService: mesh summary for " << jobId
                  << "; presentation=" << (presentation == ScenePresentation::FLAT_URBAN ? "flat_urban" : "metric")
                  << "; emitted_buildings=" << glb.buildingCount
                  << "; terrain_triangles=" << glb.terrainTriangleCount
                  << "; roof_triangles=" << glb.roofTriangleCount
                  << "; wall_triangles=" << glb.wallTriangleCount
                  << "; glb_bytes=" << glb.compressedGlbByteBuffer.size();

         for (const std::string& warning : glb.geometryWarnings)
         {
             LOG_WARN << "PipelineService: " << jobId << ": " << warning;
         }

         // 8. Upload the finished GLB before replying to the frontend.
         std::string glbUrl = uploadGlb(jobId, glb);

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
             diagnostics->stages = std::move(stages);
             diagnostics->buildings = std::move(buildings);
             diagnostics->presentationMode = presentation == ScenePresentation::FLAT_URBAN ? "flat_urban" : "metric";
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
                jobId, std::move(surface), std::move(diagnostics)))
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
