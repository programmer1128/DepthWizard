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
            
            // NEW: Validate EITHER a valid HTTPS URL OR the legacy host/port
            bool hasValidUrl = !ep.url.empty() && 
                               (ep.url.rfind("http://", 0) == 0 || ep.url.rfind("https://", 0) == 0);
            bool hasValidHostPort = !ep.host.empty() && ep.port > 0 && ep.port <= 65535;

            if (!hasValidUrl && !hasValidHostPort)
            {
                outErrors.push_back("Invalid endpoint configuration: Must provide either a valid 'url' or 'host'+'port'.");
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
    
    // NEW: Configure your deployed Modal URL
    config.endpoints.push_back({
        .host = "", // Empty because we are using URL
        .port = 443,
        .url = "https://satadru-ghosh-cse28--depth-wizard-inference-depthinferen-f5d179.modal.run",
        .workerId = "modal-ndsm-worker",
        .enabled = true
    });

    config.network.maxConcurrentRequests = 4;
    config.network.maxRetries = 3;
    config.network.connectTimeoutMs = 20000;
    config.network.sendTimeoutMs = 120000;
    config.network.receiveTimeoutMs = 300000;

    config.model.expectedModelName = "model_a_metric_ndsm";
    config.model.expectedTileSize = 518;
    config.model.minAcceptableHeight = -50.0f;
    config.model.maxAcceptableHeight = 9000.0f;

    config.stitching.hannWindowEnabled = true;
    config.stitching.minimumEffectiveWeight = 1e-6f;
    config.stitching.confidenceWeightingEnabled = true;

    return config;
}
