#include <gtest/gtest.h>

#include "SemanticContext/SemanticPostProcessor.h"
#include "TestGridSupport.h"

#include <array>
#include <cmath>
#include <cstdint>
#include <stdexcept>
#include <vector>

namespace
{
using namespace depthwizard::test;

SemanticLogits makeLogits(
    int width,
    int height,
    const std::array<float, 6>& values)
{
    SemanticLogits logits;
    logits.unknownLogits = makeConstantGrid(width, height, values[0]);
    logits.groundLogits = makeConstantGrid(width, height, values[1]);
    logits.buildingLogits = makeConstantGrid(width, height, values[2]);
    logits.roadLogits = makeConstantGrid(width, height, values[3]);
    logits.vegetationLogits = makeConstantGrid(width, height, values[4]);
    logits.waterLogits = makeConstantGrid(width, height, values[5]);
    logits.classCount = 6;
    logits.layout = TensorLayout::CHW;
    return logits;
}

TEST(SemanticPostProcessorTest, DominantGroundLogitProducesExact4x4Probabilities)
{
    constexpr int width = 4;
    constexpr int height = 4;
    const SemanticLogits logits =
        makeLogits(width, height, {0.0F, 2.0F, 0.0F, 0.0F, 0.0F, 0.0F});
    const RasterGrid<float> modelConfidence =
        makeConstantGrid(width, height, 0.8F);
    const RasterGrid<uint8_t> validMask =
        makeConstantGrid<uint8_t>(width, height, uint8_t{1});

    const SemanticScene scene = timedCall(
        "SemanticPostProcessor::buildScene dominant-ground",
        [&] { return SemanticPostProcessor::buildScene(logits, modelConfidence, validMask); });

    const float denominator = std::exp(2.0F) + 5.0F;
    const float expectedGround = std::exp(2.0F) / denominator;
    const float expectedOther = 1.0F / denominator;

    expectGridNear(scene.groundProbability, width, height,
                   std::vector<float>(16, expectedGround));
    expectGridNear(scene.buildingProbability, width, height,
                   std::vector<float>(16, expectedOther));
    expectGridNear(scene.semanticConfidence, width, height,
                   std::vector<float>(16, expectedGround * 0.8F));
    expectGridEqual(scene.finalClassMap, width, height,
                    std::vector<SemanticClass>(16, SemanticClass::GROUND));

    for (std::size_t i = 0; i < 16; ++i)
    {
        const float sum =
            scene.unknownProbability.data[i] + scene.groundProbability.data[i] +
            scene.buildingProbability.data[i] + scene.roadProbability.data[i] +
            scene.vegetationProbability.data[i] + scene.waterProbability.data[i];
        EXPECT_NEAR(sum, 1.0F, 1.0e-6F);
    }
}

TEST(SemanticPostProcessorTest, EqualLogitsBecomeUnknownBecauseMarginIsInsufficient)
{
    const SemanticLogits logits =
        makeLogits(4, 4, {0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F});
    const RasterGrid<float> confidence = makeConstantGrid(4, 4, 1.0F);
    const RasterGrid<uint8_t> mask =
        makeConstantGrid<uint8_t>(4, 4, uint8_t{1});

    const SemanticScene scene = timedCall(
        "SemanticPostProcessor::buildScene equal-logits",
        [&] { return SemanticPostProcessor::buildScene(logits, confidence, mask); });

    expectGridEqual(scene.finalClassMap, 4, 4,
                    std::vector<SemanticClass>(16, SemanticClass::UNKNOWN));
    expectGridNear(scene.semanticConfidence, 4, 4,
                   std::vector<float>(16, 0.0F));
    expectGridNear(scene.unknownProbability, 4, 4,
                   std::vector<float>(16, 1.0F / 6.0F));
}

TEST(SemanticPostProcessorTest, InvalidPixelForcesUnknownAndZeroConfidence)
{
    const SemanticLogits logits =
        makeLogits(4, 4, {0.0F, 0.0F, 4.0F, 0.0F, 0.0F, 0.0F});
    const RasterGrid<float> confidence = makeConstantGrid(4, 4, 0.9F);
    RasterGrid<uint8_t> mask = makeConstantGrid<uint8_t>(4, 4, uint8_t{1});
    mask.data[5] = 0;

    const SemanticScene scene = timedCall(
        "SemanticPostProcessor::buildScene invalid-pixel",
        [&] { return SemanticPostProcessor::buildScene(logits, confidence, mask); });

    EXPECT_EQ(scene.finalClassMap.data[5], SemanticClass::UNKNOWN);
    EXPECT_FLOAT_EQ(scene.semanticConfidence.data[5], 0.0F);
    EXPECT_EQ(scene.finalClassMap.data[6], SemanticClass::BUILDING);
    EXPECT_GT(scene.semanticConfidence.data[6], 0.0F);
}

TEST(SemanticPostProcessorTest, RejectsMismatchedRasterShapeAndClassContract)
{
    SemanticLogits logits =
        makeLogits(4, 4, {0.0F, 2.0F, 0.0F, 0.0F, 0.0F, 0.0F});
    logits.buildingLogits.width = 3;
    logits.classCount = 5;

    const RasterGrid<float> confidence = makeConstantGrid(4, 4, 1.0F);
    const RasterGrid<uint8_t> mask =
        makeConstantGrid<uint8_t>(4, 4, uint8_t{1});

    EXPECT_THROW(
        static_cast<void>(timedCall(
            "SemanticPostProcessor::buildScene malformed-input",
            [&] { return SemanticPostProcessor::buildScene(logits, confidence, mask); })),
        std::invalid_argument);
}

} // namespace
