#include <gtest/gtest.h>
#include "../ImagePreprocessing/ImagePreprocessingService.h"
#include <gdal_priv.h>
#include <cpl_vsi.h>

class ImagePreprocessingTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
        GDALAllRegister();
    }

    // Helper to generate an isolated 1x1 pixel GeoTIFF in RAM
    SceneInput createMockScene(const std::string &name, uint8_t r, uint8_t g, uint8_t b)
    {
        std::string path = "/vsimem/" + name + ".tif";
        GDALDriver *driver = GetGDALDriverManager()->GetDriverByName("GTiff");

        // Create 3-band RGB image
        GDALDataset *ds = driver->Create(path.c_str(), 1, 1, 3, GDT_Byte, nullptr);
        ds->GetRasterBand(1)->RasterIO(GF_Write, 0, 0, 1, 1, &r, 1, 1, GDT_Byte, 0, 0);
        ds->GetRasterBand(2)->RasterIO(GF_Write, 0, 0, 1, 1, &g, 1, 1, GDT_Byte, 0, 0);
        ds->GetRasterBand(3)->RasterIO(GF_Write, 0, 0, 1, 1, &b, 1, 1, GDT_Byte, 0, 0);
        GDALClose(ds);

        SceneInput scene;
        scene.inputPath = path;
        scene.width = 1;
        scene.height = 1;
        return scene;
    }
};

TEST_F(ImagePreprocessingTest, AccuratelyPassesValidTerrain)
{
    // Normal green terrain (R=100, G=150, B=100)
    SceneInput scene = createMockScene("valid", 100, 150, 100);
    ImageQualityResult result = ImagePreprocessingService::process(scene);

    EXPECT_EQ(result.validPixelMask.data[0], 1);
    EXPECT_EQ(result.cloudMask.data[0], 0);
    EXPECT_EQ(result.shadowMask.data[0], 0);
    EXPECT_EQ(result.saturationMask.data[0], 0);
    EXPECT_FLOAT_EQ(result.qualityScore, 1.0f);

    VSIUnlink(scene.inputPath.c_str());
}

TEST_F(ImagePreprocessingTest, IsolatesHighLuminanceClouds)
{
    // Cloud pixel: High brightness, low saturation (R=240, G=240, B=240)
    SceneInput scene = createMockScene("cloud", 240, 240, 240);
    ImageQualityResult result = ImagePreprocessingService::process(scene);

    EXPECT_EQ(result.cloudMask.data[0], 1);      // Cloud detected
    EXPECT_EQ(result.validPixelMask.data[0], 0); // Invalidated
    EXPECT_FLOAT_EQ(result.qualityScore, 0.0f);

    VSIUnlink(scene.inputPath.c_str());
}

TEST_F(ImagePreprocessingTest, DetectsDeepShadowsByBlueRatio)
{
    // Shadow pixel: Low overall luminance, dominated by blue ambient scatter (R=10, G=10, B=60)
    SceneInput scene = createMockScene("shadow", 10, 10, 60);
    ImageQualityResult result = ImagePreprocessingService::process(scene);

    EXPECT_EQ(result.shadowMask.data[0], 1);     // Shadow detected
    EXPECT_EQ(result.validPixelMask.data[0], 0); // Invalidated

    VSIUnlink(scene.inputPath.c_str());
}

TEST_F(ImagePreprocessingTest, FlagsSensorSaturation)
{
    // Overexposed sensor pixel (R=255, G=255, B=255)
    SceneInput scene = createMockScene("saturation", 255, 255, 255);
    ImageQualityResult result = ImagePreprocessingService::process(scene);

    EXPECT_EQ(result.saturationMask.data[0], 1); // Saturation detected
    EXPECT_EQ(result.validPixelMask.data[0], 0); // Invalidated

    VSIUnlink(scene.inputPath.c_str());
}

