#include "BuildingRoofModeler.h"

#include <opencv2/imgproc.hpp>

#include <algorithm>
#include <cmath>
#include <cstddef>
#include <limits>
#include <numeric>
#include <vector>

namespace
{
float percentile(std::vector<float> samples, double quantile)
{
    if (samples.empty()) return 0.0f;
    const std::size_t index = static_cast<std::size_t>(std::clamp(
        quantile, 0.0, 1.0) * static_cast<double>(samples.size() - 1));
    std::nth_element(samples.begin(), samples.begin() + index, samples.end());
    return samples[index];
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

double distance(const PixelPoint& a, const PixelPoint& b)
{
    return std::hypot(b.column - a.column, b.row - a.row);
}

PixelPoint interpolate(const PixelPoint& a, const PixelPoint& b, double t)
{
    return {a.column + t * (b.column - a.column),
            a.row + t * (b.row - a.row)};
}

// Find a sharp, supported height discontinuity across an aligned rectangle.
// A gradual pitched surface has no single jump and remains one roof block.
bool splitAtHeightStep(const DecomposedBuildingBlock& source,
                       const RasterGrid<float>& ndsm,
                       const RasterGrid<uint8_t>& valid,
                       const SpatialMetadata& metadata,
                       const BuildingReconstructionConfig& config,
                       DecomposedBuildingBlock& first,
                       DecomposedBuildingBlock& second)
{
    const auto& p = source.pixelCorners;
    const double ex = p[1].column - p[0].column;
    const double ey = p[1].row - p[0].row;
    const double fx = p[3].column - p[0].column;
    const double fy = p[3].row - p[0].row;
    const double determinant = ex * fy - ey * fx;
    if (std::abs(determinant) < 1.0) return false;

    const int left = std::max(0, static_cast<int>(std::floor(std::min({
        p[0].column, p[1].column, p[2].column, p[3].column}))));
    const int right = std::min(metadata.width, static_cast<int>(std::ceil(std::max({
        p[0].column, p[1].column, p[2].column, p[3].column}))));
    const int top = std::max(0, static_cast<int>(std::floor(std::min({
        p[0].row, p[1].row, p[2].row, p[3].row}))));
    const int bottom = std::min(metadata.height, static_cast<int>(std::ceil(std::max({
        p[0].row, p[1].row, p[2].row, p[3].row}))));

    for (int axis = 0; axis < 2; ++axis)
    {
        const double length = axis == 0 ? std::hypot(ex, ey) : std::hypot(fx, fy);
        const int bins = static_cast<int>(std::lround(length));
        if (bins < 10) continue;
        std::vector<std::vector<float>> strips(static_cast<std::size_t>(bins));
        for (int row = top; row < bottom; ++row)
            for (int column = left; column < right; ++column)
            {
                const double dx = column + 0.5 - p[0].column;
                const double dy = row + 0.5 - p[0].row;
                const double u = (dx * fy - dy * fx) / determinant;
                const double v = (ex * dy - ey * dx) / determinant;
                if (u < 0.0 || u >= 1.0 || v < 0.0 || v >= 1.0) continue;
                const std::size_t index = static_cast<std::size_t>(row) * ndsm.width + column;
                const float height = ndsm.data[index];
                if (!valid.data[index] || !std::isfinite(height) || height <= 0.0f)
                    continue;
                const double t = axis == 0 ? u : v;
                strips[std::min(bins - 1, static_cast<int>(t * bins))].push_back(height);
            }
        std::vector<float> medians(static_cast<std::size_t>(bins),
                                   std::numeric_limits<float>::quiet_NaN());
        for (int bin = 0; bin < bins; ++bin)
            if (static_cast<int>(strips[bin].size()) >= config.minRequiredSamples)
                medians[bin] = percentile(strips[bin], 0.5);

        for (int cut = bins / 5; cut < 4 * bins / 5; ++cut)
        {
            if (cut < 2 || cut + 1 >= bins ||
                !std::isfinite(medians[cut - 2]) ||
                !std::isfinite(medians[cut + 1])) continue;
            const float jump = std::abs(medians[cut + 1] - medians[cut - 2]) *
                               config.heightScaleMultiplier;
            if (jump <= config.minSetbackHeightStepMetres) continue;
            std::vector<float> lower, upper;
            for (int bin = 0; bin < cut; ++bin)
                lower.insert(lower.end(), strips[bin].begin(), strips[bin].end());
            for (int bin = cut; bin < bins; ++bin)
                upper.insert(upper.end(), strips[bin].begin(), strips[bin].end());
            if (lower.size() < static_cast<std::size_t>(config.minRequiredSamples * 4) ||
                upper.size() < static_cast<std::size_t>(config.minRequiredSamples * 4))
                continue;
            const float sideStep = std::abs(percentile(lower, 0.5) -
                                            percentile(upper, 0.5)) *
                                   config.heightScaleMultiplier;
            const float spread = std::max(
                percentile(lower, 0.9) - percentile(lower, 0.1),
                percentile(upper, 0.9) - percentile(upper, 0.1)) *
                config.heightScaleMultiplier;
            if (sideStep <= config.minSetbackHeightStepMetres ||
                spread > 0.6f * sideStep) continue;
            const double t = static_cast<double>(cut) / bins;
            first = source;
            second = source;
            if (axis == 0)
            {
                first.pixelCorners[1] = interpolate(p[0], p[1], t);
                first.pixelCorners[2] = interpolate(p[3], p[2], t);
                second.pixelCorners[0] = first.pixelCorners[1];
                second.pixelCorners[3] = first.pixelCorners[2];
            }
            else
            {
                first.pixelCorners[2] = interpolate(p[1], p[2], t);
                first.pixelCorners[3] = interpolate(p[0], p[3], t);
                second.pixelCorners[0] = first.pixelCorners[3];
                second.pixelCorners[1] = first.pixelCorners[2];
            }
            first.footprintAreaSquareMetres *= static_cast<float>(t);
            second.footprintAreaSquareMetres *= static_cast<float>(1.0 - t);
            if (std::min(first.footprintAreaSquareMetres,
                         second.footprintAreaSquareMetres) <
                config.minDecomposedBlockAreaSquareMetres) continue;
            for (auto* block : {&first, &second})
                for (std::size_t corner = 0; corner < 4; ++corner)
                    block->projectedCorners[corner] =
                        toProjected(block->pixelCorners[corner], metadata);
            return true;
        }
    }
    return false;
}

void setFlatRoof(DecomposedBuildingBlock& block, float height,
                 float confidence, const SpatialMetadata& metadata)
{
    block.roof.type = RoofType::FLAT;
    block.roof.eaveHeightAboveGround = height;
    block.roof.ridgeHeightAboveGround = height;
    block.roof.confidence = confidence;
    PixelPoint centre;
    for (const auto& point : block.pixelCorners)
    {
        centre.column += point.column;
        centre.row += point.row;
    }
    centre.column /= 4.0;
    centre.row /= 4.0;
    block.roof.ridgeStartPixel = centre;
    block.roof.ridgeEndPixel = centre;
    block.roof.ridgeStartProjected = toProjected(centre, metadata);
    block.roof.ridgeEndProjected = block.roof.ridgeStartProjected;
}
} // namespace

void BuildingRoofModeler::fit(
    std::vector<DecomposedBuildingBlock>& blocks,
    const RasterGrid<float>& reconstructionNdsm,
    const RasterGrid<uint8_t>& validMask,
    const SpatialMetadata& metadata,
    float fallbackHeightAboveGround,
    const BuildingReconstructionConfig& config)
{
    if (!config.validate() || !reconstructionNdsm.isValid() ||
        !validMask.isValid() ||
        reconstructionNdsm.width != metadata.width ||
        reconstructionNdsm.height != metadata.height ||
        validMask.width != metadata.width || validMask.height != metadata.height)
    {
        for (auto& block : blocks)
            setFlatRoof(block, fallbackHeightAboveGround, 0.0f, metadata);
        return;
    }

    const double pixelArea = std::abs(
        metadata.geoTransform[1] * metadata.geoTransform[5] -
        metadata.geoTransform[2] * metadata.geoTransform[4]);
    if (!std::isfinite(pixelArea) || pixelArea <= 1.0e-12)
    {
        for (auto& block : blocks)
            setFlatRoof(block, fallbackHeightAboveGround, 0.0f, metadata);
        return;
    }
    const double gsd = std::sqrt(pixelArea);
    const float parcelArea = std::accumulate(
        blocks.begin(), blocks.end(), 0.0f,
        [](float area, const DecomposedBuildingBlock& block)
        { return area + block.footprintAreaSquareMetres; });
    const int boundaryRadius = std::max(
        1, static_cast<int>(std::ceil(config.roofBoundaryBandMetres / gsd)));

    // Split at most twice per original rectangle. The two new outlines share
    // exact endpoints, so podium and tower edges cannot drift apart.
    for (int pass = 0; pass < 2; ++pass)
    {
        std::vector<DecomposedBuildingBlock> refined;
        refined.reserve(blocks.size() * 2);
        for (const auto& block : blocks)
        {
            DecomposedBuildingBlock first, second;
            if (refined.size() + blocks.size() <
                    static_cast<std::size_t>(config.maxDecomposedBlocks) &&
                splitAtHeightStep(block, reconstructionNdsm, validMask,
                                  metadata, config, first, second))
            {
                refined.push_back(first);
                refined.push_back(second);
            }
            else refined.push_back(block);
        }
        blocks = std::move(refined);
    }

    for (auto& block : blocks)
    {
        double minColumn = block.pixelCorners[0].column;
        double maxColumn = minColumn;
        double minRow = block.pixelCorners[0].row;
        double maxRow = minRow;
        for (const auto& point : block.pixelCorners)
        {
            minColumn = std::min(minColumn, point.column);
            maxColumn = std::max(maxColumn, point.column);
            minRow = std::min(minRow, point.row);
            maxRow = std::max(maxRow, point.row);
        }
        const int roiX = std::max(0, static_cast<int>(std::floor(minColumn)) - 1);
        const int roiY = std::max(0, static_cast<int>(std::floor(minRow)) - 1);
        const int roiRight = std::min(
            metadata.width, static_cast<int>(std::ceil(maxColumn)) + 2);
        const int roiBottom = std::min(
            metadata.height, static_cast<int>(std::ceil(maxRow)) + 2);
        if (roiRight <= roiX || roiBottom <= roiY)
        {
            setFlatRoof(block, fallbackHeightAboveGround, 0.0f, metadata);
            continue;
        }

        cv::Mat blockMask = cv::Mat::zeros(
            roiBottom - roiY, roiRight - roiX, CV_8UC1);
        std::vector<cv::Point> corners;
        corners.reserve(4);
        for (const auto& point : block.pixelCorners)
            corners.emplace_back(
                static_cast<int>(std::lround(point.column)) - roiX,
                static_cast<int>(std::lround(point.row)) - roiY);
        cv::fillConvexPoly(blockMask, corners, cv::Scalar(255));

        cv::Mat eroded;
        const cv::Mat kernel = cv::getStructuringElement(
            cv::MORPH_ELLIPSE,
            cv::Size(boundaryRadius * 2 + 1, boundaryRadius * 2 + 1));
        cv::erode(blockMask, eroded, kernel);
        cv::Mat boundary;
        cv::subtract(blockMask, eroded, boundary);

        // Smooth only supported roof pixels. Blurring invalid cells as zero
        // would introduce a false slope at masked roof edges.
        cv::Mat weightedHeights = cv::Mat::zeros(blockMask.size(), CV_32F);
        cv::Mat weights = cv::Mat::zeros(blockMask.size(), CV_32F);
        for (int row = 0; row < blockMask.rows; ++row)
            for (int column = 0; column < blockMask.cols; ++column)
            {
                if (blockMask.at<uint8_t>(row, column) == 0) continue;
                const std::size_t index =
                    static_cast<std::size_t>(roiY + row) * metadata.width +
                    roiX + column;
                const float height = reconstructionNdsm.data[index];
                if (validMask.data[index] && std::isfinite(height) &&
                    height > 0.0f)
                {
                    weightedHeights.at<float>(row, column) = height;
                    weights.at<float>(row, column) = 1.0f;
                }
            }
        cv::Mat blurredHeights, blurredWeights, smoothedNdsm;
        cv::GaussianBlur(weightedHeights, blurredHeights,
                         cv::Size(5, 5), 1.5);
        cv::GaussianBlur(weights, blurredWeights, cv::Size(5, 5), 1.5);
        cv::divide(blurredHeights, blurredWeights + 1.0e-6f,
                   smoothedNdsm);

        std::vector<float> allSamples;
        std::vector<float> boundarySamples;
        std::vector<float> pitchSamples;
        std::vector<cv::Point2f> samplePoints;
        for (int row = 0; row < blockMask.rows; ++row)
        {
            for (int column = 0; column < blockMask.cols; ++column)
            {
                if (blockMask.at<uint8_t>(row, column) == 0) continue;
                const int globalColumn = roiX + column;
                const int globalRow = roiY + row;
                const std::size_t index =
                    static_cast<std::size_t>(globalRow) * metadata.width +
                    globalColumn;
                const float height = reconstructionNdsm.data[index];
                if (validMask.data[index] == 0 || !std::isfinite(height) ||
                    height <= 0.0f) continue;
                allSamples.push_back(height);
                samplePoints.emplace_back(
                    globalColumn + 0.5f, globalRow + 0.5f);
                if (boundary.at<uint8_t>(row, column) != 0)
                    boundarySamples.push_back(height);
                if (row > 0 && row + 1 < blockMask.rows &&
                    column > 0 && column + 1 < blockMask.cols &&
                    eroded.at<uint8_t>(row, column) != 0 &&
                    blockMask.at<uint8_t>(row - 1, column) != 0 &&
                    blockMask.at<uint8_t>(row + 1, column) != 0 &&
                    blockMask.at<uint8_t>(row, column - 1) != 0 &&
                    blockMask.at<uint8_t>(row, column + 1) != 0)
                {
                    const std::size_t left = index - 1;
                    const std::size_t right = index + 1;
                    const std::size_t above = index - metadata.width;
                    const std::size_t below = index + metadata.width;
                    if (validMask.data[left] && validMask.data[right] &&
                        validMask.data[above] && validMask.data[below] &&
                        std::isfinite(reconstructionNdsm.data[left]) &&
                        std::isfinite(reconstructionNdsm.data[right]) &&
                        std::isfinite(reconstructionNdsm.data[above]) &&
                        std::isfinite(reconstructionNdsm.data[below]))
                    {
                        const double dc = 0.5 * (
                            smoothedNdsm.at<float>(row, column + 1) -
                            smoothedNdsm.at<float>(row, column - 1)) *
                            config.heightScaleMultiplier;
                        const double dr = 0.5 * (
                            smoothedNdsm.at<float>(row + 1, column) -
                            smoothedNdsm.at<float>(row - 1, column)) *
                            config.heightScaleMultiplier;
                        const auto& gt = metadata.geoTransform;
                        const double gx = (gt[5] * dc - gt[4] * dr) /
                                          (gt[1] * gt[5] - gt[2] * gt[4]);
                        const double gy = (gt[1] * dr - gt[2] * dc) /
                                          (gt[1] * gt[5] - gt[2] * gt[4]);
                        pitchSamples.push_back(static_cast<float>(
                            std::atan(std::hypot(gx, gy)) * 180.0 /
                            3.14159265358979323846));
                    }
                }
            }
        }

        if (static_cast<int>(allSamples.size()) < config.minRequiredSamples ||
            static_cast<int>(boundarySamples.size()) < config.minRequiredSamples)
        {
            setFlatRoof(block, fallbackHeightAboveGround, 0.0f, metadata);
            continue;
        }

        const float medianHeight = percentile(allSamples, 0.50);
        const float dominantPitch = percentile(pitchSamples, 0.50);
        float eaveHeight = percentile(boundarySamples, 0.25);
        // Boundary interpolation in monocular nDSM tends to fall toward the
        // street. Prevent that blur from producing implausibly deep roofs.
        eaveHeight = std::clamp(
            eaveHeight, 0.65f * medianHeight, medianHeight);
        const float highThreshold = percentile(allSamples, 0.85);

        std::vector<cv::Point2f> highPoints;
        std::vector<float> highSamples;
        highPoints.reserve(allSamples.size() / 5 + 1);
        highSamples.reserve(highPoints.capacity());
        for (std::size_t index = 0; index < allSamples.size(); ++index)
        {
            if (allSamples[index] >= highThreshold)
            {
                highSamples.push_back(allSamples[index]);
                highPoints.push_back(samplePoints[index]);
            }
        }
        const float highSupportFraction = static_cast<float>(highPoints.size()) /
            static_cast<float>(allSamples.size());
        // A real ridge or hip occupies a minority of the roof. Broad upper
        // support is checked after the tall-step fallback below.
        if (highPoints.size() < 3)
        {
            setFlatRoof(block, medianHeight * config.heightScaleMultiplier,
                        0.25f, metadata);
            continue;
        }

        const float ridgeHeight = percentile(highSamples, 0.50);
        const float rise = (ridgeHeight - eaveHeight) *
                           config.heightScaleMultiplier;
        if (std::isfinite(rise) && rise > config.maxRoofRiseMetres)
        {
            setFlatRoof(block, ridgeHeight * config.heightScaleMultiplier,
                        0.90f, metadata);
            continue;
        }
        const auto projectedEdgeLength = [](const ProjectedPoint& a,
                                            const ProjectedPoint& b)
        {
            return std::hypot(b.easting - a.easting,
                              b.northing - a.northing);
        };
        const double shortSpan = std::min(
            projectedEdgeLength(block.projectedCorners[0],
                                block.projectedCorners[1]),
            projectedEdgeLength(block.projectedCorners[1],
                                block.projectedCorners[2]));
        // A rise close to the full short span is usually a height step or
        // nDSM edge artifact, not a plausible gable across that rectangle.
        if (shortSpan > 0.0 && rise > 0.40 * shortSpan)
        {
            setFlatRoof(block, medianHeight * config.heightScaleMultiplier,
                        0.65f, metadata);
            continue;
        }
        if (highSupportFraction > 0.45F)
        {
            setFlatRoof(block, medianHeight * config.heightScaleMultiplier,
                        0.75f, metadata);
            continue;
        }
        if (pitchSamples.size() < static_cast<std::size_t>(config.minRequiredSamples) ||
            dominantPitch < config.flatRoofPitchDegrees ||
            dominantPitch <= config.minPitchedRoofDegrees ||
            parcelArea > config.commercialFlatRoofAreaSquareMetres ||
            block.footprintAreaSquareMetres >
                config.commercialFlatRoofAreaSquareMetres)
        {
            setFlatRoof(block, medianHeight * config.heightScaleMultiplier,
                        0.85f, metadata);
            continue;
        }
        if (!config.enableLod2RoofFitting ||
            !std::isfinite(rise) || rise < config.minRoofRiseMetres)
        {
            setFlatRoof(block, medianHeight * config.heightScaleMultiplier,
                        0.75f, metadata);
            continue;
        }

        cv::Vec4f fittedLine;
        cv::fitLine(highPoints, fittedLine, cv::DIST_L2, 0.0, 0.01, 0.01);
        const double dx = fittedLine[0];
        const double dy = fittedLine[1];
        const double x0 = fittedLine[2];
        const double y0 = fittedLine[3];
        double minProjection = std::numeric_limits<double>::infinity();
        double maxProjection = -std::numeric_limits<double>::infinity();
        double perpendicularSquared = 0.0;
        for (const auto& point : highPoints)
        {
            const double rx = point.x - x0;
            const double ry = point.y - y0;
            const double projection = rx * dx + ry * dy;
            minProjection = std::min(minProjection, projection);
            maxProjection = std::max(maxProjection, projection);
            const double perpendicular = -rx * dy + ry * dx;
            perpendicularSquared += perpendicular * perpendicular;
        }
        const double span = maxProjection - minProjection;
        const double rmsWidth = std::sqrt(
            perpendicularSquared / static_cast<double>(highPoints.size()));
        const double longAxis = std::max(
            distance(block.pixelCorners[0], block.pixelCorners[1]),
            distance(block.pixelCorners[1], block.pixelCorners[2]));
        const double spanRatio = longAxis > 0.0 ? span / longAxis : 0.0;
        const double linearity = span / std::max(1.0, 2.0 * rmsWidth);

        block.roof.ridgeStartPixel = {
            x0 + minProjection * dx, y0 + minProjection * dy};
        block.roof.ridgeEndPixel = {
            x0 + maxProjection * dx, y0 + maxProjection * dy};
        block.roof.ridgeStartProjected =
            toProjected(block.roof.ridgeStartPixel, metadata);
        block.roof.ridgeEndProjected =
            toProjected(block.roof.ridgeEndPixel, metadata);
        block.roof.eaveHeightAboveGround =
            eaveHeight * config.heightScaleMultiplier;
        block.roof.ridgeHeightAboveGround =
            ridgeHeight * config.heightScaleMultiplier;

        const bool longRidge = spanRatio >= 0.50 && linearity >= 2.0;
        block.roof.type = longRidge ? RoofType::GABLE : RoofType::HIP;
        const float sampleConfidence = std::min(
            1.0f, static_cast<float>(allSamples.size()) /
                static_cast<float>(config.minRequiredSamples * 12));
        const float riseConfidence = std::min(
            1.0f, rise / std::max(0.1f, 2.0f * config.minRoofRiseMetres));
        const float shapeConfidence = longRidge
            ? static_cast<float>(std::min(1.0, linearity / 4.0))
            : 0.65f;
        block.roof.confidence =
            sampleConfidence * riseConfidence * shapeConfidence;
        if (block.roof.confidence < config.minRoofFitConfidence)
            setFlatRoof(block, medianHeight * config.heightScaleMultiplier,
                        block.roof.confidence, metadata);
    }
}
