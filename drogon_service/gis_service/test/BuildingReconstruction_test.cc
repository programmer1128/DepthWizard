#include <gtest/gtest.h>
#include "../BuildingReconstruction/BuildingMaskProcessor.h"
#include "../BuildingReconstruction/BuildingInstanceExtractor.h"
#include <cmath>
#include <vector>

class BuildingReconstructionTest : public ::testing::Test
{
protected:
    // Helper to generate mocked Spatial Metadata
    SpatialMetadata createMockMetadata(int w, int h, double gsd, bool isGeo = false)
    {
        SpatialMetadata m;
        m.width = w;
        m.height = h;
        m.gsd = gsd;
        // In projected CRS (e.g., UTM), GSD matches the GeoTransform array directly
        m.geoTransform = {0.0, gsd, 0.0, 0.0, 0.0, -gsd};
        m.isGeoreferenced = true;
        // Use PROJCS for metric, GEOGCS for geographic (degrees)
        m.projectionRef = isGeo ? "GEOGCS[\"WGS 84\",...]" : "PROJCS[\"WGS 84 / UTM zone 33N\",...]";
        return m;
    }

    // Helper to generate mocked AI Semantics
    SemanticScene createMockSemantics(int w, int h, float defaultProb)
    {
        SemanticScene s;
        s.buildingProbability.width = w;
        s.buildingProbability.height = h;
        s.buildingProbability.data.assign(w * h, defaultProb);

        s.semanticConfidence.width = w;
        s.semanticConfidence.height = h;
        s.semanticConfidence.data.assign(w * h, 1.0f);
        return s;
    }

    // Helper to generate a mocked Valid Mask
    RasterGrid<uint8_t> createMockValidMask(int w, int h)
    {
        RasterGrid<uint8_t> m;
        m.width = w;
        m.height = h;
        m.data.assign(w * h, 1);
        return m;
    }
};

// -------------------------------------------------------------------------
// BUILDING MASK PROCESSOR TESTS
// -------------------------------------------------------------------------

TEST_F(BuildingReconstructionTest, RejectsOutOfBoundsProbabilities)
{
    int w = 10, h = 10;
    auto meta = createMockMetadata(w, h, 1.0);
    auto mask = createMockValidMask(w, h);
    auto semantics = createMockSemantics(w, h, 0.8f);

    // Poison the matrix with a negative probability (e.g., from neural network underflow)
    semantics.buildingProbability.data[5] = -0.1f;

    BuildingReconstructionConfig config;
    BuildingMaskResult result = BuildingMaskProcessor::createCleanMask(semantics, mask, meta, config);

    EXPECT_FALSE(result.success);
    EXPECT_NE(result.errorMessage.find("non-finite"), std::string::npos);
}

TEST_F(BuildingReconstructionTest, FiltersByValidMaskAndThreshold)
{
    int w = 5, h = 5;
    auto meta = createMockMetadata(w, h, 1.0);
    auto mask = createMockValidMask(w, h);
    // AI predicts entire map is a building at 80%
    auto semantics = createMockSemantics(w, h, 0.8f);

    // Mask out the center pixel (e.g., cloud cover)
    mask.data[2 * w + 2] = 0;

    // Make the bottom-right pixel weak (40% probability)
    semantics.buildingProbability.data[4 * w + 4] = 0.4f;

    BuildingReconstructionConfig config;
    config.buildingProbabilityThreshold = 0.5f;
    config.openingRadiusMetres = 0.0f; // Disable morphology to test pure masking
    config.closingRadiusMetres = 0.0f;
    config.minBuildingAreaSquareMetres = 0.0f;

    BuildingMaskResult result = BuildingMaskProcessor::createCleanMask(semantics, mask, meta, config);

    EXPECT_TRUE(result.success);
    EXPECT_EQ(result.cleanMask.data[0], 1);         // Passed threshold & valid
    EXPECT_EQ(result.cleanMask.data[2 * w + 2], 0); // Failed valid mask
    EXPECT_EQ(result.cleanMask.data[4 * w + 4], 0); // Failed threshold
}

// -------------------------------------------------------------------------
// BUILDING INSTANCE EXTRACTOR TESTS
// -------------------------------------------------------------------------

