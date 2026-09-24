#include "SemanticInferenceClient.h"
#include "SemanticProtocolCodec.h"
#include <sys/socket.h>   
#include <arpa/inet.h>    
#include <netinet/tcp.h>  
#include <unistd.h>  
#include <sys/time.h>    
#include <cstring>
#include <stdexcept>
#include <chrono>
#include "SemanticResponseValidator.h"


static size_t validateRequest(
    const TileRequest& request,
    const SemanticInferenceConfig& config)
{
    if (request.width <= 0 || request.height <= 0)
    {
        throw std::invalid_argument(
            "SemanticClient: Tile dimensions must be positive.");
    }

    if (static_cast<uint32_t>(request.width) !=
            config.expectedTileSize ||
        static_cast<uint32_t>(request.height) !=
            config.expectedTileSize)
    {
        throw std::invalid_argument(
            "SemanticClient: Tile dimensions do not match model contract.");
    }

    if (request.validWidth <= 0 ||
        request.validHeight <= 0 ||
        request.validWidth > request.width ||
        request.validHeight > request.height)
    {
        throw std::invalid_argument(
            "SemanticClient: Invalid tile valid region.");
    }

    const size_t width = static_cast<size_t>(request.width);
    const size_t height = static_cast<size_t>(request.height);

    if (width > std::numeric_limits<size_t>::max() / height)
    {
        throw std::overflow_error(
            "SemanticClient: Tile pixel count overflow.");
    }

    const size_t pixels = width * height;

    if (pixels > std::numeric_limits<size_t>::max() / 3)
    {
        throw std::overflow_error(
            "SemanticClient: RGB element count overflow.");
    }

    if (request.normalizedRgbBytes.size() != pixels * 3)
    {
        throw std::invalid_argument(
            "SemanticClient: RGB tensor size mismatch.");
    }

    if (request.validMaskBytes.size() != pixels)
    {
        throw std::invalid_argument(
            "SemanticClient: Preprocessing mask size mismatch.");
    }

    for (uint8_t value : request.validMaskBytes)
    {
        if (value != 0 && value != 1)
        {
            throw std::invalid_argument(
                "SemanticClient: Preprocessing mask is not binary.");
        }
    }

    return pixels;
}


// Helper function to guarantee all bytes are sent
static void sendAll(int sock, const uint8_t* data, size_t length) 
{
    size_t totalSent = 0;
    while (totalSent < length) {
        ssize_t sent = send(sock, data + totalSent, length - totalSent, MSG_NOSIGNAL);
        if (sent <= 0) {
            throw std::runtime_error("SemanticClient: Connection dropped during send.");
        }
        totalSent += sent;
    }
}

// Helper function to guarantee all bytes are received
static void recvAll(int sock, uint8_t* data, size_t length) 
{
    size_t totalReceived = 0;
    while (totalReceived < length) {
        ssize_t bytesRead = recv(sock, data + totalReceived, length - totalReceived, 0);
        if (bytesRead <= 0) {
            throw std::runtime_error("SemanticClient: Connection dropped during receive.");
        }
        totalReceived += bytesRead;
    }
}

