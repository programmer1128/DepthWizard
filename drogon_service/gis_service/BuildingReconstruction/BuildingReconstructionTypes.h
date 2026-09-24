#pragma once
#include "../structures/GeographicStructs.h"
#include <vector>
#include <string>
#include <cstdint>
#include <cmath>



struct BuildingMaskResult 
{
    bool success{false};
    std::string errorMessage;
    RasterGrid<uint8_t> cleanMask;
    int smallComponentRejectedPixelCount{0};
    int recoveredCandidatePixelCount{0};
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
    int32_t componentId{0};          // Standardized to int32_t
    int pixelCount{0};                
    PixelBoundingBox pixelBoundingBox;
    PixelPoint centroid;              
    double physicalAreaSquareMetres{0.0}; 
    float meanBuildingProbability{0.0f}; 
    float minSemanticConfidence{0.0f};
    float meanSemanticConfidence{0.0f};
    int32_t _originalLabel{0};       // Standardized to int32_t
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


// Add to BuildingReconstructionTypes.h

struct FootprintVectorizationResult 
{
    bool success{false};
    std::string errorMessage;
    
    FootprintPolygon<PixelPoint> pixelFootprint;
    FootprintPolygon<ProjectedPoint> projectedFootprint;
    
    std::vector<std::string> warnings;
};



struct BuildingHeightEstimate 
{
     bool success{false};
     std::string errorMessage;
     
     float representativeBaseElevation{0.0f};
     float heightAboveGround{0.0f};
     float roofElevation{0.0f};
     float footprintElevationDeltaMetres{0.0f};

     // DTM sampled at each outer-footprint vertex. This lets the wall mesh
     // follow terrain locally instead of ending at one median elevation.
     std::vector<float> baseElevationPerOuterVertex;
    
     int validRoofSampleCount{0};
     int validGroundSampleCount{0};
     float confidence{0.0f};
     
     std::vector<std::string> warnings;
};
