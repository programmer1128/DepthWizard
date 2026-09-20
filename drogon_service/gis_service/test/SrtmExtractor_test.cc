#include <gtest/gtest.h>

#include "SrtmExtractor/SrtmExtractor.h"

#include <cpl_conv.h>
#include <gdal_priv.h>
#include <ogr_spatialref.h>

#include <algorithm>
#include <array>
#include <chrono>
#include <cctype>
#include <filesystem>
#include <format>
#include <fstream>
#include <functional>
#include <iostream>
#include <optional>
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
        if constexpr (std::is_void_v<ReturnType>)
        {
            std::invoke(std::forward<Callable>(callable));

            logger.writeLatency(
                operation,
                std::chrono::steady_clock::now() - start);
        }
        else
        {
            ReturnType result =
                std::invoke(std::forward<Callable>(callable));

            logger.writeLatency(
                operation,
                std::chrono::steady_clock::now() - start);

            return result;
        }
    }
    catch (...)
    {
        logger.writeLatency(
            std::format("{} [THREW]", operation),
            std::chrono::steady_clock::now() - start);

        throw;
    }
}

GDALDatasetPtr createMockDataset(
    std::array<double, 6> geoTransform,
    const std::vector<float>& heights,
    const std::optional<std::string>& projection)
{
    constexpr int width = 4;
    constexpr int height = 4;
    constexpr std::size_t pixelCount = width * height;

    if (heights.size() != pixelCount)
    {
        throw std::invalid_argument(
            "Mock 4x4 dataset requires exactly 16 height values.");
    }

    GDALDriver* driver =
        GetGDALDriverManager()->GetDriverByName("MEM");

    if (driver == nullptr)
    {
        throw std::runtime_error("GDAL MEM driver is unavailable.");
    }

    GDALDatasetPtr dataset(
        driver->Create("", width, height, 1, GDT_Float32, nullptr));

    if (!dataset)
    {
        throw std::runtime_error("Failed to create GDAL MEM dataset.");
    }

    if (dataset->SetGeoTransform(geoTransform.data()) != CE_None)
    {
        throw std::runtime_error("Failed to assign mock GeoTransform.");
    }

    if (projection.has_value())
    {
        OGRSpatialReference spatialReference;

        if (spatialReference.SetFromUserInput(projection->c_str()) !=
            OGRERR_NONE)
        {
            throw std::runtime_error("Failed to parse mock projection.");
        }

#if GDAL_VERSION_MAJOR >= 3
        spatialReference.SetAxisMappingStrategy(
            OAMS_TRADITIONAL_GIS_ORDER);
#endif

        char* wkt = nullptr;

        if (spatialReference.exportToWkt(&wkt) != OGRERR_NONE ||
            wkt == nullptr)
        {
            throw std::runtime_error("Failed to export mock projection.");
        }

        const CPLErr projectionResult = dataset->SetProjection(wkt);
        CPLFree(wkt);

        if (projectionResult != CE_None)
        {
            throw std::runtime_error(
                "Failed to assign mock projection.");
        }
    }

    GDALRasterBand* band = dataset->GetRasterBand(1);

    if (band == nullptr)
    {
        throw std::runtime_error("Mock raster band is unavailable.");
    }

    std::vector<float> writableHeights = heights;

    if (band->RasterIO(
            GF_Write,
            0,
            0,
            width,
            height,
            writableHeights.data(),
            width,
            height,
            GDT_Float32,
            0,
            0,
            nullptr) != CE_None)
    {
        throw std::runtime_error("Failed to populate mock raster.");
    }

    return dataset;
}

class SrtmExtractorTest : public testing::Test
{
protected:
    static void SetUpTestSuite()
    {
        initGDAL();
    }
};

TEST_F(SrtmExtractorTest, ExtractsAxisAlignedBoundsFromMock4x4Raster)
{
    PerTestLogger log;

    // Heights intentionally include negative and extreme values. Bounds
    // extraction must depend only on raster geometry, not elevation values.
    const std::vector<float> heights{
        -500.0F, -20.0F, 0.0F, 1.0F,
        10.0F, 20.0F, 30.0F, 40.0F,
        100.0F, 500.0F, 8848.0F, 100000.0F,
        -100000.0F, 3.5F, 7.25F, 42.0F
    };

    auto dataset = createMockDataset(
        {100.0, 2.0, 0.0, 200.0, 0.0, -3.0},
        heights,
        std::string{"EPSG:4326"});

    const GpsBounds bounds = timedCall(
        log,
        "SrtmExtractor::extractGpsBounds axis-aligned 4x4",
        [&]
        {
            return SrtmExtractor::extractGpsBounds(dataset.get());
        });

    EXPECT_EQ(bounds.pixels_x, 4);
    EXPECT_EQ(bounds.pixels_y, 4);
    EXPECT_DOUBLE_EQ(bounds.min_x, 100.0);
    EXPECT_DOUBLE_EQ(bounds.max_x, 108.0);
    EXPECT_DOUBLE_EQ(bounds.min_y, 188.0);
    EXPECT_DOUBLE_EQ(bounds.max_y, 200.0);

    OGRSpatialReference actual;
    OGRSpatialReference expected;

    ASSERT_EQ(
        actual.SetFromUserInput(bounds.crs.c_str()),
        OGRERR_NONE);

    ASSERT_EQ(
        expected.SetFromUserInput("EPSG:4326"),
        OGRERR_NONE);

#if GDAL_VERSION_MAJOR >= 3
    actual.SetAxisMappingStrategy(OAMS_TRADITIONAL_GIS_ORDER);
    expected.SetAxisMappingStrategy(OAMS_TRADITIONAL_GIS_ORDER);
#endif

    EXPECT_TRUE(actual.IsSame(&expected));
}

