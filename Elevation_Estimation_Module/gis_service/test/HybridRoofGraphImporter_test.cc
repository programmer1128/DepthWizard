#include "BuildingReconstruction/HybridRoofGraphImporter.h"
#include "BuildingReconstructionTestSupport.h"

#include <gtest/gtest.h>
#include <json/json.h>

#include <algorithm>
#include <cmath>
#include <filesystem>
#include <fstream>
#include <limits>
#include <sstream>
#include <string>
#include <vector>

using namespace depthwizard;
using namespace depthwizard::test;

namespace
{

const std::filesystem::path kExamples = std::filesystem::path(DEPTHWIZARD_CONTRACTS_DIR) / "examples";

Json::Value loadJson(const std::filesystem::path& path)
{
    std::ifstream file(path);
    Json::Value root;
    Json::CharReaderBuilder builder;
    std::string errors;
    EXPECT_TRUE(Json::parseFromStream(builder, file, &root, &errors)) << path << ": " << errors;
    return root;
}

std::vector<std::filesystem::path> fixtures(const std::string& prefix)
{
    std::vector<std::filesystem::path> paths;
    for (const auto& entry : std::filesystem::directory_iterator(kExamples))
    {
        const std::string name = entry.path().filename().string();
        if (name.rfind(prefix, 0) == 0 && entry.path().extension() == ".json") paths.push_back(entry.path());
    }
    std::sort(paths.begin(), paths.end());
    return paths;
}

bool hasMessage(const std::vector<std::string>& messages, const std::string& code)
{
    return std::any_of(messages.begin(), messages.end(),
                       [&](const std::string& message) { return message.rfind(code + ":", 0) == 0; });
}

std::string joined(const std::vector<std::string>& messages)
{
    std::string text;
    for (const auto& message : messages) text += "\n  " + message;
    return text;
}

Json::Value point(double column, double row)
{
    Json::Value value(Json::arrayValue);
    value.append(column);
    value.append(row);
    return value;
}

// Positive image-space area: the contract's outer-ring winding.
Json::Value rect(double left, double top, double right, double bottom)
{
    Json::Value ring(Json::arrayValue);
    ring.append(point(left, top));
    ring.append(point(right, top));
    ring.append(point(right, bottom));
    ring.append(point(left, bottom));
    return ring;
}

// Negative image-space area: the contract's hole winding.
Json::Value holeRect(double left, double top, double right, double bottom)
{
    Json::Value ring(Json::arrayValue);
    ring.append(point(left, top));
    ring.append(point(left, bottom));
    ring.append(point(right, bottom));
    ring.append(point(right, top));
    return ring;
}

Json::Value document(int width = 100, int height = 100)
{
    Json::Value root(Json::objectValue);
    root["schema"] = "depthwizard.roofgraph.v1";
    root["raster_width"] = width;
    root["raster_height"] = height;
    root["coordinate_convention"] = "pixel_edge_column_row";

    Json::Value building(Json::objectValue);
    building["id"] = "b";
    building["footprint_proposal"] = rect(10, 10, 50, 40);
    Json::Value section(Json::objectValue);
    section["id"] = "b-0";
    section["polygon"] = rect(10, 10, 50, 40);
    Json::Value corner(Json::objectValue);
    corner["xy"] = point(10, 10);
    section["corners"].append(corner);
    building["roof_sections"].append(section);
    root["buildings"].append(building);
    return root;
}

Json::Value& firstBuilding(Json::Value& root) { return root["buildings"][0]; }
Json::Value& firstSection(Json::Value& root) { return root["buildings"][0]["roof_sections"][0]; }
Json::Value& firstCorner(Json::Value& root) { return firstSection(root)["corners"][0]; }

} // namespace

