#pragma once
#include "CommonTypes.h"
#include <vector>
#include <string>
#include <cstdint>
#include <optional>

struct SceneInput 
{
      std::string jobId;
      std::string inputPath;
      PipelineMode inputMode{PipelineMode::GEOREFERENCED};
      int width{0};
      int height{0};
      std::vector<uint8_t> rgbTextureBytes;
      std::string textureMimeType; //"image/jpeg" or "image/png"
      std::optional<SpatialMetadata> spatialMetadata; //optional for non-geo inputs
      std::string sourceFormat;
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