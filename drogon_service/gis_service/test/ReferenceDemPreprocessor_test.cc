#include <gtest/gtest.h>

#include "ReferenceTerrainService/ReferenceDemPreprocessor.h"

#include <chrono>
#include <cmath>
#include <cstdint>
#include <format>
#include <functional>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <string_view>
#include <type_traits>
#include <utility>
#include <vector>

namespace
{

template<typename T>
RasterGrid<T> makeGrid(
    const int width,
    const int height,
    std::vector<T> values)
{
    RasterGrid<T> grid;
    grid.width = width;
    grid.height = height;
    grid.data = std::move(values);
    return grid;
}

template<typename T>
RasterGrid<T> makeConstantGrid(
    const int width,
    const int height,
    const T value)
{
    return makeGrid<T>(
        width,
        height,
        std::vector<T>(
            static_cast<std::size_t>(width) *
                static_cast<std::size_t>(height),
            value));
}

SceneInput makeGeoreferencedScene(
    const int width,
    const int height,
    const double pixelWidth = 1.0,
    const double pixelHeight = -1.0)
{
    SpatialMetadata metadata;
    metadata.width = width;
    metadata.height = height;
    metadata.geoTransform = {
        100.0,
        pixelWidth,
        0.0,
        200.0,
        0.0,
        pixelHeight};
    metadata.pixelSizeX = std::abs(pixelWidth);
    metadata.pixelSizeY = std::abs(pixelHeight);
    metadata.isGeoreferenced = true;

    SceneInput scene;
    scene.jobId = "reference-dem-test";
    scene.inputMode = PipelineMode::GEOREFERENCED;
    scene.width = width;
    scene.height = height;
    scene.spatialMetadata = metadata;
    scene.sourceFormat = "GTiff";
    return scene;
}

template<typename Callable>
decltype(auto) timedCall(
    const std::string_view operation,
    Callable&& callable)
{
    const auto start = std::chrono::steady_clock::now();

    if constexpr (std::is_void_v<std::invoke_result_t<Callable>>)
    {
        std::invoke(std::forward<Callable>(callable));
        const auto elapsed = std::chrono::steady_clock::now() - start;
        const double microseconds =
            std::chrono::duration<double, std::micro>(elapsed).count();
        std::cout << std::format(
            "[LATENCY] operation={} elapsed_us={:.3f}\n",
            operation,
            microseconds);
    }
    else
    {
        auto result = std::invoke(std::forward<Callable>(callable));
        const auto elapsed = std::chrono::steady_clock::now() - start;
        const double microseconds =
            std::chrono::duration<double, std::micro>(elapsed).count();
        std::cout << std::format(
            "[LATENCY] operation={} elapsed_us={:.3f}\n",
            operation,
            microseconds);
        return result;
    }
}

template<typename T>
void expectExactGrid(
    const RasterGrid<T>& actual,
    const int expectedWidth,
    const int expectedHeight,
    const std::vector<T>& expected)
{
    ASSERT_EQ(actual.width, expectedWidth);
    ASSERT_EQ(actual.height, expectedHeight);
    ASSERT_EQ(actual.data.size(), expected.size());

    for (std::size_t index = 0; index < expected.size(); ++index)
    {
        EXPECT_EQ(actual.data[index], expected[index])
            << "Grid mismatch at flat index " << index;
    }
}

void expectFloatGridNear(
    const RasterGrid<float>& actual,
    const int expectedWidth,
    const int expectedHeight,
    const std::vector<float>& expected,
    const float tolerance = 1.0e-6F)
{
    ASSERT_EQ(actual.width, expectedWidth);
    ASSERT_EQ(actual.height, expectedHeight);
    ASSERT_EQ(actual.data.size(), expected.size());

    for (std::size_t index = 0; index < expected.size(); ++index)
    {
        EXPECT_NEAR(actual.data[index], expected[index], tolerance)
            << "Grid mismatch at flat index " << index;
    }
}

} // namespace

TEST(ReferenceDemPreprocessorTest, ComputesGeometricMeanGsdFromAffineTransform)
{
    SpatialMetadata metadata;
    metadata.geoTransform = {0.0, 4.0, 0.0, 0.0, 0.0, -9.0};

    const float gsd = timedCall(
        "ReferenceDemPreprocessor::computeGsd",
        [&] { return ReferenceDemPreprocessor::computeGsd(metadata); });

    EXPECT_FLOAT_EQ(gsd, 6.0F);
}

