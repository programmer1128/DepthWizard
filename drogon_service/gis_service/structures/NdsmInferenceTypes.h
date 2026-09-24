#pragma once
#include "CommonTypes.h"
#include "InferenceStructs.h" // Supplies TilePlacement and ModelMetadata
#include <vector>
#include <cstdint>

// Represents the isolated output of exactly one 518x518 tile from Model A
struct NdsmTileResult 
{
    uint32_t tileId{0};
    TilePlacement placement;
    
    // Extracted from ONNX Model A output tensor [1, 2, 518, 518] (Channel Index 0)
    RasterGrid<float> metricNdsm; 
    
    // Extracted from ONNX Model A output tensor [1, 2, 518, 518] (Channel Index 1)
    RasterGrid<float> ndsmConfidence; 
    
    // Intersection of the preprocessing validity mask and worker validity
    RasterGrid<uint8_t> validMask;
};

// Represents the collection of all height tiles before stitching
struct NdsmTiledPayload 
{
    int globalWidth{0};
    int globalHeight{0};
    ModelMetadata model; 
    
    std::vector<NdsmTileResult> tiles;
    
    // Diagnostics for observability (Ignored by math, useful for logs)
    int successfulTileCount{0};
    int failedTileCount{0};
    int retriedTileCount{0};
};

// Represents the final branch output to be exposed to the dual-model coordinator
struct NdsmInferenceBundle 
{
    RasterGrid<float> globalMetricNdsm;
    RasterGrid<float> globalNdsmConfidence;
    RasterGrid<uint8_t> globalValidMask;
    
    ModelMetadata model;
};