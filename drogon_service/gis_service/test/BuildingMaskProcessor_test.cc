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

    config.maxFootprintElevationDeltaMetres = 0.0F;
    EXPECT_FALSE(config.validate());
    config.maxFootprintElevationDeltaMetres = 8.0F;

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
    semantics.finalClassMap =
        makeConstantGrid<SemanticClass>(4, 4, SemanticClass::BUILDING);

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
    semantics.finalClassMap.data[3 * 7 + 3] = SemanticClass::BUILDING;
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
    semantics.finalClassMap.data[1 * 8 + 1] = SemanticClass::BUILDING;
    fillRectangle(
        semantics.finalClassMap,
        4,
        4,
        6,
        6,
        SemanticClass::BUILDING);
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

TEST(BuildingMaskProcessorTest, RejectsProbabilityWhenFinalClassIsNotBuilding)
{
    SemanticScene semantics = makeSemanticScene(4, 4, SemanticClass::GROUND);
    semantics.buildingProbability.data.assign(16, 0.99F);
    semantics.semanticConfidence.data.assign(16, 0.99F);
    const RasterGrid<uint8_t> validMask =
        makeConstantGrid<uint8_t>(4, 4, uint8_t{1});

    BuildingReconstructionConfig config = noMorphologyConfig();
    const BuildingMaskResult result = BuildingMaskProcessor::createCleanMask(
        semantics,
        validMask,
        makeProjectedMetadata(4, 4),
        config);

    ASSERT_TRUE(result.success) << result.errorMessage;
    EXPECT_EQ(
        std::count(result.cleanMask.data.begin(), result.cleanMask.data.end(), uint8_t{1}),
        0);
}

TEST(BuildingMaskProcessorTest, RejectsLowConfidenceBuildingDecision)
{
    SemanticScene semantics =
        makeSemanticScene(4, 4, SemanticClass::BUILDING);
    semantics.buildingProbability.data.assign(16, 0.99F);
    semantics.semanticConfidence.data.assign(16, 0.20F);
    const RasterGrid<uint8_t> validMask =
        makeConstantGrid<uint8_t>(4, 4, uint8_t{1});

    BuildingReconstructionConfig config = noMorphologyConfig();
    config.minBuildingSemanticConfidence = 0.60F;
    const BuildingMaskResult result = BuildingMaskProcessor::createCleanMask(
        semantics,
        validMask,
        makeProjectedMetadata(4, 4),
        config);

    ASSERT_TRUE(result.success) << result.errorMessage;
    EXPECT_EQ(
        std::count(result.cleanMask.data.begin(), result.cleanMask.data.end(), uint8_t{1}),
        0);
}

TEST(BuildingMaskProcessorTest, RecoversUnknownRoofUsingProbabilityAndMetricNdsm)
{
    SemanticScene semantics =
        makeSemanticScene(6, 6, SemanticClass::UNKNOWN);
    semantics.buildingProbability.data.assign(36, 0.40F);
    semantics.semanticConfidence.data.assign(36, 0.0F);
    const RasterGrid<float> ndsm = makeConstantGrid(6, 6, 8.0F);
    const RasterGrid<uint8_t> validMask =
        makeConstantGrid<uint8_t>(6, 6, uint8_t{1});

    BuildingReconstructionConfig config = noMorphologyConfig();
    config.buildingProbabilityThreshold = 0.50F;
    config.buildingRecoveryProbabilityThreshold = 0.35F;
    config.minRecoveryNdsmHeightMetres = 2.0F;
    config.recoveryDistanceMetres = 1.0F;

    const BuildingMaskResult result = BuildingMaskProcessor::createCleanMask(
        semantics,
        ndsm,
        validMask,
        makeProjectedMetadata(6, 6),
        config);

    ASSERT_TRUE(result.success) << result.errorMessage;
    // Height alone cannot invent a building with no strong semantic seed.
    EXPECT_EQ(result.recoveredCandidatePixelCount, 0);
    EXPECT_EQ(
        std::count(
            result.cleanMask.data.begin(),
            result.cleanMask.data.end(),
            uint8_t{1}),
        0);

    semantics.finalClassMap.data[2 * 6 + 2] = SemanticClass::BUILDING;
    semantics.buildingProbability.data[2 * 6 + 2] = 0.95F;
    semantics.semanticConfidence.data[2 * 6 + 2] = 0.95F;
    const auto grown = BuildingMaskProcessor::createCleanMask(
        semantics, ndsm, validMask, makeProjectedMetadata(6, 6), config);
    ASSERT_TRUE(grown.success);
    EXPECT_EQ(grown.recoveredCandidatePixelCount, 4);
    EXPECT_EQ(std::count(grown.cleanMask.data.begin(), grown.cleanMask.data.end(), uint8_t{1}), 5);
}

