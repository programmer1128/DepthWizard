#include <gtest/gtest.h>

#include "BuildingReconstruction/BuildingMaskProcessor.h"
#include "BuildingReconstructionTestSupport.h"

#include <limits>
#include <vector>

namespace
{
using namespace depthwizard::test;

TEST(BuildingMaskProcessorTest, ConfigurationValidatorRejectsInvalidValues)
{
    BuildingReconstructionConfig config;
    EXPECT_TRUE(config.validate());

    config.connectivity = 6;
    EXPECT_FALSE(config.validate());
    config.connectivity = 4;

    config.buildingProbabilityThreshold = 1.1F;
    EXPECT_FALSE(config.validate());
    config.buildingProbabilityThreshold = 0.5F;

    config.openingRadiusMetres =
        std::numeric_limits<float>::quiet_NaN();
    EXPECT_FALSE(config.validate());
}

TEST(BuildingMaskProcessorTest, ThresholdsMock4x4ProbabilityAndAppliesValidityMaskExactly)
{
    SemanticScene semantics = makeSemanticScene(4, 4);
    semantics.buildingProbability.data = {
        0.49F, 0.50F, 0.51F, 0.90F,
        0.10F, 0.80F, 0.20F, 0.70F,
        0.60F, 0.30F, 0.55F, 0.45F,
        0.99F, 0.01F, 0.50F, 0.40F};
    RasterGrid<uint8_t> validMask =
        makeConstantGrid<uint8_t>(4, 4, uint8_t{1});
    validMask.data[3] = 0;

    BuildingReconstructionConfig config = noMorphologyConfig();
    config.buildingProbabilityThreshold = 0.5F;

    const BuildingMaskResult result = timedCall(
        "BuildingMaskProcessor::createCleanMask threshold-4x4",
        [&]
        {
            return BuildingMaskProcessor::createCleanMask(
                semantics,
                validMask,
                makeProjectedMetadata(4, 4),
                config);
        });

    ASSERT_TRUE(result.success) << result.errorMessage;
    expectGridEqual<uint8_t>(
        result.cleanMask,
        4,
        4,
        {0, 1, 1, 0,
         0, 1, 0, 1,
         1, 0, 1, 0,
         1, 0, 1, 0});
    EXPECT_FLOAT_EQ(result.thresholdUsed, 0.5F);
    EXPECT_EQ(result.openingKernelWidth, 1);
    EXPECT_EQ(result.closingKernelWidth, 1);
}

TEST(BuildingMaskProcessorTest, OpeningRemovesIsolatedBuildingPixel)
{
    SemanticScene semantics = makeSemanticScene(7, 7);
    semantics.buildingProbability.data[3 * 7 + 3] = 1.0F;
    const RasterGrid<uint8_t> validMask =
        makeConstantGrid<uint8_t>(7, 7, uint8_t{1});

    BuildingReconstructionConfig config = noMorphologyConfig();
    config.openingRadiusMetres = 1.0F;

    const BuildingMaskResult result = BuildingMaskProcessor::createCleanMask(
        semantics,
        validMask,
        makeProjectedMetadata(7, 7),
        config);

    ASSERT_TRUE(result.success) << result.errorMessage;
    EXPECT_EQ(
        std::count(result.cleanMask.data.begin(), result.cleanMask.data.end(), uint8_t{1}),
        0);
    EXPECT_EQ(result.openingKernelWidth, 3);
    EXPECT_EQ(result.openingKernelHeight, 3);
}

TEST(BuildingMaskProcessorTest, RejectsSmallComponentsUsingPhysicalArea)
{
    SemanticScene semantics = makeSemanticScene(8, 8);
    semantics.buildingProbability.data[1 * 8 + 1] = 1.0F;
    fillRectangle(semantics.buildingProbability, 4, 4, 6, 6, 1.0F);
    const RasterGrid<uint8_t> validMask =
        makeConstantGrid<uint8_t>(8, 8, uint8_t{1});

    BuildingReconstructionConfig config = noMorphologyConfig();
    config.minBuildingAreaSquareMetres = 3.0F;

    const BuildingMaskResult result = BuildingMaskProcessor::createCleanMask(
        semantics,
        validMask,
        makeProjectedMetadata(8, 8),
        config);

    ASSERT_TRUE(result.success) << result.errorMessage;
    EXPECT_EQ(result.smallComponentRejectedPixelCount, 1);
    EXPECT_EQ(
        std::count(result.cleanMask.data.begin(), result.cleanMask.data.end(), uint8_t{1}),
        4);
}

TEST(BuildingMaskProcessorTest, ComputesAffineAwareRectangularKernelDimensions)
{
    SemanticScene semantics = makeSemanticScene(9, 9);
    const RasterGrid<uint8_t> validMask =
        makeConstantGrid<uint8_t>(9, 9, uint8_t{1});
    BuildingReconstructionConfig config = noMorphologyConfig();
    config.openingRadiusMetres = 2.0F;
    config.closingRadiusMetres = 3.0F;

    const BuildingMaskResult result = BuildingMaskProcessor::createCleanMask(
        semantics,
        validMask,
        makeProjectedMetadata(9, 9, 2.0, 1.0),
        config);

    ASSERT_TRUE(result.success) << result.errorMessage;
    EXPECT_EQ(result.openingKernelWidth, 3);
    EXPECT_EQ(result.openingKernelHeight, 5);
    EXPECT_EQ(result.closingKernelWidth, 5);
    EXPECT_EQ(result.closingKernelHeight, 7);
}

TEST(BuildingMaskProcessorTest, RejectsInvalidProbabilityWithoutProcessing)
{
    SemanticScene semantics = makeSemanticScene(4, 4);
    semantics.buildingProbability.data[5] =
        std::numeric_limits<float>::quiet_NaN();
    const RasterGrid<uint8_t> validMask =
        makeConstantGrid<uint8_t>(4, 4, uint8_t{1});

    const BuildingMaskResult result = BuildingMaskProcessor::createCleanMask(
        semantics,
        validMask,
        makeProjectedMetadata(4, 4),
        noMorphologyConfig());

    EXPECT_FALSE(result.success);
    EXPECT_FALSE(result.errorMessage.empty());
}

} // namespace