TEST_F(ImagePreprocessingTest, ImageNetZScoreNormalizationIsMathematicallyAccurate)
{
    // Test pure black pixel (0,0,0) against GAMUS AI means/stds
    SceneInput scene = createMockScene("black", 0, 0, 0);
    ImageQualityResult result = ImagePreprocessingService::process(scene);

    // AI Standard: mean=[0.485, 0.456, 0.406], std=[0.229, 0.224, 0.225]
    // Expected R for 0: (0.0 - 0.485) / 0.229 = -2.1179
    EXPECT_NEAR(result.normalizedRgbTensor.data[0], -2.1179f, 0.001f);

    VSIUnlink(scene.inputPath.c_str());
}

// -------------------------------------------------------------------------
// CRITICAL STRESS TESTS & EDGE CASES
// -------------------------------------------------------------------------

TEST_F(ImagePreprocessingTest, SafelyProcessesGrayscaleGeoTiffs)
{
    // Some older satellites only provide 1-band (Grayscale) imagery.
    // This tests if the `numBands >= X ? X : 1` logic successfully prevents a Segmentation Fault
    // and correctly clones the grayscale band across the RGB tensor.
    std::string path = "/vsimem/grayscale.tif";
    GDALDriver *driver = GetGDALDriverManager()->GetDriverByName("GTiff");

    // Create 1-band image
    GDALDataset *ds = driver->Create(path.c_str(), 1, 1, 1, GDT_Byte, nullptr);
    uint8_t grayVal = 100;
    ds->GetRasterBand(1)->RasterIO(GF_Write, 0, 0, 1, 1, &grayVal, 1, 1, GDT_Byte, 0, 0);
    GDALClose(ds);

    SceneInput scene;
    scene.inputPath = path;
    scene.width = 1;
    scene.height = 1;

    ImageQualityResult result = ImagePreprocessingService::process(scene);

    // The Z-Score math should treat this as R=100, G=100, B=100
    float expectedR = ((100.0f / 255.0f) - 0.485f) / 0.229f;
    float expectedG = ((100.0f / 255.0f) - 0.456f) / 0.224f;
    float expectedB = ((100.0f / 255.0f) - 0.406f) / 0.225f;

    EXPECT_NEAR(result.normalizedRgbTensor.data[0], expectedR, 0.001f); // R
    EXPECT_NEAR(result.normalizedRgbTensor.data[1], expectedG, 0.001f); // G
    EXPECT_NEAR(result.normalizedRgbTensor.data[2], expectedB, 0.001f); // B

    VSIUnlink(path.c_str());
}

TEST_F(ImagePreprocessingTest, BlackBorderPaddingIsInvalidated)
{
    // GeoTIFFs are often rotated, leaving large triangular artificial borders of pure black (0,0,0).
    // The processor calculates `isBorderPadding`, but it relies on the `pSat[i] == 1` saturation
    // gate (which flags anything <= 1.0f) to actually mask it. This verifies the padding is rejected.
    SceneInput scene = createMockScene("border", 0, 0, 0);
    ImageQualityResult result = ImagePreprocessingService::process(scene);

    EXPECT_EQ(result.saturationMask.data[0], 1); // Must trigger saturation
    EXPECT_EQ(result.validPixelMask.data[0], 0); // Must be explicitly invalidated
    EXPECT_FLOAT_EQ(result.qualityScore, 0.0f);

    VSIUnlink(scene.inputPath.c_str());
}

TEST_F(ImagePreprocessingTest, OpenMpSurvivesPrimeNumberGridDimensions)
{
    // Threaded `#pragma omp parallel for` loops divide totalPixels across CPU cores.
    // If the grid size is a prime number (e.g., 17x13 = 221 total pixels), it won't divide evenly.
    // If memory boundaries aren't strictly handled, threads will overshoot and Segfault.
    int w = 17, h = 13;
    std::string path = "/vsimem/prime.tif";
    GDALDriver *driver = GetGDALDriverManager()->GetDriverByName("GTiff");

    GDALDataset *ds = driver->Create(path.c_str(), w, h, 3, GDT_Byte, nullptr);
    std::vector<uint8_t> dummyData(w * h, 128); // Neutral grey
    ds->GetRasterBand(1)->RasterIO(GF_Write, 0, 0, w, h, dummyData.data(), w, h, GDT_Byte, 0, 0);
    ds->GetRasterBand(2)->RasterIO(GF_Write, 0, 0, w, h, dummyData.data(), w, h, GDT_Byte, 0, 0);
    ds->GetRasterBand(3)->RasterIO(GF_Write, 0, 0, w, h, dummyData.data(), w, h, GDT_Byte, 0, 0);
    GDALClose(ds);

    SceneInput scene;
    scene.inputPath = path;
    scene.width = w;
    scene.height = h;

    // If OpenMP boundary handling fails, the test suite will instantly crash here.
    ImageQualityResult result = ImagePreprocessingService::process(scene);

    EXPECT_EQ(result.normalizedRgbTensor.data.size(), 221 * 3);
    EXPECT_EQ(result.validPixelMask.data.size(), 221);

    VSIUnlink(path.c_str());
}

