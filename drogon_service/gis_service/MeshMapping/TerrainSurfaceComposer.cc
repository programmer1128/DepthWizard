#include "TerrainSurfaceComposer.h"

#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/photo.hpp>

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
        
        // RECT used here to maintain sharp structural boundaries during mask expansion
        const cv::Mat kernel = cv::getStructuringElement(
            cv::MORPH_RECT,
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

std::vector<uint8_t> TerrainSurfaceComposer::inpaintBuildingTextures(
    const std::vector<uint8_t>& originalJpegBytes,
    const RasterGrid<uint8_t>& buildingMask,
    const SpatialMetadata& metadata)
{
    if (originalJpegBytes.empty() || !buildingMask.isValid()) 
    {
        return originalJpegBytes;
    }

    cv::Mat image = cv::imdecode(originalJpegBytes, cv::IMREAD_COLOR);
    if (image.empty() || image.cols != buildingMask.width || image.rows != buildingMask.height) 
    {
        return originalJpegBytes;
    }

    cv::Mat inpaintMask(buildingMask.height, buildingMask.width, CV_8UC1, 
                        const_cast<uint8_t*>(buildingMask.data.data()));

    // Dynamically calculate dilation kernel size based on a ~2-meter physical spread
    double colRes = std::hypot(metadata.geoTransform[1], metadata.geoTransform[4]);
    double rowRes = std::hypot(metadata.geoTransform[2], metadata.geoTransform[5]);
    
    int radiusX = (colRes > 0) ? std::max(1, static_cast<int>(std::ceil(2.0 / colRes))) : 5;
    int radiusY = (rowRes > 0) ? std::max(1, static_cast<int>(std::ceil(2.0 / rowRes))) : 5;

    cv::Mat expandedMask;
    cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(radiusX * 2 + 1, radiusY * 2 + 1));
    cv::dilate(inpaintMask, expandedMask, kernel);

    // Fast-marching Telea algorithm synthesizes surrounding dirt/grass over the roof
    cv::Mat inpaintedImage;
    cv::inpaint(image, expandedMask, inpaintedImage, 3.0, cv::INPAINT_TELEA);

    std::vector<uint8_t> resultBytes;
    cv::imencode(".jpg", inpaintedImage, resultBytes, {cv::IMWRITE_JPEG_QUALITY, 92});

    return resultBytes;
}