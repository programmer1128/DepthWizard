#include <gtest/gtest.h>

#include "BuildingReconstruction/BuildingFootprintDecomposer.h"
#include "BuildingReconstructionTestSupport.h"

namespace
{
using namespace depthwizard::test;

BuildingReconstructionConfig decompositionConfig()
{
    auto config = noMorphologyConfig();
    config.minDecomposedBlockAreaSquareMetres = 4.0F;
    config.minDecompositionCoverage = 0.80F;
    config.minDecompositionMaskIoU = 0.75F;
    config.decompositionResidualRatio = 0.02F;
    config.maxDecomposedBlocks = 8;
    return config;
}

TEST(BuildingFootprintDecomposerTest, PreservesSimpleRectangleAsOneBlock)
{
    FootprintPolygon<PixelPoint> footprint;
    footprint.outerRing = {
        {4.0, 4.0}, {24.0, 4.0}, {24.0, 16.0}, {4.0, 16.0}};

    const auto result = BuildingFootprintDecomposer::decompose(
        footprint, makeProjectedMetadata(32, 24), decompositionConfig());

    ASSERT_TRUE(result.success) << result.errorMessage;
    ASSERT_TRUE(result.accepted);
    ASSERT_EQ(result.blocks.size(), 1U);
    EXPECT_GT(result.coverageRatio, 0.95F);
    EXPECT_GT(result.maskIoU, 0.85F);
    EXPECT_GT(result.blocks.front().footprintAreaSquareMetres, 200.0F);
}

TEST(BuildingFootprintDecomposerTest, CourtyardKeepsUnifiedFootprint)
{
    FootprintPolygon<PixelPoint> footprint;
    footprint.outerRing = {
        {2.0, 2.0}, {28.0, 2.0}, {28.0, 28.0}, {2.0, 28.0}};
    footprint.holes.push_back({
        {10.0, 10.0}, {20.0, 10.0}, {20.0, 20.0}, {10.0, 20.0}});

    const auto result = BuildingFootprintDecomposer::decompose(
        footprint, makeProjectedMetadata(32, 32), decompositionConfig());

    EXPECT_TRUE(result.success);
    EXPECT_FALSE(result.accepted);
    EXPECT_TRUE(result.blocks.empty());
    EXPECT_FALSE(result.warnings.empty());
}

TEST(BuildingFootprintDecomposerTest, RejectsUnmodeledConnectingWing)
{
    FootprintPolygon<PixelPoint> footprint;
    footprint.outerRing = {
        {2.0, 2.0}, {25.0, 2.0}, {25.0, 7.0},
        {22.0, 7.0}, {22.0, 12.0}, {2.0, 12.0}};
    auto config = decompositionConfig();
    config.minDecomposedBlockAreaSquareMetres = 50.0F;
    config.minDecompositionCoverage = 0.80F;

    const auto result = BuildingFootprintDecomposer::decompose(
        footprint, makeProjectedMetadata(30, 20), config);

    EXPECT_TRUE(result.success);
    EXPECT_LT(result.coverageRatio, 0.95F);
    EXPECT_FALSE(result.accepted);
    EXPECT_TRUE(result.blocks.empty());
}

TEST(BuildingFootprintDecomposerTest, RepresentsConcaveLShapeWithMultipleBlocks)
{
    FootprintPolygon<PixelPoint> footprint;
    footprint.outerRing = {
        {3.0, 3.0}, {23.0, 3.0}, {23.0, 9.0},
        {10.0, 9.0}, {10.0, 22.0}, {3.0, 22.0}};

    const auto result = BuildingFootprintDecomposer::decompose(
        footprint, makeProjectedMetadata(30, 30), decompositionConfig());

    ASSERT_TRUE(result.success) << result.errorMessage;
    ASSERT_TRUE(result.accepted);
    EXPECT_GE(result.blocks.size(), 2U);
    EXPECT_GT(result.coverageRatio, 0.90F);
    EXPECT_GT(result.maskIoU, 0.80F);
}

TEST(BuildingFootprintDecomposerTest, FallsBackWhenBlocksCannotExplainMask)
{
    FootprintPolygon<PixelPoint> footprint;
    footprint.outerRing = {
        {15.0, 2.0}, {18.0, 11.0}, {28.0, 11.0}, {20.0, 17.0},
        {23.0, 27.0}, {15.0, 21.0}, {7.0, 27.0}, {10.0, 17.0},
        {2.0, 11.0}, {12.0, 11.0}};
    auto config = decompositionConfig();
    config.minDecompositionCoverage = 0.99F;
    config.minDecompositionMaskIoU = 0.99F;
    config.maxDecomposedBlocks = 2;

    const auto result = BuildingFootprintDecomposer::decompose(
        footprint, makeProjectedMetadata(32, 32), config);

    ASSERT_TRUE(result.success) << result.errorMessage;
    EXPECT_FALSE(result.accepted);
    EXPECT_TRUE(result.blocks.empty());
}
} // namespace
