#include <gtest/gtest.h>
#include "../ImageTilingService/OutputStitching/MetricOutputStitcher.h"
#include <vector>
#include <cmath>
#include <stdexcept>

class MetricOutputStitcherTest : public ::testing::Test
{
protected:
    // Helper to generate a baseline tile
    TileInferenceResult createMockTile(int width, int height, float baseVal)
    {
        TileInferenceResult tile;
        tile.placement.paddedWidth = width;
        tile.placement.paddedHeight = height;
        tile.placement.sourceX = 0;
        tile.placement.sourceY = 0;

        int size = width * height;
        tile.metricNdsm.data.assign(size, baseVal);
        tile.ndsmConfidence.data.assign(size, 1.0f);
        tile.validMask.data.assign(size, 1);

        tile.semanticLogits.classCount = 6;
        tile.semanticLogits.groundLogits.data.assign(size, baseVal);
        tile.semanticLogits.buildingLogits.data.assign(size, 0.0f);
        tile.semanticLogits.roadLogits.data.assign(size, 0.0f);
        tile.semanticLogits.vegetationLogits.data.assign(size, 0.0f);
        tile.semanticLogits.waterLogits.data.assign(size, 0.0f);
        tile.semanticLogits.unknownLogits.data.assign(size, 0.0f);
        return tile;
    }
};

TEST_F(MetricOutputStitcherTest, RejectsMismatchedTileGridDimensions)
{
    TiledInferencePayload payload;
    payload.globalWidth = 10;
    payload.globalHeight = 10;

    TileInferenceResult tile = createMockTile(4, 4, 1.0f);
    tile.metricNdsm.data.pop_back(); // Intentionally corrupt the size
    payload.allTiles.push_back(tile);

    EXPECT_THROW(MetricOutputStitcher::stitch(payload), std::invalid_argument);
}

TEST_F(MetricOutputStitcherTest, RejectsInconsistentSemanticClassCount)
{
    TiledInferencePayload payload;
    payload.globalWidth = 10;
    payload.globalHeight = 10;

    TileInferenceResult tile1 = createMockTile(4, 4, 1.0f);
    TileInferenceResult tile2 = createMockTile(4, 4, 1.0f);
    tile2.semanticLogits.classCount = 5; // Mismatch

    payload.allTiles.push_back(tile1);
    payload.allTiles.push_back(tile2);

    EXPECT_THROW(MetricOutputStitcher::stitch(payload), std::invalid_argument);
}

TEST_F(MetricOutputStitcherTest, OneByOneTileAvoidsHannDivisionByZero)
{
    TiledInferencePayload payload;
    payload.globalWidth = 1;
    payload.globalHeight = 1;

    TileInferenceResult tile = createMockTile(1, 1, 7.5f);
    tile.ndsmConfidence.data[0] = 0.8f;
    payload.allTiles.push_back(tile);

    InferenceBundle result = MetricOutputStitcher::stitch(payload);

    EXPECT_FALSE(std::isnan(result.globalNdsm.data[0]));
    EXPECT_FLOAT_EQ(result.globalNdsm.data[0], 7.5f);
    EXPECT_FLOAT_EQ(result.globalNdsmConfidence.data[0], 0.8f);
    EXPECT_FLOAT_EQ(result.globalSemanticLogits.groundLogits.data[0], 7.5f);
}

TEST_F(MetricOutputStitcherTest, AllZeroValidMaskContributesNothing)
{
    TiledInferencePayload payload;
    payload.globalWidth = 4;
    payload.globalHeight = 4;

    TileInferenceResult tile = createMockTile(4, 4, 500.0f);
    // Flag the entire tile as clouds/invalid
    std::fill(tile.validMask.data.begin(), tile.validMask.data.end(), 0);
    payload.allTiles.push_back(tile);

    InferenceBundle result = MetricOutputStitcher::stitch(payload);

    for (float val : result.globalNdsm.data)
    {
        EXPECT_FLOAT_EQ(val, 0.0f);
    }
    for (float conf : result.globalNdsmConfidence.data)
    {
        EXPECT_FLOAT_EQ(conf, 0.0f);
    }
}

