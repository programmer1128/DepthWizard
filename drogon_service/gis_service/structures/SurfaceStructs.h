#pragma once
#include "CommonTypes.h"
#include <optional>
#include <cstdint>

struct SurfaceBundle 
{
     RasterGrid<float> DTM;
     RasterGrid<float> DSM;
     RasterGrid<float> nDSM;
     std::optional<RasterGrid<float>> optionalCanopyHeight;
     RasterGrid<float> surfaceConfidence;
     RasterGrid<uint8_t> validMask;
     PipelineMode mode;
     std::string unitsDatumMetadata;
};

struct RasterProductSet 
{
     RasterGrid<float> DSM;
     RasterGrid<float> DTM;
     RasterGrid<float> nDSM;
     RasterGrid<float> slope;
     RasterGrid<float> aspect;
     RasterGrid<float> hillshade;
     std::optional<RasterGrid<float>> canopyHeight;
     RasterGrid<float> confidence;
};
