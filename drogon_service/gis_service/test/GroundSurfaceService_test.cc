#include <gtest/gtest.h>

#include "SemanticContext/GroundSurfaceService.h"
#include "TestGridSupport.h"

#include <cstdint>
#include <stdexcept>
#include <vector>

namespace
{
using namespace depthwizard::test;

SemanticScene makeScene()
{
    SemanticScene scene;
    scene.groundProbability = makeConstantGrid(4, 4, 0.0F);
    scene.roadProbability = makeConstantGrid(4, 4, 0.0F);
    scene.buildingProbability = makeConstantGrid(4, 4, 0.0F);
    scene.vegetationProbability = makeConstantGrid(4, 4, 0.0F);
    scene.waterProbability = makeConstantGrid(4, 4, 0.0F);
    scene.unknownProbability = makeConstantGrid(4, 4, 1.0F);
    scene.semanticConfidence = makeConstantGrid(4, 4, 0.0F);
    scene.finalClassMap =
        makeConstantGrid<SemanticClass>(4, 4, SemanticClass::UNKNOWN);
    return scene;
}

ImageQualityResult makeQuality()
{
    ImageQualityResult quality;
    quality.validPixelMask = makeConstantGrid<uint8_t>(4, 4, uint8_t{1});
    quality.cloudMask = makeConstantGrid<uint8_t>(4, 4, uint8_t{0});
    quality.shadowMask = makeConstantGrid<uint8_t>(4, 4, uint8_t{0});
    quality.saturationMask = makeConstantGrid<uint8_t>(4, 4, uint8_t{0});
    return quality;
}

ReferenceTerrainBundle makeReference()
{
    ReferenceTerrainBundle reference;
    reference.validMask = makeConstantGrid<uint8_t>(4, 4, uint8_t{1});
    return reference;
}

TEST(GroundSurfaceServiceTest, AppliesExactMultiCriteriaRulesToMock4x4Scene)
{
    SemanticScene scene = makeScene();
    ImageQualityResult quality = makeQuality();
    ReferenceTerrainBundle reference = makeReference();

    scene.groundProbability.data[0] = 0.60F;
    scene.semanticConfidence.data[0] = 0.90F;

    scene.roadProbability.data[1] = 0.70F;
    scene.semanticConfidence.data[1] = 0.80F;

    scene.groundProbability.data[2] = 0.50F; // strict > 0.5: reject
    scene.groundProbability.data[3] = 0.60F;
    scene.buildingProbability.data[3] = 0.10F; // strict < 0.1: reject
    scene.groundProbability.data[4] = 0.60F;
    scene.vegetationProbability.data[4] = 0.15F; // strict < 0.15: reject

    scene.groundProbability.data[5] = 0.80F;
    quality.validPixelMask.data[5] = 0;
    scene.groundProbability.data[6] = 0.80F;
    reference.validMask.data[6] = 0;

    scene.groundProbability.data[7] = 0.80F;
    scene.semanticConfidence.data[7] = 0.40F;
    quality.shadowMask.data[7] = 1;

    const GroundMask result = timedCall(
        "GroundSurfaceService::buildGroundMask 4x4",
        [&] { return GroundSurfaceService::buildGroundMask(scene, quality, reference); });

    expectGridEqual<uint8_t>(
        result.isValidGround,
        4,
        4,
        {1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0});
    expectGridNear(
        result.weights,
        4,
        4,
        {0.9F, 0.8F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
         0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F});
    EXPECT_EQ(result.validGroundCount, 2U);
}

TEST(GroundSurfaceServiceTest, RejectsMismatchedInputGridShapes)
{
    SemanticScene scene = makeScene();
    ImageQualityResult quality = makeQuality();
    ReferenceTerrainBundle reference = makeReference();
    scene.roadProbability.width = 3;

    EXPECT_THROW(
        static_cast<void>(timedCall(
            "GroundSurfaceService::buildGroundMask malformed-input",
            [&] { return GroundSurfaceService::buildGroundMask(scene, quality, reference); })),
        std::invalid_argument);
}

} // namespace
