// Automatic urban-versus-natural presentation, checked in the packaged GLB.
//
// A natural, high-relief scene without accepted buildings must render as
// textured metric terrain (DTM elevations at 1:1, skirt, aligned optical
// texture), never as a flat plate. Operator overrides change only the render.

#include "BuildingReconstruction/Sat2Lod2Importer.h"
#include "BuildingReconstructionTestSupport.h"
#include "GlbTestSupport.h"
#include "MeshMapping/BuildingMeshConfig.h"
#include "MeshMapping/SceneMeshService.h"
#include "MeshMapping/ScenePresentationPolicy.h"
#include "MeshMapping/ScenePresentationSelector.h"
#include "Vegetation/VegetationCanopyBuilder.h"
#include "Vegetation/VegetationClassifier.h"
#include "Vegetation/VegetationExtractor.h"
#include "Vegetation/VegetationHeightSampler.h"
#include "Vegetation/VegetationTreeInstancer.h"
#include "Vegetation/DenseForestProxyGenerator.h"
#include "MeshMapping/TerrainSurfaceSampler.h"
#include "MeshMapping/GeoTransformMapping.h"
#include "MeshMapping/LocalFrameTransformer.h"
#include "tiny_gltf.h"

#include <gtest/gtest.h>
#include <json/json.h>
#include <opencv2/imgcodecs.hpp>

#include <algorithm>
#include <chrono>
#include <set>
#include <cstring>
#include <iostream>
#include <cmath>
#include <tuple>
#include <utility>

using namespace depthwizard::test;

namespace
{
constexpr int kWidth = 90;
constexpr int kHeight = 60;
// Draco: 16-bit positions over a ~1 km box (~1.6 cm), 12-bit UVs.
constexpr double kElevationTolerance = 0.05;
constexpr double kUvTolerance = 1.0 / 4096.0;

// Rotated (~16 degrees), non-square 10 m x 12 m pixels, so a transposed
// term, swapped u/v or V flip cannot pass.
SpatialMetadata rotatedMetadata()
{
    SpatialMetadata metadata = makeProjectedMetadata(kWidth, kHeight, 10.0, -12.0);
    metadata.geoTransform = {8110000.0, 9.6, 3.36, 4120000.0, 2.8, -11.52};
    return metadata;
}

std::pair<double, double> pixelEdgeOf(const SpatialMetadata& metadata, double easting, double northing)
{
    const auto& gt = metadata.geoTransform;
    const double dx = easting - gt[0];
    const double dy = northing - gt[3];
    const double det = gt[1] * gt[5] - gt[2] * gt[4];
    return {(dx * gt[5] - dy * gt[2]) / det, (dy * gt[1] - dx * gt[4]) / det};
}

// A valley side with a central peak: ~390 m of relief.
float dtmAt(int column, int row)
{
    const double dx = column - 45.0, dy = row - 30.0;
    return static_cast<float>(1200.0 + 3.0 * column + 2.0 * row + 150.0 * std::exp(-(dx * dx + dy * dy) / 288.0));
}

// Every texel names its own pixel: red = 2 * column, green = 3 * row.
cv::Mat codedOpticalImage()
{
    cv::Mat image(kHeight, kWidth, CV_8UC3);
    for (int row = 0; row < kHeight; ++row)
        for (int column = 0; column < kWidth; ++column)
            image.at<cv::Vec3b>(row, column) =
                cv::Vec3b(128, static_cast<uint8_t>(3 * row), static_cast<uint8_t>(2 * column)); // BGR
    return image;
}

struct NaturalScene
{
    SpatialMetadata metadata = rotatedMetadata();
    SemanticScene semantics = makeSemanticScene(kWidth, kHeight, SemanticClass::VEGETATION);
    GeoreferencedSurfaceBundle surface = makeSurface(kWidth, kHeight, 0.0F, 0.0F);
    SceneInput scene;
    BuildingCollection buildings;
    float dtmMin{1e9F};
    float dtmMax{-1e9F};

    NaturalScene()
    {
        surface.spatialMetadata = metadata;
        semantics.vegetationProbability = makeConstantGrid(kWidth, kHeight, 0.8F);
        for (int row = 0; row < kHeight; ++row)
            for (int column = 0; column < kWidth; ++column)
            {
                const std::size_t index = static_cast<std::size_t>(row) * kWidth + column;
                surface.dtm.data[index] = dtmAt(column, row);
                // Forest canopy: the terrain must follow the DTM, not the DSM.
                surface.ndsm.data[index] = 12.0F;
                surface.dsm.data[index] = surface.dtm.data[index] + surface.ndsm.data[index];
                dtmMin = std::min(dtmMin, surface.dtm.data[index]);
                dtmMax = std::max(dtmMax, surface.dtm.data[index]);
            }
        scene.width = kWidth;
        scene.height = kHeight;
        scene.spatialMetadata = metadata;
        scene.textureMimeType = "image/png";
        EXPECT_TRUE(cv::imencode(".png", codedOpticalImage(), scene.rgbTextureBytes));
    }

    ScenePresentation resolve(ScenePresentationPolicy policy) const
    {
        return resolveScenePresentation(policy, ScenePresentationSelector::select(semantics, surface, buildings));
    }

