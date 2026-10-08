#include "NdsmInferenceService.h"
#include "NdsmTileDispatcher.h"
#include <stdexcept>
#include <trantor/utils/Logger.h>

NdsmTiledPayload NdsmInferenceService::executeInference(
    int globalWidth,
    int globalHeight,
    const std::vector<std::shared_ptr<TileRequest>>& tiles,
    const NdsmInferenceConfig& config)
{
    std::vector<std::string> configErrors;
    if (!config.validate(configErrors)) 
    {
        for (const auto& err : configErrors) 
        {
            LOG_ERROR << "NdsmInferenceConfig Error: " << err;
        }
        throw std::runtime_error("NdsmInferenceService: Invalid configuration provided.");
    }

    if (tiles.empty()) 
    {
        LOG_WARN << "NdsmInferenceService: Received empty tile batch.";
        NdsmTiledPayload emptyPayload;
        emptyPayload.globalWidth = globalWidth;
        emptyPayload.globalHeight = globalHeight;
        return emptyPayload;
    }

    LOG_INFO << "NdsmInferenceService: Dispatching " << tiles.size() << " tiles for nDSM inference.";
    
    // Call the bounded queue. Developer A's responsibility stops when this returns.
    return NdsmTileDispatcher::dispatchBatch(globalWidth, globalHeight, tiles, config);
}