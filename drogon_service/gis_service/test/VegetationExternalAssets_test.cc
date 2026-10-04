// Stage 5A: bundled external vegetation assets (small bush, forest patch) and
// the dense-canopy forest-patch placement.

#include "BuildingReconstructionTestSupport.h"
#include "MeshMapping/GeoTransformMapping.h"
#include "MeshMapping/LocalFrameTransformer.h"
#include "MeshMapping/TerrainSurfaceSampler.h"
#include "Vegetation/DenseForestProxyGenerator.h"
#include "Vegetation/ExternalVegetationAssetLoader.h"
#include "Vegetation/VegetationCoverGenerator.h"

#include <gtest/gtest.h>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <tiny_gltf.h>

#include <cmath>
#include <fstream>
#include <limits>
#include <set>

using namespace depthwizard::test;
namespace geo = depthwizard::geo;

namespace
{
const std::filesystem::path kAssets = DEPTHWIZARD_VEGETATION_ASSET_SOURCE_DIR;

ExternalVegetationAsset load(const char* file, VegetationAssetSource source)
{
    std::string error;
    auto asset = ExternalVegetationAssetLoader::load(kAssets / file, source, &error);
    EXPECT_TRUE(asset.has_value()) << error;
    return asset ? *asset : ExternalVegetationAsset{};
}
} // namespace

TEST(ExternalVegetationAssetTest, SmallBushKeepsItsMeshUvsAndTextureNormalised)
{
    const ExternalVegetationAsset bush = load("small_bush.glb", VegetationAssetSource::SMALL_BUSH);
    ASSERT_EQ(bush.parts.size(), 1U);
    EXPECT_EQ(bush.triangles(), 320U);   // The 320-triangle source mesh
    const ExternalVegetationPart& part = bush.parts[0];
    EXPECT_EQ(part.positions.size() / 3, 289U);
    EXPECT_EQ(part.uvs.size(), part.positions.size() / 3 * 2);
    // Base 0, top 1, horizontal crown radius 1, centred.
    EXPECT_NEAR(bush.boundsMin[1], 0.0F, 1e-5F);
    EXPECT_NEAR(bush.boundsMax[1], 1.0F, 1e-5F);
    EXPECT_NEAR(bush.horizontalRadius, 1.0F, 1e-4F);
    // Embedded RGBA texture, alpha-tested (no sorting), double-sided, rough.
    ASSERT_EQ(bush.images.size(), 1U);
    EXPECT_EQ(bush.images[0].mimeType, "image/png");
    const cv::Mat image = cv::imdecode(bush.images[0].bytes, cv::IMREAD_UNCHANGED);
    EXPECT_EQ(image.channels(), 4);
    EXPECT_EQ(part.alphaMode, "MASK");
    EXPECT_NEAR(part.alphaCutoff, 0.45, 1e-9);
    EXPECT_TRUE(part.doubleSided);
    EXPECT_GE(part.roughness, 0.9);
    EXPECT_EQ(bush.credits.at("author"), "yanix (https://sketchfab.com/yanix)");
    // Not rectangular cards: well under half of the UV-covered texels pass the cutoff.
    cv::Mat covered = cv::Mat::zeros(image.rows, image.cols, CV_8U);
    for (std::size_t t = 0; t < part.indices.size(); t += 3)
    {
        std::vector<cv::Point> triangle;
        for (int k = 0; k < 3; ++k)
        {
            const uint32_t v = part.indices[t + static_cast<std::size_t>(k)];
            triangle.emplace_back(static_cast<int>(part.uvs[v * 2] * image.cols), static_cast<int>(part.uvs[v * 2 + 1] * image.rows));
        }
        cv::fillConvexPoly(covered, triangle, 255);
    }
    std::vector<cv::Mat> channels;
    cv::split(image, channels);
    const double area = cv::countNonZero(covered);
    const double opaque = cv::countNonZero(covered & (channels[3] >= static_cast<int>(0.45 * 255)));
    ASSERT_GT(area, 0.0);
    EXPECT_LT(opaque / area, 0.6);
    EXPECT_GT(opaque / area, 0.2);
}

