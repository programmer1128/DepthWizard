#include "NdsmInferenceClient.h"
#include "NdsmProtocolCodec.h"
#include "NdsmResponseValidator.h"

#include <curl/curl.h>
#include <sys/socket.h> // Kept if needed elsewhere, but TCP logic removed
#include <arpa/inet.h>
#include <netinet/tcp.h>
#include <unistd.h>

#include <algorithm>
#include <cstring>
#include <iostream>
#include <limits>
#include <mutex>
#include <stdexcept>
#include <string>
#include <vector>

namespace
{
    // Thread-safe global CURL initialization
    std::once_flag g_curlOnceFlag;
    void ensureCurlGlobalInit()
    {
        std::call_once(g_curlOnceFlag, []() {
            curl_global_init(CURL_GLOBAL_DEFAULT);
            std::cout << ">> [CURL] Global Init OK (" << curl_version() << ")" << std::endl;
        });
    }

    // Helper to stream HTTP response into a buffer
    struct DownloadSink
    {
        std::vector<char>* buf;
        size_t hardLimit;
    };

    constexpr size_t MAX_HTTP_RESPONSE_BYTES = 16 * 1024 * 1024;

    size_t WriteCallback(char* ptr, size_t size, size_t nmemb, void* userdata)
    {
        auto* sink = static_cast<DownloadSink*>(userdata);
        if (size == 0 || nmemb == 0) return 0;
        if (size > SIZE_MAX / nmemb) return 0;
        const size_t bytes = size * nmemb;
        if (bytes == 0) return 0;
        if (sink->buf->size() + bytes > sink->hardLimit) return 0; // Abort if too large
        sink->buf->insert(sink->buf->end(), ptr, ptr + bytes);
        return bytes;
    }

    bool isHttpEndpoint(const std::string& url)
    {
        return url.rfind("http://", 0) == 0 || url.rfind("https://", 0) == 0;
    }

    // Helper to package the final result (Kept exactly as your original logic)
    NdsmTileResult packageResult(
        const std::shared_ptr<TileRequest>& request,
        const std::vector<float>& outNdsm,
        const std::vector<float>& outConf)
    {
        const size_t pixelCount = static_cast<size_t>(request->width) * static_cast<size_t>(request->height);
        NdsmTileResult result;

        result.tileId = request->tileId;
        result.placement.sourceX = request->xOffset;
        result.placement.sourceY = request->yOffset;
        result.placement.paddedWidth = request->width;
        result.placement.paddedHeight = request->height;
        result.placement.validStartX = 0;
        result.placement.validStartY = 0;
        result.placement.validWidth = request->validWidth;
        result.placement.validHeight = request->validHeight;

        result.metricNdsm.width = request->width;
        result.metricNdsm.height = request->height;
        result.metricNdsm.data.resize(pixelCount);

        result.ndsmConfidence.width = request->width;
        result.ndsmConfidence.height = request->height;
        result.ndsmConfidence.data.resize(pixelCount);

        result.validMask.width = request->width;
        result.validMask.height = request->height;
        result.validMask.data.resize(pixelCount);

        float* pNdsm = result.metricNdsm.data.data();
        float* pConf = result.ndsmConfidence.data.data();
        uint8_t* pMask = result.validMask.data.data();
        const uint8_t* pInputMask = request->validMaskBytes.data();

        for (size_t i = 0; i < pixelCount; ++i)
        {
            if (pInputMask[i] == 1)
            {
                pNdsm[i] = outNdsm[i];
                pConf[i] = outConf[i];
                pMask[i] = 1;
            }
            else
            {
                pNdsm[i] = std::numeric_limits<float>::quiet_NaN();
                pConf[i] = 0.0f;
                pMask[i] = 0;
            }
        }
        return result;
    }
} // namespace