TEST_F(SrtmExtractorTest, IncludesRotationAndSkewInFourCornerBounds)
{
    PerTestLogger log;

    const std::vector<float> heights(16, 120.0F);

    auto dataset = createMockDataset(
        {100.0, 2.0, 0.5, 200.0, -0.25, -3.0},
        heights,
        std::string{"EPSG:4326"});

    const GpsBounds bounds = timedCall(
        log,
        "SrtmExtractor::extractGpsBounds rotated 4x4",
        [&]
        {
            return SrtmExtractor::extractGpsBounds(dataset.get());
        });

    // Transformed corners:
    // TL=(100,200), TR=(108,199), BR=(110,187), BL=(102,188).
    EXPECT_DOUBLE_EQ(bounds.min_x, 100.0);
    EXPECT_DOUBLE_EQ(bounds.max_x, 110.0);
    EXPECT_DOUBLE_EQ(bounds.min_y, 187.0);
    EXPECT_DOUBLE_EQ(bounds.max_y, 200.0);
}

TEST_F(SrtmExtractorTest, MissingProjectionUsesDocumentedDefault)
{
    PerTestLogger log;

    const std::vector<float> heights(16, 0.0F);

    auto dataset = createMockDataset(
        {77.0, 0.01, 0.0, 29.0, 0.0, -0.01},
        heights,
        std::nullopt);

    const GpsBounds bounds = timedCall(
        log,
        "SrtmExtractor::extractGpsBounds missing projection",
        [&]
        {
            return SrtmExtractor::extractGpsBounds(dataset.get());
        });

    EXPECT_EQ(bounds.crs, "EPSG:4326");
    EXPECT_EQ(bounds.pixels_x, 4);
    EXPECT_EQ(bounds.pixels_y, 4);
}

TEST_F(SrtmExtractorTest, NullDatasetReturnsDefaultBoundsWithoutCrash)
{
    PerTestLogger log;

    const GpsBounds bounds = timedCall(
        log,
        "SrtmExtractor::extractGpsBounds null dataset",
        []
        {
            return SrtmExtractor::extractGpsBounds(
                static_cast<GDALDataset*>(nullptr));
        });

    EXPECT_DOUBLE_EQ(bounds.min_x, 0.0);
    EXPECT_DOUBLE_EQ(bounds.min_y, 0.0);
    EXPECT_DOUBLE_EQ(bounds.max_x, 0.0);
    EXPECT_DOUBLE_EQ(bounds.max_y, 0.0);
    EXPECT_EQ(bounds.pixels_x, 0);
    EXPECT_EQ(bounds.pixels_y, 0);
    EXPECT_EQ(bounds.crs, "EPSG:4326");
}

TEST_F(SrtmExtractorTest, BuildsExactCopernicusUrlsForBothHemispheres)
{
    PerTestLogger log;

    const std::string northEast = timedCall(
        log,
        "SrtmExtractor::buildCopernicusUrl northeast",
        []
        {
            return SrtmExtractor::buildCopernicusUrl(
                28.6139,
                77.2090);
        });

    EXPECT_EQ(
        northEast,
        "/vsicurl/https://copernicus-dem-30m.s3.eu-central-1."
        "amazonaws.com/Copernicus_DSM_COG_10_N28_00_E077_00_DEM/"
        "Copernicus_DSM_COG_10_N28_00_E077_00_DEM.tif");

    const std::string southWest = timedCall(
        log,
        "SrtmExtractor::buildCopernicusUrl southwest",
        []
        {
            return SrtmExtractor::buildCopernicusUrl(-0.1, -0.1);
        });

    EXPECT_EQ(
        southWest,
        "/vsicurl/https://copernicus-dem-30m.s3.eu-central-1."
        "amazonaws.com/Copernicus_DSM_COG_10_S01_00_W001_00_DEM/"
        "Copernicus_DSM_COG_10_S01_00_W001_00_DEM.tif");
}

TEST_F(SrtmExtractorTest, BuildsExactDefaultZoomSrtmUrl)
{
    PerTestLogger log;

    const std::string url = timedCall(
        log,
        "SrtmExtractor::buildSrtmUrl equator",
        []
        {
            return SrtmExtractor::buildSrtmUrl(0.0, 0.0);
        });

    EXPECT_EQ(
        url,
        "/vsicurl/https://elevation-tiles-prod.s3.amazonaws.com/"
        "geotiff/12/2048/2048.tif");
}

TEST_F(SrtmExtractorTest, InvalidInputPathReturnsNullDatasets)
{
    PerTestLogger log;

    RasterDatasets datasets = timedCall(
        log,
        "SrtmExtractor::fetchTile invalid local path",
        []
        {
            return SrtmExtractor::fetchTile(
                "/definitely/not/a/real/input/geotiff.tif");
        });

    EXPECT_EQ(datasets.hInputDS, nullptr);
    EXPECT_EQ(datasets.hDemDS, nullptr);
}

} // namespace