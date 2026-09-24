#include "NdsmInferenceConfig.h"
#include <cmath>

bool NdsmInferenceConfig::validate(std::vector<std::string>& outErrors) const
{
    bool isValid = true;

    bool hasActiveEndpoint = false;
    for (const auto& ep : endpoints) 
    {
        if (ep.enabled) 
        {
            hasActiveEndpoint = true;
            if (ep.host.empty() || ep.port <= 0 || ep.port > 65535) 
            {
                outErrors.push_back("Invalid endpoint configuration: " + ep.host + ":" + std::to_string(ep.port));
                isValid = false;
            }
        }
    }
    
    if (!hasActiveEndpoint) 
    {
        outErrors.push_back("No active nDSM worker endpoints configured.");
        isValid = false;
    }

    if (network.maxConcurrentRequests <= 0) 
    {
        outErrors.push_back("Maximum concurrent requests must be greater than zero.");
        isValid = false;
    }

    if (network.maxRetries <= 0)
    {
        outErrors.push_back("Maximum retries must be greater than zero.");
        isValid = false;
    }

    if (network.connectTimeoutMs <= 0 ||
        network.sendTimeoutMs <= 0 ||
        network.receiveTimeoutMs <= 0)
    {
        outErrors.push_back("All nDSM network timeouts must be greater than zero.");
        isValid = false;
    }

    if (model.expectedModelName.empty() || model.expectedTileSize <= 0)
    {
        outErrors.push_back("The nDSM model name and tile size must be configured.");
        isValid = false;
    }

    if (!std::isfinite(model.minAcceptableHeight) ||
        !std::isfinite(model.maxAcceptableHeight) ||
        model.maxAcceptableHeight <= model.minAcceptableHeight)
    {
        outErrors.push_back("Max acceptable height must be strictly greater than min acceptable height.");
        isValid = false;
    }

    if (!std::isfinite(stitching.minimumEffectiveWeight) ||
        stitching.minimumEffectiveWeight <= 0.0f)
    {
        outErrors.push_back("Minimum nDSM stitching weight must be finite and positive.");
        isValid = false;
    }

    return isValid;
}

NdsmInferenceConfig NdsmInferenceConfig::loadDefaults()
{
    NdsmInferenceConfig config;
    config.endpoints.push_back({
        .host = "127.0.0.1",
        .port = 9092,
        .workerId = "local-ndsm-worker",
        .enabled = true
    });
    return config;
}