// -------------------------------------------------------------------------
// ARCHITECTURAL BOUNDARY & FORMAT FALLBACK TESTS
// -------------------------------------------------------------------------

TEST_F(ImagePreprocessingTest, GrayscaleShadowDetectionBypassesBlueRatio)
{
    // If a pixel is R=30, G=30, B=30, the luminance is 30 (< 40.0f).
    // However, the blue ratio is exactly 0.333 (30 / 90).
    // The standard RGB shadow check requires blueRatio > 0.38f.
    // If the `isGrayscale` immunity flag in your code failed, grayscale images
    // would physically never register shadows. This proves the override works.

    std::string path = "/vsimem/gray_shadow.tif";
    GDALDriver *driver = GetGDALDriverManager()->GetDriverByName("GTiff");

    // Create explicitly 1-band image
    GDALDataset *ds = driver->Create(path.c_str(), 1, 1, 1, GDT_Byte, nullptr);
    uint8_t shadowVal = 30;
    ds->GetRasterBand(1)->RasterIO(GF_Write, 0, 0, 1, 1, &shadowVal, 1, 1, GDT_Byte, 0, 0);
    GDALClose(ds);

    SceneInput scene;
    scene.inputPath = path;
    scene.width = 1;
    scene.height = 1;

    ImageQualityResult result = ImagePreprocessingService::process(scene);

    EXPECT_EQ(result.shadowMask.data[0], 1);     // Must be flagged as shadow
    EXPECT_EQ(result.validPixelMask.data[0], 0); // Must be invalidated

    VSIUnlink(path.c_str());
}

TEST_F(ImagePreprocessingTest, SafelyRoutesTwoBandImageryWithoutSegfaults)
{
    // Some formats (like old aerial RGB-IR converted to Grayscale+Alpha) have exactly 2 bands.
    // Your code reads: GetRasterBand(numBands >= 3 ? 3 : 1) for the Blue channel.
    // For 2 bands, it should mathematically map Band 1 to Red, Band 2 to Green, and Band 1 to Blue.
    // If it blindly tried to read Band 3, the GDAL C++ API would throw a hard segmentation fault.

    std::string path = "/vsimem/twoband.tif";
    GDALDriver *driver = GetGDALDriverManager()->GetDriverByName("GTiff");

    GDALDataset *ds = driver->Create(path.c_str(), 1, 1, 2, GDT_Byte, nullptr);
    uint8_t band1Val = 100; // Red and Blue
    uint8_t band2Val = 50;  // Green
    ds->GetRasterBand(1)->RasterIO(GF_Write, 0, 0, 1, 1, &band1Val, 1, 1, GDT_Byte, 0, 0);
    ds->GetRasterBand(2)->RasterIO(GF_Write, 0, 0, 1, 1, &band2Val, 1, 1, GDT_Byte, 0, 0);
    GDALClose(ds);

    SceneInput scene;
    scene.inputPath = path;
    scene.width = 1;
    scene.height = 1;

    // A segfault here means the `numBands >= 3 ? 3 : 1` ternary operator failed
    ImageQualityResult result = ImagePreprocessingService::process(scene);

    // Verify Red (Band 1)
    float expectedR = ((100.0f / 255.0f) - 0.485f) / 0.229f;
    EXPECT_NEAR(result.normalizedRgbTensor.data[0], expectedR, 0.001f);

    // Verify Green (Band 2)
    float expectedG = ((50.0f / 255.0f) - 0.456f) / 0.224f;
    EXPECT_NEAR(result.normalizedRgbTensor.data[1], expectedG, 0.001f);

    // Verify Blue (Fallback to Band 1)
    float expectedB = ((100.0f / 255.0f) - 0.406f) / 0.225f;
    EXPECT_NEAR(result.normalizedRgbTensor.data[2], expectedB, 0.001f);

    VSIUnlink(path.c_str());
}