TEST_F(MetricOutputStitcherTest, HandlesNegativeAndExtremeFiniteHeights)
{
    TiledInferencePayload payload;
    payload.globalWidth = 4;
    payload.globalHeight = 4;

    TileInferenceResult tile = createMockTile(4, 4, 0.0f);
    tile.metricNdsm.data[0] = -100000.0f; // Extreme valley
    tile.metricNdsm.data[1] = 100000.0f;  // Extreme peak
    payload.allTiles.push_back(tile);

    InferenceBundle result = MetricOutputStitcher::stitch(payload);

    EXPECT_FLOAT_EQ(result.globalNdsm.data[0], -100000.0f);
    EXPECT_FLOAT_EQ(result.globalNdsm.data[1], 100000.0f);
}

TEST_F(MetricOutputStitcherTest, SingleMock4x4TilePreservesExactValues)
{
    TiledInferencePayload payload;
    payload.globalWidth = 4;
    payload.globalHeight = 4;

    TileInferenceResult tile = createMockTile(4, 4, 0.0f);
    for (size_t i = 0; i < 16; ++i)
    {
        tile.metricNdsm.data[i] = static_cast<float>(i); // Ascending matrix
    }
    payload.allTiles.push_back(tile);

    InferenceBundle result = MetricOutputStitcher::stitch(payload);

    for (size_t i = 0; i < 16; ++i)
    {
        EXPECT_FLOAT_EQ(result.globalNdsm.data[i], static_cast<float>(i));
    }
}

TEST_F(MetricOutputStitcherTest, IgnoresOutOfBoundsPixelsWithoutCrashing)
{
    TiledInferencePayload payload;
    payload.globalWidth = 4;
    payload.globalHeight = 4;

    // 4x4 tile placed wildly out of bounds
    TileInferenceResult tile = createMockTile(4, 4, 42.0f);
    tile.placement.sourceX = -2; // Overhangs the left edge
    tile.placement.sourceY = 3;  // Overhangs the bottom edge
    payload.allTiles.push_back(tile);

    // If boundary clamping fails, this will throw a Segmentation Fault
    InferenceBundle result = MetricOutputStitcher::stitch(payload);

    // The local pixel at (r=0, c=2) maps to global (3, 0)
    EXPECT_FLOAT_EQ(result.globalNdsm.data[3 * 4 + 0], 42.0f);

    // Global pixel (0, 0) should be completely untouched
    EXPECT_FLOAT_EQ(result.globalNdsm.data[0], 0.0f);
}

TEST_F(MetricOutputStitcherTest, HighConfidenceTileDominatesLowConfidenceTile)
{
    TiledInferencePayload payload;
    payload.globalWidth = 4;
    payload.globalHeight = 4;

    // Tile A predicts a 100m skyscraper, 90% confident
    TileInferenceResult tileA = createMockTile(4, 4, 100.0f);
    std::fill(tileA.ndsmConfidence.data.begin(), tileA.ndsmConfidence.data.end(), 0.9f);

    // Tile B predicts a 10m house, 10% confident
    TileInferenceResult tileB = createMockTile(4, 4, 10.0f);
    std::fill(tileB.ndsmConfidence.data.begin(), tileB.ndsmConfidence.data.end(), 0.1f);

    payload.allTiles.push_back(tileA);
    payload.allTiles.push_back(tileB);

    InferenceBundle result = MetricOutputStitcher::stitch(payload);

    // Since Hann weights are perfectly equal for perfectly overlapping tiles, they cancel out.
    // The math should strictly be: (100 * 0.9 + 10 * 0.1) / (0.9 + 0.1) = 91.0f
    for (int i = 0; i < 16; ++i)
    {
        EXPECT_NEAR(result.globalNdsm.data[i], 91.0f, 1e-4f);
    }
}

