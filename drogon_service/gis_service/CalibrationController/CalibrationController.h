#pragma once

#include <drogon/HttpController.h>
#include <drogon/drogon.h>
#include <coroutine>
#include "../structures/ExportStructs.h"
using namespace drogon;

class CalibrationController : public drogon::HttpController<CalibrationController>
{
  public:
    METHOD_LIST_BEGIN
    // use METHOD_ADD to add your custom processing function here;
    // METHOD_ADD(CalibrationController::get, "/{2}/{1}", Get); // path is /CalibrationController/{arg2}/{arg1}
    // METHOD_ADD(CalibrationController::your_method_name, "/{1}/{2}/list", Get); // path is /CalibrationController/{arg1}/{arg2}/list
    // ADD_METHOD_TO(CalibrationController::your_method_name, "/absolute/path/{1}/{2}/list", Get); // path is /absolute/path/{arg1}/{arg2}/list

    ADD_METHOD_TO(CalibrationController::processTerrain, "/api/v1/processor", drogon::Post);

    ADD_METHOD_TO(CalibrationController::processNormalImageForTerrain, "/api/v1/processor/normal-image", drogon::Post);

    METHOD_LIST_END
    // your declaration of processing function maybe like this:
    // void get(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback, int p1, std::string p2);
    // void your_method_name(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback, double p1, int p2) const;

    drogon::Task<drogon::HttpResponsePtr>processTerrain(drogon::HttpRequestPtr req);

    drogon::Task<drogon::HttpResponsePtr>processNormalImageForTerrain(drogon::HttpRequestPtr req);

    // serializes the C++ PipelineResult struct into strictly formatted JSON
    static drogon::HttpResponsePtr toHttpResponse(const PipelineResult& result);
};