TEST(HybridRoofGraphImporterTest, ParsesMinimalFixture)
{
    const auto result = HybridRoofGraphImporter::parseFile((kExamples / "valid_building_minimal.json").string());
    ASSERT_TRUE(result.success) << joined(result.errors);
    EXPECT_TRUE(result.warnings.empty()) << joined(result.warnings);
    EXPECT_EQ(result.document.rasterWidth, 512);
    EXPECT_EQ(result.document.rasterHeight, 512);
    EXPECT_TRUE(result.document.metadata.empty());
    ASSERT_EQ(result.document.buildings.size(), 1U);

    const BuildingProposal& building = result.document.buildings[0];
    EXPECT_EQ(building.id, "building-1");
    ASSERT_EQ(building.footprintProposal.outerRing.size(), 4U);
    EXPECT_DOUBLE_EQ(building.footprintProposal.outerRing[0].column, 10.0);
    EXPECT_DOUBLE_EQ(building.footprintProposal.outerRing[0].row, 10.0);
    EXPECT_FALSE(building.roofprintProposal.has_value());
    EXPECT_DOUBLE_EQ(building.scores.semantic, 0.95);
    EXPECT_DOUBLE_EQ(building.scores.ndsm, 0.88);
    EXPECT_FALSE(building.scores.sam2.has_value());
    EXPECT_FALSE(building.scores.kibs.has_value());
    ASSERT_EQ(building.roofSections.size(), 1U);
    EXPECT_EQ(building.roofSections[0].typeHint, "flat");
    ASSERT_EQ(building.roofSections[0].corners.size(), 4U);
    EXPECT_FALSE(building.roofSections[0].corners[0].heightClassHintMetres.has_value());
    ASSERT_EQ(building.provenance.size(), 1U);
    EXPECT_EQ(building.provenance[0].timestamp, "2026-10-02T10:00:00Z");
    EXPECT_EQ(result.buildingCount, 1U);
    EXPECT_EQ(result.sectionCount, 1U);
}

TEST(HybridRoofGraphImporterTest, ParsesComplexFixture)
{
    const auto result = HybridRoofGraphImporter::parseFile((kExamples / "valid_building_complex.json").string());
    ASSERT_TRUE(result.success) << joined(result.errors);
    EXPECT_TRUE(result.warnings.empty()) << joined(result.warnings);

    const RoofGraphSceneMetadata& metadata = result.document.metadata;
    EXPECT_EQ(metadata.crs, "EPSG:32632");
    ASSERT_TRUE(metadata.geoTransform.has_value());
    EXPECT_DOUBLE_EQ((*metadata.geoTransform)[5], -0.5);
    EXPECT_EQ(metadata.gsd, 0.5);
    ASSERT_EQ(result.document.buildings.size(), 2U);

    const BuildingProposal& courtyard = result.document.buildings[0];
    ASSERT_EQ(courtyard.footprintProposal.holes.size(), 1U);
    ASSERT_TRUE(courtyard.roofprintProposal.has_value());
    EXPECT_DOUBLE_EQ((*courtyard.roofprintProposal)[0].row, 98.0);
    ASSERT_EQ(courtyard.roofSections.size(), 1U);
    EXPECT_EQ(courtyard.roofSections[0].holes.size(), 1U);
    EXPECT_EQ(courtyard.roofSections[0].corners[0].heightClassHintMetres, 12.0);
    ASSERT_EQ(courtyard.provenance.size(), 2U);
    EXPECT_DOUBLE_EQ(courtyard.provenance[1].details["iou_prediction"].asDouble(), 0.96);

    const BuildingProposal& gable = result.document.buildings[1];
    EXPECT_FALSE(gable.scores.sam2.has_value());
    EXPECT_EQ(gable.scores.kibs, 0.88);
    ASSERT_EQ(gable.roofSections.size(), 2U);
    EXPECT_EQ(gable.roofSections[0].adjacentSections, std::vector<std::string>{"102-south-pitch"});
    EXPECT_EQ(gable.roofSections[1].adjacentSections, std::vector<std::string>{"102-north-pitch"});
    EXPECT_EQ(gable.roofSections[1].corners[3].heightClassHintMetres, std::nullopt);
}

// Valid fixtures are stored in canonical form, including the one written by
// the Python models, so parse + serialize must give back the same JSON value.
TEST(HybridRoofGraphImporterTest, EveryValidFixtureReserializesToItsCanonicalForm)
{
    const auto paths = fixtures("valid_");
    ASSERT_GE(paths.size(), 3U);
    for (const auto& path : paths)
    {
        SCOPED_TRACE(path.filename().string());
        const Json::Value original = loadJson(path);
        const auto result = HybridRoofGraphImporter::parse(original);
        ASSERT_TRUE(result.success) << joined(result.errors);
        EXPECT_TRUE(result.warnings.empty()) << joined(result.warnings);

        const Json::Value serialized = HybridRoofGraphImporter::toJson(result.document);
        EXPECT_EQ(serialized, original) << serialized.toStyledString();

        const auto reparsed = HybridRoofGraphImporter::parseJson(
            HybridRoofGraphImporter::toJsonString(result.document, false));
        ASSERT_TRUE(reparsed.success) << joined(reparsed.errors);
        EXPECT_EQ(HybridRoofGraphImporter::toJson(reparsed.document), original);
    }
}