TEST_F(BuildingReconstructionTest, ExtractorRejectsGeographicCrsToPreventMicroMeshes)
{
    int w = 10, h = 10;
    // Simulate a Geographic CRS (degrees) where the GSD is microscopic
    auto meta = createMockMetadata(w, h, 0.00027, true);
    auto semantics = createMockSemantics(w, h, 0.8f);
    auto mask = createMockValidMask(w, h);

    BuildingReconstructionConfig config;
    BuildingMaskResult maskResult = BuildingMaskProcessor::createCleanMask(semantics, mask, meta, config);

    // The mask processor will fail first due to the zero-area check
    EXPECT_FALSE(maskResult.success);
    EXPECT_NE(maskResult.errorMessage.find("zero spatial resolution"), std::string::npos);
}

TEST_F(BuildingReconstructionTest, RejectsSmallComponentsBasedOnPhysicalMetricScaling)
{
    int w = 20, h = 20;
    // Set GSD to 0.5m. Therefore, 1 pixel = 0.25 sq meters.
    auto meta = createMockMetadata(w, h, 0.5);
    auto mask = createMockValidMask(w, h);
    auto semantics = createMockSemantics(w, h, 0.0f); // Blank slate

    // Draw a 5x5 building (25 pixels * 0.25 = 6.25 sq meters)
    for (int r = 2; r < 7; ++r)
    {
        for (int c = 2; c < 7; ++c)
        {
            semantics.buildingProbability.data[r * w + c] = 0.9f;
        }
    }

    BuildingReconstructionConfig config;
    config.openingRadiusMetres = 0.0f;
    config.closingRadiusMetres = 0.0f;
    // Set absolute minimum to 10 sq meters
    config.minBuildingAreaSquareMetres = 10.0f;

    BuildingMaskResult maskResult = BuildingMaskProcessor::createCleanMask(semantics, mask, meta, config);
    EXPECT_TRUE(maskResult.success);

    // The Mask Processor natively culls the small area first.
    EXPECT_EQ(maskResult.smallComponentRejectedPixelCount, 25);

    ComponentExtractionResult extResult = BuildingInstanceExtractor::extract(maskResult, semantics, meta, config);

    EXPECT_TRUE(extResult.success);
    EXPECT_EQ(extResult.acceptedComponentCount, 0);
    EXPECT_EQ(extResult.rejectedComponentCount, 0); // Changed from 1 to 0 because the map is already blank
}

TEST_F(BuildingReconstructionTest, WatershedSuccessfullySplitsJoinedBuildings)
{
    int w = 20, h = 15;
    auto meta = createMockMetadata(w, h, 1.0); // 1 pixel = 1m
    auto mask = createMockValidMask(w, h);
    auto semantics = createMockSemantics(w, h, 0.0f); // Blank slate

    // Draw Building 1: 7x7 square (x: 2..8, y: 2..8)
    for (int r = 2; r <= 8; ++r)
    {
        for (int c = 2; c <= 8; ++c)
            semantics.buildingProbability.data[r * w + c] = 0.9f;
    }
    // Draw Building 2: 7x7 square (x: 11..17, y: 2..8)
    for (int r = 2; r <= 8; ++r)
    {
        for (int c = 11; c <= 17; ++c)
            semantics.buildingProbability.data[r * w + c] = 0.9f;
    }
    // Draw thin bridge connecting them: 2x2 block (x: 9..10, y: 4..5)
    for (int r = 4; r <= 5; ++r)
    {
        for (int c = 9; c <= 10; ++c)
            semantics.buildingProbability.data[r * w + c] = 0.9f;
    }

    BuildingReconstructionConfig config;
    config.openingRadiusMetres = 0.0f;
    config.closingRadiusMetres = 0.0f;
    config.minBuildingAreaSquareMetres = 10.0f;

    BuildingMaskResult maskResult = BuildingMaskProcessor::createCleanMask(semantics, mask, meta, config);
    EXPECT_TRUE(maskResult.success);

    // The Extractor's Watershed logic should detect the bridge as a pinch-point
    // and sever it, returning exactly 2 separate building components.
    ComponentExtractionResult extResult = BuildingInstanceExtractor::extract(maskResult, semantics, meta, config);

    EXPECT_TRUE(extResult.success);
    EXPECT_EQ(extResult.acceptedComponentCount, 2);

    // Verify deterministic spatial sorting (Left building should be ID 1, Right is ID 2)
    EXPECT_LT(extResult.components[0].pixelBoundingBox.x, extResult.components[1].pixelBoundingBox.x);

    // FIX: OpenCV's watershed boundary is 1-pixel thick. Since our bridge is 2 pixels wide (x=9 and x=10),
    // it will assign one column to a building and turn the other column into the '0' boundary.
    bool bridgeSevered = (extResult.labelRaster.data[4 * w + 9] == 0) || (extResult.labelRaster.data[4 * w + 10] == 0);
    EXPECT_TRUE(bridgeSevered);
}

