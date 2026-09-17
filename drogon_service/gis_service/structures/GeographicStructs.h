#pragma once
#include "CommonTypes.h"
#include <vector>
#include <cstdint>

struct SemanticScene 
{
     RasterGrid<float> groundProbability;
     RasterGrid<float> buildingProbability;
     RasterGrid<float> roadProbability;
     RasterGrid<float> vegetationProbability;
     RasterGrid<float> waterProbability;
     RasterGrid<float> unknownProbability;
     RasterGrid<uint8_t> finalClassMap;
     RasterGrid<float> semanticConfidence;
};

struct Point2D 
{
     double x;
     double y;
};

struct BuildingInstance 
{
     uint32_t buildingId;
     std::vector<Point2D> footprintPolygon;
     float baseElevation;
     float roofElevation;
     float heightAboveGround;
     float semanticConfidence;
     float heightConfidence;
     std::vector<std::string> geometryWarnings;
};

struct BuildingCollection 
{
     std::vector<BuildingInstance> buildings;
};