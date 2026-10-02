#include "BuildingReconstruction/HybridRoofGraphImporter.h"
#include "BuildingReconstructionTestSupport.h"

#include <gtest/gtest.h>
#include <json/json.h>

#include <cmath>
#include <fstream>
#include <string>

using namespace depthwizard;
using namespace depthwizard::test;

namespace
{

std::string findExamplesDir()
{
    const std::vector<std::string> candidates = {
        "contracts/examples/",
        "../contracts/examples/",
        "../../contracts/examples/",
        "../../../contracts/examples/",
        "drogon_service/gis_service/contracts/examples/",
        "/home/satadru345/DepthWizard/drogon_service/gis_service/contracts/examples/"
    };
    for (const auto& c : candidates)
    {
        std::ifstream test(c + "valid_building_minimal.json");
        if (test.good()) return c;
    }
    return "contracts/examples/";
}

Json::Value point(double col, double row)
{
    Json::Value p(Json::arrayValue);
    p.append(col);
    p.append(row);
    return p;
}

Json::Value rectRing(double left, double top, double right, double bottom)
{
    Json::Value ring(Json::arrayValue);
    ring.append(point(left, top));
    ring.append(point(right, top));
    ring.append(point(right, bottom));
    ring.append(point(left, bottom));
    return ring;
}

Json::Value minimalDocument(int width = 512, int height = 512,
                            const std::string& conv = "pixel_edge_column_row")
{
    Json::Value doc(Json::objectValue);
    doc["schema"] = "depthwizard.roofgraph.v1";
    doc["raster_width"] = width;
    doc["raster_height"] = height;
    doc["coordinate_convention"] = conv;

    Json::Value building(Json::objectValue);
    building["id"] = "test-building-1";
    building["footprint_proposal"] = rectRing(10.0, 10.0, 40.0, 30.0);
    building["roofprint_proposal"] = rectRing(10.0, 10.0, 40.0, 30.0);
    building["holes"] = Json::Value(Json::arrayValue);

    Json::Value scores(Json::objectValue);
    scores["semantic"] = 0.95;
    scores["ndsm"] = 0.88;
    scores["sam2"] = 0.91;
    scores["kibs"] = 0.0;
    building["scores"] = scores;

    building["roof_sections"] = Json::Value(Json::arrayValue);
    building["provenance"] = Json::Value(Json::arrayValue);

    doc["buildings"] = Json::Value(Json::arrayValue);
    doc["buildings"].append(building);

    return doc;
}

} // namespace

TEST(HybridRoofGraphImporterTest, ParsesValidMinimalFixture)
{
    const std::string path = findExamplesDir() + "valid_building_minimal.json";
    const auto result = HybridRoofGraphImporter::parseFile(path, true);

    ASSERT_TRUE(result.success) << "Errors: " << (result.errors.empty() ? "" : result.errors[0]);
    EXPECT_EQ(result.document.schema, "depthwizard.roofgraph.v1");
    EXPECT_EQ(result.document.rasterWidth, 512);
    EXPECT_EQ(result.document.rasterHeight, 512);
    EXPECT_EQ(result.document.coordinateConvention, RoofGraphCoordinateConvention::PIXEL_EDGE_COLUMN_ROW);
    ASSERT_EQ(result.document.buildings.size(), 1U);

    const auto& b = result.document.buildings[0];
    EXPECT_EQ(b.id, "building-1");
    EXPECT_EQ(b.footprintProposal.outerRing.size(), 4U);
    EXPECT_FLOAT_EQ(b.scores.semantic, 0.95f);
    EXPECT_FLOAT_EQ(b.scores.ndsm, 0.88f);
    EXPECT_FLOAT_EQ(b.scores.sam2, 0.92f);
    ASSERT_EQ(b.roofSections.size(), 1U);
    EXPECT_EQ(b.roofSections[0].typeHint, "flat");
    EXPECT_EQ(b.roofSections[0].corners.size(), 4U);
}

TEST(HybridRoofGraphImporterTest, ParsesValidComplexFixtureWithHolesAndSections)
{
    const std::string path = findExamplesDir() + "valid_building_complex.json";
    const auto result = HybridRoofGraphImporter::parseFile(path, true);

    ASSERT_TRUE(result.success) << "Errors: " << (result.errors.empty() ? "" : result.errors[0]);
    EXPECT_EQ(result.document.rasterWidth, 1024);
    EXPECT_EQ(result.document.rasterHeight, 1024);
    ASSERT_EQ(result.document.buildings.size(), 2U);

    // Building 1: Courtyard building
    const auto& b1 = result.document.buildings[0];
    EXPECT_EQ(b1.id, "candidate-courtyard-101");
    EXPECT_EQ(b1.footprintProposal.outerRing.size(), 4U);
    ASSERT_EQ(b1.footprintProposal.holes.size(), 1U);
    EXPECT_EQ(b1.footprintProposal.holes[0].size(), 4U);
    ASSERT_EQ(b1.roofSections.size(), 1U);
    EXPECT_EQ(b1.roofSections[0].holes.size(), 1U);
    ASSERT_EQ(b1.roofSections[0].corners.size(), 4U);
    EXPECT_TRUE(b1.roofSections[0].corners[0].heightClassM.has_value());
    EXPECT_FLOAT_EQ(*b1.roofSections[0].corners[0].heightClassM, 12.0f);

    // Building 2: Gable building with two adjacent sections
    const auto& b2 = result.document.buildings[1];
    EXPECT_EQ(b2.id, "candidate-gable-102");
    ASSERT_EQ(b2.roofSections.size(), 2U);
    EXPECT_EQ(b2.roofSections[0].id, "102-north-pitch");
    EXPECT_EQ(b2.roofSections[1].id, "102-south-pitch");
    EXPECT_EQ(b2.roofSections[0].adjacentSections, std::vector<std::string>{"102-south-pitch"});
    EXPECT_EQ(b2.roofSections[1].adjacentSections, std::vector<std::string>{"102-north-pitch"});
    EXPECT_EQ(b2.provenance.size(), 2U);
}