// -------------------------------------------------------------------------
// CRITICAL STRESS TESTS & TOPOLOGICAL EDGE CASES
// -------------------------------------------------------------------------

TEST_F(BuildingReconstructionTest, MorphologyObliteratesThinArtifacts)
{
    int w = 20, h = 20;
    auto meta = createMockMetadata(w, h, 1.0);
    auto mask = createMockValidMask(w, h);
    auto semantics = createMockSemantics(w, h, 0.0f);

    // Draw a 1-pixel thin "wall" that is 15 pixels long (Area = 15 sq meters)
    // Even if config.minBuildingAreaSquareMetres is 10, morphology should destroy it.
    for (int c = 2; c < 17; ++c)
    {
        semantics.buildingProbability.data[10 * w + c] = 0.9f;
    }

    BuildingReconstructionConfig config;
    config.openingRadiusMetres = 2.0f; // A 2m radius kernel will completely erode a 1m thick line
    config.closingRadiusMetres = 0.0f;
    config.minBuildingAreaSquareMetres = 10.0f;

    BuildingMaskResult maskResult = BuildingMaskProcessor::createCleanMask(semantics, mask, meta, config);
    EXPECT_TRUE(maskResult.success);

    // The line should be completely erased by the morphological opening
    bool isCompletelyBlank = true;
    for (uint8_t pixel : maskResult.cleanMask.data)
    {
        if (pixel > 0)
            isCompletelyBlank = false;
    }
    EXPECT_TRUE(isCompletelyBlank);
}

TEST_F(BuildingReconstructionTest, HandlesComplexDonutTopology)
{
    int w = 20, h = 20;
    auto meta = createMockMetadata(w, h, 1.0);
    auto mask = createMockValidMask(w, h);
    auto semantics = createMockSemantics(w, h, 0.0f);

    // Draw a 10x10 building
    for (int r = 5; r < 15; ++r)
    {
        for (int c = 5; c < 15; ++c)
            semantics.buildingProbability.data[r * w + c] = 0.9f;
    }
    // Punch a 4x4 courtyard hole in the middle
    for (int r = 8; r < 12; ++r)
    {
        for (int c = 8; c < 12; ++c)
            semantics.buildingProbability.data[r * w + c] = 0.1f;
    }

    BuildingReconstructionConfig config;
    config.openingRadiusMetres = 0.0f;
    config.closingRadiusMetres = 0.0f;
    config.minBuildingAreaSquareMetres = 10.0f;

    BuildingMaskResult maskResult = BuildingMaskProcessor::createCleanMask(semantics, mask, meta, config);
    ComponentExtractionResult extResult = BuildingInstanceExtractor::extract(maskResult, semantics, meta, config);

    EXPECT_TRUE(extResult.success);
    // FIX: Use ASSERT to gracefully stop the test if 0 components are found, preventing Segfaults
    ASSERT_EQ(extResult.acceptedComponentCount, 1);
    EXPECT_EQ(extResult.components[0].pixelCount, 100 - 16); // 84 pixels
}

TEST_F(BuildingReconstructionTest, CheckerboardNoiseIsEfficientlyCulled)
{
    int w = 50, h = 50;
    auto meta = createMockMetadata(w, h, 1.0);
    auto mask = createMockValidMask(w, h);
    auto semantics = createMockSemantics(w, h, 0.0f);

    // Generate a high-frequency checkerboard pattern
    for (int r = 0; r < h; ++r)
    {
        for (int c = 0; c < w; ++c)
        {
            if ((r + c) % 2 == 0)
                semantics.buildingProbability.data[r * w + c] = 0.9f;
        }
    }

    BuildingReconstructionConfig config;
    config.openingRadiusMetres = 0.0f;
    config.closingRadiusMetres = 0.0f;
    config.minBuildingAreaSquareMetres = 5.0f; // Each block is 1 sq meter, so all should fail

    BuildingMaskResult maskResult = BuildingMaskProcessor::createCleanMask(semantics, mask, meta, config);

    // The mask processor should have rejected every single one of the 1,250 blocks
    EXPECT_EQ(maskResult.smallComponentRejectedPixelCount, 1250);

    ComponentExtractionResult extResult = BuildingInstanceExtractor::extract(maskResult, semantics, meta, config);
    EXPECT_EQ(extResult.acceptedComponentCount, 0);
}

