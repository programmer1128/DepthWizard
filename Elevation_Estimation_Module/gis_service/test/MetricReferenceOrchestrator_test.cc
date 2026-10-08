#include <gtest/gtest.h>

#include "ReferenceTerrainService/MetricReferenceOrchestrator.h"
#include "RasterProcessor/RasterProcessor.h"
#include "SrtmExtractor/SrtmExtractor.h"

#include <chrono>
#include <format>
#include <iostream>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

namespace test_double
{

enum class ThrowPoint
{
    None,
    Fetch,
    Warp,
    Preprocess
};

struct State
{
    int fetchCalls{0};
    int warpCalls{0};
    int preprocessCalls{0};

    bool returnNullDem{false};
    ThrowPoint throwPoint{ThrowPoint::None};

    std::string fetchedPath;
    std::string receivedDemSource;
    SpatialMetadata receivedMetadata;
    RasterGrid<float> warpedDem;

    std::vector<std::string> callOrder;
};

State state;

template<typename T>
RasterGrid<T> makeConstantGrid(
    const int width,
    const int height,
    const T value)
{
    RasterGrid<T> grid;
    grid.width = width;
    grid.height = height;
    grid.data.assign(
        static_cast<std::size_t>(width) *
            static_cast<std::size_t>(height),
        value);
    return grid;
}

GDALDatasetPtr createMemoryDem()
{
    GDALAllRegister();

    GDALDriver* driver =
        GetGDALDriverManager()->GetDriverByName("MEM");

    if (driver == nullptr)
    {
        throw std::runtime_error("GDAL MEM driver is unavailable");
    }

    GDALDataset* rawDataset =
        driver->Create("", 4, 4, 1, GDT_Float32, nullptr);

    if (rawDataset == nullptr)
    {
        throw std::runtime_error("Could not create mock GDAL dataset");
    }

    return GDALDatasetPtr(rawDataset);
}

ReferenceTerrainBundle executeWithTiming(const SceneInput& scene)
{
    const auto start = std::chrono::steady_clock::now();

    try
    {
        ReferenceTerrainBundle result =
            drogon::sync_wait(
                MetricReferenceOrchestrator::prepareReferenceTerrain(scene));

        const auto elapsed = std::chrono::steady_clock::now() - start;

        std::cout << std::format(
            "[LATENCY] operation=prepareReferenceTerrain "
            "elapsed_us={:.3f}\n",
            std::chrono::duration<double, std::micro>(elapsed).count());

        return result;
    }
    catch (...)
    {
        const auto elapsed = std::chrono::steady_clock::now() - start;

        std::cout << std::format(
            "[LATENCY] operation=prepareReferenceTerrain[THREW] "
            "elapsed_us={:.3f}\n",
            std::chrono::duration<double, std::micro>(elapsed).count());

        throw;
    }
}

} // namespace test_double

// -------------------------------------------------------------------------
// Link-time test doubles
//
// Do not link the real SrtmExtractor.cc, RasterProcessor.cc or
// ReferenceDemPreprocessor.cc into this particular test target.
// -------------------------------------------------------------------------

RasterDatasets SrtmExtractor::fetchTile(const std::string& filePath)
{
    auto& state = test_double::state;

    ++state.fetchCalls;
    state.callOrder.emplace_back("fetch");
    state.fetchedPath = filePath;

    if (state.throwPoint == test_double::ThrowPoint::Fetch)
    {
        throw std::runtime_error("Mock DEM fetch failure");
    }

    RasterDatasets result;

    if (!state.returnNullDem)
    {
        result.hDemDS = test_double::createMemoryDem();
    }

    return result;
}

RasterGrid<float> RasterProcessor::warpDemToScene(
    const GDALDatasetPtr& demDataset,
    const SpatialMetadata& metadata)
{
    auto& state = test_double::state;

    ++state.warpCalls;
    state.callOrder.emplace_back("warp");
    state.receivedMetadata = metadata;

    if (state.throwPoint == test_double::ThrowPoint::Warp)
    {
        throw std::runtime_error("Mock DEM warp failure");
    }

    if (!demDataset)
    {
        throw std::invalid_argument(
            "Mock RasterProcessor received null DEM");
    }

    return state.warpedDem;
}

ReferenceTerrainBundle ReferenceDemPreprocessor::process(
    const RasterGrid<float>& warpedDem,
    const SceneInput&,
    const std::string& demSource)
{
    auto& state = test_double::state;

    ++state.preprocessCalls;
    state.callOrder.emplace_back("preprocess");
    state.receivedDemSource = demSource;

    if (state.throwPoint == test_double::ThrowPoint::Preprocess)
    {
        throw std::runtime_error("Mock DEM preprocessing failure");
    }

    ReferenceTerrainBundle result;
    result.rawWarpedDem = warpedDem;
    result.correctedTerrainPrior = warpedDem;
    result.demSource = demSource;
    result.sourceResolutionMeters = 30.0F;

    result.validMask =
        test_double::makeConstantGrid<uint8_t>(
            warpedDem.width,
            warpedDem.height,
            uint8_t{1});

    result.confidence =
        test_double::makeConstantGrid<float>(
            warpedDem.width,
            warpedDem.height,
            0.75F);

    return result;
}

// -------------------------------------------------------------------------
// Tests
// -------------------------------------------------------------------------

