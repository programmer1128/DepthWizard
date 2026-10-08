#include <gtest/gtest.h>
#include "BuildingReconstructionTestSupport.h"
#include "BuildingReconstruction/BuildingReconstructionService.h"
#include "MeshMapping/SceneMeshService.h"
#include "MeshMapping/ScenePresentationSelector.h"
#include "MeshMapping/TerrainMesher.h"
#include "SurfaceFusion/SurfaceFusionService.h"
#include "GlbTestSupport.h"
#include "tiny_gltf.h"
#include <draco/compression/decode.h>
#include <opencv2/imgcodecs.hpp>

#include <algorithm>

using namespace depthwizard::test;

TEST(UrbanSceneIntegrationTest, FlatPresentationKeepsTrueBuildingHeightsAndScientificRasters)
{
    constexpr int n = 32;
    auto metadata = makeProjectedMetadata(n, n, .5, -.5);
    auto semantics = makeSemanticScene(n, n, SemanticClass::ROAD);
    fillRectangle(semantics.finalClassMap, 4, 4, 28, 28, SemanticClass::BUILDING);
    fillRectangle(semantics.buildingProbability, 4, 4, 28, 28, .95F);
    auto surface = makeSurface(n, n, 100, 10);
    surface.spatialMetadata = metadata;
    fillRectangle(surface.ndsm, 16, 4, 28, 28, 25.0F);
    for (int y = 0; y < n; ++y)
        for (int x = 0; x < n; ++x) {
            const int i = y * n + x;
            surface.dtm.data[i] += x * .1F;
            surface.dsm.data[i] = surface.dtm.data[i] + surface.ndsm.data[i];
        }
    const auto originalDtm = surface.dtm.data, originalDsm = surface.dsm.data;
    BuildingReconstructionDiagnostics stages;
    BuildingReconstructionConfig bldgConfig;
    const auto buildings = BuildingReconstructionService::reconstruct(
        semantics, surface, metadata, bldgConfig, &stages);
    ASSERT_EQ(buildings.buildings.size(), 2U);
    EXPECT_FLOAT_EQ(buildings.buildings[0].heightAboveGround,
                    10.0F * bldgConfig.heightScaleMultiplier);
    EXPECT_FLOAT_EQ(buildings.buildings[1].heightAboveGround,
                    25.0F * bldgConfig.heightScaleMultiplier);
    ASSERT_TRUE(stages.instanceLabels.isValid());

    SceneInput scene; scene.width = scene.height = n; scene.spatialMetadata = metadata;
    scene.textureMimeType = "image/png";
    cv::Mat optical(n, n, CV_8UC3, cv::Scalar(80, 80, 80));
    optical(cv::Rect(4, 4, 24, 24)).setTo(cv::Scalar(10, 10, 220));
    ASSERT_TRUE(cv::imencode(".png", optical, scene.rgbTextureBytes));
    const auto originalOpticalBytes = scene.rgbTextureBytes;
    MeshBuildConfig config; config.presentation = ScenePresentation::FLAT_URBAN;
    const auto glb = SceneMeshService::generateGlb(scene, surface, buildings, metadata, config);
    ASSERT_FALSE(glb.compressedGlbByteBuffer.empty());
    ASSERT_EQ(glb.buildingCount, 2U);
    tinygltf::TinyGLTF loader; tinygltf::Model model; std::string error, warning;
    ASSERT_TRUE(loader.LoadBinaryFromMemory(&model, &error, &warning,
        glb.compressedGlbByteBuffer.data(), glb.compressedGlbByteBuffer.size())) << error;
    EXPECT_EQ(model.asset.extras.Get("presentationMode").Get<std::string>(), "flat_urban");
    EXPECT_FALSE(model.asset.extras.Get("renderYIsAbsoluteElevationOffset").Get<bool>());
    ASSERT_EQ(model.meshes[0].primitives.size(), 4U);
    EXPECT_TRUE(model.images.empty());
    const auto& terrainMaterial = model.materials.at(
        model.meshes[0].primitives[0].material);
    EXPECT_TRUE(terrainMaterial.extensions.contains("KHR_materials_unlit"));
    EXPECT_EQ(terrainMaterial.pbrMetallicRoughness.baseColorFactor,
              (std::vector<double>{0.26, 0.26, 0.26, 1.0}));
    EXPECT_EQ(scene.rgbTextureBytes, originalOpticalBytes);
    const auto& terrain = model.accessors[model.meshes[0].primitives[0].attributes.at("POSITION")];
    const auto& roof = model.accessors[model.meshes[0].primitives[1].attributes.at("POSITION")];
    EXPECT_NEAR(terrain.maxValues[1], 0, 1e-5);
    EXPECT_NEAR(terrain.minValues[1], 0, 1e-5);
    EXPECT_EQ(glb.terrainTriangleCount, static_cast<std::size_t>(2 * (n-1) * (n-1)));
    EXPECT_NEAR(roof.minValues[1], 10.0 * bldgConfig.heightScaleMultiplier, 1e-5);
    EXPECT_NEAR(roof.maxValues[1], 25.0 * bldgConfig.heightScaleMultiplier, 1e-5);
    // Verify actual compressed positions, not only accessor bounding boxes.
    for (std::size_t primitiveIndex = 0; primitiveIndex < 2; ++primitiveIndex)
    {
        const auto& primitive = model.meshes[0].primitives[primitiveIndex];
        const int viewId = primitive.extensions.at("KHR_draco_mesh_compression")
            .Get("bufferView").Get<int>();
        const auto& view = model.bufferViews.at(viewId);
        draco::DecoderBuffer buffer;
        buffer.Init(reinterpret_cast<const char*>(model.buffers.at(view.buffer).data.data() + view.byteOffset),
                    view.byteLength);
        draco::Decoder decoder;
        auto decoded = decoder.DecodeMeshFromBuffer(&buffer);
        ASSERT_TRUE(decoded.ok());
        const auto& mesh = decoded.value();
        const auto* positions = mesh->GetNamedAttribute(draco::GeometryAttribute::POSITION);
        ASSERT_NE(positions, nullptr);
        for (uint32_t point = 0; point < mesh->num_points(); ++point)
        {
            float position[3];
            ASSERT_TRUE(positions->ConvertValue<float>(positions->mapped_index(draco::PointIndex(point)), 3, position));
            const float y = position[1];
            if (primitiveIndex == 0)
            {
                EXPECT_NEAR(y, 0, .02F);
                // Draco is free to reorder vertices. Read the mapped UV for
                // this point and check its projected coordinate, not its index.
                const auto* uvAttribute = mesh->GetNamedAttribute(draco::GeometryAttribute::TEX_COORD);
                ASSERT_NE(uvAttribute, nullptr);
                float uv[2];
                ASSERT_TRUE(uvAttribute->ConvertValue<float>(
                    uvAttribute->mapped_index(draco::PointIndex(point)), 2, uv));
                EXPECT_NEAR(position[0], uv[0] * n * .5 - n * .25, .02);
                EXPECT_NEAR(position[2], uv[1] * n * .5 - n * .25, .02);
            }
            else
                EXPECT_TRUE(std::abs(y - 10.0F * bldgConfig.heightScaleMultiplier) < .02F ||
                            std::abs(y - 25.0F * bldgConfig.heightScaleMultiplier) < .02F);
        }
    }
    EXPECT_EQ(surface.dtm.data, originalDtm);
    EXPECT_EQ(surface.dsm.data, originalDsm);
}