    tinygltf::Model render(ScenePresentation presentation) const
    {
        MeshBuildConfig config;
        config.presentation = presentation;
        config.presentationStyle = depthwizard::PresentationStyle::ORTHOPHOTO_REALISTIC;
        const GlbBuildResult glb = SceneMeshService::generateGlb(scene, surface, buildings, metadata, config);
        EXPECT_FALSE(glb.compressedGlbByteBuffer.empty()) << ::testing::PrintToString(glb.geometryWarnings);
        return loadGlb(glb.compressedGlbByteBuffer);
    }
};

struct DecodedPrimitive
{
    std::vector<float> positions;
    std::vector<float> uvs;
    std::size_t size() const { return positions.size() / 3; }
    float y(std::size_t vertex) const { return positions[vertex * 3 + 1]; }
    std::pair<float, float> yRange() const
    {
        float low = 1e9F, high = -1e9F;
        for (std::size_t vertex = 0; vertex < size(); ++vertex)
        {
            low = std::min(low, y(vertex));
            high = std::max(high, y(vertex));
        }
        return {low, high};
    }
};

DecodedPrimitive decode(const tinygltf::Model& model, const tinygltf::Primitive& primitive)
{
    return {decodeDracoAttribute(model, primitive, "POSITION"), decodeDracoAttribute(model, primitive, "TEXCOORD_0")};
}

std::string semanticOf(const tinygltf::Model& model, const tinygltf::Primitive& primitive)
{
    const tinygltf::Value& extras = model.materials[primitive.material].extras;
    return extras.Has("textureSemantic") ? extras.Get("textureSemantic").Get<std::string>() : std::string();
}

std::vector<uint8_t> imageBytes(const tinygltf::Model& model, int texture)
{
    const tinygltf::BufferView& view = model.bufferViews[model.images[model.textures[texture].source].bufferView];
    const auto begin = model.buffers[view.buffer].data.begin() + static_cast<std::ptrdiff_t>(view.byteOffset);
    return {begin, begin + static_cast<std::ptrdiff_t>(view.byteLength)};
}

double extra(const tinygltf::Model& model, const char* name)
{
    return model.asset.extras.Get(name).GetNumberAsDouble();
}

} // namespace

