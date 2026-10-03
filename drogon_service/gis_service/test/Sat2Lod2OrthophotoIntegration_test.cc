// End-to-end check of the production presentation path:
// SAT2LoD2 geometry + DepthWizard nDSM heights + orthophoto roof UVs +
// procedural facade UVs + repaired optical terrain.
//
// A SAT2LoD2 building document is imported exactly as PipelineService does,
// rendered by SceneMeshService in ORTHOPHOTO_REALISTIC and every check reads
// the packaged GLB itself.

#include "BuildingReconstruction/Sat2Lod2Importer.h"
#include "BuildingReconstructionTestSupport.h"
#include "GlbTestSupport.h"
#include "MeshMapping/FacadeAtlasGenerator.h"
#include "MeshMapping/SceneMeshService.h"
#include "tiny_gltf.h"

#include <gtest/gtest.h>
#include <json/json.h>
#include <opencv2/imgcodecs.hpp>

#include <algorithm>
#include <cmath>
#include <optional>
#include <utility>

using namespace depthwizard::test;

namespace
{
constexpr int kWidth = 96;
constexpr int kHeight = 72;
// Draco stores TEXCOORD_0 with 12-bit quantization: allow one 12-bit step
// over the full [0, 1] range (0.02 px here), still far below one pixel.
constexpr double kUvTolerance = 1.0 / 4096.0;

// Rotated (about 16 degrees) with non-square 0.5 m x 0.6 m pixels: every
// geotransform term differs, so a transposed term, swapped u/v or a V flip
// cannot pass. Pixel axes stay orthogonal, so SAT2LoD2 rectangles remain
// rectangles in projected space.
SpatialMetadata rotatedMetadata()
{
    SpatialMetadata metadata = makeProjectedMetadata(kWidth, kHeight, 0.5, -0.6);
    metadata.geoTransform = {500000.0, 0.48, 0.168, 2000000.0, 0.14, -0.576};
    return metadata;
}

ProjectedPoint projectEdge(const SpatialMetadata& metadata, double column, double row)
{
    const auto& gt = metadata.geoTransform;
    return {gt[0] + column * gt[1] + row * gt[2], gt[3] + column * gt[4] + row * gt[5]};
}

// Independent inverse affine: projected (E, N) -> pixel-edge (column, row).
std::pair<double, double> pixelEdgeOf(const SpatialMetadata& metadata, double easting, double northing)
{
    const auto& gt = metadata.geoTransform;
    const double dx = easting - gt[0];
    const double dy = northing - gt[3];
    const double det = gt[1] * gt[5] - gt[2] * gt[4];
    return {(dx * gt[5] - dy * gt[2]) / det, (dy * gt[1] - dx * gt[4]) / det};
}

Json::Value point(double column, double row)
{
    Json::Value value(Json::arrayValue);
    value.append(column);
    value.append(row);
    return value;
}

// SAT2LoD2 writes pixel-centre indices; the importer adds 0.5.
Json::Value rectangle(double left, double top, double right, double bottom)
{
    Json::Value ring(Json::arrayValue);
    ring.append(point(left, top));
    ring.append(point(right, top));
    ring.append(point(right, bottom));
    ring.append(point(left, bottom));
    return ring;
}

Json::Value segment(int id, double left, double top, double right, double bottom, const std::string& roofType)
{
    Json::Value block;
    block["corners"] = rectangle(left, top, right, bottom);
    block["roof_type"] = roofType;
    block["eave"] = 10.0;
    block["ridge"] = 12.0;
    const double middle = 0.5 * (top + bottom);
    Json::Value ridge(Json::arrayValue);
    ridge.append(point(left, middle));
    ridge.append(point(right, middle));
    block["ridge_line"] = ridge;

    Json::Value value;
    value["id"] = id;
    value["footprint"] = rectangle(left, top, right, bottom);
    value["blocks"].append(block);
    value["irregular"] = false;
    return value;
}

// A representative buildings.json: one flat commercial block, one gable
// house and one hip house.
Json::Value buildingsDocument()
{
    Json::Value root;
    root["schema"] = "depthwizard.sat2lod2.v1";
    root["raster_width"] = kWidth;
    root["raster_height"] = kHeight;
    root["segments"].append(segment(0, 10, 10, 39, 29, "flat"));
    root["segments"].append(segment(1, 50, 10, 69, 29, "gable"));
    root["segments"].append(segment(2, 50, 40, 69, 59, "hip"));
    return root;
}

// Every texel names its own pixel: red = 2 * column, green = 3 * row.
cv::Mat codedOpticalImage()
{
    cv::Mat image(kHeight, kWidth, CV_8UC3);
    for (int row = 0; row < kHeight; ++row)
        for (int column = 0; column < kWidth; ++column)
            image.at<cv::Vec3b>(row, column) = cv::Vec3b(
                128, static_cast<uint8_t>(3 * row), static_cast<uint8_t>(2 * column)); // BGR
    return image;
}

struct ProductionScene
{
    SpatialMetadata metadata = rotatedMetadata();
    SemanticScene semantics = makeSemanticScene(kWidth, kHeight, SemanticClass::ROAD);
    GeoreferencedSurfaceBundle surface = makeSurface(kWidth, kHeight, 50.0F, 0.0F);
    RasterGrid<float> correctedNdsm = makeConstantGrid(kWidth, kHeight, 0.0F);
    SceneInput scene;
    BuildingReconstructionConfig config;
    Sat2Lod2ImportResult imported;