TEST(UrbanSceneIntegrationTest, NarrowRoofReachesGlbAndRoadNoiseCannotEngulfIt)
{
    constexpr int size = 48;
    auto metadata = makeProjectedMetadata(size, size, 0.5, -0.5);
    auto semantics = makeSemanticScene(size, size, SemanticClass::ROAD);
    semantics.roadProbability = makeConstantGrid(size, size, 0.95F);
    // A townhouse 2 m wide, 16 m long: formerly lost at the watershed step.
    fillRectangle(semantics.finalClassMap, 10, 8, 14, 40, SemanticClass::BUILDING);
    fillRectangle(semantics.buildingProbability, 10, 8, 14, 40, 0.95F);
    fillRectangle(semantics.roadProbability, 10, 8, 14, 40, 0.0F);

    ReferenceTerrainBundle reference;
    reference.correctedTerrainPrior = makeConstantGrid(size, size, 100.0F);
    reference.validMask = makeConstantGrid<uint8_t>(size, size, 1);
    reference.confidence = makeConstantGrid(size, size, 1.0F);
    // Height model error on surrounding roads is higher than the true roof.
    auto predictedHeight = makeConstantGrid(size, size, 40.0F);
    fillRectangle(predictedHeight, 10, 8, 14, 40, 12.0F);
    auto surface = SurfaceFusionService::composeMetricSurface(
        predictedHeight, reference, semantics,
        makeConstantGrid(size, size, 1.0F), metadata);
    EXPECT_FLOAT_EQ(surface.ndsm.data[0], 0.0F);
    EXPECT_FLOAT_EQ(surface.dsm.data[12 * size + 11], 112.0F);

    const auto buildings = BuildingReconstructionService::reconstruct(
        semantics, surface, metadata); // Real production defaults.
    ASSERT_EQ(buildings.buildings.size(), 1U);
    EXPECT_NEAR(buildings.buildings[0].heightAboveGround,
                12.0F * BuildingReconstructionConfig{}.heightScaleMultiplier, 1e-4F);
    EXPECT_NEAR(buildings.buildings[0].roofElevation,
                100.0F + 12.0F * BuildingReconstructionConfig{}.heightScaleMultiplier,
                1e-4F);

    SceneInput scene;
    scene.width = scene.height = size;
    scene.spatialMetadata = metadata;
    const auto glb = SceneMeshService::generateGlb(scene, surface, buildings, metadata);
    ASSERT_FALSE(glb.compressedGlbByteBuffer.empty());
    EXPECT_EQ(glb.buildingCount, 1U);
    EXPECT_GT(glb.roofTriangleCount, 0U);
    EXPECT_GT(glb.wallTriangleCount, 0U);
    tinygltf::TinyGLTF loader;
    tinygltf::Model model;
    std::string error, warning;
    ASSERT_TRUE(loader.LoadBinaryFromMemory(&model, &error, &warning,
        glb.compressedGlbByteBuffer.data(), glb.compressedGlbByteBuffer.size())) << error;
    ASSERT_EQ(model.meshes.size(), 1U);
    ASSERT_EQ(model.meshes[0].primitives.size(), 4U);
    for (std::size_t i = 1; i < 3; ++i)
    {
        const auto& primitive = model.meshes[0].primitives[i];
        EXPECT_FALSE(primitive.attributes.contains("TEXCOORD_0"));
        EXPECT_FALSE(model.materials[primitive.material].extensions.contains("KHR_materials_unlit"));
        EXPECT_EQ(model.materials[primitive.material].pbrMetallicRoughness.baseColorTexture.index, -1);
        EXPECT_EQ(model.materials[primitive.material].emissiveFactor, (std::vector<double>{0, 0, 0}));
    }

    const auto frame = LocalFrameTransformer::create(metadata, surface);
    const auto terrain = TerrainMesher::generate(surface, metadata, frame);
    for (int i = 0; i < size * size; ++i)
        EXPECT_FLOAT_EQ(terrain.terrainPrimitive.positions[i * 3 + 1], 0.0F);
    EXPECT_FLOAT_EQ(surface.dsm.data[12 * size + 11], 112.0F);
}



