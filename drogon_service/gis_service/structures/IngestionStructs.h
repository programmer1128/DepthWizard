#pragma once
#include "CommonTypes.h"
#include <vector>
#include <string>
#include <cstdint>

struct SceneInput 
{
     std::string jobId;
     std::string inputPath;
     PipelineMode inputMode;
     int width;
     int height;
     std::vector<uint8_t> rgbTextureBytes;
     SpatialMetadata spatialMetadata;
     std::string sourceFormat;
     std::string originalFileMetadata;
};


struct ImageQualityResult 
{
     //3 channels (RGB) flattened specific tensor format
     std::vector<float> normalizedRgbRaster; 
     RasterGrid<uint8_t> validPixelMask;
     RasterGrid<uint8_t> cloudMask;
     RasterGrid<uint8_t> shadowMask;
     RasterGrid<uint8_t> saturationMask;
     float qualityScore;
     std::vector<std::string> warnings;
};