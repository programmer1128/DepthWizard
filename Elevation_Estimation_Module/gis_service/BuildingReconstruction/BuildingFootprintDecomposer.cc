#include "BuildingFootprintDecomposer.h"

#include <opencv2/imgproc.hpp>

#include <algorithm>
#include <array>
#include <cmath>
#include <cstddef>
#include <limits>
#include <vector>

namespace
{
struct IntegerRectangle
{
    int left{0};
    int top{0};
    int right{-1};
    int bottom{-1};
    int area{0};
};

IntegerRectangle largestForegroundRectangle(const cv::Mat& mask)
{
    IntegerRectangle best;
    std::vector<int> heights(static_cast<std::size_t>(mask.cols), 0);
    for (int row = 0; row < mask.rows; ++row)
    {
        const auto* pixels = mask.ptr<uint8_t>(row);
        for (int column = 0; column < mask.cols; ++column)
            heights[column] = pixels[column] != 0 ? heights[column] + 1 : 0;

        struct HistogramBar
        {
            int height;
            int startColumn;
        };
        std::vector<HistogramBar> stack;
        stack.reserve(static_cast<std::size_t>(mask.cols) + 1);
        for (int column = 0; column <= mask.cols; ++column)
        {
            const int currentHeight = column == mask.cols ? 0 : heights[column];
            int startColumn = column;
            while (!stack.empty() && stack.back().height > currentHeight)
            {
                const HistogramBar bar = stack.back();
                stack.pop_back();
                startColumn = bar.startColumn;
                const int width = column - bar.startColumn;
                const int area = bar.height * width;
                if (area > best.area)
                {
                    best.left = bar.startColumn;
                    best.right = column - 1;
                    best.bottom = row;
                    best.top = row - bar.height + 1;
                    best.area = area;
                }
            }
            if (column < mask.cols && currentHeight > 0 &&
                (stack.empty() || stack.back().height < currentHeight))
            {
                stack.push_back({currentHeight, startColumn});
            }
        }
    }
    return best;
}

ProjectedPoint toProjected(const PixelPoint& pixel,
                           const SpatialMetadata& metadata)
{
    return {
        metadata.geoTransform[0] + pixel.column * metadata.geoTransform[1] +
            pixel.row * metadata.geoTransform[2],
        metadata.geoTransform[3] + pixel.column * metadata.geoTransform[4] +
            pixel.row * metadata.geoTransform[5]};
}

double signedArea(const std::array<ProjectedPoint, 4>& corners)
{
    double twiceArea = 0.0;
    for (std::size_t index = 0; index < corners.size(); ++index)
    {
        const auto& current = corners[index];
        const auto& next = corners[(index + 1) % corners.size()];
        twiceArea += current.easting * next.northing -
            next.easting * current.northing;
    }
    return 0.5 * twiceArea;
}

std::vector<cv::Point> rasterRing(
    const std::vector<PixelPoint>& ring, int offsetX, int offsetY)
{
    std::vector<cv::Point> points;
    points.reserve(ring.size());
    for (const auto& point : ring)
        points.emplace_back(
            static_cast<int>(std::lround(point.column)) - offsetX,
            static_cast<int>(std::lround(point.row)) - offsetY);
    return points;
}
} // namespace