TEST(ExternalVegetationAssetTest, ForestPatchDropsTheFloorAndIsYUpWithAlignedTrunks)
{
    const ExternalVegetationAsset forest = load("forest_patch.glb", VegetationAssetSource::FOREST_PATCH);
    std::vector<std::string> names;
    for (const auto& part : forest.parts) names.push_back(part.materialName);
    EXPECT_EQ(names, (std::vector<std::string>{"Vegetation_Forest_Green_Elka", "Vegetation_Forest_Green_sosna_001",
                                                "Vegetation_Forest_Wood_tree_001", "Vegetation_Forest_Wood_tree_002"}));
    for (const auto& name : names)
        for (const char* dropped : {"Floor", "Kust", "Paporotnik"}) EXPECT_EQ(name.find(dropped), std::string::npos);
    EXPECT_EQ(forest.triangles(), 32826U);
    EXPECT_NEAR(forest.boundsMin[1], 0.0F, 1e-5F);
    EXPECT_NEAR(forest.boundsMax[1], 1.0F, 1e-5F);
    // Y-up: a wide, low patch (about 6 units wide per unit of tree height).
    EXPECT_GT(forest.boundsMax[0] - forest.boundsMin[0], 5.0F);
    EXPECT_GT(forest.boundsMax[2] - forest.boundsMin[2], 5.0F);
    EXPECT_EQ(forest.images.size(), 2U);   // Foliage + one shared trunk texture
    for (const TextureAsset& image : forest.images) EXPECT_FALSE(cv::imdecode(image.bytes, cv::IMREAD_UNCHANGED).empty());
    for (const auto& part : forest.parts)
        EXPECT_EQ(part.alphaMode, part.materialName.find("Green") != std::string::npos ? "MASK" : "OPAQUE");

    // Exact alignment with the source: every retained vertex is the source
    // vertex under (x, y, z) -> (x, z, -y), one shared offset and one uniform scale.
    tinygltf::TinyGLTF loader;
    tinygltf::Model source;
    std::string err, warn;
    ASSERT_TRUE(loader.LoadASCIIFromFile(&source, &err, &warn, (kAssets / "../source/forest/scene.gltf").string())) << err;
    const std::vector<std::string> sourceMaterials{"Green_Elka", "Green_sosna.001", "Wood_tree.001", "Wood_tree.002"};
    std::vector<std::vector<float>> converted(sourceMaterials.size());
    for (const tinygltf::Node& node : source.nodes)
    {
        if (node.mesh < 0) continue;
        const tinygltf::Primitive& p = source.meshes[static_cast<std::size_t>(node.mesh)].primitives[0];
        const auto it = std::find(sourceMaterials.begin(), sourceMaterials.end(), source.materials[static_cast<std::size_t>(p.material)].name);
        if (it == sourceMaterials.end()) continue;
        const tinygltf::Accessor& a = source.accessors[static_cast<std::size_t>(p.attributes.at("POSITION"))];
        const tinygltf::BufferView& v = source.bufferViews[static_cast<std::size_t>(a.bufferView)];
        const int stride = a.ByteStride(v);
        for (std::size_t i = 0; i < a.count; ++i)
        {
            const float* xyz = reinterpret_cast<const float*>(source.buffers[0].data.data() + v.byteOffset + a.byteOffset + i * static_cast<std::size_t>(stride));
            auto& out = converted[static_cast<std::size_t>(it - sourceMaterials.begin())];
            out.insert(out.end(), {xyz[0], xyz[2], -xyz[1]});
        }
    }
    float lo[3] = {1e30F, 1e30F, 1e30F}, hi[3] = {-1e30F, -1e30F, -1e30F};
    for (const auto& points : converted)
        for (std::size_t i = 0; i < points.size(); ++i)
        {
            lo[i % 3] = std::min(lo[i % 3], points[i]);
            hi[i % 3] = std::max(hi[i % 3], points[i]);
        }
    EXPECT_NEAR(lo[1], 0.0F, 1e-5F);   // Trunks stand on the source ground (z = 0)
    const float scale = 1.0F / (hi[1] - lo[1]);
    const float cx = (lo[0] + hi[0]) / 2, cz = (lo[2] + hi[2]) / 2;
    double worst = 0.0;
    for (std::size_t k = 0; k < forest.parts.size(); ++k)
    {
        ASSERT_EQ(forest.parts[k].positions.size(), converted[k].size());
        for (std::size_t i = 0; i < converted[k].size(); i += 3)
        {
            worst = std::max<double>(worst, std::abs(forest.parts[k].positions[i] - (converted[k][i] - cx) * scale));
            worst = std::max<double>(worst, std::abs(forest.parts[k].positions[i + 1] - (converted[k][i + 1] - lo[1]) * scale));
            worst = std::max<double>(worst, std::abs(forest.parts[k].positions[i + 2] - (converted[k][i + 2] - cz) * scale));
        }
    }
    EXPECT_LT(worst, 2e-5);
}

