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
      std::optional<SpatialMetadata> spatialMetadata; //optional for non-geo inputs[cite: 8]
      std::string sourceFormat;
};

struct ImageQualityResult 
{
      ImageTensor normalizedRgbTensor; //img tensor instead of raw vector
      RasterGrid<uint8_t> validPixelMask;
      RasterGrid<uint8_t> cloudMask;
      RasterGrid<uint8_t> shadowMask;
      RasterGrid<uint8_t> saturationMask;
      float qualityScore{1.0f};
      std::vector<std::string> warnings;
};