#pragma once

#include <drogon/HttpController.h>
#include <string>

class GlbDownloadController : public drogon::HttpController<GlbDownloadController>
{
public:
    METHOD_LIST_BEGIN
    ADD_METHOD_TO(GlbDownloadController::downloadGlb, "/api/v1/download/{1}", drogon::Get);
    METHOD_LIST_END

    drogon::Task<drogon::HttpResponsePtr> downloadGlb(
        drogon::HttpRequestPtr request,
        std::string filename);
};