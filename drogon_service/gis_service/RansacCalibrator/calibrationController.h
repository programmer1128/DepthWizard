#pragma once
#include <drogon/HttpController.h>
#include <drogon/drogon.h>
#include <drogon/utils/coroutine.h>

using namespace drogon;

class CalibrationController : public drogon::HttpController<CalibrationController> 
{
public:
    METHOD_LIST_BEGIN
    
    ADD_METHOD_TO(CalibrationController::ping, "/api/v1/ping", Get);
    
    METHOD_LIST_END

    Task<HttpResponsePtr> ping(HttpRequestPtr req);
};