TEST(ReferenceDemPreprocessorTest, InvalidPixelAreaUsesOneMeterFallback)
{
    SpatialMetadata metadata;
    metadata.geoTransform = {0.0, 0.0, 0.0, 0.0, 0.0, -10.0};

    const float gsd = timedCall(
        "ReferenceDemPreprocessor::computeGsd zero-area",
        [&] { return ReferenceDemPreprocessor::computeGsd(metadata); });

    EXPECT_FLOAT_EQ(gsd, 1.0F);
}

TEST(ReferenceDemPreprocessorTest, RemovesCentralSpikeFromMock4x4Grid)
{
    RasterGrid<float> dem = makeGrid<float>(
        4,
        4,
        {
            10.0F, 10.0F, 10.0F, 10.0F,
            10.0F, 100.0F, 10.0F, 10.0F,
            10.0F, 10.0F, 10.0F, 10.0F,
            10.0F, 10.0F, 10.0F, 10.0F,
        });

    timedCall(
        "ReferenceDemPreprocessor::removeSpikes 4x4",
        [&] { ReferenceDemPreprocessor::removeSpikes(dem, 35.0F); });

    expectFloatGridNear(
        dem,
        4,
        4,
        std::vector<float>(16, 10.0F));
}

TEST(ReferenceDemPreprocessorTest, PreservesBoundaryValuesAndNoData)
{
    const float nan = std::numeric_limits<float>::quiet_NaN();
    RasterGrid<float> dem = makeGrid<float>(
        4,
        4,
        {
            999.0F, 10.0F, 10.0F, 10.0F,
            10.0F, nan,   10.0F, 10.0F,
            10.0F, 10.0F, 10.0F, 10.0F,
            10.0F, 10.0F, 10.0F, -999.0F,
        });

    timedCall(
        "ReferenceDemPreprocessor::removeSpikes boundary/nodata",
        [&] { ReferenceDemPreprocessor::removeSpikes(dem, 35.0F); });

    EXPECT_FLOAT_EQ(dem.data.front(), 999.0F);
    EXPECT_FLOAT_EQ(dem.data.back(), -999.0F);
    EXPECT_TRUE(std::isnan(dem.data[5]));
}

TEST(ReferenceDemPreprocessorTest, MorphologicalOpeningRemovesMock4x4HighFeature)
{
    RasterGrid<float> dem = makeConstantGrid<float>(4, 4, 10.0F);
    dem.data[5] = 50.0F;

    const RasterGrid<float> opened = timedCall(
        "ReferenceDemPreprocessor::applyAdaptiveGroundFilter 4x4",
        [&]
        {
            return ReferenceDemPreprocessor::applyAdaptiveGroundFilter(
                dem,
                30.0F);
        });

    expectFloatGridNear(
        opened,
        4,
        4,
        std::vector<float>(16, 10.0F));
}

TEST(ReferenceDemPreprocessorTest, MorphologicalOpeningPreservesConstantNegativeTerrain)
{
    const RasterGrid<float> dem =
        makeConstantGrid<float>(4, 4, -125.5F);

    const RasterGrid<float> opened = timedCall(
        "ReferenceDemPreprocessor::applyAdaptiveGroundFilter negative",
        [&]
        {
            return ReferenceDemPreprocessor::applyAdaptiveGroundFilter(
                dem,
                30.0F);
        });

    expectFloatGridNear(
        opened,
        4,
        4,
        std::vector<float>(16, -125.5F));
}

TEST(ReferenceDemPreprocessorTest, OpeningRadiusRemainsMetricOnHalfMetreImagery)
{
    auto dem = makeConstantGrid<float>(180, 180, 100.0F);
    // 30 m-wide reference roof contamination survived the old 7.5 m radius.
    for (int row = 60; row < 120; ++row)
        for (int column = 60; column < 120; ++column)
            dem.data[row * 180 + column] = 140.0F;
    const auto result = ReferenceDemPreprocessor::applyAdaptiveGroundFilter(dem, 0.5F);
    EXPECT_FLOAT_EQ(result.data[90 * 180 + 90], 100.0F);
    EXPECT_FLOAT_EQ(result.data[0], 100.0F);
}

