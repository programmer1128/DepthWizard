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
    EXPECT_EQ(model.materials[roof.material].name, "Hologram_Roof");
    EXPECT_EQ(model.materials[wall.material].name, "Hologram_Wall");
    EXPECT_EQ(std::count(model.extensionsUsed.begin(), model.extensionsUsed.end(),
        "KHR_materials_unlit"), 0);
    const auto& wallPbr = model.materials[wall.material].pbrMetallicRoughness;
    const auto& roofPbr = model.materials[roof.material].pbrMetallicRoughness;
    EXPECT_EQ(wallPbr.baseColorFactor, (std::vector<double>{0.015, 0.10, 0.42, 1.0}));
    EXPECT_DOUBLE_EQ(wallPbr.metallicFactor, 0.0);
    EXPECT_DOUBLE_EQ(wallPbr.roughnessFactor, 0.6);
    EXPECT_EQ(roofPbr.baseColorFactor, (std::vector<double>{0.025, 0.24, 0.72, 1.0}));
    EXPECT_DOUBLE_EQ(roofPbr.metallicFactor, 0.0);
    EXPECT_DOUBLE_EQ(roofPbr.roughnessFactor, 0.65);
    EXPECT_LT(
        model.materials[wall.material]
            .pbrMetallicRoughness.baseColorFactor[2],
        model.materials[roof.material]
            .pbrMetallicRoughness.baseColorFactor[2]);
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
} // namespace
