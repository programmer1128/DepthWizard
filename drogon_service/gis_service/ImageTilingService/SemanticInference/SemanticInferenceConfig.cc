#include "SemanticInferenceConfig.h"
#include <cmath>
#include <limits>

void SemanticInferenceConfig::validate() const
{
    if (endpoints.empty())
    {
        throw std::runtime_error(
            "SemanticInferenceConfig: No endpoints configured.");
    }

    bool hasEnabledEndpoint = false;

    for (const auto& endpoint : endpoints)
    {
        if (!endpoint.enabled)
            continue;

        hasEnabledEndpoint = true;

        if (endpoint.host.empty())
        {
            throw std::runtime_error(
                "SemanticInferenceConfig: Enabled endpoint has empty host.");
        }

        if (endpoint.port == 0)
        {
            throw std::runtime_error(
                "SemanticInferenceConfig: Enabled endpoint has port zero.");
        }
    }

    if (!hasEnabledEndpoint)
    {
        throw std::runtime_error(
            "SemanticInferenceConfig: All endpoints are disabled.");
    }

    if (maxConcurrentRequests <= 0)
    {
        throw std::runtime_error(
            "SemanticInferenceConfig: maxConcurrentRequests must be positive.");
    }

    if (maxRetries < 0)
    {
        throw std::runtime_error(
            "SemanticInferenceConfig: maxRetries cannot be negative.");
    }

    if (connectTimeout.count() <= 0 ||
        sendTimeout.count() <= 0 ||
        receiveTimeout.count() <= 0)
    {
        throw std::runtime_error(
            "SemanticInferenceConfig: All timeouts must be positive.");
    }

    if (expectedTileSize == 0 ||
        expectedTileSize >
            static_cast<uint32_t>(std::numeric_limits<int>::max()))
    {
        throw std::runtime_error(
            "SemanticInferenceConfig: Invalid tile size.");
    }

    if (expectedClassCount != 6)
    {
        throw std::runtime_error(
            "SemanticInferenceConfig: Current semantic contract requires exactly six classes.");
    }

    if (expectedProtocolVersion == 0)
    {
        throw std::runtime_error(
            "SemanticInferenceConfig: Protocol version cannot be zero.");
    }

    if (expectedModelName.empty())
    {
        throw std::runtime_error(
            "SemanticInferenceConfig: Expected model name is empty.");
    }

    if (acceptedVersions.empty())
    {
        throw std::runtime_error(
            "SemanticInferenceConfig: No accepted model versions configured.");
    }

    if (!std::isfinite(minEffectiveWeight) ||
        minEffectiveWeight <= 0.0f ||
        minEffectiveWeight > 1.0f)
    {
        throw std::runtime_error(
            "SemanticInferenceConfig: minEffectiveWeight must be in (0,1].");
    }
}

SemanticInferenceConfig SemanticInferenceConfig::loadDefaults() 
{
    SemanticInferenceConfig config;
    
    // Add one default active endpoint specifically for the semantic Python worker
    SemanticWorkerEndpoint defaultEndpoint;
    defaultEndpoint.host = "127.0.0.1";
    defaultEndpoint.port = 9093; 
    defaultEndpoint.enabled = true;
    
    config.endpoints.push_back(defaultEndpoint);
    
    return config;
}