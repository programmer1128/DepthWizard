#include <gtest/gtest.h>

#include "CompressionLib/DracoCompressor.h"
#include "FileGenerators/GltfPackager.h"
#include "MeshMapping/BuildingMesher.h"
#include "MeshMapping/TerrainMesher.h"
#include "MeshMapping/TerrainSurfaceComposer.h"
#include "MeshMapping/TerrainTextureComposer.h"
#include "MeshMapping/FacadeAtlasGenerator.h"
#include "MeshMapping/PresentationMaterials.h"
#include "GlbTestSupport.h"
#include <opencv2/imgcodecs.hpp>
#include "TestGridSupport.h"
#include "BuildingReconstructionTestSupport.h"
#include "tiny_gltf.h"

#include <algorithm>
#include <array>
#include <cmath>
#include <cstdint>
#include <tuple>
#include <limits>
#include <string>
#include <vector>

namespace
{
using namespace depthwizard::test;

TEST(MeshPipelineTest, TerrainVerticesUseReconstructedDsmNotBareEarthDtm)
{
    GeoreferencedSurfaceBundle surface;
    surface.dtm = makeConstantGrid(3, 3, 100.0F);
    surface.dsm = makeConstantGrid(3, 3, 100.0F);
    surface.dsm.data[4] = 125.0F;
    surface.validMask = makeConstantGrid<uint8_t>(3, 3, uint8_t{1});

    SpatialMetadata metadata;
    metadata.width = 3;
    metadata.height = 3;
    metadata.geoTransform = {0.0, 1.0, 0.0, 0.0, 0.0, -1.0};

    LocalSceneFrame frame;
    frame.elevationOrigin = 100.0;

    TerrainMeshConfig config;
    config.elevationSource = TerrainElevationSource::SURFACE_PREVIEW;
    config.maxGridSize = 3;
    config.skirtDepth = 10.0F;

    const TerrainMesh mesh = TerrainMesher::generate(
        surface,
        metadata,
        frame,
        config);

    const std::size_t centerVertex = 4;
    ASSERT_GT(mesh.terrainPrimitive.positions.size(), centerVertex * 3 + 1);
    EXPECT_FLOAT_EQ(
        mesh.terrainPrimitive.positions[centerVertex * 3 + 1],
        25.0F);
}

TEST(MeshPipelineTest, AcceptedBuildingPixelsUseDtmInTexturedTerrain)
{
    GeoreferencedSurfaceBundle surface;
    surface.dtm = makeConstantGrid(3, 3, 100.0F);
    surface.dsm = makeConstantGrid(3, 3, 105.0F);
    surface.dsm.data[4] = 125.0F;
    surface.validMask = makeConstantGrid<uint8_t>(3, 3, uint8_t{1});

    RasterGrid<uint8_t> acceptedMask =
        makeConstantGrid<uint8_t>(3, 3, uint8_t{0});
    acceptedMask.data[4] = 1;

    SpatialMetadata metadata;
    metadata.width = 3;
    metadata.height = 3;
    metadata.geoTransform = {0.0, 1.0, 0.0, 0.0, 0.0, -1.0};

    LocalSceneFrame frame;
    frame.elevationOrigin = 100.0;

    TerrainMeshConfig config;
    config.elevationSource = TerrainElevationSource::SURFACE_PREVIEW;
    config.maxGridSize = 3;

    const TerrainMesh mesh = TerrainMesher::generate(
        surface,
        acceptedMask,
        metadata,
        frame,
        config);

    // The building center is flattened to DTM, while non-building terrain
    // retains the high-frequency DSM.
    EXPECT_FLOAT_EQ(mesh.terrainPrimitive.positions[4 * 3 + 1], 0.0F);
    EXPECT_FLOAT_EQ(mesh.terrainPrimitive.positions[0 * 3 + 1], 5.0F);
}

TEST(MeshPipelineTest, ComposerMasksOnlyAcceptedBuildingFootprints)
{
    BuildingInstance accepted;
    accepted.pixelFootprint.outerRing = {
        {1.0, 1.0},
        {3.0, 1.0},
        {3.0, 3.0},
        {1.0, 3.0}};

    BuildingCollection buildings;
    buildings.buildings.push_back(accepted);

    SpatialMetadata metadata;
    metadata.width = 5;
    metadata.height = 5;
    metadata.geoTransform = {0.0, 1.0, 0.0, 0.0, 0.0, -1.0};

    const RasterGrid<uint8_t> mask =
        TerrainSurfaceComposer::buildAcceptedBuildingMask(
            buildings, metadata, 0.0F);

    ASSERT_TRUE(mask.isValid());
    EXPECT_EQ(mask.data[2 * 5 + 2], 1);
    EXPECT_EQ(mask.data[0], 0);
    EXPECT_EQ(mask.data[4 * 5 + 4], 0);
}

TEST(MeshPipelineTest, RenderTextureHidesAcceptedRoofWithoutChangingDistantRoads)
{
    TextureAsset texture;
    texture.mimeType = "image/png";
    cv::Mat optical(15, 15, CV_8UC3, cv::Scalar(80, 80, 80));
    optical(cv::Rect(5, 5, 5, 5)).setTo(cv::Scalar(10, 10, 220));
    optical.at<cv::Vec3b>(7, 14) = cv::Vec3b(20, 40, 60);
    ASSERT_TRUE(cv::imencode(".png", optical, texture.bytes));

    auto footprints = makeConstantGrid<uint8_t>(15, 15, uint8_t{0});
    fillRectangle(footprints, 5, 5, 10, 10, uint8_t{1});
    const auto metadata = makeProjectedMetadata(15, 15);
    const TextureAsset repaired = TerrainTextureComposer::concealAcceptedRoofs(
        texture, footprints, metadata, 1.0f);
    EXPECT_EQ(repaired.mimeType, "image/png");
    const cv::Mat decoded = cv::imdecode(repaired.bytes, cv::IMREAD_COLOR);
    ASSERT_FALSE(decoded.empty());
    EXPECT_LT(decoded.at<cv::Vec3b>(7, 7)[2], 120);
    EXPECT_EQ(decoded.at<cv::Vec3b>(7, 14), cv::Vec3b(20, 40, 60));
    EXPECT_EQ(decoded.at<cv::Vec3b>(0, 0), cv::Vec3b(80, 80, 80));
    EXPECT_EQ(texture.mimeType, "image/png");
    EXPECT_EQ(cv::imdecode(texture.bytes, cv::IMREAD_COLOR)
                  .at<cv::Vec3b>(7, 7)[2], 220);

    footprints.data.assign(15 * 15, 0);
    const auto untouched = TerrainTextureComposer::concealAcceptedRoofs(
        texture, footprints, metadata, 1.0f);
    EXPECT_EQ(untouched.bytes, texture.bytes);
}

TEST(MeshPipelineTest, FeatureIdAccessorUsesGltfLegalFloatComponentType)
{
    MeshPrimitive primitive;
    primitive.materialRole = MaterialRole::BUILDING_ROOF;
    primitive.positions = {
        0.0F, 0.0F, 0.0F,
        1.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 1.0F};
    primitive.indices = {0, 1, 2};
    primitive.featureIds = std::vector<float>{7.0F, 7.0F, 7.0F};
    primitive.localBounds = {0.0, 0.0, 0.0, 1.0, 0.0, 1.0, true};

    const CompressedPrimitive compressed = DracoCompressor::compress(primitive);
    ASSERT_TRUE(compressed.success) << compressed.errorMessage;
    ASSERT_GE(compressed.featureIdAttrId, 0);

    SceneMesh scene;
    scene.roofPrimitive = primitive;
    scene.materials = {MaterialRole::BUILDING_ROOF};
    scene.sceneBounds = primitive.localBounds;

    const GlbBuildResult glb = GltfPackager::buildSceneToMemory(
        scene,
        {compressed},
        1);
    ASSERT_FALSE(glb.compressedGlbByteBuffer.empty());

    tinygltf::TinyGLTF loader;
    tinygltf::Model model;
    std::string error;
    std::string warning;
    const bool loaded = loader.LoadBinaryFromMemory(
        &model,
        &error,
        &warning,
        glb.compressedGlbByteBuffer.data(),
        static_cast<unsigned int>(glb.compressedGlbByteBuffer.size()));

    ASSERT_TRUE(loaded) << error;
    ASSERT_EQ(model.meshes.size(), 1U);
    ASSERT_EQ(model.meshes[0].primitives.size(), 1U);

    const auto feature =
        model.meshes[0].primitives[0].attributes.find("_FEATURE_ID_0");
    ASSERT_NE(feature, model.meshes[0].primitives[0].attributes.end());
    ASSERT_GE(feature->second, 0);
    ASSERT_LT(static_cast<std::size_t>(feature->second), model.accessors.size());
    EXPECT_EQ(
        model.accessors[feature->second].componentType,
        TINYGLTF_COMPONENT_TYPE_FLOAT);

    ASSERT_EQ(model.materials.size(), 1U);
    EXPECT_FALSE(model.materials[0].extensions.contains(
        "KHR_materials_unlit"));
}

TEST(MeshPipelineTest, Color0AccessorUsesGltfLegalVec4FloatComponentType)
{
    MeshPrimitive primitive;
    primitive.materialRole = MaterialRole::BUILDING_ROOF;
    primitive.positions = {
        0.0F, 0.0F, 0.0F,
        1.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 1.0F};
    primitive.indices = {0, 1, 2};
    primitive.colors = std::vector<float>{
        0.0F, 0.62F, 0.82F, 1.0F,
        0.0F, 0.62F, 0.82F, 1.0F,
        0.0F, 0.62F, 0.82F, 1.0F};
    primitive.localBounds = {0.0, 0.0, 0.0, 1.0, 0.0, 1.0, true};

    const CompressedPrimitive compressed = DracoCompressor::compress(primitive);
    ASSERT_TRUE(compressed.success) << compressed.errorMessage;
    ASSERT_GE(compressed.colorAttrId, 0);

    SceneMesh scene;
    scene.roofPrimitive = primitive;
    scene.materials = {MaterialRole::BUILDING_ROOF};
    scene.sceneBounds = primitive.localBounds;

    const GlbBuildResult glb = GltfPackager::buildSceneToMemory(
        scene,
        {compressed},
        1);
    ASSERT_FALSE(glb.compressedGlbByteBuffer.empty());

    tinygltf::TinyGLTF loader;
    tinygltf::Model model;
    std::string error;
    std::string warning;
    const bool loaded = loader.LoadBinaryFromMemory(
        &model,
        &error,
        &warning,
        glb.compressedGlbByteBuffer.data(),
        static_cast<unsigned int>(glb.compressedGlbByteBuffer.size()));

    ASSERT_TRUE(loaded) << error;
    ASSERT_EQ(model.meshes.size(), 1U);
    ASSERT_EQ(model.meshes[0].primitives.size(), 1U);

    const auto colorAttr =
        model.meshes[0].primitives[0].attributes.find("COLOR_0");
    ASSERT_NE(colorAttr, model.meshes[0].primitives[0].attributes.end());
    ASSERT_GE(colorAttr->second, 0);
    ASSERT_LT(static_cast<std::size_t>(colorAttr->second), model.accessors.size());
    EXPECT_EQ(
        model.accessors[colorAttr->second].componentType,
        TINYGLTF_COMPONENT_TYPE_FLOAT);
    EXPECT_EQ(
        model.accessors[colorAttr->second].type,
        TINYGLTF_TYPE_VEC4);
}

TEST(MeshPipelineTest, DisablingSkirtEmitsOnlyTopSurfaceVerticesAndFaces)
{
    auto metadata = makeProjectedMetadata(4, 4, 1, -1);
    auto surface = makeSurface(4, 4, 100, 10);
    auto frame = LocalFrameTransformer::create(metadata, surface);
    TerrainMeshConfig config;
    config.elevationSource = TerrainElevationSource::FLAT_PRESENTATION;
    config.generateSkirt = false;
    const auto flat = TerrainMesher::generate(surface, metadata, frame, config);
    EXPECT_EQ(flat.terrainPrimitive.positions.size(), 4U*4U*3U);
    EXPECT_EQ(flat.terrainPrimitive.indices.size(), 3U*3U*6U);
    EXPECT_DOUBLE_EQ(flat.terrainPrimitive.localBounds.minY, 0);
    config.generateSkirt = true;
    const auto terrain = TerrainMesher::generate(surface, metadata, frame, config);
    EXPECT_GT(terrain.terrainPrimitive.positions.size(), flat.terrainPrimitive.positions.size());
    EXPECT_LT(terrain.terrainPrimitive.localBounds.minY, 0);
}

TEST(MeshPipelineTest, BuildingPrimitivesAreUntexturedShadedAndSeparateFromTerrain)
{
    const auto makeTriangle = [](MaterialRole role, bool withUvs)
    {
        MeshPrimitive primitive;
        primitive.materialRole = role;
        primitive.positions = {
            0.0F, 0.0F, 0.0F,
            1.0F, 0.0F, 0.0F,
            0.0F, 0.0F, 1.0F};
        primitive.indices = {0, 1, 2};
        primitive.localBounds = {0.0, 0.0, 0.0, 1.0, 0.0, 1.0, true};
        if (withUvs)
        {
            primitive.uvs = std::vector<float>{
                0.0F, 0.0F,
                1.0F, 0.0F,
                0.0F, 1.0F};
        }
        return primitive;
    };

    SceneMesh scene;
    scene.terrainPrimitive = makeTriangle(
        MaterialRole::TERRAIN_TEXTURE, true);
    scene.roofPrimitive = makeTriangle(
        MaterialRole::BUILDING_ROOF, false);
    scene.wallPrimitive = makeTriangle(
        MaterialRole::BUILDING_WALL, false);
    scene.materials = {
        MaterialRole::TERRAIN_TEXTURE,
        MaterialRole::BUILDING_ROOF,
        MaterialRole::BUILDING_WALL};
    scene.sceneBounds = scene.terrainPrimitive.localBounds;
    TextureAsset texture;
    texture.mimeType = "image/png";
    const cv::Mat optical(2, 3, CV_8UC3, cv::Scalar(10, 20, 30));
    ASSERT_TRUE(cv::imencode(".png", optical, texture.bytes));
    scene.texture = std::move(texture);

    const std::vector<CompressedPrimitive> compressed{
        DracoCompressor::compress(scene.terrainPrimitive),
        DracoCompressor::compress(scene.roofPrimitive),
        DracoCompressor::compress(scene.wallPrimitive)};
    ASSERT_TRUE(compressed[0].success);
    ASSERT_TRUE(compressed[1].success);
    ASSERT_TRUE(compressed[2].success);

    const GlbBuildResult glb = GltfPackager::buildSceneToMemory(
        scene, compressed, 1);
    ASSERT_FALSE(glb.compressedGlbByteBuffer.empty());

    tinygltf::TinyGLTF loader;
    tinygltf::Model model;
    std::string error;
    std::string warning;
    ASSERT_TRUE(loader.LoadBinaryFromMemory(
        &model,
        &error,
        &warning,
        glb.compressedGlbByteBuffer.data(),
        static_cast<unsigned int>(glb.compressedGlbByteBuffer.size())))
        << error;

    ASSERT_EQ(model.meshes.size(), 1U);
    ASSERT_EQ(model.meshes[0].primitives.size(), 3U);
    ASSERT_EQ(model.materials.size(), 3U);
    ASSERT_EQ(model.textures.size(), 1U);
    ASSERT_GE(model.textures[0].sampler, 0);
    const auto& sampler = model.samplers.at(model.textures[0].sampler);
    EXPECT_EQ(sampler.wrapS, TINYGLTF_TEXTURE_WRAP_CLAMP_TO_EDGE);
    EXPECT_EQ(sampler.wrapT, TINYGLTF_TEXTURE_WRAP_CLAMP_TO_EDGE);

    const tinygltf::Primitive& terrain = model.meshes[0].primitives[0];
    const tinygltf::Primitive& roof = model.meshes[0].primitives[1];
    const tinygltf::Primitive& wall = model.meshes[0].primitives[2];

    EXPECT_TRUE(terrain.attributes.contains("TEXCOORD_0"));
    EXPECT_FALSE(roof.attributes.contains("TEXCOORD_0"));
    EXPECT_FALSE(wall.attributes.contains("TEXCOORD_0"));

    ASSERT_GE(roof.material, 0);
    ASSERT_GE(wall.material, 0);
    EXPECT_FALSE(model.materials[roof.material].extensions.contains(
        "KHR_materials_unlit"));
    EXPECT_FALSE(model.materials[wall.material].extensions.contains(
        "KHR_materials_unlit"));
    EXPECT_EQ(
        model.materials[roof.material]
            .pbrMetallicRoughness.baseColorTexture.index,
        -1);
    EXPECT_EQ(
        model.materials[wall.material]
            .pbrMetallicRoughness.baseColorTexture.index,
        -1);
    EXPECT_TRUE(model.materials[roof.material].name == "Building_Roof" ||
                model.materials[roof.material].name == "Hologram_Roof");
    EXPECT_TRUE(model.materials[wall.material].name == "Building_Wall" ||
                model.materials[wall.material].name == "Hologram_Wall");
    EXPECT_EQ(std::count(model.extensionsUsed.begin(), model.extensionsUsed.end(),
        "KHR_materials_unlit"), 1);
    const auto& wallPbr = model.materials[wall.material].pbrMetallicRoughness;
    const auto& roofPbr = model.materials[roof.material].pbrMetallicRoughness;
    EXPECT_DOUBLE_EQ(wallPbr.baseColorFactor[0], 1.0);
    EXPECT_DOUBLE_EQ(wallPbr.baseColorFactor[1], 1.0);
    EXPECT_DOUBLE_EQ(wallPbr.baseColorFactor[2], 1.0);
    EXPECT_DOUBLE_EQ(wallPbr.metallicFactor, 0.10);
    EXPECT_DOUBLE_EQ(wallPbr.roughnessFactor, 0.40);
    EXPECT_EQ(model.materials[wall.material].alphaMode, "OPAQUE");
    EXPECT_TRUE(model.materials[wall.material].doubleSided);
    EXPECT_DOUBLE_EQ(roofPbr.baseColorFactor[0], 1.0);
    EXPECT_DOUBLE_EQ(roofPbr.baseColorFactor[1], 1.0);
    EXPECT_DOUBLE_EQ(roofPbr.baseColorFactor[2], 1.0);
    EXPECT_DOUBLE_EQ(roofPbr.baseColorFactor[3], 1.0);
    EXPECT_DOUBLE_EQ(roofPbr.metallicFactor, 0.10);
    EXPECT_DOUBLE_EQ(roofPbr.roughnessFactor, 0.40);
    EXPECT_EQ(model.materials[roof.material].alphaMode, "OPAQUE");
    EXPECT_TRUE(model.materials[roof.material].doubleSided);
}

TEST(MeshPipelineTest, TerrainUvMatchesPixelEdgeFrameWithoutVerticalReflection)
{
    auto metadata = makeProjectedMetadata(4, 4, 2.0, -3.0);
    // Include rotation/shear so the test cannot pass by equating world Z to V.
    metadata.geoTransform[2] = 0.25;
    metadata.geoTransform[4] = 0.1;
    auto surface = makeSurface(4, 4, 100, 0);
    auto frame = LocalFrameTransformer::create(metadata, surface);
    TerrainMeshConfig config;
    config.generateSkirt = false;
    const auto mesh = TerrainMesher::generate(surface, metadata, frame, config);
    const auto& positions = mesh.terrainPrimitive.positions;
    ASSERT_TRUE(mesh.terrainPrimitive.uvs.has_value());
    const auto& uv = *mesh.terrainPrimitive.uvs;
    const double pixelCoordinates[] = {0.0, 1.5, 2.5, 4.0};
    for (int row = 0; row < 4; ++row)
        for (int col = 0; col < 4; ++col)
        {
            const int index = row * 4 + col;
            const double px = pixelCoordinates[col], py = pixelCoordinates[row];
            EXPECT_NEAR(uv[index * 2], px / 4, 1e-7);
            EXPECT_NEAR(uv[index * 2 + 1], py / 4, 1e-7);
            const double e = metadata.geoTransform[0] + px * 2.0 + py * 0.25;
            const double n = metadata.geoTransform[3] + px * 0.1 - py * 3.0;
            EXPECT_NEAR(positions[index * 3], e - frame.projectedOriginX, 1e-5);
            EXPECT_NEAR(positions[index * 3 + 2], -(n - frame.projectedOriginY), 1e-5);
        }
}

TEST(MeshPipelineTest, DecimatedTerrainTextureStillCoversWholeNonSquareRaster)
{
    auto metadata = makeProjectedMetadata(11, 7, 0.5, -0.75);
    auto surface = makeSurface(11, 7, 100, 0);
    auto frame = LocalFrameTransformer::create(metadata, surface);
    TerrainMeshConfig config;
    config.maxGridSize = 3;
    config.generateSkirt = false;
    const auto mesh = TerrainMesher::generate(surface, metadata, frame, config);
    const auto& p = mesh.terrainPrimitive.positions;
    const auto& uv = *mesh.terrainPrimitive.uvs;
    EXPECT_FLOAT_EQ(uv[0], 0);
    EXPECT_FLOAT_EQ(uv[1], 0);
    EXPECT_FLOAT_EQ(uv[uv.size() - 2], 1);
    EXPECT_FLOAT_EQ(uv.back(), 1);
    for (std::size_t i = 0; i < p.size() / 3; ++i)
    {
        const double pixelX = (p[i*3] + frame.projectedOriginX - metadata.geoTransform[0]) / 0.5;
        const double pixelY = (-p[i*3+2] + frame.projectedOriginY - metadata.geoTransform[3]) / -0.75;
        EXPECT_NEAR(uv[i*2], pixelX / 11, 1e-6);
        EXPECT_NEAR(uv[i*2+1], pixelY / 7, 1e-6);
    }
}

TEST(MeshPipelineTest, BuildingRoofTriangulatesAfterLocalAxisReflection)
{
    BuildingInstance building;
    building.buildingId = 11;
    building.projectedFootprint.outerRing = {
        {0.0, 0.0},
        {2.0, 0.0},
        {2.0, 2.0},
        {0.0, 2.0}};
    building.representativeBaseElevation = 101.5F;
    building.baseElevationPerVertex = {100.0F, 101.0F, 102.0F, 103.0F};
    building.roofElevation = 110.0F;

    BuildingCollection buildings;
    buildings.buildings.push_back(building);

    LocalSceneFrame frame;
    frame.elevationOrigin = 100.0;

    BuildingMeshConfig config;
    config.wallTerrainEmbedDepthMetres = 0.5F;

    const BuildingMesh mesh = BuildingMesher::generate(
        buildings,
        frame,
        config);

    ASSERT_EQ(mesh.roofPrimitive.positions.size(), 12U);
    ASSERT_EQ(mesh.roofPrimitive.indices.size(), 6U);
    ASSERT_EQ(mesh.wallPrimitive.indices.size(), 24U);

    for (uint32_t index : mesh.roofPrimitive.indices)
    {
        EXPECT_LT(index, 4U);
    }

    // The wall bases follow all four DTM vertex elevations with only the
    // configured 0.5 m overlap; they are not forced into a 15 m underground
    // extrusion.
    std::vector<float> wallBaseElevations;
    for (std::size_t quad = 0; quad < 4; ++quad)
    {
        const std::size_t firstBaseY = quad * 12 + 1;
        const std::size_t secondBaseY = quad * 12 + 10;
        wallBaseElevations.push_back(
            mesh.wallPrimitive.positions[firstBaseY]);
        wallBaseElevations.push_back(
            mesh.wallPrimitive.positions[secondBaseY]);
    }

    const auto [minimumBase, maximumBase] = std::minmax_element(
        wallBaseElevations.begin(),
        wallBaseElevations.end());
    ASSERT_NE(minimumBase, wallBaseElevations.end());
    ASSERT_NE(maximumBase, wallBaseElevations.end());
    EXPECT_FLOAT_EQ(*minimumBase, -0.5F);
    EXPECT_FLOAT_EQ(*maximumBase, 2.5F);
}

TEST(MeshPipelineTest, CourtyardRoofNeverEmitsOutOfRangeBridgeIndices)
{
    BuildingInstance building;
    building.buildingId = 12;
    building.projectedFootprint.outerRing = {
        {0.0, 0.0},
        {10.0, 0.0},
        {10.0, 10.0},
        {0.0, 10.0}};
    building.projectedFootprint.holes.push_back({
        {3.0, 3.0},
        {3.0, 7.0},
        {7.0, 7.0},
        {7.0, 3.0}});
    building.representativeBaseElevation = 100.0F;
    building.roofElevation = 110.0F;

    BuildingCollection buildings;
    buildings.buildings.push_back(std::move(building));

    LocalSceneFrame frame;
    frame.elevationOrigin = 100.0;

    const BuildingMesh mesh = BuildingMesher::generate(buildings, frame);

    ASSERT_FALSE(mesh.roofPrimitive.indices.empty());
    const std::size_t roofVertexCount =
        mesh.roofPrimitive.positions.size() / 3;
    for (uint32_t index : mesh.roofPrimitive.indices)
    {
        EXPECT_LT(index, roofVertexCount);
    }
}

TEST(MeshPipelineTest, Lod2GableBlockProducesSlopedRoofAndCrispWalls)
{
    BuildingInstance building;
    building.buildingId = 21;
    building.heightAboveGround = 15.0F;
    building.representativeBaseElevation = 100.0F;
    building.roofElevation = 115.0F;
    building.projectedFootprint.outerRing = {
        {0.0, 0.0}, {20.0, 0.0}, {20.0, 10.0}, {0.0, 10.0}};
    DecomposedBuildingBlock block;
    block.projectedCorners = {
        ProjectedPoint{0.0, 0.0}, ProjectedPoint{20.0, 0.0},
        ProjectedPoint{20.0, 10.0}, ProjectedPoint{0.0, 10.0}};
    block.roof.type = RoofType::GABLE;
    block.roof.eaveHeightAboveGround = 10.0F;
    block.roof.ridgeHeightAboveGround = 15.0F;
    // Evidence says the ridge runs along the shorter north/south axis. The
    // mesher must honor that fitted direction instead of assuming long-axis.
    block.roof.ridgeStartProjected = {10.0, 0.0};
    block.roof.ridgeEndProjected = {10.0, 10.0};
    building.blocks.push_back(block);

    BuildingCollection buildings;
    buildings.buildings.push_back(building);
    LocalSceneFrame frame;
    frame.elevationOrigin = 100.0;

    const BuildingMesh mesh = BuildingMesher::generate(buildings, frame);

    ASSERT_EQ(mesh.emittedBuildingIds, std::vector<uint32_t>{21});
    ASSERT_EQ(mesh.roofPrimitive.indices.size(), 12U);
    ASSERT_EQ(mesh.wallPrimitive.indices.size(), 30U);
    ASSERT_TRUE(mesh.roofPrimitive.normals.has_value());
    float minimumRoofY = std::numeric_limits<float>::max();
    float maximumRoofY = std::numeric_limits<float>::lowest();
    float minimumRidgeX = std::numeric_limits<float>::max();
    float maximumRidgeX = std::numeric_limits<float>::lowest();
    float minimumRidgeZ = std::numeric_limits<float>::max();
    float maximumRidgeZ = std::numeric_limits<float>::lowest();
    bool foundSlopedNormal = false;
    for (std::size_t vertex = 0;
         vertex < mesh.roofPrimitive.positions.size() / 3; ++vertex)
    {
        minimumRoofY = std::min(
            minimumRoofY, mesh.roofPrimitive.positions[vertex * 3 + 1]);
        maximumRoofY = std::max(
            maximumRoofY, mesh.roofPrimitive.positions[vertex * 3 + 1]);
        if (std::abs(mesh.roofPrimitive.positions[vertex * 3 + 1] - 15.0F) <
            1.0e-5F)
        {
            minimumRidgeX = std::min(
                minimumRidgeX, mesh.roofPrimitive.positions[vertex * 3]);
            maximumRidgeX = std::max(
                maximumRidgeX, mesh.roofPrimitive.positions[vertex * 3]);
            minimumRidgeZ = std::min(
                minimumRidgeZ, mesh.roofPrimitive.positions[vertex * 3 + 2]);
            maximumRidgeZ = std::max(
                maximumRidgeZ, mesh.roofPrimitive.positions[vertex * 3 + 2]);
        }
        const auto& normals = *mesh.roofPrimitive.normals;
        foundSlopedNormal = foundSlopedNormal ||
            std::abs(normals[vertex * 3]) > 0.05F ||
            std::abs(normals[vertex * 3 + 2]) > 0.05F;
    }
    EXPECT_FLOAT_EQ(minimumRoofY, 10.0F);
    EXPECT_FLOAT_EQ(maximumRoofY, 15.0F);
    EXPECT_TRUE(foundSlopedNormal);
    EXPECT_NEAR(maximumRidgeX - minimumRidgeX, 0.0F, 1.0e-5F);
    EXPECT_NEAR(maximumRidgeZ - minimumRidgeZ, 10.0F, 1.0e-5F);
}

TEST(MeshPipelineTest, SetbackEmitsOnlyExposedStepWall)
{
    BuildingInstance building;
    building.buildingId = 22;
    building.heightAboveGround = 45.0F;
    building.representativeBaseElevation = 100.0F;
    building.roofElevation = 145.0F;
    building.projectedFootprint.outerRing = {
        {0.0, 0.0}, {20.0, 0.0}, {20.0, 10.0}, {0.0, 10.0}};
    DecomposedBuildingBlock podium, tower;
    podium.projectedCorners = {{{0.0, 0.0}, {10.0, 0.0},
                                {10.0, 10.0}, {0.0, 10.0}}};
    tower.projectedCorners = {{{10.0, 0.0}, {20.0, 0.0},
                               {20.0, 10.0}, {10.0, 10.0}}};
    podium.roof.eaveHeightAboveGround = 20.0F;
    podium.roof.ridgeHeightAboveGround = 20.0F;
    tower.roof.eaveHeightAboveGround = 45.0F;
    tower.roof.ridgeHeightAboveGround = 45.0F;
    building.blocks = {podium, tower};
    BuildingCollection buildings;
    buildings.buildings.push_back(building);
    LocalSceneFrame frame;
    frame.elevationOrigin = 100.0;

    const auto mesh = BuildingMesher::generate(buildings, frame);

    int stepTriangles = 0;
    const auto& positions = mesh.wallPrimitive.positions;
    for (std::size_t index = 0; index < positions.size(); index += 9)
    {
        const float x0 = positions[index];
        const float x1 = positions[index + 3];
        const float x2 = positions[index + 6];
        if (std::abs(x0 - 10.0F) < 1e-4F &&
            std::abs(x1 - 10.0F) < 1e-4F &&
            std::abs(x2 - 10.0F) < 1e-4F)
        {
            ++stepTriangles;
            EXPECT_GE(std::min({positions[index + 1], positions[index + 4],
                                positions[index + 7]}), 20.0F);
            EXPECT_LE(std::max({positions[index + 1], positions[index + 4],
                                positions[index + 7]}), 45.0F);
        }
    }
    EXPECT_EQ(stepTriangles, 2);
}

TEST(MeshPipelineTest, PartialSharedEdgeKeepsUncoveredExteriorWall)
{
    BuildingInstance building;
    building.buildingId = 23;
    building.heightAboveGround = 20.0F;
    building.representativeBaseElevation = 100.0F;
    building.roofElevation = 120.0F;
    building.projectedFootprint.outerRing = {
        {0.0, 0.0}, {20.0, 0.0}, {20.0, 5.0},
        {10.0, 5.0}, {10.0, 10.0}, {0.0, 10.0}};
    DecomposedBuildingBlock left, upperRight;
    left.projectedCorners = {{{0.0, 0.0}, {10.0, 0.0},
                              {10.0, 10.0}, {0.0, 10.0}}};
    upperRight.projectedCorners = {{{10.0, 0.0}, {20.0, 0.0},
                                    {20.0, 5.0}, {10.0, 5.0}}};
    for (auto* block : {&left, &upperRight})
    {
        block->roof.type = RoofType::FLAT;
        block->roof.eaveHeightAboveGround = 20.0F;
        block->roof.ridgeHeightAboveGround = 20.0F;
    }
    building.blocks = {left, upperRight};
    BuildingCollection buildings;
    buildings.buildings.push_back(building);
    LocalSceneFrame frame;
    frame.elevationOrigin = 100.0;

    const auto mesh = BuildingMesher::generate(buildings, frame);
    int uncoveredWallTriangles = 0;
    int coveredWallTriangles = 0;
    const auto& positions = mesh.wallPrimitive.positions;
    for (std::size_t index = 0; index < positions.size(); index += 9)
    {
        if (std::abs(positions[index] - 10.0F) > 1.0e-4F ||
            std::abs(positions[index + 3] - 10.0F) > 1.0e-4F ||
            std::abs(positions[index + 6] - 10.0F) > 1.0e-4F)
            continue;
        const float minZ = std::min({positions[index + 2],
                                     positions[index + 5],
                                     positions[index + 8]});
        const float maxZ = std::max({positions[index + 2],
                                     positions[index + 5],
                                     positions[index + 8]});
        if (minZ >= -10.0F - 1.0e-4F &&
            maxZ <= -5.0F + 1.0e-4F)
            ++uncoveredWallTriangles;
        if (minZ >= -5.0F - 1.0e-4F &&
            maxZ <= 0.0F + 1.0e-4F)
            ++coveredWallTriangles;
    }
    EXPECT_EQ(uncoveredWallTriangles, 2);
    EXPECT_EQ(coveredWallTriangles, 0);
}

TEST(MeshPipelineTest, DefaultTerrainUsesDtmEvenWhenNoBuildingsAreAccepted)
{
    GeoreferencedSurfaceBundle surface;
    surface.dtm = makeConstantGrid(4, 4, 100.0F);
    surface.dsm = makeConstantGrid(4, 4, 180.0F);
    surface.validMask = makeConstantGrid<uint8_t>(4, 4, 1);
    for (int row = 0; row < 4; ++row)
        for (int col = 0; col < 4; ++col)
            surface.dtm.data[row * 4 + col] += row + col;
    SpatialMetadata metadata;
    metadata.width = metadata.height = 4;
    metadata.geoTransform = {0, 1, 0, 0, 0, -1};
    LocalSceneFrame frame;
    frame.elevationOrigin = 100;
    const auto terrain = TerrainMesher::generate(surface, metadata, frame);
    for (int i = 0; i < 16; ++i)
        EXPECT_FLOAT_EQ(terrain.terrainPrimitive.positions[i * 3 + 1],
                        surface.dtm.data[i] - 100.0F);
    EXPECT_FLOAT_EQ(surface.dsm.data[5], 180.0F); // Analysis DSM was not edited.
}

TEST(MeshPipelineTest, OuterAndCourtyardWallsFaceTheirExteriorAndRoofsFaceUp)
{
    BuildingInstance building;
    building.buildingId = 7;
    building.projectedFootprint.outerRing = {{0,0}, {10,0}, {10,10}, {0,10}};
    building.projectedFootprint.holes = {{{3,3}, {3,7}, {7,7}, {7,3}}};
    building.representativeBaseElevation = 100;
    building.roofElevation = 112;
    BuildingCollection buildings;
    buildings.buildings.push_back(building);
    LocalSceneFrame frame;
    frame.elevationOrigin = 100;
    const auto mesh = BuildingMesher::generate(buildings, frame);
    ASSERT_EQ(mesh.emittedBuildingIds.size(), 1U);
    ASSERT_EQ(mesh.wallPrimitive.indices.size(), 48U);

    for (std::size_t face = 0; face < 16; ++face)
    {
        const auto& p = mesh.wallPrimitive.positions;
        const auto& ids = mesh.wallPrimitive.indices;
        auto a = ids[3*face]*3, b = ids[3*face+1]*3, c = ids[3*face+2]*3;
        const double ux=p[b]-p[a], uy=p[b+1]-p[a+1], uz=p[b+2]-p[a+2];
        const double vx=p[c]-p[a], vy=p[c+1]-p[a+1], vz=p[c+2]-p[a+2];
        const double nx=uy*vz-uz*vy, nz=ux*vy-uy*vx;
        const auto& normals = *mesh.wallPrimitive.normals;
        EXPECT_GT(nx*normals[a] + nz*normals[a+2], 0.0);
        const double cx=(p[a]+p[b]+p[c])/3.0, cz=(p[a+2]+p[b+2]+p[c+2])/3.0;
        const double awayFromCentre = nx*(cx-5.0) + nz*(cz+5.0);
        if (face < 8) EXPECT_GT(awayFromCentre, 0.0);
        else EXPECT_LT(awayFromCentre, 0.0); // Inner walls face courtyard.
    }

    double roofArea = 0;
    const auto& p = mesh.roofPrimitive.positions;
    const auto& ids = mesh.roofPrimitive.indices;
    for (std::size_t i=0; i<ids.size(); i+=3)
    {
        auto a=ids[i]*3, b=ids[i+1]*3, c=ids[i+2]*3;
        const double ny=(p[b+2]-p[a+2])*(p[c]-p[a]) -
                        (p[b]-p[a])*(p[c+2]-p[a+2]);
        EXPECT_GT(ny, 0.0);
        roofArea += 0.5*ny;
    }
    EXPECT_NEAR(roofArea, 84.0, 1e-5); // 100 m2 footprint minus 16 m2 courtyard.
}

TEST(MeshPipelineTest, BuildingMesherAssignsHeightBinnedMapflowColors)
{
    BuildingInstance lowRise;
    lowRise.buildingId = 1;
    lowRise.heightAboveGround = 8.0F;
    lowRise.representativeBaseElevation = 100.0F;
    lowRise.roofElevation = 108.0F;
    lowRise.projectedFootprint.outerRing = {{0,0}, {10,0}, {10,10}, {0,10}};

    BuildingInstance midRise;
    midRise.buildingId = 2;
    midRise.heightAboveGround = 25.0F;
    midRise.representativeBaseElevation = 100.0F;
    midRise.roofElevation = 125.0F;
    midRise.projectedFootprint.outerRing = {{20,0}, {30,0}, {30,10}, {20,10}};

    BuildingInstance highRise;
    highRise.buildingId = 3;
    highRise.heightAboveGround = 50.0F;
    highRise.representativeBaseElevation = 100.0F;
    highRise.roofElevation = 150.0F;
    highRise.projectedFootprint.outerRing = {{40,0}, {50,0}, {50,10}, {40,10}};

    BuildingCollection buildings;
    buildings.buildings = {lowRise, midRise, highRise};

    LocalSceneFrame frame;
    frame.elevationOrigin = 100.0;
    const auto mesh = BuildingMesher::generate(buildings, frame);

    ASSERT_TRUE(mesh.roofPrimitive.colors.has_value());
    ASSERT_TRUE(mesh.wallPrimitive.colors.has_value());
    EXPECT_EQ(mesh.roofPrimitive.colors->size(), (mesh.roofPrimitive.positions.size() / 3) * 4);
    EXPECT_EQ(mesh.wallPrimitive.colors->size(), (mesh.wallPrimitive.positions.size() / 3) * 4);

    // Assert wireframe edgePrimitive is populated with LINES topology
    EXPECT_EQ(mesh.edgePrimitive.topology, PrimitiveTopology::LINES);
    EXPECT_EQ(mesh.edgePrimitive.materialRole, MaterialRole::BUILDING_EDGE);
    ASSERT_TRUE(mesh.edgePrimitive.colors.has_value());
    EXPECT_FALSE(mesh.edgePrimitive.positions.empty());
    EXPECT_FALSE(mesh.edgePrimitive.indices.empty());
    EXPECT_EQ(mesh.edgePrimitive.indices.size() % 2, 0U);
    EXPECT_EQ(mesh.edgePrimitive.colors->size(), (mesh.edgePrimitive.positions.size() / 3) * 4);
    EXPECT_TRUE(mesh.edgePrimitive.localBounds.isInitialized);

    // Assert edge colors are sharp white with 0.90 alpha
    EXPECT_NEAR((*mesh.edgePrimitive.colors)[0], 1.00F, 1e-4F);
    EXPECT_NEAR((*mesh.edgePrimitive.colors)[1], 1.00F, 1e-4F);
    EXPECT_NEAR((*mesh.edgePrimitive.colors)[2], 1.00F, 1e-4F);
    EXPECT_NEAR((*mesh.edgePrimitive.colors)[3], 0.90F, 1e-4F);

    // Low-rise cyan with walls darkened by 35%.
    EXPECT_NEAR((*mesh.wallPrimitive.colors)[0], 0.00F, 1e-4F);
    EXPECT_NEAR((*mesh.wallPrimitive.colors)[1], 0.52F, 1e-4F);
    EXPECT_NEAR((*mesh.wallPrimitive.colors)[2], 0.6175F, 1e-4F);
    EXPECT_NEAR((*mesh.wallPrimitive.colors)[3], 1.0F, 1e-4F);

    EXPECT_NEAR((*mesh.roofPrimitive.colors)[0], 0.00F, 1e-4F);
    EXPECT_NEAR((*mesh.roofPrimitive.colors)[1], 0.80F, 1e-4F);
    EXPECT_NEAR((*mesh.roofPrimitive.colors)[2], 0.95F, 1e-4F);
    EXPECT_NEAR((*mesh.roofPrimitive.colors)[3], 1.0F, 1e-4F);

    // Mid-rise blue. Four edges give 16 wall vertices per building.
    std::size_t midRiseWallColorOffset = 16 * 4;
    EXPECT_NEAR((*mesh.wallPrimitive.colors)[midRiseWallColorOffset + 0], 0.065F, 1e-4F);
    EXPECT_NEAR((*mesh.wallPrimitive.colors)[midRiseWallColorOffset + 1], 0.1625F, 1e-4F);
    EXPECT_NEAR((*mesh.wallPrimitive.colors)[midRiseWallColorOffset + 2], 0.585F, 1e-4F);
    EXPECT_NEAR((*mesh.wallPrimitive.colors)[midRiseWallColorOffset + 3], 1.0F, 1e-4F);

    // High-rise red.
    std::size_t highRiseWallColorOffset = 32 * 4;
    EXPECT_NEAR((*mesh.wallPrimitive.colors)[highRiseWallColorOffset + 0], 0.65F, 1e-4F);
    EXPECT_NEAR((*mesh.wallPrimitive.colors)[highRiseWallColorOffset + 1], 0.0975F, 1e-4F);
    EXPECT_NEAR((*mesh.wallPrimitive.colors)[highRiseWallColorOffset + 2], 0.195F, 1e-4F);
    EXPECT_NEAR((*mesh.wallPrimitive.colors)[highRiseWallColorOffset + 3], 1.0F, 1e-4F);
}

TEST(MeshPipelineTest, MapflowPresentationAestheticTerrainAndBuildingColors)
{
    // 1. TerrainTextureComposer emits solid unlit dark grey (0.26f, 0.26f, 0.26f, 1.0f)
    const auto colors = TerrainTextureComposer::composeSolidTerrainColors(4);
    ASSERT_EQ(colors.size(), 16U);
    for (std::size_t i = 0; i < 4; ++i)
    {
        EXPECT_NEAR(colors[i * 4 + 0], 0.26F, 1e-5F);
        EXPECT_NEAR(colors[i * 4 + 1], 0.26F, 1e-5F);
        EXPECT_NEAR(colors[i * 4 + 2], 0.26F, 1e-5F);
        EXPECT_NEAR(colors[i * 4 + 3], 1.00F, 1e-5F);
    }

    // 2. TerrainMesher assigns solid unlit dark grey to terrainPrimitive.colors
    const auto metadata = makeProjectedMetadata(4, 4);
    const auto surface = makeSurface(4, 4, 100.0F, 0.0F);
    const auto frame = LocalFrameTransformer::create(metadata, surface);
    TerrainMeshConfig terrainConfig;
    terrainConfig.generateSkirt = false;
    const auto terrainMesh = TerrainMesher::generate(surface, metadata, frame, terrainConfig);
    ASSERT_TRUE(terrainMesh.terrainPrimitive.colors.has_value());
    const auto& tColors = *terrainMesh.terrainPrimitive.colors;
    ASSERT_EQ(tColors.size(), (terrainMesh.terrainPrimitive.positions.size() / 3) * 4);
    for (std::size_t i = 0; i < tColors.size(); i += 4)
    {
        EXPECT_NEAR(tColors[i + 0], 0.26F, 1e-5F);
        EXPECT_NEAR(tColors[i + 1], 0.26F, 1e-5F);
        EXPECT_NEAR(tColors[i + 2], 0.26F, 1e-5F);
        EXPECT_NEAR(tColors[i + 3], 1.00F, 1e-5F);
    }

    // 3. BuildingMesher absolute tier boundary checks (no scene maximum)
    BuildingInstance b14_5;
    b14_5.buildingId = 1;
    b14_5.heightAboveGround = 14.5F; // Low-rise (< 15m)
    b14_5.representativeBaseElevation = 100.0F;
    b14_5.roofElevation = 114.5F;
    b14_5.projectedFootprint.outerRing = {{0,0}, {10,0}, {10,10}, {0,10}};

    BuildingInstance b15_0;
    b15_0.buildingId = 2;
    b15_0.heightAboveGround = 15.0F; // Mid-rise (15m to 45m)
    b15_0.representativeBaseElevation = 100.0F;
    b15_0.roofElevation = 115.0F;
    b15_0.projectedFootprint.outerRing = {{20,0}, {30,0}, {30,10}, {20,10}};

    BuildingInstance b45_0;
    b45_0.buildingId = 3;
    b45_0.heightAboveGround = 45.0F; // Mid-rise (15m to 45m)
    b45_0.representativeBaseElevation = 100.0F;
    b45_0.roofElevation = 145.0F;
    b45_0.projectedFootprint.outerRing = {{40,0}, {50,0}, {50,10}, {40,10}};

    BuildingInstance b45_5;
    b45_5.buildingId = 4;
    b45_5.heightAboveGround = 45.5F; // High-rise (> 45m)
    b45_5.representativeBaseElevation = 100.0F;
    b45_5.roofElevation = 145.5F;
    b45_5.projectedFootprint.outerRing = {{60,0}, {70,0}, {70,10}, {60,10}};

    BuildingCollection buildings;
    buildings.buildings = {b14_5, b15_0, b45_0, b45_5};
    const auto bldgMesh = BuildingMesher::generate(buildings, frame);

    ASSERT_TRUE(bldgMesh.roofPrimitive.colors.has_value());
    ASSERT_TRUE(bldgMesh.wallPrimitive.colors.has_value());

    // Check roof and wall colors for each building
    // Building 1 (< 15m): Cyan (0.0, 0.8, 0.95), walls darkened by 0.65x
    std::size_t wallOff0 = 0 * 16 * 4;
    EXPECT_NEAR((*bldgMesh.wallPrimitive.colors)[wallOff0 + 0], 0.00F * 0.65F, 1e-4F);
    EXPECT_NEAR((*bldgMesh.wallPrimitive.colors)[wallOff0 + 1], 0.80F * 0.65F, 1e-4F);
    EXPECT_NEAR((*bldgMesh.wallPrimitive.colors)[wallOff0 + 2], 0.95F * 0.65F, 1e-4F);

    // Building 2 (15.0m): Deep Blue (0.1, 0.25, 0.9), walls darkened by 0.65x
    std::size_t wallOff1 = 1 * 16 * 4;
    EXPECT_NEAR((*bldgMesh.wallPrimitive.colors)[wallOff1 + 0], 0.10F * 0.65F, 1e-4F);
    EXPECT_NEAR((*bldgMesh.wallPrimitive.colors)[wallOff1 + 1], 0.25F * 0.65F, 1e-4F);
    EXPECT_NEAR((*bldgMesh.wallPrimitive.colors)[wallOff1 + 2], 0.90F * 0.65F, 1e-4F);

    // Building 3 (45.0m): Deep Blue (0.1, 0.25, 0.9), walls darkened by 0.65x
    std::size_t wallOff2 = 2 * 16 * 4;
    EXPECT_NEAR((*bldgMesh.wallPrimitive.colors)[wallOff2 + 0], 0.10F * 0.65F, 1e-4F);
    EXPECT_NEAR((*bldgMesh.wallPrimitive.colors)[wallOff2 + 1], 0.25F * 0.65F, 1e-4F);
    EXPECT_NEAR((*bldgMesh.wallPrimitive.colors)[wallOff2 + 2], 0.90F * 0.65F, 1e-4F);

    // Building 4 (> 45m): Hologram Red (1.0, 0.15, 0.3), walls darkened by 0.65x
    std::size_t wallOff3 = 3 * 16 * 4;
    EXPECT_NEAR((*bldgMesh.wallPrimitive.colors)[wallOff3 + 0], 1.00F * 0.65F, 1e-4F);
    EXPECT_NEAR((*bldgMesh.wallPrimitive.colors)[wallOff3 + 1], 0.15F * 0.65F, 1e-4F);
    EXPECT_NEAR((*bldgMesh.wallPrimitive.colors)[wallOff3 + 2], 0.30F * 0.65F, 1e-4F);
}

TEST(MeshPipelineTest, GltfPackagerPacksEdgeHighlightLinesAsUncompressedLinesMode)
{
    MeshPrimitive edgePrim;
    edgePrim.topology = PrimitiveTopology::LINES;
    edgePrim.materialRole = MaterialRole::BUILDING_EDGE;
    edgePrim.positions = {
        0.0F, 10.0F, 0.0F,
        10.0F, 10.0F, 0.0F};
    edgePrim.indices = {0, 1};
    edgePrim.colors = std::vector<float>{
        1.0F, 1.0F, 1.0F, 1.0F,
        1.0F, 1.0F, 1.0F, 1.0F};
    edgePrim.localBounds = {0.0, 10.0, 0.0, 10.0, 10.0, 0.0, true};

    SceneMesh scene;
    scene.edgePrimitive = edgePrim;
    scene.materials = {MaterialRole::BUILDING_EDGE};
    scene.sceneBounds = edgePrim.localBounds;

    const GlbBuildResult glb = GltfPackager::buildSceneToMemory(
        scene,
        {},
        1);
    ASSERT_FALSE(glb.compressedGlbByteBuffer.empty());

    tinygltf::TinyGLTF loader;
    tinygltf::Model model;
    std::string error;
    std::string warning;
    const bool loaded = loader.LoadBinaryFromMemory(
        &model,
        &error,
        &warning,
        glb.compressedGlbByteBuffer.data(),
        static_cast<unsigned int>(glb.compressedGlbByteBuffer.size()));

    ASSERT_TRUE(loaded) << error;
    ASSERT_EQ(model.meshes.size(), 1U);
    ASSERT_EQ(model.meshes[0].primitives.size(), 1U);

    const auto& prim = model.meshes[0].primitives[0];
    EXPECT_EQ(prim.mode, TINYGLTF_MODE_LINE); // Mode 1: LINE
    EXPECT_FALSE(prim.extensions.contains("KHR_draco_mesh_compression")); // Uncompressed!

    ASSERT_TRUE(prim.attributes.contains("POSITION"));
    ASSERT_TRUE(prim.attributes.contains("COLOR_0"));
    EXPECT_GE(prim.indices, 0);

    ASSERT_GE(prim.material, 0);
    EXPECT_EQ(model.materials[prim.material].name, "Building_Edge_Highlight");
}

TEST(MeshPipelineTest, CollinearVertexAlongStraightWallDoesNotEmitVerticalSeam)
{
    BuildingInstance building;
    building.buildingId = 42;
    building.heightAboveGround = 15.0F;
    building.representativeBaseElevation = 100.0F;
    building.roofElevation = 115.0F;
    // Outer ring with a collinear redundant vertex on the bottom wall (5, 0) between (0, 0) and (10, 0)
    // 5 vertices: (0, 0), (5, 0), (10, 0), (10, 10), (0, 10)
    building.projectedFootprint.outerRing = {
        {0.0, 0.0},
        {5.0, 0.0}, // Collinear turn angle ~ 0 degrees
        {10.0, 0.0},
        {10.0, 10.0},
        {0.0, 10.0}
    };

    BuildingCollection buildings;
    buildings.buildings = {building};
    LocalSceneFrame frame;
    frame.elevationOrigin = 100.0;

    const auto mesh = BuildingMesher::generate(buildings, frame);
    // Vertical seams only at the 4 true 90-degree corners, not at the collinear vertex (5, 0)
    // Count vertical lines (where x1 == x2 && z1 == z2 && y1 != y2)
    const auto& pos = mesh.edgePrimitive.positions;
    const auto& idx = mesh.edgePrimitive.indices;
    int verticalSeams = 0;
    for (std::size_t i = 0; i < idx.size(); i += 2)
    {
        uint32_t a = idx[i] * 3;
        uint32_t b = idx[i + 1] * 3;
        if (std::abs(pos[a] - pos[b]) < 1e-4F &&
            std::abs(pos[a + 2] - pos[b + 2]) < 1e-4F &&
            std::abs(pos[a + 1] - pos[b + 1]) > 0.1F)
        {
            ++verticalSeams;
            // Ensure no vertical seam was emitted at x = 5.0
            EXPECT_FALSE(std::abs(pos[a] - 5.0F) < 1e-3F && std::abs(pos[a + 2] - 0.0F) < 1e-3F);
        }
    }
    // Exactly 4 vertical seams for the 4 corners
    EXPECT_EQ(verticalSeams, 4);
}

// --- Phase 2: render-only textures, UVs and materials -----------------------

using depthwizard::FacadeAtlasGenerator;

BuildingInstance boxBuilding(uint32_t id, double left, double top, double right, double bottom,
                             float height)
{
    // Projected rectangle with pixel-edge footprint on a 1 m north-up raster
    // whose origin is (0, 0): column = easting, row = -northing.
    BuildingInstance building;
    building.buildingId = id;
    building.heightAboveGround = height;
    building.representativeBaseElevation = 100.0F;
    building.roofElevation = 100.0F + height;
    building.pixelFootprint.outerRing = {{left, top}, {right, top}, {right, bottom}, {left, bottom}};
    building.projectedFootprint.outerRing = {{left, -top}, {right, -top}, {right, -bottom}, {left, -bottom}};
    return building;
}

SpatialMetadata unitMetadata(int width, int height)
{
    SpatialMetadata metadata = makeProjectedMetadata(width, height, 1.0, -1.0);
    metadata.geoTransform[0] = 0.0;
    metadata.geoTransform[3] = 0.0;
    return metadata;
}

uint8_t cell(const RasterGrid<uint8_t>& mask, int column, int row)
{
    return mask.data[static_cast<std::size_t>(row) * mask.width + column];
}

int countSet(const RasterGrid<uint8_t>& mask)
{
    int count = 0;
    for (uint8_t value : mask.data) count += value != 0;
    return count;
}

TEST(MeshPipelineTest, ExactFootprintMaskCoversOnlyPixelCentresInside)
{
    const SpatialMetadata metadata = unitMetadata(64, 64);
    BuildingCollection buildings;
    buildings.buildings.push_back(boxBuilding(1, 20, 20, 40, 40, 10.0F));
    buildings.buildings[0].pixelFootprint.holes = {{{28, 28}, {28, 32}, {32, 32}, {32, 28}}};

    const RasterGrid<uint8_t> exact = TerrainSurfaceComposer::buildExactFootprintMask(buildings, metadata);
    EXPECT_EQ(countSet(exact), 20 * 20 - 4 * 4);
    EXPECT_EQ(cell(exact, 20, 20), 1);
    EXPECT_EQ(cell(exact, 39, 39), 1);
    EXPECT_EQ(cell(exact, 40, 30), 0); // Pixel 40 starts at the footprint's right edge.
    EXPECT_EQ(cell(exact, 19, 30), 0);
    EXPECT_EQ(cell(exact, 30, 30), 0); // Courtyard.

    // The polygon-fill mask grows by its boundary pixels even at 0 m clearance.
    buildings.buildings[0].pixelFootprint.holes.clear();
    EXPECT_GT(countSet(TerrainSurfaceComposer::buildAcceptedBuildingMask(buildings, metadata, 0.0F)), 400);

    // Fractional edges: centres 10.5, 11.5 and 12.5 lie inside [10.4, 12.6].
    BuildingCollection fractional;
    fractional.buildings.push_back(boxBuilding(2, 10.4, 10.4, 12.6, 12.6, 5.0F));
    EXPECT_EQ(countSet(TerrainSurfaceComposer::buildExactFootprintMask(fractional, metadata)), 9);
}

TEST(MeshPipelineTest, ConcealedRoofHaloIsMetricAndLeavesRoadsOutsideItUntouched)
{
    constexpr int n = 64;
    cv::Mat optical(n, n, CV_8UC3, cv::Scalar(120, 120, 120));
    optical(cv::Rect(20, 20, 20, 20)).setTo(cv::Scalar(10, 10, 200));
    optical(cv::Rect(0, 30, 20, 1)).setTo(cv::Scalar(40, 200, 40)); // Road marking up to the wall.
    TextureAsset original;
    original.mimeType = "image/png";
    ASSERT_TRUE(cv::imencode(".png", optical, original.bytes));

    BuildingCollection buildings;
    buildings.buildings.push_back(boxBuilding(1, 20, 20, 40, 40, 10.0F));

    const auto repair = [&](double pixelSize, float halo)
    {
        SpatialMetadata metadata = unitMetadata(n, n);
        metadata.geoTransform[1] = pixelSize;
        metadata.geoTransform[5] = -pixelSize;
        const TextureAsset repaired = TerrainTextureComposer::concealAcceptedRoofs(
            original, TerrainSurfaceComposer::buildExactFootprintMask(buildings, metadata), metadata, halo);
        EXPECT_EQ(repaired.semantic, TextureSemantic::OPTICAL_GROUND_REPAIRED);
        return cv::imdecode(repaired.bytes, cv::IMREAD_COLOR);
    };

    // No halo: the roof is inpainted and the marking touching the wall survives.
    cv::Mat noHalo = repair(1.0, 0.0F);
    EXPECT_NE(noHalo.at<cv::Vec3b>(30, 30), cv::Vec3b(10, 10, 200));
    EXPECT_EQ(noHalo.at<cv::Vec3b>(30, 19), cv::Vec3b(40, 200, 40));

    // 2 m at 1 m/pixel repairs two pixels around the roof, and nothing beyond.
    cv::Mat twoMetres = repair(1.0, 2.0F);
    EXPECT_NE(twoMetres.at<cv::Vec3b>(30, 18), cv::Vec3b(40, 200, 40));
    EXPECT_EQ(twoMetres.at<cv::Vec3b>(30, 17), cv::Vec3b(40, 200, 40));

    // 1 m at 10 m/pixel rounds to no halo (it was always 2-3 pixels before).
    cv::Mat coarse = repair(10.0, 1.0F);
    EXPECT_EQ(coarse.at<cv::Vec3b>(30, 19), cv::Vec3b(40, 200, 40));
}

TEST(MeshPipelineTest, FacadeAtlasIsDeterministicBandedAndRepeatable)
{
    const TextureAsset atlas = FacadeAtlasGenerator::generateAtlasPng(false);
    EXPECT_EQ(atlas.bytes, FacadeAtlasGenerator::generateAtlasPng(false).bytes);
    EXPECT_EQ(atlas.semantic, TextureSemantic::FACADE_ATLAS);
    EXPECT_EQ(atlas.mimeType, "image/png");
    EXPECT_EQ(atlas.wrapS, TextureWrap::REPEAT);
    EXPECT_EQ(atlas.wrapT, TextureWrap::CLAMP_TO_EDGE);

    const cv::Mat image = cv::imdecode(atlas.bytes, cv::IMREAD_COLOR);
    ASSERT_EQ(image.cols, FacadeAtlasGenerator::kAtlasWidth);
    ASSERT_EQ(image.rows, FacadeAtlasGenerator::kAtlasHeight);
    for (int band = 0; band < FacadeAtlasGenerator::kVariantCount; ++band)
    {
        // Darker ground floor at the bottom of every band.
        const int bottom = (band + 1) * FacadeAtlasGenerator::kBandHeight;
        const double ground = cv::mean(image(cv::Rect(0, bottom - FacadeAtlasGenerator::kFloorPixels,
                                                      image.cols, FacadeAtlasGenerator::kFloorPixels)))[1];
        const double upper = cv::mean(image(cv::Rect(0, bottom - 6 * FacadeAtlasGenerator::kFloorPixels,
                                                     image.cols, FacadeAtlasGenerator::kFloorPixels)))[1];
        EXPECT_LT(ground, upper) << "band " << band;
        // Seamless horizontal repeat: the first and last columns hold the same pattern.
        EXPECT_LT(cv::norm(image.col(0).rowRange(bottom - 256, bottom), image.col(image.cols - 1).rowRange(bottom - 256, bottom),
                           cv::NORM_L1) / 256.0, 12.0);
    }

    // Neutral atlas: plain concrete in every band.
    const cv::Mat neutral = cv::imdecode(FacadeAtlasGenerator::generateAtlasPng(true).bytes, cv::IMREAD_COLOR);
    EXPECT_NE(atlas.bytes, FacadeAtlasGenerator::generateAtlasPng(true).bytes);
    cv::Mat channels[3];
    cv::split(neutral, channels);
    EXPECT_LT(cv::norm(channels[0], channels[2], cv::NORM_INF), 1.0); // Grey only
}

TEST(MeshPipelineTest, FacadeFloorsVariantsAndUvMath)
{
    EXPECT_EQ(FacadeAtlasGenerator::presentationFloors(15.5), 5);
    EXPECT_EQ(FacadeAtlasGenerator::presentationFloors(3.1 * 2.6), 3);
    EXPECT_EQ(FacadeAtlasGenerator::presentationFloors(0.5), 1);
    EXPECT_EQ(FacadeAtlasGenerator::presentationFloors(500.0), FacadeAtlasGenerator::kFloorsPerBand);
    EXPECT_EQ(FacadeAtlasGenerator::presentationFloors(std::numeric_limits<double>::quiet_NaN()), 1);

    // Stable hash: repeatable, covers every variant, not id % 4.
    std::array<int, FacadeAtlasGenerator::kVariantCount> histogram{};
    bool differsFromModulo = false;
    for (uint32_t id = 1; id <= 400; ++id)
    {
        const int variant = FacadeAtlasGenerator::variantFor(id, false);
        ASSERT_EQ(variant, FacadeAtlasGenerator::variantFor(id, false));
        ++histogram[variant];
        differsFromModulo = differsFromModulo || variant != static_cast<int>(id % 4);
        EXPECT_EQ(FacadeAtlasGenerator::variantFor(id, true), FacadeAtlasGenerator::kNeutralVariant);
    }
    EXPECT_TRUE(differsFromModulo);
    for (int count : histogram) EXPECT_GT(count, 60);

    // u: one tile per 24 m; a segment keeps its length and continues the phase.
    const auto [u0, u1] = FacadeAtlasGenerator::segmentU(30.0, 6.0);
    EXPECT_FLOAT_EQ(u0, 0.25F);
    EXPECT_FLOAT_EQ(u1, 0.50F);
    const auto [u2, u3] = FacadeAtlasGenerator::segmentU(36.0, 30.0);
    EXPECT_FLOAT_EQ(u2, u1);
    EXPECT_FLOAT_EQ(u3 - u2, 30.0F / 24.0F);

    // v: ground at the band bottom, one atlas floor per presentation floor,
    // clamped inside the band above the top floor.
    constexpr double atlasHeight = FacadeAtlasGenerator::kAtlasHeight;
    for (int variant = 0; variant < FacadeAtlasGenerator::kVariantCount; ++variant)
    {
        const double bottom = (variant + 1) * FacadeAtlasGenerator::kBandHeight;
        EXPECT_FLOAT_EQ(FacadeAtlasGenerator::v(variant, 5, 15.5, 0.0),
                        (bottom - FacadeAtlasGenerator::kBandMarginPixels) / atlasHeight);
        EXPECT_FLOAT_EQ(FacadeAtlasGenerator::v(variant, 5, 15.5, 15.5),
                        (bottom - 5 * FacadeAtlasGenerator::kFloorPixels) / atlasHeight);
        EXPECT_FLOAT_EQ(FacadeAtlasGenerator::v(variant, 5, 15.5, 6.2),
                        (bottom - 2 * FacadeAtlasGenerator::kFloorPixels) / atlasHeight);
        const float top = FacadeAtlasGenerator::v(variant, 32, 99.2, 1000.0);
        EXPECT_GE(top * atlasHeight, variant * FacadeAtlasGenerator::kBandHeight + FacadeAtlasGenerator::kBandMarginPixels - 1e-3);
        EXPECT_LE(FacadeAtlasGenerator::v(variant, 5, 15.5, -0.5) * atlasHeight, bottom);
    }
}

// Shared by the roof UV tests: a sheared, rotated geotransform exercises
// every term of the inverse affine transform.
SpatialMetadata shearedMetadata()
{
    SpatialMetadata metadata = makeProjectedMetadata(100, 80, 0.5, -0.5);
    metadata.geoTransform = {500000.0, 0.5, 0.1, 2000000.0, 0.05, -0.5};
    return metadata;
}

ProjectedPoint project(const SpatialMetadata& metadata, double column, double row)
{
    const auto& gt = metadata.geoTransform;
    return {gt[0] + column * gt[1] + row * gt[2], gt[3] + column * gt[4] + row * gt[5]};
}

std::pair<double, double> pixelOf(const SpatialMetadata& metadata, const LocalSceneFrame& frame,
                                  double x, double z)
{
    const auto& gt = metadata.geoTransform;
    const double dx = x + frame.projectedOriginX - gt[0];
    const double dy = -z + frame.projectedOriginY - gt[3];
    const double det = gt[1] * gt[5] - gt[2] * gt[4];
    return {(dx * gt[5] - dy * gt[2]) / det, (dy * gt[1] - dx * gt[4]) / det};
}

DecomposedBuildingBlock pixelBlock(const SpatialMetadata& metadata, RoofType type, double left, double top,
                                   double right, double bottom, float eave, float ridge)
{
    DecomposedBuildingBlock block;
    block.pixelCorners = {{{left, top}, {right, top}, {right, bottom}, {left, bottom}}};
    for (std::size_t corner = 0; corner < 4; ++corner)
        block.projectedCorners[corner] = project(metadata, block.pixelCorners[corner].column, block.pixelCorners[corner].row);
    block.roof.type = type;
    block.roof.eaveHeightAboveGround = eave;
    block.roof.ridgeHeightAboveGround = ridge;
    const double middle = 0.5 * (top + bottom);
    block.roof.ridgeStartProjected = project(metadata, left, middle);
    block.roof.ridgeEndProjected = project(metadata, right, middle);
    return block;
}

TEST(MeshPipelineTest, RoofUvsAreTheExactInverseAffineIncludingRidgeVertices)
{
    const SpatialMetadata metadata = shearedMetadata();
    LocalSceneFrame frame;
    const ProjectedPoint origin = project(metadata, 50, 40);
    frame.projectedOriginX = origin.easting;
    frame.projectedOriginY = origin.northing;
    frame.elevationOrigin = 100.0;

    BuildingCollection buildings;
    for (const auto& [id, type, left] : std::vector<std::tuple<uint32_t, RoofType, double>>{
             {1, RoofType::GABLE, 10.0}, {2, RoofType::HIP, 55.0}})
    {
        BuildingInstance building;
        building.buildingId = id;
        building.heightAboveGround = 12.0F;
        building.representativeBaseElevation = 100.0F;
        building.roofElevation = 112.0F;
        building.blocks.push_back(pixelBlock(metadata, type, left, 20.0, left + 30.0, 40.0, 8.0F, 12.0F));
        for (const PixelPoint& corner : building.blocks[0].pixelCorners)
            building.projectedFootprint.outerRing.push_back(project(metadata, corner.column, corner.row));
        buildings.buildings.push_back(building);
    }

    BuildingMeshConfig config;
    config.generateRoofUVs = true;
    config.generateWallUVs = true;
    const BuildingMesh mesh = BuildingMesher::generate(buildings, frame, config, &metadata);
    ASSERT_TRUE(mesh.roofPrimitive.uvs.has_value());
    ASSERT_EQ(mesh.roofPrimitive.uvs->size(), mesh.roofPrimitive.positions.size() / 3 * 2);
    EXPECT_EQ(mesh.roofUvOutOfBoundsVertexCount, 0U);

    bool foundGableRidgeStart = false;
    for (std::size_t vertex = 0; vertex < mesh.roofPrimitive.positions.size() / 3; ++vertex)
    {
        const auto [column, row] = pixelOf(metadata, frame, mesh.roofPrimitive.positions[vertex * 3],
                                           mesh.roofPrimitive.positions[vertex * 3 + 2]);
        const float u = (*mesh.roofPrimitive.uvs)[vertex * 2];
        const float v = (*mesh.roofPrimitive.uvs)[vertex * 2 + 1];
        // glTF top-left UV origin: v grows with the row (no 1 - row/height flip).
        EXPECT_NEAR(u, column / 100.0, 1e-5);
        EXPECT_NEAR(v, row / 80.0, 1e-5);
        foundGableRidgeStart = foundGableRidgeStart ||
            (std::abs(u - 0.1F) < 1e-5F && std::abs(v - 0.375F) < 1e-5F &&
             mesh.roofPrimitive.positions[vertex * 3 + 1] > 11.9F);
    }
    EXPECT_TRUE(foundGableRidgeStart); // Gable ridge end at pixel (10, 30), 12 m up.
}

TEST(MeshPipelineTest, RoofAndTerrainShareOneImageConvention)
{
    const SpatialMetadata metadata = shearedMetadata();
    GeoreferencedSurfaceBundle surface = makeSurface(100, 80, 100.0F, 0.0F);
    surface.spatialMetadata = metadata;
    LocalSceneFrame frame;
    frame.projectedOriginX = metadata.geoTransform[0];
    frame.projectedOriginY = metadata.geoTransform[3];
    frame.elevationOrigin = 100.0;

    RasterGrid<uint8_t> noBuildings;
    noBuildings.width = 100;
    noBuildings.height = 80;
    noBuildings.data.assign(100 * 80, 0);
    const TerrainMesh terrain = TerrainMesher::generate(surface, noBuildings, metadata, frame, TerrainMeshConfig());
    ASSERT_TRUE(terrain.terrainPrimitive.uvs.has_value());
    std::size_t checked = 0;
    for (std::size_t vertex = 0; vertex < terrain.terrainPrimitive.positions.size() / 3; ++vertex)
    {
        const float u = (*terrain.terrainPrimitive.uvs)[vertex * 2];
        const float v = (*terrain.terrainPrimitive.uvs)[vertex * 2 + 1];
        if (u == 0.5F && v == 0.5F) continue; // Skirt centre
        const auto [column, row] = pixelOf(metadata, frame, terrain.terrainPrimitive.positions[vertex * 3],
                                           terrain.terrainPrimitive.positions[vertex * 3 + 2]);
        EXPECT_NEAR(u, column / 100.0, 1e-5);
        EXPECT_NEAR(v, row / 80.0, 1e-5);
        ++checked;
    }
    EXPECT_GT(checked, 100U);
}

TEST(MeshPipelineTest, RoofVerticesOutsideTheImageAreReportedNotClamped)
{
    const SpatialMetadata metadata = unitMetadata(64, 64);
    BuildingCollection buildings;
    buildings.buildings.push_back(boxBuilding(1, 50, 10, 70, 30, 10.0F)); // Ends at column 70 of 64.
    LocalSceneFrame frame;
    frame.elevationOrigin = 100.0;
    BuildingMeshConfig config;
    config.generateRoofUVs = true;
    const BuildingMesh mesh = BuildingMesher::generate(buildings, frame, config, &metadata);
    EXPECT_GT(mesh.roofUvOutOfBoundsVertexCount, 0U);
    EXPECT_GT(*std::max_element(mesh.roofPrimitive.uvs->begin(), mesh.roofPrimitive.uvs->end()), 1.05F);

    BuildingMeshConfig withoutMetadata;
    withoutMetadata.generateRoofUVs = true;
    EXPECT_THROW(BuildingMesher::generate(buildings, frame, withoutMetadata, nullptr), std::invalid_argument);
}

TEST(MeshPipelineTest, Lod1WallUvsFollowThePerimeterAndPresentationFloors)
{
    const SpatialMetadata metadata = unitMetadata(64, 64);
    BuildingCollection buildings;
    buildings.buildings.push_back(boxBuilding(7, 10, 10, 40, 22, 15.5F)); // 30 m x 12 m, 5 floors
    LocalSceneFrame frame;
    frame.elevationOrigin = 100.0;
    BuildingMeshConfig config;
    config.generateWallUVs = true;
    const BuildingMesh mesh = BuildingMesher::generate(buildings, frame, config, &metadata);
    ASSERT_TRUE(mesh.wallPrimitive.uvs.has_value());
    const auto& positions = mesh.wallPrimitive.positions;
    const auto& uvs = *mesh.wallPrimitive.uvs;
    const std::size_t quads = positions.size() / 12;
    ASSERT_EQ(quads, 4U);

    const int variant = FacadeAtlasGenerator::variantFor(7, false);
    const float ground = FacadeAtlasGenerator::v(variant, 5, 15.5, -0.5);
    const float top = FacadeAtlasGenerator::v(variant, 5, 15.5, 15.5);
    EXPECT_FLOAT_EQ(top, ((variant + 1) * 1024.0F - 5 * 32.0F) / 4096.0F);
    double perimeter = 0.0;
    for (std::size_t quad = 0; quad < quads; ++quad)
    {
        // Vertex order per quad: base A, roof A, roof B, base B.
        const std::size_t first = quad * 4;
        const auto uv = [&](std::size_t vertex, int axis) { return uvs[(first + vertex) * 2 + axis]; };
        const double length = std::hypot(positions[(first + 2) * 3] - positions[(first + 1) * 3],
                                         positions[(first + 2) * 3 + 2] - positions[(first + 1) * 3 + 2]);
        EXPECT_FLOAT_EQ(uv(0, 1), ground);
        EXPECT_FLOAT_EQ(uv(1, 1), top);
        EXPECT_FLOAT_EQ(uv(2, 1), top);
        EXPECT_NEAR(uv(2, 0) - uv(1, 0), length / 24.0, 1e-5);
        const double expectedStart = perimeter / 24.0 - std::floor(perimeter / 24.0);
        EXPECT_NEAR(uv(0, 0), expectedStart, 1e-5); // Pattern continues around the corner.
        perimeter += length;
    }
    EXPECT_NEAR(perimeter, 84.0, 1e-4);
}

TEST(MeshPipelineTest, Lod2WallAndGableUvsAreDistinctContinuousAndFloorAligned)
{
    const SpatialMetadata metadata = unitMetadata(64, 64);
    LocalSceneFrame frame;
    frame.elevationOrigin = 100.0;

    // A: 20 x 10 m gable (eave 6 m, ridge 9 m). B: flat, 12 m, on A's north side.
    BuildingInstance building = boxBuilding(11, 10, 30, 30, 40, 12.0F);
    building.projectedFootprint.outerRing = {{10, -20}, {30, -20}, {30, -40}, {10, -40}};
    building.blocks.push_back(pixelBlock(metadata, RoofType::GABLE, 10, 30, 30, 40, 6.0F, 9.0F));
    building.blocks.push_back(pixelBlock(metadata, RoofType::FLAT, 10, 20, 30, 30, 12.0F, 12.0F));
    BuildingCollection buildings;
    buildings.buildings.push_back(building);

    BuildingMeshConfig config;
    config.flatPresentation = true;
    config.generateWallUVs = true;
    const BuildingMesh mesh = BuildingMesher::generate(buildings, frame, config, &metadata);
    ASSERT_TRUE(mesh.wallPrimitive.uvs.has_value());
    const auto& positions = mesh.wallPrimitive.positions;
    const auto& normals = *mesh.wallPrimitive.normals;
    const auto& uvs = *mesh.wallPrimitive.uvs;
    const std::size_t vertices = positions.size() / 3;
    const int variant = FacadeAtlasGenerator::variantFor(11, false);

    // Regression: every corner used to receive the third corner's UV.
    for (std::size_t triangle = 0; triangle < vertices / 3; ++triangle)
    {
        const std::size_t a = triangle * 3;
        const bool allEqual = uvs[a * 2] == uvs[(a + 1) * 2] && uvs[a * 2] == uvs[(a + 2) * 2] &&
                              uvs[a * 2 + 1] == uvs[(a + 1) * 2 + 1] && uvs[a * 2 + 1] == uvs[(a + 2) * 2 + 1];
        EXPECT_FALSE(allEqual) << "triangle " << triangle;
    }

    // B's setback wall faces A across the shared edge (local z = 30) and starts
    // at A's 6 m eave: its base v is two of B's four floors up, not the ground floor.
    const float setbackBase = FacadeAtlasGenerator::v(variant, 4, 12.0, 6.0);
    EXPECT_FLOAT_EQ(setbackBase, ((variant + 1) * 1024.0F - 2 * 32.0F) / 4096.0F);
    bool foundSetback = false;
    std::vector<float> gableEaveU;
    std::vector<float> wallTopU;
    for (std::size_t vertex = 0; vertex < vertices; ++vertex)
    {
        const float y = positions[vertex * 3 + 1];
        const float nx = normals[vertex * 3];
        const float nz = normals[vertex * 3 + 2];
        if (std::abs(y - 6.0F) < 1e-4F && std::abs(nz) > 0.99F &&
            std::abs(positions[vertex * 3 + 2] - 30.0F) < 1e-3F)
        {
            EXPECT_FLOAT_EQ(uvs[vertex * 2 + 1], setbackBase);
            foundSetback = true;
        }
        // A's east end (x = 30, normal +X): gable eave vertices and wall-top vertices.
        if (nx > 0.99F && positions[vertex * 3] > 29.999F && positions[vertex * 3 + 2] > 30.0F - 1e-3F)
        {
            if (std::abs(y - 6.0F) < 1e-4F)
            {
                EXPECT_FLOAT_EQ(uvs[vertex * 2 + 1], FacadeAtlasGenerator::v(variant, 2, 6.0, 6.0));
                gableEaveU.push_back(uvs[vertex * 2]);
            }
            if (std::abs(y - 9.0F) < 1e-4F)
                EXPECT_FLOAT_EQ(uvs[vertex * 2 + 1], FacadeAtlasGenerator::v(variant, 2, 6.0, 9.0));
        }
    }
    EXPECT_TRUE(foundSetback);
    // Gable eave u values coincide with the wall below on the same edge.
    ASSERT_FALSE(gableEaveU.empty());
    std::sort(gableEaveU.begin(), gableEaveU.end());
    gableEaveU.erase(std::unique(gableEaveU.begin(), gableEaveU.end(),
                                 [](float l, float r) { return std::abs(l - r) < 1e-6F; }), gableEaveU.end());
    EXPECT_EQ(gableEaveU.size(), 2U);
    EXPECT_NEAR(gableEaveU[1] - gableEaveU[0], 10.0 / 24.0, 1e-5);
}

TEST(MeshPipelineTest, VertexColoursAreOptionalAndNeverChangeGeometry)
{
    const SpatialMetadata metadata = unitMetadata(64, 64);
    BuildingCollection buildings;
    buildings.buildings.push_back(boxBuilding(3, 10, 10, 30, 30, 20.0F));
    LocalSceneFrame frame;
    frame.elevationOrigin = 100.0;

    BuildingMeshConfig coloured;
    BuildingMeshConfig plain;
    plain.generateVertexColors = false;
    plain.generateRoofUVs = true;
    plain.generateWallUVs = true;
    const BuildingMesh a = BuildingMesher::generate(buildings, frame, coloured, &metadata);
    const BuildingMesh b = BuildingMesher::generate(buildings, frame, plain, &metadata);
    EXPECT_TRUE(a.roofPrimitive.colors.has_value());
    EXPECT_FALSE(b.roofPrimitive.colors.has_value());
    EXPECT_FALSE(b.wallPrimitive.colors.has_value());
    EXPECT_EQ(a.roofPrimitive.positions, b.roofPrimitive.positions);
    EXPECT_EQ(a.wallPrimitive.positions, b.wallPrimitive.positions);
    EXPECT_EQ(a.roofPrimitive.indices, b.roofPrimitive.indices);
    EXPECT_EQ(a.wallPrimitive.featureIds, b.wallPrimitive.featureIds);
}

MeshPrimitive texturedTriangle(MaterialRole role)
{
    MeshPrimitive primitive;
    primitive.positions = {0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F};
    primitive.normals = std::vector<float>{0.0F, 1.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 1.0F, 0.0F};
    primitive.uvs = std::vector<float>{0.0F, 0.0F, 2.5F, 0.0F, 0.0F, 0.75F};
    primitive.indices = {0, 1, 2};
    primitive.materialRole = role;
    return primitive;
}

TEST(MeshPipelineTest, GltfPackagerBindsTexturesSamplersAndRejectsUnboundRoles)
{
    SceneMesh scene;
    for (int index = 0; index < 3; ++index)
    {
        TextureAsset asset;
        asset.mimeType = "image/png";
        ASSERT_TRUE(cv::imencode(".png", cv::Mat(8, 8, CV_8UC3, cv::Scalar(40 * index, 60, 70)), asset.bytes));
        scene.textures.push_back(asset);
    }
    scene.textures[0].semantic = TextureSemantic::OPTICAL_GROUND_REPAIRED;
    scene.textures[1].semantic = TextureSemantic::OPTICAL_ORIGINAL;
    scene.textures[2] = FacadeAtlasGenerator::generateAtlasPng(false);
    scene.materialDescriptors = depthwizard::presentation::orthophotoMaterials(0, 1, 2);

    std::vector<CompressedPrimitive> primitives;
    for (MaterialRole role : {MaterialRole::TERRAIN_TEXTURE, MaterialRole::BUILDING_ROOF, MaterialRole::BUILDING_WALL})
    {
        primitives.push_back(DracoCompressor::compress(texturedTriangle(role)));
        ASSERT_TRUE(primitives.back().success);
    }
    const GlbBuildResult result = GltfPackager::buildSceneToMemory(scene, primitives, 1);
    ASSERT_FALSE(result.compressedGlbByteBuffer.empty());
    const tinygltf::Model model = loadGlb(result.compressedGlbByteBuffer);

    ASSERT_EQ(model.samplers.size(), 3U);
    EXPECT_EQ(model.samplers[0].wrapS, TINYGLTF_TEXTURE_WRAP_CLAMP_TO_EDGE);
    EXPECT_EQ(model.samplers[1].wrapT, TINYGLTF_TEXTURE_WRAP_CLAMP_TO_EDGE);
    EXPECT_EQ(model.samplers[2].wrapS, TINYGLTF_TEXTURE_WRAP_REPEAT);
    EXPECT_EQ(model.samplers[2].wrapT, TINYGLTF_TEXTURE_WRAP_CLAMP_TO_EDGE);
    ASSERT_EQ(model.meshes[0].primitives.size(), 3U);
    for (int index = 0; index < 3; ++index)
    {
        const tinygltf::Primitive& primitive = model.meshes[0].primitives[index];
        EXPECT_EQ(model.materials[primitive.material].pbrMetallicRoughness.baseColorTexture.index, index);
        // Draco preserves TEXCOORD_0, including the repeating u = 2.5.
        const std::vector<float> uv = decodeDracoAttribute(model, primitive, "TEXCOORD_0");
        ASSERT_EQ(uv.size(), 6U);
        EXPECT_NEAR(uv[2], 2.5F, 1e-3F);
        EXPECT_NEAR(uv[5], 0.75F, 1e-3F);
    }
    // No material is unlit, so the extension is not declared.
    EXPECT_EQ(std::count(model.extensionsUsed.begin(), model.extensionsUsed.end(), "KHR_materials_unlit"), 0);

    // A primitive whose role has no material is an error, never material 0.
    SceneMesh missingWall = scene;
    missingWall.materialDescriptors.pop_back();
    const GlbBuildResult unbound = GltfPackager::buildSceneToMemory(missingWall, primitives, 1);
    EXPECT_TRUE(unbound.compressedGlbByteBuffer.empty());
    EXPECT_FALSE(unbound.geometryWarnings.empty());

    SceneMesh badIndex = scene;
    badIndex.materialDescriptors[1].textureIndex = 9;
    EXPECT_TRUE(GltfPackager::buildSceneToMemory(badIndex, primitives, 1).compressedGlbByteBuffer.empty());
}

TEST(MeshPipelineTest, MaterialBindingRulesRejectCrossedTextures)
{
    SceneMesh scene;
    scene.terrainPrimitive = texturedTriangle(MaterialRole::TERRAIN_TEXTURE);
    scene.roofPrimitive = texturedTriangle(MaterialRole::BUILDING_ROOF);
    scene.wallPrimitive = texturedTriangle(MaterialRole::BUILDING_WALL);
    for (TextureSemantic semantic : {TextureSemantic::OPTICAL_GROUND_REPAIRED, TextureSemantic::OPTICAL_ORIGINAL,
                                     TextureSemantic::FACADE_ATLAS})
    {
        TextureAsset asset;
        asset.semantic = semantic;
        scene.textures.push_back(asset);
    }
    scene.materialDescriptors = depthwizard::presentation::orthophotoMaterials(0, 1, 2);
    EXPECT_EQ(depthwizard::presentation::bindingProblem(scene), "");

    SceneMesh crossed = scene;
    crossed.materialDescriptors = depthwizard::presentation::orthophotoMaterials(1, 0, 2);
    crossed.materialDescriptors[0].textureSemantic = TextureSemantic::OPTICAL_ORIGINAL;
    crossed.materialDescriptors[1].textureSemantic = TextureSemantic::OPTICAL_GROUND_REPAIRED;
    EXPECT_NE(depthwizard::presentation::bindingProblem(crossed), "");

    SceneMesh noUvs = scene;
    noUvs.roofPrimitive.uvs.reset();
    EXPECT_NE(depthwizard::presentation::bindingProblem(noUvs), "");

    SceneMesh duplicate = scene;
    duplicate.materialDescriptors.push_back(duplicate.materialDescriptors[2]);
    EXPECT_NE(depthwizard::presentation::bindingProblem(duplicate), "");
}

} // namespace
