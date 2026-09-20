#include <gtest/gtest.h>

#include "ImageTilingService/OutputStitching/MetricOutputStitcher.h"

#include <algorithm>
#include <array>
#include <chrono>
#include <cctype>
#include <cmath>
#include <cstdint>
#include <filesystem>
#include <format>
#include <fstream>
#include <functional>
#include <iostream>
#include <stdexcept>
#include <string>
#include <string_view>
#include <type_traits>
#include <utility>
#include <vector>

namespace
{

class PerTestLogger
{
public:
    PerTestLogger()
    {
        const testing::TestInfo* info =
            testing::UnitTest::GetInstance()->current_test_info();

        const std::string suite =
            info != nullptr ? sanitize(info->test_suite_name()) : "UnknownSuite";

        const std::string test =
            info != nullptr ? sanitize(info->name()) : "UnknownTest";

        std::error_code error;
        std::filesystem::create_directories("test_logs", error);

        if (error)
        {
            throw std::runtime_error(
                std::format(
                    "Failed to create test_logs directory: {}",
                    error.message()));
        }

        const std::filesystem::path path =
            std::filesystem::path("test_logs") /
            std::format("output_log_{}_{}.log", suite, test);

        output_.open(path, std::ios::out | std::ios::trunc);

        if (!output_)
        {
            throw std::runtime_error(
                std::format("Failed to open test log: {}", path.string()));
        }

        writeMessage(std::format("Starting {}.{}", suite, test));
    }

    void writeLatency(
        const std::string_view operation,
        const std::chrono::nanoseconds elapsed)
    {
        const double microseconds =
            std::chrono::duration<double, std::micro>(elapsed).count();

        writeMessage(
            std::format(
                "[LATENCY] operation={} elapsed_us={:.3f}",
                operation,
                microseconds));
    }

    void writeMessage(const std::string_view message)
    {
        std::cout << message << '\n';
        output_ << message << '\n';
        output_.flush();
    }

private:
    static std::string sanitize(std::string value)
    {
        std::ranges::transform(
            value,
            value.begin(),
            [](const unsigned char character)
            {
                return std::isalnum(character) != 0
                    ? static_cast<char>(character)
                    : '_';
            });

        return value;
    }

