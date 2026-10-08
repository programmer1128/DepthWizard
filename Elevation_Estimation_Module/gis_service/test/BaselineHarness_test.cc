#include <gtest/gtest.h>
#include "BuildingReconstructionTestSupport.h"
#include "BuildingReconstruction/BuildingReconstructionService.h"
#include "MeshMapping/SceneMeshService.h"
#include "tools/BaselineInspector.h"
#include "utils/FeatureFlags.h"

#include <gdal_priv.h>
#include <opencv2/imgcodecs.hpp>

#include <cmath>
#include <cstring>
#include <filesystem>
#include <limits>
#include <map>
#include <unistd.h>

using namespace depthwizard::test;

namespace
{
HybridFeatureFlags parse(std::map<std::string, std::string> values)
{
    return HybridFeatureFlags::parse([values](const std::string& name) -> std::optional<std::string>
    {
        const auto found = values.find(name);
        if (found == values.end()) return std::nullopt;
        return found->second;
    });
}

struct GeneratedScene
{
    BuildingCollection buildings;
    GlbBuildResult glb;
};

// A small urban scene through the real reconstruction and GLB path.
GeneratedScene generateScene()
{
    constexpr int n = 32;
    auto metadata = makeProjectedMetadata(n, n, .5, -.5);
    auto semantics = makeSemanticScene(n, n, SemanticClass::ROAD);
    fillRectangle(semantics.finalClassMap, 4, 4, 28, 28, SemanticClass::BUILDING);
    fillRectangle(semantics.buildingProbability, 4, 4, 28, 28, .95F);
    auto surface = makeSurface(n, n, 100, 10);
    surface.spatialMetadata = metadata;
    fillRectangle(surface.ndsm, 16, 4, 28, 28, 25.0F);
    for (std::size_t i = 0; i < surface.dsm.data.size(); ++i)
        surface.dsm.data[i] = surface.dtm.data[i] + surface.ndsm.data[i];

    GeneratedScene result;
    BuildingReconstructionConfig config;
    result.buildings = BuildingReconstructionService::reconstruct(semantics, surface, metadata, config);

    SceneInput scene;
    scene.width = scene.height = n;
    scene.spatialMetadata = metadata;
    scene.textureMimeType = "image/png";
    cv::Mat optical(n, n, CV_8UC3, cv::Scalar(80, 80, 80));
    cv::imencode(".png", optical, scene.rgbTextureBytes);
    MeshBuildConfig meshConfig;
    meshConfig.presentation = ScenePresentation::FLAT_URBAN;
    result.glb = SceneMeshService::generateGlb(scene, surface, result.buildings, metadata, meshConfig);
    return result;
}

std::string writeRaster(const std::string& name, const std::vector<float>& values, int width, int height)
{
    const auto path = (std::filesystem::temp_directory_path() /
                       (name + "_" + std::to_string(getpid()) + ".tif")).string();
    GDALAllRegister();
    GDALDataset* dataset = GetGDALDriverManager()->GetDriverByName("GTiff")->Create(
        path.c_str(), width, height, 1, GDT_Float32, nullptr);
    double transform[6] = {500000.0, 0.5, 0.0, 2000000.0, 0.0, -0.5};
    dataset->SetGeoTransform(transform);
    dataset->GetRasterBand(1)->SetNoDataValue(std::numeric_limits<double>::quiet_NaN());
    std::vector<float> copy = values;
    (void)dataset->GetRasterBand(1)->RasterIO(GF_Write, 0, 0, width, height, copy.data(),
                                              width, height, GDT_Float32, 0, 0);
    GDALClose(dataset);
    return path;
}
} // namespace