    ProductionScene()
    {
        surface.spatialMetadata = metadata;
        // Pixel-centre rectangles [left, right] cover pixels left..right.
        const auto building = [&](int left, int top, int right, int bottom, float height)
        {
            fillRectangle(semantics.finalClassMap, left, top, right + 1, bottom + 1, SemanticClass::BUILDING);
            fillRectangle(semantics.buildingProbability, left, top, right + 1, bottom + 1, 0.9F);
            fillRectangle(correctedNdsm, left, top, right + 1, bottom + 1, height);
        };
        building(10, 10, 39, 29, 15.0F);
        building(50, 10, 69, 29, 12.0F);
        building(50, 40, 69, 59, 12.0F);
        surface.ndsm = correctedNdsm;
        for (std::size_t index = 0; index < surface.dsm.data.size(); ++index)
            surface.dsm.data[index] = surface.dtm.data[index] + surface.ndsm.data[index];

        // The production configuration, with SAT2LoD2's pitched roofs enabled
        // so parametric ridge and hip vertices are exercised.
        config.enableLod2RoofFitting = true;
        imported = Sat2Lod2Importer::import(buildingsDocument(), semantics, surface, metadata, config,
                                            correctedNdsm);

        scene.width = kWidth;
        scene.height = kHeight;
        scene.spatialMetadata = metadata;
        scene.textureMimeType = "image/png";
        EXPECT_TRUE(cv::imencode(".png", codedOpticalImage(), scene.rgbTextureBytes));
    }

    GlbBuildResult render() const
    {
        MeshBuildConfig meshConfig;
        meshConfig.presentationStyle = depthwizard::PresentationStyle::ORTHOPHOTO_REALISTIC;
        return SceneMeshService::generateGlb(scene, surface, imported.buildings, metadata, meshConfig);
    }
};

std::vector<uint8_t> imageBytes(const tinygltf::Model& model, int texture)
{
    const tinygltf::BufferView& view = model.bufferViews[model.images[model.textures[texture].source].bufferView];
    const auto begin = model.buffers[view.buffer].data.begin() + static_cast<std::ptrdiff_t>(view.byteOffset);
    return {begin, begin + static_cast<std::ptrdiff_t>(view.byteLength)};
}

int textureOf(const tinygltf::Model& model, const tinygltf::Primitive& primitive)
{
    return model.materials[primitive.material].pbrMetallicRoughness.baseColorTexture.index;
}

std::string semanticOf(const tinygltf::Model& model, const tinygltf::Primitive& primitive)
{
    const tinygltf::Value& extras = model.materials[primitive.material].extras;
    return extras.Has("textureSemantic") ? extras.Get("textureSemantic").Get<std::string>() : std::string();
}

struct DecodedRoof
{
    std::vector<float> positions;
    std::vector<float> uvs;
    std::vector<float> featureIds;
    double originX{0.0};
    double originY{0.0};

    std::size_t size() const { return positions.size() / 3; }
    double easting(std::size_t vertex) const { return positions[vertex * 3] + originX; }
    double northing(std::size_t vertex) const { return -positions[vertex * 3 + 2] + originY; }
    float height(std::size_t vertex) const { return positions[vertex * 3 + 1]; }
};

DecodedRoof decodeRoof(const tinygltf::Model& model, const tinygltf::Primitive& roof)
{
    DecodedRoof decoded;
    decoded.positions = decodeDracoAttribute(model, roof, "POSITION");
    decoded.uvs = decodeDracoAttribute(model, roof, "TEXCOORD_0");
    decoded.featureIds = decodeDracoAttribute(model, roof, "_FEATURE_ID_0");
    // The local frame is read from the GLB's own metadata.
    decoded.originX = model.asset.extras.Get("projectedOriginX").GetNumberAsDouble();
    decoded.originY = model.asset.extras.Get("projectedOriginY").GetNumberAsDouble();
    return decoded;
}

} // namespace