// --- Phase 2: presentation styles through SceneMeshService ------------------

namespace
{

struct StyledScene
{
    SpatialMetadata metadata;
    SemanticScene semantics;
    GeoreferencedSurfaceBundle surface;
    BuildingCollection buildings;
    SceneInput scene;
};

StyledScene styledScene(bool withOptical)
{
    constexpr int n = 32;
    StyledScene s;
    s.metadata = makeProjectedMetadata(n, n, .5, -.5);
    s.semantics = makeSemanticScene(n, n, SemanticClass::ROAD);
    fillRectangle(s.semantics.finalClassMap, 4, 4, 28, 28, SemanticClass::BUILDING);
    fillRectangle(s.semantics.buildingProbability, 4, 4, 28, 28, .95F);
    s.surface = makeSurface(n, n, 100, 10);
    s.surface.spatialMetadata = s.metadata;
    fillRectangle(s.surface.ndsm, 16, 4, 28, 28, 25.0F);
    for (int y = 0; y < n; ++y)
        for (int x = 0; x < n; ++x)
        {
            const int i = y * n + x;
            s.surface.dtm.data[i] += x * .1F;
            s.surface.dsm.data[i] = s.surface.dtm.data[i] + s.surface.ndsm.data[i];
        }
    BuildingReconstructionDiagnostics stages;
    s.buildings = BuildingReconstructionService::reconstruct(
        s.semantics, s.surface, s.metadata, BuildingReconstructionConfig(), &stages);

    s.scene.width = s.scene.height = n;
    s.scene.spatialMetadata = s.metadata;
    if (withOptical)
    {
        s.scene.textureMimeType = "image/png";
        cv::Mat optical(n, n, CV_8UC3, cv::Scalar(70, 70, 70));
        optical(cv::Rect(4, 4, 24, 24)).setTo(cv::Scalar(20, 20, 220));
        EXPECT_TRUE(cv::imencode(".png", optical, s.scene.rgbTextureBytes));
    }
    return s;
}

GlbBuildResult render(const StyledScene& s, depthwizard::PresentationStyle style, bool neutral = false)
{
    MeshBuildConfig config;
    config.presentationStyle = style;
    config.neutralFacades = neutral;
    return SceneMeshService::generateGlb(s.scene, s.surface, s.buildings, s.metadata, config);
}

std::vector<uint8_t> imageBytes(const tinygltf::Model& model, int texture)
{
    const tinygltf::BufferView& view = model.bufferViews[model.images[model.textures[texture].source].bufferView];
    const auto begin = model.buffers[view.buffer].data.begin() + static_cast<std::ptrdiff_t>(view.byteOffset);
    return {begin, begin + static_cast<std::ptrdiff_t>(view.byteLength)};
}

} // namespace

