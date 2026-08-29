#include "calibrationController.h"

Task<HttpResponsePtr> CalibrationController::ping(HttpRequestPtr req) 
{
     // Create a JSON object
     Json::Value ret;
     ret["status"] = "success";
     ret["message"] = "Drogon GIS Engine is online and running on C++20 Coroutines!";
    
     // Wrap it in an HTTP response
     auto resp = HttpResponse::newHttpJsonResponse(ret);
     resp->setStatusCode(k200OK);
    
     // Return directly using the C++20 co_return keyword
     co_return resp;
}