SemanticTileResult SemanticInferenceClient::inferTile(
    std::shared_ptr<TileRequest> request, 
    const SemanticWorkerEndpoint& endpoint,
    const SemanticInferenceConfig& config)
{
    if (!request) {
        throw std::invalid_argument("SemanticClient: TileRequest is null.");
    }

    uint64_t correlationId = static_cast<uint64_t>(request->tileId);
    size_t pixelCount = static_cast<size_t>(request->width) * request->height;

    // 1. Establish Socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        throw std::runtime_error("SemanticClient: Failed to create socket.");
    }

    // Disable Nagle's algorithm for immediate transmission
    int flag = 1;
    config.validate();
    const size_t pixelCount = validateRequest(*request, config);
    setsockopt(sock, IPPROTO_TCP, TCP_NODELAY, (char*)&flag, sizeof(int));

    // Apply strict configuration timeouts
    struct timeval tvSend, tvRecv;
    tvSend.tv_sec = std::chrono::duration_cast<std::chrono::seconds>(config.sendTimeout).count();
    tvSend.tv_usec = 0;
    tvRecv.tv_sec = std::chrono::duration_cast<std::chrono::seconds>(config.receiveTimeout).count();
    tvRecv.tv_usec = 0;
    setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, (const char*)&tvSend, sizeof(tvSend));
    setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tvRecv, sizeof(tvRecv));

    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(endpoint.port); 
    
    if (inet_pton(AF_INET, endpoint.host.c_str(), &serv_addr.sin_addr) <= 0) {
        close(sock);
        throw std::runtime_error("SemanticClient: Invalid worker IP: " + endpoint.host);
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        close(sock);
        throw std::runtime_error("SemanticClient: Connection refused at " + endpoint.host + ":" + std::to_string(endpoint.port));
    }

    try {
        // 2. Transmit Data
        SemanticRequestHeader reqHeader = SemanticProtocolCodec::buildRequestHeader(correlationId, *request);
        
        sendAll(sock, reinterpret_cast<const uint8_t*>(&reqHeader), sizeof(SemanticRequestHeader));
        sendAll(sock, reinterpret_cast<const uint8_t*>(request->normalizedRgbBytes.data()), reqHeader.rgbPayloadLength);
        sendAll(sock, reinterpret_cast<const uint8_t*>(request->validMaskBytes.data()), reqHeader.maskPayloadLength);

        // 3. Receive & Validate Header
        SemanticResponseHeader respHeader;
        recvAll(sock, reinterpret_cast<uint8_t*>(&respHeader), sizeof(SemanticResponseHeader));

        SemanticProtocolCodec::validateResponseHeader(
            respHeader,
            correlationId,
            request->tileId,
            static_cast<uint32_t>(request->width),
            static_cast<uint32_t>(request->height),
            config.expectedClassCount,
            config.expectedProtocolVersion);

        // 4. Receive Payloads
        std::vector<float> flatLogits(pixelCount * config.expectedClassCount);
        std::vector<float> rawConfidence(pixelCount);
        std::vector<uint8_t> rawMask(pixelCount);

        recvAll(sock, reinterpret_cast<uint8_t*>(flatLogits.data()), respHeader.logitsPayloadLength);
        recvAll(sock, reinterpret_cast<uint8_t*>(rawConfidence.data()), respHeader.confidencePayloadLength);
        recvAll(sock, reinterpret_cast<uint8_t*>(rawMask.data()), respHeader.validMaskPayloadLength);

        close(sock);

        // 5. Build Result & Intersect Mask
        SemanticTileResult result;
        result.tileId = request->tileId;
        
        // Map Placement
        result.placement.sourceX = request->xOffset;
        result.placement.sourceY = request->yOffset;
        result.placement.paddedWidth = request->width;
        result.placement.paddedHeight = request->height;
        result.placement.validStartX = 0;
        result.placement.validStartY = 0;
        result.placement.validWidth = request->validWidth;
        result.placement.validHeight = request->validHeight;

        // Initialize Output Grids
        result.confidence.width = request->width;
        result.confidence.height = request->height;
        result.confidence.data = std::move(rawConfidence);

        result.validMask.width = request->width;
        result.validMask.height = request->height;
        result.validMask.data.resize(pixelCount, 0);

        // Intersect worker mask with preprocessing mask
        result.validMask.data = std::move(rawMask);
        SemanticResponseValidator::validateAndNormalize(
            result,
            request->validMaskBytes);

        // 6. Distribute Flat Logits into CHW Rasters
        result.semanticLogits.classCount = config.expectedClassCount;
        result.semanticLogits.layout = TensorLayout::CHW;
        
        auto initGrid = [&](RasterGrid<float>& grid, size_t channelIndex) {
            grid.width = request->width;
            grid.height = request->height;
            grid.data.resize(pixelCount);
            std::memcpy(grid.data.data(), &flatLogits[channelIndex * pixelCount], pixelCount * sizeof(float));
        };

        initGrid(
    result.semanticLogits.unknownLogits,
    static_cast<size_t>(SemanticChannel::UNKNOWN));

        initGrid(
            result.semanticLogits.groundLogits,
            static_cast<size_t>(SemanticChannel::GROUND));

        initGrid(
            result.semanticLogits.buildingLogits,
            static_cast<size_t>(SemanticChannel::BUILDING));

        initGrid(
            result.semanticLogits.roadLogits,
            static_cast<size_t>(SemanticChannel::ROAD));

        initGrid(
            result.semanticLogits.vegetationLogits,
            static_cast<size_t>(SemanticChannel::VEGETATION));

        initGrid(
            result.semanticLogits.waterLogits,
            static_cast<size_t>(SemanticChannel::WATER));
       // SemanticResponseValidator::validateAndNormalize(result);
        return result;

    } catch (...) {
        close(sock);
        throw; // Re-throw to be handled by the dispatcher's retry logic
    }
}