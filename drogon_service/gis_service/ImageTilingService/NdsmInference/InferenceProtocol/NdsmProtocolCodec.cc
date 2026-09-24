#include "NdsmProtocolCodec.h"

NdsmRequestHeader NdsmProtocolCodec::buildRequestHeader(uint32_t tileId, int width, int height)
{
    NdsmRequestHeader header;
    header.magic = NDSM_MAGIC_NUMBER;
    header.tileId = tileId;
    header.width = static_cast<uint32_t>(width);
    header.height = static_cast<uint32_t>(height);
    header.channels = 3; 
    
    // Payload length = (Width * Height * 3 channels) * 4 bytes per float
    header.payloadLen = static_cast<uint64_t>(width) * height * 3 * sizeof(float);
    
    return header;
}