FootprintDecompositionResult BuildingFootprintDecomposer::decompose(
    const FootprintPolygon<PixelPoint>& footprint,
    const SpatialMetadata& metadata,
    const BuildingReconstructionConfig& config)
{
    FootprintDecompositionResult result;
    if (!config.validate() || footprint.outerRing.size() < 3 ||
        metadata.width <= 0 || metadata.height <= 0)
    {
        result.errorMessage = "Invalid footprint, metadata, or reconstruction configuration.";
        return result;
    }
    if (!footprint.holes.empty())
    {
        result.success = true;
        result.warnings.push_back(
            "Footprint retained as unified boundary to preserve continuous courtyard walls.");
        return result;
    }

    std::vector<cv::Point2f> outer;
    outer.reserve(footprint.outerRing.size());
    PixelPoint centre;
    for (const auto& point : footprint.outerRing)
    {
        outer.emplace_back(static_cast<float>(point.column),
                           static_cast<float>(point.row));
        centre.column += point.column;
        centre.row += point.row;
    }
    centre.column /= footprint.outerRing.size();
    centre.row /= footprint.outerRing.size();

    const cv::RotatedRect orientedBounds = cv::minAreaRect(outer);
    cv::Point2f box[4];
    orientedBounds.points(box);
    cv::Point2f direction = box[1] - box[0];
    if (cv::norm(box[2] - box[1]) > cv::norm(direction))
        direction = box[2] - box[1];
    const double directionLength = cv::norm(direction);
    if (!std::isfinite(directionLength) || directionLength < 1.0e-6)
    {
        result.errorMessage = "Footprint has no stable dominant orientation.";
        return result;
    }
    const double ux = direction.x / directionLength;
    const double uy = direction.y / directionLength;
    const double vx = -uy;
    const double vy = ux;

    auto toAligned = [&](const PixelPoint& point)
    {
        const double dx = point.column - centre.column;
        const double dy = point.row - centre.row;
        return cv::Point2d(dx * ux + dy * uy, dx * vx + dy * vy);
    };

    double minU = std::numeric_limits<double>::infinity();
    double maxU = -std::numeric_limits<double>::infinity();
    double minV = std::numeric_limits<double>::infinity();
    double maxV = -std::numeric_limits<double>::infinity();
    for (const auto& point : footprint.outerRing)
    {
        const auto aligned = toAligned(point);
        minU = std::min(minU, aligned.x);
        maxU = std::max(maxU, aligned.x);
        minV = std::min(minV, aligned.y);
        maxV = std::max(maxV, aligned.y);
    }
    constexpr int margin = 2;
    const int alignedWidth = std::max(
        1, static_cast<int>(std::ceil(maxU - minU)) + 2 * margin + 1);
    const int alignedHeight = std::max(
        1, static_cast<int>(std::ceil(maxV - minV)) + 2 * margin + 1);
    if (alignedWidth > metadata.width * 2 + 32 ||
        alignedHeight > metadata.height * 2 + 32)
    {
        result.errorMessage = "Aligned footprint extent is inconsistent with the raster.";
        return result;
    }

    auto alignedRing = [&](const std::vector<PixelPoint>& ring)
    {
        std::vector<cv::Point> points;
        points.reserve(ring.size());
        for (const auto& point : ring)
        {
            const auto aligned = toAligned(point);
            points.emplace_back(
                static_cast<int>(std::lround(aligned.x - minU)) + margin,
                static_cast<int>(std::lround(aligned.y - minV)) + margin);
        }
        return points;
    };

    cv::Mat sourceMask = cv::Mat::zeros(
        alignedHeight, alignedWidth, CV_8UC1);
    const auto alignedOuter = alignedRing(footprint.outerRing);
    cv::fillPoly(sourceMask,
        std::vector<std::vector<cv::Point>>{alignedOuter}, cv::Scalar(255));
    for (const auto& hole : footprint.holes)
    {
        const auto alignedHole = alignedRing(hole);
        cv::fillPoly(sourceMask,
            std::vector<std::vector<cv::Point>>{alignedHole}, cv::Scalar(0));
    }
    const int originalPixels = cv::countNonZero(sourceMask);
    if (originalPixels <= 0)
    {
        result.errorMessage = "Footprint rasterization produced an empty mask.";
        return result;
    }

    cv::Mat remaining = sourceMask.clone();
    int representedPixels = 0;
    auto fromAligned = [&](double column, double row)
    {
        const double u = column + minU - margin;
        const double v = row + minV - margin;
        return PixelPoint{
            centre.column + u * ux + v * vx,
            centre.row + u * uy + v * vy};
    };

    while (static_cast<int>(result.blocks.size()) < config.maxDecomposedBlocks)
    {
        const int pixelsLeft = cv::countNonZero(remaining);
        if (static_cast<double>(pixelsLeft) / originalPixels <=
            config.decompositionResidualRatio) break;

        const IntegerRectangle rectangle = largestForegroundRectangle(remaining);
        if (rectangle.area <= 0) break;

        DecomposedBuildingBlock block;
        block.pixelCorners = {
            fromAligned(rectangle.left, rectangle.top),
            fromAligned(rectangle.right + 1.0, rectangle.top),
            fromAligned(rectangle.right + 1.0, rectangle.bottom + 1.0),
            fromAligned(rectangle.left, rectangle.bottom + 1.0)};
        for (std::size_t index = 0; index < block.pixelCorners.size(); ++index)
            block.projectedCorners[index] =
                toProjected(block.pixelCorners[index], metadata);

        double area = signedArea(block.projectedCorners);
        if (area < 0.0)
        {
            std::reverse(block.pixelCorners.begin(), block.pixelCorners.end());
            std::reverse(block.projectedCorners.begin(), block.projectedCorners.end());
            area = -area;
        }
        if (!std::isfinite(area) ||
            area < config.minDecomposedBlockAreaSquareMetres)
            break;

        block.footprintAreaSquareMetres = static_cast<float>(area);
        result.blocks.push_back(block);
        representedPixels += rectangle.area;
        remaining(cv::Rect(
            rectangle.left,
            rectangle.top,
            rectangle.right - rectangle.left + 1,
            rectangle.bottom - rectangle.top + 1)).setTo(0);
    }

    result.coverageRatio = static_cast<float>(representedPixels) /
        static_cast<float>(originalPixels);
    if (result.blocks.empty())
    {
        result.errorMessage = "No supported rectangular block was found.";
        return result;
    }

    double minColumn = footprint.outerRing.front().column;
    double maxColumn = minColumn;
    double minRow = footprint.outerRing.front().row;
    double maxRow = minRow;
    for (const auto& point : footprint.outerRing)
    {
        minColumn = std::min(minColumn, point.column);
        maxColumn = std::max(maxColumn, point.column);
        minRow = std::min(minRow, point.row);
        maxRow = std::max(maxRow, point.row);
    }
    const int roiX = std::max(0, static_cast<int>(std::floor(minColumn)) - 2);
    const int roiY = std::max(0, static_cast<int>(std::floor(minRow)) - 2);
    const int roiRight = std::min(
        metadata.width, static_cast<int>(std::ceil(maxColumn)) + 3);
    const int roiBottom = std::min(
        metadata.height, static_cast<int>(std::ceil(maxRow)) + 3);
    cv::Mat observed = cv::Mat::zeros(
        roiBottom - roiY, roiRight - roiX, CV_8UC1);
    cv::Mat modeled = observed.clone();
    cv::fillPoly(observed,
        std::vector<std::vector<cv::Point>>{
            rasterRing(footprint.outerRing, roiX, roiY)},
        cv::Scalar(255));
    for (const auto& hole : footprint.holes)
        cv::fillPoly(observed,
            std::vector<std::vector<cv::Point>>{
                rasterRing(hole, roiX, roiY)},
            cv::Scalar(0));
    for (const auto& block : result.blocks)
    {
        std::vector<cv::Point> corners;
        corners.reserve(4);
        for (const auto& point : block.pixelCorners)
            corners.emplace_back(
                static_cast<int>(std::lround(point.column)) - roiX,
                static_cast<int>(std::lround(point.row)) - roiY);
        cv::fillConvexPoly(modeled, corners, cv::Scalar(255));
    }
    cv::Mat intersection;
    cv::Mat maskUnion;
    cv::bitwise_and(observed, modeled, intersection);
    cv::bitwise_or(observed, modeled, maskUnion);
    const int unionPixels = cv::countNonZero(maskUnion);
    result.maskIoU = unionPixels > 0
        ? static_cast<float>(cv::countNonZero(intersection)) / unionPixels
        : 0.0f;

    // A high area ratio can still hide a missing connector or narrow wing.
    // Keep the unified polygon if a coherent two-dimensional residual is
    // left outside every block; one-pixel raster fringes are tolerated.
    cv::Mat unmodeled;
    cv::bitwise_and(observed, ~modeled, unmodeled);
    cv::Mat residualLabels, residualStats, residualCentroids;
    const int residualComponents = cv::connectedComponentsWithStats(
        unmodeled, residualLabels, residualStats, residualCentroids,
        8, CV_32S);
    const int significantResidualPixels = std::max(
        8, static_cast<int>(std::ceil(0.025 * originalPixels)));
    bool missingWing = false;
    for (int i = 1; i < residualComponents; ++i)
        if (residualStats.at<int>(i, cv::CC_STAT_AREA) >=
                significantResidualPixels &&
            residualStats.at<int>(i, cv::CC_STAT_WIDTH) >= 2 &&
            residualStats.at<int>(i, cv::CC_STAT_HEIGHT) >= 2)
            missingWing = true;

    result.success = true;
    result.accepted = result.coverageRatio >=
            config.minDecompositionCoverage &&
        result.maskIoU >= config.minDecompositionMaskIoU &&
        !missingWing;
    if (!result.accepted)
    {
        result.warnings.push_back(
            "Footprint retained as unified boundary to preserve continuous wall topology.");
        result.blocks.clear();
    }
    else if (result.blocks.size() > 1)
    {
        result.warnings.push_back(
            "Footprint decomposed into supported orientation-aligned LoD2 blocks.");
    }
    return result;
}
