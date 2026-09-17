#pragma once
#include "CommonTypes.h"
#include <vector>
#include <cstdint>
#include <optional>

struct ModelMetadata 
{
     std::string modelName;
     std::string modelVersion;
     std::string outputType;
     std::string units;
};


struct TileInferenceResult 
{
     uint32_t tileId;
     int xOffset;
     int yOffset;
     int width;
     int height;
     std::vector<float> metricNdsm;
     std::optional<std::vector<float>> optionalRelativeDepth;
     std::vector<float> semanticLogits; // Multi-channel flattened
     std::vector<float> confidence;
     std::vector<uint8_t> validMask;
     ModelMetadata modelMetadata;
};


struct SemanticLogits 
{
     RasterGrid<float> groundLogits;
     RasterGrid<float> buildingLogits;
     RasterGrid<float> roadLogits;
     RasterGrid<float> vegetationLogits;
     RasterGrid<float> waterLogits;
};

struct InferenceBundle 
{
     RasterGrid<float> globalNdsm;
     std::optional<RasterGrid<float>> globalRelativeDepth;
     SemanticLogits globalSemanticLogits;
     RasterGrid<float> globalConfidence;
     RasterGrid<uint8_t> globalValidMask;
     ModelMetadata modelMetadata;
};