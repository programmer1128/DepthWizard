#include <gtest/gtest.h>

#include "ImageTilingService/OutputStitching/NdsmOutputStitcher.h"
#include "ImageTilingService/OutputStitching/SemanticOutputStitcher.h"
#include "ImageTilingService/Tiling/TileDispatcher.h"
#include "SemanticContext/SemanticPostProcessor.h"

#include <cmath>
#include <vector>

namespace
{
template <typename T>
RasterGrid<T> grid(int width, int height, std::vector<T> values)
{
    return RasterGrid<T>{width, height, std::move(values)};
}

TilePlacement placement(int width, int height)
{
    TilePlacement result;
    result.paddedWidth = width;
    result.paddedHeight = height;
    result.validWidth = width;
    result.validHeight = height;
    return result;
}

SemanticTileResult semanticTile(float buildingLogit)
{
    SemanticTileResult tile;
    tile.tileId = 0;
    tile.placement = placement(2, 2);
    tile.semanticLogits.classCount = 6;
    tile.semanticLogits.layout = TensorLayout::CHW;
    tile.semanticLogits.otherLogits = grid<float>(2, 2, {0, 0, 0, 0});
    tile.semanticLogits.groundLogits = grid<float>(2, 2, {1, 1, 1, 1});
    tile.semanticLogits.lowVegetationLogits = grid<float>(2, 2, {0, 0, 0, 0});
    tile.semanticLogits.buildingLogits =
        grid<float>(2, 2, {buildingLogit, buildingLogit, buildingLogit, buildingLogit});
    tile.semanticLogits.roadLogits = grid<float>(2, 2, {0, 0, 0, 0});
    tile.semanticLogits.waterLogits = grid<float>(2, 2, {0, 0, 0, 0});
    tile.validMask = grid<uint8_t>(2, 2, {1, 1, 1, 1});
    return tile;
}

NdsmStitchingConfig ndsmStitchingConfig()
{
    NdsmStitchingConfig config;
    config.minimumEffectiveWeight = 1e-6f;
    return config;
}

SemanticInferenceConfig semanticStitchingConfig()
{
    SemanticInferenceConfig config;
    config.minEffectiveWeight = 1e-6f;
    return config;
}
}

TEST(DualModelStitchersTest, NdsmSingleTilePreservesMetricValuesAndMask)
{
    NdsmTileResult tile;
    tile.tileId = 0;
    tile.placement = placement(2, 2);
    tile.metricNdsm = grid<float>(2, 2, {2.0f, 4.0f, 6.0f, 8.0f});
    tile.ndsmConfidence = grid<float>(2, 2, {0.8f, 0.8f, 0.8f, 0.8f});
    tile.validMask = grid<uint8_t>(2, 2, {1, 1, 1, 0});

    NdsmTiledPayload payload;
    payload.globalWidth = 2;
    payload.globalHeight = 2;
    payload.tiles.push_back(std::move(tile));

    const NdsmInferenceBundle result =
        NdsmOutputStitcher::stitch(payload, ndsmStitchingConfig());

    EXPECT_FLOAT_EQ(result.globalMetricNdsm.data[0], 2.0f);
    EXPECT_FLOAT_EQ(result.globalMetricNdsm.data[1], 4.0f);
    EXPECT_FLOAT_EQ(result.globalMetricNdsm.data[2], 6.0f);
    EXPECT_TRUE(std::isnan(result.globalMetricNdsm.data[3]));
    EXPECT_EQ(result.globalValidMask.data, (std::vector<uint8_t>{1, 1, 1, 0}));
    EXPECT_NEAR(result.globalNdsmConfidence.data[0], 0.8f, 1e-6f);
}

TEST(DualModelStitchersTest, NdsmZeroConfidenceCannotCreateAValidPixel)
{
    NdsmTileResult tile;
    tile.placement = placement(1, 1);
    tile.metricNdsm = grid<float>(1, 1, {10.0f});
    tile.ndsmConfidence = grid<float>(1, 1, {0.0f});
    tile.validMask = grid<uint8_t>(1, 1, {1});

    NdsmTiledPayload payload;
    payload.globalWidth = 1;
    payload.globalHeight = 1;
    payload.tiles.push_back(std::move(tile));

    const NdsmInferenceBundle result =
        NdsmOutputStitcher::stitch(payload, ndsmStitchingConfig());
    EXPECT_EQ(result.globalValidMask.data[0], 0);
    EXPECT_TRUE(std::isnan(result.globalMetricNdsm.data[0]));
    EXPECT_FLOAT_EQ(result.globalNdsmConfidence.data[0], 0.0f);
}