TEST(ReferenceDemPreprocessorTest, InpaintsCenterVoidUsingExactIdwMath)
{
    const float nan = std::numeric_limits<float>::quiet_NaN();
    RasterGrid<float> dem = makeGrid<float>(
        4,
        4,
        {
             0.0F, 10.0F, 20.0F, 90.0F,
            30.0F, nan,   50.0F, 90.0F,
            60.0F, 70.0F, 80.0F, 90.0F,
            90.0F, 90.0F, 90.0F, 90.0F,
        });
    RasterGrid<uint8_t> validMask =
        makeConstantGrid<uint8_t>(4, 4, uint8_t{0});

    timedCall(
        "ReferenceDemPreprocessor::inpaintVoidsIDW 4x4",
        [&]
        {
            ReferenceDemPreprocessor::inpaintVoidsIDW(
                dem,
                validMask,
                1);
        });

    // The eight neighbours have a total IDW numerator of 240 and total
    // weight of 6, so the exact reconstructed center elevation is 40.
    EXPECT_NEAR(dem.data[5], 40.0F, 1.0e-6F);
    expectExactGrid<uint8_t>(
        validMask,
        4,
        4,
        std::vector<uint8_t>(16, uint8_t{1}));
}

TEST(ReferenceDemPreprocessorTest, UnrecoverableAllNoDataGridRemainsInvalid)
{
    const float nan = std::numeric_limits<float>::quiet_NaN();
    RasterGrid<float> dem = makeConstantGrid<float>(4, 4, nan);
    RasterGrid<uint8_t> validMask =
        makeConstantGrid<uint8_t>(4, 4, uint8_t{1});

    timedCall(
        "ReferenceDemPreprocessor::inpaintVoidsIDW all-nodata",
        [&]
        {
            ReferenceDemPreprocessor::inpaintVoidsIDW(
                dem,
                validMask,
                2);
        });

    for (const float value : dem.data)
    {
        EXPECT_TRUE(std::isnan(value));
    }
    expectExactGrid<uint8_t>(
        validMask,
        4,
        4,
        std::vector<uint8_t>(16, uint8_t{0}));
}

TEST(ReferenceDemPreprocessorTest, FlatMock4x4TerrainHasExactInteriorConfidence)
{
    const RasterGrid<float> dtm =
        makeConstantGrid<float>(4, 4, 100.0F);
    const RasterGrid<uint8_t> validMask =
        makeConstantGrid<uint8_t>(4, 4, uint8_t{1});

    const RasterGrid<float> confidence = timedCall(
        "ReferenceDemPreprocessor::computeTerrainConfidence flat-4x4",
        [&]
        {
            return ReferenceDemPreprocessor::computeTerrainConfidence(
                dtm,
                validMask);
        });

    expectFloatGridNear(
        confidence,
        4,
        4,
        {
            0.0F, 0.0F, 0.0F, 0.0F,
            0.0F, 1.0F, 1.0F, 0.0F,
            0.0F, 1.0F, 1.0F, 0.0F,
            0.0F, 0.0F, 0.0F, 0.0F,
        });
}

TEST(ReferenceDemPreprocessorTest, LinearSlopeUsesExactConfidenceFormula)
{
    const RasterGrid<float> dtm = makeGrid<float>(
        4,
        4,
        {
             0.0F, 10.0F, 20.0F, 30.0F,
             0.0F, 10.0F, 20.0F, 30.0F,
             0.0F, 10.0F, 20.0F, 30.0F,
             0.0F, 10.0F, 20.0F, 30.0F,
        });
    RasterGrid<uint8_t> validMask =
        makeConstantGrid<uint8_t>(4, 4, uint8_t{1});
    validMask.data[5] = uint8_t{0};

    const RasterGrid<float> confidence = timedCall(
        "ReferenceDemPreprocessor::computeTerrainConfidence slope-4x4",
        [&]
        {
            return ReferenceDemPreprocessor::computeTerrainConfidence(
                dtm,
                validMask);
        });

    constexpr float expectedSlopeConfidence = 2.0F / 3.0F;
    EXPECT_FLOAT_EQ(confidence.data[5], 0.0F);
    EXPECT_NEAR(
        confidence.data[6],
        expectedSlopeConfidence,
        1.0e-6F);
    EXPECT_NEAR(
        confidence.data[9],
        expectedSlopeConfidence,
        1.0e-6F);
    EXPECT_NEAR(
        confidence.data[10],
        expectedSlopeConfidence,
        1.0e-6F);
}

