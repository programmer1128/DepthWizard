#pragma once
#include "../structures/GeographicStructs.h"
#include <vector>
#include <string>
#include <cstdint>
#include <cmath>

struct BuildingReconstructionConfig
{
    float buildingProbabilityThreshold{0.5f};
    float openingRadiusMetres{2.0f};
    float closingRadiusMetres{3.0f};
    float minBuildingAreaSquareMetres{20.0f};
    int connectivity{4};
    float footprintSimplificationToleranceMetres{0.5f};

    bool validate() const
    {
        return std::isfinite(buildingProbabilityThreshold) && buildingProbabilityThreshold >= 0.0f && buildingProbabilityThreshold <= 1.0f &&
               std::isfinite(openingRadiusMetres) && openingRadiusMetres >= 0.0f &&
               std::isfinite(closingRadiusMetres) && closingRadiusMetres >= 0.0f &&
               std::isfinite(minBuildingAreaSquareMetres) && minBuildingAreaSquareMetres >= 0.0f &&
               std::isfinite(footprintSimplificationToleranceMetres) && footprintSimplificationToleranceMetres >= 0.0f &&
               (connectivity == 4 || connectivity == 8);
    }
};

struct BuildingMaskResult
{
    bool success{false};
    std::string errorMessage;
    RasterGrid<uint8_t> cleanMask;
    int smallComponentRejectedPixelCount{0};
    float thresholdUsed{0.0f};
    int openingKernelWidth{0};
    int openingKernelHeight{0};
    int closingKernelWidth{0};
    int closingKernelHeight{0};
    std::vector<std::string> warnings;
};

struct PixelBoundingBox
{
    int x{0};
    int y{0};
    int width{0};
    int height{0};
};

struct ComponentStats
{
    int32_t componentId{0}; // Standardized to int32_t
    int pixelCount{0};
    PixelBoundingBox pixelBoundingBox;
    PixelPoint centroid;
    double physicalAreaSquareMetres{0.0};
    float meanBuildingProbability{0.0f};
    float minSemanticConfidence{0.0f};
    float meanSemanticConfidence{0.0f};
    int32_t _originalLabel{0}; // Standardized to int32_t
};

struct ComponentExtractionResult
{
    bool success{false};
    std::string errorMessage;
    RasterGrid<int32_t> labelRaster; // Standardized to int32_t
    std::vector<ComponentStats> components;
    int acceptedComponentCount{0};
    int rejectedComponentCount{0};
    std::vector<std::string> warnings;
};