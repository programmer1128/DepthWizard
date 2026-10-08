#pragma once
#include "BuildingReconstructionConfig.h"
#include "../structures/GeographicStructs.h"

// Constrained marker flooding: split only components with multiple sizeable
// high-probability roof cores separated by probability or height evidence.
// Every input pixel receives exactly one label. Unsupported blocks stay whole.
class BuildingInstanceSplitter
{
public:
    static RasterGrid<int32_t> label(
        const RasterGrid<uint8_t>& mask, const SemanticScene& semantics,
        const RasterGrid<float>* ndsm, double pixelArea,
        const BuildingReconstructionConfig& config,
        const RasterGrid<uint8_t>* opticalGray = nullptr);
};