TEST(NaturalTerrainPresentationTest, TerrainOnlySceneRendersTexturedMetricTerrainWithSkirt)
{
    const NaturalScene s;
    ASSERT_GT(s.dtmMax - s.dtmMin, 100.0F);

    // AUTO resolves the natural scene to METRIC through the selector alone.
    const ScenePresentationDecision decision =
        ScenePresentationSelector::select(s.semantics, s.surface, s.buildings);
    EXPECT_EQ(decision.reason, "No accepted buildings; retaining metric terrain and skirts.");
    const ScenePresentation presentation = resolveScenePresentation(ScenePresentationPolicy::AUTO, decision);
    ASSERT_EQ(presentation, ScenePresentation::METRIC);

    const tinygltf::Model model = s.render(presentation);
    EXPECT_EQ(model.asset.extras.Get("presentationMode").Get<std::string>(), "metric");
    EXPECT_EQ(model.asset.extras.Get("presentationStyle").Get<std::string>(), "orthophoto");
    EXPECT_EQ(model.asset.extras.Get("buildingCount").GetNumberAsInt(), 0);

    // Terrain only: no roof, wall or edge primitives.
    ASSERT_EQ(model.meshes.at(0).primitives.size(), 1U);
    EXPECT_EQ(primitiveWithMaterial(model, "Building_"), nullptr);
    const tinygltf::Primitive* terrain = primitiveWithMaterial(model, "Terrain_Repaired_Optical");
    ASSERT_NE(terrain, nullptr);
    EXPECT_EQ(terrain->mode, TINYGLTF_MODE_TRIANGLES);
    EXPECT_TRUE(terrain->attributes.contains("TEXCOORD_0"));
    EXPECT_FALSE(terrain->attributes.contains("COLOR_0"));
    EXPECT_EQ(semanticOf(model, *terrain), "OPTICAL_GROUND_REPAIRED");

    // With nothing to conceal, the repaired ground is the optical image itself.
    const int texture = model.materials[terrain->material].pbrMetallicRoughness.baseColorTexture.index;
    const cv::Mat ground = cv::imdecode(imageBytes(model, texture), cv::IMREAD_COLOR);
    ASSERT_EQ(ground.cols, kWidth);
    ASSERT_EQ(ground.rows, kHeight);
    EXPECT_EQ(cv::norm(ground, codedOpticalImage(), cv::NORM_INF), 0.0);

    const DecodedPrimitive mesh = decode(model, *terrain);
    ASSERT_EQ(mesh.uvs.size(), mesh.size() * 2);
    const double origin = extra(model, "elevationOrigin");
    const double originX = extra(model, "projectedOriginX");
    const double originY = extra(model, "projectedOriginY");
    const auto [lowestY, highestY] = mesh.yRange();

    // Skirt: base vertices sit skirtDepth below the lowest terrain vertex.
    const float skirtDepth = TerrainMeshConfig().skirtDepth;
    const float expectedBase = static_cast<float>(s.dtmMin - origin) - skirtDepth;
    EXPECT_NEAR(lowestY, expectedBase, kElevationTolerance);
    std::size_t skirtVertices = 0;
    float topLow = 1e9F, topHigh = -1e9F;
    for (std::size_t vertex = 0; vertex < mesh.size(); ++vertex)
    {
        if (mesh.y(vertex) < expectedBase + 0.5F * skirtDepth)
        {
            ++skirtVertices;
            continue;
        }
        topLow = std::min(topLow, mesh.y(vertex));
        topHigh = std::max(topHigh, mesh.y(vertex));
    }
    EXPECT_GE(skirtVertices, static_cast<std::size_t>(2 * (kWidth + kHeight)));

    // Top surface: true 1:1 metric DTM relief, with no exaggeration and no
    // building height scale.
    EXPECT_GT(topHigh - topLow, 100.0F);
    EXPECT_NEAR(topHigh - topLow, s.dtmMax - s.dtmMin, kElevationTolerance);
    EXPECT_NEAR(topLow + origin, s.dtmMin, kElevationTolerance);
    EXPECT_NEAR(topHigh + origin, s.dtmMax, kElevationTolerance);

    // Georeferencing and texture alignment: every top vertex carries the
    // inverse-affine UV of its own position, and the DTM sample under that UV
    // is its elevation (the DTM, not the canopy DSM).
    std::size_t checked = 0;
    for (std::size_t vertex = 0; vertex < mesh.size(); ++vertex)
    {
        if (mesh.y(vertex) < expectedBase + 0.5F * skirtDepth) continue;
        const double easting = mesh.positions[vertex * 3] + originX;
        const double northing = -mesh.positions[vertex * 3 + 2] + originY;
        const auto [column, row] = pixelEdgeOf(s.metadata, easting, northing);
        const float u = mesh.uvs[vertex * 2], v = mesh.uvs[vertex * 2 + 1];
        ASSERT_NEAR(u, column / kWidth, kUvTolerance) << "vertex " << vertex;
        ASSERT_NEAR(v, row / kHeight, kUvTolerance) << "vertex " << vertex;
        const int pixelColumn = std::clamp(static_cast<int>(std::floor(u * kWidth)), 0, kWidth - 1);
        const int pixelRow = std::clamp(static_cast<int>(std::floor(v * kHeight)), 0, kHeight - 1);
        ASSERT_NEAR(mesh.y(vertex) + origin, dtmAt(pixelColumn, pixelRow), kElevationTolerance)
            << "vertex " << vertex << " at pixel (" << pixelColumn << ", " << pixelRow << ")";
        // The texel under that UV is the same pixel.
        const cv::Vec3b texel = ground.at<cv::Vec3b>(pixelRow, pixelColumn);
        ASSERT_EQ(texel[2] / 2, pixelColumn);
        ASSERT_EQ(texel[1] / 3, pixelRow);
        ++checked;
    }
    EXPECT_GE(checked, static_cast<std::size_t>(kWidth * kHeight));
}

