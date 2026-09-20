#include <gtest/gtest.h>

#include "BuildingReconstruction/FootprintVectorizer.h"
#include "BuildingReconstructionTestSupport.h"

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

} // namespace
