#pragma once
#include <string>
#include <vector>

struct NdsmWorkerEndpoint
{
    std::string host;   // Kept for backward compatibility (can be empty if using url)
    int port;           // Kept for backward compatibility (can be 0 if using url)
    std::string url;    // NEW: Full Modal URL (e.g., "https://...modal.run")
    std::string workerId;
    bool enabled{true};
};

struct NdsmNetworkLimits 
{
    int connectTimeoutMs{5000};
    int sendTimeoutMs{15000};
    int receiveTimeoutMs{30000};
    int maxRetries{3};
    int maxConcurrentRequests{8}; // Strict bounded concurrency limit
};

struct NdsmModelExpectations 
{
    std::string expectedModelName{"model_a_metric_ndsm"};
    int expectedTileSize{518};
    
    // Physical limits to catch AI hallucinations and trigger tile failure
    float minAcceptableHeight{-50.0f};  // Pit/quarry limit
    float maxAcceptableHeight{9000.0f}; // Extreme mountain limit
};

struct NdsmStitchingConfig 
{
    bool hannWindowEnabled{true};
    float minimumEffectiveWeight{1e-6f};
    bool confidenceWeightingEnabled{true};
};

class NdsmInferenceConfig 
{
public:
    std::vector<NdsmWorkerEndpoint> endpoints;
    NdsmNetworkLimits network;
    NdsmModelExpectations model;
    NdsmStitchingConfig stitching;

    // Must be called once during service initialization
    [[nodiscard]] bool validate(std::vector<std::string>& outErrors) const;

    static NdsmInferenceConfig loadDefaults();
};