#include "NdsmInferenceConfig.h"

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

    if (model.maxAcceptableHeight <= model.minAcceptableHeight) 
    {
        outErrors.push_back("Max acceptable height must be strictly greater than min acceptable height.");
        isValid = false;
    }

    return isValid;
}