    std::ofstream output_;
};

template<typename Callable>
auto timedCall(
    PerTestLogger& logger,
    const std::string_view operation,
    Callable&& callable) -> std::invoke_result_t<Callable>
{
    using ReturnType = std::invoke_result_t<Callable>;

    const auto start = std::chrono::steady_clock::now();

    try
    {
        ReturnType result =
            std::invoke(std::forward<Callable>(callable));

        logger.writeLatency(
            operation,
            std::chrono::steady_clock::now() - start);

        return result;
    }
    catch (...)
    {
        logger.writeLatency(
            std::format("{} [THREW]", operation),
            std::chrono::steady_clock::now() - start);

        throw;
    }
}

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

RasterGrid<float> makeConstantFloatGrid(
    const int width,
    const int height,
    const float value)
{
    return makeGrid<float>(
        width,
        height,
        std::vector<float>(
            static_cast<std::size_t>(width) *
                static_cast<std::size_t>(height),
            value));
}

TileInferenceResult makeTile(
    const uint32_t tileId,
    const int sourceX,
    const int sourceY,
    const int width,
    const int height,
    std::vector<float> ndsm,
    std::vector<float> confidence,
    std::vector<uint8_t> validMask,
    const std::array<float, 6>& logits)
{
    TileInferenceResult tile;

    tile.tileId = tileId;
    tile.placement.sourceX = sourceX;
    tile.placement.sourceY = sourceY;
    tile.placement.paddedWidth = width;
    tile.placement.paddedHeight = height;
    tile.placement.validStartX = 0;
    tile.placement.validStartY = 0;
    tile.placement.validWidth = width;
    tile.placement.validHeight = height;

    tile.metricNdsm =
        makeGrid<float>(width, height, std::move(ndsm));

    tile.ndsmConfidence =
        makeGrid<float>(width, height, std::move(confidence));

    tile.validMask =
        makeGrid<uint8_t>(width, height, std::move(validMask));

    tile.semanticLogits.groundLogits =
        makeConstantFloatGrid(width, height, logits[0]);

    tile.semanticLogits.buildingLogits =
        makeConstantFloatGrid(width, height, logits[1]);

    tile.semanticLogits.roadLogits =
        makeConstantFloatGrid(width, height, logits[2]);

    tile.semanticLogits.vegetationLogits =
        makeConstantFloatGrid(width, height, logits[3]);

    tile.semanticLogits.waterLogits =
        makeConstantFloatGrid(width, height, logits[4]);

    tile.semanticLogits.unknownLogits =
        makeConstantFloatGrid(width, height, logits[5]);

    tile.semanticLogits.classCount = 6;
    tile.semanticLogits.layout = TensorLayout::CHW;

    return tile;
}

void expectFloatGridNear(
    const RasterGrid<float>& actual,
    const int expectedWidth,
    const int expectedHeight,
    const std::vector<float>& expected,
    const float tolerance = 1.0e-5F)
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

TEST(MetricOutputStitcherTest, SingleMock4x4TilePreservesExactValues)
{
    PerTestLogger log;

    const std::vector<float> ndsm{
        0.0F, 1.0F, 2.0F, 3.0F,
        4.0F, 5.0F, 6.0F, 7.0F,
        8.0F, 9.0F, 10.0F, 11.0F,
        12.0F, 13.0F, 14.0F, 15.0F
    };

    const std::vector<float> confidence{
        0.10F, 0.20F, 0.30F, 0.40F,
        0.50F, 0.60F, 0.70F, 0.80F,
        0.90F, 1.00F, 0.95F, 0.85F,
        0.75F, 0.65F, 0.55F, 0.45F
    };

    TiledInferencePayload payload;
    payload.globalWidth = 4;
    payload.globalHeight = 4;

    payload.allTiles.push_back(
        makeTile(
            1,
            0,
            0,
            4,
            4,
            ndsm,
            confidence,
            std::vector<uint8_t>(16, 1),
            {1.0F, 2.0F, 3.0F, 4.0F, 5.0F, 6.0F}));

    const InferenceBundle result = timedCall(
        log,
        "MetricOutputStitcher::stitch single 4x4 tile",
        [&]
        {
            return MetricOutputStitcher::stitch(payload);
        });

    expectFloatGridNear(result.globalNdsm, 4, 4, ndsm);
    expectFloatGridNear(
        result.globalNdsmConfidence,
        4,
        4,
        confidence);

    expectFloatGridNear(
        result.globalSemanticLogits.groundLogits,
        4,
        4,
        std::vector<float>(16, 1.0F));

    expectFloatGridNear(
        result.globalSemanticLogits.buildingLogits,
        4,
        4,
        std::vector<float>(16, 2.0F));

    EXPECT_EQ(
        result.globalValidMask.data,
        std::vector<uint8_t>(16, 1));

    EXPECT_EQ(result.globalSemanticLogits.classCount, 6);
    EXPECT_EQ(result.globalSemanticLogits.layout, TensorLayout::CHW);
}

TEST(MetricOutputStitcherTest, TwoOverlapping4x4TilesUseExactConfidenceWeights)
{
    PerTestLogger log;

    TiledInferencePayload payload;
    payload.globalWidth = 4;
    payload.globalHeight = 4;

    payload.allTiles.push_back(
        makeTile(
            1,
            0,
            0,
            4,
            4,
            std::vector<float>(16, 10.0F),
            std::vector<float>(16, 1.0F),
            std::vector<uint8_t>(16, 1),
            {1.0F, 2.0F, 3.0F, 4.0F, 5.0F, 6.0F}));

    payload.allTiles.push_back(
        makeTile(
            2,
            0,
            0,
            4,
            4,
            std::vector<float>(16, 20.0F),
            std::vector<float>(16, 0.5F),
            std::vector<uint8_t>(16, 1),
            {7.0F, 8.0F, 9.0F, 10.0F, 11.0F, 12.0F}));

    const InferenceBundle result = timedCall(
        log,
        "MetricOutputStitcher::stitch overlapping 4x4 tiles",
        [&]
        {
            return MetricOutputStitcher::stitch(payload);
        });

    // (10*1 + 20*0.5) / (1 + 0.5) = 13.333333...
    expectFloatGridNear(
        result.globalNdsm,
        4,
        4,
        std::vector<float>(16, 13.333333F),
        1.0e-4F);

    // Confidence output is the Hann-weighted mean confidence.
    expectFloatGridNear(
        result.globalNdsmConfidence,
        4,
        4,
        std::vector<float>(16, 0.75F));

    // (1*1 + 7*0.5) / 1.5 = 3
    expectFloatGridNear(
        result.globalSemanticLogits.groundLogits,
        4,
        4,
        std::vector<float>(16, 3.0F));

    // (2*1 + 8*0.5) / 1.5 = 4
    expectFloatGridNear(
        result.globalSemanticLogits.buildingLogits,
        4,
        4,
        std::vector<float>(16, 4.0F));
}

TEST(MetricOutputStitcherTest, AllZeroValidMaskContributesNothing)
{
    PerTestLogger log;

    TiledInferencePayload payload;
    payload.globalWidth = 4;
    payload.globalHeight = 4;

    payload.allTiles.push_back(
        makeTile(
            1,
            0,
            0,
            4,
            4,
            std::vector<float>(16, 500.0F),
            std::vector<float>(16, 1.0F),
            std::vector<uint8_t>(16, 0),
            {10.0F, 20.0F, 30.0F, 40.0F, 50.0F, 60.0F}));

    const InferenceBundle result = timedCall(
        log,
        "MetricOutputStitcher::stitch all-zero mask",
        [&]
        {
            return MetricOutputStitcher::stitch(payload);
        });

    expectFloatGridNear(
        result.globalNdsm,
        4,
        4,
        std::vector<float>(16, 0.0F));

    expectFloatGridNear(
        result.globalNdsmConfidence,
        4,
        4,
        std::vector<float>(16, 0.0F));

    expectFloatGridNear(
        result.globalSemanticLogits.groundLogits,
        4,
        4,
        std::vector<float>(16, 0.0F));

    EXPECT_EQ(
        result.globalValidMask.data,
        std::vector<uint8_t>(16, 0));
}

TEST(MetricOutputStitcherTest, HandlesNegativeAndExtremeFiniteHeights)
{
    PerTestLogger log;

    const std::vector<float> extremeHeights{
        -100000.0F, 100000.0F, -50000.0F, 50000.0F,
        -1000.0F, 1000.0F, -100.0F, 100.0F,
        -1.0F, 1.0F, -0.001F, 0.001F,
        3.4e20F, -3.4e20F, 42.0F, -42.0F
    };

    TiledInferencePayload payload;
    payload.globalWidth = 4;
    payload.globalHeight = 4;

    payload.allTiles.push_back(
        makeTile(
            1,
            0,
            0,
            4,
            4,
            extremeHeights,
            std::vector<float>(16, 1.0F),
            std::vector<uint8_t>(16, 1),
            {0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F}));

    const InferenceBundle result = timedCall(
        log,
        "MetricOutputStitcher::stitch extreme heights",
        [&]
        {
            return MetricOutputStitcher::stitch(payload);
        });

    expectFloatGridNear(
        result.globalNdsm,
        4,
        4,
        extremeHeights,
        1.0e-3F);

    for (const float value : result.globalNdsm.data)
    {
        EXPECT_TRUE(std::isfinite(value));
    }
}

TEST(MetricOutputStitcherTest, EmptyPayloadThrowsWithoutDereferencingTiles)
{
    PerTestLogger log;

    TiledInferencePayload payload;
    payload.globalWidth = 4;
    payload.globalHeight = 4;

    EXPECT_THROW(
        {
            static_cast<void>(
                timedCall(
                    log,
                    "MetricOutputStitcher::stitch empty payload",
                    [&]
                    {
                        return MetricOutputStitcher::stitch(payload);
                    }));
        },
        std::runtime_error);
}

TEST(MetricOutputStitcherTest, RejectsMismatchedTileGridDimensions)
{
    PerTestLogger log;

    TiledInferencePayload payload;
    payload.globalWidth = 4;
    payload.globalHeight = 4;

    TileInferenceResult tile =
        makeTile(
            1,
            0,
            0,
            4,
            4,
            std::vector<float>(16, 10.0F),
            std::vector<float>(16, 1.0F),
            std::vector<uint8_t>(16, 1),
            {1.0F, 2.0F, 3.0F, 4.0F, 5.0F, 6.0F});

    // Keep the buffer allocated to prevent the test itself from invoking UB.
    // The declared shape is intentionally inconsistent with placement.
    tile.metricNdsm.width = 3;
    tile.metricNdsm.height = 4;

    payload.allTiles.push_back(std::move(tile));

    EXPECT_THROW(
        {
            static_cast<void>(
                timedCall(
                    log,
                    "MetricOutputStitcher::stitch malformed tile",
                    [&]
                    {
                        return MetricOutputStitcher::stitch(payload);
                    }));
        },
        std::invalid_argument);
}

TEST(MetricOutputStitcherTest, OneByOneTileAvoidsHannDivisionByZero)
{
    PerTestLogger log;

    TiledInferencePayload payload;
    payload.globalWidth = 1;
    payload.globalHeight = 1;

    payload.allTiles.push_back(
        makeTile(
            1,
            0,
            0,
            1,
            1,
            {7.5F},
            {0.8F},
            {1},
            {1.0F, 2.0F, 3.0F, 4.0F, 5.0F, 6.0F}));

    const InferenceBundle result = timedCall(
        log,
        "MetricOutputStitcher::stitch one-by-one tile",
        [&]
        {
            return MetricOutputStitcher::stitch(payload);
        });

    ASSERT_EQ(result.globalNdsm.data.size(), 1U);
    EXPECT_NEAR(result.globalNdsm.data[0], 7.5F, 1.0e-6F);
    EXPECT_NEAR(result.globalNdsmConfidence.data[0], 0.8F, 1.0e-6F);
    EXPECT_EQ(result.globalValidMask.data[0], 1);
    EXPECT_NEAR(
        result.globalSemanticLogits.groundLogits.data[0],
        1.0F,
        1.0e-6F);
}

TEST(MetricOutputStitcherTest, RejectsInconsistentSemanticClassCount)
{
    PerTestLogger log;

    TiledInferencePayload payload;
    payload.globalWidth = 4;
    payload.globalHeight = 4;

    TileInferenceResult tile =
        makeTile(
            1,
            0,
            0,
            4,
            4,
            std::vector<float>(16, 10.0F),
            std::vector<float>(16, 1.0F),
            std::vector<uint8_t>(16, 1),
            {1.0F, 2.0F, 3.0F, 4.0F, 5.0F, 6.0F});

    tile.semanticLogits.classCount = 5;
    payload.allTiles.push_back(std::move(tile));

    EXPECT_THROW(
        {
            static_cast<void>(
                timedCall(
                    log,
                    "MetricOutputStitcher::stitch class mismatch",
                    [&]
                    {
                        return MetricOutputStitcher::stitch(payload);
                    }));
        },
        std::invalid_argument);
}

} // namespace