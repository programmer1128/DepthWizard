#include <gtest/gtest.h>

#include "SurfaceFusion/NdsmGroundBiasCorrector.h"
#include "TestGridSupport.h"

#include <cstdint>
#include <limits>
#include <stdexcept>
#include <vector>

namespace
{
using namespace depthwizard::test;

GroundMask makeGroundMask(int width, int height, uint8_t value)
{
    GroundMask mask;
    mask.isValidGround = makeConstantGrid<uint8_t>(width, height, value);
    mask.weights = makeConstantGrid(width, height, 1.0F);
    mask.validGroundCount = value == 0
        ? 0U
        : static_cast<std::size_t>(width) * static_cast<std::size_t>(height);
    return mask;
}

TEST(NdsmGroundBiasCorrectorTest, InsufficientSupportBypassesCorrectionExactly)
{
    const float nan = std::numeric_limits<float>::quiet_NaN();
    const RasterGrid<float> ndsm = makeGrid<float>(
        4, 4,
        {-2.0F, -1.0F, 0.0F, 1.0F,
          2.0F,  3.0F, nan,  4.0F,
          5.0F,  6.0F, 7.0F, 8.0F,
          9.0F, 10.0F, 11.0F, 12.0F});
    GroundMask groundMask = makeGroundMask(4, 4, uint8_t{0});
    groundMask.isValidGround.data[0] = 1;
    groundMask.isValidGround.data[1] = 1;
    groundMask.isValidGround.data[2] = 1;
    groundMask.validGroundCount = 3;
    const RasterGrid<float> confidence = makeConstantGrid(4, 4, 0.8F);

    const NdsmCorrectionResult result = timedCall(
        "NdsmGroundBiasCorrector::correct insufficient-support",
        [&] { return NdsmGroundBiasCorrector::correct(ndsm, groundMask, confidence); });

    EXPECT_FALSE(result.correctionApplied);
    EXPECT_EQ(result.supportCount, 3U);
    EXPECT_FLOAT_EQ(result.estimatedGroundBias, 0.0F);
    EXPECT_FALSE(result.warning.empty());
    expectGridNear(result.correctedMetricNdsm, 4, 4, ndsm.data);
    expectGridNear(result.confidence, 4, 4, confidence.data);
}

TEST(NdsmGroundBiasCorrectorTest, ExactlyFiveHundredSamplesApplyRobustMedian)
{
    constexpr int width = 25;
    constexpr int height = 20;
    RasterGrid<float> ndsm = makeConstantGrid(width, height, 0.5F);
    ndsm.data.back() = 10.5F;
    const GroundMask groundMask = makeGroundMask(width, height, uint8_t{1});
    const RasterGrid<float> confidence = makeConstantGrid(width, height, 0.9F);

    const NdsmCorrectionResult result = timedCall(
        "NdsmGroundBiasCorrector::correct 500-samples",
        [&] { return NdsmGroundBiasCorrector::correct(ndsm, groundMask, confidence); });

    EXPECT_TRUE(result.correctionApplied);
    EXPECT_EQ(result.supportCount, 500U);
    EXPECT_FLOAT_EQ(result.estimatedGroundBias, 0.5F);
    EXPECT_TRUE(result.warning.empty());
    EXPECT_FLOAT_EQ(result.correctedMetricNdsm.data.front(), 0.0F);
    EXPECT_FLOAT_EQ(result.correctedMetricNdsm.data.back(), 10.0F);
}

TEST(NdsmGroundBiasCorrectorTest, ClampsExcessivePositiveBiasToFiveMeters)
{
    constexpr int width = 25;
    constexpr int height = 20;
    const RasterGrid<float> ndsm = makeConstantGrid(width, height, 10.0F);
    const GroundMask groundMask = makeGroundMask(width, height, uint8_t{1});
    const RasterGrid<float> confidence = makeConstantGrid(width, height, 1.0F);

    const NdsmCorrectionResult result = timedCall(
        "NdsmGroundBiasCorrector::correct clamped-bias",
        [&] { return NdsmGroundBiasCorrector::correct(ndsm, groundMask, confidence); });

    EXPECT_TRUE(result.correctionApplied);
    EXPECT_FLOAT_EQ(result.estimatedGroundBias, 5.0F);
    expectGridNear(result.correctedMetricNdsm, width, height,
                   std::vector<float>(500, 5.0F));
}

TEST(NdsmGroundBiasCorrectorTest, RejectsMismatchedGroundMaskShape)
{
    const RasterGrid<float> ndsm = makeConstantGrid(4, 4, 1.0F);
    GroundMask groundMask = makeGroundMask(4, 4, uint8_t{1});
    groundMask.isValidGround.width = 3;
    const RasterGrid<float> confidence = makeConstantGrid(4, 4, 1.0F);

    EXPECT_THROW(
        static_cast<void>(timedCall(
            "NdsmGroundBiasCorrector::correct malformed-input",
            [&] { return NdsmGroundBiasCorrector::correct(ndsm, groundMask, confidence); })),
        std::invalid_argument);
}

} // namespace
