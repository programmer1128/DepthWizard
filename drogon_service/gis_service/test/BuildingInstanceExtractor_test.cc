#include <gtest/gtest.h>

#include "BuildingReconstruction/BuildingInstanceExtractor.h"
#include "BuildingReconstructionTestSupport.h"

#include <algorithm>
#include <cstdint>

namespace
{
using namespace depthwizard::test;

BuildingMaskResult makeSuccessfulMask(int width, int height)
{
    BuildingMaskResult result;
    result.success = true;
    result.cleanMask = makeConstantGrid<uint8_t>(width, height, uint8_t{0});
    return result;
}

TEST(BuildingInstanceExtractorTest, EmptyMaskReturnsSuccessfulEmptyExtraction)
{
    const BuildingMaskResult mask = makeSuccessfulMask(12, 12);
    const SemanticScene semantics = makeSemanticScene(12, 12);

    const ComponentExtractionResult result = timedCall(
        "BuildingInstanceExtractor::extract empty-mask",
        [&]
        {
            return BuildingInstanceExtractor::extract(
                mask,
                semantics,
                makeProjectedMetadata(12, 12),
                noMorphologyConfig());
        });

    ASSERT_TRUE(result.success) << result.errorMessage;
    EXPECT_EQ(result.acceptedComponentCount, 0);
    EXPECT_TRUE(result.components.empty());
    expectGridEqual<int32_t>(
        result.labelRaster,
        12,
        12,
        std::vector<int32_t>(144, 0));
}

TEST(BuildingInstanceExtractorTest, ExtractsTwoSeparatedBuildingsWithDeterministicIds)
{
    BuildingMaskResult mask = makeSuccessfulMask(24, 14);
    fillRectangle<uint8_t>(mask.cleanMask, 2, 3, 9, 11, uint8_t{1});
    fillRectangle<uint8_t>(mask.cleanMask, 15, 3, 22, 11, uint8_t{1});

    SemanticScene semantics = makeSemanticScene(24, 14);
    semantics.buildingProbability = makeConstantGrid(24, 14, 0.8F);
    semantics.semanticConfidence = makeConstantGrid(24, 14, 0.9F);

    BuildingReconstructionConfig config = noMorphologyConfig();
    config.connectivity = 4;

    const ComponentExtractionResult result = timedCall(
        "BuildingInstanceExtractor::extract two-buildings",
        [&]
        {
            return BuildingInstanceExtractor::extract(
                mask,
                semantics,
                makeProjectedMetadata(24, 14),
                config);
        });

    ASSERT_TRUE(result.success) << result.errorMessage;
    ASSERT_EQ(result.acceptedComponentCount, 2);
    ASSERT_EQ(result.components.size(), 2U);
    EXPECT_EQ(result.components[0].componentId, 1);
    EXPECT_EQ(result.components[1].componentId, 2);
    EXPECT_LT(result.components[0].pixelBoundingBox.x,
              result.components[1].pixelBoundingBox.x);

    for (const ComponentStats& component : result.components)
    {
        EXPECT_GT(component.pixelCount, 0);
        EXPECT_DOUBLE_EQ(
            component.physicalAreaSquareMetres,
            static_cast<double>(component.pixelCount));
        EXPECT_NEAR(component.meanBuildingProbability, 0.8F, 1.0e-6F);
        EXPECT_NEAR(component.meanSemanticConfidence, 0.9F, 1.0e-6F);
        EXPECT_NEAR(component.minSemanticConfidence, 0.9F, 1.0e-6F);
    }

    EXPECT_TRUE(std::any_of(
        result.labelRaster.data.begin(),
        result.labelRaster.data.end(),
        [](int32_t value) { return value == 1; }));
    EXPECT_TRUE(std::any_of(
        result.labelRaster.data.begin(),
        result.labelRaster.data.end(),
        [](int32_t value) { return value == 2; }));
}

TEST(BuildingInstanceExtractorTest, RejectsUnprojectedCoordinateSystem)
{
    BuildingMaskResult mask = makeSuccessfulMask(12, 12);
    fillRectangle<uint8_t>(mask.cleanMask, 2, 2, 10, 10, uint8_t{1});
    const SemanticScene semantics = makeSemanticScene(12, 12);
    SpatialMetadata metadata = makeProjectedMetadata(12, 12);
    metadata.projectionRef = "GEOGCS[\"WGS 84\"]";

    const ComponentExtractionResult result = BuildingInstanceExtractor::extract(
        mask,
        semantics,
        metadata,
        noMorphologyConfig());

    EXPECT_FALSE(result.success);
    EXPECT_FALSE(result.errorMessage.empty());
}

TEST(BuildingInstanceExtractorTest, RejectsMismatchedSemanticDimensions)
{
    const BuildingMaskResult mask = makeSuccessfulMask(12, 12);
    SemanticScene semantics = makeSemanticScene(12, 12);
    semantics.semanticConfidence.width = 11;

    const ComponentExtractionResult result = BuildingInstanceExtractor::extract(
        mask,
        semantics,
        makeProjectedMetadata(12, 12),
        noMorphologyConfig());

    EXPECT_FALSE(result.success);
    EXPECT_FALSE(result.errorMessage.empty());
}

TEST(BuildingInstanceExtractorTest, PreservesNarrowTownhouseAndFullPixelArea)
{
    BuildingMaskResult mask = makeSuccessfulMask(40, 40);
    // 2 m wide at 0.5 m/pixel: no pixel can reach the old 2.5 m seed radius.
    fillRectangle<uint8_t>(mask.cleanMask, 10, 4, 14, 36, uint8_t{1});
    const auto result = BuildingInstanceExtractor::extract(
        mask, makeSemanticScene(40, 40),
        makeProjectedMetadata(40, 40, 0.5, -0.5), noMorphologyConfig());
    ASSERT_TRUE(result.success);
    ASSERT_EQ(result.components.size(), 1U);
    EXPECT_EQ(result.components[0].pixelCount, 128);
    EXPECT_DOUBLE_EQ(result.components[0].physicalAreaSquareMetres, 32.0);
    EXPECT_EQ(result.components[0].pixelBoundingBox.width, 4);
    for (std::size_t i = 0; i < mask.cleanMask.data.size(); ++i)
        EXPECT_EQ(result.labelRaster.data[i] != 0, mask.cleanMask.data[i] != 0);
}

TEST(BuildingInstanceExtractorTest, KeepsImageEdgeRoofsAndSeparatesDiagonalContacts)
{
    BuildingMaskResult mask = makeSuccessfulMask(12, 12);
    fillRectangle<uint8_t>(mask.cleanMask, 0, 0, 4, 4, uint8_t{1});
    fillRectangle<uint8_t>(mask.cleanMask, 4, 4, 8, 8, uint8_t{1});
    auto config = noMorphologyConfig();
    config.connectivity = 8; // Output still has one outer ring per instance.
    const auto result = BuildingInstanceExtractor::extract(
        mask, makeSemanticScene(12, 12), makeProjectedMetadata(12, 12), config);
    ASSERT_TRUE(result.success);
    ASSERT_EQ(result.components.size(), 2U);
    EXPECT_EQ(result.components[0].pixelCount, 16);
    EXPECT_EQ(result.components[1].pixelCount, 16);
    EXPECT_NE(result.labelRaster.data[0], 0);
}
TEST(BuildingInstanceExtractorTest, SplitsTouchingRoofsAtHeightStepWithoutLosingPixels)
{
    auto mask = makeSuccessfulMask(32, 20);
    fillRectangle<uint8_t>(mask.cleanMask, 2, 2, 30, 18, 1);
    auto semantics = makeSemanticScene(32, 20, SemanticClass::BUILDING);
    semantics.buildingProbability = makeConstantGrid(32, 20, 0.95F);
    auto heights = makeConstantGrid(32, 20, 10.0F);
    fillRectangle(heights, 16, 2, 30, 18, 25.0F);
    auto config = noMorphologyConfig();
    ASSERT_TRUE(config.splitSupportedInstances);
    ASSERT_FLOAT_EQ(config.instanceHeightStepMetres, 2.0F);
    ASSERT_FLOAT_EQ(config.minInstanceSeedAreaSquareMetres, 15.0F);
    const auto result = BuildingInstanceExtractor::extract(mask, semantics,
        makeProjectedMetadata(32, 20), config, &heights);
    ASSERT_TRUE(result.success);
    ASSERT_EQ(result.components.size(), 2U);
    EXPECT_NE(result.labelRaster.data[10 * 32 + 8], result.labelRaster.data[10 * 32 + 24]);
    for (std::size_t i = 0; i < mask.cleanMask.data.size(); ++i)
        EXPECT_EQ(result.labelRaster.data[i] != 0, mask.cleanMask.data[i] != 0);
    const auto repeated = BuildingInstanceExtractor::extract(mask, semantics,
        makeProjectedMetadata(32, 20), config, &heights);
    EXPECT_EQ(result.labelRaster.data, repeated.labelRaster.data);
}

TEST(BuildingInstanceExtractorTest, ProbabilityValleySeparatesRoofsButUniformBlockStaysWhole)
{
    auto mask = makeSuccessfulMask(32, 20);
    fillRectangle<uint8_t>(mask.cleanMask, 2, 2, 30, 18, 1);
    auto semantics = makeSemanticScene(32, 20, SemanticClass::BUILDING);
    semantics.buildingProbability = makeConstantGrid(32, 20, 0.95F);
    auto config = noMorphologyConfig();
    config.splitSupportedInstances = true;
    auto result = BuildingInstanceExtractor::extract(mask, semantics,
        makeProjectedMetadata(32, 20), config);
    ASSERT_EQ(result.components.size(), 1U);
    fillRectangle(semantics.buildingProbability, 15, 2, 17, 18, 0.4F);
    result = BuildingInstanceExtractor::extract(mask, semantics,
        makeProjectedMetadata(32, 20), config);
    ASSERT_EQ(result.components.size(), 2U);
    EXPECT_EQ(result.components[0].pixelCount + result.components[1].pixelCount, 28 * 16);
}

TEST(BuildingInstanceExtractorTest, LargeBlockDoesNotEraseSeparateNarrowRoof)
{
    auto mask = makeSuccessfulMask(100, 80);
    fillRectangle<uint8_t>(mask.cleanMask, 2, 2, 60, 70, 1);
    fillRectangle<uint8_t>(mask.cleanMask, 80, 10, 84, 50, 1);
    auto semantics = makeSemanticScene(100, 80, SemanticClass::BUILDING);
    semantics.buildingProbability = makeConstantGrid(100, 80, 0.95F);
    const auto result = BuildingInstanceExtractor::extract(mask, semantics,
        makeProjectedMetadata(100, 80, .5, -.5), BuildingReconstructionConfig{});
    ASSERT_EQ(result.components.size(), 2U);
    EXPECT_EQ(result.components[1].pixelCount, 160);
}
} // namespace
