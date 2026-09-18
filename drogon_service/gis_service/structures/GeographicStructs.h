#pragma once
#include "CommonTypes.h"
#include <optional>
#include <cstdint>
#include <vector>

// Strongly typed semantic IDs
enum class SemanticClass : uint8_t 
{
      UNKNOWN = 0, 
      GROUND = 1, 
      BUILDING = 2, 
      ROAD = 3, 
      VEGETATION = 4, 
      WATER = 5
};

enum class BaseElevationModel 
{
      FLAT,
      GROUND_PLANE,
      PER_VERTEX
};

struct SemanticScene 
{
    RasterGrid<float> groundProbability;
    RasterGrid<float> buildingProbability;
    RasterGrid<float> roadProbability;
    RasterGrid<float> vegetationProbability;
    RasterGrid<float> waterProbability;
    RasterGrid<float> unknownProbability;
    RasterGrid<SemanticClass> finalClassMap; // Explicit enum usage
    RasterGrid<float> semanticConfidence;
};

// Polygon representation supporting inner courtyards/holes
template <typename PointT>
struct FootprintPolygon 
{
    std::vector<PointT> outerRing; // Invariant: CCW winding, OPEN (no duplicate end point)
    std::vector<std::vector<PointT>> holes; // Invariant: CW winding, OPEN
};

struct GroundPlane 
{
    float a{0.0f};
    float b{0.0f};
    float c{0.0f};
};

struct BuildingInstance 
{
    uint32_t buildingId{0};
    FootprintPolygon<PixelPoint> pixelFootprint;           
    FootprintPolygon<ProjectedPoint> projectedFootprint;   
    
    BaseElevationModel baseModel{BaseElevationModel::FLAT}; // Explicit model
    
    float representativeBaseElevation{0.0f};
    std::optional<GroundPlane> groundPlane;                
    std::vector<float> baseElevationPerVertex;             
    
    float roofElevation{0.0f}; // Assumes flat roof
    float heightAboveGround{0.0f};
    float footprintAreaSquareMetres{0.0f};
    float semanticConfidence{0.0f};
    float heightConfidence{0.0f};
    std::vector<std::string> geometryWarnings;
};

struct BuildingCollection 
{
    std::vector<BuildingInstance> buildings;
};