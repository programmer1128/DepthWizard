#pragma once

#include "CommonTypes.h"
#include "InferenceStructs.h" // Assuming SemanticLogits & ModelMetadata live here
#include <vector>
#include <cstdint>
#include <string>
#include "GeographicStructs.h"

#include <array>
#include <cstddef>

/**
 * @brief The result of a single tile processed by the semantic segmentation model.
 */
struct SemanticTileResult {
    uint32_t tileId{0};
    TilePlacement placement;
    uint32_t semanticSchemaId{DEPTHWIZARD_SEMANTIC_SCHEMA_ID};
    // The multi-channel raw neural network scores (e.g., 6 channels)
    SemanticLogits semanticLogits;       
    
    RasterGrid<float> confidence;
    RasterGrid<uint8_t> validMask;
    
    // Invariants:
    // 1. All grids (each channel in logits, confidence, mask) must exactly match the padded tile dimensions.
    // 2. Logits are unbounded floats (negative or positive).
    // 3. Confidence must be finite and within [0, 1].
    // 4. Valid mask is strictly 0 (invalid) or 1 (valid).
    // 5. If mask == 0, confidence must be 0, and logits should ideally be NaN or ignored.
};

/**
 * @brief The collection of all semantic tiles before stitching.
 */
struct SemanticTiledPayload {
    uint32_t globalWidth{0};
    uint32_t globalHeight{0};
    ModelMetadata model;
    
    std::vector<SemanticTileResult> tiles;
    
    // Operational diagnostics (strictly for logging/monitoring, not math)
    uint32_t successfulTileCount{0};
    std::vector<uint32_t> failedTileIds;
};

/**
 * @brief The final, fully stitched output of the semantic branch.
 * This is the ONLY object returned to the Pipeline Coordinator.
 */
struct SemanticInferenceBundle {
    uint32_t semanticSchemaId{DEPTHWIZARD_SEMANTIC_SCHEMA_ID};
    SemanticLogits globalSemanticLogits;
    RasterGrid<float> globalConfidence;
    RasterGrid<uint8_t> globalValidMask;
    
    ModelMetadata model;
    
    // Invariants:
    // 1. All grids must exactly match scene.width x scene.height.
    // 2. No padding exists in these grids.
};



inline constexpr uint32_t DEPTHWIZARD_SEMANTIC_SCHEMA_ID = 1;

inline constexpr std::array<SemanticClass, 6>
    DEPTHWIZARD_SEMANTIC_CHANNEL_ORDER = {
        SemanticClass::UNKNOWN,
        SemanticClass::GROUND,
        SemanticClass::BUILDING,
        SemanticClass::ROAD,
        SemanticClass::VEGETATION,
        SemanticClass::WATER
    };

enum class SemanticChannel : std::size_t
{
    UNKNOWN = 0,
    GROUND = 1,
    BUILDING = 2,
    ROAD = 3,
    VEGETATION = 4,
    WATER = 5
};