#include "SemanticInferenceClient.h"
#include "SemanticProtocolCodec.h"
#include "SemanticResponseValidator.h"

#include <curl/curl.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/tcp.h>
#include <unistd.h>
#include <sys/time.h>

#include <algorithm>
#include <chrono>
#include <cerrno>
#include <cstring>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <string>
#include <vector>
#include <mutex>  

namespace
{
    // Thread-safe global CURL initialization
    std::once_flag g_curlOnceFlag;
    void ensureCurlGlobalInit()
    {
        std::call_once(g_curlOnceFlag, []() {
            curl_global_init(CURL_GLOBAL_DEFAULT);
            std::cout << ">> [CURL] Semantic Global Init OK (" << curl_version() << ")" << std::endl;
        });
    }

    // Helper to stream HTTP response into a buffer
    struct DownloadSink
    {
        std::vector<char>* buf;
        size_t hardLimit;
    };

    constexpr size_t MAX_HTTP_RESPONSE_BYTES = 32 * 1024 * 1024; // Semantic payload is larger (6 channels)

    size_t WriteCallback(char* ptr, size_t size, size_t nmemb, void* userdata)
    {
        auto* sink = static_cast<DownloadSink*>(userdata);
        if (size == 0 || nmemb == 0) return 0;
        if (size > SIZE_MAX / nmemb) return 0;
        const size_t bytes = size * nmemb;
        if (bytes == 0) return 0;
        if (sink->buf->size() + bytes > sink->hardLimit) return 0;
        sink->buf->insert(sink->buf->end(), ptr, ptr + bytes);
        return bytes;
    }

    bool isHttpEndpoint(const std::string& url)
    {
        return url.rfind("http://", 0) == 0 || url.rfind("https://", 0) == 0;
    }

    size_t validateRequest(const TileRequest& request, const SemanticInferenceConfig& config)
    {
        if (request.width <= 0 || request.height <= 0) throw std::invalid_argument("SemanticClient: Tile dimensions must be positive.");
        if (static_cast<uint32_t>(request.width) != config.expectedTileSize || static_cast<uint32_t>(request.height) != config.expectedTileSize) {
            throw std::invalid_argument("SemanticClient: Tile dimensions do not match model contract.");
        }
        if (request.validWidth <= 0 || request.validHeight <= 0 || request.validWidth > request.width || request.validHeight > request.height) {
            throw std::invalid_argument("SemanticClient: Invalid tile valid region.");
        }
        const size_t width = static_cast<size_t>(request.width);
        const size_t height = static_cast<size_t>(request.height);
        if (width > std::numeric_limits<size_t>::max() / height) throw std::overflow_error("SemanticClient: Tile pixel count overflow.");
        const size_t pixels = width * height;
        if (pixels > std::numeric_limits<size_t>::max() / 3) throw std::overflow_error("SemanticClient: RGB element count overflow.");
        
        if (request.normalizedRgbBytes.size() != pixels * 3) throw std::invalid_argument("SemanticClient: RGB tensor size mismatch.");
        if (request.validMaskBytes.size() != pixels) throw std::invalid_argument("SemanticClient: Preprocessing mask size mismatch.");
        for (uint8_t value : request.validMaskBytes) {
            if (value != 0 && value != 1) throw std::invalid_argument("SemanticClient: Preprocessing mask is not binary.");
        }
        return pixels;
    }
} // namespace

