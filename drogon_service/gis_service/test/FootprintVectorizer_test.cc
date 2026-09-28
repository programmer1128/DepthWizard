#include <gtest/gtest.h>

#include "BuildingReconstruction/FootprintVectorizer.h"
#include "BuildingReconstruction/FootprintGeometryRegularizer.h"
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

TEST(FootprintVectorizerTest, IgnoresSmallTriangularRoofPuncture)
{
    auto labels = makeConstantGrid<int32_t>(30, 30, 0);
    fillRectangle<int32_t>(labels, 3, 3, 27, 27, 1);
    cv::Mat puncture = cv::Mat::zeros(30, 30, CV_8U);
    cv::fillConvexPoly(puncture,
        std::vector<cv::Point>{{12, 12}, {16, 12}, {12, 16}},
        cv::Scalar(255));
    int count = 0;
    for (int row = 3; row < 27; ++row)
        for (int column = 3; column < 27; ++column)
        {
            if (puncture.at<uint8_t>(row, column))
                labels.data[row * 30 + column] = 0;
            else
                ++count;
        }
    auto stats = rectangleStats(1, 3, 3, 24, 24, 1.0);
    stats.pixelCount = count;
    stats.physicalAreaSquareMetres = count;
    auto config = noMorphologyConfig();
    config.minHoleAreaSquareMetres = 5.0F;
    config.footprintAreaDeviationTolerance = 0.1F;
    const auto result = FootprintVectorizer::vectorize(
        stats, labels, makeProjectedMetadata(30, 30), config);
    ASSERT_TRUE(result.success) << result.errorMessage;
    EXPECT_TRUE(result.projectedFootprint.holes.empty());
}

