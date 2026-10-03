#include "TerrainSurfaceComposer.h"

#include <opencv2/imgproc.hpp>

#include <algorithm>
#include <cmath>
#include <stdexcept>
#include <vector>

RasterGrid<uint8_t> TerrainSurfaceComposer::buildAcceptedBuildingMask(
    const BuildingCollection& buildings,
    const SpatialMetadata& metadata,
    float clearanceMetres)
{
    if (metadata.width <= 0 || metadata.height <= 0 ||
        !std::isfinite(clearanceMetres) || clearanceMetres < 0.0f)
    {
        throw std::invalid_argument(
            "TerrainSurfaceComposer: invalid raster dimensions or clearance");
    }

    const double columnResolution = std::hypot(
        metadata.geoTransform[1], metadata.geoTransform[4]);
    const double rowResolution = std::hypot(
        metadata.geoTransform[2], metadata.geoTransform[5]);
    if (!std::isfinite(columnResolution) || columnResolution <= 0.0 ||
        !std::isfinite(rowResolution) || rowResolution <= 0.0)
    {
        throw std::invalid_argument(
            "TerrainSurfaceComposer: invalid affine pixel resolution");
    }

    cv::Mat acceptedMask(
        metadata.height, metadata.width, CV_8UC1, cv::Scalar(0));

    const auto toCvRing = [](const std::vector<PixelPoint>& ring)
    {
        std::vector<cv::Point> converted;
        converted.reserve(ring.size());
        for (const PixelPoint& point : ring)
        {
            converted.emplace_back(
                static_cast<int>(std::lround(point.column)),
                static_cast<int>(std::lround(point.row)));
        }
        return converted;
    };

    for (const BuildingInstance& building : buildings.buildings)
    {
        if (building.pixelFootprint.outerRing.size() < 3)
        {
            continue;
        }

        // Rasterize each building independently. This prevents a courtyard
        // in one footprint from erasing an overlapping accepted building.
        cv::Mat buildingMask(
            metadata.height, metadata.width, CV_8UC1, cv::Scalar(0));
        const std::vector<cv::Point> outer =
            toCvRing(building.pixelFootprint.outerRing);
        cv::fillPoly(
            buildingMask,
            std::vector<std::vector<cv::Point>>{outer},
            cv::Scalar(255));

        for (const std::vector<PixelPoint>& hole :
             building.pixelFootprint.holes)
        {
            if (hole.size() < 3)
            {
                continue;
            }
            const std::vector<cv::Point> convertedHole = toCvRing(hole);
            cv::fillPoly(
                buildingMask,
                std::vector<std::vector<cv::Point>>{convertedHole},
                cv::Scalar(0));
        }

        cv::bitwise_or(acceptedMask, buildingMask, acceptedMask);
    }

    if (clearanceMetres > 0.0f && cv::countNonZero(acceptedMask) > 0)
    {
        const int radiusX = std::max(
            1,
            static_cast<int>(std::ceil(
                clearanceMetres / columnResolution)));
        const int radiusY = std::max(
            1,
            static_cast<int>(std::ceil(clearanceMetres / rowResolution)));
        const cv::Mat kernel = cv::getStructuringElement(
            cv::MORPH_ELLIPSE,
            cv::Size(radiusX * 2 + 1, radiusY * 2 + 1));
        cv::dilate(acceptedMask, acceptedMask, kernel);
    }

    RasterGrid<uint8_t> result;
    result.width = metadata.width;
    result.height = metadata.height;
    result.data.resize(
        static_cast<std::size_t>(metadata.width) * metadata.height);

    for (int row = 0; row < metadata.height; ++row)
    {
        const uint8_t* source = acceptedMask.ptr<uint8_t>(row);
        uint8_t* destination =
            result.data.data() + static_cast<std::size_t>(row) * metadata.width;
        for (int column = 0; column < metadata.width; ++column)
        {
            destination[column] = source[column] == 0 ? 0 : 1;
        }
    }

    return result;
}

RasterGrid<uint8_t> TerrainSurfaceComposer::buildExactFootprintMask(
    const BuildingCollection& buildings,
    const SpatialMetadata& metadata)
{
    if (metadata.width <= 0 || metadata.height <= 0)
    {
        throw std::invalid_argument(
            "TerrainSurfaceComposer: invalid raster dimensions");
    }

    RasterGrid<uint8_t> result;
    result.width = metadata.width;
    result.height = metadata.height;
    result.data.assign(
        static_cast<std::size_t>(metadata.width) * metadata.height, 0);

    std::vector<double> crossings;
    for (const BuildingInstance& building : buildings.buildings)
    {
        const FootprintPolygon<PixelPoint>& footprint = building.pixelFootprint;
        if (footprint.outerRing.size() < 3) continue;

        std::vector<const std::vector<PixelPoint>*> rings{&footprint.outerRing};
        for (const auto& hole : footprint.holes)
            if (hole.size() >= 3) rings.push_back(&hole);

        double minRow = footprint.outerRing.front().row;
        double maxRow = minRow;
        for (const PixelPoint& point : footprint.outerRing)
        {
            minRow = std::min(minRow, point.row);
            maxRow = std::max(maxRow, point.row);
        }
        const int firstRow = std::max(0, static_cast<int>(std::floor(minRow - 0.5)));
        const int lastRow = std::min(metadata.height - 1, static_cast<int>(std::ceil(maxRow - 0.5)));

        for (int row = firstRow; row <= lastRow; ++row)
        {
            const double y = row + 0.5;
            crossings.clear();
            for (const auto* ring : rings)
            {
                for (std::size_t index = 0; index < ring->size(); ++index)
                {
                    const PixelPoint& a = (*ring)[index];
                    const PixelPoint& b = (*ring)[(index + 1) % ring->size()];
                    // Half-open rule: an edge counts when y is in [min, max).
                    if ((a.row <= y) != (b.row <= y))
                        crossings.push_back(a.column + (y - a.row) * (b.column - a.column) / (b.row - a.row));
                }
            }
            std::sort(crossings.begin(), crossings.end());
            uint8_t* destination = result.data.data() + static_cast<std::size_t>(row) * metadata.width;
            for (std::size_t pair = 0; pair + 1 < crossings.size(); pair += 2)
            {
                // Pixel centres x = column + 0.5 with left <= x < right.
                const int first = std::max(0, static_cast<int>(std::ceil(crossings[pair] - 0.5)));
                const int last = std::min(metadata.width - 1,
                                          static_cast<int>(std::ceil(crossings[pair + 1] - 0.5)) - 1);
                for (int column = first; column <= last; ++column) destination[column] = 1;
            }
        }
    }
    return result;
}
