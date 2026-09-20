// Scaffolding for the asynchronous background publishing layer 
// decouples the instantaneous 3D GLB upload from the heavy GeoTIFF uploads

#pragma once

#include <string>
#include <vector>
#include <drogon/drogon.h>
#include "../structures/ExportStructs.h"
#include "../FileGenerators/TiffExporter.h"

class ArtifactPublisher 
{
public:
    
    // intended to upload the GLB synchronously to return the URL instantly, 
    // while pushing the TIFF list to a background worker queue

    static drogon::Task<ArtifactManifest> publish(
        const std::string& jobId, 
        const GlbBuildResult& glb, 
        const std::vector<RasterArtifactBuffer>& rasters);
};