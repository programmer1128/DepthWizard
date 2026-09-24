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
#include <cerrno>
#include <limits>
#include "SemanticResponseValidator.h"

class SocketHandle
{
public:
    explicit SocketHandle(int descriptor) : descriptor_(descriptor) {}
    SocketHandle(const SocketHandle&) = delete;
    SocketHandle& operator=(const SocketHandle&) = delete;

    ~SocketHandle()
    {
        if (descriptor_ >= 0)
            ::close(descriptor_);
    }

    int get() const noexcept { return descriptor_; }

private:
    int descriptor_{-1};
};

static timeval toTimeval(std::chrono::milliseconds timeout)
{
    const auto totalMilliseconds = timeout.count();
    timeval value{};
    value.tv_sec = static_cast<time_t>(totalMilliseconds / 1000);
    value.tv_usec = static_cast<suseconds_t>((totalMilliseconds % 1000) * 1000);
    return value;
}

static void requireSocketOption(
    int socketDescriptor,
    int level,
    int option,
    const void* value,
    socklen_t valueSize,
    const char* optionName)
{
    if (::setsockopt(socketDescriptor, level, option, value, valueSize) != 0)
    {
        throw std::runtime_error(
            std::string("SemanticClient: Failed to set ") + optionName +
            ": " + std::strerror(errno));
    }
}

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

    config.validate();
    const size_t pixelCount = validateRequest(*request, config);
    const uint64_t correlationId = static_cast<uint64_t>(request->tileId);

    // 1. Establish Socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        throw std::runtime_error("SemanticClient: Failed to create socket.");
    }
    SocketHandle socketHandle(sock);

    // Disable Nagle's algorithm for immediate transmission
    int flag = 1;
    requireSocketOption(sock, IPPROTO_TCP, TCP_NODELAY, &flag, sizeof(flag), "TCP_NODELAY");

    // Apply strict configuration timeouts
    const timeval tvSend = toTimeval(config.sendTimeout);
    const timeval tvRecv = toTimeval(config.receiveTimeout);
    requireSocketOption(sock, SOL_SOCKET, SO_SNDTIMEO, &tvSend, sizeof(tvSend), "SO_SNDTIMEO");
    requireSocketOption(sock, SOL_SOCKET, SO_RCVTIMEO, &tvRecv, sizeof(tvRecv), "SO_RCVTIMEO");

    struct sockaddr_in serv_addr{};
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(endpoint.port); 
    
    if (inet_pton(AF_INET, endpoint.host.c_str(), &serv_addr.sin_addr) <= 0) {
        throw std::runtime_error("SemanticClient: Invalid worker IP: " + endpoint.host);
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        throw std::runtime_error("SemanticClient: Connection refused at " + endpoint.host + ":" + std::to_string(endpoint.port));
    }

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

        // 5. Build Result
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

        // Copy the worker mask now; validation intersects it with preprocessing.
        result.validMask.data = std::move(rawMask);

        // 6. Distribute flat logits into CHW rasters before validation.
        result.semanticLogits.classCount = config.expectedClassCount;
        result.semanticLogits.layout = TensorLayout::CHW;
        
        auto initGrid = [&](RasterGrid<float>& grid, size_t channelIndex) {
            grid.width = request->width;
            grid.height = request->height;
            grid.data.resize(pixelCount);
            std::memcpy(grid.data.data(), &flatLogits[channelIndex * pixelCount], pixelCount * sizeof(float));
        };

        initGrid(
            result.semanticLogits.otherLogits,
            static_cast<size_t>(SemanticChannel::OTHER));

        initGrid(
            result.semanticLogits.groundLogits,
            static_cast<size_t>(SemanticChannel::GROUND));

        initGrid(
            result.semanticLogits.lowVegetationLogits,
            static_cast<size_t>(SemanticChannel::LOW_VEGETATION));

        initGrid(
            result.semanticLogits.buildingLogits,
            static_cast<size_t>(SemanticChannel::BUILDING));

        initGrid(
            result.semanticLogits.waterLogits,
            static_cast<size_t>(SemanticChannel::WATER));

        initGrid(
            result.semanticLogits.roadLogits,
            static_cast<size_t>(SemanticChannel::ROAD));

        // Intersect the worker and preprocessing masks only after every grid
        // has been constructed; the validator reads and normalizes all grids.
        SemanticResponseValidator::validateAndNormalize(
            result,
            request->validMaskBytes);

        return result;
}
