#include "Sat2Lod2ModalTransport.h"

#include <drogon/utils/Utilities.h>
#include <trantor/utils/Logger.h>

#include <chrono>
#include <cstdint>
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <limits>
#include <map>
#include <mutex>
#include <stdexcept>

namespace
{
constexpr const char* kDefaultModalUrl =
    "https://programmer1128--sat2lod2-reconstruction-sat2lod2engine-app.modal.run";
// Long enough to cover Modal queueing for a container; the answer is unused.
constexpr double kWakeUpTimeoutSeconds = 150.0;
// Modal allows about 20 result redirects (20 x 150 s) before giving up.
constexpr int kMaxRedirects = 20;

std::string environment(const char* name)
{
    const char* value = std::getenv(name);
    return value ? value : "";
}
} // namespace

Sat2Lod2Endpoint Sat2Lod2ModalTransport::endpointFromEnvironment()
{
    Sat2Lod2Endpoint endpoint;
    endpoint.enabled = environment("DEPTHWIZARD_SAT2LOD2") != "0";
    endpoint.url = environment("DEPTHWIZARD_SAT2LOD2_URL");
    if (endpoint.url.empty()) endpoint.url = kDefaultModalUrl;
    while (endpoint.url.ends_with('/')) endpoint.url.pop_back();

    const std::string transport = environment("DEPTHWIZARD_SAT2LOD2_TRANSPORT");
    if (!transport.empty() && transport != "local" && transport != "modal")
        throw std::runtime_error("DEPTHWIZARD_SAT2LOD2_TRANSPORT must be local or modal");
    endpoint.local = !transport.empty()
        ? transport == "local"
        : endpoint.url.starts_with("http://127.0.0.1:") ||
              endpoint.url.starts_with("http://localhost:");
    return endpoint;
}

drogon::HttpRequestPtr Sat2Lod2ModalTransport::makeRequest(
    const std::string& ndsmPath,
    const std::string& orthoTiffPath,
    const std::string& labelPath)
{
    const std::string boundary = "DepthWizardSat2Lod2" + drogon::utils::getUuid();
    std::string body;
    const auto addFile = [&](const std::string& path, const char* itemName,
                             const char* fileName)
    {
        std::ifstream file(path, std::ios::binary);
        if (!file)
            throw std::runtime_error("Cannot open SAT2LoD2 upload: " + path);
        const auto fileSize = std::filesystem::file_size(path);
        if (fileSize > static_cast<std::uintmax_t>(
                           std::numeric_limits<std::streamsize>::max()))
            throw std::runtime_error("SAT2LoD2 upload is too large: " + path);
        body += "--" + boundary + "\r\n";
        body += "Content-Disposition: form-data; name=\"";
        body += itemName;
        body += "\"; filename=\"";
        body += fileName;
        body += "\"\r\nContent-Type: image/tiff\r\n\r\n";
        const auto offset = body.size();
        body.resize(offset + static_cast<std::size_t>(fileSize));
        file.read(body.data() + offset, static_cast<std::streamsize>(fileSize));
        if (!file)
            throw std::runtime_error("Cannot read SAT2LoD2 upload: " + path);
        body += "\r\n";
    };
    addFile(ndsmPath, "dsm", "ndsm.tif");
    addFile(orthoTiffPath, "ortho", "ortho.tif");
    addFile(labelPath, "label", "label.tif");
    body += "--" + boundary + "--\r\n";

    auto request = drogon::HttpRequest::newHttpRequest();
    request->setMethod(drogon::Post);
    request->setPath("/api/v1/reconstruct");
    // Must replace drogon's default content type. addHeader("content-type")
    // sends a second header after "text/plain"; FastAPI reads the first,
    // finds no file parts and rejects the job with 422.
    request->setContentTypeString("multipart/form-data; boundary=" + boundary);
    request->setBody(std::move(body));
    return request;
}