TEST_F(MetricOutputStitcherTest, HandlesAsymmetricNonSquareTiles)
{
    TiledInferencePayload payload;
    payload.globalWidth = 10;
    payload.globalHeight = 3;

    TileInferenceResult tile = createMockTile(10, 3, 5.0f);
    payload.allTiles.push_back(tile);

    InferenceBundle result = MetricOutputStitcher::stitch(payload);

    // Check extremes to ensure both axes computed cleanly without NaN
    EXPECT_FLOAT_EQ(result.globalNdsm.data[0], 5.0f);          // Top-Left
    EXPECT_FLOAT_EQ(result.globalNdsm.data[2 * 10 + 9], 5.0f); // Bottom-Right
}

TEST_F(MetricOutputStitcherTest, CorrectlyBlendsNegativeSemanticLogits)
{
    TiledInferencePayload payload;
    payload.globalWidth = 4;
    payload.globalHeight = 4;

    TileInferenceResult tileA = createMockTile(4, 4, 1.0f);
    // Force highly negative logits for building class
    std::fill(tileA.semanticLogits.buildingLogits.data.begin(),
              tileA.semanticLogits.buildingLogits.data.end(), -35.5f);

    TileInferenceResult tileB = createMockTile(4, 4, 1.0f);
    // Force highly positive logits for building class
    std::fill(tileB.semanticLogits.buildingLogits.data.begin(),
              tileB.semanticLogits.buildingLogits.data.end(), 15.5f);

    payload.allTiles.push_back(tileA);
    payload.allTiles.push_back(tileB);

    InferenceBundle result = MetricOutputStitcher::stitch(payload);

    // Equal confidence (1.0) and equal Hann weight means standard average
    // Expected: (-35.5 + 15.5) / 2 = -10.0f
    for (int i = 0; i < 16; ++i)
    {
        EXPECT_NEAR(result.globalSemanticLogits.buildingLogits.data[i], -10.0f, 1e-4f);
    }
}

TEST_F(MetricOutputStitcherTest, SimdHandlesPrimeDimensionsWithoutSegfault)
{
    TiledInferencePayload payload;
    // 17x13 = 221 total pixels. 221 is not divisible by 2, 4, 8, or 16.
    payload.globalWidth = 17;
    payload.globalHeight = 13;

    TileInferenceResult tile = createMockTile(17, 13, 3.14f);
    payload.allTiles.push_back(tile);

    // If the SIMD tail is not handled correctly by the compiler,
    // this will crash the entire test binary with a segfault.
    InferenceBundle result = MetricOutputStitcher::stitch(payload);

    EXPECT_FLOAT_EQ(result.globalNdsm.data[0], 3.14f);
    EXPECT_FLOAT_EQ(result.globalNdsm.data[17 * 13 - 1], 3.14f);
}

TEST_F(MetricOutputStitcherTest, SparseDonutMaskSeamlesslyFillsHoles)
{
    TiledInferencePayload payload;
    payload.globalWidth = 4;
    payload.globalHeight = 4;

    TileInferenceResult tileA = createMockTile(4, 4, 10.0f);
    // Punch a 2x2 hole in the center of Tile A (Simulating a cloud)
    tileA.validMask.data[1 * 4 + 1] = 0;
    tileA.validMask.data[1 * 4 + 2] = 0;
    tileA.validMask.data[2 * 4 + 1] = 0;
    tileA.validMask.data[2 * 4 + 2] = 0;

    TileInferenceResult tileB = createMockTile(4, 4, 20.0f);
    // Tile B is entirely invalid EXCEPT for the center 2x2 hole
    std::fill(tileB.validMask.data.begin(), tileB.validMask.data.end(), 0);
    tileB.validMask.data[1 * 4 + 1] = 1;
    tileB.validMask.data[1 * 4 + 2] = 1;
    tileB.validMask.data[2 * 4 + 1] = 1;
    tileB.validMask.data[2 * 4 + 2] = 1;

    payload.allTiles.push_back(tileA);
    payload.allTiles.push_back(tileB);

    InferenceBundle result = MetricOutputStitcher::stitch(payload);

    // The edges should be exclusively 10.0f (From Tile A)
    EXPECT_FLOAT_EQ(result.globalNdsm.data[0], 10.0f);

    // The center should be exclusively 20.0f (From Tile B)
    // If the 0.0f values leaked, this would be averaged down to ~15.0f
    EXPECT_FLOAT_EQ(result.globalNdsm.data[1 * 4 + 1], 20.0f);
    EXPECT_FLOAT_EQ(result.globalNdsm.data[2 * 4 + 2], 20.0f);
}