TEST(NaturalTerrainPresentationTest, OneSurvivingBuildingDoesNotFlattenMountainTerrain)
{
    NaturalScene s;
    // SAT2LoD2 returns a single hut on the slope (pixel-centre rectangle).
    fillRectangle(s.semantics.finalClassMap, 40, 25, 53, 36, SemanticClass::BUILDING);
    fillRectangle(s.semantics.buildingProbability, 40, 25, 53, 36, 0.9F);
    fillRectangle(s.semantics.vegetationProbability, 40, 25, 53, 36, 0.0F);
    RasterGrid<float> ndsm = makeConstantGrid(kWidth, kHeight, 0.0F);
    fillRectangle(ndsm, 40, 25, 53, 36, 9.0F);
    s.surface.ndsm = ndsm;
    for (std::size_t index = 0; index < s.surface.dsm.data.size(); ++index)
        s.surface.dsm.data[index] = s.surface.dtm.data[index] + ndsm.data[index];

    Json::Value ring(Json::arrayValue);
    for (const auto& [column, row] : std::vector<std::pair<int, int>>{{40, 25}, {52, 25}, {52, 35}, {40, 35}})
    {
        Json::Value point(Json::arrayValue);
        point.append(column);
        point.append(row);
        ring.append(point);
    }
    Json::Value block;
    block["corners"] = ring;
    block["roof_type"] = "flat";
    block["eave"] = 9.0;
    block["ridge"] = 9.0;
    Json::Value segment;
    segment["id"] = 0;
    segment["footprint"] = ring;
    segment["blocks"].append(block);
    segment["irregular"] = false;
    Json::Value document;
    document["schema"] = "depthwizard.sat2lod2.v1";
    document["raster_width"] = kWidth;
    document["raster_height"] = kHeight;
    document["segments"].append(segment);
    const BuildingReconstructionConfig config;
    s.buildings = Sat2Lod2Importer::import(document, s.semantics, s.surface, s.metadata, config, ndsm).buildings;
    ASSERT_EQ(s.buildings.buildings.size(), 1U);
    const BuildingInstance& hut = s.buildings.buildings.front();
    // The nDSM height stays authoritative (render-scaled as everywhere).
    EXPECT_NEAR(hut.heightAboveGround, 9.0F * config.heightScaleMultiplier, 1e-3);

    const ScenePresentationDecision decision = ScenePresentationSelector::select(s.semantics, s.surface, s.buildings);
    // Forest or localized-settlement reasons are both natural-terrain reasons.
    EXPECT_EQ(decision.reason.find("Distributed"), std::string::npos) << decision.reason;
    const ScenePresentation presentation = resolveScenePresentation(ScenePresentationPolicy::AUTO, decision);
    ASSERT_EQ(presentation, ScenePresentation::METRIC);

    const tinygltf::Model model = s.render(presentation);
    EXPECT_EQ(model.asset.extras.Get("presentationMode").Get<std::string>(), "metric");
    EXPECT_EQ(model.asset.extras.Get("buildingCount").GetNumberAsInt(), 1);
    const double origin = extra(model, "elevationOrigin");
    const auto* terrain = primitiveWithMaterial(model, "Terrain_Repaired_Optical");
    const auto* roof = primitiveWithMaterial(model, "Building_Roof_Optical");
    const auto* wall = primitiveWithMaterial(model, "Building_Wall_Facade");
    ASSERT_TRUE(terrain && roof && wall);

    // Terrain still follows the DTM, skirt included.
    const auto [terrainLow, terrainHigh] = decode(model, *terrain).yRange();
    EXPECT_NEAR(terrainLow + origin, s.dtmMin - TerrainMeshConfig().skirtDepth, kElevationTolerance);
    EXPECT_NEAR(terrainHigh + origin, s.dtmMax, kElevationTolerance);

    // The hut sits on its own terrain: roof at its absolute roof elevation,
    // wall bases at its per-vertex terrain elevation minus the embed depth.
    const auto [roofLow, roofHigh] = decode(model, *roof).yRange();
    EXPECT_NEAR(roofHigh + origin, hut.roofElevation, kElevationTolerance);
    ASSERT_EQ(hut.baseElevationPerVertex.size(), hut.projectedFootprint.outerRing.size());
    const auto [baseLow, baseHigh] =
        std::minmax_element(hut.baseElevationPerVertex.begin(), hut.baseElevationPerVertex.end());
    const float embed = BuildingMeshConfig().wallTerrainEmbedDepthMetres;
    const auto [wallLow, wallHigh] = decode(model, *wall).yRange();
    EXPECT_GE(wallLow + origin, *baseLow - embed - kElevationTolerance);
    EXPECT_LE(wallLow + origin, *baseHigh - embed + kElevationTolerance);
    EXPECT_GT(wallLow + origin, s.dtmMin + 50.0); // Not dropped to a flat datum
}

TEST(NaturalTerrainPresentationTest, ForcedFlatUrbanDeliberatelyFlattensNaturalScene)
{
    const NaturalScene s;
    const ScenePresentation presentation = s.resolve(ScenePresentationPolicy::FORCE_FLAT_URBAN);
    ASSERT_EQ(presentation, ScenePresentation::FLAT_URBAN);
    const tinygltf::Model model = s.render(presentation);
    EXPECT_EQ(model.asset.extras.Get("presentationMode").Get<std::string>(), "flat_urban");
    const DecodedPrimitive mesh = decode(model, *primitiveWithMaterial(model, "Terrain_Repaired_Optical"));
    const auto [low, high] = mesh.yRange();
    EXPECT_EQ(low, 0.0F);
    EXPECT_EQ(high, 0.0F);          // The flat plate: only by explicit request
    EXPECT_EQ(mesh.size(), static_cast<std::size_t>(kWidth * kHeight)); // No skirt vertices
}

TEST(NaturalTerrainPresentationTest, PresentationOverridesNeverTouchRastersOrPlacement)
{
    const NaturalScene s;
    const auto dtm = s.surface.dtm.data;
    const auto dsm = s.surface.dsm.data;
    const auto ndsm = s.surface.ndsm.data;
    const auto valid = s.surface.validMask.data;
    const auto optical = s.scene.rgbTextureBytes;

    // Top-surface (x, z, u, v) of each policy's terrain, order-independent.
    const auto placement = [&](ScenePresentationPolicy policy)
    {
        const tinygltf::Model model = s.render(s.resolve(policy));
        const DecodedPrimitive mesh = decode(model, *primitiveWithMaterial(model, "Terrain_Repaired_Optical"));
        const float top = policy == ScenePresentationPolicy::FORCE_FLAT_URBAN ? -1.0F : mesh.yRange().first + 1.0F;
        std::vector<std::tuple<long, long, long, long>> points;
        for (std::size_t vertex = 0; vertex < mesh.size(); ++vertex)
            if (mesh.y(vertex) > top)
                points.emplace_back(std::lround(mesh.positions[vertex * 3] * 10), std::lround(mesh.positions[vertex * 3 + 2] * 10),
                                    std::lround(mesh.uvs[vertex * 2] * 4096), std::lround(mesh.uvs[vertex * 2 + 1] * 4096));
        std::sort(points.begin(), points.end());
        return points;
    };
    const auto automatic = placement(ScenePresentationPolicy::AUTO);
    const auto flat = placement(ScenePresentationPolicy::FORCE_FLAT_URBAN);
    const auto metric = placement(ScenePresentationPolicy::FORCE_METRIC);
    ASSERT_EQ(automatic.size(), static_cast<std::size_t>(kWidth * kHeight));
    EXPECT_EQ(automatic, metric);
    // Flattening changes Y only: XY placement and UVs agree to 10 cm / 1 UV step.
    ASSERT_EQ(flat.size(), automatic.size());
    for (std::size_t index = 0; index < flat.size(); ++index)
    {
        EXPECT_NEAR(std::get<0>(flat[index]), std::get<0>(automatic[index]), 1);
        EXPECT_NEAR(std::get<1>(flat[index]), std::get<1>(automatic[index]), 1);
        EXPECT_NEAR(std::get<2>(flat[index]), std::get<2>(automatic[index]), 1);
        EXPECT_NEAR(std::get<3>(flat[index]), std::get<3>(automatic[index]), 1);
    }

    // Exported rasters come from these grids: value-identical under every policy.
    EXPECT_EQ(s.surface.dtm.data, dtm);
    EXPECT_EQ(s.surface.dsm.data, dsm);
    EXPECT_EQ(s.surface.ndsm.data, ndsm);
    EXPECT_EQ(s.surface.validMask.data, valid);
    EXPECT_EQ(s.scene.rgbTextureBytes, optical);
}