TEST(HybridRoofGraphImporterTest, EveryInvalidFixtureIsRejectedWithItsExpectedCode)
{
    const auto paths = fixtures("invalid_");
    ASSERT_GE(paths.size(), 20U);
    for (const auto& path : paths)
    {
        SCOPED_TRACE(path.filename().string());
        const std::string expected = loadJson(path)["x_expected_error"].asString();
        ASSERT_FALSE(expected.empty());

        HybridRoofGraphImportResult result;
        EXPECT_NO_THROW(result = HybridRoofGraphImporter::parseFile(path.string()));
        EXPECT_FALSE(result.success);
        EXPECT_TRUE(hasMessage(result.errors, expected)) << "expected " << expected << ":" << joined(result.errors);
        EXPECT_TRUE(result.document.buildings.empty());
    }
}

// Section 5 of the playbook: pixel-edge coordinates, no implicit +0.5.
TEST(HybridRoofGraphImporterTest, PixelEdgeCoordinatesAreNeverShifted)
{
    Json::Value root = document(100, 80);
    firstBuilding(root)["footprint_proposal"] = rect(0, 0, 100, 80); // The whole raster, edge to edge.
    firstCorner(root)["xy"] = point(100, 80);
    const auto result = HybridRoofGraphImporter::parse(root);
    ASSERT_TRUE(result.success) << joined(result.errors);

    const auto& ring = result.document.buildings[0].footprintProposal.outerRing;
    EXPECT_DOUBLE_EQ(ring[0].column, 0.0);
    EXPECT_DOUBLE_EQ(ring[0].row, 0.0);
    EXPECT_DOUBLE_EQ(ring[2].column, 100.0);
    EXPECT_DOUBLE_EQ(ring[2].row, 80.0);
    EXPECT_DOUBLE_EQ(result.document.buildings[0].roofSections[0].corners[0].xy.column, 100.0);

    // Pixel edges map straight through the geotransform. Sat2Lod2Importer,
    // which reads pixel-centre indices, would place (10, 20) at 500005.25.
    const SpatialMetadata metadata = makeProjectedMetadata(100, 80, 0.5, -0.5);
    const ProjectedPoint projected = HybridRoofGraphImporter::toProjected(PixelPoint{10.0, 20.0}, metadata);
    EXPECT_DOUBLE_EQ(projected.easting, 500005.0);
    EXPECT_DOUBLE_EQ(projected.northing, 1999990.0);

    const Json::Value serialized = HybridRoofGraphImporter::toJson(result.document);
    EXPECT_EQ(serialized["buildings"][0]["footprint_proposal"], rect(0, 0, 100, 80));
    EXPECT_EQ(serialized["coordinate_convention"].asString(), "pixel_edge_column_row");
}

TEST(HybridRoofGraphImporterTest, PixelCentreConventionIsRejectedInsteadOfShifted)
{
    Json::Value root = document();
    root["coordinate_convention"] = "pixel_centre_column_row";
    for (const auto mode : {RoofGraphValidationMode::Strict, RoofGraphValidationMode::Repair})
    {
        const auto result = HybridRoofGraphImporter::parse(root, mode);
        EXPECT_FALSE(result.success);
        EXPECT_TRUE(hasMessage(result.errors, "coordinate_convention")) << joined(result.errors);
        EXPECT_TRUE(result.document.buildings.empty());
    }
}

TEST(HybridRoofGraphImporterTest, SnakeCaseIsTheOnlyWireFormat)
{
    Json::Value root = document();
    root["rasterWidth"] = root["raster_width"];
    root.removeMember("raster_width");
    const auto result = HybridRoofGraphImporter::parse(root);
    EXPECT_FALSE(result.success);
    EXPECT_TRUE(hasMessage(result.errors, "raster_size")) << joined(result.errors);

    const Json::Value serialized = HybridRoofGraphImporter::toJson(
        HybridRoofGraphImporter::parseFile((kExamples / "valid_building_complex.json").string()).document);
    for (const std::string& key : serialized.getMemberNames())
        EXPECT_EQ(key.find_first_of("ABCDEFGHIJKLMNOPQRSTUVWXYZ"), std::string::npos) << key;
    for (const std::string& key : serialized["buildings"][0].getMemberNames())
        EXPECT_EQ(key.find_first_of("ABCDEFGHIJKLMNOPQRSTUVWXYZ"), std::string::npos) << key;
}

