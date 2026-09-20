#include "CalibrationController.h"

#include "PipelineService.h"
#include "../DataHandlers/MiniIOClient.h"
#include "../FileGenerators/BackgroundTiffExportService.h"

#include <string>
#include <utility>

static const char* exportStateName(JobStatus state)
{
    switch (state)
    {
    case JobStatus::QUEUED: return "queued";
    case JobStatus::PROCESSING: return "processing";
    case JobStatus::READY: return "ready";
    case JobStatus::FAILED: return "failed";
    }
    return "unknown";
}

drogon::Task<drogon::HttpResponsePtr> CalibrationController::processTerrain(
    drogon::HttpRequestPtr request)
{
    drogon::MultiPartParser upload;
    if (upload.parse(request) != 0)
    {
        Json::Value error;
        error["message"] = "Failed to parse multipart request.";
        auto response = drogon::HttpResponse::newHttpJsonResponse(error);
        response->setStatusCode(drogon::k400BadRequest);
        co_return response;
    }

    const auto files = upload.getFilesMap();
    auto image = files.find("image");
    if (image == files.end())
    {
        Json::Value error;
        error["message"] = "Missing image file.";
        auto response = drogon::HttpResponse::newHttpJsonResponse(error);
        response->setStatusCode(drogon::k400BadRequest);
        co_return response;
    }

    try
    {
        // The pipeline completes GLB generation and queues GeoTIFF exports.
        // Return its small rendering response without waiting for TIFF uploads.
        Json::Value result = co_await PipelineService().executeCalibration(
            image->second);
        co_return drogon::HttpResponse::newHttpJsonResponse(result);
    }
    catch (const std::exception& error)
    {
        Json::Value body;
        body["message"] = error.what();
        auto response = drogon::HttpResponse::newHttpJsonResponse(body);
        response->setStatusCode(drogon::k500InternalServerError);
        co_return response;
    }
}

drogon::Task<drogon::HttpResponsePtr>
CalibrationController::processNormalImageForTerrain(
    drogon::HttpRequestPtr request)
{
    drogon::MultiPartParser upload;
    if (upload.parse(request) != 0)
    {
        Json::Value error;
        error["message"] = "Failed to parse multipart request.";
        auto response = drogon::HttpResponse::newHttpJsonResponse(error);
        response->setStatusCode(drogon::k400BadRequest);
        co_return response;
    }

    const auto files = upload.getFilesMap();
    auto image = files.find("image");
    if (image == files.end())
    {
        Json::Value error;
        error["message"] = "Missing image file.";
        auto response = drogon::HttpResponse::newHttpJsonResponse(error);
        response->setStatusCode(drogon::k400BadRequest);
        co_return response;
    }

    try
    {
        std::string savedFile = co_await PipelineService()
            .executeCalibrationNormalImage(image->second);

        Json::Value result;
        result["saved_file"] = std::move(savedFile);
        co_return drogon::HttpResponse::newHttpJsonResponse(result);
    }
    catch (const std::exception& error)
    {
        Json::Value body;
        body["message"] = error.what();
        auto response = drogon::HttpResponse::newHttpJsonResponse(body);
        response->setStatusCode(drogon::k500InternalServerError);
        co_return response;
    }
}

drogon::Task<drogon::HttpResponsePtr> CalibrationController::getExportStatus(
    drogon::HttpRequestPtr request, std::string uuid)
{
    (void)request;

    // The initial upload response contains the UUID. Poll this endpoint
    // before requesting the DSM through a height-query API.
    auto status = BackgroundTiffExportService::instance().getStatus(uuid);
    if (!status)
    {
        Json::Value error;
        error["message"] = "No raster-export job found for this UUID.";
        auto response = drogon::HttpResponse::newHttpJsonResponse(error);
        response->setStatusCode(drogon::k404NotFound);
        co_return response;
    }

    Json::Value result(Json::objectValue);
    result["uuid"] = uuid;
    result["status"] = exportStateName(status->overall());
    result["dsm"] = exportStateName(status->dsm);
    result["dtm"] = exportStateName(status->dtm);
    result["ndsm"] = exportStateName(status->ndsm);
    result["confidence"] = exportStateName(status->confidence);

    if (status->dsm == JobStatus::READY)
        result["dsm_url"] = MinioClient::generatePresignedUrl(
            "terrain-assets", "heights_" + uuid + ".tif");
    if (status->dtm == JobStatus::READY)
        result["dtm_url"] = MinioClient::generatePresignedUrl(
            "terrain-assets", "dtm_" + uuid + ".tif");
    if (status->ndsm == JobStatus::READY)
        result["ndsm_url"] = MinioClient::generatePresignedUrl(
            "terrain-assets", "ndsm_" + uuid + ".tif");
    if (status->confidence == JobStatus::READY)
        result["confidence_url"] = MinioClient::generatePresignedUrl(
            "terrain-assets", "confidence_" + uuid + ".tif");

    Json::Value errors(Json::arrayValue);
    for (const std::string& error : status->errors)
        errors.append(error);
    if (!errors.empty())
        result["errors"] = std::move(errors);

    co_return drogon::HttpResponse::newHttpJsonResponse(result);
}
