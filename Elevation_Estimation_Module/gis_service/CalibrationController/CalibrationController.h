#pragma once

#include <drogon/HttpController.h>
#include <drogon/drogon.h>
#include <string>

class CalibrationController : public drogon::HttpController<CalibrationController>
{
public:
    METHOD_LIST_BEGIN
    ADD_METHOD_TO(CalibrationController::processTerrain, "/api/v1/processor", drogon::Post);
    ADD_METHOD_TO(CalibrationController::processNormalImageForTerrain, "/api/v1/processor/normal-image", drogon::Post);
    ADD_METHOD_TO(CalibrationController::getExportStatus, "/api/v1/processor/exports/{1}", drogon::Get);
    METHOD_LIST_END

    drogon::Task<drogon::HttpResponsePtr> processTerrain(
        drogon::HttpRequestPtr request);
    drogon::Task<drogon::HttpResponsePtr> processNormalImageForTerrain(
        drogon::HttpRequestPtr request);
    drogon::Task<drogon::HttpResponsePtr> getExportStatus(
        drogon::HttpRequestPtr request, std::string uuid);
};