void Sat2Lod2ModalTransport::wakeUp(const std::string& baseUrl)
{
    // One long-lived client per URL: a client must outlive its callbacks.
    static std::mutex mutex;
    static std::map<std::string, drogon::HttpClientPtr> clients;
    drogon::HttpClientPtr client;
    {
        std::lock_guard lock(mutex);
        auto& cached = clients[baseUrl];
        if (!cached) cached = drogon::HttpClient::newHttpClient(baseUrl);
        client = cached;
    }
    auto request = drogon::HttpRequest::newHttpRequest();
    request->setMethod(drogon::Get);
    request->setPath("/api/v1/health");
    const auto started = std::chrono::steady_clock::now();
    client->sendRequest(request,
        [started](drogon::ReqResult result, const drogon::HttpResponsePtr& response)
        {
            const double seconds = std::chrono::duration<double>(
                std::chrono::steady_clock::now() - started).count();
            if (result == drogon::ReqResult::Ok && response)
                LOG_INFO << "SAT2LoD2 wake-up answered HTTP "
                         << static_cast<int>(response->statusCode()) << " after " << seconds << " s";
            else
                LOG_WARN << "SAT2LoD2 wake-up failed after " << seconds << " s: "
                         << drogon::to_string_view(result);
        },
        kWakeUpTimeoutSeconds);
}

std::optional<Sat2Lod2ModalTransport::Redirect> Sat2Lod2ModalTransport::redirectOf(
    const drogon::HttpResponsePtr& response)
{
    if (!response) return std::nullopt;
    const int code = static_cast<int>(response->statusCode());
    // 307/308 would require resending the upload; Modal answers with 303.
    if (code != 301 && code != 302 && code != 303) return std::nullopt;
    const std::string location = response->getHeader("location");
    if (location.empty()) return std::nullopt;

    const auto scheme = location.find("://");
    if (scheme == std::string::npos)
        return Redirect{"", location.starts_with('/') ? location : "/" + location};
    const auto pathStart = location.find('/', scheme + 3);
    if (pathStart == std::string::npos)
        return Redirect{location, "/"};
    return Redirect{location.substr(0, pathStart), location.substr(pathStart)};
}

drogon::Task<drogon::HttpResponsePtr> Sat2Lod2ModalTransport::send(
    const std::string& baseUrl,
    drogon::HttpRequestPtr request,
    double timeoutSeconds,
    trantor::EventLoop* loop)
{
    const auto deadline = std::chrono::steady_clock::now() +
        std::chrono::duration<double>(timeoutSeconds);
    std::string origin = baseUrl;
    auto client = drogon::HttpClient::newHttpClient(origin, loop);

    for (int hop = 0; ; ++hop)
    {
        const double remaining = std::chrono::duration<double>(
            deadline - std::chrono::steady_clock::now()).count();
        if (remaining <= 0.0)
            throw std::runtime_error("SAT2LoD2 did not answer within " +
                                     std::to_string(static_cast<int>(timeoutSeconds)) + " s");

        auto response = co_await client->sendRequestCoro(request, remaining);
        const auto redirect = redirectOf(response);
        if (!redirect) co_return response;
        if (hop >= kMaxRedirects)
            throw std::runtime_error("SAT2LoD2 exceeded the result redirect limit");

        // A fresh client per poll: the connection that carried the redirect
        // may already be closed, and drogon would reuse it and fail.
        if (!redirect->origin.empty()) origin = redirect->origin;
        client = drogon::HttpClient::newHttpClient(origin, loop);
        LOG_INFO << "SAT2LoD2 still running after Modal's 150 s request limit; "
                    "polling its result URL (" << hop + 1 << ")";
        // A 303 is answered with a GET of the result URL, already encoded.
        request = drogon::HttpRequest::newHttpRequest();
        request->setMethod(drogon::Get);
        request->setPathEncode(false);
        request->setPath(redirect->pathAndQuery);
    }
}

Json::Value Sat2Lod2ModalTransport::readBuildings(
    const drogon::HttpResponsePtr& response)
{
    if (!response)
        throw std::runtime_error("Modal SAT2LoD2 returned no HTTP response");
    if (response->statusCode() != drogon::k200OK)
        throw std::runtime_error(
            "Modal SAT2LoD2 HTTP " +
            std::to_string(static_cast<int>(response->statusCode())) + ": " +
            std::string(response->body().substr(0, 512)));
    const auto& document = response->getJsonObject();
    if (!document || !(*document)["buildings"].isObject() ||
        !(*document)["buildings"]["segments"].isArray())
        throw std::runtime_error("Modal SAT2LoD2 returned no building document");
    return (*document)["buildings"];
}
