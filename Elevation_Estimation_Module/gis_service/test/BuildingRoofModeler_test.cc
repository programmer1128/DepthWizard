#include <gtest/gtest.h>

#include "BuildingReconstruction/BuildingRoofModeler.h"
#include "BuildingReconstructionTestSupport.h"

#include <algorithm>
#include <cmath>

namespace
{
using namespace depthwizard::test;

DecomposedBuildingBlock makeBlock()
{
    DecomposedBuildingBlock block;
    block.pixelCorners = {
        PixelPoint{4.0, 4.0}, PixelPoint{36.0, 4.0},
        PixelPoint{36.0, 24.0}, PixelPoint{4.0, 24.0}};
    const auto metadata = makeProjectedMetadata(42, 30);
    for (std::size_t index = 0; index < 4; ++index)
    {
        const auto& pixel = block.pixelCorners[index];
        block.projectedCorners[index] = {
            metadata.geoTransform[0] + pixel.column,
            metadata.geoTransform[3] + pixel.row};
    }
    block.footprintAreaSquareMetres = 640.0F;
    return block;
}

BuildingReconstructionConfig roofConfig()
{
    auto config = noMorphologyConfig();
    config.enableLod2RoofFitting = true;
    config.minRoofFitConfidence = 0.20F;
    config.minRoofRiseMetres = 1.0F;
    config.maxRoofRiseMetres = 10.0F;
    config.roofBoundaryBandMetres = 2.0F;
    config.commercialFlatRoofAreaSquareMetres = 1000.0F;
    return config;
}

TEST(BuildingRoofModelerTest, KeepsUniformEvidenceFlat)
{
    const auto metadata = makeProjectedMetadata(42, 30);
    auto ndsm = makeConstantGrid(42, 30, 10.0F);
    auto valid = makeConstantGrid<uint8_t>(42, 30, uint8_t{1});
    std::vector<DecomposedBuildingBlock> blocks{makeBlock()};

    BuildingRoofModeler::fit(
        blocks, ndsm, valid, metadata, 10.0F, roofConfig());

    ASSERT_EQ(blocks.size(), 1U);
    EXPECT_EQ(blocks[0].roof.type, RoofType::FLAT);
    EXPECT_FLOAT_EQ(blocks[0].roof.eaveHeightAboveGround, 10.0F);
    EXPECT_FLOAT_EQ(blocks[0].roof.ridgeHeightAboveGround, 10.0F);
}

TEST(BuildingRoofModelerTest, DoesNotTurnFlatRoofEquipmentIntoHip)
{
    const auto metadata = makeProjectedMetadata(42, 30);
    auto ndsm = makeConstantGrid(42, 30, 25.0F);
    auto valid = makeConstantGrid<uint8_t>(42, 30, uint8_t{1});
    for (int row = 10; row < 14; ++row)
        for (int column = 17; column < 23; ++column)
            ndsm.data[static_cast<std::size_t>(row) * ndsm.width + column] = 29.0F;
    std::vector<DecomposedBuildingBlock> blocks{makeBlock()};

    BuildingRoofModeler::fit(blocks, ndsm, valid, metadata, 25.0F, roofConfig());

    ASSERT_EQ(blocks.size(), 1U);
    EXPECT_EQ(blocks[0].roof.type, RoofType::FLAT);
    EXPECT_FLOAT_EQ(blocks[0].roof.eaveHeightAboveGround, 25.0F);
}

TEST(BuildingRoofModelerTest, ClassifiesFiveDegreePlaneAsFlat)
{
    const auto metadata = makeProjectedMetadata(42, 30);
    auto ndsm = makeConstantGrid(42, 30, 0.0F);
    auto valid = makeConstantGrid<uint8_t>(42, 30, uint8_t{1});
    for (int row = 4; row <= 24; ++row)
        for (int column = 4; column <= 36; ++column)
            ndsm.data[static_cast<std::size_t>(row) * ndsm.width + column] =
                12.0F + (row - 4) * std::tan(5.0 * 3.141592653589793 / 180.0);
    std::vector<DecomposedBuildingBlock> blocks{makeBlock()};

    BuildingRoofModeler::fit(blocks, ndsm, valid, metadata, 13.0F, roofConfig());

    ASSERT_EQ(blocks.size(), 1U);
    EXPECT_EQ(blocks[0].roof.type, RoofType::FLAT);
}

TEST(BuildingRoofModelerTest, SmoothsPixelNoiseBeforePitchClassification)
{
    const auto metadata = makeProjectedMetadata(42, 30);
    auto ndsm = makeConstantGrid(42, 30, 0.0F);
    auto valid = makeConstantGrid<uint8_t>(42, 30, uint8_t{1});
    for (int row = 4; row <= 24; ++row)
        for (int column = 4; column <= 36; ++column)
            ndsm.data[static_cast<std::size_t>(row) * ndsm.width + column] =
                25.0F + 1.5F * std::sin(
                    column * 2.0 * 3.141592653589793 / 3.0);
    std::vector<DecomposedBuildingBlock> blocks{makeBlock()};

    BuildingRoofModeler::fit(blocks, ndsm, valid, metadata, 25.0F,
                            roofConfig());

    ASSERT_EQ(blocks.size(), 1U);
    EXPECT_EQ(blocks[0].roof.type, RoofType::FLAT);
    EXPECT_NEAR(blocks[0].roof.eaveHeightAboveGround, 25.0F, 0.1F);
}

TEST(BuildingRoofModelerTest, SeparatesSharpPodiumAndTowerHeightStep)
{
    const auto metadata = makeProjectedMetadata(42, 30);
    auto ndsm = makeConstantGrid(42, 30, 20.0F);
    auto valid = makeConstantGrid<uint8_t>(42, 30, uint8_t{1});
    for (int row = 4; row < 24; ++row)
        for (int column = 20; column < 36; ++column)
            ndsm.data[static_cast<std::size_t>(row) * ndsm.width + column] = 45.0F;
    std::vector<DecomposedBuildingBlock> blocks{makeBlock()};

    BuildingRoofModeler::fit(blocks, ndsm, valid, metadata, 45.0F, roofConfig());

    ASSERT_EQ(blocks.size(), 2U);
    EXPECT_EQ(blocks[0].roof.type, RoofType::FLAT);
    EXPECT_EQ(blocks[1].roof.type, RoofType::FLAT);
    const float lower = std::min(blocks[0].roof.eaveHeightAboveGround,
                                 blocks[1].roof.eaveHeightAboveGround);
    const float upper = std::max(blocks[0].roof.eaveHeightAboveGround,
                                 blocks[1].roof.eaveHeightAboveGround);
    EXPECT_NEAR(lower, 20.0F, 0.1F);
    EXPECT_NEAR(upper, 45.0F, 0.1F);
    EXPECT_NEAR(blocks[0].pixelCorners[1].column,
                blocks[1].pixelCorners[0].column, 0.1);
}

TEST(BuildingRoofModelerTest, LargeCommercialBlockRemainsFlatDespiteApparentPitch)
{
    const auto metadata = makeProjectedMetadata(42, 30);
    auto ndsm = makeConstantGrid(42, 30, 0.0F);
    auto valid = makeConstantGrid<uint8_t>(42, 30, uint8_t{1});
    for (int row = 4; row <= 24; ++row)
        for (int column = 4; column <= 36; ++column)
            ndsm.data[static_cast<std::size_t>(row) * ndsm.width + column] =
                20.0F + 4.0F * std::max(0.0F,
                    1.0F - std::abs(static_cast<float>(row - 14)) / 10.0F);
    auto config = roofConfig();
    config.commercialFlatRoofAreaSquareMetres = 250.0F;
    std::vector<DecomposedBuildingBlock> blocks{makeBlock()};

    BuildingRoofModeler::fit(blocks, ndsm, valid, metadata, 22.0F, config);

    ASSERT_EQ(blocks.size(), 1U);
    EXPECT_EQ(blocks[0].roof.type, RoofType::FLAT);
}

TEST(BuildingRoofModelerTest, LargeParcelKeepsSmallDecomposedBlocksFlat)
{
    const auto metadata = makeProjectedMetadata(44, 18);
    auto ndsm = makeConstantGrid(44, 18, 0.0F);
    auto valid = makeConstantGrid<uint8_t>(44, 18, uint8_t{1});
    std::vector<DecomposedBuildingBlock> blocks;
    for (int left : {2, 22})
    {
        DecomposedBuildingBlock block;
        block.pixelCorners = {{{static_cast<double>(left), 2.0},
                               {static_cast<double>(left + 16), 2.0},
                               {static_cast<double>(left + 16), 12.0},
                               {static_cast<double>(left), 12.0}}};
        for (std::size_t corner = 0; corner < 4; ++corner)
            block.projectedCorners[corner] = {
                500000.0 + block.pixelCorners[corner].column,
                2000000.0 + block.pixelCorners[corner].row};
        block.footprintAreaSquareMetres = 160.0F;
        blocks.push_back(block);
        for (int row = 2; row <= 12; ++row)
            for (int column = left; column <= left + 16; ++column)
                ndsm.data[static_cast<std::size_t>(row) * ndsm.width + column] =
                    10.0F + 4.0F * std::max(
                        0.0F, 1.0F - std::abs(row - 7) / 5.0F);
    }
    auto config = roofConfig();
    config.commercialFlatRoofAreaSquareMetres = 250.0F;

    BuildingRoofModeler::fit(blocks, ndsm, valid, metadata, 12.0F, config);

    ASSERT_EQ(blocks.size(), 2U);
    EXPECT_EQ(blocks[0].roof.type, RoofType::FLAT);
    EXPECT_EQ(blocks[1].roof.type, RoofType::FLAT);
}

TEST(BuildingRoofModelerTest, TallUnsplitStepKeepsUpperFlatRoof)
{
    const auto metadata = makeProjectedMetadata(42, 30);
    auto ndsm = makeConstantGrid(42, 30, 20.0F);
    auto valid = makeConstantGrid<uint8_t>(42, 30, uint8_t{1});
    for (int row = 4; row <= 24; ++row)
        for (int column = 20; column <= 36; ++column)
            ndsm.data[static_cast<std::size_t>(row) * ndsm.width + column] =
                45.0F;
    auto config = roofConfig();
    config.minDecomposedBlockAreaSquareMetres = 500.0F;
    std::vector<DecomposedBuildingBlock> blocks{makeBlock()};

    BuildingRoofModeler::fit(blocks, ndsm, valid, metadata, 20.0F, config);

    ASSERT_EQ(blocks.size(), 1U);
    EXPECT_EQ(blocks[0].roof.type, RoofType::FLAT);
    EXPECT_NEAR(blocks[0].roof.eaveHeightAboveGround, 45.0F, 0.1F);
}

TEST(BuildingRoofModelerTest, FitsLongSupportedRidgeAsGable)
{
    const auto metadata = makeProjectedMetadata(42, 30);
    auto ndsm = makeConstantGrid(42, 30, 0.0F);
    auto valid = makeConstantGrid<uint8_t>(42, 30, uint8_t{1});
    for (int row = 4; row <= 24; ++row)
    {
        const float rise = 4.0F * std::max(
            0.0F, 1.0F - std::abs(static_cast<float>(row - 14)) / 10.0F);
        for (int column = 4; column <= 36; ++column)
            ndsm.data[static_cast<std::size_t>(row) * ndsm.width + column] =
                10.0F + rise;
    }
    std::vector<DecomposedBuildingBlock> blocks{makeBlock()};

    BuildingRoofModeler::fit(
        blocks, ndsm, valid, metadata, 12.0F, roofConfig());

    EXPECT_EQ(blocks[0].roof.type, RoofType::GABLE);
    EXPECT_GT(blocks[0].roof.ridgeHeightAboveGround,
              blocks[0].roof.eaveHeightAboveGround);
    EXPECT_GT(blocks[0].roof.confidence, 0.20F);
}

TEST(BuildingRoofModelerTest, FitsCompactPeakAsHip)
{
    const auto metadata = makeProjectedMetadata(42, 30);
    auto ndsm = makeConstantGrid(42, 30, 0.0F);
    auto valid = makeConstantGrid<uint8_t>(42, 30, uint8_t{1});
    for (int row = 4; row <= 24; ++row)
    {
        for (int column = 4; column <= 36; ++column)
        {
            const float radius = std::hypot(
                static_cast<float>(column - 20),
                static_cast<float>(row - 14));
            const float rise = 5.0F * std::max(0.0F, 1.0F - radius / 12.0F);
            ndsm.data[static_cast<std::size_t>(row) * ndsm.width + column] =
                9.0F + rise;
        }
    }
    std::vector<DecomposedBuildingBlock> blocks{makeBlock()};

    BuildingRoofModeler::fit(
        blocks, ndsm, valid, metadata, 11.0F, roofConfig());

    EXPECT_EQ(blocks[0].roof.type, RoofType::HIP);
    EXPECT_GT(blocks[0].roof.ridgeHeightAboveGround,
              blocks[0].roof.eaveHeightAboveGround);
}
} // namespace
