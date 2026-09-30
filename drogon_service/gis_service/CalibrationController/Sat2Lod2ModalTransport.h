#pragma once

#include <drogon/HttpRequest.h>
#include <drogon/HttpResponse.h>
#include <json/value.h>
#include <string>

// The Modal ASGI route transfers files and returns the parametric building
// document inline. The local uvicorn route uses shared filesystem paths.
class Sat2Lod2ModalTransport
{
public:
    static drogon::HttpRequestPtr makeRequest(
        const std::string& ndsmPath,
        const std::string& orthoTiffPath,
        const std::string& labelPath);

    static Json::Value readBuildings(const drogon::HttpResponsePtr& response);
};
