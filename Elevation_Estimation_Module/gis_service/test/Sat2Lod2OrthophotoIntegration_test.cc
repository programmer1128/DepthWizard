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
#include "MeshMapping/ScenePresentationPolicy.h"
#include "MeshMapping/ScenePresentationSelector.h"
#include "MeshMapping/TerrainSurfaceComposer.h"
#include "Vegetation/VegetationCanopyBuilder.h"
#include "Vegetation/VegetationClassifier.h"
#include "Vegetation/VegetationExtractor.h"
#include "Vegetation/VegetationHeightSampler.h"
#include "Vegetation/VegetationTreeCandidateGenerator.h"
#include "Vegetation/VegetationTreeInstancer.h"
#include "Vegetation/DenseForestProxyGenerator.h"
#include "Vegetation/VegetationCoverGenerator.h"
#include "MeshMapping/LocalFrameTransformer.h"
#include "tiny_gltf.h"

#include <gtest/gtest.h>
#include <json/json.h>
#include <opencv2/imgcodecs.hpp>

#include <algorithm>
#include <cmath>
#include <optional>
#include <memory>
#include <set>
#include <sstream>
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

    GlbBuildResult render(ScenePresentation presentation = ScenePresentation::METRIC) const
    {
        MeshBuildConfig meshConfig;
        meshConfig.presentation = presentation;
        meshConfig.presentationStyle = depthwizard::PresentationStyle::ORTHOPHOTO_REALISTIC;
        return SceneMeshService::generateGlb(scene, surface, imported.buildings, metadata, meshConfig);
    }

    ScenePresentation resolve(ScenePresentationPolicy policy) const
    {
        return resolveScenePresentation(
            policy, ScenePresentationSelector::select(semantics, surface, imported.buildings));
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

// --- Automatic presentation keeps the validated urban path exactly ---

namespace
{
// FNV-1a over the decoded building geometry: positions and UVs at their Draco
// precision, feature IDs and triangle indices.
uint64_t buildingDigest(const tinygltf::Model& model)
{
    uint64_t hash = 1469598103934665603ULL;
    const auto mix = [&](int64_t value)
    {
        for (int byte = 0; byte < 8; ++byte)
        {
            hash ^= static_cast<uint64_t>(value >> (8 * byte)) & 0xFFU;
            hash *= 1099511628211ULL;
        }
    };
    for (const char* name : {"Building_Roof_Optical", "Building_Wall_Facade"})
    {
        const tinygltf::Primitive* primitive = primitiveWithMaterial(model, name);
        if (primitive == nullptr) continue;
        for (const char* attribute : {"POSITION", "TEXCOORD_0", "_FEATURE_ID_0"})
            for (float value : decodeDracoAttribute(model, *primitive, attribute))
                mix(std::llround(static_cast<double>(value) * 1.0e5));
        const auto extension = primitive->extensions.find("KHR_draco_mesh_compression");
        const tinygltf::BufferView& view = model.bufferViews[extension->second.Get("bufferView").GetNumberAsInt()];
        draco::DecoderBuffer source;
        source.Init(reinterpret_cast<const char*>(model.buffers[view.buffer].data.data() + view.byteOffset),
                    view.byteLength);
        draco::Decoder decoder;
        auto mesh = decoder.DecodeMeshFromBuffer(&source).value();
        for (draco::FaceIndex face(0); face < mesh->num_faces(); ++face)
            for (int corner = 0; corner < 3; ++corner) mix(mesh->face(face)[corner].value());
    }
    return hash;
}
} // namespace

TEST(Sat2Lod2OrthophotoIntegrationTest, AutoKeepsTheValidatedFlatUrbanPathUnchanged)
{
    const ProductionScene s;
    ASSERT_EQ(s.imported.buildings.buildings.size(), 3U);
    const ScenePresentationDecision decision =
        ScenePresentationSelector::select(s.semantics, s.surface, s.imported.buildings);
    EXPECT_EQ(decision.reason, "Distributed high-confidence urban structures; flat presentation without skirts.");
    const ScenePresentation presentation = resolveScenePresentation(ScenePresentationPolicy::AUTO, decision);
    ASSERT_EQ(presentation, ScenePresentation::FLAT_URBAN);

    // AUTO produces exactly the GLB of the validated (explicit flat_urban) path.
    const GlbBuildResult automatic = s.render(presentation);
    const GlbBuildResult validated = s.render(ScenePresentation::FLAT_URBAN);
    ASSERT_FALSE(automatic.compressedGlbByteBuffer.empty()) << ::testing::PrintToString(automatic.geometryWarnings);
    EXPECT_EQ(automatic.compressedGlbByteBuffer, validated.compressedGlbByteBuffer);
    const tinygltf::Model model = loadGlb(automatic.compressedGlbByteBuffer);
    EXPECT_EQ(model.asset.extras.Get("presentationMode").Get<std::string>(), "flat_urban");
    EXPECT_EQ(model.asset.extras.Get("presentationStyle").Get<std::string>(), "orthophoto");
    EXPECT_EQ(model.asset.extras.Get("buildingCount").GetNumberAsInt(), 3);

    // Flat urban ground: top surface at Y = 0 and no skirt vertices.
    const auto* terrain = primitiveWithMaterial(model, "Terrain_Repaired_Optical");
    const auto* roof = primitiveWithMaterial(model, "Building_Roof_Optical");
    const auto* wall = primitiveWithMaterial(model, "Building_Wall_Facade");
    ASSERT_TRUE(terrain && roof && wall);
    const std::vector<float> terrainPositions = decodeDracoAttribute(model, *terrain, "POSITION");
    ASSERT_EQ(terrainPositions.size() / 3, static_cast<std::size_t>(kWidth * kHeight));
    for (std::size_t index = 1; index < terrainPositions.size(); index += 3)
        ASSERT_EQ(terrainPositions[index], 0.0F);

    // Materials, primitives and no scientific edge lines.
    EXPECT_EQ(semanticOf(model, *roof), "OPTICAL_ORIGINAL");
    EXPECT_EQ(semanticOf(model, *wall), "FACADE_ATLAS");
    EXPECT_EQ(semanticOf(model, *terrain), "OPTICAL_GROUND_REPAIRED");
    EXPECT_EQ(model.meshes.at(0).primitives.size(), 3U);
    for (const tinygltf::Primitive& primitive : model.meshes.at(0).primitives)
        EXPECT_EQ(primitive.mode, TINYGLTF_MODE_TRIANGLES);
    for (const tinygltf::Material& material : model.materials)
        EXPECT_EQ(material.name.find("Edge"), std::string::npos);

    // SAT2LoD2 building IDs, nDSM heights (1:1 above flat ground) and roof UVs.
    const DecodedRoof decoded = decodeRoof(model, *roof);
    std::set<uint32_t> ids;
    for (float id : decoded.featureIds) ids.insert(static_cast<uint32_t>(std::lround(id)));
    std::set<uint32_t> expectedIds;
    for (const BuildingInstance& building : s.imported.buildings.buildings)
    {
        expectedIds.insert(building.buildingId);
        float top = -1e9F;
        for (std::size_t vertex = 0; vertex < decoded.size(); ++vertex)
            if (static_cast<uint32_t>(std::lround(decoded.featureIds[vertex])) == building.buildingId)
                top = std::max(top, decoded.height(vertex));
        EXPECT_NEAR(top, building.heightAboveGround, 2e-2) << "building " << building.buildingId;
    }
    EXPECT_EQ(ids, expectedIds);
    for (std::size_t vertex = 0; vertex < decoded.size(); ++vertex)
    {
        const auto [column, row] = pixelEdgeOf(s.metadata, decoded.easting(vertex), decoded.northing(vertex));
        EXPECT_NEAR(decoded.uvs[vertex * 2], column / kWidth, kUvTolerance);
        EXPECT_NEAR(decoded.uvs[vertex * 2 + 1], row / kHeight, kUvTolerance);
    }

    // Building geometry digest of the validated urban fixture, captured from
    // the production mesher before automatic presentation landed.
    EXPECT_EQ(buildingDigest(model), 14738508419874179917ULL) << "digest " << buildingDigest(model);
}

TEST(Sat2Lod2OrthophotoIntegrationTest, ForcedMetricRetainsTerrainInUrbanSceneRenderOnly)
{
    const ProductionScene s;
    const auto dtm = s.surface.dtm.data;
    const auto dsm = s.surface.dsm.data;
    const auto ndsm = s.surface.ndsm.data;
    const auto corrected = s.correctedNdsm.data;

    const ScenePresentation presentation = s.resolve(ScenePresentationPolicy::FORCE_METRIC);
    ASSERT_EQ(presentation, ScenePresentation::METRIC);
    const GlbBuildResult glb = s.render(presentation);
    ASSERT_FALSE(glb.compressedGlbByteBuffer.empty());
    const tinygltf::Model model = loadGlb(glb.compressedGlbByteBuffer);
    EXPECT_EQ(model.asset.extras.Get("presentationMode").Get<std::string>(), "metric");
    EXPECT_EQ(model.asset.extras.Get("buildingCount").GetNumberAsInt(), 3);

    // Terrain keeps its skirt; roofs sit at their absolute roof elevations.
    const auto* terrain = primitiveWithMaterial(model, "Terrain_Repaired_Optical");
    const auto* roof = primitiveWithMaterial(model, "Building_Roof_Optical");
    ASSERT_TRUE(terrain && roof);
    const std::vector<float> terrainPositions = decodeDracoAttribute(model, *terrain, "POSITION");
    EXPECT_GT(terrainPositions.size() / 3, static_cast<std::size_t>(kWidth * kHeight));
    float lowest = 1e9F;
    for (std::size_t index = 1; index < terrainPositions.size(); index += 3)
        lowest = std::min(lowest, terrainPositions[index]);
    EXPECT_NEAR(lowest, -TerrainMeshConfig().skirtDepth, 2e-2); // Flat 50 m DTM, origin at its minimum
    const double origin = model.asset.extras.Get("elevationOrigin").GetNumberAsDouble();
    const DecodedRoof decoded = decodeRoof(model, *roof);
    for (const BuildingInstance& building : s.imported.buildings.buildings)
    {
        float top = -1e9F;
        for (std::size_t vertex = 0; vertex < decoded.size(); ++vertex)
            if (static_cast<uint32_t>(std::lround(decoded.featureIds[vertex])) == building.buildingId)
                top = std::max(top, decoded.height(vertex));
        EXPECT_NEAR(top + origin, building.roofElevation, 2e-2);
    }

    // Render-only: no raster changes under either override.
    s.render(s.resolve(ScenePresentationPolicy::FORCE_FLAT_URBAN));
    EXPECT_EQ(s.surface.dtm.data, dtm);
    EXPECT_EQ(s.surface.dsm.data, dsm);
    EXPECT_EQ(s.surface.ndsm.data, ndsm);
    EXPECT_EQ(s.correctedNdsm.data, corrected);
}

TEST(Sat2Lod2OrthophotoIntegrationTest, VegetationStageTwoLeavesTheGlbByteIdentical)
{
    ProductionScene s;
    // Trees beside the buildings (and one touching a footprint).
    fillRectangle(s.semantics.finalClassMap, 10, 34, 40, 50, SemanticClass::VEGETATION);
    fillRectangle(s.semantics.vegetationProbability, 10, 34, 40, 50, 0.9F);
    fillRectangle(s.surface.ndsm, 10, 34, 40, 50, 9.0F);
    fillRectangle(s.semantics.finalClassMap, 70, 10, 80, 30, SemanticClass::VEGETATION);
    fillRectangle(s.semantics.vegetationProbability, 70, 10, 80, 30, 0.9F);
    fillRectangle(s.surface.ndsm, 70, 10, 80, 30, 7.0F);
    for (std::size_t i = 0; i < s.surface.dsm.data.size(); ++i)
        s.surface.dsm.data[i] = s.surface.dtm.data[i] + s.surface.ndsm.data[i];
    const ScenePresentation presentation = s.resolve(ScenePresentationPolicy::AUTO);
    ASSERT_EQ(presentation, ScenePresentation::FLAT_URBAN);

    const GlbBuildResult before = s.render(presentation);
    ASSERT_FALSE(before.compressedGlbByteBuffer.empty());

    // Exactly what PipelineService runs with DEPTHWIZARD_VEGETATION=1.
    VegetationConfig config;
    config.mode = VegetationMode::ON;
    const VegetationMask mask = VegetationExtractor::extract(
        s.semantics, s.surface, TerrainSurfaceComposer::buildExactFootprintMask(s.imported.buildings, s.metadata),
        s.metadata, config);
    const VegetationHeights heights = VegetationHeightSampler::sample(mask, s.surface, config);
    ASSERT_GT(mask.stats.confirmedPixels, 0U);
    EXPECT_GT(mask.stats.rejectedBuildingBuffer, 0U); // The rectangle touching building 2 is trimmed
    EXPECT_GT(heights.sampledPixels, 0U);
    for (std::size_t i = 0; i < mask.tier.data.size(); ++i)
        if (mask.tier.data[i] != static_cast<uint8_t>(VegetationTier::NONE))
            ASSERT_EQ(mask.protectedMask.data[i], 0U); // Never on a buffered footprint

    const GlbBuildResult after = s.render(presentation);
    EXPECT_EQ(after.compressedGlbByteBuffer, before.compressedGlbByteBuffer);
    EXPECT_EQ(buildingDigest(loadGlb(after.compressedGlbByteBuffer)), 14738508419874179917ULL);
}

// --- Stage 3: the canopy overlay appended to the validated urban scene ------

namespace
{
// The vegetation pipeline exactly as PipelineService runs it; owns every
// object the canopy input points at.
struct VegetationRun
{
    VegetationMask mask;
    VegetationHeights heights;
    VegetationClassification classes;
    VegetationCanopyMesh canopy;
    VegetationCanopyInput input;

    VegetationRun(const ProductionScene& s, VegetationConfig config)
    {
        config.mode = VegetationMode::ON;
        mask = VegetationExtractor::extract(
            s.semantics, s.surface, TerrainSurfaceComposer::buildExactFootprintMask(s.imported.buildings, s.metadata),
            s.metadata, config);
        heights = VegetationHeightSampler::sample(mask, s.surface, config);
        classes = VegetationClassifier::classify(mask, config);
        input.mask = &mask;
        input.classification = &classes;
        input.heights = &heights;
        input.config = config;
        input.buildingDisplayHeightScale = s.config.heightScaleMultiplier;
        input.output = &canopy;
    }
};

// A 23 m x 23 m wooded courtyard south of the first block: dense at 0.5 m.
void addCourtyardTrees(ProductionScene& s)
{
    fillRectangle(s.semantics.finalClassMap, 0, 34, 46, 72, SemanticClass::VEGETATION);
    fillRectangle(s.semantics.vegetationProbability, 0, 34, 46, 72, 0.9F);
    fillRectangle(s.surface.ndsm, 0, 34, 46, 72, 9.0F);
    for (std::size_t i = 0; i < s.surface.dsm.data.size(); ++i)
        s.surface.dsm.data[i] = s.surface.dtm.data[i] + s.surface.ndsm.data[i];
}

GlbBuildResult renderWith(const ProductionScene& s, ScenePresentation presentation, const VegetationCanopyInput* input)
{
    MeshBuildConfig meshConfig;
    meshConfig.presentation = presentation;
    meshConfig.presentationStyle = depthwizard::PresentationStyle::ORTHOPHOTO_REALISTIC;
    return SceneMeshService::generateGlb(s.scene, s.surface, s.imported.buildings, s.metadata, meshConfig, input);
}

std::string materialJson(const tinygltf::Material& m)
{
    std::ostringstream text;
    text << m.name << "|" << m.pbrMetallicRoughness.baseColorTexture.index << "|"
         << m.pbrMetallicRoughness.metallicFactor << "|" << m.pbrMetallicRoughness.roughnessFactor << "|"
         << m.doubleSided << "|" << m.alphaMode << "|";
    for (double value : m.pbrMetallicRoughness.baseColorFactor) text << value << ",";
    if (m.extras.Has("textureSemantic")) text << m.extras.Get("textureSemantic").Get<std::string>();
    return text.str();
}

std::vector<int> decodedIndices(const tinygltf::Model& model, const tinygltf::Primitive& primitive)
{
    const auto extension = primitive.extensions.find("KHR_draco_mesh_compression");
    const tinygltf::BufferView& view = model.bufferViews[extension->second.Get("bufferView").GetNumberAsInt()];
    draco::DecoderBuffer source;
    source.Init(reinterpret_cast<const char*>(model.buffers[view.buffer].data.data() + view.byteOffset),
                view.byteLength);
    draco::Decoder decoder;
    auto mesh = decoder.DecodeMeshFromBuffer(&source).value();
    std::vector<int> values;
    for (draco::FaceIndex face(0); face < mesh->num_faces(); ++face)
        for (int corner = 0; corner < 3; ++corner) values.push_back(static_cast<int>(mesh->face(face)[corner].value()));
    return values;
}
} // namespace

TEST(Sat2Lod2OrthophotoIntegrationTest, CanopyIsAppendedAfterAnUnchangedUrbanScene)
{
    ProductionScene s;
    addCourtyardTrees(s);
    const ScenePresentation presentation = s.resolve(ScenePresentationPolicy::AUTO);
    ASSERT_EQ(presentation, ScenePresentation::FLAT_URBAN);
    VegetationRun vegetation(s, VegetationConfig{});
    ASSERT_GT(vegetation.classes.stats.densePixels, 0U);

    const GlbBuildResult plain = renderWith(s, presentation, nullptr);
    const GlbBuildResult withCanopy = renderWith(s, presentation, &vegetation.input);
    ASSERT_FALSE(withCanopy.compressedGlbByteBuffer.empty()) << ::testing::PrintToString(withCanopy.geometryWarnings);
    ASSERT_FALSE(vegetation.canopy.empty()) << vegetation.canopy.stats.skippedReason;
    const tinygltf::Model a = loadGlb(plain.compressedGlbByteBuffer);
    const tinygltf::Model b = loadGlb(withCanopy.compressedGlbByteBuffer);

    // Base scene: node 0, mesh 0, its primitives, materials and textures are unchanged.
    ASSERT_EQ(a.nodes.size(), 1U);
    ASSERT_EQ(b.nodes.size(), 2U);
    EXPECT_EQ(b.nodes[0].mesh, 0);
    EXPECT_TRUE(b.nodes[0].name.empty());
    EXPECT_EQ(b.nodes[0].matrix, a.nodes[0].matrix);
    EXPECT_EQ(b.nodes[0].translation, a.nodes[0].translation);
    EXPECT_EQ(b.scenes[0].nodes, (std::vector<int>{0, 1}));
    ASSERT_EQ(a.meshes[0].primitives.size(), b.meshes[0].primitives.size());
    for (std::size_t p = 0; p < a.meshes[0].primitives.size(); ++p)
    {
        const auto& pa = a.meshes[0].primitives[p];
        const auto& pb = b.meshes[0].primitives[p];
        EXPECT_EQ(pa.material, pb.material);
        EXPECT_EQ(pa.attributes, pb.attributes);
        for (const char* attribute : {"POSITION", "NORMAL", "TEXCOORD_0", "_FEATURE_ID_0", "COLOR_0"})
            EXPECT_EQ(decodeDracoAttribute(a, pa, attribute), decodeDracoAttribute(b, pb, attribute)) << attribute;
        EXPECT_EQ(decodedIndices(a, pa), decodedIndices(b, pb));
    }
    for (std::size_t m = 0; m < a.materials.size(); ++m) EXPECT_EQ(materialJson(a.materials[m]), materialJson(b.materials[m]));
    ASSERT_EQ(a.textures.size(), b.textures.size()); // The canopy reuses the optical texture
    for (std::size_t t = 0; t < a.textures.size(); ++t) EXPECT_EQ(imageBytes(a, static_cast<int>(t)), imageBytes(b, static_cast<int>(t)));
    EXPECT_EQ(buildingDigest(b), 14738508419874179917ULL);

    // The canopy node: named, tagged, textured with the original image.
    const tinygltf::Node& node = b.nodes[1];
    EXPECT_EQ(node.name, "VEGETATION_CANOPY");
    EXPECT_EQ(node.extras.Get("geometrySemantic").Get<std::string>(), "VEGETATION_CANOPY");
    EXPECT_TRUE(node.extras.Get("visualizationProxy").Get<bool>());
    EXPECT_FALSE(node.extras.Get("scientificSurface").Get<bool>());
    EXPECT_FALSE(node.extras.Get("speciesInferred").Get<bool>());
    EXPECT_FALSE(node.extras.Get("externalGeographicDataUsed").Get<bool>());
    EXPECT_EQ(node.extras.Get("heightSource").Get<std::string>(), "NDSM");
    EXPECT_EQ(node.extras.Get("presentationMode").Get<std::string>(), "flat_urban");
    EXPECT_NEAR(node.extras.Get("displayHeightScale").GetNumberAsDouble(), s.config.heightScaleMultiplier, 1e-6);
    const tinygltf::Primitive& canopy = b.meshes[static_cast<std::size_t>(node.mesh)].primitives.at(0);
    const tinygltf::Material& material = b.materials[static_cast<std::size_t>(canopy.material)];
    EXPECT_EQ(material.extras.Get("textureSemantic").Get<std::string>(), "OPTICAL_ORIGINAL");
    EXPECT_EQ(material.extras.Get("geometrySemantic").Get<std::string>(), "VEGETATION_CANOPY");
    EXPECT_LE(material.pbrMetallicRoughness.metallicFactor, 0.0);
    EXPECT_GE(material.pbrMetallicRoughness.roughnessFactor, 0.8);
    const auto* roof = primitiveWithMaterial(b, "Building_Roof_Optical");
    EXPECT_EQ(material.pbrMetallicRoughness.baseColorTexture.index,
              b.materials[static_cast<std::size_t>(roof->material)].pbrMetallicRoughness.baseColorTexture.index);
    EXPECT_FALSE(canopy.attributes.contains("_FEATURE_ID_0"));
    EXPECT_FALSE(canopy.attributes.contains("COLOR_0"));

    // No canopy vertex on a protected footprint; heights are the scaled nDSM.
    const std::vector<float> positions = decodeDracoAttribute(b, canopy, "POSITION");
    const double originX = b.asset.extras.Get("projectedOriginX").GetNumberAsDouble();
    const double originY = b.asset.extras.Get("projectedOriginY").GetNumberAsDouble();
    ASSERT_FALSE(positions.empty());
    for (std::size_t v = 0; v < positions.size() / 3; ++v)
    {
        const auto [column, row] = pixelEdgeOf(s.metadata, positions[v * 3] + originX, -positions[v * 3 + 2] + originY);
        const int x = static_cast<int>(column), y = static_cast<int>(row);
        ASSERT_TRUE(x >= 0 && x < kWidth && y >= 0 && y < kHeight);
        ASSERT_EQ(vegetation.mask.protectedMask.data[static_cast<std::size_t>(y) * kWidth + x], 0U);
        EXPECT_LE(positions[v * 3 + 1], 9.0F * s.config.heightScaleMultiplier + 2e-2F);
    }
}

TEST(Sat2Lod2OrthophotoIntegrationTest, DisabledOrEmptyCanopyLeavesTheGlbByteIdentical)
{
    ProductionScene s;
    addCourtyardTrees(s);
    const ScenePresentation presentation = s.resolve(ScenePresentationPolicy::AUTO);
    const GlbBuildResult plain = renderWith(s, presentation, nullptr);
    EXPECT_EQ(buildingDigest(loadGlb(plain.compressedGlbByteBuffer)), 14738508419874179917ULL);

    // DEPTHWIZARD_VEGETATION_CANOPY=0.
    VegetationConfig noCanopy;
    noCanopy.canopy = false;
    VegetationRun disabled(s, noCanopy);
    EXPECT_EQ(renderWith(s, presentation, &disabled.input).compressedGlbByteBuffer, plain.compressedGlbByteBuffer);

    // No dense vegetation survives (a raised minimum area): no node at all.
    VegetationConfig strict;
    strict.denseMinAreaSquareMetres = 100000.0F;
    VegetationRun empty(s, strict);
    EXPECT_EQ(empty.classes.stats.densePixels, 0U);
    EXPECT_EQ(renderWith(s, presentation, &empty.input).compressedGlbByteBuffer, plain.compressedGlbByteBuffer);
    EXPECT_TRUE(empty.canopy.empty());
}

// --- Stage 4: tree candidates are computed but never rendered ---------------

TEST(Sat2Lod2OrthophotoIntegrationTest, TreeCandidatesLeaveTheCanopyGlbByteIdentical)
{
    ProductionScene s;
    addCourtyardTrees(s);
    // Two crowns rising 5 m above the 9 m courtyard canopy.
    for (const auto& [cx, cy] : std::vector<std::pair<double, double>>{{12.0, 50.0}, {34.0, 60.0}})
        for (int y = 34; y < 72; ++y)
            for (int x = 0; x < 46; ++x)
            {
                const double d = std::hypot((x + 0.5 - cx) * 0.5, (y + 0.5 - cy) * 0.6);
                float& h = s.surface.ndsm.data[static_cast<std::size_t>(y) * kWidth + x];
                h = std::max(h, static_cast<float>(9.0 + 5.0 * std::exp(-d * d / (2 * 2.5 * 2.5))));
            }
    for (std::size_t i = 0; i < s.surface.dsm.data.size(); ++i)
        s.surface.dsm.data[i] = s.surface.dtm.data[i] + s.surface.ndsm.data[i];
    const ScenePresentation presentation = s.resolve(ScenePresentationPolicy::AUTO);
    VegetationRun vegetation(s, VegetationConfig{});
    const GlbBuildResult before = renderWith(s, presentation, &vegetation.input);
    ASSERT_FALSE(vegetation.canopy.empty());

    VegetationTreeInput input;
    input.mask = &vegetation.mask;
    input.classification = &vegetation.classes;
    input.heights = &vegetation.heights;
    input.semantics = &s.semantics;
    input.surface = &s.surface;
    input.metadata = &s.metadata;
    input.frame = LocalFrameTransformer::create(s.metadata, s.surface);
    input.terrainConfig.elevationSource = TerrainElevationSource::FLAT_PRESENTATION;
    input.presentation = presentation;
    input.buildingDisplayHeightScale = s.config.heightScaleMultiplier;
    input.config = vegetation.input.config;
    const VegetationTreeCandidates trees = VegetationTreeCandidateGenerator::generate(input);
    ASSERT_TRUE(trees.enabled) << trees.disabledReason;
    ASSERT_FALSE(trees.candidates.empty());
    for (const TreeCandidate& c : trees.candidates)
    {
        EXPECT_EQ(vegetation.mask.protectedMask.data[static_cast<std::size_t>(c.pixelRow) * kWidth +
                                                     static_cast<std::size_t>(c.pixelColumn)], 0U);
        EXPECT_FLOAT_EQ(c.displayScale, s.config.heightScaleMultiplier);
    }

    // The canopy mesh and the GLB are exactly as before.
    VegetationRun again(s, VegetationConfig{});
    const GlbBuildResult after = renderWith(s, presentation, &again.input);
    EXPECT_EQ(after.compressedGlbByteBuffer, before.compressedGlbByteBuffer);
    EXPECT_EQ(again.canopy.primitive.positions, vegetation.canopy.primitive.positions);
    EXPECT_EQ(again.canopy.primitive.indices, vegetation.canopy.primitive.indices);
    const tinygltf::Model model = loadGlb(after.compressedGlbByteBuffer);
    EXPECT_EQ(model.nodes.size(), 2U); // Base + canopy: no tree nodes in stage 4
    EXPECT_EQ(buildingDigest(model), 14738508419874179917ULL);
}

// --- Stage 5: instanced tree proxies ----------------------------------------

namespace
{
std::vector<float> accessorFloats(const tinygltf::Model& model, int accessorIndex)
{
    const tinygltf::Accessor& accessor = model.accessors[static_cast<std::size_t>(accessorIndex)];
    const tinygltf::BufferView& view = model.bufferViews[static_cast<std::size_t>(accessor.bufferView)];
    const int components = accessor.type == TINYGLTF_TYPE_VEC4 ? 4 : accessor.type == TINYGLTF_TYPE_VEC3 ? 3 : 1;
    const float* data = reinterpret_cast<const float*>(model.buffers[static_cast<std::size_t>(view.buffer)].data.data() +
                                                       view.byteOffset + accessor.byteOffset);
    return {data, data + accessor.count * static_cast<std::size_t>(components)};
}

struct TreeScene
{
    ProductionScene s;
    ScenePresentation presentation{ScenePresentation::FLAT_URBAN};
    std::unique_ptr<VegetationRun> vegetation;
    VegetationTreeCandidates trees;
    VegetationTreeInstances instances;

    explicit TreeScene(VegetationConfig config = VegetationConfig{})
    {
        addCourtyardTrees(s);
        for (const auto& [cx, cy] : std::vector<std::pair<double, double>>{{12.0, 50.0}, {34.0, 60.0}})
            for (int y = 34; y < 72; ++y)
                for (int x = 0; x < 46; ++x)
                {
                    const double d = std::hypot((x + 0.5 - cx) * 0.5, (y + 0.5 - cy) * 0.6);
                    float& h = s.surface.ndsm.data[static_cast<std::size_t>(y) * kWidth + x];
                    h = std::max(h, static_cast<float>(9.0 + 5.0 * std::exp(-d * d / (2 * 2.5 * 2.5))));
                }
        // An isolated street tree east of the third building.
        for (int y = 40; y < 60; ++y)
            for (int x = 76; x < 92; ++x)
            {
                const double d = std::hypot((x + 0.5 - 84) * 0.5, (y + 0.5 - 50) * 0.6);
                const float h = static_cast<float>(8.0 * std::exp(-d * d / (2 * 1.6 * 1.6)));
                if (h < 0.5F) continue;
                const std::size_t i = static_cast<std::size_t>(y) * kWidth + x;
                s.semantics.finalClassMap.data[i] = SemanticClass::VEGETATION;
                s.semantics.vegetationProbability.data[i] = 0.9F;
                s.surface.ndsm.data[i] = h;
            }
        for (std::size_t i = 0; i < s.surface.dsm.data.size(); ++i)
            s.surface.dsm.data[i] = s.surface.dtm.data[i] + s.surface.ndsm.data[i];
        presentation = s.resolve(ScenePresentationPolicy::AUTO);
        vegetation = std::make_unique<VegetationRun>(s, config);
        VegetationTreeInput input;
        input.mask = &vegetation->mask;
        input.classification = &vegetation->classes;
        input.heights = &vegetation->heights;
        input.semantics = &s.semantics;
        input.surface = &s.surface;
        input.metadata = &s.metadata;
        input.frame = LocalFrameTransformer::create(s.metadata, s.surface);
        input.terrainConfig.elevationSource = TerrainElevationSource::FLAT_PRESENTATION;
        input.presentation = presentation;
        input.buildingDisplayHeightScale = s.config.heightScaleMultiplier;
        input.config = vegetation->input.config;
        trees = VegetationTreeCandidateGenerator::generate(input);
        vegetation->input.treeCandidates = &trees;
        vegetation->input.treeOutput = &instances;
    }
};
} // namespace

TEST(Sat2Lod2OrthophotoIntegrationTest, TreesAreInstancedAfterAnUnchangedSceneAndCanopy)
{
    VegetationConfig canopyOnlyConfig;
    canopyOnlyConfig.trees = false;
    TreeScene canopyOnly(canopyOnlyConfig);
    canopyOnly.vegetation->input.treeCandidates = nullptr;
    const GlbBuildResult stage3 = renderWith(canopyOnly.s, canopyOnly.presentation, &canopyOnly.vegetation->input);

    TreeScene full;
    ASSERT_TRUE(full.trees.enabled);
    ASSERT_GE(full.trees.candidates.size(), 2U);
    const GlbBuildResult glb = renderWith(full.s, full.presentation, &full.vegetation->input);
    ASSERT_FALSE(glb.compressedGlbByteBuffer.empty()) << ::testing::PrintToString(glb.geometryWarnings);
    const tinygltf::Model a = loadGlb(stage3.compressedGlbByteBuffer);
    const tinygltf::Model b = loadGlb(glb.compressedGlbByteBuffer);

    // Base scene and canopy: unchanged.
    ASSERT_EQ(a.nodes.size(), 2U);
    ASSERT_GT(b.nodes.size(), 2U);
    EXPECT_EQ(b.nodes[0].mesh, 0);
    EXPECT_EQ(b.nodes[1].name, "VEGETATION_CANOPY");
    for (std::size_t m = 0; m < 2; ++m)
        for (std::size_t p = 0; p < a.meshes[m].primitives.size(); ++p)
        {
            const auto& pa = a.meshes[m].primitives[p];
            const auto& pb = b.meshes[m].primitives[p];
            EXPECT_EQ(pa.material, pb.material);
            for (const char* attribute : {"POSITION", "NORMAL", "TEXCOORD_0", "_FEATURE_ID_0"})
                EXPECT_EQ(decodeDracoAttribute(a, pa, attribute), decodeDracoAttribute(b, pb, attribute)) << attribute;
            EXPECT_EQ(decodedIndices(a, pa), decodedIndices(b, pb));
        }
    for (std::size_t m = 0; m < a.materials.size(); ++m) EXPECT_EQ(materialJson(a.materials[m]), materialJson(b.materials[m]));
    ASSERT_EQ(a.textures.size(), b.textures.size());
    EXPECT_EQ(buildingDigest(b), 14738508419874179917ULL);

    // EXT_mesh_gpu_instancing: used, not required.
    EXPECT_NE(std::find(b.extensionsUsed.begin(), b.extensionsUsed.end(), "EXT_mesh_gpu_instancing"), b.extensionsUsed.end());
    EXPECT_EQ(std::find(b.extensionsRequired.begin(), b.extensionsRequired.end(), "EXT_mesh_gpu_instancing"),
              b.extensionsRequired.end());
    ASSERT_FALSE(full.instances.empty());
    std::map<std::string, const TreeBatch*> batchByName;
    for (const TreeBatch& batch : full.instances.batches) batchByName[batch.name] = &batch;
    std::size_t treeNodes = 0;
    for (std::size_t n = 2; n < b.nodes.size(); ++n)
    {
        const tinygltf::Node& node = b.nodes[n];
        ASSERT_EQ(node.name.rfind("VEGETATION_TREES_", 0), 0U) << node.name;
        ASSERT_TRUE(batchByName.count(node.name)) << node.name;
        const TreeBatch& batch = *batchByName.at(node.name);
        ++treeNodes;
        EXPECT_EQ(node.extras.Get("geometrySemantic").Get<std::string>(), "VEGETATION_TREE_INSTANCES");
        EXPECT_TRUE(node.extras.Get("visualizationProxy").Get<bool>());
        EXPECT_FALSE(node.extras.Get("scientificSurface").Get<bool>());
        EXPECT_FALSE(node.extras.Get("speciesInferred").Get<bool>());
        EXPECT_EQ(node.extras.Get("heightSource").Get<std::string>(), "NDSM");
        const auto extension = node.extensions.find("EXT_mesh_gpu_instancing");
        ASSERT_NE(extension, node.extensions.end());
        const tinygltf::Value& attributes = extension->second.Get("attributes");
        const int t = attributes.Get("TRANSLATION").GetNumberAsInt();
        const int r = attributes.Get("ROTATION").GetNumberAsInt();
        const int sc = attributes.Get("SCALE").GetNumberAsInt();
        for (const auto& [index, type] : {std::pair{t, TINYGLTF_TYPE_VEC3}, std::pair{r, TINYGLTF_TYPE_VEC4}, std::pair{sc, TINYGLTF_TYPE_VEC3}})
        {
            EXPECT_EQ(b.accessors[static_cast<std::size_t>(index)].componentType, TINYGLTF_COMPONENT_TYPE_FLOAT);
            EXPECT_EQ(b.accessors[static_cast<std::size_t>(index)].type, type);
            EXPECT_EQ(b.accessors[static_cast<std::size_t>(index)].count, batch.instances.size());
        }
        const auto translations = accessorFloats(b, t), rotations = accessorFloats(b, r), scales = accessorFloats(b, sc);
        // Per-instance colour tint (cosmetic): one rgb per instance, in [0, 1].
        ASSERT_TRUE(attributes.Has("_COLOR_0"));
        const auto tints = accessorFloats(b, attributes.Get("_COLOR_0").GetNumberAsInt());
        ASSERT_EQ(tints.size(), batch.instances.size() * 3);
        for (float value : tints) EXPECT_TRUE(value > 0.5F && value <= 1.0F);
        for (std::size_t k = 0; k < batch.instances.size(); ++k)
        {
            const TreeInstance& instance = full.instances.instances[batch.instances[k]];
            for (int c = 0; c < 3; ++c)
            {
                EXPECT_FLOAT_EQ(translations[k * 3 + c], instance.translation[static_cast<std::size_t>(c)]);
                EXPECT_FLOAT_EQ(scales[k * 3 + c], instance.scale[static_cast<std::size_t>(c)]);
            }
            const float* q = &rotations[k * 4];
            EXPECT_NEAR(q[0] * q[0] + q[1] * q[1] + q[2] * q[2] + q[3] * q[3], 1.0F, 1e-6F);
            // Grounded at Y = 0 (flat_urban) and topped at the measured display height.
            const TreeCandidate* source = nullptr;
            for (const TreeCandidate& c : full.trees.candidates)
                if (c.id == instance.candidateId) source = &c;
            ASSERT_NE(source, nullptr);
            EXPECT_FLOAT_EQ(translations[k * 3 + 1], 0.0F);
            EXPECT_FLOAT_EQ(translations[k * 3 + 1] + scales[k * 3 + 1], source->topY);
            EXPECT_LE(scales[k * 3], source->clearanceMetres + 1e-4F); // Crown never reaches the building buffer
        }
        // The prototype mesh: base at 0, top at 1 in instance space.
        for (const tinygltf::Primitive& primitive : b.meshes[static_cast<std::size_t>(node.mesh)].primitives)
        {
            const tinygltf::Accessor& position = b.accessors[static_cast<std::size_t>(primitive.attributes.at("POSITION"))];
            EXPECT_GE(position.minValues[1], 0.0);
            EXPECT_LE(position.maxValues[1], 1.0);
        }
    }
    EXPECT_EQ(treeNodes, full.instances.batches.size());
}

TEST(Sat2Lod2OrthophotoIntegrationTest, VegetationFlagsSelectEachRenderingPathExactly)
{
    // Trees off: exactly the stage-3 canopy GLB.
    VegetationConfig treesOff;
    treesOff.trees = false;
    TreeScene canopyOnly(treesOff);
    canopyOnly.vegetation->input.treeCandidates = nullptr;
    const auto stage3 = renderWith(canopyOnly.s, canopyOnly.presentation, &canopyOnly.vegetation->input).compressedGlbByteBuffer;
    TreeScene withTreesFlagOff;
    withTreesFlagOff.vegetation->input.config.trees = false; // Candidates present, flag off
    EXPECT_EQ(renderWith(withTreesFlagOff.s, withTreesFlagOff.presentation, &withTreesFlagOff.vegetation->input).compressedGlbByteBuffer,
              stage3);

    // Canopy off, trees on: tree nodes directly after the base scene.
    TreeScene treesOnly;
    treesOnly.vegetation->input.config.canopy = false;
    const tinygltf::Model only = loadGlb(renderWith(treesOnly.s, treesOnly.presentation, &treesOnly.vegetation->input).compressedGlbByteBuffer);
    ASSERT_GT(only.nodes.size(), 1U);
    EXPECT_EQ(only.nodes[1].name.rfind("VEGETATION_TREES_", 0), 0U);
    for (const tinygltf::Node& node : only.nodes) EXPECT_NE(node.name, "VEGETATION_CANOPY");
    EXPECT_EQ(buildingDigest(only), 14738508419874179917ULL);

    // No vegetation at all: the original validated path.
    const auto original = renderWith(treesOnly.s, treesOnly.presentation, nullptr).compressedGlbByteBuffer;
    EXPECT_EQ(loadGlb(original).nodes.size(), 1U);

    // No candidates: no tree nodes.
    TreeScene empty;
    empty.trees.candidates.clear();
    empty.vegetation->input.config.canopy = false;
    EXPECT_EQ(renderWith(empty.s, empty.presentation, &empty.vegetation->input).compressedGlbByteBuffer, original);
}

// --- Stage 5A: external vegetation assets -----------------------------------

namespace
{
// The smaller model's arrays and binary chunk are prefixes of the larger one's.
void expectPrefix(const tinygltf::Model& small, const tinygltf::Model& large)
{
    ASSERT_LE(small.buffers[0].data.size(), large.buffers[0].data.size());
    EXPECT_TRUE(std::equal(small.buffers[0].data.begin(), small.buffers[0].data.end(), large.buffers[0].data.begin()));
    const auto prefix = [](const auto& a, const auto& b) {
        return a.size() <= b.size() && std::equal(a.begin(), a.end(), b.begin());
    };
    EXPECT_TRUE(prefix(small.accessors, large.accessors));
    EXPECT_TRUE(prefix(small.bufferViews, large.bufferViews));
    EXPECT_TRUE(prefix(small.meshes, large.meshes));
    EXPECT_TRUE(prefix(small.materials, large.materials));
    EXPECT_TRUE(prefix(small.nodes, large.nodes));
    EXPECT_TRUE(prefix(small.textures, large.textures));
    EXPECT_TRUE(prefix(small.samplers, large.samplers));
    ASSERT_LE(small.images.size(), large.images.size());
    for (std::size_t i = 0; i < small.images.size(); ++i)
    {
        EXPECT_EQ(small.images[i].bufferView, large.images[i].bufferView);
        EXPECT_EQ(small.images[i].mimeType, large.images[i].mimeType);
    }
}
} // namespace

TEST(Sat2Lod2OrthophotoIntegrationTest, ExternalBushesReplaceProceduralTreesAfterAnUnchangedSceneAndCanopy)
{
    VegetationConfig canopyOnlyConfig;
    canopyOnlyConfig.trees = false;
    TreeScene canopyOnly(canopyOnlyConfig);
    canopyOnly.vegetation->input.treeCandidates = nullptr;
    const tinygltf::Model stage3 = loadGlb(renderWith(canopyOnly.s, canopyOnly.presentation, &canopyOnly.vegetation->input).compressedGlbByteBuffer);

    TreeScene procedural;
    const auto proceduralGlb = renderWith(procedural.s, procedural.presentation, &procedural.vegetation->input).compressedGlbByteBuffer;
    VegetationConfig externalConfig;
    externalConfig.assetMode = VegetationAssetMode::EXTERNAL;
    TreeScene external(externalConfig);
    DenseForestProxies forest;
    external.vegetation->input.forestOutput = &forest;
    const GlbBuildResult glb = renderWith(external.s, external.presentation, &external.vegetation->input);
    ASSERT_FALSE(glb.compressedGlbByteBuffer.empty());
    EXPECT_TRUE(glb.geometryWarnings.empty()) << ::testing::PrintToString(glb.geometryWarnings);
    EXPECT_NE(glb.compressedGlbByteBuffer, proceduralGlb);
    const tinygltf::Model b = loadGlb(glb.compressedGlbByteBuffer);

    // Buildings, terrain and canopy: the stage-3 model is a byte-exact prefix.
    expectPrefix(stage3, b);
    EXPECT_EQ(buildingDigest(b), 14738508419874179917ULL);
    EXPECT_EQ(b.nodes[1].name, "VEGETATION_CANOPY");

    // flat_urban: never forest patches.
    EXPECT_TRUE(forest.empty());
    EXPECT_NE(forest.disabledReason.find("flat_urban"), std::string::npos);

    // No procedural polygon trees; one textured, alpha-tested bush prototype.
    for (const tinygltf::Material& m : b.materials) EXPECT_EQ(m.name.rfind("Vegetation_Tree_", 0), std::string::npos) << m.name;
    std::set<int> bushMeshes;
    std::map<uint32_t, int> drawnPerCandidate;
    for (std::size_t n = 2; n < b.nodes.size(); ++n)
    {
        const tinygltf::Node& node = b.nodes[n];
        ASSERT_EQ(node.name.rfind("VEGETATION_TREES_NEAR_SMALL_BUSH", 0), 0U) << node.name;
        EXPECT_EQ(node.extras.Get("assetSource").Get<std::string>(), "SMALL_BUSH");
        EXPECT_TRUE(node.extras.Get("visualizationProxy").Get<bool>());
        EXPECT_FALSE(node.extras.Get("scientificSurface").Get<bool>());
        EXPECT_FALSE(node.extras.Get("speciesInferred").Get<bool>());
        EXPECT_FALSE(node.extras.Get("externalGeographicDataUsed").Get<bool>());
        bushMeshes.insert(node.mesh);
        const tinygltf::Value& attributes = node.extensions.at("EXT_mesh_gpu_instancing").Get("attributes");
        EXPECT_FALSE(attributes.Has("_COLOR_0"));   // Authored texture, no procedural tint
        const auto translations = accessorFloats(b, attributes.Get("TRANSLATION").GetNumberAsInt());
        const auto scales = accessorFloats(b, attributes.Get("SCALE").GetNumberAsInt());
        for (std::size_t k = 0; k < translations.size() / 3; ++k)
        {
            const TreeCandidate* source = nullptr;
            for (const TreeCandidate& c : external.trees.candidates)
                if (std::abs(c.worldX - translations[k * 3]) < 1e-4 && std::abs(c.worldZ - translations[k * 3 + 2]) < 1e-4) source = &c;
            ASSERT_NE(source, nullptr);
            ++drawnPerCandidate[source->id];
            EXPECT_FLOAT_EQ(translations[k * 3 + 1], source->baseY);                          // Base
            EXPECT_FLOAT_EQ(translations[k * 3 + 1] + scales[k * 3 + 1], source->topY);       // Top
            EXPECT_LE(scales[k * 3], source->crownRadiusMetres + 1e-5F);                       // Crown radius
            EXPECT_GE(scales[k * 3], 0.9F * source->crownRadiusMetres - 1e-5F);
        }
    }
    ASSERT_EQ(bushMeshes.size(), 1U);   // One shared prototype for every bush
    EXPECT_EQ(drawnPerCandidate.size(), external.trees.candidates.size());
    for (const auto& [id, count] : drawnPerCandidate) EXPECT_EQ(count, 1) << id;   // Never twice
    const tinygltf::Mesh& mesh = b.meshes[static_cast<std::size_t>(*bushMeshes.begin())];
    ASSERT_EQ(mesh.primitives.size(), 1U);
    const tinygltf::Primitive& primitive = mesh.primitives[0];
    EXPECT_TRUE(primitive.attributes.count("TEXCOORD_0"));
    EXPECT_EQ(b.accessors[static_cast<std::size_t>(primitive.indices)].count, 960U);   // 320 triangles
    const tinygltf::Accessor& position = b.accessors[static_cast<std::size_t>(primitive.attributes.at("POSITION"))];
    EXPECT_NEAR(position.minValues[1], 0.0, 1e-5);
    EXPECT_NEAR(position.maxValues[1], 1.0, 1e-5);
    const tinygltf::Material& material = b.materials[static_cast<std::size_t>(primitive.material)];
    EXPECT_EQ(material.alphaMode, "MASK");
    EXPECT_NEAR(material.alphaCutoff, 0.45, 1e-9);
    EXPECT_DOUBLE_EQ(material.pbrMetallicRoughness.metallicFactor, 0.0);
    ASSERT_GE(material.pbrMetallicRoughness.baseColorTexture.index, static_cast<int>(stage3.textures.size()));
    const tinygltf::Image& image = b.images[static_cast<std::size_t>(b.textures[static_cast<std::size_t>(material.pbrMetallicRoughness.baseColorTexture.index)].source)];
    EXPECT_EQ(image.mimeType, "image/png");
    EXPECT_EQ(image.component, 4);
}

TEST(Sat2Lod2OrthophotoIntegrationTest, AssetModeFlagsKeepEveryRollbackPathExact)
{
    // procedural (explicit) == the stage-5 default.
    TreeScene byDefault;
    const auto stage5 = renderWith(byDefault.s, byDefault.presentation, &byDefault.vegetation->input).compressedGlbByteBuffer;
    VegetationConfig proceduralConfig;
    proceduralConfig.assetMode = VegetationAssetMode::PROCEDURAL;
    proceduralConfig.forestProxies = true;
    TreeScene procedural(proceduralConfig);
    EXPECT_EQ(renderWith(procedural.s, procedural.presentation, &procedural.vegetation->input).compressedGlbByteBuffer, stage5);

    // External with trees off: exactly the stage-3 canopy GLB.
    VegetationConfig treesOff;
    treesOff.trees = false;
    TreeScene canopyOnly(treesOff);
    canopyOnly.vegetation->input.treeCandidates = nullptr;
    const auto stage3 = renderWith(canopyOnly.s, canopyOnly.presentation, &canopyOnly.vegetation->input).compressedGlbByteBuffer;
    VegetationConfig externalTreesOff;
    externalTreesOff.assetMode = VegetationAssetMode::EXTERNAL;
    externalTreesOff.trees = false;
    TreeScene external(externalTreesOff);
    EXPECT_EQ(renderWith(external.s, external.presentation, &external.vegetation->input).compressedGlbByteBuffer, stage3);

    // External with forest proxies off in flat_urban: identical to forest on (none placed here).
    VegetationConfig on, off;
    on.assetMode = off.assetMode = VegetationAssetMode::EXTERNAL;
    off.forestProxies = false;
    TreeScene withForest(on), withoutForest(off);
    EXPECT_EQ(renderWith(withForest.s, withForest.presentation, &withForest.vegetation->input).compressedGlbByteBuffer,
              renderWith(withoutForest.s, withoutForest.presentation, &withoutForest.vegetation->input).compressedGlbByteBuffer);

    // External, canopy off: bushes directly after the base scene.
    VegetationConfig bushesOnly;
    bushesOnly.assetMode = VegetationAssetMode::EXTERNAL;
    bushesOnly.canopy = false;
    TreeScene only(bushesOnly);
    const tinygltf::Model model = loadGlb(renderWith(only.s, only.presentation, &only.vegetation->input).compressedGlbByteBuffer);
    ASSERT_GT(model.nodes.size(), 1U);
    EXPECT_EQ(model.nodes[1].name.rfind("VEGETATION_TREES_NEAR_SMALL_BUSH", 0), 0U);
    EXPECT_EQ(buildingDigest(model), 14738508419874179917ULL);
    // No vegetation: the original path.
    EXPECT_EQ(loadGlb(renderWith(only.s, only.presentation, nullptr).compressedGlbByteBuffer).nodes.size(), 1U);
}

TEST(Sat2Lod2OrthophotoIntegrationTest, UrbanParksBecomeGardensWithoutTallBushesOrCanopyMounds)
{
    TreeScene plainScene;
    const tinygltf::Model plain = loadGlb(renderWith(plainScene.s, plainScene.presentation, nullptr).compressedGlbByteBuffer);
    VegetationConfig externalConfig;
    externalConfig.assetMode = VegetationAssetMode::EXTERNAL;
    TreeScene garden(externalConfig);
    ASSERT_EQ(garden.presentation, ScenePresentation::FLAT_URBAN);
    VegetationCover cover;
    garden.vegetation->input.semantics = &garden.s.semantics;
    garden.vegetation->input.coverOutput = &cover;
    const GlbBuildResult glb = renderWith(garden.s, garden.presentation, &garden.vegetation->input);
    EXPECT_TRUE(glb.geometryWarnings.empty()) << ::testing::PrintToString(glb.geometryWarnings);
    const tinygltf::Model b = loadGlb(glb.compressedGlbByteBuffer);

    // Buildings and terrain untouched (the plain model is a prefix); no canopy mound.
    expectPrefix(plain, b);
    EXPECT_EQ(buildingDigest(b), 14738508419874179917ULL);
    ASSERT_TRUE(cover.enabled) << cover.disabledReason;
    EXPECT_EQ(cover.mode, VegetationCoverMode::GARDEN);
    ASSERT_FALSE(cover.empty());
    std::size_t drawn = 0;
    for (std::size_t n = 1; n < b.nodes.size(); ++n)
    {
        const tinygltf::Node& node = b.nodes[n];
        EXPECT_NE(node.name, "VEGETATION_CANOPY");
        // Garden: only cover shrubs; candidates are not drawn as tree-sized bushes.
        ASSERT_EQ(node.name.rfind("VEGETATION_COVER_NEAR_SMALL_BUSH_CHUNK_", 0), 0U) << node.name;
        EXPECT_EQ(node.extras.Get("geometrySemantic").Get<std::string>(), "VEGETATION_COVER_PROXY");
        EXPECT_EQ(node.extras.Get("coverMode").Get<std::string>(), "GARDEN");
        EXPECT_FALSE(node.extras.Get("individualTreesResolved").Get<bool>());
        EXPECT_TRUE(node.extras.Get("visualizationProxy").Get<bool>());
        const tinygltf::Value& attributes = node.extensions.at("EXT_mesh_gpu_instancing").Get("attributes");
        const auto translations = accessorFloats(b, attributes.Get("TRANSLATION").GetNumberAsInt());
        const auto scales = accessorFloats(b, attributes.Get("SCALE").GetNumberAsInt());
        for (std::size_t k = 0; k < translations.size() / 3; ++k)
        {
            EXPECT_FLOAT_EQ(translations[k * 3 + 1], 0.0F);                     // On the flat_urban ground
            EXPECT_LE(scales[k * 3 + 1], 1.5F * garden.s.config.heightScaleMultiplier + 1e-4F);         // Garden shrubs, display scale
            ++drawn;
        }
    }
    EXPECT_EQ(drawn, cover.shrubs.size());
    for (const TreeInstance& i : garden.instances.instances) EXPECT_FALSE(i.rendered);
}