// The only height-like value in the contract is an optional advisory hint.
TEST(HybridRoofGraphImporterTest, HeightClassIsAnOptionalAdvisoryHint)
{
    Json::Value root = document();
    EXPECT_FALSE(HybridRoofGraphImporter::parse(root).document.buildings[0]
                     .roofSections[0].corners[0].heightClassHintMetres.has_value());

    firstCorner(root)["height_class_m"] = Json::nullValue;
    EXPECT_FALSE(HybridRoofGraphImporter::parse(root).document.buildings[0]
                     .roofSections[0].corners[0].heightClassHintMetres.has_value());

    firstCorner(root)["height_class_m"] = 37.5;
    const auto result = HybridRoofGraphImporter::parse(root);
    ASSERT_TRUE(result.success) << joined(result.errors);
    EXPECT_EQ(result.document.buildings[0].roofSections[0].corners[0].heightClassHintMetres, 37.5);

    const Json::Value corner = HybridRoofGraphImporter::toJson(result.document)["buildings"][0]["roof_sections"][0]["corners"][0];
    EXPECT_EQ(corner.getMemberNames(), (std::vector<std::string>{"corner_type", "height_class_m", "score", "xy"}));
    EXPECT_DOUBLE_EQ(corner["height_class_m"].asDouble(), 37.5);

    for (const Json::Value& bad : {Json::Value(-1.0), Json::Value("12"),
                                   Json::Value(std::numeric_limits<double>::infinity())})
    {
        firstCorner(root)["height_class_m"] = bad;
        const auto strict = HybridRoofGraphImporter::parse(root);
        EXPECT_FALSE(strict.success) << bad.toStyledString();

        const auto repaired = HybridRoofGraphImporter::parse(root, RoofGraphValidationMode::Repair);
        ASSERT_TRUE(repaired.success) << joined(repaired.errors);
        ASSERT_EQ(repaired.document.buildings[0].roofSections[0].corners.size(), 1U);
        EXPECT_FALSE(repaired.document.buildings[0].roofSections[0].corners[0].heightClassHintMetres.has_value());
    }
}

// Json::Value built in memory can carry NaN/inf, which JSON text cannot.
TEST(HybridRoofGraphImporterTest, RejectsNonFiniteValuesFromMemoryDocuments)
{
    const double nan = std::numeric_limits<double>::quiet_NaN();
    const auto expectRejected = [](const Json::Value& root, const std::string& code)
    {
        HybridRoofGraphImportResult result;
        EXPECT_NO_THROW(result = HybridRoofGraphImporter::parse(root));
        EXPECT_FALSE(result.success);
        EXPECT_TRUE(hasMessage(result.errors, code)) << code << joined(result.errors);
    };

    Json::Value root = document();
    firstBuilding(root)["footprint_proposal"][1][0] = nan;
    expectRejected(root, "non_finite");

    root = document();
    firstBuilding(root)["scores"]["semantic"] = nan;
    expectRejected(root, "non_finite");

    root = document();
    firstBuilding(root)["scores"]["sam2"] = -std::numeric_limits<double>::infinity();
    expectRejected(root, "non_finite");

    root = document();
    firstCorner(root)["xy"][1] = nan;
    expectRejected(root, "non_finite");

    root = document();
    firstSection(root)["score"] = nan;
    expectRejected(root, "non_finite");

    root = document();
    for (int index = 0; index < 5; ++index) root["metadata"]["geo_transform"].append(1.0);
    root["metadata"]["geo_transform"].append(nan);
    expectRejected(root, "metadata");
}