TEST_F(BuildingReconstructionTest, WatershedSurvivesTotalScreenFill)
{
    int w = 20, h = 20;
    auto meta = createMockMetadata(w, h, 1.0);
    auto mask = createMockValidMask(w, h);

    // The AI predicts the ENTIRE tile is a single massive building
    auto semantics = createMockSemantics(w, h, 0.9f);

    BuildingReconstructionConfig config;
    config.openingRadiusMetres = 0.0f;
    config.closingRadiusMetres = 0.0f;
    config.minBuildingAreaSquareMetres = 10.0f;

    BuildingMaskResult maskResult = BuildingMaskProcessor::createCleanMask(semantics, mask, meta, config);
    ComponentExtractionResult extResult = BuildingInstanceExtractor::extract(maskResult, semantics, meta, config);

    // Watershed relies on finding "Sure Background" (pixels guaranteed NOT to be buildings).
    // If the building touches all 4 edges, there IS no background.
    EXPECT_TRUE(extResult.success);
    // FIX: Use ASSERT to safely guard the array access
    ASSERT_EQ(extResult.acceptedComponentCount, 1);
    EXPECT_EQ(extResult.components[0].pixelCount, 400);
}

// -------------------------------------------------------------------------
// EXTREME PHYSICAL & MATHEMATICAL STRESS TESTS
// -------------------------------------------------------------------------

TEST_F(BuildingReconstructionTest, SurvivesExtremeAsymmetricSensorWarping)
{
    int w = 50, h = 50;

    // Simulate a heavily warped satellite pass where the X-axis is ultra-high res (0.1m)
    // but the Y-axis is heavily stretched/compressed (5.0m).
    SpatialMetadata meta;
    meta.width = w;
    meta.height = h;
    meta.geoTransform = {0.0, 0.1, 0.0, 0.0, 0.0, -5.0}; // Asymmetric resolution
    meta.isGeoreferenced = true;
    meta.projectionRef = "PROJCS[\"WGS 84 / UTM zone 33N\",...]";

    auto mask = createMockValidMask(w, h);
    auto semantics = createMockSemantics(w, h, 0.9f);

    BuildingReconstructionConfig config;
    config.openingRadiusMetres = 2.0f;
    config.closingRadiusMetres = 2.0f;

    // This attacks the calcKernelDim lambda.
    // X-kernel should be: ceil(2.0 / 0.1) * 2 + 1 = 41 pixels wide.
    // Y-kernel should be: ceil(2.0 / 5.0) * 2 + 1 = 3 pixels high.
    // If the safety cap fails, this will throw an OpenCV kernel assertion exception.
    BuildingMaskResult maskResult = BuildingMaskProcessor::createCleanMask(semantics, mask, meta, config);

    EXPECT_TRUE(maskResult.success);
    EXPECT_EQ(maskResult.openingKernelWidth, 41);
    EXPECT_EQ(maskResult.openingKernelHeight, 3);
}

TEST_F(BuildingReconstructionTest, LongThinWallSurvivesDistanceTransformUnderflow)
{
    int w = 100, h = 20;
    auto meta = createMockMetadata(w, h, 1.0);
    auto mask = createMockValidMask(w, h);
    auto semantics = createMockSemantics(w, h, 0.0f);

    // Draw a wall 1 pixel thick, 80 pixels long. Area = 80 sq meters.
    for (int c = 10; c < 90; ++c)
    {
        semantics.buildingProbability.data[10 * w + c] = 0.9f;
    }

    BuildingReconstructionConfig config;
    config.openingRadiusMetres = 0.0f; // Disable morphology to test purely the Watershed math
    config.closingRadiusMetres = 0.0f;
    config.minBuildingAreaSquareMetres = 50.0f;

    BuildingMaskResult maskResult = BuildingMaskProcessor::createCleanMask(semantics, mask, meta, config);
    ComponentExtractionResult extResult = BuildingInstanceExtractor::extract(maskResult, semantics, meta, config);

    // CRITICAL: A 1-pixel thick line has a maximum distance transform of exactly 1.0.
    // Because our distThreshPixels = 1.2, OpenCV's sureFg will be completely empty.
    // If our "fgComponents <= 2" bypass wasn't there, OpenCV would annihilate this building
    // into 0 components. This test verifies the bypass successfully rescues thin architecture.
    EXPECT_TRUE(extResult.success);
    ASSERT_EQ(extResult.acceptedComponentCount, 1);
    EXPECT_EQ(extResult.components[0].pixelCount, 80);
}

