#include "SemanticInferenceConfig.h"
#include <cmath>
#include <limits>

void SemanticInferenceConfig::validate() const
{
    if (endpoints.empty())
    {
        throw std::runtime_error("SemanticInferenceConfig: No endpoints configured.");
    }
    
    bool hasEnabledEndpoint = false;
    for (const auto& endpoint : endpoints)
    {
        if (!endpoint.enabled) continue;
        hasEnabledEndpoint = true;
        
        // NEW: Validate EITHER a valid HTTPS URL OR the legacy host/port
        bool hasValidUrl = !endpoint.url.empty() && 
                           (endpoint.url.rfind("http://", 0) == 0 || endpoint.url.rfind("https://", 0) == 0);
        bool hasValidHostPort = !endpoint.host.empty() && endpoint.port > 0;
        
        if (!hasValidUrl && !hasValidHostPort)
        {
            throw std::runtime_error("SemanticInferenceConfig: Enabled endpoint must provide either a valid 'url' or 'host'+'port'.");
        }
    }
    
    if (!hasEnabledEndpoint)
    {
        throw std::runtime_error("SemanticInferenceConfig: All endpoints are disabled.");
    }
    if (maxConcurrentRequests <= 0) throw std::runtime_error("SemanticInferenceConfig: maxConcurrentRequests must be positive.");
    if (maxRetries < 0) throw std::runtime_error("SemanticInferenceConfig: maxRetries cannot be negative.");
    if (connectTimeout.count() <= 0 || sendTimeout.count() <= 0 || receiveTimeout.count() <= 0) {
        throw std::runtime_error("SemanticInferenceConfig: All timeouts must be positive.");
    }
    if (expectedTileSize == 0 || expectedTileSize > static_cast<uint32_t>(std::numeric_limits<int>::max())) {
        throw std::runtime_error("SemanticInferenceConfig: Invalid tile size.");
    }
    if (expectedClassCount != 6) throw std::runtime_error("SemanticInferenceConfig: Current semantic contract requires exactly six classes.");
    if (expectedProtocolVersion == 0) throw std::runtime_error("SemanticInferenceConfig: Protocol version cannot be zero.");
    if (expectedModelName.empty()) throw std::runtime_error("SemanticInferenceConfig: Expected model name is empty.");
    if (acceptedVersions.empty()) throw std::runtime_error("SemanticInferenceConfig: No accepted model versions configured.");
    if (!std::isfinite(minEffectiveWeight) || minEffectiveWeight <= 0.0f || minEffectiveWeight > 1.0f) {
        throw std::runtime_error("SemanticInferenceConfig: minEffectiveWeight must be in (0,1].");
    }
}

SemanticInferenceConfig SemanticInferenceConfig::loadDefaults()
{
    SemanticInferenceConfig config;
    
    // NEW: Configure your deployed Modal Semantic URL
    SemanticWorkerEndpoint defaultEndpoint;
    defaultEndpoint.host = ""; // Empty because we are using URL
    defaultEndpoint.port = 443;
    defaultEndpoint.url = "https://satadru-ghosh-cse28--depth-wizard-semantic-inference-sem-f82538.modal.run";
    defaultEndpoint.enabled = true;
    config.endpoints.push_back(defaultEndpoint);
    
    // Robust timeouts for Modal HTTP/2 inference
    config.connectTimeout = std::chrono::milliseconds(20000);
    config.sendTimeout = std::chrono::milliseconds(120000);
    config.receiveTimeout = std::chrono::milliseconds(300000);
    
    config.maxConcurrentRequests = 3;
    config.maxRetries = 3;
    
    return config;
}