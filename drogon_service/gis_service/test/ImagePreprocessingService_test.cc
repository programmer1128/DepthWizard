#include <gtest/gtest.h>

#include "ImagePreprocessing/ImagePreprocessingService.h"
#include "GdalRasterTestSupport.h"
#include "TestGridSupport.h"

#include <array>
#include <cmath>
#include <cstdint>
#include <stdexcept>
#include <string>
#include <vector>

namespace
{
using namespace depthwizard::test;

SceneInput makeScene(const std::string& path, int width = 4, int height = 4)
{
    SceneInput scene;
    scene.jobId = "image-preprocessing-test";
    scene.inputPath = path;
    scene.inputMode = PipelineMode::GEOREFERENCED;
    scene.width = width;
    scene.height = height;
    scene.sourceFormat = "GTiff";
    return scene;
}

TEST(ImagePreprocessingServiceTest, ProducesExactNormalizationAndQualityMasksForMock4x4Rgb)
{
    const std::string path = uniqueVsiPath("preprocess_rgb");
    VsiPathGuard guard(path);

    std::vector<uint8_t> red(16, 100);
    std::vector<uint8_t> green(16, 120);
    std::vector<uint8_t> blue(16, 80);

    red[0] = green[0] = blue[0] = 220; // cloud
    red[1] = 10; green[1] = 10; blue[1] = 30; // blue-biased shadow
    red[2] = green[2] = blue[2] = 255; // fully clipped/saturated
    red[3] = green[3] = blue[3] = 0; // border padding

    const std::array<double, 6> transform{100.0, 1.0, 0.0, 200.0, 0.0, -1.0};
    const int epsg = 32645;
    createByteGeoTiff(path, 4, 4, {red, green, blue}, &transform, &epsg);

    const ImageQualityResult result = timedCall(
        "ImagePreprocessingService::process rgb-4x4",
        [&] { return ImagePreprocessingService::process(makeScene(path)); });

    ASSERT_EQ(result.normalizedRgbTensor.data.size(), 48U);
    EXPECT_EQ(result.normalizedRgbTensor.width, 4);
    EXPECT_EQ(result.normalizedRgbTensor.height, 4);
    EXPECT_EQ(result.normalizedRgbTensor.channels, 3);
    EXPECT_EQ(result.normalizedRgbTensor.layout, TensorLayout::CHW);
    EXPECT_EQ(result.normalizedRgbTensor.colorOrder, ColorOrder::RGB);

    constexpr std::size_t validPixel = 4;
    constexpr std::size_t channelSize = 16;
    EXPECT_NEAR(
        result.normalizedRgbTensor.data[validPixel],
        ((100.0F / 255.0F) - 0.485F) / 0.229F,
        1.0e-6F);
    EXPECT_NEAR(
        result.normalizedRgbTensor.data[channelSize + validPixel],
        ((120.0F / 255.0F) - 0.456F) / 0.224F,
        1.0e-6F);
    EXPECT_NEAR(
        result.normalizedRgbTensor.data[2 * channelSize + validPixel],
        ((80.0F / 255.0F) - 0.406F) / 0.225F,
        1.0e-6F);

    EXPECT_EQ(result.cloudMask.data[0], 1);
    EXPECT_EQ(result.shadowMask.data[1], 1);
    EXPECT_EQ(result.saturationMask.data[2], 1);
    EXPECT_EQ(result.saturationMask.data[3], 1);
    EXPECT_EQ(result.validPixelMask.data[0], 0);
    EXPECT_EQ(result.validPixelMask.data[1], 1);
    EXPECT_EQ(result.validPixelMask.data[2], 0);
    EXPECT_EQ(result.validPixelMask.data[3], 0);
    EXPECT_EQ(result.validPixelMask.data[4], 1);
    EXPECT_NEAR(result.qualityScore, 13.0F / 16.0F, 1.0e-6F);
}

TEST(ImagePreprocessingServiceTest, AppliesGrayscaleCloudAndShadowRules)
{
    const std::string path = uniqueVsiPath("preprocess_gray");
    VsiPathGuard guard(path);

    std::vector<uint8_t> grayscale(16, 100);
    grayscale[0] = 20;
    grayscale[1] = 220;

    const std::array<double, 6> transform{0.0, 1.0, 0.0, 0.0, 0.0, -1.0};
    const int epsg = 32645;
    createByteGeoTiff(path, 4, 4, {grayscale}, &transform, &epsg);

    const ImageQualityResult result = timedCall(
        "ImagePreprocessingService::process grayscale-4x4",
        [&] { return ImagePreprocessingService::process(makeScene(path)); });

    EXPECT_EQ(result.shadowMask.data[0], 1);
    EXPECT_EQ(result.cloudMask.data[1], 1);
    EXPECT_EQ(result.validPixelMask.data[0], 1);
    EXPECT_EQ(result.validPixelMask.data[1], 0);
    EXPECT_EQ(result.validPixelMask.data[2], 1);
    EXPECT_NEAR(result.qualityScore, 15.0F / 16.0F, 1.0e-6F);

    EXPECT_NEAR(
        result.normalizedRgbTensor.data[2],
        ((100.0F / 255.0F) - 0.485F) / 0.229F,
        1.0e-6F);
    EXPECT_NEAR(
        result.normalizedRgbTensor.data[16 + 2],
        ((100.0F / 255.0F) - 0.456F) / 0.224F,
        1.0e-6F);
    EXPECT_NEAR(
        result.normalizedRgbTensor.data[32 + 2],
        ((100.0F / 255.0F) - 0.406F) / 0.225F,
        1.0e-6F);
}

TEST(ImagePreprocessingServiceTest, RejectsMissingRasterPath)
{
    EXPECT_THROW(
        static_cast<void>(timedCall(
            "ImagePreprocessingService::process missing-file",
            [&] { return ImagePreprocessingService::process(makeScene("/vsimem/missing.tif")); })),
        std::runtime_error);
}

TEST(ImagePreprocessingServiceTest, RejectsSceneAndDatasetDimensionMismatch)
{
    const std::string path = uniqueVsiPath("preprocess_mismatch");
    VsiPathGuard guard(path);
    const std::vector<uint8_t> band(16, 100);
    const std::array<double, 6> transform{0.0, 1.0, 0.0, 0.0, 0.0, -1.0};
    const int epsg = 32645;
    createByteGeoTiff(path, 4, 4, {band, band, band}, &transform, &epsg);

    EXPECT_THROW(
        static_cast<void>(timedCall(
            "ImagePreprocessingService::process dimension-mismatch",
            [&] { return ImagePreprocessingService::process(makeScene(path, 3, 4)); })),
        std::invalid_argument);
}

} // namespace