TEST(HybridRoofGraphImporterTest, MalformedInputNeverThrows)
{
    std::vector<Json::Value> roots;
    roots.emplace_back(Json::arrayValue);
    roots.emplace_back("not a document");
    roots.emplace_back(Json::nullValue);
    for (const char* key : {"buildings", "metadata"})
    {
        Json::Value root = document();
        root[key] = 7;
        roots.push_back(root);
    }
    {
        Json::Value root = document();
        root["metadata"]["geo_transform"] = Json::Value(Json::arrayValue);
        for (int index = 0; index < 5; ++index) root["metadata"]["geo_transform"].append(1.0);
        root["metadata"]["geo_transform"].append("x"); // Threw Json::LogicError before.
        roots.push_back(root);
    }
    const std::vector<std::pair<const char*, Json::Value>> buildingFields = {
        {"id", Json::Value(5)}, {"footprint_proposal", Json::Value("ring")},
        {"holes", Json::Value(3)}, {"scores", Json::Value(true)},
        {"roof_sections", Json::Value("x")}, {"provenance", Json::Value(1.5)},
        {"roofprint_proposal", Json::Value(Json::objectValue)}};
    for (const auto& [key, value] : buildingFields)
    {
        Json::Value root = document();
        firstBuilding(root)[key] = value;
        roots.push_back(root);
    }
    {
        Json::Value root = document();
        firstBuilding(root)["footprint_proposal"][0].append(1.0); // Three coordinates.
        roots.push_back(root);
    }
    {
        Json::Value root = document();
        firstSection(root)["corners"] = Json::Value("x");
        firstSection(root)["adjacent_sections"] = Json::Value(Json::objectValue);
        roots.push_back(root);
    }
    {
        Json::Value root = document();
        firstCorner(root) = Json::Value(4);
        roots.push_back(root);
    }

    for (const Json::Value& root : roots)
    {
        for (const auto mode : {RoofGraphValidationMode::Strict, RoofGraphValidationMode::Repair})
        {
            HybridRoofGraphImportResult result;
            EXPECT_NO_THROW(result = HybridRoofGraphImporter::parse(root, mode)) << root.toStyledString();
            if (mode == RoofGraphValidationMode::Strict)
            {
                EXPECT_FALSE(result.success) << root.toStyledString();
            }
        }
    }

    for (const std::string text : {"", "{", "[1, 2", "{\"schema\": NaN}", "{\"a\": 1, \"a\": 2}",
                                   "{} trailing", "// comment\n{}"})
    {
        HybridRoofGraphImportResult result;
        EXPECT_NO_THROW(result = HybridRoofGraphImporter::parseJson(text));
        EXPECT_FALSE(result.success) << text;
        EXPECT_TRUE(hasMessage(result.errors, "json_syntax")) << text << joined(result.errors);
    }

    const auto missing = HybridRoofGraphImporter::parseFile((kExamples / "does_not_exist.json").string());
    EXPECT_FALSE(missing.success);
    EXPECT_TRUE(hasMessage(missing.errors, "io"));
}

TEST(HybridRoofGraphImporterTest, NormalizesWindingWithAWarning)
{
    Json::Value root = document();
    Json::Value reversed(Json::arrayValue);
    const Json::Value outer = rect(10, 10, 50, 40);
    for (int index = 3; index >= 0; --index) reversed.append(outer[index]);
    firstBuilding(root)["footprint_proposal"] = reversed;
    firstBuilding(root)["holes"].append(rect(20, 20, 30, 30)); // Outer winding used for a hole.

    const auto result = HybridRoofGraphImporter::parse(root);
    ASSERT_TRUE(result.success) << joined(result.errors);
    const auto& footprint = result.document.buildings[0].footprintProposal;
    EXPECT_EQ(HybridRoofGraphImporter::toJson(result.document)["buildings"][0]["footprint_proposal"], outer);
    ASSERT_EQ(footprint.holes.size(), 1U);
    Json::Value hole(Json::arrayValue); // rect(20, 20, 30, 30) reversed.
    for (const auto& [column, row] : std::vector<std::pair<double, double>>{{20, 30}, {30, 30}, {30, 20}, {20, 20}})
        hole.append(point(column, row));
    EXPECT_EQ(HybridRoofGraphImporter::toJson(result.document)["buildings"][0]["holes"][0], hole);
    EXPECT_EQ(std::count_if(result.warnings.begin(), result.warnings.end(),
                            [](const std::string& warning) { return warning.rfind("winding:", 0) == 0; }), 2);
}

TEST(HybridRoofGraphImporterTest, ProjectPolygonFollowsTheFootprintPolygonInvariant)
{
    Json::Value root = document();
    firstBuilding(root)["holes"].append(holeRect(20, 20, 30, 30));
    const auto result = HybridRoofGraphImporter::parse(root);
    ASSERT_TRUE(result.success) << joined(result.errors);

    const SpatialMetadata metadata = makeProjectedMetadata(100, 100, 0.5, -0.5);
    const auto projected = HybridRoofGraphImporter::projectPolygon(
        result.document.buildings[0].footprintProposal, metadata);
    const auto area = [](const std::vector<ProjectedPoint>& ring)
    {
        double twice = 0.0;
        for (std::size_t index = 0; index < ring.size(); ++index)
        {
            const auto& current = ring[index];
            const auto& next = ring[(index + 1) % ring.size()];
            twice += current.easting * next.northing - next.easting * current.northing;
        }
        return 0.5 * twice;
    };
    EXPECT_NEAR(area(projected.outerRing), 40.0 * 30.0 * 0.25, 1e-6);
    ASSERT_EQ(projected.holes.size(), 1U);
    EXPECT_NEAR(area(projected.holes[0]), -10.0 * 10.0 * 0.25, 1e-6);
}