TEST(Sat2Lod2OrthophotoIntegrationTest, ImportedDocumentKeepsSat2Lod2RectanglesAndNdsmHeights)
{
    const ProductionScene s;
    ASSERT_EQ(s.imported.buildings.buildings.size(), 3U) << ::testing::PrintToString(s.imported.warnings);
    EXPECT_EQ(s.imported.segmentCount, 3U);
    EXPECT_EQ(s.imported.buildings.gableRoofBlockCount, 1U);
    EXPECT_EQ(s.imported.buildings.hipRoofBlockCount, 1U);
    for (const BuildingInstance& building : s.imported.buildings.buildings)
    {
        EXPECT_EQ(building.projectedFootprint.outerRing.size(), 4U);
        // Heights come from the DepthWizard nDSM, never from SAT2LoD2's eave/ridge.
        const float metric = building.blocks.empty() ? 15.0F : 12.0F;
        EXPECT_NEAR(building.heightAboveGround, metric * s.config.heightScaleMultiplier, 1e-3);
    }
}

TEST(Sat2Lod2OrthophotoIntegrationTest, GlbBindsOpticalRoofsFacadeWallsAndRepairedTerrain)
{
    const ProductionScene s;
    ASSERT_EQ(s.imported.buildings.buildings.size(), 3U);
    const GlbBuildResult glb = s.render();
    ASSERT_FALSE(glb.compressedGlbByteBuffer.empty()) << ::testing::PrintToString(glb.geometryWarnings);
    const tinygltf::Model model = loadGlb(glb.compressedGlbByteBuffer);

    EXPECT_EQ(model.asset.extras.Get("presentationStyle").Get<std::string>(), "orthophoto");

    const auto* terrain = primitiveWithMaterial(model, "Terrain_Repaired_Optical");
    const auto* roof = primitiveWithMaterial(model, "Building_Roof_Optical");
    const auto* wall = primitiveWithMaterial(model, "Building_Wall_Facade");
    ASSERT_TRUE(terrain && roof && wall);

    // Roof: TEXCOORD_0 sampling the uploaded image itself.
    EXPECT_TRUE(roof->attributes.contains("TEXCOORD_0"));
    EXPECT_EQ(semanticOf(model, *roof), "OPTICAL_ORIGINAL");
    EXPECT_EQ(imageBytes(model, textureOf(model, *roof)), s.scene.rgbTextureBytes);

    // Walls: the procedural facade atlas.
    EXPECT_TRUE(wall->attributes.contains("TEXCOORD_0"));
    EXPECT_EQ(semanticOf(model, *wall), "FACADE_ATLAS");
    EXPECT_EQ(imageBytes(model, textureOf(model, *wall)),
              depthwizard::FacadeAtlasGenerator::generateAtlasPng(false).bytes);

    // Terrain: a repaired copy of the image, with the roofs concealed.
    EXPECT_EQ(semanticOf(model, *terrain), "OPTICAL_GROUND_REPAIRED");
    const std::vector<uint8_t> groundBytes = imageBytes(model, textureOf(model, *terrain));
    EXPECT_NE(groundBytes, s.scene.rgbTextureBytes);
    const cv::Mat ground = cv::imdecode(groundBytes, cv::IMREAD_COLOR);
    ASSERT_EQ(ground.cols, kWidth);
    ASSERT_EQ(ground.rows, kHeight);
    EXPECT_NE(ground.at<cv::Vec3b>(20, 25), codedOpticalImage().at<cv::Vec3b>(20, 25)); // Roof hidden
    EXPECT_EQ(ground.at<cv::Vec3b>(66, 4), codedOpticalImage().at<cv::Vec3b>(66, 4));   // Far road kept

    // No scientific vertex colours and no edge lines.
    EXPECT_FALSE(roof->attributes.contains("COLOR_0"));
    EXPECT_FALSE(wall->attributes.contains("COLOR_0"));
    EXPECT_EQ(model.meshes.at(0).primitives.size(), 3U);
    for (const tinygltf::Primitive& primitive : model.meshes.at(0).primitives)
    {
        EXPECT_EQ(primitive.mode, TINYGLTF_MODE_TRIANGLES);
        EXPECT_EQ(model.materials[primitive.material].name.find("Edge"), std::string::npos);
    }
    for (const tinygltf::Material& material : model.materials)
        EXPECT_EQ(material.name.find("Edge"), std::string::npos);
}

