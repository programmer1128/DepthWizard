#pragma once

#include <drogon/drogon.h>
using namespace drogon;

class HeightQueryController : public drogon::HttpController<HeightQueryController>
{
   public:
   public:
    METHOD_LIST_BEGIN
   
    ADD_METHOD_TO(HeightQueryController::calculateHeight, "/api/v1/height", drogon::Post);

    METHOD_LIST_END

    drogon::Task<drogon::HttpResponsePtr>calculateHeight(drogon::HttpRequestPtr req);
};