TEST_F(BuildingReconstructionTest, EnforcesConnectivityRulesOnDiagonals)
{
    int w = 20, h = 20;
    auto meta = createMockMetadata(w, h, 1.0);
    auto mask = createMockValidMask(w, h);
    auto semantics = createMockSemantics(w, h, 0.0f);

    // Draw a perfectly diagonal line of 10 pixels (Area = 10 sq meters)
    for (int i = 5; i < 15; ++i)
    {
        semantics.buildingProbability.data[i * w + i] = 0.9f;
    }

    BuildingReconstructionConfig config;
    config.openingRadiusMetres = 0.0f;
    config.closingRadiusMetres = 0.0f;
    config.minBuildingAreaSquareMetres = 5.0f;

    // TEST A: 4-Connectivity
    // Under 4-connectivity, diagonals do not connect. This should be viewed as
    // 10 separate buildings of 1 pixel each. All 10 will fail the 5 sq meter minimum.
    config.connectivity = 4;
    BuildingMaskResult maskResult4 = BuildingMaskProcessor::createCleanMask(semantics, mask, meta, config);
    EXPECT_TRUE(maskResult4.success);
    EXPECT_EQ(maskResult4.smallComponentRejectedPixelCount, 10);

    // TEST B: 8-Connectivity
    // Under 8-connectivity, diagonals DO connect. This should be viewed as
    // 1 single building of 10 pixels. It passes the 5 sq meter minimum.
    config.connectivity = 8;
    BuildingMaskResult maskResult8 = BuildingMaskProcessor::createCleanMask(semantics, mask, meta, config);
    EXPECT_TRUE(maskResult8.success);
    EXPECT_EQ(maskResult8.smallComponentRejectedPixelCount, 0);

    ComponentExtractionResult extResult8 = BuildingInstanceExtractor::extract(maskResult8, semantics, meta, config);
    EXPECT_TRUE(extResult8.success);
    EXPECT_EQ(extResult8.acceptedComponentCount, 1);
}

TEST_F(BuildingReconstructionTest, CatchesMemoryCorruptionAndNaNPoisoning)
{
    int w = 10, h = 10;
    auto meta = createMockMetadata(w, h, 1.0);
    auto mask = createMockValidMask(w, h);
    auto semantics = createMockSemantics(w, h, 0.8f);

    // Simulate an AI Tensor memory leak / divide-by-zero that generates NaNs and Infs
    semantics.buildingProbability.data[2] = std::numeric_limits<float>::quiet_NaN();
    semantics.semanticConfidence.data[3] = std::numeric_limits<float>::infinity();

    BuildingReconstructionConfig config;

    // The Processor should immediately catch the NaN and abort
    BuildingMaskResult maskResult = BuildingMaskProcessor::createCleanMask(semantics, mask, meta, config);
    EXPECT_FALSE(maskResult.success);
    EXPECT_NE(maskResult.errorMessage.find("non-finite"), std::string::npos);

    // Simulate a scenario where the processor passes, but the extractor receives corrupted data later
    semantics.buildingProbability.data[2] = 0.5f; // Fix probability
    maskResult.success = true;                    // Force pass
    maskResult.cleanMask = createMockValidMask(w, h);

    // Extractor should catch the Infinity in the confidence tensor and abort before OpenCV segfaults
    ComponentExtractionResult extResult = BuildingInstanceExtractor::extract(maskResult, semantics, meta, config);
    EXPECT_FALSE(extResult.success);
    EXPECT_NE(extResult.errorMessage.find("invalid values"), std::string::npos);
}

// -------------------------------------------------------------------------
// DEEP ARCHITECTURE & DATA INTEGRITY TESTS
// -------------------------------------------------------------------------