TEST(HybridRoofGraphImporterTest, RoundTripSerializationPreservesStructureAndValues)
{
    const std::string path = findExamplesDir() + "valid_building_complex.json";
    const auto initial = HybridRoofGraphImporter::parseFile(path, true);
    ASSERT_TRUE(initial.success);

    // Serialize to JSON string
    const std::string jsonStr = HybridRoofGraphImporter::toJsonString(initial.document);

    // Parse back from serialized JSON
    const auto roundTripped = HybridRoofGraphImporter::parseJson(jsonStr, true);
    ASSERT_TRUE(roundTripped.success) << "Errors: " << (roundTripped.errors.empty() ? "" : roundTripped.errors[0]);

    EXPECT_EQ(roundTripped.document.schema, initial.document.schema);
    EXPECT_EQ(roundTripped.document.rasterWidth, initial.document.rasterWidth);
    EXPECT_EQ(roundTripped.document.rasterHeight, initial.document.rasterHeight);
    EXPECT_EQ(roundTripped.document.coordinateConvention, initial.document.coordinateConvention);
    ASSERT_EQ(roundTripped.document.buildings.size(), initial.document.buildings.size());

    for (std::size_t i = 0; i < initial.document.buildings.size(); ++i)
    {
        const auto& origB = initial.document.buildings[i];
        const auto& rtB = roundTripped.document.buildings[i];
        EXPECT_EQ(origB.id, rtB.id);
        EXPECT_EQ(origB.footprintProposal.outerRing.size(), rtB.footprintProposal.outerRing.size());
        for (std::size_t j = 0; j < origB.footprintProposal.outerRing.size(); ++j)
        {
            EXPECT_NEAR(origB.footprintProposal.outerRing[j].column, rtB.footprintProposal.outerRing[j].column, 1e-5);
            EXPECT_NEAR(origB.footprintProposal.outerRing[j].row, rtB.footprintProposal.outerRing[j].row, 1e-5);
        }
        EXPECT_FLOAT_EQ(origB.scores.semantic, rtB.scores.semantic);
        EXPECT_FLOAT_EQ(origB.scores.ndsm, rtB.scores.ndsm);
        EXPECT_EQ(origB.roofSections.size(), rtB.roofSections.size());
    }
}

TEST(HybridRoofGraphImporterTest, ExplicitPixelEdgeCoordinateConventionDoesNotAddHalfPixel)
{
    // Spatial metadata with affine transform:
    // easting = 500000 + col * 0.5
    // northing = 2000000 - row * 0.5
    const SpatialMetadata metadata = makeProjectedMetadata(512, 512, 0.5, -0.5);

    // In pixel_edge_column_row, pixel (10.0, 20.0) is at exact pixel edges
    const PixelPoint edgePoint{10.0, 20.0};
    const ProjectedPoint proj = HybridRoofGraphImporter::toProjected(edgePoint, metadata);

    // Verify exact projected coordinates without any +0.5 shift:
    // Sat2Lod2Importer added +0.5 (yielding 500000 + 10.5*0.5 = 500005.25)
    // HybridRoofGraphImporter preserves exact pixel edges: 500000 + 10.0*0.5 = 500005.00
    EXPECT_DOUBLE_EQ(proj.easting, 500000.0 + 10.0 * 0.5);
    EXPECT_DOUBLE_EQ(proj.northing, 2000000.0 - 20.0 * 0.5);
}

TEST(HybridRoofGraphImporterTest, PixelCentreConventionAppliesHalfPixelShiftExplicitly)
{
    // Document declaring pixel_centre_column_row
    Json::Value doc = minimalDocument(512, 512, "pixel_centre_column_row");
    const auto result = HybridRoofGraphImporter::parse(doc, true);

    ASSERT_TRUE(result.success);
    EXPECT_EQ(result.document.coordinateConvention, RoofGraphCoordinateConvention::PIXEL_CENTRE_COLUMN_ROW);
    EXPECT_FALSE(result.warnings.empty());

    // Coordinate [10.0, 10.0] in pixel_centre should become [10.5, 10.5] in canonical edge coordinates
    const auto& pt = result.document.buildings[0].footprintProposal.outerRing[0];
    EXPECT_DOUBLE_EQ(pt.column, 10.5);
    EXPECT_DOUBLE_EQ(pt.row, 10.5);
}