TEST(HybridFeatureFlagsTest, DefaultsReproduceTheCurrentPipeline)
{
    const HybridFeatureFlags flags = parse({});
    EXPECT_EQ(flags.presentationStyle, PresentationStyle::SCIENTIFIC);
    EXPECT_FALSE(flags.neutralFacades);
    EXPECT_FALSE(flags.sam2);
    EXPECT_FALSE(flags.kibs);
    EXPECT_FALSE(flags.hybridFusion);
    EXPECT_TRUE(flags.allDefault());
    EXPECT_TRUE(flags.unimplementedRequests().empty());
    EXPECT_TRUE(flags.warnings.empty());
    EXPECT_EQ(flags.summary(),
              "presentation_style=scientific neutral_facades=0 sam2=0 kibs=0 hybrid_fusion=0 city3d=0 city3d_mode=shadow");

    // Explicit "off" values are the same as unset.
    EXPECT_TRUE(parse({{"DEPTHWIZARD_PRESENTATION_STYLE", "scientific"}, {"DEPTHWIZARD_SAM2", "0"},
                       {"DEPTHWIZARD_KIBS", ""}, {"DEPTHWIZARD_HYBRID_FUSION", "off"},
                       {"DEPTHWIZARD_NEUTRAL_FACADES", "false"}}).allDefault());
}

TEST(HybridFeatureFlagsTest, PresentationStylesAreImplementedAndModelFlagsAreNot)
{
    const HybridFeatureFlags flags = parse({{"DEPTHWIZARD_PRESENTATION_STYLE", "Terra"},
                                            {"DEPTHWIZARD_NEUTRAL_FACADES", "1"},
                                            {"DEPTHWIZARD_SAM2", "1"},
                                            {"DEPTHWIZARD_KIBS", "true"},
                                            {"DEPTHWIZARD_HYBRID_FUSION", "ON"}});
    EXPECT_EQ(flags.presentationStyle, PresentationStyle::TERRA_MASSING);
    EXPECT_TRUE(flags.neutralFacades && flags.sam2 && flags.kibs && flags.hybridFusion);
    EXPECT_FALSE(flags.allDefault());
    // Phase 2 implements presentation styles; SAM2, KIBS and fusion remain unimplemented.
    EXPECT_EQ(flags.unimplementedRequests(),
              (std::vector<std::string>{"DEPTHWIZARD_SAM2=1", "DEPTHWIZARD_KIBS=1", "DEPTHWIZARD_HYBRID_FUSION=1"}));
    EXPECT_EQ(flags.toJson()["presentation_style"].asString(), "terra");
    EXPECT_EQ(parse({{"DEPTHWIZARD_PRESENTATION_STYLE", "orthophoto"}}).presentationStyle,
              PresentationStyle::ORTHOPHOTO_REALISTIC);
    EXPECT_EQ(parse({{"DEPTHWIZARD_PRESENTATION_STYLE", "ORTHOPHOTO_REALISTIC"}}).presentationStyle,
              PresentationStyle::ORTHOPHOTO_REALISTIC);
}

TEST(HybridFeatureFlagsTest, InvalidValuesFallBackToDefaultsWithWarnings)
{
    const HybridFeatureFlags flags = parse({{"DEPTHWIZARD_PRESENTATION_STYLE", "photoreal"},
                                            {"DEPTHWIZARD_SAM2", "maybe"},
                                            {"DEPTHWIZARD_KIBS", "2"}});
    EXPECT_TRUE(flags.allDefault());
    EXPECT_EQ(flags.warnings.size(), 3U);
}

