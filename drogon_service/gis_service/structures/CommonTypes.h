#pragma once

#include <vector>
#include <string>
#include <array>
#include <stdexcept>
#include <cstdint>
#include <algorithm>

enum class PipelineMode 
{ 
      GEOREFERENCED, 
      RELATIVE 
};

enum class JobStatus 
{ 
      QUEUED, 
      PROCESSING, 
      READY, 
      FAILED 
};

enum class PipelineStatus 
{ 
      SUCCESS, 
      WARNING, 
      FATAL_ERROR 
};


enum class QualityStatus 
{ 
      PASS, 
      WARN, 
      FAIL 
};

enum class ElevationUnit 
{ 
      METERS, 
      FEET, 
      UNKNOWN 
};

enum class TensorLayout 
{ 
      CHW, 
      HWC 
};

enum class ColorOrder 
{ 
      RGB, 
      BGR, 
      GRAYSCALE 
};

struct LocalSceneFrame 
{
    double projectedOriginX{0.0};
    double projectedOriginY{0.0};
    double elevationOrigin{0.0};
    std::string horizontalCrs;
    std::string axisConvention{"Y-UP_RIGHT-HANDED"};
};

struct AxisAlignedBounds 
{
    double minX{0.0}, minY{0.0}, minZ{0.0};
    double maxX{0.0}, maxY{0.0}, maxZ{0.0};
    bool isInitialized{false};

    void expand(double x, double y, double z)
    {
        if (!isInitialized)
        {
            minX = maxX = x;
            minY = maxY = y;
            minZ = maxZ = z;
            isInitialized = true;
        }
        else
        {
            minX = std::min(minX, x);
            minY = std::min(minY, y);
            minZ = std::min(minZ, z);
            maxX = std::max(maxX, x);
            maxY = std::max(maxY, y);
            maxZ = std::max(maxZ, z);
        }
    }
};

template <typename T>
struct RasterGrid 
{
      int width{0};
      int height{0};
      std::vector<T> data;
    
      // Invariant: data size must exactly match grid dimensions
      bool isValid() const 
      { 
           return width > 0 && height > 0 && 
           data.size() == static_cast<std::size_t>(width) * static_cast<std::size_t>(height); 
      }
};

struct ImageTensor 
{
      int width{0};
      int height{0};
      int channels{3};
      TensorLayout layout{TensorLayout::CHW};
      ColorOrder colorOrder{ColorOrder::RGB};
      std::string normalizationId;
      std::vector<float> data;
};

// Authoritative metadata object
struct SpatialMetadata 
{
      int width{0};
      int height{0};
      std::array<double, 6> geoTransform{0.0, 1.0, 0.0, 0.0, 0.0, -1.0};
      std::string projectionRef{""};
      double pixelSizeX{0.0};
      double pixelSizeY{0.0};
      std::string verticalDatum{""};
      bool isGeoreferenced{false};
       double gsd{1.0};
};

// Explicit geometric coordinate concepts to prevent CRS mix-ups
struct PixelPoint 
{ 
      double column{0.0}; 
      double row{0.0}; 
};

struct ProjectedPoint 
{ 
      double easting{0.0}; 
      double northing{0.0}; 
};

struct LocalPoint 
{ 
      double x{0.0}; 
      double z{0.0}; 
};