#pragma once
#include <drogon/HttpController.h>

class HeightQueryController : public drogon::HttpController<HeightQueryController> {
public:
    METHOD_LIST_BEGIN
        ADD_METHOD_TO(HeightQueryController::getSingleHeight, "/api/height/single", drogon::Post);
        ADD_METHOD_TO(HeightQueryController::compareHeights, "/api/height/compare", drogon::Post);
    METHOD_LIST_END

    drogon::Task<drogon::HttpResponsePtr> getSingleHeight(drogon::HttpRequestPtr req);
    drogon::Task<drogon::HttpResponsePtr> compareHeights(drogon::HttpRequestPtr req);
};