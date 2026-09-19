#pragma once
#include "CommonTypes.h"
#include <vector>
#include <cstdint>
#include <optional>

struct ModelMetadata 
{
    std::string modelName;
    std::string modelVersion;
};

struct ModelCollection 
{
    ModelMetadata nDsmModel;       
    ModelMetadata semanticModel;   
};

struct SemanticLogits 
{
    RasterGrid<float> groundLogits;
    RasterGrid<float> buildingLogits;
    RasterGrid<float> roadLogits;
    RasterGrid<float> vegetationLogits;
    RasterGrid<float> waterLogits;
    RasterGrid<float> unknownLogits; 
    int classCount{6};         
    TensorLayout layout{TensorLayout::CHW};
};

// Explicit placement contract for boundary padding and stitching
struct TilePlacement 
{
    int sourceX{0};
    int sourceY{0};
    int paddedWidth{0};
    int paddedHeight{0};
    int validStartX{0};
    int validStartY{0};
    int validWidth{0};
    int validHeight{0};
};

struct TileInferenceResult 
{
    uint32_t tileId{0};
    TilePlacement placement;      // Replaces raw offsets
    RasterGrid<float> metricNdsm; 
    SemanticLogits semanticLogits;
    RasterGrid<float> ndsmConfidence; // Renamed for clarity
    RasterGrid<uint8_t> validMask;
    // ModelCollection removed from here to prevent redundancy
};

struct InferenceBundle 
{
    RasterGrid<float> globalNdsm;
    SemanticLogits globalSemanticLogits;
    RasterGrid<float> globalNdsmConfidence; 
    RasterGrid<uint8_t> globalValidMask;
    ModelCollection models; 
};