#include <gtest/gtest.h>

#include "CompressionLib/DracoCompressor.h"
#include "FileGenerators/GltfPackager.h"
#include "MeshMapping/BuildingMesher.h"
#include "MeshMapping/TerrainMesher.h"
#include "MeshMapping/TerrainSurfaceComposer.h"
#include "MeshMapping/TerrainTextureComposer.h"
#include <opencv2/imgcodecs.hpp>
#include "TestGridSupport.h"
#include "BuildingReconstructionTestSupport.h"
#include "tiny_gltf.h"

#include <cstdint>
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
} // namespace