TEST_F(BuildingReconstructionTest, MorphologyStrictlyRespectsValidMask)
{
    int w = 20, h = 20;
    auto meta = createMockMetadata(w, h, 1.0);
    auto mask = createMockValidMask(w, h);
    auto semantics = createMockSemantics(w, h, 0.0f);

    // Draw a U-shaped building
    for (int r = 5; r < 15; ++r)
    {
        semantics.buildingProbability.data[r * w + 5] = 0.9f;  // Left leg
        semantics.buildingProbability.data[r * w + 15] = 0.9f; // Right leg
    }
    for (int c = 5; c <= 15; ++c)
    {
        semantics.buildingProbability.data[14 * w + c] = 0.9f; // Bottom connection
    }

    // Poison the center courtyard with a cloud (validMask = 0)
    for (int r = 6; r < 13; ++r)
    {
        for (int c = 6; c < 15; ++c)
        {
            mask.data[r * w + c] = 0;
        }
    }

    BuildingReconstructionConfig config;
    config.openingRadiusMetres = 0.0f;
    config.closingRadiusMetres = 5.0f; // Massive closing kernel, normally bridges a U into a solid square
    config.minBuildingAreaSquareMetres = 5.0f;

    BuildingMaskResult maskResult = BuildingMaskProcessor::createCleanMask(semantics, mask, meta, config);

    EXPECT_TRUE(maskResult.success);
    // CRITICAL: The dilation step of morphology blindly expands the 255 pixels.
    // If the cv::bitwise_and intersection fails, the AI will hallucinate building
    // mass over top of the cloud. This asserts the validMask firmly blocks it.
    EXPECT_EQ(maskResult.cleanMask.data[10 * w + 10], 0);
}

TEST_F(BuildingReconstructionTest, BypassRescuesHighResSmallBuildings)
{
    int w = 50, h = 50;
    auto meta = createMockMetadata(w, h, 0.05); // 5cm High-Res Drone Imagery
    auto mask = createMockValidMask(w, h);
    auto semantics = createMockSemantics(w, h, 0.0f);

    // Draw a 30x30 pixel shed (1.5m x 1.5m = 2.25 sq meters physical area)
    for (int r = 10; r < 40; ++r)
    {
        for (int c = 10; c < 40; ++c)
        {
            semantics.buildingProbability.data[r * w + c] = 0.9f;
        }
    }

    BuildingReconstructionConfig config;
    config.openingRadiusMetres = 0.0f; // FIX: Prevent the default 2m erosion from destroying the 1.5m drone shed
    config.closingRadiusMetres = 0.0f;
    config.minBuildingAreaSquareMetres = 2.0f;

    BuildingMaskResult maskResult = BuildingMaskProcessor::createCleanMask(semantics, mask, meta, config);
    ComponentExtractionResult extResult = BuildingInstanceExtractor::extract(maskResult, semantics, meta, config);

    // CRITICAL: At 5cm GSD, the Extractor's dynamic threshold is 1.2 / 0.05 = 24 pixels.
    // The shed's maximum distance from its center to its edge is only 15 pixels.
    // OpenCV's distanceTransform finds ZERO peaks.
    // If our "if (fgComponents > 2)" Bypass isn't working, OpenCV Watershed will
    // immediately delete the building. This test guarantees the Bypass catches the
    // high-res failure and rescues the shed.
    EXPECT_TRUE(extResult.success);
    ASSERT_EQ(extResult.acceptedComponentCount, 1);
    EXPECT_EQ(extResult.components[0].pixelCount, 900);
}