TEST(UrbanSceneIntegrationTest, OrthophotoStyleBindsOpticalRoofsRepairedGroundAndFacadeWalls)
{
    StyledScene s = styledScene(true);
    ASSERT_EQ(s.buildings.buildings.size(), 2U);
    const auto originalOptical = s.scene.rgbTextureBytes;
    const auto originalDtm = s.surface.dtm.data;
    const auto originalDsm = s.surface.dsm.data;
    const auto originalNdsm = s.surface.ndsm.data;

    const GlbBuildResult glb = render(s, depthwizard::PresentationStyle::ORTHOPHOTO_REALISTIC);
    ASSERT_FALSE(glb.compressedGlbByteBuffer.empty());
    const tinygltf::Model model = loadGlb(glb.compressedGlbByteBuffer);
    EXPECT_EQ(model.asset.extras.Get("presentationStyle").Get<std::string>(), "orthophoto");
    EXPECT_TRUE(model.asset.extras.Get("syntheticFacades").Get<bool>());

    ASSERT_EQ(model.textures.size(), 3U);
    const auto* terrain = primitiveWithMaterial(model, "Terrain_Repaired_Optical");
    const auto* roof = primitiveWithMaterial(model, "Building_Roof_Optical");
    const auto* wall = primitiveWithMaterial(model, "Building_Wall_Facade");
    ASSERT_TRUE(terrain && roof && wall);
    ASSERT_EQ(model.meshes[0].primitives.size(), 3U); // No edge lines in realistic styles

    const auto textureOf = [&](const tinygltf::Primitive* primitive)
    { return model.materials[primitive->material].pbrMetallicRoughness.baseColorTexture.index; };
    // Roofs show the uploaded image itself; terrain shows a repaired copy.
    EXPECT_EQ(imageBytes(model, textureOf(roof)), originalOptical);
    EXPECT_NE(imageBytes(model, textureOf(terrain)), originalOptical);
    EXPECT_NE(textureOf(roof), textureOf(terrain));
    // Geographic images clamp; the facade atlas repeats along walls.
    const auto samplerOf = [&](const tinygltf::Primitive* primitive)
    { return model.samplers[model.textures[textureOf(primitive)].sampler]; };
    EXPECT_EQ(samplerOf(terrain).wrapS, TINYGLTF_TEXTURE_WRAP_CLAMP_TO_EDGE);
    EXPECT_EQ(samplerOf(roof).wrapT, TINYGLTF_TEXTURE_WRAP_CLAMP_TO_EDGE);
    EXPECT_EQ(samplerOf(wall).wrapS, TINYGLTF_TEXTURE_WRAP_REPEAT);
    EXPECT_EQ(samplerOf(wall).wrapT, TINYGLTF_TEXTURE_WRAP_CLAMP_TO_EDGE);
    EXPECT_EQ(std::count(model.extensionsUsed.begin(), model.extensionsUsed.end(), "KHR_materials_unlit"), 0);

    for (const tinygltf::Primitive* primitive : {terrain, roof, wall})
    {
        // COLOR_0 would multiply into the texture: none in textured styles.
        EXPECT_FALSE(primitive->attributes.contains("COLOR_0"));
        const std::vector<float> positions = decodeDracoAttribute(model, *primitive, "POSITION");
        const std::vector<float> uvs = decodeDracoAttribute(model, *primitive, "TEXCOORD_0");
        ASSERT_FALSE(positions.empty());
        EXPECT_EQ(uvs.size(), positions.size() / 3 * 2);
    }
    EXPECT_FALSE(decodeDracoAttribute(model, *roof, "_FEATURE_ID_0").empty());
    EXPECT_FALSE(decodeDracoAttribute(model, *wall, "_FEATURE_ID_0").empty());

    // Wall UVs stay inside one atlas band vertically.
    const std::vector<float> wallUvs = decodeDracoAttribute(model, *wall, "TEXCOORD_0");
    for (std::size_t index = 1; index < wallUvs.size(); index += 2)
    {
        EXPECT_GE(wallUvs[index], 0.0F);
        EXPECT_LE(wallUvs[index], 1.0F);
    }

    // Render-only: no input raster or image was modified.
    EXPECT_EQ(s.scene.rgbTextureBytes, originalOptical);
    EXPECT_EQ(s.surface.dtm.data, originalDtm);
    EXPECT_EQ(s.surface.dsm.data, originalDsm);
    EXPECT_EQ(s.surface.ndsm.data, originalNdsm);
}

