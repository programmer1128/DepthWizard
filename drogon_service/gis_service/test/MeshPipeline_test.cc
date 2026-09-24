#include <gtest/gtest.h>

#include "CompressionLib/DracoCompressor.h"
#include "FileGenerators/GltfPackager.h"
#include "MeshMapping/BuildingMesher.h"
#include "MeshMapping/TerrainMesher.h"
#include "MeshMapping/TerrainSurfaceComposer.h"
#include "TestGridSupport.h"
#include "tiny_gltf.h"

#include <cstdint>
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
    EXPECT_TRUE(model.materials[0].extensions.contains(
        "KHR_materials_unlit"));
}

TEST(MeshPipelineTest, BuildingPrimitivesAreUntexturedUnlitAndSeparateFromTerrain)
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

    const tinygltf::Primitive& terrain = model.meshes[0].primitives[0];
    const tinygltf::Primitive& roof = model.meshes[0].primitives[1];
    const tinygltf::Primitive& wall = model.meshes[0].primitives[2];

    EXPECT_TRUE(terrain.attributes.contains("TEXCOORD_0"));
    EXPECT_FALSE(roof.attributes.contains("TEXCOORD_0"));
    EXPECT_FALSE(wall.attributes.contains("TEXCOORD_0"));

    ASSERT_GE(roof.material, 0);
    ASSERT_GE(wall.material, 0);
    EXPECT_TRUE(model.materials[roof.material].extensions.contains(
        "KHR_materials_unlit"));
    EXPECT_TRUE(model.materials[wall.material].extensions.contains(
        "KHR_materials_unlit"));
    EXPECT_EQ(
        model.materials[roof.material]
            .pbrMetallicRoughness.baseColorTexture.index,
        -1);
    EXPECT_EQ(
        model.materials[wall.material]
            .pbrMetallicRoughness.baseColorTexture.index,
        -1);
    EXPECT_EQ(model.materials[roof.material].name, "Hologram_Roof");
    EXPECT_EQ(model.materials[wall.material].name, "Hologram_Wall");
    EXPECT_LT(
        model.materials[wall.material]
            .pbrMetallicRoughness.baseColorFactor[2],
        model.materials[roof.material]
            .pbrMetallicRoughness.baseColorFactor[2]);
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
} // namespace