TEST(ExternalVegetationAssetTest, MissingOrInvalidAssetsReportAClearReason)
{
    const auto dir = std::filesystem::temp_directory_path() / "dw_stage5a_assets";
    std::filesystem::create_directories(dir);
    std::ofstream(dir / "small_bush.glb") << "not a glb";
    const VegetationAssetPrototypeProvider broken(dir);
    EXPECT_EQ(broken.bush(), nullptr);
    EXPECT_EQ(broken.forest(), nullptr);
    EXPECT_NE(broken.error().find("not a readable GLB"), std::string::npos) << broken.error();
    EXPECT_NE(broken.error().find("file not found"), std::string::npos) << broken.error();
    const VegetationAssetPrototypeProvider bundled(kAssets);
    EXPECT_NE(bundled.bush(), nullptr);
    EXPECT_NE(bundled.forest(), nullptr);
    EXPECT_TRUE(bundled.error().empty()) << bundled.error();
    std::filesystem::remove_all(dir);
}

// --- Forest-patch placement --------------------------------------------------

namespace
{
constexpr int kSize = 400;   // 400 m x 400 m at 1 m

struct ForestScene
{
    SpatialMetadata metadata = makeProjectedMetadata(kSize, kSize, 1.0, -1.0);
    GeoreferencedSurfaceBundle surface = makeSurface(kSize, kSize, 100.0F, 0.0F);
    VegetationMask mask;
    VegetationClassification classes;
    VegetationHeights heights;
    VegetationConfig config;

    explicit ForestScene(float canopyHeight = 12.0F, double slopeDegrees = 0.0)
    {
        surface.spatialMetadata = metadata;
        mask.barrierMask = makeConstantGrid<uint8_t>(kSize, kSize, uint8_t{0});
        classes.classes = makeConstantGrid<uint8_t>(kSize, kSize, uint8_t{0});
        heights.metricHeight = makeConstantGrid(kSize, kSize, std::numeric_limits<float>::quiet_NaN());
        const double rise = std::tan(slopeDegrees * 3.14159265358979 / 180.0);
        for (int y = 0; y < kSize; ++y)
            for (int x = 0; x < kSize; ++x)
            {
                const std::size_t i = index(x, y);
                surface.dtm.data[i] = static_cast<float>(100.0 + rise * x);
                if (x >= 20 && x < 380 && y >= 20 && y < 380)
                {
                    classes.classes.data[i] = static_cast<uint8_t>(VegetationClass::DENSE);
                    // Gentle canopy texture, deterministic.
                    heights.metricHeight.data[i] = canopyHeight + 0.5F * static_cast<float>(std::sin(x * 0.3) * std::cos(y * 0.2));
                }
                const bool building = x >= 180 && x < 220 && y >= 180 && y < 220;
                const bool road = y >= 100 && y < 104;
                if (building || road)
                {
                    mask.barrierMask.data[i] = 1;
                    classes.classes.data[i] = static_cast<uint8_t>(VegetationClass::NONE);
                    heights.metricHeight.data[i] = std::numeric_limits<float>::quiet_NaN();
                }
                if (x >= 280 && x < 290 && y >= 280 && y < 290) heights.metricHeight.data[i] = std::numeric_limits<float>::quiet_NaN();
            }
        for (std::size_t i = 0; i < surface.dsm.data.size(); ++i) surface.dsm.data[i] = surface.dtm.data[i];
        config.mode = VegetationMode::ON;
        config.assetMode = VegetationAssetMode::EXTERNAL;
    }
    std::size_t index(int x, int y) const { return static_cast<std::size_t>(y) * kSize + static_cast<std::size_t>(x); }