TEST(DualModelStitchersTest, SemanticLogitsRemainRawUntilGlobalPostprocessing)
{
    SemanticTileResult tile = semanticTile(5.0f);
    tile.confidence = grid<float>(2, 2, {0.9f, 0.9f, 0.9f, 0.9f});

    SemanticTiledPayload payload;
    payload.globalWidth = 2;
    payload.globalHeight = 2;
    payload.tiles.push_back(std::move(tile));

    const SemanticInferenceBundle stitched =
        SemanticOutputStitcher::stitch(payload, semanticStitchingConfig());
    EXPECT_FLOAT_EQ(stitched.globalSemanticLogits.buildingLogits.data[0], 5.0f);
    EXPECT_NEAR(stitched.globalConfidence.data[0], 0.9f, 1e-6f);

    const SemanticScene scene = SemanticPostProcessor::buildScene(
        stitched.globalSemanticLogits,
        stitched.globalConfidence,
        stitched.globalValidMask);
    EXPECT_EQ(scene.finalClassMap.data[0], SemanticClass::BUILDING);
    EXPECT_GT(scene.buildingProbability.data[0], 0.9f);
}

TEST(DualModelStitchersTest, MissingOptionalSemanticReliabilityDefaultsToOne)
{
    SemanticTiledPayload payload;
    payload.globalWidth = 2;
    payload.globalHeight = 2;
    payload.tiles.push_back(semanticTile(5.0f));

    const SemanticInferenceBundle result =
        SemanticOutputStitcher::stitch(payload, semanticStitchingConfig());
    EXPECT_FLOAT_EQ(result.globalConfidence.data[0], 1.0f);
    EXPECT_EQ(result.globalValidMask.data[0], 1);
}

TEST(DualModelStitchersTest, SemanticSchemaMismatchFailsClosed)
{
    SemanticTileResult tile = semanticTile(5.0f);
    tile.semanticSchemaId = DEPTHWIZARD_SEMANTIC_SCHEMA_ID + 1;

    SemanticTiledPayload payload;
    payload.globalWidth = 2;
    payload.globalHeight = 2;
    payload.tiles.push_back(std::move(tile));

    EXPECT_THROW(
        SemanticOutputStitcher::stitch(payload, semanticStitchingConfig()),
        std::invalid_argument);
}

TEST(DualModelStitchersTest, SharedTilePlannerProducesDeterministicAlignedRequests)
{
    SceneInput scene;
    scene.width = 4;
    scene.height = 4;

    ImageQualityResult quality;
    quality.normalizedRgbTensor.width = 4;
    quality.normalizedRgbTensor.height = 4;
    quality.normalizedRgbTensor.channels = 3;
    quality.normalizedRgbTensor.layout = TensorLayout::CHW;
    quality.normalizedRgbTensor.data.resize(4 * 4 * 3);
    for (size_t i = 0; i < quality.normalizedRgbTensor.data.size(); ++i)
        quality.normalizedRgbTensor.data[i] = static_cast<float>(i);

    quality.validPixelMask = grid<uint8_t>(
        4,
        4,
        {1, 1, 1, 1,
         1, 0, 1, 1,
         1, 1, 1, 1,
         1, 1, 1, 1});

    const auto requests = TileDispatcher::buildTileRequests(scene, quality, 3, 2);

    ASSERT_EQ(requests.size(), 4U);
    EXPECT_EQ(requests[0]->tileId, 0U);
    EXPECT_EQ(requests[0]->xOffset, 0);
    EXPECT_EQ(requests[0]->yOffset, 0);
    EXPECT_EQ(requests[1]->xOffset, 1);
    EXPECT_EQ(requests[1]->yOffset, 0);
    EXPECT_EQ(requests[2]->xOffset, 0);
    EXPECT_EQ(requests[2]->yOffset, 1);
    EXPECT_EQ(requests[3]->xOffset, 1);
    EXPECT_EQ(requests[3]->yOffset, 1);

    for (const auto& request : requests)
    {
        ASSERT_NE(request, nullptr);
        EXPECT_EQ(request->width, 3);
        EXPECT_EQ(request->height, 3);
        EXPECT_EQ(request->validWidth, 3);
        EXPECT_EQ(request->validHeight, 3);
        EXPECT_EQ(request->normalizedRgbBytes.size(), 27U);
        EXPECT_EQ(request->validMaskBytes.size(), 9U);
    }

    // The lower-right tile starts at source (1,1), so its first validity
    // sample must be the invalid source pixel at row 1, column 1.
    EXPECT_EQ(requests[3]->validMaskBytes[0], 0);
}
