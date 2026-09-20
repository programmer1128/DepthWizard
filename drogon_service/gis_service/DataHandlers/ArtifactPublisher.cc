// scaffold implementation for the background pipeline dispatch

#include "ArtifactPublisher.h"

drogon::Task<ArtifactManifest> ArtifactPublisher::publish(
    const std::string& jobId, 
    const GlbBuildResult& glb, 
    const std::vector<RasterArtifactBuffer>& rasters)
{
    ArtifactManifest manifest;

    // TODO: Implement MinioClient::uploadBuffer for GLB synchronously here
    // TODO: Obtain presigned URL from MinioClient::generatePresignedUrl
    
    // scaffold implementation for the frontend response mapping
    manifest.glb.status = JobStatus::READY;
    manifest.glb.url = "http://minio-scaffold-url/terrain-assets/mesh_" + jobId + ".glb";

    // set all TIFF jobs to processing state
    manifest.dsm.status = JobStatus::PROCESSING;
    manifest.dtm.status = JobStatus::PROCESSING;
    manifest.ndsm.status = JobStatus::PROCESSING;
    manifest.slope.status = JobStatus::PROCESSING;
    manifest.aspect.status = JobStatus::PROCESSING;
    manifest.hillshade.status = JobStatus::PROCESSING;
    manifest.confidence.status = JobStatus::PROCESSING;
    
    bool hasCanopy = false;
    for (const auto& raster : rasters) 
    {
        if (raster.productType == "canopy") 
        {
            hasCanopy = true;
            break; 
        }
    }
    
    if (hasCanopy) 
    {
        ArtifactStatus canopyStatus;
        canopyStatus.status = JobStatus::PROCESSING;
        manifest.canopyHeight = canopyStatus;
    }

    // TODO: dispatch rasters vector to the BackgroundJobExecutor queue here

    co_return manifest;
}