TEST(ReferenceDemPreprocessorTest, InvalidGradientStencilProducesZeroConfidence)
{
    RasterGrid<float> dtm = makeConstantGrid<float>(4, 4, 100.0F);
    const RasterGrid<uint8_t> validMask =
        makeConstantGrid<uint8_t>(4, 4, uint8_t{1});
    dtm.data[4] = std::numeric_limits<float>::quiet_NaN();

    const RasterGrid<float> confidence = timedCall(
        "ReferenceDemPreprocessor::computeTerrainConfidence invalid-stencil",
        [&]
        {
            return ReferenceDemPreprocessor::computeTerrainConfidence(
                dtm,
                validMask);
        });

    EXPECT_TRUE(std::isfinite(confidence.data[5]));
    EXPECT_FLOAT_EQ(confidence.data[5], 0.0F);
}

TEST(ReferenceDemPreprocessorTest, ProcessBuildsCompleteBundleForConstantMock4x4Dem)
{
    const RasterGrid<float> warpedDem =
        makeConstantGrid<float>(4, 4, 12.5F);
    const SceneInput scene = makeGeoreferencedScene(4, 4, 30.0, -30.0);

    const ReferenceTerrainBundle result = timedCall(
        "ReferenceDemPreprocessor::process constant-4x4",
        [&]
        {
            return ReferenceDemPreprocessor::process(
                warpedDem,
                scene,
                "Copernicus_30m");
        });

    EXPECT_EQ(result.demSource, "Copernicus_30m");
    EXPECT_FLOAT_EQ(result.sourceResolutionMeters, 30.0F);
    EXPECT_TRUE(result.warnings.empty());

    expectFloatGridNear(
        result.rawWarpedDem,
        4,
        4,
        std::vector<float>(16, 12.5F));
    expectFloatGridNear(
        result.correctedTerrainPrior,
        4,
        4,
        std::vector<float>(16, 12.5F));
    expectExactGrid<uint8_t>(
        result.validMask,
        4,
        4,
        std::vector<uint8_t>(16, uint8_t{1}));
    expectFloatGridNear(
        result.confidence,
        4,
        4,
        {
            0.0F, 0.0F, 0.0F, 0.0F,
            0.0F, 1.0F, 1.0F, 0.0F,
            0.0F, 1.0F, 1.0F, 0.0F,
            0.0F, 0.0F, 0.0F, 0.0F,
        });
}

TEST(ReferenceDemPreprocessorTest, ProcessRejectsMissingSpatialMetadata)
{
    const RasterGrid<float> warpedDem =
        makeConstantGrid<float>(4, 4, 10.0F);
    SceneInput scene;
    scene.width = 4;
    scene.height = 4;
    scene.spatialMetadata = std::nullopt;

    EXPECT_THROW(
        timedCall(
            "ReferenceDemPreprocessor::process missing-metadata",
            [&]
            {
                return ReferenceDemPreprocessor::process(
                    warpedDem,
                    scene,
                    "SRTMGL1");
            }),
        std::invalid_argument);
}

TEST(ReferenceDemPreprocessorTest, ProcessRejectsSceneAndRasterDimensionMismatch)
{
    const RasterGrid<float> warpedDem =
        makeConstantGrid<float>(3, 3, 10.0F);
    const SceneInput scene = makeGeoreferencedScene(4, 4);

    EXPECT_THROW(
        timedCall(
            "ReferenceDemPreprocessor::process dimension-mismatch",
            [&]
            {
                return ReferenceDemPreprocessor::process(
                    warpedDem,
                    scene,
                    "SRTMGL1");
            }),
        std::invalid_argument);
}

TEST(ReferenceDemPreprocessorTest, ProcessRejectsEmptyRaster)
{
    const RasterGrid<float> emptyDem;
    const SceneInput scene = makeGeoreferencedScene(0, 0);

    EXPECT_THROW(
        timedCall(
            "ReferenceDemPreprocessor::process empty-raster",
            [&]
            {
                return ReferenceDemPreprocessor::process(
                    emptyDem,
                    scene,
                    "SRTMGL1");
            }),
        std::invalid_argument);
}