    DenseForestProxies run(ScenePresentation presentation = ScenePresentation::METRIC, uint32_t seed = 1337) const
    {
        DenseForestProxyInput input;
        input.mask = &mask;
        input.classification = &classes;
        input.heights = &heights;
        input.surface = &surface;
        input.metadata = &metadata;
        input.frame = LocalFrameTransformer::create(metadata, surface);
        input.presentation = presentation;
        input.config = config;
        input.config.seed = seed;
        input.prototypeRadius = 3.9695F;   // forest_patch.glb
        input.chunkSizeMetres = 100.0;
        return DenseForestProxyGenerator::generate(input);
    }
};

bool sameProxies(const DenseForestProxies& a, const DenseForestProxies& b)
{
    if (a.proxies.size() != b.proxies.size()) return false;
    for (std::size_t k = 0; k < a.proxies.size(); ++k)
        if (a.proxies[k].translation != b.proxies[k].translation || a.proxies[k].rotation != b.proxies[k].rotation ||
            a.proxies[k].scale != b.proxies[k].scale)
            return false;
    return true;
}
} // namespace

TEST(DenseForestProxyTest, PatchesStayInsideDenseCanopyBelowTheEnvelope)
{
    const ForestScene s;
    const DenseForestProxies forest = s.run();
    ASSERT_TRUE(forest.enabled) << forest.disabledReason;
    ASSERT_GE(forest.proxies.size(), 5U);
    EXPECT_LE(forest.proxies.size(), DenseForestProxyGenerator::kMaxPatches);
    const LocalSceneFrame frame = LocalFrameTransformer::create(s.metadata, s.surface);
    for (const ForestProxy& p : forest.proxies)
    {
        // Whole footprint disc: DENSE, no barrier (building, road), finite nDSM, inside the image.
        float maxHeight = 0.0F;
        const auto [cx, cy] = geo::localToPixelEdge(s.metadata, frame, p.translation[0], p.translation[2]);
        EXPECT_NEAR(cx, p.pixelColumn, 1e-3);
        EXPECT_NEAR(cy, p.pixelRow, 1e-3);
        const int r = static_cast<int>(std::ceil(p.footprintRadiusMetres));
        for (int y = static_cast<int>(cy) - r; y <= static_cast<int>(cy) + r; ++y)
            for (int x = static_cast<int>(cx) - r; x <= static_cast<int>(cx) + r; ++x)
            {
                if (std::hypot(x + 0.5 - cx, y + 0.5 - cy) > p.footprintRadiusMetres) continue;
                ASSERT_TRUE(x >= 0 && y >= 0 && x < kSize && y < kSize);
                const std::size_t i = s.index(x, y);
                ASSERT_EQ(s.classes.classes.data[i], static_cast<uint8_t>(VegetationClass::DENSE)) << x << "," << y;
                ASSERT_EQ(s.mask.barrierMask.data[i], 0);
                ASSERT_TRUE(std::isfinite(s.heights.metricHeight.data[i]));
                maxHeight = std::max(maxHeight, s.heights.metricHeight.data[i]);
            }
        // Tallest tree within the local nDSM envelope (never canopy + tree).
        EXPECT_LE(p.scale, p.envelopeMetres + 1e-4F);
        EXPECT_LE(p.envelopeMetres, maxHeight + 1e-4F);
        EXPECT_GE(p.scale, DenseForestProxyGenerator::kMinPatchHeightMetres);
        EXPECT_NEAR(p.footprintRadiusMetres, p.scale * 3.9695F, 1e-3F);
        // Grounded on flat terrain: base = rendered terrain height, no tilt.
        EXPECT_NEAR(p.translation[1], static_cast<float>(100.0 - frame.elevationOrigin), 1e-3F);
        EXPECT_NEAR(p.tiltDegrees, 0.0F, 1e-3F);
        const auto& q = p.rotation;
        EXPECT_NEAR(q[0] * q[0] + q[1] * q[1] + q[2] * q[2] + q[3] * q[3], 1.0F, 1e-5F);
    }
    // Limited overlap between patches.
    for (std::size_t a = 0; a < forest.proxies.size(); ++a)
        for (std::size_t b = a + 1; b < forest.proxies.size(); ++b)
        {
            const auto& pa = forest.proxies[a];
            const auto& pb = forest.proxies[b];
            EXPECT_GE(std::hypot(pa.translation[0] - pb.translation[0], pa.translation[2] - pb.translation[2]) + 1e-3,
                      (1.0 - DenseForestProxyGenerator::kMaxOverlapShare) * (pa.footprintRadiusMetres + pb.footprintRadiusMetres));
        }
}

