#include <gtest/gtest.h>
#include "BuildingReconstructionTestSupport.h"
#include "BuildingReconstruction/BuildingReconstructionService.h"
#include "MeshMapping/SceneMeshService.h"
#include "MeshMapping/ScenePresentationSelector.h"
#include "MeshMapping/TerrainMesher.h"
#include "SurfaceFusion/SurfaceFusionService.h"
#include "tiny_gltf.h"
#include <draco/compression/decode.h>
#include <opencv2/imgcodecs.hpp>

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
    EXPECT_FLOAT_EQ(buildings.buildings[0].heightAboveGround, 19.0F);
    EXPECT_FLOAT_EQ(buildings.buildings[1].heightAboveGround, 47.5F);
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
    ASSERT_EQ(model.images.size(), 1U);
    const auto& imageView = model.bufferViews.at(model.images[0].bufferView);
    const auto& imageBuffer = model.buffers.at(imageView.buffer).data;
    const auto* encodedStart = imageBuffer.data() + imageView.byteOffset;
    const cv::Mat encoded(1, static_cast<int>(imageView.byteLength), CV_8UC1,
                          const_cast<uint8_t*>(encodedStart));
    const cv::Mat renderTexture = cv::imdecode(encoded, cv::IMREAD_COLOR);
    ASSERT_FALSE(renderTexture.empty());
    EXPECT_EQ(model.images[0].mimeType, "image/png");
    EXPECT_LT(renderTexture.at<cv::Vec3b>(16, 16)[2], 150);
    EXPECT_EQ(renderTexture.at<cv::Vec3b>(0, 0), cv::Vec3b(80, 80, 80));
    EXPECT_EQ(scene.rgbTextureBytes, originalOpticalBytes);
    const auto& terrain = model.accessors[model.meshes[0].primitives[0].attributes.at("POSITION")];
    const auto& roof = model.accessors[model.meshes[0].primitives[1].attributes.at("POSITION")];
    EXPECT_NEAR(terrain.maxValues[1], 0, 1e-5);
    EXPECT_NEAR(terrain.minValues[1], 0, 1e-5);
    EXPECT_EQ(glb.terrainTriangleCount, static_cast<std::size_t>(2 * (n-1) * (n-1)));
    EXPECT_NEAR(roof.minValues[1], 19.0, 1e-5);
    EXPECT_NEAR(roof.maxValues[1], 47.5, 1e-5);
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
                EXPECT_TRUE(std::abs(y - 19.0F) < .02F || std::abs(y - 47.5F) < .02F);
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
    EXPECT_NEAR(buildings.buildings[0].heightAboveGround, 22.8F, 1e-4F);
    EXPECT_NEAR(buildings.buildings[0].roofElevation, 122.8F, 1e-4F);

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
