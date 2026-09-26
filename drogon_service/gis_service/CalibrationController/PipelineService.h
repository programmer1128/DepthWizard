#pragma once
#include <drogon/MultiPart.h>
#include <drogon/drogon.h>
#include "../MeshMapping/MeshBuildConfig.h"

class PipelineService
{
public:
    // GeoTIFF route: return the uploaded GLB URL and UUID; queue raster exports.
    drogon::Task<Json::Value> executeCalibration(
        const drogon::HttpFile& imageFile);

    // Separate non-georeferenced route; relative-surface support is pending.
    drogon::Task<std::string> executeCalibrationNormalImage(
        const drogon::HttpFile& imageFile);
};
