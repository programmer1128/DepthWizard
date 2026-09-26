#include <gtest/gtest.h>

#include "BuildingReconstruction/FootprintVectorizer.h"
#include "BuildingReconstructionTestSupport.h"

#include <opencv2/imgproc.hpp>
#include <algorithm>
#include <cstdint>

namespace
{
using namespace depthwizard::test;

ComponentStats rectangleStats(
    int componentId,
    int x,
    int y,
    int width,
    int height,
    double pixelArea)
{
    ComponentStats stats;
    stats.componentId = componentId;
    stats.pixelCount = width * height;
    stats.pixelBoundingBox = {x, y, width, height};
    stats.physicalAreaSquareMetres =
        static_cast<double>(stats.pixelCount) * pixelArea;
    return stats;
}

TEST(FootprintVectorizerTest, VectorizesRectangleWithExactAreaAndAffineCoordinates)
{
    RasterGrid<int32_t> labels = makeConstantGrid<int32_t>(10, 10, 0);
    fillRectangle<int32_t>(labels, 2, 3, 6, 6, 1);
    const SpatialMetadata metadata = makeProjectedMetadata(10, 10, 2.0, 3.0);
    const ComponentStats stats = rectangleStats(1, 2, 3, 4, 3, 6.0);

    const FootprintVectorizationResult result = timedCall(
        "FootprintVectorizer::vectorize rectangle",
        [&]
        {
            return FootprintVectorizer::vectorize(
                stats,
                labels,
                metadata,
                noMorphologyConfig());
        });

    ASSERT_TRUE(result.success) << result.errorMessage;
    ASSERT_EQ(result.projectedFootprint.outerRing.size(), 4U);
    ASSERT_EQ(result.pixelFootprint.outerRing.size(), 4U);
    EXPECT_NEAR(
        projectedRingArea(result.projectedFootprint.outerRing),
        72.0,
        1.0e-6);

    double minColumn = 1000.0;
    double maxColumn = -1000.0;
    double minRow = 1000.0;
    double maxRow = -1000.0;
    for (const PixelPoint& point : result.pixelFootprint.outerRing)
    {
        minColumn = std::min(minColumn, point.column);
        maxColumn = std::max(maxColumn, point.column);
        minRow = std::min(minRow, point.row);
        maxRow = std::max(maxRow, point.row);
    }
    EXPECT_NEAR(minColumn, 2.0, 1.0e-6);
    EXPECT_NEAR(maxColumn, 6.0, 1.0e-6);
    EXPECT_NEAR(minRow, 3.0, 1.0e-6);
    EXPECT_NEAR(maxRow, 6.0, 1.0e-6);
}

TEST(FootprintVectorizerTest, PreservesCourtyardAsInteriorHole)
{
    RasterGrid<int32_t> labels = makeConstantGrid<int32_t>(12, 12, 0);
    fillRectangle<int32_t>(labels, 2, 2, 10, 10, 1);
    fillRectangle<int32_t>(labels, 4, 4, 7, 7, 0);

    ComponentStats stats;
    stats.componentId = 1;
    stats.pixelCount = 64 - 9;
    stats.pixelBoundingBox = {2, 2, 8, 8};
    stats.physicalAreaSquareMetres = 55.0;

    BuildingReconstructionConfig config = noMorphologyConfig();
    config.minHoleAreaSquareMetres = 5.0F;

    const FootprintVectorizationResult result = FootprintVectorizer::vectorize(
        stats,
        labels,
        makeProjectedMetadata(12, 12),
        config);

    ASSERT_TRUE(result.success) << result.errorMessage;
    ASSERT_EQ(result.projectedFootprint.holes.size(), 1U);
    EXPECT_NEAR(projectedRingArea(result.projectedFootprint.outerRing), 64.0, 1.0e-6);
    EXPECT_NEAR(projectedRingArea(result.projectedFootprint.holes[0]), 9.0, 1.0e-6);
}

TEST(FootprintVectorizerTest, HandlesStandardNorthUpNegativeRowResolution)
{
    RasterGrid<int32_t> labels = makeConstantGrid<int32_t>(10, 10, 0);
    fillRectangle<int32_t>(labels, 2, 2, 7, 7, 1);
    const ComponentStats stats = rectangleStats(1, 2, 2, 5, 5, 1.0);

    const FootprintVectorizationResult result = FootprintVectorizer::vectorize(
        stats,
        labels,
        makeProjectedMetadata(10, 10, 1.0, -1.0),
        noMorphologyConfig());

    ASSERT_TRUE(result.success) << result.errorMessage;
    EXPECT_NEAR(projectedRingArea(result.projectedFootprint.outerRing), 25.0, 1.0e-6);
}

TEST(FootprintVectorizerTest, RejectsBoundingBoxOutsideRaster)
{
    const RasterGrid<int32_t> labels = makeConstantGrid<int32_t>(10, 10, 0);
    const ComponentStats stats = rectangleStats(1, 8, 8, 5, 5, 1.0);

    const FootprintVectorizationResult result = FootprintVectorizer::vectorize(
        stats,
        labels,
        makeProjectedMetadata(10, 10),
        noMorphologyConfig());

    EXPECT_FALSE(result.success);
    EXPECT_FALSE(result.errorMessage.empty());
}

TEST(FootprintVectorizerTest, RegularizesSupportedRectangleButPreservesLShape)
{
    // Regularization must recover supported right angles, not erase concavity.
    auto labels = makeConstantGrid<int32_t>(16, 16, 0);
    fillRectangle<int32_t>(labels, 2, 2, 12, 12, 1);
    labels.data[2 * 16 + 2] = 0; // Single raster corner nick, 99% box support.
    auto stats = rectangleStats(1, 2, 2, 10, 10, 1.0);
    stats.pixelCount = 99;
    stats.physicalAreaSquareMetres = 99.0;
    BuildingReconstructionConfig config;
    auto result = FootprintVectorizer::vectorize(
        stats, labels, makeProjectedMetadata(16, 16), config);
    ASSERT_TRUE(result.success) << result.errorMessage;
    EXPECT_EQ(result.projectedFootprint.outerRing.size(), 4U);
    EXPECT_NEAR(projectedRingArea(result.projectedFootprint.outerRing), 100, 1e-5);

    labels.data[2 * 16 + 2] = 1;
    fillRectangle<int32_t>(labels, 7, 2, 12, 7, 0);
    stats.pixelCount = 75;
    stats.physicalAreaSquareMetres = 75;
    result = FootprintVectorizer::vectorize(
        stats, labels, makeProjectedMetadata(16, 16), config);
    ASSERT_TRUE(result.success) << result.errorMessage;
    EXPECT_EQ(result.projectedFootprint.outerRing.size(), 6U);
    EXPECT_NEAR(projectedRingArea(result.projectedFootprint.outerRing), 75, 1e-5);
}
TEST(FootprintVectorizerTest, SupportedEdgeFitKeepsConcaveWingAndArea)
{
    auto labels = makeConstantGrid<int32_t>(18, 18, 0);
    fillRectangle<int32_t>(labels, 2, 2, 14, 14, 1);
    fillRectangle<int32_t>(labels, 8, 2, 14, 8, 0);
    auto stats = rectangleStats(1, 2, 2, 12, 12, 1.0);
    stats.pixelCount = 108; stats.physicalAreaSquareMetres = 108;
    auto meta = makeProjectedMetadata(18,18);
    meta.geoTransform[2] = .03; // Mild shear: slightly noisy, supported axes.
    BuildingReconstructionConfig config;
    config.regularizeRectangularFootprints = false;
    const auto result = FootprintVectorizer::vectorize(stats, labels, meta, config);
    ASSERT_TRUE(result.success) << result.errorMessage;
    ASSERT_EQ(result.projectedFootprint.outerRing.size(), 6U);
    EXPECT_NEAR(projectedRingArea(result.projectedFootprint.outerRing), 108, 5.4);
    const auto& ring = result.projectedFootprint.outerRing;
    for (std::size_t i=0; i<ring.size(); ++i) {
        const auto& a=ring[(i+ring.size()-1)%ring.size()];
        const auto& b=ring[i]; const auto& c=ring[(i+1)%ring.size()];
        const double dx1=b.easting-a.easting, dy1=b.northing-a.northing;
        const double dx2=c.easting-b.easting, dy2=c.northing-b.northing;
        EXPECT_NEAR((dx1*dx2+dy1*dy2)/(std::hypot(dx1,dy1)*std::hypot(dx2,dy2)), 0, 1e-5);
    }
}
TEST(FootprintVectorizerTest, ArchitecturalDefaultsValidateAndRejectUnboundedAdjustments)
{
    BuildingReconstructionConfig config;
    EXPECT_TRUE(config.validate());
    EXPECT_FLOAT_EQ(config.footprintSimplificationToleranceMetres, 1.25f);
    EXPECT_FLOAT_EQ(config.maxCornerAdjustmentMetres, 1.0f);
    EXPECT_FLOAT_EQ(config.minimumRectangleFillRatio, 0.9f);
    EXPECT_FLOAT_EQ(config.minimumFootprintMaskIoU, 0.93f);
    config.maxCornerAdjustmentMetres = 3.01f;
    EXPECT_FALSE(config.validate());
    config.maxCornerAdjustmentMetres = 1.0f;
    config.minimumFootprintMaskIoU = 0.0f;
    EXPECT_FALSE(config.validate());
}

TEST(FootprintVectorizerTest, LooseRectangleFillDoesNotFillAnEightyFourPercentLShape)
{
    auto labels = makeConstantGrid<int32_t>(16, 16, 0);
    fillRectangle<int32_t>(labels, 2, 2, 12, 12, 1);
    fillRectangle<int32_t>(labels, 8, 2, 12, 6, 0);
    auto stats = rectangleStats(1, 2, 2, 10, 10, 1.0);
    stats.pixelCount = 84;
    stats.physicalAreaSquareMetres = 84;
    BuildingReconstructionConfig config;
    config.minimumRectangleFillRatio = .8F;
    const auto result = FootprintVectorizer::vectorize(
        stats, labels, makeProjectedMetadata(16, 16), config);
    ASSERT_TRUE(result.success) << result.errorMessage;
    EXPECT_EQ(result.projectedFootprint.outerRing.size(), 6U);
    EXPECT_NEAR(projectedRingArea(result.projectedFootprint.outerRing), 84, 1e-5);
}

TEST(FootprintVectorizerTest, RoundedConvexRectangleCanRecoverFourArchitecturalCorners)
{
    auto labels = makeConstantGrid<int32_t>(20, 20, 0);
    fillRectangle<int32_t>(labels, 3, 3, 15, 15, 1);
    // Clip three pixels at each corner: an almost-convex rounded rectangle
    // with 91.7% box support, which the old .95 fill cutoff could not recover.
    for (const auto [x, y] : std::vector<std::pair<int, int>>{
        {3,3},{4,3},{3,4}, {14,3},{13,3},{14,4},
        {3,14},{4,14},{3,13}, {14,14},{13,14},{14,13}})
        labels.data[y * 20 + x] = 0;
    auto stats = rectangleStats(1, 3, 3, 12, 12, 1.0);
    stats.pixelCount = 132;
    stats.physicalAreaSquareMetres = 132;
    BuildingReconstructionConfig config;
    auto result = FootprintVectorizer::vectorize(
        stats, labels, makeProjectedMetadata(20, 20), config);
    ASSERT_TRUE(result.success) << result.errorMessage;
    // The conservative default should not invent twelve missing corner cells.
    EXPECT_GT(result.projectedFootprint.outerRing.size(), 4U);
    EXPECT_NEAR(projectedRingArea(result.projectedFootprint.outerRing), 132, 5.0);

    // A caller can explicitly opt into a looser presentation fit; the shape
    // still has to pass the same topology and neighbour checks.
    config.maxCornerAdjustmentMetres = 3.0f;
    config.minimumFootprintMaskIoU = .90f;
    result = FootprintVectorizer::vectorize(
        stats, labels, makeProjectedMetadata(20, 20), config);
    ASSERT_TRUE(result.success) << result.errorMessage;
    EXPECT_EQ(result.projectedFootprint.outerRing.size(), 4U);
    EXPECT_NEAR(projectedRingArea(result.projectedFootprint.outerRing), 144, 1e-5);
}

TEST(FootprintVectorizerTest, AggressiveSimplificationRetriesRatherThanDeletingSmallCourtyard)
{
    auto labels = makeConstantGrid<int32_t>(20, 20, 0);
    fillRectangle<int32_t>(labels, 2, 2, 18, 18, 1);
    fillRectangle<int32_t>(labels, 7, 7, 10, 10, 0);
    auto stats = rectangleStats(1, 2, 2, 16, 16, 1.0);
    stats.pixelCount = 247;
    stats.physicalAreaSquareMetres = 247;
    const auto result = FootprintVectorizer::vectorize(
        stats, labels, makeProjectedMetadata(20, 20), BuildingReconstructionConfig{});
    ASSERT_TRUE(result.success) << result.errorMessage;
    ASSERT_EQ(result.projectedFootprint.holes.size(), 1U);
    EXPECT_NEAR(projectedRingArea(result.projectedFootprint.holes.front()), 9, 1e-5);
    EXPECT_NEAR(projectedRingArea(result.projectedFootprint.outerRing), 256, 1e-5);
}

TEST(FootprintVectorizerTest, RectangleExpansionDoesNotStealNeighbouringInstancePixels)
{
    auto labels = makeConstantGrid<int32_t>(16, 16, 0);
    fillRectangle<int32_t>(labels, 2, 2, 12, 12, 1);
    labels.data[2 * 16 + 2] = 2;
    auto stats = rectangleStats(1, 2, 2, 10, 10, 1.0);
    stats.pixelCount = 99;
    stats.physicalAreaSquareMetres = 99;
    const auto result = FootprintVectorizer::vectorize(
        stats, labels, makeProjectedMetadata(16, 16), BuildingReconstructionConfig{});
    ASSERT_TRUE(result.success) << result.errorMessage;
    // A smaller-epsilon fit can trim the affected corner without reverting
    // every other straight wall to the unsimplified pixel-edge outline.
    EXPECT_LT(result.projectedFootprint.outerRing.size(), 6U);
    EXPECT_GE(projectedRingArea(result.projectedFootprint.outerRing), 95);
    EXPECT_LE(projectedRingArea(result.projectedFootprint.outerRing), 99);
    std::vector<cv::Point2f> pixelRing;
    for (const auto& point : result.pixelFootprint.outerRing)
        pixelRing.emplace_back(point.column, point.row);
    EXPECT_LT(cv::pointPolygonTest(pixelRing, cv::Point2f(2.5f, 2.5f), false), 0);
    EXPECT_TRUE(std::any_of(result.warnings.begin(), result.warnings.end(),
        [](const std::string& warning) { return warning.find("neighbouring") != std::string::npos; }));
}

TEST(FootprintVectorizerTest, SupportedWallsReplaceSmallChamferWithRightAngle)
{
    auto labels = makeConstantGrid<int32_t>(18, 18, 0);
    fillRectangle<int32_t>(labels, 2, 2, 14, 14, 1);
    labels.data[2 * 18 + 2] = 0;
    auto stats = rectangleStats(1, 2, 2, 12, 12, 1.0);
    stats.pixelCount = 143;
    stats.physicalAreaSquareMetres = 143;
    BuildingReconstructionConfig config;
    config.regularizeRectangularFootprints = false;
    // Isolate edge fitting from a bounding-box substitution.
    const auto result = FootprintVectorizer::vectorize(
        stats, labels, makeProjectedMetadata(18, 18), config);
    ASSERT_TRUE(result.success) << result.errorMessage;
    EXPECT_EQ(result.projectedFootprint.outerRing.size(), 4U);
    EXPECT_NEAR(projectedRingArea(result.projectedFootprint.outerRing), 143, 7.15);
    const auto& ring = result.projectedFootprint.outerRing;
    for (std::size_t i = 0; i < ring.size(); ++i)
    {
        const auto& a = ring[(i + ring.size() - 1) % ring.size()];
        const auto& b = ring[i];
        const auto& c = ring[(i + 1) % ring.size()];
        const double dx1 = b.easting - a.easting, dy1 = b.northing - a.northing;
        const double dx2 = c.easting - b.easting, dy2 = c.northing - b.northing;
        EXPECT_NEAR((dx1 * dx2 + dy1 * dy2) /
            (std::hypot(dx1, dy1) * std::hypot(dx2, dy2)), 0, .03);
    }
    EXPECT_TRUE(result.projectedFootprint.holes.empty());
}

TEST(FootprintVectorizerTest, OrthogonalFacadeSurvivesAnAttachedDiagonalWing)
{
    cv::Mat painted(40, 48, CV_8UC1, cv::Scalar(0));
    cv::fillPoly(painted,
        std::vector<std::vector<cv::Point>>{{
            {2, 2}, {20, 2}, {20, 10}, {39, 28},
            {30, 36}, {17, 20}, {2, 20}}},
        cv::Scalar(255));
    painted.at<uint8_t>(2, 2) = 0; // One-pixel chamfer on a supported corner.

    auto labels = makeConstantGrid<int32_t>(48, 40, 0);
    int count = 0;
    for (int row = 0; row < 40; ++row)
        for (int column = 0; column < 48; ++column)
            if (painted.at<uint8_t>(row, column))
            {
                labels.data[row * 48 + column] = 1;
                ++count;
            }

    auto stats = rectangleStats(1, 2, 2, 38, 35, 1.0);
    stats.pixelCount = count;
    stats.physicalAreaSquareMetres = count;
    BuildingReconstructionConfig config;
    config.regularizeRectangularFootprints = false;
    const auto fitted = FootprintVectorizer::vectorize(
        stats, labels, makeProjectedMetadata(48, 40), config);
    ASSERT_TRUE(fitted.success) << fitted.errorMessage;

    config.regularizeSupportedEdges = false;
    const auto unfit = FootprintVectorizer::vectorize(
        stats, labels, makeProjectedMetadata(48, 40), config);
    ASSERT_TRUE(unfit.success) << unfit.errorMessage;
    const auto cornerDot = [](const auto& ring)
    {
        const auto& before = ring.back();
        const auto& corner = ring.front();
        const auto& after = ring[1];
        const double ax = corner.easting - before.easting;
        const double ay = corner.northing - before.northing;
        const double bx = after.easting - corner.easting;
        const double by = after.northing - corner.northing;
        return std::abs((ax * bx + ay * by) /
            (std::hypot(ax, ay) * std::hypot(bx, by)));
    };
    EXPECT_LT(cornerDot(fitted.projectedFootprint.outerRing), 0.02);
    EXPECT_LT(cornerDot(fitted.projectedFootprint.outerRing),
              cornerDot(unfit.projectedFootprint.outerRing));
    EXPECT_LE(fitted.projectedFootprint.outerRing.size(),
              unfit.projectedFootprint.outerRing.size());
    EXPECT_GT(fitted.projectedFootprint.outerRing.size(), 4U);
    EXPECT_NEAR(projectedRingArea(fitted.projectedFootprint.outerRing),
                count, 0.05 * count);
}

TEST(FootprintVectorizerTest, SupportedFitKeepsCourtyardAndConcaveWings)
{
    auto labels = makeConstantGrid<int32_t>(26, 26, 0);
    fillRectangle<int32_t>(labels, 2, 2, 22, 22, 1);
    fillRectangle<int32_t>(labels, 13, 2, 22, 7, 0); // Deep concave wing.
    fillRectangle<int32_t>(labels, 6, 10, 10, 14, 0); // Courtyard.
    auto stats = rectangleStats(1, 2, 2, 20, 20, 1.0);
    stats.pixelCount = 339;
    stats.physicalAreaSquareMetres = 339;
    const auto result = FootprintVectorizer::vectorize(
        stats, labels, makeProjectedMetadata(26, 26), BuildingReconstructionConfig{});
    ASSERT_TRUE(result.success) << result.errorMessage;
    ASSERT_EQ(result.projectedFootprint.holes.size(), 1U);
    EXPECT_GE(result.projectedFootprint.outerRing.size(), 6U);
    EXPECT_NEAR(projectedRingArea(result.projectedFootprint.outerRing), 355, 3.0);
    EXPECT_NEAR(projectedRingArea(result.projectedFootprint.holes.front()), 16, 1e-5);
}
} // namespace
