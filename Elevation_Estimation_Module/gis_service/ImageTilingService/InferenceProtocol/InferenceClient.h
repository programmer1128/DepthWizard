// connection between C++ engine and the model GPUs
// defines the tile structure before sending to GPU 
// handles the actual sending process

#pragma once

#include <string>
#include <vector>
#include <memory>
#include <cstdint>
#include "../../structures/InferenceStructs.h"
#include "../../utils/TilingTypes.h"


class InferenceClient 
{
    
    public:

    // connects to GPU, sends the tile and gets 4 results back
    // request: pointer to the tile data
    // target_gpu_ip: IP of the GPU that will process this tile
    // TileInferenceResult: 4 mathematical layers returned by the model
     
    static TileInferenceResult inferMetricTile(
        std::shared_ptr<TileRequest> request, 
        const std::string& target_gpu_ip);
};