// --- Stage 3: the canopy overlay on metric mountain terrain -----------------

TEST(NaturalTerrainPresentationTest, MetricCanopyFollowsTheTerrainAndSamplesItsOwnPixels)
{
    // Forest everywhere (12 m nDSM, VEGETATION class); 10-12 m pixels are too
    // coarse for crowns, so all of it is canopy.
    const NaturalScene s;
    VegetationConfig config;
    config.mode = VegetationMode::ON;
    const VegetationMask mask = VegetationExtractor::extract(
        s.semantics, s.surface, makeConstantGrid<uint8_t>(kWidth, kHeight, uint8_t{0}), s.metadata, config);
    const VegetationHeights heights = VegetationHeightSampler::sample(mask, s.surface, config);
    const VegetationClassification classes = VegetationClassifier::classify(mask, config);
    EXPECT_FALSE(classes.stats.individualTreesResolvable);
    EXPECT_EQ(classes.stats.isolatedPixels, 0U);
    VegetationCanopyMesh canopy;
    VegetationCanopyInput input;
    input.mask = &mask;
    input.classification = &classes;
    input.heights = &heights;
    input.config = config;
    input.buildingDisplayHeightScale = 2.25F; // Ignored in metric
    input.output = &canopy;

    MeshBuildConfig meshConfig;
    meshConfig.presentation = s.resolve(ScenePresentationPolicy::AUTO);
    ASSERT_EQ(meshConfig.presentation, ScenePresentation::METRIC);
    meshConfig.presentationStyle = depthwizard::PresentationStyle::ORTHOPHOTO_REALISTIC;
    const GlbBuildResult plainGlb = SceneMeshService::generateGlb(s.scene, s.surface, s.buildings, s.metadata, meshConfig);
    const GlbBuildResult glb =
        SceneMeshService::generateGlb(s.scene, s.surface, s.buildings, s.metadata, meshConfig, &input);
    ASSERT_FALSE(canopy.empty()) << canopy.stats.skippedReason;
    EXPECT_EQ(canopy.stats.displayHeightScale, 1.0F);
    const tinygltf::Model plain = loadGlb(plainGlb.compressedGlbByteBuffer);
    const tinygltf::Model model = loadGlb(glb.compressedGlbByteBuffer);

    // Terrain (with its skirt) is untouched.
    const auto* terrain = primitiveWithMaterial(model, "Terrain_Repaired_Optical");
    const auto* plainTerrain = primitiveWithMaterial(plain, "Terrain_Repaired_Optical");
    ASSERT_TRUE(terrain && plainTerrain);
    for (const char* attribute : {"POSITION", "NORMAL", "TEXCOORD_0"})
        EXPECT_EQ(decodeDracoAttribute(model, *terrain, attribute), decodeDracoAttribute(plain, *plainTerrain, attribute));

    ASSERT_EQ(model.nodes.size(), 2U);
    ASSERT_EQ(model.nodes[1].name, "VEGETATION_CANOPY");
    EXPECT_EQ(model.nodes[1].extras.Get("presentationMode").Get<std::string>(), "metric");
    const tinygltf::Primitive& primitive = model.meshes[static_cast<std::size_t>(model.nodes[1].mesh)].primitives.at(0);
    const std::vector<float> positions = decodeDracoAttribute(model, primitive, "POSITION");
    const std::vector<float> uvs = decodeDracoAttribute(model, primitive, "TEXCOORD_0");
    ASSERT_EQ(uvs.size(), positions.size() / 3 * 2);
    const int texture = model.materials[static_cast<std::size_t>(primitive.material)].pbrMetallicRoughness.baseColorTexture.index;
    const cv::Mat image = cv::imdecode(imageBytes(model, texture), cv::IMREAD_COLOR);
    ASSERT_EQ(image.cols, kWidth);
    const double origin = extra(model, "elevationOrigin");
    std::size_t checked = 0;
    for (std::size_t v = 0; v < positions.size() / 3; ++v)
    {
        const double easting = positions[v * 3] + extra(model, "projectedOriginX");
        const double northing = -positions[v * 3 + 2] + extra(model, "projectedOriginY");
        const auto [column, row] = pixelEdgeOf(s.metadata, easting, northing);
        // UV = the vertex's own pixel-edge coordinate / size (no swap, no flip).
        ASSERT_NEAR(uvs[v * 2], column / kWidth, kUvTolerance);
        ASSERT_NEAR(uvs[v * 2 + 1], row / kHeight, kUvTolerance);
        // The texel under that UV is the pixel under the vertex.
        const int pixelColumn = std::clamp(static_cast<int>(std::floor(uvs[v * 2] * kWidth)), 0, kWidth - 1);
        const int pixelRow = std::clamp(static_cast<int>(std::floor(uvs[v * 2 + 1] * kHeight)), 0, kHeight - 1);
        const cv::Vec3b texel = image.at<cv::Vec3b>(pixelRow, pixelColumn);
        ASSERT_EQ(texel[2] / 2, pixelColumn);
        ASSERT_EQ(texel[1] / 3, pixelRow);
        // Interior nodes coincide with terrain nodes: top = DTM + nDSM (12 m), 1:1.
        if (pixelColumn > 0 && pixelColumn < kWidth - 1 && pixelRow > 0 && pixelRow < kHeight - 1)
        {
            ASSERT_NEAR(positions[v * 3 + 1] + origin, dtmAt(pixelColumn, pixelRow) + 12.0F, kElevationTolerance)
                << "vertex " << v;
            ++checked;
        }
    }
    EXPECT_GT(checked, 2000U);
}

