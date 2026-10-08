#pragma once
#include "CommonTypes.h"
#include <cstddef>
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

// Parametric roof information produced by the C++ LoD2 fitting stage. These
// domain types intentionally avoid OpenCV objects so geometry can cross the
// reconstruction, meshing, diagnostics and serialization layers safely.
enum class RoofType : uint8_t
{
    FLAT,
    GABLE,
    HIP
};

struct RoofParameters
{
    RoofType type{RoofType::FLAT};
    float eaveHeightAboveGround{0.0f};
    float ridgeHeightAboveGround{0.0f};
    PixelPoint ridgeStartPixel;
    PixelPoint ridgeEndPixel;
    ProjectedPoint ridgeStartProjected;
    ProjectedPoint ridgeEndProjected;
    float confidence{0.0f};
};

struct DecomposedBuildingBlock
{
    // Four corners, open and counter-clockwise in projected coordinates.
    std::array<PixelPoint, 4> pixelCorners;
    std::array<ProjectedPoint, 4> projectedCorners;
    RoofParameters roof;
    float footprintAreaSquareMetres{0.0f};
};

// Arbitrary building surface from an external reconstruction expert
// (City3D), validated before it is attached. Vertices are metric projected
// coordinates (easting, northing, elevation in the source CRS); triangle
// indices are grouped by role. Heights stay metric: the mesher applies the
// scene's render height scale exactly as it does for native buildings.
struct ProjectedVertex3D
{
    double easting{0.0};
    double northing{0.0};
    double elevation{0.0};
};

struct BuildingSurfaceShell
{
    std::vector<ProjectedVertex3D> vertices;
    std::vector<uint32_t> roofIndices;  // Triangles
    std::vector<uint32_t> wallIndices;  // Triangles
    std::string source{"city3d"};
    float renderHeightScale{1.0f};      // Render height = metric height above base x scale
};

struct BuildingInstance 
{
    uint32_t buildingId{0};
    FootprintPolygon<PixelPoint> pixelFootprint;           
    FootprintPolygon<ProjectedPoint> projectedFootprint;   
    
    BaseElevationModel baseModel{BaseElevationModel::FLAT}; // Explicit model
    
    float representativeBaseElevation{0.0f};
    std::optional<GroundPlane> groundPlane;                
    // One DTM elevation per outer-ring vertex. Empty means use the
    // representative flat base.
    std::vector<float> baseElevationPerVertex;
    
    float roofElevation{0.0f}; // Assumes flat roof
    float heightAboveGround{0.0f};
    float footprintAreaSquareMetres{0.0f};
    float semanticConfidence{0.0f};
    float heightConfidence{0.0f};
    std::vector<DecomposedBuildingBlock> blocks;
    // Validated expert shell; when present the mesher prefers it over blocks
    // and footprint extrusion. Heights and footprints above stay authoritative.
    std::optional<BuildingSurfaceShell> reconstructedShell;
    std::vector<std::string> geometryWarnings;
};

struct BuildingCollection 
{
    std::vector<BuildingInstance> buildings;

    // Reconstruction-stage diagnostics. These are data, not a separate
    // report file, so the orchestrator can log and expose them consistently.
    std::size_t semanticCandidateCount{0};
    std::size_t recoveredCandidatePixelCount{0};
    std::size_t componentRejectedCount{0};
    std::size_t vectorizationRejectedCount{0};
    std::size_t physicsRejectedCount{0};
    std::size_t lod2BlockCount{0};
    std::size_t flatRoofBlockCount{0};
    std::size_t gableRoofBlockCount{0};
    std::size_t hipRoofBlockCount{0};
};
