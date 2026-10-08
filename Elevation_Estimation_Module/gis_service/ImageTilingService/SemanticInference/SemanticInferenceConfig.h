#pragma once
#include <string>
#include <vector>
#include <chrono>
#include <cstdint>
#include <stdexcept>

struct SemanticWorkerEndpoint {
    std::string host{"127.0.0.1"};
    uint16_t port{9093}; 
    std::string url;     // NEW: Full Modal URL (e.g., "https://...modal.run")
    bool enabled{true};
};

class SemanticInferenceConfig {
public:
    // Network & Worker Pool
    std::vector<SemanticWorkerEndpoint> endpoints;
    int maxConcurrentRequests{4};
    int maxRetries{3};
    
    // Timeouts
    std::chrono::milliseconds connectTimeout{20000};
    std::chrono::milliseconds sendTimeout{120000};
    std::chrono::milliseconds receiveTimeout{300000};
    
    // Model Expectations
    std::string expectedModelName{"DepthAnythingV2-Semantic"};
    std::vector<std::string> acceptedVersions{"1.0"};
    uint32_t expectedProtocolVersion{1};
    uint32_t expectedTileSize{518};
    
    // Deployed ONNX order: other, ground, low vegetation, building, water, road.
    uint32_t expectedClassCount{6};
    
    // Stitching Configuration
    bool hannWindowEnabled{true};
    float minEffectiveWeight{0.01f};
    
    // Methods
    void validate() const;
    static SemanticInferenceConfig loadDefaults();
};