TEST_F(BuildingReconstructionTest, ComputesAccurateStatsForIrregularShapes)
{
    int w = 20, h = 20;
    auto meta = createMockMetadata(w, h, 1.0);
    auto mask = createMockValidMask(w, h);
    auto semantics = createMockSemantics(w, h, 0.0f);

    // Draw an irregular L-Shape
    for (int r = 2; r < 12; ++r)
    {
        semantics.buildingProbability.data[r * w + 2] = 0.8f;
        semantics.buildingProbability.data[r * w + 3] = 0.8f;
        semantics.semanticConfidence.data[r * w + 2] = 0.5f;
        semantics.semanticConfidence.data[r * w + 3] = 1.0f;
    }
    for (int c = 2; c < 12; ++c)
    {
        semantics.buildingProbability.data[10 * w + c] = 0.8f;
        semantics.buildingProbability.data[11 * w + c] = 0.8f;
        semantics.semanticConfidence.data[10 * w + c] = 0.5f;
        semantics.semanticConfidence.data[11 * w + c] = 1.0f;
    }

    BuildingReconstructionConfig config;
    config.openingRadiusMetres = 0.0f; // FIX: Prevent the default 2.0m erosion from vaporizing the drone shed
    config.closingRadiusMetres = 0.0f;
    config.minBuildingAreaSquareMetres = 2.0f;

    BuildingMaskResult maskResult = BuildingMaskProcessor::createCleanMask(semantics, mask, meta, config);
    ComponentExtractionResult extResult = BuildingInstanceExtractor::extract(maskResult, semantics, meta, config);

    ASSERT_EQ(extResult.acceptedComponentCount, 1);
    auto &comp = extResult.components[0];

    // CRITICAL: Validates the Pointer Offset Math and OpenCV CCA Stats
    // The overlap is 2x2 (4 pixels). Total area should be 20 + 20 - 4 = 36.
    EXPECT_EQ(comp.pixelCount, 36);
    EXPECT_EQ(comp.pixelBoundingBox.x, 2);
    EXPECT_EQ(comp.pixelBoundingBox.y, 2);
    EXPECT_EQ(comp.pixelBoundingBox.width, 10);
    EXPECT_EQ(comp.pixelBoundingBox.height, 10);

    // Verify that the custom loop correctly scanned the irregular geometry
    // without reading background zeroes.
    EXPECT_FLOAT_EQ(comp.minSemanticConfidence, 0.5f);
    EXPECT_FLOAT_EQ(comp.meanBuildingProbability, 0.8f);
}

TEST_F(BuildingReconstructionTest, WatershedSafelyProcessesMultipleDisjointBuildings)
{
    int w = 40, h = 40;
    auto meta = createMockMetadata(w, h, 1.0);
    auto mask = createMockValidMask(w, h);
    auto semantics = createMockSemantics(w, h, 0.0f);

    // Draw 3 distinctly separated 5x5 buildings
    auto drawBldg = [&](int startX, int startY)
    {
        for (int r = startY; r < startY + 5; ++r)
        {
            for (int c = startX; c < startX + 5; ++c)
            {
                semantics.buildingProbability.data[r * w + c] = 0.9f;
            }
        }
    };
    drawBldg(2, 2);
    drawBldg(20, 2);
    drawBldg(10, 20);

    BuildingReconstructionConfig config;
    config.openingRadiusMetres = 0.0f; // FIX: Disable erosion so the 5x5 squares aren't rounded into circles
    config.closingRadiusMetres = 0.0f;
    config.minBuildingAreaSquareMetres = 10.0f;

    BuildingMaskResult maskResult = BuildingMaskProcessor::createCleanMask(semantics, mask, meta, config);
    ComponentExtractionResult extResult = BuildingInstanceExtractor::extract(maskResult, semantics, meta, config);

    // CRITICAL: Because there are 3 disjoint buildings, fgComponents = 4.
    // This forces the Watershed block to trigger. We must ensure the bitwise_and
    // logic cleanly maps the markers without destroying isolated valid buildings.
    ASSERT_EQ(extResult.acceptedComponentCount, 3);
    EXPECT_EQ(extResult.components[0].pixelCount, 25);
    EXPECT_EQ(extResult.components[1].pixelCount, 25);
    EXPECT_EQ(extResult.components[2].pixelCount, 25);
}

// -------------------------------------------------------------------------
// HARDWARE LIMITS & FLOATING-POINT PRECISION TESTS
// -------------------------------------------------------------------------

TEST_F(BuildingReconstructionTest, HardwareCapPreventsRamExhaustionOnMillimeterGsd)
{
    int w = 50, h = 50;

    // Simulate 1mm resolution (0.001m). This is a hostile input.
    auto meta = createMockMetadata(w, h, 0.001);
    auto mask = createMockValidMask(w, h);
    auto semantics = createMockSemantics(w, h, 0.9f);

    BuildingReconstructionConfig config;
    config.openingRadiusMetres = 2.0f;
    config.closingRadiusMetres = 0.0f;
    config.minBuildingAreaSquareMetres = 0.0f;

    // A 2m radius at 1mm GSD mathematically requires a 4,000 x 4,000 pixel kernel.
    // That single operation would allocate gigabytes of RAM and crash the Drogon worker.
    // The hardware cap `min(pixels, 50)` must violently restrict this to 101x101.
    BuildingMaskResult maskResult = BuildingMaskProcessor::createCleanMask(semantics, mask, meta, config);

    EXPECT_TRUE(maskResult.success);
    EXPECT_EQ(maskResult.openingKernelWidth, 101); // (50 * 2) + 1
    EXPECT_EQ(maskResult.openingKernelHeight, 101);
}