// --- Stage 5: 3,000 instanced trees stay bounded ----------------------------

TEST(NaturalTerrainPresentationTest, ThreeThousandTreesStayBoundedInNodesSizeAndTime)
{
    const NaturalScene s;
    VegetationTreeCandidates trees;
    trees.enabled = true;
    const LocalSceneFrame frame = LocalFrameTransformer::create(s.metadata, s.surface);
    for (uint32_t k = 1; k <= 3000; ++k)
    {
        TreeCandidate c;
        c.id = k;
        c.category = k % 4 == 0 ? TreeCandidateCategory::DENSE_CANOPY_CROWN : TreeCandidateCategory::ISOLATED_TREE;
        const double column = 1.0 + (k * 37 % 880) / 10.0, row = 1.0 + (k * 53 % 580) / 10.0;
        const LocalPoint local = depthwizard::geo::pixelEdgeToLocal(s.metadata, frame, column, row);
        c.pixelColumn = column;
        c.pixelRow = row;
        c.worldX = local.x;
        c.worldZ = local.z;
        c.baseY = dtmAt(static_cast<int>(column), static_cast<int>(row)) - static_cast<float>(frame.elevationOrigin);
        c.metricHeight = 3.0F + (k % 17);
        c.displayScale = 1.0F;
        c.displayHeight = c.metricHeight;
        c.topY = c.baseY + c.displayHeight;
        c.crownRadiusMetres = 1.5F + (k % 11) * 0.4F;
        c.vegetationSupport = 0.6F + (k % 5) * 0.08F;
        c.compactness = 0.4F + (k % 6) * 0.1F;
        trees.candidates.push_back(c);
    }
    VegetationConfig config;
    config.mode = VegetationMode::ON;
    config.canopy = false;
    VegetationTreeInstances instances;
    VegetationCanopyInput input;
    input.config = config;
    input.treeCandidates = &trees;
    input.treeOutput = &instances;
    MeshBuildConfig meshConfig;
    meshConfig.presentation = ScenePresentation::METRIC;
    meshConfig.presentationStyle = depthwizard::PresentationStyle::ORTHOPHOTO_REALISTIC;
    const GlbBuildResult plain = SceneMeshService::generateGlb(s.scene, s.surface, s.buildings, s.metadata, meshConfig);
    const auto started = std::chrono::steady_clock::now();
    const GlbBuildResult glb = SceneMeshService::generateGlb(s.scene, s.surface, s.buildings, s.metadata, meshConfig, &input);
    const double seconds = std::chrono::duration<double>(std::chrono::steady_clock::now() - started).count();
    ASSERT_FALSE(glb.compressedGlbByteBuffer.empty());
    const tinygltf::Model model = loadGlb(glb.compressedGlbByteBuffer);
    const std::size_t treeNodes = model.nodes.size() - 1;
    const std::size_t added = glb.compressedGlbByteBuffer.size() - plain.compressedGlbByteBuffer.size();
    std::size_t near = 0;
    for (const tinygltf::Node& node : model.nodes)
        if (node.extras.Has("vegetationLod") && node.extras.Get("vegetationLod").Get<std::string>() == "NEAR")
            near += static_cast<std::size_t>(node.extras.Get("instanceCount").GetNumberAsInt());
    EXPECT_EQ(near, 3000U);                                  // Every tree once per level
    EXPECT_EQ(instances.instances.size(), 3000U);
    EXPECT_LE(treeNodes, instances.chunks * kTreeVariantCount * 3);
    EXPECT_LE(treeNodes, 400U);                              // Not one node (or draw call) per tree

    // Size, by what it scales with. Instance data is stored once per tree
    // (13 floats: translation, rotation, scale, tint), shared by the levels
    // of detail of its batch; prototype geometry is a fixed cost; JSON grows
    // with the bounded node count only.
    std::set<int> instanceAccessors, geometryAccessors;
    for (const tinygltf::Node& node : model.nodes)
    {
        if (!node.extensions.count("EXT_mesh_gpu_instancing")) continue;
        const tinygltf::Value attributes = node.extensions.at("EXT_mesh_gpu_instancing").Get("attributes");
        for (const std::string& key : attributes.Keys()) instanceAccessors.insert(attributes.Get(key).GetNumberAsInt());
        for (const tinygltf::Primitive& primitive : model.meshes[static_cast<std::size_t>(node.mesh)].primitives)
        {
            for (const auto& [name, accessor] : primitive.attributes) geometryAccessors.insert(accessor);
            geometryAccessors.insert(primitive.indices);
        }
    }
    const auto accessorBytes = [&model](const std::set<int>& accessors) {
        std::size_t bytes = 0;
        for (int a : accessors) bytes += model.bufferViews[static_cast<std::size_t>(model.accessors[a].bufferView)].byteLength;
        return bytes;
    };
    const std::size_t instanceBytes = accessorBytes(instanceAccessors), geometryBytes = accessorBytes(geometryAccessors);
    const auto jsonBytes = [](const std::vector<uint8_t>& g) {
        uint32_t length = 0;
        std::memcpy(&length, g.data() + 12, 4);
        return static_cast<std::size_t>(length);
    };
    const std::size_t addedJson = jsonBytes(glb.compressedGlbByteBuffer) - jsonBytes(plain.compressedGlbByteBuffer);
    EXPECT_EQ(instanceBytes, 3000U * 13U * sizeof(float));   // Once per tree, not per level
    EXPECT_LT(geometryBytes, 200000U);                       // All prototypes, independent of tree count
    EXPECT_LT(addedJson, treeNodes * 1200U);                 // Per-node metadata only
    EXPECT_LT(added, 1000000U);                              // < 1 MB for 3,000 trees
    EXPECT_LT(seconds, 5.0);
    std::cout << "[stress] 3000 trees: chunks=" << instances.chunks << " nodes=" << treeNodes
              << " added_bytes=" << added << " instance_bytes=" << instanceBytes
              << " prototype_bytes=" << geometryBytes << " added_json_bytes=" << addedJson
              << " build_s=" << seconds << "\n";
}