TEST(DenseForestProxyTest, PlacementIsDeterministicAndSeeded)
{
    const ForestScene s;
    EXPECT_TRUE(sameProxies(s.run(), s.run()));
    EXPECT_FALSE(sameProxies(s.run(ScenePresentation::METRIC, 1337), s.run(ScenePresentation::METRIC, 7)));
}

TEST(DenseForestProxyTest, NoPatchesInFlatUrbanOrAridScenes)
{
    const DenseForestProxies urban = ForestScene().run(ScenePresentation::FLAT_URBAN);
    EXPECT_TRUE(urban.empty());
    EXPECT_NE(urban.disabledReason.find("flat_urban"), std::string::npos);
    const DenseForestProxies arid = ForestScene(2.5F).run();
    EXPECT_TRUE(arid.empty());
    EXPECT_NE(arid.disabledReason.find("arid"), std::string::npos) << arid.disabledReason;
}

TEST(DenseForestProxyTest, PatchesFollowGentleSlopesAndSkipSteepOnes)
{
    const DenseForestProxies gentle = ForestScene(12.0F, 10.0).run();
    ASSERT_FALSE(gentle.empty()) << gentle.disabledReason;
    for (const ForestProxy& p : gentle.proxies)
    {
        EXPECT_NEAR(p.tiltDegrees, 10.0F, 0.3F);
        EXPECT_LE(p.terrainResidualMetres, 0.15F * p.scale);
        // Rotated up axis = terrain normal (-tan 10deg, 1, 0) normalised: leans towards -X.
        const auto& q = p.rotation;
        const float upX = 2.0F * (q[0] * q[1] - q[3] * q[2]);
        const float upY = 1.0F - 2.0F * (q[0] * q[0] + q[2] * q[2]);
        EXPECT_NEAR(std::atan2(-upX, upY) * 180.0F / 3.14159265F, 10.0F, 0.3F);
    }
    const DenseForestProxies steep = ForestScene(12.0F, 30.0).run();
    EXPECT_TRUE(steep.empty());
    EXPECT_GT(steep.stats.rejectedSlope, 0U);
}

// --- Shrub cover (external assets, individual-tree resolution) ----------------