TEST_F(BuildingReconstructionTest, MassiveHBlockBridgeIsCleanlySevered)
{
    int w = 30, h = 30;
    auto meta = createMockMetadata(w, h, 1.0);
    auto mask = createMockValidMask(w, h);
    auto semantics = createMockSemantics(w, h, 0.0f);

    // Left Tower
    for (int r = 5; r < 25; ++r)
    {
        for (int c = 2; c < 7; ++c)
            semantics.buildingProbability.data[r * w + c] = 0.9f;
    }
    // Right Tower
    for (int r = 5; r < 25; ++r)
    {
        for (int c = 17; c < 22; ++c)
            semantics.buildingProbability.data[r * w + c] = 0.9f;
    }
    // FIX: The Bridge. A bridge 4m wide generates its own peak!
    // We thin it to 2m (x=14 to 15). Max center distance is 1.0 < 1.2 threshold.
    // This forces OpenCV to treat it as a connecting bridge and slice it.
    for (int r = 14; r < 16; ++r)
    {
        for (int c = 7; c < 17; ++c)
            semantics.buildingProbability.data[r * w + c] = 0.9f;
    }

    BuildingReconstructionConfig config;
    config.openingRadiusMetres = 0.0f;
    config.closingRadiusMetres = 0.0f;
    config.minBuildingAreaSquareMetres = 10.0f;

    BuildingMaskResult maskResult = BuildingMaskProcessor::createCleanMask(semantics, mask, meta, config);
    ComponentExtractionResult extResult = BuildingInstanceExtractor::extract(maskResult, semantics, meta, config);

    EXPECT_TRUE(extResult.success);
    ASSERT_EQ(extResult.acceptedComponentCount, 2);
}

TEST_F(BuildingReconstructionTest, NullSemanticPoisoningFailsGracefully)
{
    int w = 10, h = 10;
    auto meta = createMockMetadata(w, h, 1.0);
    auto mask = createMockValidMask(w, h);

    // The AI predicts absolutely nothing. Every pixel is 0.0f.
    auto semantics = createMockSemantics(w, h, 0.0f);

    BuildingReconstructionConfig config;
    config.openingRadiusMetres = 0.0f;
    config.closingRadiusMetres = 0.0f;
    config.minBuildingAreaSquareMetres = 5.0f;

    BuildingMaskResult maskResult = BuildingMaskProcessor::createCleanMask(semantics, mask, meta, config);
    ComponentExtractionResult extResult = BuildingInstanceExtractor::extract(maskResult, semantics, meta, config);

    // It should not crash, it should not divide by zero on stats, it should just return 0 accepted.
    EXPECT_TRUE(extResult.success);
    EXPECT_EQ(extResult.acceptedComponentCount, 0);
    EXPECT_EQ(extResult.rejectedComponentCount, 0);
}

TEST_F(BuildingReconstructionTest, StrictFloatingPointAreaBoundary)
{
    int w = 20, h = 20;

    // Set GSD so exactly 1 pixel = 1.0 sq meters
    auto meta = createMockMetadata(w, h, 1.0);
    auto mask = createMockValidMask(w, h);
    auto semantics = createMockSemantics(w, h, 0.0f);

    // Draw exactly 19 pixels
    for (int i = 0; i < 19; ++i)
        semantics.buildingProbability.data[i] = 0.9f;

    BuildingReconstructionConfig config;
    config.openingRadiusMetres = 0.0f;
    config.closingRadiusMetres = 0.0f;
    config.minBuildingAreaSquareMetres = 20.0f;

    BuildingMaskResult maskResult = BuildingMaskProcessor::createCleanMask(semantics, mask, meta, config);

    // FIX: The Mask Processor natively culls the area first!
    EXPECT_TRUE(maskResult.success);
    EXPECT_EQ(maskResult.smallComponentRejectedPixelCount, 19);

    ComponentExtractionResult extResult = BuildingInstanceExtractor::extract(maskResult, semantics, meta, config);

    EXPECT_TRUE(extResult.success);
    EXPECT_EQ(extResult.acceptedComponentCount, 0);
    EXPECT_EQ(extResult.rejectedComponentCount, 0); // Already rejected by mask processor
}