TEST(FootprintVectorizerTest, DiagonallyTouchingVoidsDoNotDropOuterBoundary)
{
    auto labels = makeConstantGrid<int32_t>(16, 16, 0);
    fillRectangle<int32_t>(labels, 2, 2, 12, 12, 1);
    labels.data[5 * 16 + 5] = 0;
    labels.data[6 * 16 + 6] = 0;
    auto stats = rectangleStats(1, 2, 2, 10, 10, 1.0);
    stats.pixelCount = 98;
    stats.physicalAreaSquareMetres = 98.0;
    auto config = noMorphologyConfig();
    config.minHoleAreaSquareMetres = 5.0F;
    config.footprintAreaDeviationTolerance = 0.05F;

    const auto result = FootprintVectorizer::vectorize(
        stats, labels, makeProjectedMetadata(16, 16), config);

    ASSERT_TRUE(result.success) << result.errorMessage;
    EXPECT_NEAR(projectedRingArea(result.projectedFootprint.outerRing),
                100.0, 1.0e-6);
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
    config.footprintDilationMetres = 0.0F;
    auto result = FootprintVectorizer::vectorize(
        stats, labels, makeProjectedMetadata(16, 16), config);
    ASSERT_TRUE(result.success) << result.errorMessage;
    EXPECT_EQ(result.projectedFootprint.outerRing.size(), 4U);
    EXPECT_NEAR(projectedRingArea(result.projectedFootprint.outerRing), 100, 1e-5);

    labels.data[2 * 16 + 2] = 1;
    fillRectangle<int32_t>(labels, 7, 2, 12, 7, 0);
    stats.pixelCount = 75;
    stats.physicalAreaSquareMetres = 75;
    config.regularizeRectangularFootprints = false;
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
    config.footprintDilationMetres = 0.0F;
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

TEST(FootprintVectorizerTest, OpticalFacadeLinesRefineSupportedCorners)
{
    auto labels = makeConstantGrid<int32_t>(30, 30, 0);
    fillRectangle<int32_t>(labels, 4, 4, 24, 24, 1);
    const auto stats = rectangleStats(1, 4, 4, 20, 20, 1.0);
    auto config = noMorphologyConfig();
    config.regularizeRectangularFootprints = false;
    config.regularizeSupportedEdges = false;
    const auto metadata = makeProjectedMetadata(30, 30);
    const std::vector<cv::Vec4f> opticalLines{
        cv::Vec4f{4.0f, 3.0f, 24.0f, 3.0f},
        cv::Vec4f{4.0f, 23.0f, 24.0f, 23.0f}};

    const auto baseline = FootprintVectorizer::vectorize(
        stats, labels, metadata, config);
    const auto refined = FootprintVectorizer::vectorize(
        stats, labels, metadata, config, &opticalLines);
    ASSERT_TRUE(baseline.success) << baseline.errorMessage;
    ASSERT_TRUE(refined.success) << refined.errorMessage;
    ASSERT_EQ(baseline.pixelFootprint.outerRing.size(), 4U);
    ASSERT_EQ(refined.pixelFootprint.outerRing.size(), 4U);
    const auto minCoordinates = [](const auto& footprint)
    {
        double minColumn = 1e6, minRow = 1e6;
        for (const auto& point : footprint.outerRing)
        {
            minColumn = std::min(minColumn, point.column);
            minRow = std::min(minRow, point.row);
        }
        return std::pair{minColumn, minRow};
    };
    const auto before = minCoordinates(baseline.pixelFootprint);
    const auto after = minCoordinates(refined.pixelFootprint);
    EXPECT_NEAR(before.first, 4.0, 1e-6);
    EXPECT_NEAR(before.second, 4.0, 1e-6);
    EXPECT_NEAR(after.first, 4.0, 1e-6);
    EXPECT_NEAR(after.second, 3.0, 1e-6);
}

TEST(FootprintVectorizerTest, FivePixelStructuralLinesCanGuideShortWalls)
{
    auto labels = makeConstantGrid<int32_t>(24, 24, 0);
    fillRectangle<int32_t>(labels, 4, 4, 12, 12, 1);
    const auto stats = rectangleStats(1, 4, 4, 8, 8, 1.0);
    auto config = noMorphologyConfig();
    config.regularizeRectangularFootprints = false;
    config.regularizeSupportedEdges = false;
    const std::vector<cv::Vec4f> lines{
        cv::Vec4f{5.0f, 3.7f, 10.5f, 3.7f},
        cv::Vec4f{5.0f, 11.7f, 10.5f, 11.7f}};
    const auto result = FootprintVectorizer::vectorize(
        stats, labels, makeProjectedMetadata(24, 24), config, &lines);
    ASSERT_TRUE(result.success) << result.errorMessage;
    double minRow = 24.0;
    for (const auto& point : result.pixelFootprint.outerRing)
        minRow = std::min(minRow, point.row);
    EXPECT_NEAR(minRow, 3.7, 0.05);
}

TEST(FootprintVectorizerTest, ArchitecturalDefaultsValidateAndRejectUnboundedAdjustments)
{
    BuildingReconstructionConfig config;
    EXPECT_TRUE(config.validate());
    EXPECT_FLOAT_EQ(config.footprintSimplificationToleranceMetres, 0.75f);
    EXPECT_FLOAT_EQ(config.minHoleAreaSquareMetres, 30.0f);
    EXPECT_FLOAT_EQ(config.maxCornerAdjustmentMetres, 1.2f);
    EXPECT_FLOAT_EQ(config.minimumRectangleFillRatio, 0.84f);
    EXPECT_FLOAT_EQ(config.minimumFootprintMaskIoU, 0.68f);
    EXPECT_FLOAT_EQ(config.footprintAreaDeviationTolerance, 0.25f);
    EXPECT_TRUE(config.splitSupportedInstances);
    EXPECT_FLOAT_EQ(config.instanceSeedProbability, 0.48f);
    EXPECT_FLOAT_EQ(config.closingRadiusMetres, 0.0f);
    EXPECT_FLOAT_EQ(config.instanceHeightStepMetres, 1.5f);
    EXPECT_FLOAT_EQ(config.minDecompositionCoverage, 0.82f);
    EXPECT_EQ(config.maxDecomposedBlocks, 3);
    EXPECT_FLOAT_EQ(config.minDecompositionMaskIoU, 0.75f);
    EXPECT_FLOAT_EQ(config.flatRoofPitchDegrees, 15.0f);
    EXPECT_FLOAT_EQ(config.minPitchedRoofDegrees, 18.0f);
    EXPECT_FLOAT_EQ(config.minInstanceSeedAreaSquareMetres, 25.0f);
    EXPECT_FLOAT_EQ(config.footprintDilationMetres, 0.0f);
    EXPECT_FLOAT_EQ(config.heightScaleMultiplier, 2.25f);
    config.maxCornerAdjustmentMetres = 3.01f;
    EXPECT_FALSE(config.validate());
    config.maxCornerAdjustmentMetres = 3.0f;
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
    config.regularizeRectangularFootprints = false;
    config.minimumRectangleFillRatio = .8F;
    config.footprintDilationMetres = 0.0F;
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

    // A conservative caller with 1.0m corner adjustment keeps the rounded outline.
    BuildingReconstructionConfig conservativeConfig;
    conservativeConfig.regularizeRectangularFootprints = false;
    conservativeConfig.maxCornerAdjustmentMetres = 1.0f;
    conservativeConfig.minimumFootprintMaskIoU = 0.93f;
    conservativeConfig.footprintDilationMetres = 0.0f;
    auto conservativeResult = FootprintVectorizer::vectorize(
        stats, labels, makeProjectedMetadata(20, 20), conservativeConfig);
    ASSERT_TRUE(conservativeResult.success) << conservativeResult.errorMessage;
    EXPECT_GT(conservativeResult.projectedFootprint.outerRing.size(), 4U);
    EXPECT_NEAR(projectedRingArea(conservativeResult.projectedFootprint.outerRing), 132, 5.0);

    // Production LOD1 defaults (maxCornerAdjustmentMetres=2.5, IoU=0.80) recover the 4 sharp corners.
    BuildingReconstructionConfig config;
    config.maxCornerAdjustmentMetres = 2.5f;
    config.footprintDilationMetres = 0.0f;
    auto result = FootprintVectorizer::vectorize(
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
    BuildingReconstructionConfig config;
    config.regularizeRectangularFootprints = false;
    config.minHoleAreaSquareMetres = 5.0F;
    config.footprintDilationMetres = 0.0F;
    const auto result = FootprintVectorizer::vectorize(
        stats, labels, makeProjectedMetadata(20, 20), config);
    ASSERT_TRUE(result.success) << result.errorMessage;
    ASSERT_EQ(result.projectedFootprint.holes.size(), 1U);
    EXPECT_NEAR(projectedRingArea(result.projectedFootprint.holes.front()), 9, 1e-5);
    EXPECT_NEAR(projectedRingArea(result.projectedFootprint.outerRing), 256, 1e-5);
}

TEST(FootprintVectorizerTest, ConfiguredDilationWidensExteriorWithoutPavingCourtyard)
{
    auto labels = makeConstantGrid<int32_t>(30, 30, 0);
    fillRectangle<int32_t>(labels, 5, 5, 25, 25, 1);
    fillRectangle<int32_t>(labels, 10, 10, 14, 14, 0);
    auto stats = rectangleStats(1, 5, 5, 20, 20, 1.0);
    stats.pixelCount = 384;
    stats.physicalAreaSquareMetres = 384;

    BuildingReconstructionConfig config;
    config.regularizeRectangularFootprints = false;
    config.minHoleAreaSquareMetres = 5.0F;
    config.footprintDilationMetres = 0.25F;
    const auto result = FootprintVectorizer::vectorize(
        stats, labels, makeProjectedMetadata(30, 30), config);

    ASSERT_TRUE(result.success) << result.errorMessage;
    ASSERT_EQ(result.projectedFootprint.holes.size(), 1U);
    EXPECT_NEAR(projectedRingArea(result.projectedFootprint.outerRing), 484, 1e-5);
    EXPECT_NEAR(projectedRingArea(result.projectedFootprint.holes.front()), 16, 1e-5);
}

TEST(FootprintVectorizerTest, RectangleExpansionDoesNotStealNeighbouringInstancePixels)
{
    auto labels = makeConstantGrid<int32_t>(16, 16, 0);
    fillRectangle<int32_t>(labels, 2, 2, 12, 12, 1);
    labels.data[2 * 16 + 2] = 2;
    auto stats = rectangleStats(1, 2, 2, 10, 10, 1.0);
    stats.pixelCount = 99;
    stats.physicalAreaSquareMetres = 99;
    BuildingReconstructionConfig config;
    config.regularizeRectangularFootprints = false;
    config.footprintDilationMetres = 0.0F;
    const auto result = FootprintVectorizer::vectorize(
        stats, labels, makeProjectedMetadata(16, 16), config);
    ASSERT_TRUE(result.success) << result.errorMessage;
    // A smaller-epsilon fit can trim the affected corner without reverting
    // every other straight wall to the unsimplified pixel-edge outline.
    EXPECT_LE(result.projectedFootprint.outerRing.size(), 6U);
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
    config.footprintDilationMetres = 0.0F;
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
    config.footprintDilationMetres = 0.0F;
    // This fixture intentionally combines two facade orientations. Isolate
    // the edge fitter with a looser caller policy; production keeps the
    // configured 0.80 mask-overlap contract.
    config.minimumFootprintMaskIoU = 0.60F;
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
    EXPECT_GE(fitted.projectedFootprint.outerRing.size(), 6U);
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
    BuildingReconstructionConfig config;
    config.regularizeRectangularFootprints = false;
    config.minHoleAreaSquareMetres = 5.0F;
    config.footprintDilationMetres = 0.0F;
    const auto result = FootprintVectorizer::vectorize(
        stats, labels, makeProjectedMetadata(26, 26), config);
    ASSERT_TRUE(result.success) << result.errorMessage;
    ASSERT_EQ(result.projectedFootprint.holes.size(), 1U);
    EXPECT_GE(result.projectedFootprint.outerRing.size(), 6U);
    EXPECT_NEAR(projectedRingArea(result.projectedFootprint.outerRing), 355, 3.0);
    EXPECT_NEAR(projectedRingArea(result.projectedFootprint.holes.front()), 16, 1e-5);
}

TEST(FootprintVectorizerTest, DiagonalStairStepBecomesOrthogonalPolygon)
{
    // A 10x10 polygon with a diagonal chamfer/stair-step on one corner
    std::vector<ProjectedPoint> steppedRing = {
        {0.0, 0.0},
        {8.0, 0.0},
        {10.0, 2.0}, // Diagonal transition
        {10.0, 10.0},
        {0.0, 10.0}
    };
    const auto regularized = FootprintVectorizer::regularizeEdges(steppedRing, 2.5, 0.30);
    EXPECT_GE(regularized.size(), 4U);
    // Every corner in regularized should have dot product ~ 0 (orthogonal)
    for (std::size_t i = 0; i < regularized.size(); ++i)
    {
        const auto& pPrev = regularized[(i + regularized.size() - 1) % regularized.size()];
        const auto& pCurr = regularized[i];
        const auto& pNext = regularized[(i + 1) % regularized.size()];
        const double inX = pCurr.easting - pPrev.easting;
        const double inY = pCurr.northing - pPrev.northing;
        const double inLen = std::hypot(inX, inY);
        const double outX = pNext.easting - pCurr.easting;
        const double outY = pNext.northing - pCurr.northing;
        const double outLen = std::hypot(outX, outY);
        ASSERT_GT(inLen, 1e-4);
        ASSERT_GT(outLen, 1e-4);
        const double dot = (inX * outX + inY * outY) / (inLen * outLen);
        EXPECT_NEAR(dot, 0.0, 1e-3);
    }
}

TEST(FootprintVectorizerTest, CollapsesSubFiveMetreRasterStaircase)
{
    const std::vector<ProjectedPoint> steppedRing = {
        {0.0, 0.0}, {20.0, 0.0}, {20.0, 4.0}, {22.0, 4.0},
        {22.0, 6.0}, {20.0, 6.0}, {20.0, 20.0}, {0.0, 20.0}
    };

    const auto regularized =
        FootprintVectorizer::regularizeEdges(steppedRing, 2.5, 0.35);

    EXPECT_LT(regularized.size(), steppedRing.size());
    EXPECT_EQ(regularized.size(), 4U);
    for (std::size_t i = 0; i < regularized.size(); ++i)
    {
        const auto& a = regularized[i];
        const auto& b = regularized[(i + 1) % regularized.size()];
        EXPECT_GE(std::hypot(b.easting - a.easting, b.northing - a.northing), 2.5);
    }
}

TEST(FootprintVectorizerTest, RotatedBuildingPreservesOrientationAndOrthogonality)
{
    // A 20x10 rectangle rotated by 30 degrees (pi / 6)
    const double angle = std::numbers::pi / 6.0;
    const double cosA = std::cos(angle);
    const double sinA = std::sin(angle);
    auto rotatePt = [&](double x, double y) -> ProjectedPoint {
        return {x * cosA - y * sinA + 100.0, x * sinA + y * cosA + 200.0};
    };
    std::vector<ProjectedPoint> rotatedRing = {
        rotatePt(0.0, 0.0),
        rotatePt(20.0, 0.0),
        rotatePt(20.0, 10.0),
        rotatePt(0.0, 10.0)
    };
    const auto regularized = FootprintVectorizer::regularizeEdges(rotatedRing, 2.5, 0.30);
    EXPECT_EQ(regularized.size(), 4U);
    for (std::size_t i = 0; i < regularized.size(); ++i)
    {
        const auto& pPrev = regularized[(i + regularized.size() - 1) % regularized.size()];
        const auto& pCurr = regularized[i];
        const auto& pNext = regularized[(i + 1) % regularized.size()];
        const double inX = pCurr.easting - pPrev.easting;
        const double inY = pCurr.northing - pPrev.northing;
        const double inLen = std::hypot(inX, inY);
        const double outX = pNext.easting - pCurr.easting;
        const double outY = pNext.northing - pCurr.northing;
        const double outLen = std::hypot(outX, outY);
        const double dot = (inX * outX + inY * outY) / (inLen * outLen);
        EXPECT_NEAR(dot, 0.0, 1e-3);
    }
}

TEST(FootprintVectorizerTest, CourtyardHoleRegularizesOrthogonally)
{
    // Hole with a diagonal transition (CW winding in GIS coords)
    // In our coordinate convention: CCW has positive area, CW has negative area.
    std::vector<ProjectedPoint> hole = {
        {2.0, 2.0},
        {2.0, 8.0},
        {6.0, 8.0},
        {8.0, 6.0}, // Diagonal
        {8.0, 2.0}
    };
    const double area = FootprintVectorizer::calculateSignedArea(hole);
    const auto regularizedHole = FootprintVectorizer::regularizeEdges(hole, 2.5, 0.30);
    EXPECT_GE(regularizedHole.size(), 4U);
    const double regArea = FootprintVectorizer::calculateSignedArea(regularizedHole);
    // Winding direction is preserved
    EXPECT_EQ((area > 0.0), (regArea > 0.0));
    for (std::size_t i = 0; i < regularizedHole.size(); ++i)
    {
        const auto& pPrev = regularizedHole[(i + regularizedHole.size() - 1) % regularizedHole.size()];
        const auto& pCurr = regularizedHole[i];
        const auto& pNext = regularizedHole[(i + 1) % regularizedHole.size()];
        const double inX = pCurr.easting - pPrev.easting;
        const double inY = pCurr.northing - pPrev.northing;
        const double inLen = std::hypot(inX, inY);
        const double outX = pNext.easting - pCurr.easting;
        const double outY = pNext.northing - pCurr.northing;
        const double outLen = std::hypot(outX, outY);
        const double dot = (inX * outX + inY * outY) / (inLen * outLen);
        EXPECT_NEAR(dot, 0.0, 1e-3);
    }
}
TEST(FootprintVectorizerTest, CgalRegularizesNoisyClosedContourWithinShiftBudget)
{
    const std::vector<ProjectedPoint> noisy = {
        {500000.0, 4500000.0}, {500020.0, 4500000.3},
        {500020.1, 4500010.0}, {500000.1, 4500009.8}};
    const auto regularized =
        FootprintGeometryRegularizer::regularizeContourWithCgal(
            noisy, 3.0, 0.10);
    ASSERT_EQ(regularized.size(), 4U);
    for (std::size_t i = 0; i < regularized.size(); ++i)
    {
        const auto& prev = regularized[(i + 3) % 4];
        const auto& current = regularized[i];
        const auto& next = regularized[(i + 1) % 4];
        const double ax = prev.easting - current.easting;
        const double ay = prev.northing - current.northing;
        const double bx = next.easting - current.easting;
        const double by = next.northing - current.northing;
        EXPECT_NEAR((ax * bx + ay * by) /
                    (std::hypot(ax, ay) * std::hypot(bx, by)),
                    0.0, 1e-3);
    }
}

TEST(FootprintVectorizerTest, GeosSimplifiesOuterRingWithoutFillingCourtyard)
{
    FootprintPolygon<ProjectedPoint> footprint;
    footprint.outerRing = {
        {0.0, 0.0}, {10.0, 0.15}, {20.0, 0.0},
        {20.0, 10.0}, {20.0, 20.0}, {0.0, 20.0},
        {0.0, 10.0}};
    footprint.holes.push_back({
        {6.0, 6.0}, {6.0, 14.0}, {14.0, 14.0}, {14.0, 6.0}});
    const auto simplified =
        FootprintGeometryRegularizer::simplifyPolygonWithGeos(
            footprint, 0.5);
    ASSERT_EQ(simplified.holes.size(), 1U);
    EXPECT_LT(simplified.outerRing.size(), footprint.outerRing.size());
    EXPECT_EQ(simplified.holes.front().size(), 4U);
    EXPECT_GT(FootprintVectorizer::calculateSignedArea(
        simplified.outerRing), 0.0);
    EXPECT_LT(FootprintVectorizer::calculateSignedArea(
        simplified.holes.front()), 0.0);
}
} // namespace
