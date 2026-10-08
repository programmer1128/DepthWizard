#pragma once

#include <cstdint>
#include <vector>
#include <string>
#include <stdexcept>
#include "../../structures/InferenceStructs.h" // For TileRequest

// Force 1-byte alignment for strict network transmission
#pragma pack(push, 1)

struct SemanticRequestHeader {
    uint32_t magic;              // Security password (e.g., 0x5E3A471C)
    uint32_t protocolVersion;    
    uint64_t requestId;          // Correlation ID
    uint32_t tileId;             
    uint32_t width;              
    uint32_t height;             
    uint32_t channels;           // 3 for RGB
    uint64_t rgbPayloadLength;   // Bytes for the RGB tensor
    uint64_t maskPayloadLength;  // Bytes for the valid mask
};

struct SemanticResponseHeader {
    uint32_t magic;
    uint32_t protocolVersion;
    uint64_t requestId;          // Must match request
    uint32_t tileId;             // Must match request
    uint32_t status;             // 0 = Success, >0 = Error code
    uint32_t width;
    uint32_t height;
    uint32_t classCount;         // Expected 6
    uint64_t logitsPayloadLength;     // Expected: 6 * W * H * 4 bytes
    uint64_t confidencePayloadLength; // Expected: W * H * 4 bytes
    uint64_t validMaskPayloadLength;  // Expected: W * H * 1 byte
};

#pragma pack(pop)

class SemanticProtocolCodec {
public:
    static constexpr uint32_t SEMANTIC_MAGIC_REQ = 0x5E3A471C;
    static constexpr uint32_t SEMANTIC_MAGIC_RESP = 0xC174A3E5;
    static constexpr uint32_t CURRENT_VERSION = 1;

    // Generates the exact binary header for the request
    static SemanticRequestHeader buildRequestHeader(
        uint64_t requestId, 
        const TileRequest& request);

    // Validates the parsed response header against our configuration
    static void validateResponseHeader(
        const SemanticResponseHeader& header,
        uint64_t expectedRequestId,
        uint32_t expectedTileId,
        uint32_t expectedWidth,
        uint32_t expectedHeight,
        uint32_t expectedClassCount,
        uint32_t expectedProtocolVersion);
};