TEST(UrbanSceneIntegrationTest, TerraStyleUsesMaterialColoursWithoutVertexColours)
{
    const StyledScene s = styledScene(true);
    const tinygltf::Model model = loadGlb(render(s, depthwizard::PresentationStyle::TERRA_MASSING).compressedGlbByteBuffer);
    EXPECT_EQ(model.asset.extras.Get("presentationStyle").Get<std::string>(), "terra");
    EXPECT_FALSE(model.asset.extras.Has("syntheticFacades"));
    ASSERT_EQ(model.textures.size(), 1U); // Repaired ground only; no facade
    ASSERT_EQ(model.meshes[0].primitives.size(), 3U);

    const auto* terrain = primitiveWithMaterial(model, "Terrain_Repaired_Optical");
    const auto* roof = primitiveWithMaterial(model, "Building_Roof_Terra");
    const auto* wall = primitiveWithMaterial(model, "Building_Wall_Terra");
    ASSERT_TRUE(terrain && roof && wall);
    EXPECT_EQ(model.materials[roof->material].pbrMetallicRoughness.baseColorTexture.index, -1);
    EXPECT_EQ(model.materials[roof->material].pbrMetallicRoughness.baseColorFactor,
              (std::vector<double>{0.95, 0.94, 0.90, 1.0}));
    EXPECT_EQ(model.materials[wall->material].pbrMetallicRoughness.baseColorFactor,
              (std::vector<double>{0.70, 0.69, 0.67, 1.0}));
    // The ivory factor is the final colour: no COLOR_0 tints it a second time.
    for (const auto& primitive : model.meshes[0].primitives)
        EXPECT_FALSE(primitive.attributes.contains("COLOR_0"));
    EXPECT_FALSE(roof->attributes.contains("TEXCOORD_0"));

    // Without the optical image, terrain is a muted untextured material.
    const tinygltf::Model plain = loadGlb(
        render(styledScene(false), depthwizard::PresentationStyle::TERRA_MASSING).compressedGlbByteBuffer);
    EXPECT_TRUE(plain.textures.empty());
    EXPECT_NE(primitiveWithMaterial(plain, "Terrain_Muted"), nullptr);
}