TEST_F(MetricOutputStitcherTest, ExtremeOverlapConfidenceClampsToOne)
{
    TiledInferencePayload payload;
    payload.globalWidth = 4;
    payload.globalHeight = 4;

    // Stack 20 identical tiles perfectly on top of each other
    for (int i = 0; i < 20; ++i)
    {
        TileInferenceResult tile = createMockTile(4, 4, 5.0f);
        std::fill(tile.ndsmConfidence.data.begin(), tile.ndsmConfidence.data.end(), 1.0f);
        payload.allTiles.push_back(tile);
    }

    InferenceBundle result = MetricOutputStitcher::stitch(payload);

    for (float conf : result.globalNdsmConfidence.data)
    {
        EXPECT_LE(conf, 1.0f); // Must be strictly less than or equal to 1.0
        EXPECT_GT(conf, 0.0f); // Must not have collapsed to 0
    }

    // The elevation math should remain perfectly stable regardless of stacks
    EXPECT_FLOAT_EQ(result.globalNdsm.data[0], 5.0f);
}

TEST_F(MetricOutputStitcherTest, ZeroConfidencePixelIsMathematicallyErased)
{
    TiledInferencePayload payload;
    payload.globalWidth = 4;
    payload.globalHeight = 4;

    // Valid Tile A predicts 10.0m with 100% confidence
    TileInferenceResult tileA = createMockTile(4, 4, 10.0f);
    std::fill(tileA.ndsmConfidence.data.begin(), tileA.ndsmConfidence.data.end(), 1.0f);

    // Poison Tile B predicts 9999.0m but with 0% confidence
    TileInferenceResult tileB = createMockTile(4, 4, 9999.0f);
    std::fill(tileB.ndsmConfidence.data.begin(), tileB.ndsmConfidence.data.end(), 0.0f);
    // Ensure the mask is still 1 so it tries to process it
    std::fill(tileB.validMask.data.begin(), tileB.validMask.data.end(), 1);

    payload.allTiles.push_back(tileA);
    payload.allTiles.push_back(tileB);

    InferenceBundle result = MetricOutputStitcher::stitch(payload);

    // The final result should be exactly 10.0f.
    // If Tile B leaked, this value would be highly distorted.
    for (int i = 0; i < 16; ++i)
    {
        EXPECT_FLOAT_EQ(result.globalNdsm.data[i], 10.0f);
    }
}

TEST_F(MetricOutputStitcherTest, MicroscopicWeightsTriggerNoDataFailsafe)
{
    TiledInferencePayload payload;
    payload.globalWidth = 4;
    payload.globalHeight = 4;

    TileInferenceResult tile = createMockTile(4, 4, 100.0f);

    // Force a microscopic confidence that will cause active_weight to underflow
    // 1e-8f (confidence) * 1e-6f (Hann edge clamp) = 1e-14f weight.
    std::fill(tile.ndsmConfidence.data.begin(), tile.ndsmConfidence.data.end(), 1e-8f);

    payload.allTiles.push_back(tile);
    InferenceBundle result = MetricOutputStitcher::stitch(payload);

    // Because the total weight is < 1e-7f, it must skip division and trigger the failsafe.
    for (int i = 0; i < 16; ++i)
    {
        EXPECT_FLOAT_EQ(result.globalNdsm.data[i], 0.0f);

        // Final confidence should also mathematically clamp to 0.0f
        EXPECT_FLOAT_EQ(result.globalNdsmConfidence.data[i], 0.0f);
    }
}