// --- Stage 5A: forest-patch proxies on a metric forest ----------------------

namespace
{
// 600 m x 600 m of dense forest at 5 m on a gentle 5 % slope (2.9 degrees).
struct GentleForest
{
    static constexpr int kSide = 120;
    SpatialMetadata metadata = makeProjectedMetadata(kSide, kSide, 5.0, -5.0);
    GeoreferencedSurfaceBundle surface = makeSurface(kSide, kSide, 0.0F, 0.0F);
    SceneInput scene;
    BuildingCollection buildings;
    VegetationMask mask;
    VegetationClassification classes;
    VegetationHeights heights;

    GentleForest()
    {
        surface.spatialMetadata = metadata;
        mask.barrierMask = makeConstantGrid<uint8_t>(kSide, kSide, uint8_t{0});
        classes.classes = makeConstantGrid<uint8_t>(kSide, kSide, static_cast<uint8_t>(VegetationClass::DENSE));
        heights.metricHeight = makeConstantGrid(kSide, kSide, 15.0F);
        for (int y = 0; y < kSide; ++y)
            for (int x = 0; x < kSide; ++x)
            {
                const std::size_t i = static_cast<std::size_t>(y) * kSide + x;
                surface.dtm.data[i] = static_cast<float>(500.0 + 0.05 * 5.0 * x);
                surface.ndsm.data[i] = 15.0F;
                surface.dsm.data[i] = surface.dtm.data[i] + 15.0F;
            }
        scene.width = kSide;
        scene.height = kSide;
        scene.spatialMetadata = metadata;
        scene.textureMimeType = "image/png";
        EXPECT_TRUE(cv::imencode(".png", cv::Mat(kSide, kSide, CV_8UC3, cv::Scalar(40, 90, 50)), scene.rgbTextureBytes));
    }

    GlbBuildResult render(const VegetationCanopyInput* vegetation) const
    {
        MeshBuildConfig config;
        config.presentation = ScenePresentation::METRIC;
        config.presentationStyle = depthwizard::PresentationStyle::ORTHOPHOTO_REALISTIC;
        return SceneMeshService::generateGlb(scene, surface, buildings, metadata, config, vegetation);
    }

    VegetationCanopyInput input(bool forestProxies, DenseForestProxies* output) const
    {
        VegetationCanopyInput in;
        in.mask = &mask;
        in.classification = &classes;
        in.heights = &heights;
        in.config.mode = VegetationMode::ON;
        in.config.canopy = false;
        in.config.assetMode = VegetationAssetMode::EXTERNAL;
        in.config.forestProxies = forestProxies;
        in.forestOutput = output;
        return in;
    }
};
} // namespace

