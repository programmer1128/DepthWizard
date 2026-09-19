#pragma once
#include <string>
#include <drogon/drogon.h>
#include "../structures/IngestionStructs.h"

class RasterIngestService
{
public:
    // validates geospatial metadata, computes GSD, extracts the unadulterated optical RGB pixels into a JPEG buffer to ensure the final 3D GLB mesh retains its true colors, and uploads the GeoTIFF to MinIO
    // Input : jobId -> unique identifier for the pipeline execution job, imageFile -> uploaded HTTP multipart GeoTIFF file.
    // Output : SceneInput -> validated geospatial payload containing the remote /vsicurl/ path
    static SceneInput ingestGeoTiff(
        const std::string &jobId,
        const drogon::HttpFile &imageFile);
};