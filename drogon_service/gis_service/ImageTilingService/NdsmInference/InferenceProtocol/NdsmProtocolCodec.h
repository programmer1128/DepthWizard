#pragma once
#include <cstdint>
#include <vector>

// Enforce 1-byte alignment to prevent C++ compiler padding from corrupting TCP network bytes
#pragma pack(push, 1)
struct NdsmRequestHeader 
{
    uint32_t magic;         // Security password (e.g., 0xDEADBEEF)
    uint32_t tileId;        // Unique tile identifier
    uint32_t width;         // Expected 518
    uint32_t height;        // Expected 518
    uint32_t channels;      // 3 (RGB Input)
    uint64_t payloadLen;    // Size of the incoming float matrix
};

struct NdsmResponseHeader 
{
    uint32_t magic;
    uint32_t tileId;        // Echoed back to ensure correlation
    uint32_t status;        // 0 = Success, >0 = Worker Error
    uint32_t width;         // 518
    uint32_t height;        // 518
    uint32_t channels;      // 2 (nDSM + Confidence)
    uint64_t payloadLen;    // Expected: 518 * 518 * 2 * sizeof(float)
};
#pragma pack(pop)

class NdsmProtocolCodec 
{
public:
    static constexpr uint32_t NDSM_MAGIC_NUMBER = 0xDEADBEEF;

    // Generates the byte-aligned header for sending
    static NdsmRequestHeader buildRequestHeader(uint32_t tileId, int width, int height);
};