TEST(NaturalTerrainPresentationTest, ForestPatchesAreInstancedOnTheTerrainAfterAnUnchangedScene)
{
    const GentleForest f;
    const auto plain = f.render(nullptr).compressedGlbByteBuffer;
    DenseForestProxies forest;
    const VegetationCanopyInput input = f.input(true, &forest);
    const GlbBuildResult glb = f.render(&input);
    EXPECT_TRUE(glb.geometryWarnings.empty()) << ::testing::PrintToString(glb.geometryWarnings);
    ASSERT_TRUE(forest.enabled) << forest.disabledReason;
    ASSERT_FALSE(forest.empty());
    const tinygltf::Model a = loadGlb(plain);
    const tinygltf::Model b = loadGlb(glb.compressedGlbByteBuffer);

    // Terrain and every base byte unchanged: the plain model is a prefix.
    ASSERT_LE(a.buffers[0].data.size(), b.buffers[0].data.size());
    EXPECT_TRUE(std::equal(a.buffers[0].data.begin(), a.buffers[0].data.end(), b.buffers[0].data.begin()));
    ASSERT_EQ(a.nodes.size(), 1U);
    EXPECT_TRUE(a.nodes[0] == b.nodes[0]);
    EXPECT_TRUE(std::equal(a.accessors.begin(), a.accessors.end(), b.accessors.begin()));
    EXPECT_TRUE(std::equal(a.materials.begin(), a.materials.end(), b.materials.begin()));

    // One shared textured patch; NEAR and MEDIUM batches share instance data.
    std::map<std::string, std::vector<const tinygltf::Node*>> byBatch;
    std::set<int> meshes;
    std::size_t instances = 0;
    for (std::size_t n = 1; n < b.nodes.size(); ++n)
    {
        const tinygltf::Node& node = b.nodes[n];
        ASSERT_EQ(node.name.rfind("VEGETATION_FOREST_", 0), 0U) << node.name;
        EXPECT_EQ(node.extras.Get("geometrySemantic").Get<std::string>(), "VEGETATION_FOREST_PROXY");
        EXPECT_EQ(node.extras.Get("positionSource").Get<std::string>(), "DENSE_CANOPY_MASK");
        EXPECT_EQ(node.extras.Get("heightSource").Get<std::string>(), "NDSM_ENVELOPE");
        EXPECT_EQ(node.extras.Get("assetSource").Get<std::string>(), "FOREST_PATCH");
        EXPECT_FALSE(node.extras.Get("individualTreesResolved").Get<bool>());
        EXPECT_TRUE(node.extras.Get("visualizationProxy").Get<bool>());
        EXPECT_FALSE(node.extras.Get("speciesInferred").Get<bool>());
        byBatch[node.extras.Get("vegetationBatch").Get<std::string>()].push_back(&node);
        meshes.insert(node.mesh);
        if (node.extras.Get("vegetationLod").Get<std::string>() == "NEAR")
            instances += static_cast<std::size_t>(node.extras.Get("instanceCount").GetNumberAsInt());
    }
    EXPECT_EQ(instances, forest.proxies.size());
    ASSERT_EQ(meshes.size(), 1U);
    for (const auto& [batch, nodes] : byBatch)
    {
        ASSERT_EQ(nodes.size(), 2U) << batch;   // NEAR + MEDIUM, no FAR
        EXPECT_TRUE(nodes[0]->extensions.at("EXT_mesh_gpu_instancing") == nodes[1]->extensions.at("EXT_mesh_gpu_instancing"));
    }
    const tinygltf::Mesh& mesh = b.meshes[static_cast<std::size_t>(*meshes.begin())];
    ASSERT_EQ(mesh.primitives.size(), 4U);
    for (const tinygltf::Primitive& p : mesh.primitives)
    {
        EXPECT_TRUE(p.attributes.count("TEXCOORD_0"));
        EXPECT_GE(b.materials[static_cast<std::size_t>(p.material)].pbrMetallicRoughness.baseColorTexture.index, 0);
    }

    // Grounded on the rendered terrain and tilted with its 5 % slope.
    const LocalSceneFrame frame = LocalFrameTransformer::create(f.metadata, f.surface);
    const TerrainSurfaceSampler sampler(f.surface, f.metadata, frame, TerrainMeshConfig{});
    for (const ForestProxy& p : forest.proxies)
    {
        const auto ground = sampler.localHeight(p.pixelColumn, p.pixelRow);
        ASSERT_TRUE(ground.has_value());
        EXPECT_NEAR(p.translation[1], *ground, 0.05F);
        EXPECT_NEAR(p.tiltDegrees, std::atan(0.05) * 180.0 / 3.14159265358979, 0.1);
        EXPECT_LE(p.scale, 15.0F + 1e-4F);   // Never above the 15 m envelope
    }

    // Forest proxies off (and no candidates, canopy off): the plain GLB.
    const VegetationCanopyInput off = f.input(false, nullptr);
    EXPECT_EQ(f.render(&off).compressedGlbByteBuffer, plain);
}
