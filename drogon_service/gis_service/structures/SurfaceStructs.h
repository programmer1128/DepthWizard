#pragma once
#include "CommonTypes.h"
#include <optional>
#include <cstdint>

// Separated contracts
struct GeoreferencedSurfaceBundle 
{
    SpatialMetadata spatialMetadata; // One authoritative object
    RasterGrid<float> dtm;
    RasterGrid<float> dsm;
    RasterGrid<float> ndsm;
    RasterGrid<float> surfaceConfidence;
    RasterGrid<uint8_t> validMask;
    ElevationUnit elevationUnit{ElevationUnit::METERS}; 
    // Mutable isConsistent removed; validation moved to QualityControlService
};

struct RelativeSurfaceBundle 
{
    RasterGrid<float> relativeSurface;
    RasterGrid<float> normalizedRelativeHeight;
    RasterGrid<float> surfaceConfidence;
    RasterGrid<uint8_t> validMask;
};

struct RasterProductSet 
{
    SpatialMetadata spatialMetadata; // Needed for TiffExporter
    
    RasterGrid<float> dsm;
    RasterGrid<float> dtm;
    RasterGrid<float> ndsm;
    
    RasterGrid<float> slope;
    std::string slopeUnits{"DEGREES"}; // Export semantics
    
    RasterGrid<float> aspect;
    std::string aspectConvention{"CLOCKWISE_FROM_NORTH"}; // Export semantics
    
    RasterGrid<float> hillshade;
    float sunAzimuth{315.0f};     // Export semantics
    float sunElevation{45.0f};    // Export semantics
    
    std::optional<RasterGrid<float>> canopyHeight;
    RasterGrid<float> confidence;
    
    float noDataValue{-9999.0f};  // Explicit NoData representation
    RasterGrid<uint8_t> validMask;
    ElevationUnit elevationUnit{ElevationUnit::METERS};
};