TEST_F(MetricOutputStitcherTest, SemanticLogitsScaleSymmetricallyWithoutBleed)
{
    TiledInferencePayload payload;
    payload.globalWidth = 4;
    payload.globalHeight = 4;

    // Tile A: 80% confident it's Ground (+10), heavily against Building (-20)
    TileInferenceResult tileA = createMockTile(4, 4, 0.0f);
    std::fill(tileA.ndsmConfidence.data.begin(), tileA.ndsmConfidence.data.end(), 0.8f);
    std::fill(tileA.semanticLogits.groundLogits.data.begin(), tileA.semanticLogits.groundLogits.data.end(), 10.0f);
    std::fill(tileA.semanticLogits.buildingLogits.data.begin(), tileA.semanticLogits.buildingLogits.data.end(), -20.0f);

    // Tile B: 20% confident it's Building (+40), heavily against Ground (-10)
    TileInferenceResult tileB = createMockTile(4, 4, 0.0f);
    std::fill(tileB.ndsmConfidence.data.begin(), tileB.ndsmConfidence.data.end(), 0.2f);
    std::fill(tileB.semanticLogits.groundLogits.data.begin(), tileB.semanticLogits.groundLogits.data.end(), -10.0f);
    std::fill(tileB.semanticLogits.buildingLogits.data.begin(), tileB.semanticLogits.buildingLogits.data.end(), 40.0f);

    payload.allTiles.push_back(tileA);
    payload.allTiles.push_back(tileB);

    InferenceBundle result = MetricOutputStitcher::stitch(payload);

    // Mathematical Expectation (assuming center pixels where Hann weight cancels out):
    // Ground: (10.0 * 0.8) + (-10.0 * 0.2) / (0.8 + 0.2) = 8.0 - 2.0 = 6.0f
    // Bldg:   (-20.0 * 0.8) + (40.0 * 0.2) / (0.8 + 0.2) = -16.0 + 8.0 = -8.0f

    // We check the center pixels (indices 5, 6, 9, 10) to avoid edge Hann dropoff
    std::vector<int> centerIndices = {5, 6, 9, 10};
    for (int idx : centerIndices)
    {
        EXPECT_NEAR(result.globalSemanticLogits.groundLogits.data[idx], 6.0f, 1e-4f);
        EXPECT_NEAR(result.globalSemanticLogits.buildingLogits.data[idx], -8.0f, 1e-4f);

        // Unused channels must remain exactly 0.0f
        EXPECT_FLOAT_EQ(result.globalSemanticLogits.waterLogits.data[idx], 0.0f);
    }
}

TEST_F(MetricOutputStitcherTest, SimdCheckerboardMaskMaintainsLaneIntegrity)
{
    TiledInferencePayload payload;
    payload.globalWidth = 4;
    payload.globalHeight = 4;

    TileInferenceResult tile = createMockTile(4, 4, 10.0f);
    // Create an alternating 0/1 checkerboard mask
    for (size_t i = 0; i < 16; ++i)
    {
        tile.validMask.data[i] = (i % 2 == 0) ? 1 : 0;
    }
    payload.allTiles.push_back(tile);

    InferenceBundle result = MetricOutputStitcher::stitch(payload);

    for (size_t i = 0; i < 16; ++i)
    {
        if (i % 2 == 0)
        {
            EXPECT_FLOAT_EQ(result.globalNdsm.data[i], 10.0f);
            EXPECT_FLOAT_EQ(result.globalNdsmConfidence.data[i], 1.0f);
        }
        else
        {
            EXPECT_FLOAT_EQ(result.globalNdsm.data[i], 0.0f);
            EXPECT_FLOAT_EQ(result.globalNdsmConfidence.data[i], 0.0f);
        }
    }
}

