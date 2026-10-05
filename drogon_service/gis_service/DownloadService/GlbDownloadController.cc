#include "GlbDownloadController.h"

#include "GlbDownloadService.h"

#include <algorithm>
#include <cctype>
#include <cstdint>
#include <string>
#include <vector>

namespace
{
bool endsWith(const std::string& text, const std::string& suffix)
{
    return text.size() > suffix.size() && text.compare(text.size() - suffix.size(), suffix.size(), suffix) == 0;
}

// Job products only: the GLB and the queued raster exports.
bool isValidGlbFilename(const std::string& filename)
{
    if (!endsWith(filename, ".glb") && !endsWith(filename, ".tif") && !endsWith(filename, ".json"))
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
    response->setContentTypeString(endsWith(filename, ".tif")    ? "image/tiff"
                                   : endsWith(filename, ".json") ? "application/json"
                                                                 : "model/gltf-binary");
    response->addHeader("Content-Disposition", "attachment; filename=\"" + filename + "\"");
    response->setBody(std::string(contents.begin(), contents.end()));
    co_return response;
}