class MetricReferenceOrchestratorTest : public testing::Test
{
protected:
    void SetUp() override
    {
        test_double::state = {};

        test_double::state.warpedDem.width = 4;
        test_double::state.warpedDem.height = 4;
        test_double::state.warpedDem.data = {
            100.0F, 101.0F, 102.0F, 103.0F,
            104.0F, 105.0F, 106.0F, 107.0F,
            108.0F, 109.0F, 110.0F, 111.0F,
            112.0F, 113.0F, 114.0F, 115.0F,
        };

        SpatialMetadata metadata;
        metadata.width = 4;
        metadata.height = 4;
        metadata.geoTransform = {
            500000.0,
            1.0,
            0.0,
            2000000.0,
            0.0,
            -1.0};
        metadata.projectionRef = "EPSG:32645";
        metadata.isGeoreferenced = true;

        scene_.jobId = "orchestrator-test";
        scene_.inputPath = "/mock/input.tif";
        scene_.inputMode = PipelineMode::GEOREFERENCED;
        scene_.width = 4;
        scene_.height = 4;
        scene_.spatialMetadata = metadata;
        scene_.sourceFormat = "GTiff";
    }

    SceneInput scene_;
};

TEST_F(
    MetricReferenceOrchestratorTest,
    RejectsMissingSpatialMetadataBeforeFetchingDem)
{
    scene_.spatialMetadata = std::nullopt;

    EXPECT_THROW(
        {
            static_cast<void>(
                test_double::executeWithTiming(scene_));
        },
        std::runtime_error);

    EXPECT_EQ(test_double::state.fetchCalls, 0);
    EXPECT_EQ(test_double::state.warpCalls, 0);
    EXPECT_EQ(test_double::state.preprocessCalls, 0);
}

TEST_F(
    MetricReferenceOrchestratorTest,
    RejectsNullDemReturnedByExtractor)
{
    test_double::state.returnNullDem = true;

    EXPECT_THROW(
        {
            static_cast<void>(
                test_double::executeWithTiming(scene_));
        },
        std::runtime_error);

    EXPECT_EQ(test_double::state.fetchCalls, 1);
    EXPECT_EQ(test_double::state.warpCalls, 0);
    EXPECT_EQ(test_double::state.preprocessCalls, 0);
}

TEST_F(
    MetricReferenceOrchestratorTest,
    ExecutesDependenciesInCorrectOrder)
{
    const ReferenceTerrainBundle result =
        test_double::executeWithTiming(scene_);

    EXPECT_EQ(
        test_double::state.callOrder,
        (std::vector<std::string>{
            "fetch",
            "warp",
            "preprocess"}));

    EXPECT_EQ(test_double::state.fetchCalls, 1);
    EXPECT_EQ(test_double::state.warpCalls, 1);
    EXPECT_EQ(test_double::state.preprocessCalls, 1);

    EXPECT_EQ(
        test_double::state.fetchedPath,
        scene_.inputPath);

    EXPECT_EQ(
        test_double::state.receivedMetadata.width,
        4);

    EXPECT_EQ(
        test_double::state.receivedMetadata.height,
        4);

    // A MEM dataset has no Copernicus/SRTM file-list marker.
    EXPECT_EQ(
        test_double::state.receivedDemSource,
        "Unknown_DEM_30m");

    EXPECT_EQ(result.correctedTerrainPrior.width, 4);
    EXPECT_EQ(result.correctedTerrainPrior.height, 4);

    EXPECT_EQ(
        result.correctedTerrainPrior.data,
        test_double::state.warpedDem.data);

    EXPECT_EQ(
        result.validMask.data,
        std::vector<uint8_t>(16, uint8_t{1}));

    EXPECT_EQ(
        result.confidence.data,
        std::vector<float>(16, 0.75F));

    EXPECT_EQ(result.demSource, "Unknown_DEM_30m");
}

TEST_F(
    MetricReferenceOrchestratorTest,
    PropagatesExtractorFailureWithoutRunningLaterStages)
{
    test_double::state.throwPoint =
        test_double::ThrowPoint::Fetch;

    EXPECT_THROW(
        {
            static_cast<void>(
                test_double::executeWithTiming(scene_));
        },
        std::runtime_error);

    EXPECT_EQ(test_double::state.fetchCalls, 1);
    EXPECT_EQ(test_double::state.warpCalls, 0);
    EXPECT_EQ(test_double::state.preprocessCalls, 0);
}

TEST_F(
    MetricReferenceOrchestratorTest,
    PropagatesWarpFailureWithoutPreprocessing)
{
    test_double::state.throwPoint =
        test_double::ThrowPoint::Warp;

    EXPECT_THROW(
        {
            static_cast<void>(
                test_double::executeWithTiming(scene_));
        },
        std::runtime_error);

    EXPECT_EQ(test_double::state.fetchCalls, 1);
    EXPECT_EQ(test_double::state.warpCalls, 1);
    EXPECT_EQ(test_double::state.preprocessCalls, 0);
}

TEST_F(
    MetricReferenceOrchestratorTest,
    PropagatesPreprocessorFailure)
{
    test_double::state.throwPoint =
        test_double::ThrowPoint::Preprocess;

    EXPECT_THROW(
        {
            static_cast<void>(
                test_double::executeWithTiming(scene_));
        },
        std::runtime_error);

    EXPECT_EQ(test_double::state.fetchCalls, 1);
    EXPECT_EQ(test_double::state.warpCalls, 1);
    EXPECT_EQ(test_double::state.preprocessCalls, 1);
}