TEST(BuildingMaskProcessorTest, MetricEdgeRecoveryStopsAtCompetingClassEvidence)
{
    SemanticScene semantics = makeSemanticScene(9, 5, SemanticClass::GROUND);
    const auto pixel = [](int x) { return 2 * 9 + x; };
    semantics.finalClassMap.data[pixel(1)] = SemanticClass::BUILDING;
    semantics.buildingProbability.data[pixel(1)] = 0.95F;
    for (int x = 2; x <= 4; ++x)
    {
        semantics.finalClassMap.data[pixel(x)] = SemanticClass::UNKNOWN;
        semantics.buildingProbability.data[pixel(x)] = 0.40F;
    }
    const auto ndsm = makeConstantGrid(9, 5, 8.0F);
    const auto valid = makeConstantGrid<uint8_t>(9, 5, uint8_t{1});
    auto config = noMorphologyConfig();
    config.buildingProbabilityThreshold = 0.50F;
    config.recoveryDistanceMetres = 2.0F;

    auto result = BuildingMaskProcessor::createCleanMask(
        semantics, ndsm, valid, makeProjectedMetadata(9, 5), config);
    ASSERT_TRUE(result.success) << result.errorMessage;
    EXPECT_EQ(result.cleanMask.data[pixel(2)], 1);
    EXPECT_EQ(result.cleanMask.data[pixel(3)], 1);
    EXPECT_EQ(result.cleanMask.data[pixel(4)], 0);

    // An UNKNOWN margin failure is not permission to cross stronger road
    // evidence, even when the nDSM happens to be high.
    semantics.roadProbability.data[pixel(2)] = 0.60F;
    result = BuildingMaskProcessor::createCleanMask(
        semantics, ndsm, valid, makeProjectedMetadata(9, 5), config);
    ASSERT_TRUE(result.success) << result.errorMessage;
    EXPECT_EQ(result.cleanMask.data[pixel(2)], 0);
    EXPECT_EQ(result.cleanMask.data[pixel(3)], 0);
}

TEST(BuildingMaskProcessorTest, DoesNotRecoverKnownVegetationAsBuilding)
{
    SemanticScene semantics =
        makeSemanticScene(6, 6, SemanticClass::VEGETATION);
    semantics.buildingProbability.data.assign(36, 0.40F);
    const RasterGrid<float> ndsm = makeConstantGrid(6, 6, 8.0F);
    const RasterGrid<uint8_t> validMask =
        makeConstantGrid<uint8_t>(6, 6, uint8_t{1});

    const BuildingMaskResult result = BuildingMaskProcessor::createCleanMask(
        semantics,
        ndsm,
        validMask,
        makeProjectedMetadata(6, 6),
        noMorphologyConfig());

    ASSERT_TRUE(result.success) << result.errorMessage;
    EXPECT_EQ(result.recoveredCandidatePixelCount, 0);
    EXPECT_EQ(
        std::count(
            result.cleanMask.data.begin(),
            result.cleanMask.data.end(),
            uint8_t{1}),
        0);
}