namespace
{
constexpr int kCover = 200;   // 100 m x 100 m at 0.5 m

struct CoverScene
{
    SpatialMetadata metadata = makeProjectedMetadata(kCover, kCover, 0.5, -0.5);
    GeoreferencedSurfaceBundle surface = makeSurface(kCover, kCover, 100.0F, 0.0F);
    SemanticScene semantics = makeSemanticScene(kCover, kCover, SemanticClass::UNKNOWN);
    VegetationMask mask;
    cv::Mat optical{kCover, kCover, CV_8UC3, cv::Scalar(140, 180, 200)};   // Sand (BGR)
    std::vector<uint8_t> bytes;
    std::vector<std::pair<int, int>> shrubs;   // Centres of the drawn shrub blobs

    CoverScene()
    {
        surface.spatialMetadata = metadata;
        mask.barrierMask = makeConstantGrid<uint8_t>(kCover, kCover, uint8_t{0});
        mask.tier = makeConstantGrid<uint8_t>(kCover, kCover, uint8_t{0});
        // Twelve dark-green shrubs (3 m across) the nDSM does not resolve.
        for (int k = 0; k < 12; ++k)
        {
            const int x = 25 + (k % 4) * 45, y = 30 + (k / 4) * 55;
            shrubs.emplace_back(x, y);
            cv::circle(optical, {x, y}, 3, cv::Scalar(50, 95, 75), cv::FILLED);
        }
        // A bluish cast shadow (flat) and a thin dark wall: not shrubs.
        cv::rectangle(optical, {150, 170}, {175, 185}, cv::Scalar(85, 70, 60), cv::FILLED);
        cv::line(optical, {10, 190}, {190, 190}, cv::Scalar(60, 90, 70), 2);
        cv::imencode(".png", optical, bytes);
    }

    VegetationCover run(ScenePresentation presentation = ScenePresentation::METRIC, uint32_t seed = 1337) const
    {
        VegetationCoverInput input;
        input.mask = &mask;
        input.semantics = &semantics;
        input.surface = &surface;
        input.metadata = &metadata;
        input.opticalBytes = &bytes;
        input.frame = LocalFrameTransformer::create(metadata, surface);
        if (presentation == ScenePresentation::FLAT_URBAN)
            input.terrainConfig.elevationSource = TerrainElevationSource::FLAT_PRESENTATION;
        input.presentation = presentation;
        input.displayHeightScale = presentation == ScenePresentation::FLAT_URBAN ? 2.25F : 1.0F;
        input.config.seed = seed;
        input.chunkSizeMetres = 100.0;
        return VegetationCoverGenerator::generate(input);
    }
};
} // namespace

TEST(VegetationCoverTest, ImageShrubsTheNdsmMissesAreFilledButShadowsAndWallsAreNot)
{
    const CoverScene s;
    const VegetationCover cover = s.run();
    ASSERT_TRUE(cover.enabled) << cover.disabledReason;
    EXPECT_EQ(cover.mode, VegetationCoverMode::NATURAL);
    ASSERT_FALSE(cover.empty());
    std::set<std::size_t> found;
    for (const CoverShrub& shrub : cover.shrubs)
    {
        // Every shrub stands on one of the drawn shrub blobs.
        std::size_t nearest = 0;
        double best = 1e9;
        for (std::size_t k = 0; k < s.shrubs.size(); ++k)
        {
            const double d = std::hypot(shrub.pixelColumn - s.shrubs[k].first - 0.5, shrub.pixelRow - s.shrubs[k].second - 0.5);
            if (d < best) { best = d; nearest = k; }
        }
        EXPECT_LT(best, 4.0) << "shrub off the vegetation at " << shrub.pixelColumn << "," << shrub.pixelRow;
        found.insert(nearest);
        // Sized from the image blob (about 3 m across), natural proportion, grounded.
        EXPECT_GE(shrub.radiusMetres, 0.6F);
        EXPECT_LE(shrub.radiusMetres, 2.2F);
        if (!shrub.companion) EXPECT_GE(shrub.metricHeight, 1.2F * shrub.radiusMetres - 1e-4F);
        // Drawn 1.3 x the measured size for prominence.
        EXPECT_NEAR(shrub.scale[1], shrub.metricHeight * VegetationCoverGenerator::kNaturalProminence, 1e-4F);
        EXPECT_NEAR(shrub.scale[0], shrub.radiusMetres * VegetationCoverGenerator::kNaturalProminence, 1e-4F);
        EXPECT_NEAR(shrub.translation[1], 0.0F, 1e-3F);   // Flat DTM at the elevation origin
    }
    EXPECT_EQ(found.size(), s.shrubs.size());   // Every visible shrub is represented
    // Every find is drawn as 3-4 bushes: 2-3 companions per primary shrub.
    const auto companions = static_cast<std::size_t>(std::count_if(cover.shrubs.begin(), cover.shrubs.end(),
                                                                   [](const CoverShrub& c) { return c.companion; }));
    EXPECT_GE(companions, 2 * (cover.shrubs.size() - companions));
    EXPECT_LE(companions, 3 * (cover.shrubs.size() - companions));
    EXPECT_EQ(cover.stats.companions, companions);
    EXPECT_GT(cover.stats.imageDetectedPixels, 0U);
    // Deterministic and seeded.
    const VegetationCover again = s.run();
    ASSERT_EQ(again.shrubs.size(), cover.shrubs.size());
    for (std::size_t k = 0; k < cover.shrubs.size(); ++k) EXPECT_EQ(again.shrubs[k].translation, cover.shrubs[k].translation);
}

