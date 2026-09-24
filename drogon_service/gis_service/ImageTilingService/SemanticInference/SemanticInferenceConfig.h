#pragma once

#include <string>
#include <vector>
#include <chrono>
#include <cstdint>
#include <stdexcept>

struct SemanticWorkerEndpoint {
    std::string host{"127.0.0.1"};
    uint16_t port{9093}; // Note: Different port than nDSM (9092)
    bool enabled{true};
};

class SemanticInferenceConfig {
public:
    // Network & Worker Pool
    std::vector<SemanticWorkerEndpoint> endpoints;
    int maxConcurrentRequests{4};
    int maxRetries{3};

    // Timeouts
    std::chrono::milliseconds connectTimeout{2000};
    std::chrono::milliseconds sendTimeout{5000};
    std::chrono::milliseconds receiveTimeout{15000};

    // Model Expectations
    std::string expectedModelName{"DepthAnythingV2-Semantic"};
    std::vector<std::string> acceptedVersions{"1.0"};
    uint32_t expectedProtocolVersion{1};
    uint32_t expectedTileSize{518};
    uint32_t expectedClassCount{6}; // Ground, Building, Road, Vegetation, Water, Unknown

    // Stitching Configuration
    bool hannWindowEnabled{true};
    float minEffectiveWeight{0.01f};

    // Methods
    void validate() const;
    
    // Optional: A helper to load defaults or read from a JSON config file
    static SemanticInferenceConfig loadDefaults();
};