TEST(HybridRoofGraphImporterTest, RejectsRingsAboveTheVertexLimit)
{
    Json::Value root = document(20000, 20000);
    Json::Value ring(Json::arrayValue);
    for (std::size_t index = 0; index <= kRoofGraphMaxRingVertices; ++index)
    {
        const double angle = 2.0 * M_PI * static_cast<double>(index) / (kRoofGraphMaxRingVertices + 1);
        ring.append(point(10000.0 + 5000.0 * std::cos(angle), 10000.0 + 5000.0 * std::sin(angle)));
    }
    firstBuilding(root)["footprint_proposal"] = ring;
    const auto result = HybridRoofGraphImporter::parse(root);
    EXPECT_FALSE(result.success);
    EXPECT_TRUE(hasMessage(result.errors, "too_many_vertices")) << joined(result.errors);

    ring.resize(kRoofGraphMaxRingVertices); // At the limit: a valid polygon.
    firstBuilding(root)["footprint_proposal"] = ring;
    firstSection(root)["polygon"] = rect(9000, 9000, 9100, 9100);
    const auto accepted = HybridRoofGraphImporter::parse(root);
    EXPECT_TRUE(accepted.success) << joined(accepted.errors);
}

TEST(HybridRoofGraphImporterTest, RepairModeFixesWhatItCanAndReportsEveryChange)
{
    Json::Value root = document();
    Json::Value& building = firstBuilding(root);
    building["footprint_proposal"] = rect(10, 10, 150, 40);                         // Off the raster.
    building["footprint_proposal"].append(point(10, 10));                          // Closing vertex.
    building["holes"].append(holeRect(60, 60, 70, 70));                            // Outside.
    building["scores"]["semantic"] = 1.4;
    building["scores"]["kibs"] = "high";
    Json::Value bowtie(Json::arrayValue);
    for (const auto& [column, row] : std::vector<std::pair<double, double>>{{10, 10}, {50, 40}, {50, 10}, {10, 40}})
        bowtie.append(point(column, row));
    building["roofprint_proposal"] = bowtie;
    firstSection(root)["adjacent_sections"].append("b-0");                         // Itself.
    firstSection(root)["adjacent_sections"].append("ghost");
    Json::Value badCorner(Json::objectValue);
    badCorner["xy"] = point(500, 5);
    firstSection(root)["corners"].append(badCorner);
    Json::Value unusable(Json::objectValue);
    unusable["id"] = "unusable";
    for (double offset : {10.0, 20.0, 30.0}) unusable["footprint_proposal"].append(point(offset, offset)); // Flat.
    root["buildings"].append(unusable);
    root["buildings"].append(building);                                            // Duplicate id.

    EXPECT_FALSE(HybridRoofGraphImporter::parse(root).success);
    const auto result = HybridRoofGraphImporter::parse(root, RoofGraphValidationMode::Repair);
    ASSERT_TRUE(result.success) << joined(result.errors);
    ASSERT_EQ(result.document.buildings.size(), 1U);

    const BuildingProposal& repaired = result.document.buildings[0];
    ASSERT_EQ(repaired.footprintProposal.outerRing.size(), 4U);
    EXPECT_DOUBLE_EQ(repaired.footprintProposal.outerRing[1].column, 100.0);
    EXPECT_TRUE(repaired.footprintProposal.holes.empty());
    EXPECT_DOUBLE_EQ(repaired.scores.semantic, 1.0);
    EXPECT_FALSE(repaired.scores.kibs.has_value());
    ASSERT_TRUE(repaired.roofprintProposal.has_value());
    EXPECT_GE(repaired.roofprintProposal->size(), 3U);
    EXPECT_TRUE(repaired.roofSections[0].adjacentSections.empty());
    EXPECT_EQ(repaired.roofSections[0].corners.size(), 1U);

    for (const char* code : {"out_of_bounds", "closing_vertex", "invalid_hole", "score_range", "field_type",
                             "self_intersection", "adjacency", "degenerate_ring", "duplicate_id"})
        EXPECT_TRUE(hasMessage(result.warnings, code)) << code << joined(result.warnings);
}