NdsmTileResult NdsmInferenceClient::infer(
    const std::shared_ptr<TileRequest>& request,
    const NdsmWorkerEndpoint& endpoint,
    const NdsmInferenceConfig& config)
{
    if (!request) throw std::invalid_argument("NdsmInferenceClient: Null TileRequest.");

    // 1. Input Validation (Kept exactly as original)
    if (request->width != config.model.expectedTileSize ||
        request->height != config.model.expectedTileSize ||
        request->validWidth <= 0 || request->validHeight <= 0 ||
        request->validWidth > request->width || request->validHeight > request->height)
    {
        throw std::invalid_argument("NdsmInferenceClient: Tile dimensions violate the model contract.");
    }

    const size_t pixelCount = static_cast<size_t>(request->width) * static_cast<size_t>(request->height);
    if (request->normalizedRgbBytes.size() != pixelCount * 3 ||
        request->validMaskBytes.size() != pixelCount)
    {
        throw std::invalid_argument("NdsmInferenceClient: Tile tensor or validity-mask size mismatch.");
    }

    for (uint8_t value : request->validMaskBytes)
    {
        if (value != 0 && value != 1)
            throw std::invalid_argument("NdsmInferenceClient: Preprocessing validity mask is not binary.");
    }

    // 2. Determine Target URL
    std::string targetUrl = endpoint.url.empty() ? endpoint.host : endpoint.url;
    if (!isHttpEndpoint(targetUrl))
    {
        throw std::runtime_error("NdsmInferenceClient: Modal deployment requires an HTTP/HTTPS endpoint URL.");
    }

    ensureCurlGlobalInit();

    // 3. Build HTTP Payload (Header + Float Tensor + Mask)
    NdsmRequestHeader reqHeader = NdsmProtocolCodec::buildRequestHeader(request->tileId, request->width, request->height);
    const size_t maskLen = pixelCount;

    std::vector<char> httpPayload(
        sizeof(NdsmRequestHeader) + 
        static_cast<size_t>(reqHeader.payloadLen) + 
        maskLen);

    std::memcpy(httpPayload.data(), &reqHeader, sizeof(NdsmRequestHeader));
    std::memcpy(httpPayload.data() + sizeof(NdsmRequestHeader), request->normalizedRgbBytes.data(), static_cast<size_t>(reqHeader.payloadLen));
    std::memcpy(httpPayload.data() + sizeof(NdsmRequestHeader) + static_cast<size_t>(reqHeader.payloadLen), request->validMaskBytes.data(), maskLen);

    // 4. Execute HTTP POST via libcurl
    std::vector<char> responseBuf;
    responseBuf.reserve(sizeof(NdsmResponseHeader) + 2 * pixelCount * sizeof(float));
    DownloadSink sink{&responseBuf, MAX_HTTP_RESPONSE_BYTES};

    CURL* curl = curl_easy_init();
    if (!curl) throw std::runtime_error("Network Error: curl_easy_init failed.");

    struct curl_slist* headers = nullptr;
    CURLcode rc = CURLE_OK;
    long httpCode = 0;

    try
    {
        headers = curl_slist_append(headers, "Content-Type: application/octet-stream");
        headers = curl_slist_append(headers, "User-Agent: NdsmInferenceClient/1.0");
        headers = curl_slist_append(headers, "Expect:"); // Prevents 100-continue delays

        curl_easy_setopt(curl, CURLOPT_URL, targetUrl.c_str());
        curl_easy_setopt(curl, CURLOPT_POST, 1L);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, httpPayload.data());
        curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE_LARGE, static_cast<curl_off_t>(httpPayload.size()));
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_HTTP_VERSION, CURL_HTTP_VERSION_2TLS); // Force HTTP/2
        
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &sink);
        
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L); // Modal uses valid certs, but safe to disable if proxy issues occur
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
        
        curl_easy_setopt(curl, CURLOPT_NOSIGNAL, 1L); // Critical for multithreading
        curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT_MS, static_cast<long>(config.network.connectTimeoutMs));
        curl_easy_setopt(curl, CURLOPT_TIMEOUT_MS, static_cast<long>(config.network.receiveTimeoutMs));

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

    if (rc != CURLE_OK)
        throw std::runtime_error(std::string("Network Error: libcurl failed: ") + curl_easy_strerror(rc));
    if (httpCode != 200)
        throw std::runtime_error("Network Error: Modal endpoint returned HTTP " + std::to_string(httpCode));
    if (responseBuf.size() < sizeof(NdsmResponseHeader))
        throw std::runtime_error("Network Error: Modal response too small for nDSM response header.");

    // 5. Parse and Validate Response
    NdsmResponseHeader respHeader;
    std::memcpy(&respHeader, responseBuf.data(), sizeof(NdsmResponseHeader));

    std::string validationError;
    if (!NdsmResponseValidator::validateHeader(respHeader, request->tileId, config.model, validationError))
    {
        throw std::runtime_error(validationError);
    }

    const size_t expectedTotal = sizeof(NdsmResponseHeader) + static_cast<size_t>(respHeader.payloadLen);
    if (responseBuf.size() != expectedTotal)
    {
        throw std::runtime_error("Network Error: Modal response body size mismatch. Expected " + 
                                 std::to_string(expectedTotal) + " bytes, got " + 
                                 std::to_string(responseBuf.size()) + " bytes.");
    }

    // Extract the float payload (skip the 32-byte header)
    std::vector<float> rawPayload(respHeader.payloadLen / sizeof(float));
    if (!rawPayload.empty())
    {
        std::memcpy(rawPayload.data(), responseBuf.data() + sizeof(NdsmResponseHeader), static_cast<size_t>(respHeader.payloadLen));
    }

    // 6. Split Tensors and Package Result
    std::vector<float> outNdsm;
    std::vector<float> outConf;
    if (!NdsmResponseValidator::validateAndSplitTensors(rawPayload, respHeader.width, respHeader.height, config.model, outNdsm, outConf, validationError))
    {
        throw std::runtime_error(validationError);
    }

    return packageResult(request, outNdsm, outConf);
}