TEST_F(ImagePreprocessingTest, StrictBoundaryValuesForSaturationMask)
{
    // The saturation gate triggers if ANY channel is >= 254 or <= 1.
    // We test the exact boundary lines (2 and 253) to prove valid terrain isn't being accidentally destroyed.

    // Test exact inner boundary (2, 253, 128) - Should be perfectly valid
    SceneInput validScene = createMockScene("inner_bound", 2, 253, 128);
    ImageQualityResult validResult = ImagePreprocessingService::process(validScene);
    EXPECT_EQ(validResult.saturationMask.data[0], 0);
    EXPECT_EQ(validResult.validPixelMask.data[0], 1);
    VSIUnlink(validScene.inputPath.c_str());

    // Test exact outer boundary (1, 128, 128) - Should trigger dark saturation
    SceneInput underScene = createMockScene("under_bound", 1, 128, 128);
    ImageQualityResult underResult = ImagePreprocessingService::process(underScene);
    EXPECT_EQ(underResult.saturationMask.data[0], 1);
    EXPECT_EQ(underResult.validPixelMask.data[0], 0);
    VSIUnlink(underScene.inputPath.c_str());

    // Test exact outer boundary (128, 254, 128) - Should trigger light saturation
    SceneInput overScene = createMockScene("over_bound", 128, 254, 128);
    ImageQualityResult overResult = ImagePreprocessingService::process(overScene);
    EXPECT_EQ(overResult.saturationMask.data[0], 1);
    EXPECT_EQ(overResult.validPixelMask.data[0], 0);
    VSIUnlink(overScene.inputPath.c_str());
}

TEST_F(ImagePreprocessingTest, SurvivesTotalCloudCoverWithoutMathErrors)
{
    // If an image is 100% clouds, validCount stays at 0.
    // qualityScore = validCount / totalPixels.
    // This ensures no floating-point exceptions or NaNs are generated when returning a 0% score.

    SceneInput scene = createMockScene("total_cloud", 250, 250, 250);
    ImageQualityResult result = ImagePreprocessingService::process(scene);

    EXPECT_EQ(result.cloudMask.data[0], 1);
    EXPECT_EQ(result.validPixelMask.data[0], 0);

    // Must be exactly 0.0f, not NaN or undefined
    EXPECT_FLOAT_EQ(result.qualityScore, 0.0f);

    VSIUnlink(scene.inputPath.c_str());
}

// -------------------------------------------------------------------------
// EXTREME PHOTOMETRIC & MEMORY ISOLATION TESTS
// -------------------------------------------------------------------------

TEST_F(ImagePreprocessingTest, ThrowsExceptionOnMissingOrCorruptGeoTiff)
{
    // If the network drops during the MinIO download or the RAM disk unmounts unexpectedly,
    // the SceneInput might point to a phantom /vsimem/ file.
    // The service MUST gracefully throw a runtime_error rather than segfaulting on a null GDALDataset.
    SceneInput scene;
    scene.inputPath = "/vsimem/does_not_exist_phantom_file.tif";
    scene.width = 100;
    scene.height = 100;

    EXPECT_THROW({ ImagePreprocessingService::process(scene); }, std::runtime_error);
}

