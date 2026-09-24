#include "SemanticProtocolCodec.h"
#include <limits>

SemanticRequestHeader SemanticProtocolCodec::buildRequestHeader(
    uint64_t requestId, 
    const TileRequest& request)
{
    SemanticRequestHeader header;
    header.magic = SEMANTIC_MAGIC_REQ;
    header.protocolVersion = CURRENT_VERSION;
    header.requestId = requestId;
    header.tileId = request.tileId;
    header.width = request.width;
    header.height = request.height;
    header.channels = 3;
    
    // Calculate exact expected byte lengths
    header.rgbPayloadLength = static_cast<uint64_t>(request.normalizedRgbBytes.size() * sizeof(float));
    header.maskPayloadLength = static_cast<uint64_t>(request.validMaskBytes.size() * sizeof(uint8_t));

    return header;
}

static uint64_t checkedMultiply(
    uint64_t lhs,
    uint64_t rhs,
    const char* field)
{
    if (lhs != 0 &&
        rhs > std::numeric_limits<uint64_t>::max() / lhs)
    {
        throw std::runtime_error(
            std::string("SemanticCodec: Overflow calculating ") + field);
    }

    return lhs * rhs;
}

void SemanticProtocolCodec::validateResponseHeader(
    const SemanticResponseHeader& header,
    uint64_t expectedRequestId,
    uint32_t expectedTileId,
    uint32_t expectedWidth,
    uint32_t expectedHeight,
    uint32_t expectedClassCount,
    uint32_t expectedProtocolVersion)
{
    if (header.magic != SEMANTIC_MAGIC_RESP)
    {
        throw std::runtime_error(
            "SemanticCodec: Invalid response magic number.");
    }

    if (header.protocolVersion != expectedProtocolVersion)
    {
        throw std::runtime_error(
            "SemanticCodec: Protocol version mismatch.");
    }

    if (header.requestId != expectedRequestId)
    {
        throw std::runtime_error(
            "SemanticCodec: Request ID mismatch.");
    }

    if (header.tileId != expectedTileId)
    {
        throw std::runtime_error(
            "SemanticCodec: Tile ID mismatch.");
    }

    if (header.status != 0)
    {
        throw std::runtime_error(
            "SemanticCodec: Worker returned error status " +
            std::to_string(header.status));
    }

    if (header.width != expectedWidth ||
        header.height != expectedHeight)
    {
        throw std::runtime_error(
            "SemanticCodec: Response dimensions do not match request.");
    }

    if (header.classCount != expectedClassCount)
    {
        throw std::runtime_error(
            "SemanticCodec: Class count mismatch.");
    }

    const uint64_t pixels = checkedMultiply(
        expectedWidth, expectedHeight, "pixel count");

    const uint64_t logitElements = checkedMultiply(
        pixels, expectedClassCount, "logit element count");

    const uint64_t expectedLogitBytes = checkedMultiply(
        logitElements, sizeof(float), "logit byte count");

    const uint64_t expectedConfidenceBytes = checkedMultiply(
        pixels, sizeof(float), "confidence byte count");

    const uint64_t expectedMaskBytes = checkedMultiply(
        pixels, sizeof(uint8_t), "mask byte count");

    if (header.logitsPayloadLength != expectedLogitBytes)
    {
        throw std::runtime_error(
            "SemanticCodec: Incorrect logits payload length.");
    }

    if (header.confidencePayloadLength != expectedConfidenceBytes)
    {
        throw std::runtime_error(
            "SemanticCodec: Incorrect confidence payload length.");
    }

    if (header.validMaskPayloadLength != expectedMaskBytes)
    {
        throw std::runtime_error(
            "SemanticCodec: Incorrect mask payload length.");
    }
}
