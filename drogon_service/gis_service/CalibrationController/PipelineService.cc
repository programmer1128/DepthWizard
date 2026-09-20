#include "PipelineService.h"

#include "../BuildingReconstruction/BuildingReconstructionService.h"
#include "../DataHandlers/MiniIOClient.h"
#include "../FileGenerators/BackgroundTiffExportService.h"
#include "../ImagePreprocessing/ImagePreprocessingService.h"
#include "../ImagePreprocessing/RasterIngestService.h"
#include "../ImageTilingService/TilingService.h"
#include "../MeshMapping/SceneMeshService.h"
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

// The tiling service must return full-resolution metric nDSM, confidence,
// validity, and six semantic-logit planes on exactly the same pixel grid.
static void validateInference(const InferenceBundle& inference,
                              int width,
                              int height)
{
     requireGridShape(inference.globalNdsm, width, height, "nDSM");
     requireGridShape(inference.globalNdsmConfidence, width, height,
                     "AI confidence");
     requireGridShape(inference.globalValidMask, width, height, "AI valid mask");

     const SemanticLogits& logits = inference.globalSemanticLogits;
     
     if (logits.classCount != 6 || logits.layout != TensorLayout::CHW)
     {
         throw std::runtime_error("PipelineService: incompatible semantic contract");
     }

     requireGridShape(logits.unknownLogits, width, height, "unknown logits");
     requireGridShape(logits.groundLogits, width, height, "ground logits");
     requireGridShape(logits.buildingLogits, width, height, "building logits");
     requireGridShape(logits.roadLogits, width, height, "road logits");
     requireGridShape(logits.vegetationLogits, width, height, "vegetation logits");
     requireGridShape(logits.waterLogits, width, height, "water logits");
}

// Invalid optical pixels must remain invalid even if a model tile predicts
// values there. The semantic and surface services consume this final mask.
static void applyPreprocessingMask(InferenceBundle& inference,
                                   const ImageQualityResult& quality)
{
     const size_t pixels = inference.globalNdsm.data.size();
 
     for (size_t i = 0; i < pixels; ++i)
     {
         if (inference.globalValidMask.data[i] == 0 ||
             quality.validPixelMask.data[i] == 0)
         {
             inference.globalValidMask.data[i] = 0;
             inference.globalNdsm.data[i] =
                 std::numeric_limits<float>::quiet_NaN();
             inference.globalNdsmConfidence.data[i] = 0.0f;
             continue;
         }

         const float height = inference.globalNdsm.data[i];
         const float confidence = inference.globalNdsmConfidence.data[i];
         
         if (!std::isfinite(height) || !std::isfinite(confidence) ||
            confidence < 0.0f || confidence > 1.0f)
         {
             throw std::runtime_error("PipelineService: invalid AI output values");
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

         // 3. Run tiled model inference and stitch metric nDSM plus semantics.
         InferenceBundle inference =
             co_await TilingService::generateStitchedMetricInference(scene, quality);
         validateInference(inference, scene.width, scene.height);
         applyPreprocessingMask(inference, quality);

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
             inference.globalSemanticLogits,
             inference.globalNdsmConfidence,
             inference.globalValidMask);
        
         GroundMask ground = GroundSurfaceService::buildGroundMask(
            semantics, quality, reference);
     
        NdsmCorrectionResult correction = NdsmGroundBiasCorrector::correct(
            inference.globalNdsm, ground, inference.globalNdsmConfidence);

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
         BuildingCollection buildings = BuildingReconstructionService::reconstruct(
             semantics, surface, metadata);
         
         GlbBuildResult glb = SceneMeshService::generateGlb(
            scene, surface, buildings, metadata);

         // 8. Upload the finished GLB before replying to the frontend.
         std::string glbUrl = uploadGlb(jobId, glb);

         // 9. Give the raster matrices to the background worker. Its queue
         //    owns them after this move; no request-local references survive.
         if (!BackgroundTiffExportService::instance().enqueue(
                jobId, std::move(surface)))
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
                  << buildings.buildings.size();
 
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
