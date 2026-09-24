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
    RasterGrid<float> otherLogits;
    RasterGrid<float> groundLogits;
    RasterGrid<float> lowVegetationLogits;
    RasterGrid<float> buildingLogits;
    RasterGrid<float> waterLogits;
    RasterGrid<float> roadLogits;
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

struct TiledInferencePayload
{
    int globalWidth;
    int globalHeight;
    std::vector<TileInferenceResult> allTiles;
};


// struct to hold one 518x518 square of the image ready to be sent to the model

struct TileRequest 
{
    uint32_t tileId;       // unique number for this square
    int xOffset;           // distance from the left edge of the main image
    int yOffset;           // distance from the top edge of the main image
    int width;             // always 518
    int height;            // always 518

    // we must track the valid area so the stitcher knows what to ignore
    int validWidth;        
    int validHeight;
    
    // normalized colors (RGB) for the model
    std::vector<float> normalizedRgbBytes;
    
    // Binary usability map (1 = usable, 0 = cloud/saturation/padding/NoData).
    // Natural shadows remain usable geometry and are represented separately
    // by ImageQualityResult::shadowMask.
    std::vector<uint8_t> validMaskBytes;
};
