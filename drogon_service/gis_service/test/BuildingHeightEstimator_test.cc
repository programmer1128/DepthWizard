#include <gtest/gtest.h>

#include "BuildingReconstruction/BuildingHeightEstimator.h"
#include "BuildingReconstructionTestSupport.h"

#include <algorithm>
#include <cstdint>

namespace
{
using namespace depthwizard::test;

FootprintPolygon<PixelPoint> squareFootprint(
    double left,
    double top,
    double right,
    double bottom)
{
    FootprintPolygon<PixelPoint> polygon;
    polygon.outerRing = {
        {left, top},
        {right, top},
        {right, bottom},
        {left, bottom}};
    return polygon;
}

TEST(BuildingHeightEstimatorTest, ComputesRobustBaseHeightAndRoofElevation)
{
    constexpr int width = 16;
    constexpr int height = 16;
    GeoreferencedSurfaceBundle surface = makeSurface(width, height, 100.0F, 0.0F);
    SemanticScene semantics = makeSemanticScene(width, height, SemanticClass::GROUND);
    fillRectangle<float>(surface.ndsm, 5, 5, 11, 11, 10.0F);
    fillRectangle<SemanticClass>(
        semantics.finalClassMap,
        5,
        5,
        11,
        11,
        SemanticClass::BUILDING);

    surface.ndsm.data[7 * width + 7] = 100.0F; // roof outlier
    surface.dtm.data[4 * width + 6] = 1000.0F; // ground-ring outlier

    BuildingReconstructionConfig config = noMorphologyConfig();
    config.groundBufferRadiusMetres = 2.0F;
    config.footprintErosionRadiusMetres = 1.0F;
    config.minRequiredSamples = 5;

    const BuildingHeightEstimate result = timedCall(
        "BuildingHeightEstimator::estimate robust-medians",
        [&]
        {
            return BuildingHeightEstimator::estimate(
                squareFootprint(5, 5, 10, 10),
                surface,
                semantics,
                makeProjectedMetadata(width, height),
                config);
        });

    ASSERT_TRUE(result.success) << result.errorMessage;
    EXPECT_FLOAT_EQ(result.representativeBaseElevation, 100.0F);
    EXPECT_FLOAT_EQ(result.heightAboveGround, 10.0F);
    EXPECT_FLOAT_EQ(result.roofElevation, 110.0F);
    EXPECT_GE(result.validGroundSampleCount, config.minRequiredSamples);
    EXPECT_GE(result.validRoofSampleCount, config.minRequiredSamples);
    EXPECT_NEAR(
        result.confidence,
        std::min(
            1.0F,
            static_cast<float>(result.validRoofSampleCount) /
                static_cast<float>(config.minRequiredSamples * 4)),
        1.0e-6F);
}

TEST(BuildingHeightEstimatorTest, FallsBackToUnerodedFootprintForSmallRoof)
{
    constexpr int width = 12;
    constexpr int height = 12;
    GeoreferencedSurfaceBundle surface = makeSurface(width, height, 50.0F, 0.0F);
    SemanticScene semantics = makeSemanticScene(width, height, SemanticClass::GROUND);
    fillRectangle<float>(surface.ndsm, 4, 4, 7, 7, 6.0F);
    fillRectangle<SemanticClass>(
        semantics.finalClassMap,
        4,
        4,
        7,
        7,
        SemanticClass::BUILDING);

    BuildingReconstructionConfig config = noMorphologyConfig();
    config.groundBufferRadiusMetres = 2.0F;
    config.footprintErosionRadiusMetres = 2.0F;
    config.minRequiredSamples = 5;

    const BuildingHeightEstimate result = BuildingHeightEstimator::estimate(
        squareFootprint(4, 4, 6, 6),
        surface,
        semantics,
        makeProjectedMetadata(width, height),
        config);

    ASSERT_TRUE(result.success) << result.errorMessage;
    EXPECT_FLOAT_EQ(result.heightAboveGround, 6.0F);
    EXPECT_FALSE(result.warnings.empty());
    EXPECT_GE(result.validRoofSampleCount, 5);
}

TEST(BuildingHeightEstimatorTest, EnforcesMinimumPositivePhysicalHeight)
{
    constexpr int width = 14;
    constexpr int height = 14;
    GeoreferencedSurfaceBundle surface = makeSurface(width, height, 20.0F, 0.0F);
    SemanticScene semantics = makeSemanticScene(width, height, SemanticClass::GROUND);
    fillRectangle<SemanticClass>(
        semantics.finalClassMap,
        4,
        4,
        10,
        10,
        SemanticClass::BUILDING);

    BuildingReconstructionConfig config = noMorphologyConfig();
    config.minRequiredSamples = 1;

    const BuildingHeightEstimate result = BuildingHeightEstimator::estimate(
        squareFootprint(4, 4, 9, 9),
        surface,
        semantics,
        makeProjectedMetadata(width, height),
        config);

    ASSERT_TRUE(result.success) << result.errorMessage;
    EXPECT_FLOAT_EQ(result.heightAboveGround, 0.1F);
    EXPECT_FLOAT_EQ(
        result.roofElevation,
        result.representativeBaseElevation + 0.1F);
}

TEST(BuildingHeightEstimatorTest, RejectsGridDimensionsThatDoNotMatchMetadata)
{
    GeoreferencedSurfaceBundle surface = makeSurface(12, 12, 100.0F, 5.0F);
    SemanticScene semantics = makeSemanticScene(12, 12);
    surface.ndsm.width = 11;

    const BuildingHeightEstimate result = BuildingHeightEstimator::estimate(
        squareFootprint(3, 3, 8, 8),
        surface,
        semantics,
        makeProjectedMetadata(12, 12),
        noMorphologyConfig());

    EXPECT_FALSE(result.success);
    EXPECT_FALSE(result.errorMessage.empty());
}

} // namespace
