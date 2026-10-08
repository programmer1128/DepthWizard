// Strictly enforces ONNX tensor rules and real-world physical limits.
// Any failure here immediately aborts the tile to prevent downstream reconstruction corruption.

#pragma once
#include "NdsmProtocolCodec.h"
#include "../NdsmInferenceConfig.h"
#include <string>
#include <vector>

class NdsmResponseValidator 
{
public:
    // Validates the parsed header from the TCP socket
    static bool validateHeader(
        const NdsmResponseHeader& header, 
        uint32_t expectedTileId, 
        const NdsmModelExpectations& config, 
        std::string& outError);

    // Iterates through the output tensor to guarantee physical possibility and split CHW channels
    static bool validateAndSplitTensors(
        const std::vector<float>& rawWorkerPayload, 
        int width, 
        int height,
        const NdsmModelExpectations& config,
        std::vector<float>& outMetricNdsm,
        std::vector<float>& outConfidence,
        std::string& outError);
};