TEST(BuildingMaskProcessorTest, ClosingCannotBridgeConfidentRoadAlley)
{
    auto semantics = makeSemanticScene(120, 100, SemanticClass::UNKNOWN);
    fillRectangle(semantics.finalClassMap, 20, 30, 40, 70, SemanticClass::BUILDING);
    fillRectangle(semantics.finalClassMap, 54, 30, 74, 70, SemanticClass::BUILDING);
    fillRectangle(semantics.buildingProbability, 20, 30, 40, 70, .95F);
    fillRectangle(semantics.buildingProbability, 54, 30, 74, 70, .95F);
    fillRectangle(semantics.finalClassMap, 40, 0, 54, 100, SemanticClass::ROAD);
    fillRectangle(semantics.roadProbability, 40, 0, 54, 100, .95F);
    auto config = noMorphologyConfig();
    config.closingRadiusMetres = 9.0F;
    const auto result = BuildingMaskProcessor::createCleanMask(semantics,
        makeConstantGrid(120, 100, 10.0F), makeConstantGrid<uint8_t>(120, 100, 1),
        makeProjectedMetadata(120, 100, .5, -.5), config);
    ASSERT_TRUE(result.success);
    for (int y = 30; y < 70; ++y) {
        EXPECT_EQ(result.cleanMask.data[y * 120 + 47], 0);
        EXPECT_EQ(result.cleanMask.data[y * 120 + 30], 1);
        EXPECT_EQ(result.cleanMask.data[y * 120 + 64], 1);
    }
}

TEST(BuildingMaskProcessorTest, NineMetreClosingBridgesUnknownTreeOcclusion)
{
    auto semantics = makeSemanticScene(120, 100, SemanticClass::UNKNOWN);
    fillRectangle(semantics.finalClassMap, 20, 30, 40, 70, SemanticClass::BUILDING);
    fillRectangle(semantics.finalClassMap, 54, 30, 74, 70, SemanticClass::BUILDING);
    fillRectangle(semantics.buildingProbability, 20, 30, 40, 70, .95F);
    fillRectangle(semantics.buildingProbability, 54, 30, 74, 70, .95F);

    auto config = noMorphologyConfig();
    config.closingRadiusMetres = 9.0F;
    const auto result = BuildingMaskProcessor::createCleanMask(
        semantics,
        makeConstantGrid(120, 100, 10.0F),
        makeConstantGrid<uint8_t>(120, 100, 1),
        makeProjectedMetadata(120, 100, .5, -.5),
        config);

    ASSERT_TRUE(result.success) << result.errorMessage;
    EXPECT_EQ(result.closingKernelWidth, 37);
    EXPECT_EQ(result.closingKernelHeight, 37);
    EXPECT_EQ(result.cleanMask.data[50 * 120 + 47], 1);
}

TEST(BuildingMaskProcessorTest, UnknownPixelsWithBuildingProbAndPhysicalHeightSpawnSeed)
{
    constexpr int width = 10;
    constexpr int height = 10;
    SemanticScene semantics = makeSemanticScene(width, height, SemanticClass::UNKNOWN);
    fillRectangle(semantics.buildingProbability, 3, 3, 7, 7, 0.45F);
    semantics.semanticConfidence = makeConstantGrid(width, height, 0.0F);

    const RasterGrid<float> ndsm = makeConstantGrid(width, height, 8.0F);
    const RasterGrid<uint8_t> validMask = makeConstantGrid<uint8_t>(width, height, uint8_t{1});

    BuildingReconstructionConfig config = noMorphologyConfig();
    config.buildingProbabilityThreshold = 0.40F;
    config.minRecoveryNdsmHeightMetres = 1.8F;

    const BuildingMaskResult result = BuildingMaskProcessor::createCleanMask(
        semantics,
        ndsm,
        validMask,
        makeProjectedMetadata(width, height),
        config);

    ASSERT_TRUE(result.success) << result.errorMessage;
    for (int y = 3; y < 7; ++y)
    {
        for (int x = 3; x < 7; ++x)
        {
            EXPECT_EQ(result.cleanMask.data[y * width + x], 1);
        }
    }
    EXPECT_EQ(result.cleanMask.data[0], 0);
    EXPECT_EQ(result.cleanMask.data[9 * width + 9], 0);
}

} // namespace
