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

TEST(BuildingHeightEstimatorTest, UpperTowerIsNotClampedToPodiumMedian)
{
    constexpr int width = 30;
    constexpr int height = 30;
    auto surface = makeSurface(width, height, 100.0F, 0.0F);
    auto semantics = makeSemanticScene(width, height, SemanticClass::GROUND);
    fillRectangle<float>(surface.ndsm, 4, 4, 24, 24, 10.0F);
    fillRectangle<float>(surface.ndsm, 18, 4, 24, 24, 50.0F);
    fillRectangle<SemanticClass>(semantics.finalClassMap, 4, 4, 24, 24,
                                 SemanticClass::BUILDING);
    auto config = noMorphologyConfig();

    const auto result = BuildingHeightEstimator::estimate(
        squareFootprint(4, 4, 23, 23), surface, semantics,
        makeProjectedMetadata(width, height), config);

    ASSERT_TRUE(result.success) << result.errorMessage;
    EXPECT_FLOAT_EQ(result.heightAboveGround, 50.0F);
    EXPECT_FLOAT_EQ(result.roofElevation, 150.0F);
}

TEST(BuildingHeightEstimatorTest, RoofSamplesStayInsideOwningInstance)
{
    constexpr int width = 26;
    constexpr int height = 22;
    auto surface = makeSurface(width, height, 100.0F, 0.0F);
    auto semantics = makeSemanticScene(width, height, SemanticClass::GROUND);
    fillRectangle<float>(surface.ndsm, 4, 4, 22, 18, 10.0F);
    fillRectangle<float>(surface.ndsm, 12, 4, 22, 18, 40.0F);
    fillRectangle<SemanticClass>(semantics.finalClassMap, 4, 4, 22, 18,
                                 SemanticClass::BUILDING);
    RasterGrid<int32_t> labels;
    labels.width = width;
    labels.height = height;
    labels.data.assign(width * height, 0);
    fillRectangle<int32_t>(labels, 4, 4, 12, 18, 1);
    fillRectangle<int32_t>(labels, 12, 4, 22, 18, 2);

    const auto footprint = squareFootprint(4, 4, 21, 17);
    const auto config = noMorphologyConfig();
    const auto unconstrained = BuildingHeightEstimator::estimate(
        footprint, surface, semantics, makeProjectedMetadata(width, height),
        config);
    const auto constrained = BuildingHeightEstimator::estimate(
        footprint, surface, semantics, makeProjectedMetadata(width, height),
        config, nullptr, &labels, 1);

    ASSERT_TRUE(unconstrained.success) << unconstrained.errorMessage;
    ASSERT_TRUE(constrained.success) << constrained.errorMessage;
    EXPECT_FLOAT_EQ(unconstrained.heightAboveGround, 40.0F);
    EXPECT_FLOAT_EQ(constrained.heightAboveGround, 10.0F);
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

TEST(BuildingHeightEstimatorTest, RejectsHeightBelowPhysicalMinimum)
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

    EXPECT_FALSE(result.success);
    EXPECT_FALSE(result.errorMessage.empty());
}

TEST(BuildingHeightEstimatorTest, FallsBackToFootprintDtmWhenExteriorGroundIsUnavailable)
{
    constexpr int width = 14;
    constexpr int height = 14;
    GeoreferencedSurfaceBundle surface = makeSurface(width, height, 1500.0F, 8.0F);
    SemanticScene semantics =
        makeSemanticScene(width, height, SemanticClass::VEGETATION);
    fillRectangle<SemanticClass>(
        semantics.finalClassMap,
        4,
        4,
        10,
        10,
        SemanticClass::BUILDING);

    BuildingReconstructionConfig config = noMorphologyConfig();
    config.minRequiredSamples = 5;

    const BuildingHeightEstimate result = BuildingHeightEstimator::estimate(
        squareFootprint(4, 4, 9, 9),
        surface,
        semantics,
        makeProjectedMetadata(width, height),
        config);

    ASSERT_TRUE(result.success) << result.errorMessage;
    EXPECT_FLOAT_EQ(result.representativeBaseElevation, 1500.0F);
    EXPECT_FLOAT_EQ(result.heightAboveGround, 8.0F);
    EXPECT_FLOAT_EQ(result.roofElevation, 1508.0F);
    EXPECT_FALSE(result.warnings.empty());
    EXPECT_EQ(
        result.baseElevationPerOuterVertex.size(),
        squareFootprint(4, 4, 9, 9).outerRing.size());
}

TEST(BuildingHeightEstimatorTest, PreservesFootprintAcrossSteepTerrainWithWarning)
{
    constexpr int width = 16;
    constexpr int height = 16;
    GeoreferencedSurfaceBundle surface = makeSurface(width, height, 100.0F, 0.0F);
    SemanticScene semantics = makeSemanticScene(width, height, SemanticClass::GROUND);

    for (int row = 4; row <= 10; ++row)
    {
        for (int column = 4; column <= 10; ++column)
        {
            const std::size_t index =
                static_cast<std::size_t>(row) * width + column;
            surface.dtm.data[index] =
                100.0F + static_cast<float>(column - 4) * 3.0F;
            surface.ndsm.data[index] = 10.0F;
            semantics.finalClassMap.data[index] = SemanticClass::BUILDING;
        }
    }

    BuildingReconstructionConfig config = noMorphologyConfig();
    config.minRequiredSamples = 5;
    config.maxFootprintElevationDeltaMetres = 8.0F;

    const BuildingHeightEstimate result = BuildingHeightEstimator::estimate(
        squareFootprint(4, 4, 10, 10),
        surface,
        semantics,
        makeProjectedMetadata(width, height),
        config);

    EXPECT_TRUE(result.success);
    EXPECT_GT(result.footprintElevationDeltaMetres, 8.0F);
    ASSERT_FALSE(result.warnings.empty());
    bool foundWarning = false;
    for (const auto& w : result.warnings)
    {
        if (w.find("terrain relief") != std::string::npos &&
            w.find("exceeds limit") != std::string::npos)
        {
            foundWarning = true;
            break;
        }
    }
    EXPECT_TRUE(foundWarning);
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

TEST(BuildingHeightEstimatorTest, IgnoresSurfaceFusionSuppressedZerosInRoofSampling)
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

    // Inject fusion zeros into half the roof interior
    for (int r = 5; r < 11; ++r)
    {
        for (int c = 5; c < 8; ++c)
        {
            surface.ndsm.data[r * width + c] = 0.0F;
        }
    }

    BuildingReconstructionConfig config = noMorphologyConfig();
    config.groundBufferRadiusMetres = 2.0F;
    config.footprintErosionRadiusMetres = 1.0F;
    config.minRequiredSamples = 5;

    const BuildingHeightEstimate result = BuildingHeightEstimator::estimate(
        squareFootprint(5, 5, 10, 10),
        surface,
        semantics,
        makeProjectedMetadata(width, height),
        config);

    ASSERT_TRUE(result.success) << result.errorMessage;
    EXPECT_FLOAT_EQ(result.heightAboveGround, 10.0F);
}

} // namespace