TEST_F(MetricOutputStitcherTest, RejectsTilesCompletelyOutsideGlobalBounds)
{
    TiledInferencePayload payload;
    payload.globalWidth = 4;
    payload.globalHeight = 4;

    TileInferenceResult tile = createMockTile(4, 4, 99.0f);

    // Push the tile entirely off the map to the right
    tile.placement.sourceX = 10;
    tile.placement.sourceY = 0;
    payload.allTiles.push_back(tile);

    // Execute stitch
    InferenceBundle result = MetricOutputStitcher::stitch(payload);

    // The entire global map must remain exactly 0.0f (no memory leaks/overwrites)
    for (size_t i = 0; i < 16; ++i)
    {
        EXPECT_FLOAT_EQ(result.globalNdsm.data[i], 0.0f);
    }
}

TEST_F(MetricOutputStitcherTest, DisjointCornersPreventRowStrideWrapping)
{
    TiledInferencePayload payload;
    payload.globalWidth = 10;
    payload.globalHeight = 10;

    // Top-Left (0,0)
    TileInferenceResult tl = createMockTile(1, 1, 1.0f);
    tl.placement.sourceX = 0;
    tl.placement.sourceY = 0;

    // Top-Right (9,0)
    TileInferenceResult tr = createMockTile(1, 1, 2.0f);
    tr.placement.sourceX = 9;
    tr.placement.sourceY = 0;

    // Bottom-Left (0,9)
    TileInferenceResult bl = createMockTile(1, 1, 3.0f);
    bl.placement.sourceX = 0;
    bl.placement.sourceY = 9;

    // Bottom-Right (9,9)
    TileInferenceResult br = createMockTile(1, 1, 4.0f);
    br.placement.sourceX = 9;
    br.placement.sourceY = 9;

    payload.allTiles = {tl, tr, bl, br};
    InferenceBundle result = MetricOutputStitcher::stitch(payload);

    // Validate the 4 corners
    EXPECT_FLOAT_EQ(result.globalNdsm.data[0], 1.0f);          // TL
    EXPECT_FLOAT_EQ(result.globalNdsm.data[9], 2.0f);          // TR
    EXPECT_FLOAT_EQ(result.globalNdsm.data[9 * 10 + 0], 3.0f); // BL
    EXPECT_FLOAT_EQ(result.globalNdsm.data[9 * 10 + 9], 4.0f); // BR

    // Check pixels immediately adjacent to the Top-Right corner to ensure it
    // didn't wrap around to the left edge of the next row (Index 10)
    EXPECT_FLOAT_EQ(result.globalNdsm.data[10], 0.0f);
}

TEST_F(MetricOutputStitcherTest, Pure1DVectorSliversComputeIndependently)
{
    // Test 1: Horizontal Sliver (10x1)
    TiledInferencePayload payloadH;
    payloadH.globalWidth = 10;
    payloadH.globalHeight = 1;
    payloadH.allTiles.push_back(createMockTile(10, 1, 55.0f));

    InferenceBundle resultH = MetricOutputStitcher::stitch(payloadH);
    EXPECT_FLOAT_EQ(resultH.globalNdsm.data[0], 55.0f);
    EXPECT_FLOAT_EQ(resultH.globalNdsm.data[9], 55.0f);

    // Test 2: Vertical Sliver (1x10)
    TiledInferencePayload payloadV;
    payloadV.globalWidth = 1;
    payloadV.globalHeight = 10;
    payloadV.allTiles.push_back(createMockTile(1, 10, 77.0f));

    InferenceBundle resultV = MetricOutputStitcher::stitch(payloadV);
    EXPECT_FLOAT_EQ(resultV.globalNdsm.data[0], 77.0f);
    EXPECT_FLOAT_EQ(resultV.globalNdsm.data[9], 77.0f);
}