SemanticTileResult SemanticInferenceClient::inferTile(
    std::shared_ptr<TileRequest> request,
    const SemanticWorkerEndpoint& endpoint,
    const SemanticInferenceConfig& config)
{
    if (!request) throw std::invalid_argument("SemanticClient: TileRequest is null.");
    config.validate();
    const size_t pixelCount = validateRequest(*request, config);
    const uint64_t correlationId = static_cast<uint64_t>(request->tileId);

    // 1. Determine Target URL
    std::string targetUrl = endpoint.url.empty() ? endpoint.host : endpoint.url;
    if (!isHttpEndpoint(targetUrl)) {
        throw std::runtime_error("SemanticClient: Modal deployment requires an HTTP/HTTPS endpoint URL.");
    }
    ensureCurlGlobalInit();

    // 2. Build HTTP Payload (48-byte Header + Float Tensor + Mask)
    SemanticRequestHeader reqHeader = SemanticProtocolCodec::buildRequestHeader(correlationId, *request);
    
    std::vector<char> httpPayload(
        sizeof(SemanticRequestHeader) + 
        static_cast<size_t>(reqHeader.rgbPayloadLength) + 
        static_cast<size_t>(reqHeader.maskPayloadLength));

    std::memcpy(httpPayload.data(), &reqHeader, sizeof(SemanticRequestHeader));
    std::memcpy(httpPayload.data() + sizeof(SemanticRequestHeader), request->normalizedRgbBytes.data(), static_cast<size_t>(reqHeader.rgbPayloadLength));
    std::memcpy(httpPayload.data() + sizeof(SemanticRequestHeader) + static_cast<size_t>(reqHeader.rgbPayloadLength), request->validMaskBytes.data(), static_cast<size_t>(reqHeader.maskPayloadLength));

    // 3. Execute HTTP POST via libcurl
    std::vector<char> responseBuf;
    responseBuf.reserve(sizeof(SemanticResponseHeader) + (pixelCount * config.expectedClassCount * sizeof(float)) + (pixelCount * sizeof(float)) + pixelCount);
    DownloadSink sink{&responseBuf, MAX_HTTP_RESPONSE_BYTES};

    CURL* curl = curl_easy_init();
    if (!curl) throw std::runtime_error("Network Error: curl_easy_init failed.");

    struct curl_slist* headers = nullptr;
    CURLcode rc = CURLE_OK;
    long httpCode = 0;

    try
    {
        headers = curl_slist_append(headers, "Content-Type: application/octet-stream");
        headers = curl_slist_append(headers, "User-Agent: SemanticInferenceClient/1.0");
        headers = curl_slist_append(headers, "Expect:");

        curl_easy_setopt(curl, CURLOPT_URL, targetUrl.c_str());
        curl_easy_setopt(curl, CURLOPT_POST, 1L);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, httpPayload.data());
        curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE_LARGE, static_cast<curl_off_t>(httpPayload.size()));
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_HTTP_VERSION, CURL_HTTP_VERSION_2TLS); // Force HTTP/2
        
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &sink);
        
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
        curl_easy_setopt(curl, CURLOPT_NOSIGNAL, 1L); // Critical for multithreading
        curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT_MS, static_cast<long>(config.connectTimeout.count()));
        curl_easy_setopt(curl, CURLOPT_TIMEOUT_MS, static_cast<long>(config.receiveTimeout.count()));

        rc = curl_easy_perform(curl);
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &httpCode);
    }
    catch (...)
    {
        if (headers) curl_slist_free_all(headers);
        curl_easy_cleanup(curl);
        throw;
    }

    if (headers) curl_slist_free_all(headers);
    curl_easy_cleanup(curl);

    if (rc != CURLE_OK) throw std::runtime_error(std::string("Network Error: libcurl failed: ") + curl_easy_strerror(rc));
    if (httpCode != 200) throw std::runtime_error("Network Error: Modal endpoint returned HTTP " + std::to_string(httpCode));
    if (responseBuf.size() < sizeof(SemanticResponseHeader)) throw std::runtime_error("Network Error: Modal response too small for Semantic response header.");

    // 4. Parse and Validate Header
    SemanticResponseHeader respHeader;
    std::memcpy(&respHeader, responseBuf.data(), sizeof(SemanticResponseHeader));

    SemanticProtocolCodec::validateResponseHeader(
        respHeader,
        correlationId,
        request->tileId,
        static_cast<uint32_t>(request->width),
        static_cast<uint32_t>(request->height),
        config.expectedClassCount,
        config.expectedProtocolVersion);

    // 5. Validate Total Payload Size
    const size_t expectedTotal = sizeof(SemanticResponseHeader) + 
                                 static_cast<size_t>(respHeader.logitsPayloadLength) + 
                                 static_cast<size_t>(respHeader.confidencePayloadLength) + 
                                 static_cast<size_t>(respHeader.validMaskPayloadLength);
                                 
    if (responseBuf.size() != expectedTotal) {
        throw std::runtime_error("Network Error: Modal response body size mismatch. Expected " + 
                                 std::to_string(expectedTotal) + " bytes, got " + 
                                 std::to_string(responseBuf.size()) + " bytes.");
    }

    // 6. Extract Payloads
    size_t offset = sizeof(SemanticResponseHeader);
    
    std::vector<float> flatLogits(respHeader.logitsPayloadLength / sizeof(float));
    std::memcpy(flatLogits.data(), responseBuf.data() + offset, respHeader.logitsPayloadLength);
    offset += respHeader.logitsPayloadLength;

    std::vector<float> rawConfidence(respHeader.confidencePayloadLength / sizeof(float));
    std::memcpy(rawConfidence.data(), responseBuf.data() + offset, respHeader.confidencePayloadLength);
    offset += respHeader.confidencePayloadLength;

    std::vector<uint8_t> rawMask(respHeader.validMaskPayloadLength);
    std::memcpy(rawMask.data(), responseBuf.data() + offset, respHeader.validMaskPayloadLength);

    // 7. Build Result (Preserving exact original grid mapping logic)
    SemanticTileResult result;
    result.tileId = request->tileId;
    
    result.placement.sourceX = request->xOffset;
    result.placement.sourceY = request->yOffset;
    result.placement.paddedWidth = request->width;
    result.placement.paddedHeight = request->height;
    result.placement.validStartX = 0;
    result.placement.validStartY = 0;
    result.placement.validWidth = request->validWidth;
    result.placement.validHeight = request->validHeight;

    result.confidence.width = request->width;
    result.confidence.height = request->height;
    result.confidence.data = std::move(rawConfidence);
    
    result.validMask.width = request->width;
    result.validMask.height = request->height;
    result.validMask.data = std::move(rawMask);

    result.semanticLogits.classCount = config.expectedClassCount;
    result.semanticLogits.layout = TensorLayout::CHW;
    
    auto initGrid = [&](RasterGrid<float>& grid, size_t channelIndex) {
        grid.width = request->width;
        grid.height = request->height;
        grid.data.resize(pixelCount);
        std::memcpy(grid.data.data(), &flatLogits[channelIndex * pixelCount], pixelCount * sizeof(float));
    };
    
    initGrid(result.semanticLogits.otherLogits, static_cast<size_t>(SemanticChannel::OTHER));
    initGrid(result.semanticLogits.groundLogits, static_cast<size_t>(SemanticChannel::GROUND));
    initGrid(result.semanticLogits.lowVegetationLogits, static_cast<size_t>(SemanticChannel::LOW_VEGETATION));
    initGrid(result.semanticLogits.buildingLogits, static_cast<size_t>(SemanticChannel::BUILDING));
    initGrid(result.semanticLogits.waterLogits, static_cast<size_t>(SemanticChannel::WATER));
    initGrid(result.semanticLogits.roadLogits, static_cast<size_t>(SemanticChannel::ROAD));

    // 8. Validate and Normalize
    SemanticResponseValidator::validateAndNormalize(result, request->validMaskBytes);

    return result;
}