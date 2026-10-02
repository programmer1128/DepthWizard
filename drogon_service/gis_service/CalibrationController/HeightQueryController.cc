#include "HeightQueryController.h"
#include "../HeightService/HeightOrchestratorService.h"
#include "../HeightService/HeightRasterStore.h"
#include "../HeightService/ReferenceDemService.h"

#include <trantor/utils/Logger.h>

#include <optional>
#include <stdexcept>
#include <string>

namespace
{
// Errors carry a JSON "message", which the frontend shows on the card.
drogon::HttpResponsePtr errorResponse(drogon::HttpStatusCode code, const std::string& message)
{
     Json::Value body(Json::objectValue);
     body["status"] = "error";
     body["message"] = message;
     auto response = drogon::HttpResponse::newHttpJsonResponse(body);
     response->setStatusCode(code);
     return response;
}

// One place maps service failures to HTTP: unavailable data is not a crash.
template <typename Handler>
drogon::Task<drogon::HttpResponsePtr> respond(Handler handler)
{
     try
     {
         co_return drogon::HttpResponse::newHttpJsonResponse(co_await handler());
     }
     catch (const std::invalid_argument& error)
     {
         co_return errorResponse(drogon::k400BadRequest, error.what());
     }
     catch (const HeightDataUnavailable& error)
     {
         co_return errorResponse(error.stillExporting ? drogon::k409Conflict : drogon::k404NotFound,
                                 error.what());
     }
     catch (const ReferenceDemUnavailable& error)
     {
         co_return errorResponse(drogon::k502BadGateway, error.what());
     }
     catch (const std::exception& error)
     {
         LOG_ERROR << "HeightQueryController: " << error.what();
         co_return errorResponse(drogon::k500InternalServerError, error.what());
     }
}

double requireNumber(const Json::Value& body, const char* field)
{
     if (!body[field].isNumeric())
         throw std::invalid_argument(std::string("'") + field + "' must be a number.");
     return body[field].asDouble();
}

std::string requireUuid(const std::string& uuid)
{
     if (uuid.empty())
         throw std::invalid_argument("'uuid' is required.");
     return uuid;
}
} // namespace

drogon::Task<drogon::HttpResponsePtr> HeightQueryController::getSingleHeight(drogon::HttpRequestPtr req)
{
     co_return co_await respond([req]() -> drogon::Task<Json::Value>
     {
         const auto body = req->getJsonObject();
         if (!body)
             throw std::invalid_argument("Expected a JSON body {uuid, x, y[, feature_id]}.");
         std::optional<uint32_t> featureId;
         if ((*body)["feature_id"].isNumeric() && (*body)["feature_id"].asDouble() >= 1.0)
             featureId = (*body)["feature_id"].asUInt();
         co_return co_await HeightOrchestratorService::processSingleHeight(
             requireUuid((*body)["uuid"].asString()),
             requireNumber(*body, "x"), requireNumber(*body, "y"), featureId);
     });
}

drogon::Task<drogon::HttpResponsePtr> HeightQueryController::compareHeights(drogon::HttpRequestPtr req)
{
     co_return co_await respond([req]() -> drogon::Task<Json::Value>
     {
         // Multipart carries a user-supplied reference GeoTIFF (tag "upload").
         if (req->contentType() == drogon::CT_MULTIPART_FORM_DATA)
         {
             drogon::MultiPartParser parser;
             if (parser.parse(req) != 0)
                 throw std::invalid_argument("Failed to parse multipart/form-data.");
             auto parameters = parser.getParameters();
             double x = 0.0, y = 0.0;
             try
             {
                 x = std::stod(parameters["x"]);
                 y = std::stod(parameters["y"]);
             }
             catch (const std::logic_error&)
             {
                 throw std::invalid_argument("'x' and 'y' must be numbers.");
             }
             const auto& files = parser.getFiles();
             co_return co_await HeightOrchestratorService::processComparison(
                 requireUuid(parameters["uuid"]),
                 parameters["tag"].empty() ? "upload" : parameters["tag"], x, y,
                 files.empty() ? nullptr : &files.front());
         }

         const auto body = req->getJsonObject();
         if (!body)
             throw std::invalid_argument("Expected a JSON body {uuid, tag, x, y}.");
         const std::string tag = (*body)["tag"].isString() ? (*body)["tag"].asString()
                                                           : "opentopography";
         co_return co_await HeightOrchestratorService::processComparison(
             requireUuid((*body)["uuid"].asString()), tag,
             requireNumber(*body, "x"), requireNumber(*body, "y"), nullptr);
     });
}