TEST(UrbanSceneIntegrationTest, OrthophotoWithoutAnImageFallsBackToTerraWithAWarning)
{
    const GlbBuildResult glb = render(styledScene(false), depthwizard::PresentationStyle::ORTHOPHOTO_REALISTIC);
    ASSERT_FALSE(glb.compressedGlbByteBuffer.empty());
    EXPECT_TRUE(std::any_of(glb.geometryWarnings.begin(), glb.geometryWarnings.end(),
                            [](const std::string& w) { return w.find("terra massing") != std::string::npos; }));
    const tinygltf::Model model = loadGlb(glb.compressedGlbByteBuffer);
    EXPECT_EQ(model.asset.extras.Get("presentationStyle").Get<std::string>(), "terra");
    EXPECT_NE(primitiveWithMaterial(model, "Building_Roof_Terra"), nullptr);
}

TEST(UrbanSceneIntegrationTest, ScientificStyleKeepsTheLegacyHypsometricMaterials)
{
    const StyledScene s = styledScene(true); // An available image is still not embedded.
    const tinygltf::Model model = loadGlb(render(s, depthwizard::PresentationStyle::SCIENTIFIC).compressedGlbByteBuffer);
    EXPECT_EQ(model.asset.extras.Get("presentationStyle").Get<std::string>(), "scientific");
    EXPECT_TRUE(model.images.empty());
    ASSERT_EQ(model.meshes[0].primitives.size(), 4U);
    EXPECT_EQ(model.meshes[0].primitives[3].mode, TINYGLTF_MODE_LINE);
    ASSERT_EQ(model.materials.size(), 4U);
    const auto& terrain = model.materials[0];
    EXPECT_EQ(terrain.name, "Terrain_Grey");
    EXPECT_TRUE(terrain.extensions.contains("KHR_materials_unlit"));
    EXPECT_EQ(terrain.pbrMetallicRoughness.baseColorFactor, (std::vector<double>{0.26, 0.26, 0.26, 1.0}));
    EXPECT_DOUBLE_EQ(model.materials[1].pbrMetallicRoughness.metallicFactor, 0.10);
    EXPECT_DOUBLE_EQ(model.materials[1].pbrMetallicRoughness.roughnessFactor, 0.40);
    for (int index = 0; index < 3; ++index)
        EXPECT_TRUE(model.meshes[0].primitives[index].attributes.contains("COLOR_0"));
}

TEST(UrbanSceneIntegrationTest, PresentationStylesNeverChangeGeometryOrBuildingIds)
{
    const StyledScene s = styledScene(true);
    std::vector<std::vector<std::vector<float>>> geometry;
    for (auto style : {depthwizard::PresentationStyle::SCIENTIFIC, depthwizard::PresentationStyle::TERRA_MASSING,
                       depthwizard::PresentationStyle::ORTHOPHOTO_REALISTIC})
    {
        const GlbBuildResult glb = render(s, style);
        ASSERT_FALSE(glb.compressedGlbByteBuffer.empty());
        const tinygltf::Model model = loadGlb(glb.compressedGlbByteBuffer);
        std::vector<std::vector<float>> attributes;
        for (int index = 0; index < 3; ++index)
        {
            const tinygltf::Primitive& primitive = model.meshes[0].primitives[index];
            attributes.push_back(decodeDracoAttribute(model, primitive, "POSITION"));
            attributes.push_back(decodeDracoAttribute(model, primitive, "NORMAL"));
            if (index > 0) attributes.push_back(decodeDracoAttribute(model, primitive, "_FEATURE_ID_0"));
        }
        geometry.push_back(attributes);
    }
    EXPECT_EQ(geometry[0], geometry[1]);
    EXPECT_EQ(geometry[0], geometry[2]);
}

TEST(UrbanSceneIntegrationTest, NeutralFacadeOptionKeepsWallsInTheConcreteBand)
{
    const tinygltf::Model model = loadGlb(
        render(styledScene(true), depthwizard::PresentationStyle::ORTHOPHOTO_REALISTIC, true).compressedGlbByteBuffer);
    const auto* wall = primitiveWithMaterial(model, "Building_Wall_Facade");
    ASSERT_NE(wall, nullptr);
    const std::vector<float> uvs = decodeDracoAttribute(model, *wall, "TEXCOORD_0");
    ASSERT_FALSE(uvs.empty());
    for (std::size_t index = 1; index < uvs.size(); index += 2)
        EXPECT_GE(uvs[index], 0.75F - 1e-3F); // Band 3 of 4
}
