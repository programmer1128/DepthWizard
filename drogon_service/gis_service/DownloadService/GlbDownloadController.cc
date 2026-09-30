#include "GlbDownloadController.h"

#include "GlbDownloadService.h"

#include <algorithm>
#include <cctype>
#include <cstdint>
#include <string>
#include <vector>

namespace
{
bool isValidGlbFilename(const std::string& filename)
{
    if (filename.size() <= 4 || filename.compare(filename.size() - 4, 4, ".glb") != 0)
    {
        return false;
    }

    return std::all_of(filename.begin(), filename.end(), [](unsigned char character) {
        return std::isalnum(character) || character == '-' || character == '_' || character == '.';
    });
}
}

drogon::Task<drogon::HttpResponsePtr> GlbDownloadController::downloadGlb(
    drogon::HttpRequestPtr,
    std::string filename)
{
    if (!isValidGlbFilename(filename))
    {
        auto response = drogon::HttpResponse::newHttpResponse();
        response->setStatusCode(drogon::k400BadRequest);
        response->setBody("A valid GLB filename is required.");
        co_return response;
    }

    std::vector<uint8_t> contents;
    if (!GlbDownloadService::download(filename, contents))
    {
        auto response = drogon::HttpResponse::newHttpResponse();
        response->setStatusCode(drogon::k404NotFound);
        response->setBody("GLB file not found.");
        co_return response;
    }

    auto response = drogon::HttpResponse::newHttpResponse();
    response->setStatusCode(drogon::k200OK);
    response->setContentTypeString("model/gltf-binary");
    response->addHeader("Content-Disposition", "attachment; filename=\"" + filename + "\"");
    response->setBody(std::string(contents.begin(), contents.end()));
    co_return response;
}