TEST_F(ImagePreprocessingTest, CloudLuminanceThresholdIsStrictlyBounded)
{
    // The cloud gate requires luminance STRICTLY > 200.0f.
    // Luminance = 0.299*R + 0.587*G + 0.114*B

    // TEST A: R=G=B=200 -> Luminance = 200.0f.
    // Because 200.0f is NOT > 200.0f, this must be recognized as bright valid terrain (like snow/sand).
    SceneInput scene200 = createMockScene("lum200", 200, 200, 200);
    ImageQualityResult result200 = ImagePreprocessingService::process(scene200);
    EXPECT_EQ(result200.cloudMask.data[0], 0);
    EXPECT_EQ(result200.validPixelMask.data[0], 1);
    VSIUnlink(scene200.inputPath.c_str());

    // TEST B: R=G=B=201 -> Luminance = 201.0f.
    // This crosses the > 200.0f threshold and must trigger the cloud mask.
    // Notice that 201 is well below the 254 saturation limit, proving the cloud math works independently.
    SceneInput scene201 = createMockScene("lum201", 201, 201, 201);
    ImageQualityResult result201 = ImagePreprocessingService::process(scene201);
    EXPECT_EQ(result201.cloudMask.data[0], 1);
    EXPECT_EQ(result201.validPixelMask.data[0], 0);
    VSIUnlink(scene201.inputPath.c_str());
}

TEST_F(ImagePreprocessingTest, RayleighScatteringBlueShadowsAreDetected)
{
    // In satellite imagery, deep shadows are rarely pure black. Because they are blocked
    // from the sun, they are illuminated purely by ambient sky scatter (Rayleigh scattering),
    // giving them a strong blue tint.
    // Let's test a pixel that is bright blue but dark overall: R=5, G=5, B=60.

    // Math Check:
    // Lum = 0.299(5) + 0.587(5) + 0.114(60) = 11.27 (Passes the < 40.0f check)
    // Blue Ratio = 60 / (5 + 5 + 60) = 0.857 (Passes the > 0.38f check)

    SceneInput scene = createMockScene("blue_shadow", 5, 5, 60);
    ImageQualityResult result = ImagePreprocessingService::process(scene);

    EXPECT_EQ(result.shadowMask.data[0], 1);
    EXPECT_EQ(result.validPixelMask.data[0], 0);

    // Asserts that it wasn't accidentally flagged by the floor saturation check (values <= 1)
    EXPECT_EQ(result.saturationMask.data[0], 0);

    VSIUnlink(scene.inputPath.c_str());
}

TEST_F(ImagePreprocessingTest, ExtremeAsymmetricSliverProcessing)
{
    // Test an extreme 1 x 10,000 pixel sliver.
    // If the 1D/2D pointer offsets in the Z-Score tensor mapping (`normG = normR + totalPixels;`)
    // have any row/col inversion bugs or layout assumptions, a 1x10000 array will violently segfault.
    int w = 1, h = 10000;
    std::string path = "/vsimem/sliver.tif";
    GDALDriver *driver = GetGDALDriverManager()->GetDriverByName("GTiff");

    GDALDataset *ds = driver->Create(path.c_str(), w, h, 3, GDT_Byte, nullptr);
    std::vector<uint8_t> dummyData(10000, 128); // Neutral grey

    // Explicit (void) casts to silence GCC warnings
    (void)ds->GetRasterBand(1)->RasterIO(GF_Write, 0, 0, w, h, dummyData.data(), w, h, GDT_Byte, 0, 0);
    (void)ds->GetRasterBand(2)->RasterIO(GF_Write, 0, 0, w, h, dummyData.data(), w, h, GDT_Byte, 0, 0);
    (void)ds->GetRasterBand(3)->RasterIO(GF_Write, 0, 0, w, h, dummyData.data(), w, h, GDT_Byte, 0, 0);
    GDALClose(ds);

    SceneInput scene;
    scene.inputPath = path;
    scene.width = w;
    scene.height = h;

    ImageQualityResult result = ImagePreprocessingService::process(scene);

    // The CHW Tensor must be exactly 30,000 floats long
    EXPECT_EQ(result.normalizedRgbTensor.data.size(), 30000);
    EXPECT_EQ(result.validPixelMask.data.size(), 10000);

    // Validate a pixel dead in the middle of the array
    EXPECT_EQ(result.validPixelMask.data[5000], 1);

    VSIUnlink(path.c_str());
}