TEST(Sat2Lod2OrthophotoIntegrationTest, RoofCornersAndRidgeVerticesSampleTheirOwnImagePixels)
{
    const ProductionScene s;
    ASSERT_EQ(s.imported.buildings.buildings.size(), 3U);
    const GlbBuildResult glb = s.render();
    ASSERT_FALSE(glb.compressedGlbByteBuffer.empty()) << ::testing::PrintToString(glb.geometryWarnings);
    const tinygltf::Model model = loadGlb(glb.compressedGlbByteBuffer);
    const auto* roofPrimitive = primitiveWithMaterial(model, "Building_Roof_Optical");
    ASSERT_NE(roofPrimitive, nullptr);
    const DecodedRoof roof = decodeRoof(model, *roofPrimitive);
    ASSERT_FALSE(roof.positions.empty());
    ASSERT_EQ(roof.uvs.size(), roof.size() * 2);
    ASSERT_EQ(roof.featureIds.size(), roof.size());

    // 1. Every roof vertex, ridge and hip vertices included, carries the
    //    inverse-affine UV of its own projected position (glTF top-left origin).
    for (std::size_t vertex = 0; vertex < roof.size(); ++vertex)
    {
        const auto [column, row] = pixelEdgeOf(s.metadata, roof.easting(vertex), roof.northing(vertex));
        EXPECT_NEAR(roof.uvs[vertex * 2], column / kWidth, kUvTolerance) << "vertex " << vertex;
        EXPECT_NEAR(roof.uvs[vertex * 2 + 1], row / kHeight, kUvTolerance) << "vertex " << vertex;
    }

    // 2. Known projected footprint corners of every imported building map to
    //    their expected source-image UV.
    const auto uvAt = [&](const ProjectedPoint& corner) -> std::optional<std::pair<float, float>>
    {
        for (std::size_t vertex = 0; vertex < roof.size(); ++vertex)
            if (std::hypot(roof.easting(vertex) - corner.easting, roof.northing(vertex) - corner.northing) < 2e-3)
                return std::make_pair(roof.uvs[vertex * 2], roof.uvs[vertex * 2 + 1]);
        return std::nullopt;
    };
    for (const BuildingInstance& building : s.imported.buildings.buildings)
        for (const ProjectedPoint& corner : building.projectedFootprint.outerRing)
        {
            const auto uv = uvAt(corner);
            ASSERT_TRUE(uv.has_value()) << "building " << building.buildingId << " corner has no roof vertex";
            const auto [column, row] = pixelEdgeOf(s.metadata, corner.easting, corner.northing);
            EXPECT_NEAR(uv->first, column / kWidth, kUvTolerance);
            EXPECT_NEAR(uv->second, row / kHeight, kUvTolerance);
        }
    // Pinned literal: the flat block's SAT2LoD2 corner (10, 10) is pixel edge
    // (10.5, 10.5), moved inwards by half the part gap along both pixel axes.
    const double halfGap = 0.5 * s.config.sat2lod2PartGapMetres;
    const double cornerColumn = 10.5 + halfGap / 0.5;
    const double cornerRow = 10.5 + halfGap / 0.6;
    const auto pinned = uvAt(projectEdge(s.metadata, cornerColumn, cornerRow));
    ASSERT_TRUE(pinned.has_value());
    EXPECT_NEAR(pinned->first, cornerColumn / kWidth, kUvTolerance);
    EXPECT_NEAR(pinned->second, cornerRow / kHeight, kUvTolerance);

    // 3. Parametric ridge/hip vertices (above the eave) exist for both pitched
    //    buildings and sit on SAT2LoD2's ridge row (pixel edge 20 and 50).
    for (const BuildingInstance& building : s.imported.buildings.buildings)
    {
        if (building.blocks.empty()) continue;
        const RoofParameters& parameters = building.blocks.front().roof;
        const bool gable = parameters.type == RoofType::GABLE;
        const double ridgeRow = gable ? 20.0 : 50.0;
        float topHeight = -1e9F;
        for (std::size_t vertex = 0; vertex < roof.size(); ++vertex)
            if (static_cast<uint32_t>(std::lround(roof.featureIds[vertex])) == building.buildingId)
                topHeight = std::max(topHeight, roof.height(vertex));
        std::size_t ridgeVertices = 0;
        for (std::size_t vertex = 0; vertex < roof.size(); ++vertex)
        {
            if (static_cast<uint32_t>(std::lround(roof.featureIds[vertex])) != building.buildingId) continue;
            if (roof.height(vertex) < topHeight - 1e-3F) continue;
            ++ridgeVertices;
            EXPECT_NEAR(roof.uvs[vertex * 2 + 1] * kHeight, ridgeRow, kUvTolerance * kHeight) << (gable ? "gable" : "hip");
            const double column = roof.uvs[vertex * 2] * kWidth;
            EXPECT_GE(column, 50.5 - 1e-3);
            EXPECT_LE(column, 69.5 + 1e-3);
            if (!gable) // Hip ridge ends are inset from the hipped ends.
            {
                EXPECT_GT(column, 51.0);
                EXPECT_LT(column, 69.0);
            }
        }
        EXPECT_GE(ridgeVertices, 2U) << (gable ? "gable" : "hip") << " ridge vertices missing";
    }

    // 4. The packaged roof texture is the image in its original orientation:
    //    sampling it at every roof triangle's centroid UV returns the coded
    //    pixel under that centroid's projected position, inside its own
    //    SAT2LoD2 rectangle.
    const cv::Mat texture = cv::imdecode(imageBytes(model, textureOf(model, *roofPrimitive)), cv::IMREAD_COLOR);
    ASSERT_EQ(texture.cols, kWidth);
    ASSERT_EQ(texture.rows, kHeight);
    const std::vector<int> indices = [&]
    {
        std::vector<int> values;
        const auto extension = roofPrimitive->extensions.find("KHR_draco_mesh_compression");
        const tinygltf::BufferView& view =
            model.bufferViews[extension->second.Get("bufferView").GetNumberAsInt()];
        draco::DecoderBuffer source;
        source.Init(reinterpret_cast<const char*>(model.buffers[view.buffer].data.data() + view.byteOffset),
                    view.byteLength);
        draco::Decoder decoder;
        auto mesh = decoder.DecodeMeshFromBuffer(&source).value();
        for (draco::FaceIndex face(0); face < mesh->num_faces(); ++face)
            for (int corner = 0; corner < 3; ++corner) values.push_back(static_cast<int>(mesh->face(face)[corner].value()));
        return values;
    }();
    ASSERT_FALSE(indices.empty());
    std::size_t sampled = 0;
    for (std::size_t triangle = 0; triangle + 2 < indices.size(); triangle += 3)
    {
        double u = 0.0, v = 0.0, east = 0.0, north = 0.0;
        for (int corner = 0; corner < 3; ++corner)
        {
            const std::size_t vertex = static_cast<std::size_t>(indices[triangle + corner]);
            u += roof.uvs[vertex * 2] / 3.0;
            v += roof.uvs[vertex * 2 + 1] / 3.0;
            east += roof.easting(vertex) / 3.0;
            north += roof.northing(vertex) / 3.0;
        }
        const cv::Vec3b texel = texture.at<cv::Vec3b>(static_cast<int>(v * kHeight), static_cast<int>(u * kWidth));
        const int sampledColumn = texel[2] / 2;
        const int sampledRow = texel[1] / 3;
        const auto [column, row] = pixelEdgeOf(s.metadata, east, north);
        EXPECT_NEAR(sampledColumn, std::floor(column), 1.0) << "triangle " << triangle / 3;
        EXPECT_NEAR(sampledRow, std::floor(row), 1.0) << "triangle " << triangle / 3;
        const bool insideRectangle =
            (sampledColumn >= 10 && sampledColumn <= 39 && sampledRow >= 10 && sampledRow <= 29) ||
            (sampledColumn >= 50 && sampledColumn <= 69 && sampledRow >= 10 && sampledRow <= 29) ||
            (sampledColumn >= 50 && sampledColumn <= 69 && sampledRow >= 40 && sampledRow <= 59);
        EXPECT_TRUE(insideRectangle) << "triangle " << triangle / 3 << " samples pixel (" << sampledColumn
                                     << ", " << sampledRow << ")";
        ++sampled;
    }
    EXPECT_GE(sampled, 6U);
}