TEST(VegetationCoverTest, GardensUseSemanticVegetationAtShrubScaleWithLawnGaps)
{
    CoverScene s;
    for (int y = 40; y < 160; ++y)
        for (int x = 40; x < 160; ++x) s.semantics.finalClassMap.data[static_cast<std::size_t>(y) * kCover + x] = SemanticClass::VEGETATION;
    for (std::size_t i = 0; i < s.surface.ndsm.data.size(); ++i) s.surface.ndsm.data[i] = 12.0F;   // Tree-height nDSM
    const VegetationCover cover = s.run(ScenePresentation::FLAT_URBAN);
    ASSERT_TRUE(cover.enabled) << cover.disabledReason;
    EXPECT_EQ(cover.mode, VegetationCoverMode::GARDEN);
    ASSERT_GT(cover.shrubs.size(), 100U);
    cv::Mat underShrubs = cv::Mat::zeros(kCover, kCover, CV_8U);
    for (const CoverShrub& shrub : cover.shrubs)
    {
        EXPECT_GE(shrub.pixelColumn, 40.0);
        EXPECT_LE(shrub.pixelColumn, 160.0);
        EXPECT_GE(shrub.pixelRow, 40.0);
        EXPECT_LE(shrub.pixelRow, 160.0);
        EXPECT_LE(shrub.metricHeight, 1.5F);                       // Shrubs, not 12 m trees
        EXPECT_NEAR(shrub.scale[1], shrub.metricHeight * 2.25F, 1e-4F);
        EXPECT_FLOAT_EQ(shrub.translation[1], 0.0F);              // flat_urban ground
        cv::circle(underShrubs, {static_cast<int>(shrub.pixelColumn), static_cast<int>(shrub.pixelRow)},
                   static_cast<int>(std::lround(shrub.radiusMetres / 0.5)), 255, cv::FILLED);
    }
    // Lawn: a clear share of the garden is open ground between shrub beds.
    const double lawn = 1.0 - cv::countNonZero(underShrubs(cv::Rect(40, 40, 120, 120))) / (120.0 * 120.0);
    EXPECT_GT(lawn, 0.2) << lawn;
    EXPECT_LT(lawn, 0.7) << lawn;
}

TEST(VegetationCoverTest, CoarseImageryGetsNoShrubCover)
{
    CoverScene s;
    s.metadata = makeProjectedMetadata(kCover, kCover, 10.0, -10.0);
    s.surface.spatialMetadata = s.metadata;
    const VegetationCover cover = s.run();
    EXPECT_FALSE(cover.enabled);
    EXPECT_NE(cover.disabledReason.find("coarse"), std::string::npos);
}