TEST(HybridRoofGraphImporterTest, RejectsImplicitClosingVertexInStrictMode)
{
    const std::string path = findExamplesDir() + "invalid_closing_vertex.json";
    const auto result = HybridRoofGraphImporter::parseFile(path, true);

    EXPECT_FALSE(result.success);
    ASSERT_FALSE(result.errors.empty());
    EXPECT_NE(result.errors[0].find("duplicate closing vertex"), std::string::npos);
}

TEST(HybridRoofGraphImporterTest, StripsClosingVertexWithWarningInLenientMode)
{
    const std::string path = findExamplesDir() + "invalid_closing_vertex.json";
    const auto result = HybridRoofGraphImporter::parseFile(path, false);

    EXPECT_TRUE(result.success);
    EXPECT_FALSE(result.warnings.empty());
    // After stripping redundant closing vertex, square has 4 points
    EXPECT_EQ(result.document.buildings[0].footprintProposal.outerRing.size(), 4U);
}

TEST(HybridRoofGraphImporterTest, RejectsDuplicateBuildingIds)
{
    const std::string path = findExamplesDir() + "invalid_duplicate_ids.json";
    const auto result = HybridRoofGraphImporter::parseFile(path, true);

    EXPECT_FALSE(result.success);
    ASSERT_FALSE(result.errors.empty());
    EXPECT_NE(result.errors[0].find("Duplicate building ID"), std::string::npos);
}

TEST(HybridRoofGraphImporterTest, RejectsOutOfBoundsCoordinatesInStrictMode)
{
    const std::string path = findExamplesDir() + "invalid_out_of_bounds.json";
    const auto result = HybridRoofGraphImporter::parseFile(path, true);

    EXPECT_FALSE(result.success);
    ASSERT_FALSE(result.errors.empty());
    EXPECT_NE(result.errors[0].find("outside raster bounds"), std::string::npos);
}

TEST(HybridRoofGraphImporterTest, RejectsOutOfRangeScoresInStrictMode)
{
    const std::string path = findExamplesDir() + "invalid_scores_range.json";
    const auto result = HybridRoofGraphImporter::parseFile(path, true);

    EXPECT_FALSE(result.success);
    ASSERT_FALSE(result.errors.empty());
    EXPECT_NE(result.errors[0].find("out of range [0, 1]"), std::string::npos);
}

TEST(HybridRoofGraphImporterTest, RejectsSelfIntersectingPolygonInStrictMode)
{
    const std::string path = findExamplesDir() + "invalid_self_intersection.json";
    const auto result = HybridRoofGraphImporter::parseFile(path, true);

    EXPECT_FALSE(result.success);
    ASSERT_FALSE(result.errors.empty());
    EXPECT_NE(result.errors[0].find("self-intersecting"), std::string::npos);
}

TEST(HybridRoofGraphImporterTest, RejectsTooFewVertices)
{
    const std::string path = findExamplesDir() + "invalid_too_few_vertices.json";
    const auto result = HybridRoofGraphImporter::parseFile(path, true);

    EXPECT_FALSE(result.success);
    ASSERT_FALSE(result.errors.empty());
    EXPECT_NE(result.errors[0].find("fewer than 3"), std::string::npos);
}

TEST(HybridRoofGraphImporterTest, ConvertsToBuildingCollectionWithCalibratedNdsmHeight)
{
    const int w = 60, h = 40;
    SpatialMetadata metadata = makeProjectedMetadata(w, h, 0.5, -0.5);
    SemanticScene semantics = makeSemanticScene(w, h);
    GeoreferencedSurfaceBundle surface = makeSurface(w, h, 50.0F, 0.0F);
    surface.spatialMetadata = metadata;
    RasterGrid<float> ndsm = makeConstantGrid(w, h, 0.0F);

    fillRectangle(semantics.finalClassMap, 10, 10, 40, 30, SemanticClass::BUILDING);
    fillRectangle(semantics.buildingProbability, 10, 10, 40, 30, 0.9F);
    fillRectangle(ndsm, 10, 10, 40, 30, 15.5F);

    Json::Value doc = minimalDocument(w, h, "pixel_edge_column_row");
    const auto importResult = HybridRoofGraphImporter::parse(doc, true);
    ASSERT_TRUE(importResult.success);

    BuildingReconstructionConfig config;
    config.heightScaleMultiplier = 1.0F;
    std::vector<std::string> warnings;
    const auto collection = HybridRoofGraphImporter::toBuildingCollection(
        importResult.document, semantics, surface, metadata, config, ndsm, warnings);

    ASSERT_EQ(collection.buildings.size(), 1U);
    const auto& building = collection.buildings[0];
    EXPECT_NEAR(building.representativeBaseElevation, 50.0F, 1e-4);
    EXPECT_NEAR(building.heightAboveGround, 15.5F, 1e-4);
    EXPECT_NEAR(building.roofElevation, 65.5F, 1e-4);
    EXPECT_GT(building.footprintAreaSquareMetres, 0.0F);
}
