#include "NdsmInferenceClient.h"
#include "NdsmProtocolCodec.h"
#include "NdsmResponseValidator.h"
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/tcp.h>
#include <unistd.h>
#include <stdexcept>
#include <limits>
#include <cstring>

// RAII Socket Wrapper to guarantee closure on exceptions or early returns
class ScopedSocket {
public:
    int fd;
    explicit ScopedSocket(int sock) : fd(sock) {}
    ~ScopedSocket() { if (fd >= 0) close(fd); }
    ScopedSocket(const ScopedSocket&) = delete;
    ScopedSocket& operator=(const ScopedSocket&) = delete;
};

void NdsmInferenceClient::sendAll(int sock, const char* data, size_t length)
{
    size_t totalSent = 0;
    while (totalSent < length) 
    {
        ssize_t sent = send(sock, data + totalSent, length - totalSent, MSG_NOSIGNAL);
        if (sent <= 0) throw std::runtime_error("Network Error: Connection dropped during send.");
        totalSent += sent;
    }
}

void NdsmInferenceClient::receiveAll(int sock, char* buffer, size_t length)
{
    size_t totalReceived = 0;
    while (totalReceived < length) 
    {
        // MSG_WAITALL attempts to block until full length is met, but we loop for safety against signals
        ssize_t received = recv(sock, buffer + totalReceived, length - totalReceived, MSG_WAITALL);
        if (received <= 0) throw std::runtime_error("Network Error: Connection dropped during receive.");
        totalReceived += received;
    }
}

NdsmTileResult NdsmInferenceClient::infer(
    const std::shared_ptr<TileRequest>& request, 
    const NdsmWorkerEndpoint& endpoint,
    const NdsmInferenceConfig& config)
{
    if (!request) throw std::invalid_argument("NdsmInferenceClient: Null TileRequest.");

    if (request->width != config.model.expectedTileSize ||
        request->height != config.model.expectedTileSize ||
        request->validWidth <= 0 || request->validHeight <= 0 ||
        request->validWidth > request->width ||
        request->validHeight > request->height)
    {
        throw std::invalid_argument(
            "NdsmInferenceClient: Tile dimensions violate the model contract.");
    }

    const size_t pixelCount =
        static_cast<size_t>(request->width) * static_cast<size_t>(request->height);
    if (request->normalizedRgbBytes.size() != pixelCount * 3 ||
        request->validMaskBytes.size() != pixelCount)
    {
        throw std::invalid_argument(
            "NdsmInferenceClient: Tile tensor or validity-mask size mismatch.");
    }

    for (uint8_t value : request->validMaskBytes)
    {
        if (value != 0 && value != 1)
        {
            throw std::invalid_argument(
                "NdsmInferenceClient: Preprocessing validity mask is not binary.");
        }
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) throw std::runtime_error("Network Error: Failed to create socket.");
    ScopedSocket scopedSock(sock);

    int flag = 1;
    setsockopt(sock, IPPROTO_TCP, TCP_NODELAY, (char*)&flag, sizeof(int));

    struct timeval snd_tv = { config.network.sendTimeoutMs / 1000, (config.network.sendTimeoutMs % 1000) * 1000 };
    struct timeval rcv_tv = { config.network.receiveTimeoutMs / 1000, (config.network.receiveTimeoutMs % 1000) * 1000 };
    setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, &snd_tv, sizeof(snd_tv));
    setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, &rcv_tv, sizeof(rcv_tv));

    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(endpoint.port);
    if (inet_pton(AF_INET, endpoint.host.c_str(), &serv_addr.sin_addr) <= 0) 
    {
        throw std::runtime_error("Network Error: Invalid endpoint IP: " + endpoint.host);
    }

    if (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) 
    {
        throw std::runtime_error("Network Error: Connection refused to " + endpoint.host + ":" + std::to_string(endpoint.port));
    }

    // 1. Send Request
    NdsmRequestHeader reqHeader = NdsmProtocolCodec::buildRequestHeader(request->tileId, request->width, request->height);
    sendAll(sock, reinterpret_cast<const char*>(&reqHeader), sizeof(NdsmRequestHeader));
    
    // Float32 RGB tensor
    sendAll(sock, reinterpret_cast<const char*>(request->normalizedRgbBytes.data()), reqHeader.payloadLen);
    
    // Preprocessing Mask (1 byte per pixel)
    const size_t maskLen = pixelCount;
    sendAll(sock, reinterpret_cast<const char*>(request->validMaskBytes.data()), maskLen);

    // 2. Receive & Validate Header
    NdsmResponseHeader respHeader;
    receiveAll(sock, reinterpret_cast<char*>(&respHeader), sizeof(NdsmResponseHeader));

    std::string validationError;
    if (!NdsmResponseValidator::validateHeader(respHeader, request->tileId, config.model, validationError))
    {
        throw std::runtime_error(validationError);
    }

    // 3. Receive Payload (Will be Float32 exactly sized for 2 channels)
    std::vector<float> rawPayload(respHeader.payloadLen / sizeof(float));
    receiveAll(sock, reinterpret_cast<char*>(rawPayload.data()), respHeader.payloadLen);

    // 4. Split and Validate Tensor Math
    std::vector<float> outNdsm;
    std::vector<float> outConf;
    if (!NdsmResponseValidator::validateAndSplitTensors(rawPayload, respHeader.width, respHeader.height, config.model, outNdsm, outConf, validationError))
    {
        throw std::runtime_error(validationError);
    }

    // 5. Package final Result
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

    // 6. Enforce NoData contract
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
            // CRITICAL: Strictly enforce NaN for NoData, never 0.0[cite: 2]
            pNdsm[i] = std::numeric_limits<float>::quiet_NaN();
            pConf[i] = 0.0f;
            pMask[i] = 0;
        }
    }

    return result;
}
