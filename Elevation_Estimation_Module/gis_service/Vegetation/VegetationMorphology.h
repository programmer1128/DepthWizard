#pragma once
#include "VegetationTypes.h"

#include <opencv2/imgproc.hpp>

#include <algorithm>
#include <cmath>

// Metric structuring elements and areas, converted per raster axis.
namespace depthwizard::vegetation
{

// Elliptical structuring element covering `metres` along each raster axis.
// Empty when the radius is below half a pixel on both axes. With
// `atLeastNeighbours`, it never shrinks below the 3x3 neighbourhood.
inline cv::Mat metricEllipse(double metres, const VegetationPixelScale& scale, bool atLeastNeighbours = false)
{
     int rx = static_cast<int>(std::lround(metres / scale.columnSpacingMetres));
     int ry = static_cast<int>(std::lround(metres / scale.rowSpacingMetres));
     if (atLeastNeighbours)
     {
          rx = std::max(rx, 1);
          ry = std::max(ry, 1);
     }
     if (rx <= 0 && ry <= 0) return {};
     return cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(2 * rx + 1, 2 * ry + 1));
}

// Pixel count equivalent of an area, never below `floor` pixels.
inline int pixelsForArea(double squareMetres, const VegetationPixelScale& scale, int floor)
{
     return std::max(floor, static_cast<int>(std::ceil(squareMetres / scale.pixelAreaSquareMetres() - 1e-9)));
}

} // namespace depthwizard::vegetation
