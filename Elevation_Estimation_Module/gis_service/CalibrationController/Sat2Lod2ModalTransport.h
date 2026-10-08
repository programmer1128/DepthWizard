#pragma once

#include <drogon/HttpClient.h>
#include <drogon/HttpRequest.h>
#include <drogon/HttpResponse.h>
#include <json/value.h>

#include <optional>
#include <string>

// Where the backend reaches SAT2LoD2, from DEPTHWIZARD_SAT2LOD2 (0 disables),
// DEPTHWIZARD_SAT2LOD2_URL and DEPTHWIZARD_SAT2LOD2_TRANSPORT (local|modal).
struct Sat2Lod2Endpoint
{
    bool enabled{true};
    std::string url;
    bool local{false};
};

// The Modal ASGI route transfers files and returns the parametric building
// document inline. The local uvicorn route uses shared filesystem paths.
class Sat2Lod2ModalTransport
{
public:
    static Sat2Lod2Endpoint endpointFromEnvironment();

    static drogon::HttpRequestPtr makeRequest(
        const std::string& ndsmPath,
        const std::string& orthoTiffPath,
        const std::string& labelPath);

    // Starts a Modal container while the backend is still preprocessing:
    // a fire-and-forget GET /api/v1/health whose result is ignored.
    static void wakeUp(const std::string& baseUrl);

    // Sends the request and follows Modal's result redirects. Every Modal web
    // request is cut at 150 s (including time queued for a container) and
    // answered with a 303 to a result URL; each GET of that URL waits up to
    // another 150 s. Gives up at timeoutSeconds in total.
    // loop: where the HTTP clients run; the default is drogon's app loop.
    static drogon::Task<drogon::HttpResponsePtr> send(
        const std::string& baseUrl,
        drogon::HttpRequestPtr request,
        double timeoutSeconds,
        trantor::EventLoop* loop = nullptr);

    // Origin ("https://host[:port]") and path+query of a redirect response,
    // or nothing when the response is not a redirect.
    struct Redirect
    {
        std::string origin; // empty: same origin as the request
        std::string pathAndQuery;
    };
    static std::optional<Redirect> redirectOf(const drogon::HttpResponsePtr& response);

    static Json::Value readBuildings(const drogon::HttpResponsePtr& response);
};