TEST(BaselineInspectorTest, DecodesDracoGlbWithBuildingIdsAndBackendCounts)
{
    const GeneratedScene scene = generateScene();
    ASSERT_FALSE(scene.glb.compressedGlbByteBuffer.empty());
    ASSERT_FALSE(scene.buildings.buildings.empty());

    const Json::Value report = BaselineInspector::inspectGlb(scene.glb.compressedGlbByteBuffer);
    EXPECT_EQ(report["schema"].asString(), "depthwizard.baseline.glb.v1");
    ASSERT_EQ(report["primitives"].size(), 4U); // terrain, roof, wall, edge lines

    // Triangle counts match what SceneMeshService reported it packed.
    EXPECT_EQ(report["primitives"][0]["triangle_count"].asUInt64(), scene.glb.terrainTriangleCount);
    EXPECT_EQ(report["primitives"][1]["triangle_count"].asUInt64(), scene.glb.roofTriangleCount);
    EXPECT_EQ(report["primitives"][2]["triangle_count"].asUInt64(), scene.glb.wallTriangleCount);
    EXPECT_TRUE(report["primitives"][1]["draco"].asBool());
    EXPECT_EQ(report["primitives"][3]["mode"].asInt(), 1); // LINES

    // Building IDs decoded from _FEATURE_ID_0 are exactly the emitted buildings.
    std::vector<Json::Int64> expected;
    for (const auto& building : scene.buildings.buildings) expected.push_back(building.buildingId);
    std::sort(expected.begin(), expected.end());
    ASSERT_EQ(report["building_ids"].size(), expected.size());
    for (Json::ArrayIndex index = 0; index < report["building_ids"].size(); ++index)
        EXPECT_EQ(report["building_ids"][index].asInt64(), expected[index]);

    // Bounds: the 16 m scene spans +/-8 m around its centre in X and Z.
    const Json::Value& bounds = report["totals"]["bounds"];
    EXPECT_NEAR(bounds["min"][0].asDouble(), -8.0, 0.5);
    EXPECT_NEAR(bounds["max"][0].asDouble(), 8.0, 0.5);
    EXPECT_GT(bounds["max"][1].asDouble(), 20.0); // roof height in the flat frame
}

TEST(BaselineInspectorTest, ReportsAreDeterministicAcrossRuns)
{
    const Json::Value first = BaselineInspector::inspectGlb(generateScene().glb.compressedGlbByteBuffer);
    const Json::Value second = BaselineInspector::inspectGlb(generateScene().glb.compressedGlbByteBuffer);
    EXPECT_EQ(first, second);
}

TEST(BaselineInspectorTest, RasterDigestTracksValuesNotNaNPayloads)
{
    constexpr int w = 4, h = 3;
    std::vector<float> values(w * h, 12.5f);
    values[5] = std::numeric_limits<float>::quiet_NaN();
    const std::string a = writeRaster("baseline_a", values, w, h);

    // A different NaN payload and a negative zero describe the same science.
    std::vector<float> variant = values;
    uint32_t payload = 0x7fc00123u;
    std::memcpy(&variant[5], &payload, sizeof(payload));
    variant[0] = 12.5f;
    const std::string b = writeRaster("baseline_b", variant, w, h);

    std::vector<float> changed = values;
    changed[7] = 12.75f;
    const std::string c = writeRaster("baseline_c", changed, w, h);

    const Json::Value reportA = BaselineInspector::inspectRaster(a);
    const Json::Value reportB = BaselineInspector::inspectRaster(b);
    const Json::Value reportC = BaselineInspector::inspectRaster(c);
    EXPECT_EQ(reportA["bands"][0]["pixel_sha256"], reportB["bands"][0]["pixel_sha256"]);
    EXPECT_NE(reportA["bands"][0]["pixel_sha256"], reportC["bands"][0]["pixel_sha256"]);
    EXPECT_EQ(reportA["bands"][0]["valid_pixels"].asUInt64(), 11U);
    EXPECT_EQ(reportA["bands"][0]["invalid_pixels"].asUInt64(), 1U);
    EXPECT_DOUBLE_EQ(reportA["geotransform"][1].asDouble(), 0.5);
    for (const auto& path : {a, b, c}) std::filesystem::remove(path);
}

TEST(BaselineInspectorTest, NegativeZeroAndZeroDigestEqually)
{
    const std::string positive = writeRaster("baseline_pz", {0.0f, 1.0f}, 2, 1);
    const std::string negative = writeRaster("baseline_nz", {-0.0f, 1.0f}, 2, 1);
    EXPECT_EQ(BaselineInspector::inspectRaster(positive)["bands"][0]["pixel_sha256"],
              BaselineInspector::inspectRaster(negative)["bands"][0]["pixel_sha256"]);
    std::filesystem::remove(positive);
    std::filesystem::remove(negative);
}
