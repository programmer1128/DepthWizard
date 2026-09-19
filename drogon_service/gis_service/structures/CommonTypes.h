#pragma once

#include <vector>
#include <string>
#include <array>
#include <stdexcept>
#include <cstdint>

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

struct AxisAlignedBounds
{
      double minX{0.0}, minY{0.0}, minZ{0.0};
      double maxX{0.0}, maxY{0.0}, maxZ{0.0};
      bool isInitialized{false};
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

      // added
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