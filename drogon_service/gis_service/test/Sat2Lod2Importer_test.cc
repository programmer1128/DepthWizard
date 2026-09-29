#include "BuildingReconstruction/Sat2Lod2Importer.h"
#include "BuildingReconstructionTestSupport.h"

#include <gtest/gtest.h>
#include <json/json.h>

using namespace depthwizard::test;

namespace
{
constexpr int kWidth = 60;
constexpr int kHeight = 40;

struct Scene
{
     SpatialMetadata metadata = makeProjectedMetadata(kWidth, kHeight, 0.5, -0.5);
     SemanticScene semantics = makeSemanticScene(kWidth, kHeight);
     GeoreferencedSurfaceBundle surface = makeSurface(kWidth, kHeight, 50.0F, 0.0F);
     RasterGrid<float> ndsm = makeConstantGrid(kWidth, kHeight, 0.0F);

     Scene()
     {
          surface.spatialMetadata = metadata;
          fillRectangle(semantics.finalClassMap, 10, 10, 40, 30, SemanticClass::BUILDING);
          fillRectangle(semantics.buildingProbability, 10, 10, 40, 30, 0.9F);
          fillRectangle(ndsm, 10, 10, 27, 30, 12.0F);
          fillRectangle(ndsm, 27, 10, 40, 30, 24.0F);
     }
};

Json::Value point(double column, double row)
{
     Json::Value value(Json::arrayValue);
     value.append(column);
     value.append(row);
     return value;
}

Json::Value rectangle(double left, double top, double right, double bottom)
{
     Json::Value ring(Json::arrayValue);
     ring.append(point(left, top));
     ring.append(point(right, top));
     ring.append(point(right, bottom));
     ring.append(point(left, bottom));
     return ring;
}

Json::Value block(double left, double right, const std::string& roofType = "flat",
                  double top = 10, double bottom = 29)
{
     Json::Value value;
     value["corners"] = rectangle(left, top, right, bottom);
     value["roof_type"] = roofType;
     value["eave"] = 10.0;
     value["ridge"] = 12.0;
     Json::Value ridge(Json::arrayValue);
     ridge.append(point(left, 19.5));
     ridge.append(point(right, 19.5));
     value["ridge_line"] = ridge;
     return value;
}

Json::Value document(Json::Value blocks)
{
     Json::Value segment;
     segment["id"] = 0;
     segment["footprint"] = rectangle(10, 10, 39, 29);
     segment["blocks"] = std::move(blocks);
     segment["irregular"] = segment["blocks"].empty();

     Json::Value root;
     root["schema"] = "depthwizard.sat2lod2.v1";
     root["raster_width"] = kWidth;
     root["raster_height"] = kHeight;
     root["segments"].append(segment);
     return root;
}

Json::Value twoBlocks()
{
     Json::Value blocks(Json::arrayValue);
     blocks.append(block(10, 26.5));
     blocks.append(block(26.5, 39));
     return blocks;
}
} // namespace

std::vector<const BuildingInstance*> byHeight(const BuildingCollection& collection)
{
     std::vector<const BuildingInstance*> buildings;
     for (const auto& building : collection.buildings) buildings.push_back(&building);
     std::sort(buildings.begin(), buildings.end(), [](const auto* a, const auto* b)
               { return a->heightAboveGround > b->heightAboveGround; });
     return buildings;
}

double minEasting(const BuildingInstance& building)
{
     double value = 1e18;
     for (const auto& point : building.projectedFootprint.outerRing)
          value = std::min(value, point.easting);
     return value;
}

double maxEasting(const BuildingInstance& building)
{
     double value = -1e18;
     for (const auto& point : building.projectedFootprint.outerRing)
          value = std::max(value, point.easting);
     return value;
}

TEST(Sat2Lod2Importer, EachRectangleBecomesItsOwnBuildingWithNdsmHeight)
{
     Scene scene;
     BuildingReconstructionConfig config;
     config.heightScaleMultiplier = 1.0F;

     const auto result = Sat2Lod2Importer::import(document(twoBlocks()), scene.semantics,
         scene.surface, scene.metadata, config, scene.ndsm);

     ASSERT_EQ(result.buildings.buildings.size(), 2U) << ::testing::PrintToString(result.warnings);
     const auto buildings = byHeight(result.buildings);
     EXPECT_NEAR(buildings[0]->heightAboveGround, 24.0F, 1e-4);
     EXPECT_NEAR(buildings[1]->heightAboveGround, 12.0F, 1e-4);
     for (const auto* building : buildings)
     {
          EXPECT_NEAR(building->representativeBaseElevation, 50.0F, 1e-4);
          EXPECT_TRUE(building->blocks.empty());
          EXPECT_EQ(building->projectedFootprint.outerRing.size(), 4U);
     }
     EXPECT_NE(buildings[0]->buildingId, buildings[1]->buildingId);
     EXPECT_EQ(result.buildings.lod2BlockCount, 2U);
     EXPECT_EQ(result.residualPartCount, 0U);
     // Neighbouring buildings stay visibly separate.
     EXPECT_NEAR(minEasting(*buildings[0]) - maxEasting(*buildings[1]),
                 config.sat2lod2PartGapMetres, 1e-6);
}

TEST(Sat2Lod2Importer, ConvertsPixelCentresThroughTheAffineTransform)
{
     Scene scene;
     const BuildingReconstructionConfig config;
     const auto result = Sat2Lod2Importer::import(document(twoBlocks()), scene.semantics,
         scene.surface, scene.metadata, config, scene.ndsm);

     ASSERT_EQ(result.buildings.buildings.size(), 2U);
     const double halfGap = 0.5 * config.sat2lod2PartGapMetres;
     double west = 1e18, north = -1e18, area = 0.0;
     for (const auto& building : result.buildings.buildings)
     {
          west = std::min(west, minEasting(building));
          for (const auto& point : building.projectedFootprint.outerRing)
               north = std::max(north, point.northing);
          area += projectedRingArea(building.projectedFootprint.outerRing);
     }
     // Pixel-centre index 10 is GDAL pixel-edge coordinate 10.5.
     EXPECT_NEAR(west, 500000.0 + 10.5 * 0.5 + halfGap, 1e-6);
     EXPECT_NEAR(north, 2000000.0 - 10.5 * 0.5 - halfGap, 1e-6);
     const double gap = config.sat2lod2PartGapMetres;
     EXPECT_NEAR(area, (8.25 - gap) * (9.5 - gap) + (6.25 - gap) * (9.5 - gap), 1e-6);
}

TEST(Sat2Lod2Importer, SnapsNearlyEqualNeighboursToOneLevel)
{
     Scene scene;
     fillRectangle(scene.ndsm, 27, 10, 40, 30, 12.5F);
     BuildingReconstructionConfig config;
     config.heightScaleMultiplier = 1.0F;

     const auto result = Sat2Lod2Importer::import(document(twoBlocks()), scene.semantics,
         scene.surface, scene.metadata, config, scene.ndsm);

     ASSERT_EQ(result.buildings.buildings.size(), 2U);
     const auto& buildings = result.buildings.buildings;
     EXPECT_FLOAT_EQ(buildings[0].heightAboveGround, buildings[1].heightAboveGround);
     EXPECT_GT(buildings[0].heightAboveGround, 12.0F);
     EXPECT_LT(buildings[0].heightAboveGround, 12.5F);
}

TEST(Sat2Lod2Importer, TallerRectangleStaysIntactAndClipsLowerOverlap)
{
     Scene scene;
     fillRectangle(scene.ndsm, 10, 10, 40, 30, 12.0F);
     fillRectangle(scene.ndsm, 20, 10, 31, 30, 30.0F);
     Json::Value blocks(Json::arrayValue);
     blocks.append(block(10, 39));   // low podium spanning the footprint
     blocks.append(block(20, 30));   // tower overlapping its middle
     BuildingReconstructionConfig config;
     config.heightScaleMultiplier = 1.0F;

     const auto result = Sat2Lod2Importer::import(document(blocks), scene.semantics,
         scene.surface, scene.metadata, config, scene.ndsm);

     ASSERT_EQ(result.buildings.buildings.size(), 3U);
     const auto buildings = byHeight(result.buildings);
     EXPECT_NEAR(buildings[0]->heightAboveGround, 30.0F, 1e-4);
     EXPECT_EQ(buildings[0]->projectedFootprint.outerRing.size(), 4U);
     const double gap = config.sat2lod2PartGapMetres;
     EXPECT_NEAR(projectedRingArea(buildings[0]->projectedFootprint.outerRing),
                 (5.0 - gap) * (9.5 - gap), 1e-6);
     for (std::size_t index = 1; index < 3; ++index)
     {
          EXPECT_NEAR(buildings[index]->heightAboveGround, 12.0F, 1e-4);
          // The podium wraps the tower with a gap instead of overlapping it.
          const bool west = maxEasting(*buildings[index]) <= minEasting(*buildings[0]) - gap + 1e-6;
          const bool east = minEasting(*buildings[index]) >= maxEasting(*buildings[0]) + gap - 1e-6;
          EXPECT_TRUE(west || east);
     }
}

TEST(Sat2Lod2Importer, ClippedPartsHaveCleanRings)
{
     Scene scene;
     fillRectangle(scene.ndsm, 10, 10, 40, 30, 12.0F);
     fillRectangle(scene.ndsm, 30, 10, 40, 20, 30.0F);
     Json::Value blocks(Json::arrayValue);
     blocks.append(block(10, 39));
     blocks.append(block(30, 39, "flat", 10, 19)); // tower in the podium's corner
     BuildingReconstructionConfig config;
     config.heightScaleMultiplier = 1.0F;

     const auto result = Sat2Lod2Importer::import(document(blocks), scene.semantics,
         scene.surface, scene.metadata, config, scene.ndsm);

     ASSERT_EQ(result.buildings.buildings.size(), 2U);
     const auto buildings = byHeight(result.buildings);
     // The podium wraps the corner tower as an L: six corners, no repeated
     // or collinear vertices left over from clipping.
     const auto& ring = buildings[1]->projectedFootprint.outerRing;
     ASSERT_EQ(ring.size(), 6U);
     for (std::size_t index = 0; index < ring.size(); ++index)
     {
          const ProjectedPoint& a = ring[index];
          const ProjectedPoint& b = ring[(index + 1) % ring.size()];
          const ProjectedPoint& c = ring[(index + 2) % ring.size()];
          EXPECT_GT(std::hypot(b.easting - a.easting, b.northing - a.northing), 0.1);
          const double cross = (b.easting - a.easting) * (c.northing - b.northing) -
                               (b.northing - a.northing) * (c.easting - b.easting);
          EXPECT_GT(std::abs(cross), 1e-3) << "collinear vertex at " << index;
     }
}

TEST(Sat2Lod2Importer, FillsLargeFootprintAreaNoRectangleCovers)
{
     Scene scene;
     Json::Value blocks(Json::arrayValue);
     blocks.append(block(10, 20));
     BuildingReconstructionConfig config;
     config.heightScaleMultiplier = 1.0F;

     // Off by default: the rectangles alone define the buildings.
     const auto rectanglesOnly = Sat2Lod2Importer::import(document(blocks), scene.semantics,
         scene.surface, scene.metadata, config, scene.ndsm);
     EXPECT_EQ(rectanglesOnly.buildings.buildings.size(), 1U);
     EXPECT_EQ(rectanglesOnly.residualPartCount, 0U);

     config.sat2lod2MinResidualAreaSquareMetres = 40.0F;
     const auto filled = Sat2Lod2Importer::import(document(blocks), scene.semantics,
         scene.surface, scene.metadata, config, scene.ndsm);
     EXPECT_EQ(filled.buildings.buildings.size(), 2U);
     EXPECT_EQ(filled.residualPartCount, 1U);
}

TEST(Sat2Lod2Importer, NeverFillsCourtyards)
{
     Scene scene;
     // A ring of building around a courtyard the semantic model saw as ground.
     fillRectangle(scene.semantics.finalClassMap, 18, 14, 32, 26, SemanticClass::GROUND);
     fillRectangle(scene.semantics.buildingProbability, 18, 14, 32, 26, 0.05F);
     Json::Value blocks(Json::arrayValue);
     blocks.append(block(10, 17));
     blocks.append(block(32, 39));
     BuildingReconstructionConfig config;
     config.heightScaleMultiplier = 1.0F;
     config.sat2lod2MinResidualAreaSquareMetres = 20.0F;

     // SAT2LoD2's outline covers the courtyard; the residual between the
     // wings must stay open.
     const auto result = Sat2Lod2Importer::import(document(blocks), scene.semantics,
         scene.surface, scene.metadata, config, scene.ndsm);
     EXPECT_EQ(result.residualPartCount, 0U);
     EXPECT_EQ(result.buildings.buildings.size(), 2U);
}

TEST(Sat2Lod2Importer, KeepsPitchedRoofsOnlyWhenEnabled)
{
     Scene scene;
     fillRectangle(scene.ndsm, 10, 10, 40, 30, 12.0F);
     Json::Value blocks(Json::arrayValue);
     blocks.append(block(10, 26.5, "gable"));

     BuildingReconstructionConfig config;
     config.heightScaleMultiplier = 1.0F;
     const auto withBlocks = [](const BuildingCollection& collection)
     {
          std::size_t count = 0;
          for (const auto& building : collection.buildings) count += building.blocks.size();
          return count;
     };

     auto flat = Sat2Lod2Importer::import(document(blocks), scene.semantics,
         scene.surface, scene.metadata, config, scene.ndsm);
     ASSERT_FALSE(flat.buildings.buildings.empty());
     EXPECT_EQ(withBlocks(flat.buildings), 0U);

     config.enableLod2RoofFitting = true;
     auto pitched = Sat2Lod2Importer::import(document(blocks), scene.semantics,
         scene.surface, scene.metadata, config, scene.ndsm);
     ASSERT_EQ(withBlocks(pitched.buildings), 1U);
     for (const auto& building : pitched.buildings.buildings)
     {
          if (building.blocks.empty()) continue;
          const RoofParameters& roof = building.blocks.front().roof;
          EXPECT_EQ(roof.type, RoofType::GABLE);
          EXPECT_NEAR(roof.ridgeHeightAboveGround, 12.0F, 1e-4);
          EXPECT_NEAR(roof.eaveHeightAboveGround, 10.0F, 1e-4);
          EXPECT_NEAR(building.heightAboveGround, 12.0F, 1e-4);
     }
}

TEST(Sat2Lod2Importer, ExtrudesIrregularSegmentsAsPrisms)
{
     Scene scene;
     const auto result = Sat2Lod2Importer::import(document(Json::Value(Json::arrayValue)),
         scene.semantics, scene.surface, scene.metadata, BuildingReconstructionConfig{}, scene.ndsm);

     ASSERT_EQ(result.buildings.buildings.size(), 1U);
     EXPECT_EQ(result.irregularCount, 1U);
     const BuildingInstance& building = result.buildings.buildings.front();
     EXPECT_TRUE(building.blocks.empty());
     EXPECT_EQ(building.baseElevationPerVertex.size(), building.projectedFootprint.outerRing.size());
     EXPECT_GT(building.heightAboveGround, 0.0F);
}

TEST(Sat2Lod2Importer, SnapsWobblyFootprintToRectilinearOutline)
{
     Scene scene;
     // A semantic-mask outline: jitter along every wall plus a 1 m jog.
     Json::Value wobbly(Json::arrayValue);
     for (const auto& [column, row] : std::vector<std::pair<double, double>>{
              {10, 10}, {18, 10.6}, {25, 9.7}, {32, 10.4}, {39, 10},
              {39.5, 16}, {38.6, 22}, {39, 29},
              {30, 29.4}, {30, 27}, {28, 27}, {28, 29}, {20, 28.6}, {10, 29},
              {10.5, 22}, {9.6, 15}})
          wobbly.append(point(column, row));
     Json::Value root = document(Json::Value(Json::arrayValue));
     root["segments"][0]["footprint"] = wobbly;

     const auto result = Sat2Lod2Importer::import(root, scene.semantics,
         scene.surface, scene.metadata, BuildingReconstructionConfig{}, scene.ndsm);

     ASSERT_EQ(result.buildings.buildings.size(), 1U);
     const auto& ring = result.buildings.buildings.front().projectedFootprint.outerRing;
     ASSERT_EQ(ring.size(), 4U);
     for (std::size_t index = 0; index < ring.size(); ++index)
     {
          const ProjectedPoint& a = ring[index];
          const ProjectedPoint& b = ring[(index + 1) % ring.size()];
          const ProjectedPoint& next = ring[(index + 2) % ring.size()];
          const double dot = (b.easting - a.easting) * (next.easting - b.easting) +
                             (b.northing - a.northing) * (next.northing - b.northing);
          EXPECT_NEAR(dot, 0.0, 1e-6) << "corner " << index << " is not square";
     }
     EXPECT_NEAR(projectedRingArea(ring), 29.0 * 19.0 * 0.25, 0.1 * 29.0 * 19.0 * 0.25);
}

TEST(Sat2Lod2Importer, RejectsMismatchedRaster)
{
     Scene scene;
     Json::Value root = document(twoBlocks());
     root["raster_width"] = kWidth + 1;
     const auto result = Sat2Lod2Importer::import(root, scene.semantics,
         scene.surface, scene.metadata, BuildingReconstructionConfig{}, scene.ndsm);
     EXPECT_TRUE(result.buildings.buildings.empty());
     EXPECT_FALSE(result.warnings.empty());
}

TEST(Sat2Lod2Importer, KeepsOnlyUncoveredNativeBuildings)
{
     Scene scene;
     auto result = Sat2Lod2Importer::import(document(twoBlocks()), scene.semantics,
         scene.surface, scene.metadata, BuildingReconstructionConfig{}, scene.ndsm);
     ASSERT_EQ(result.buildings.buildings.size(), 2U);

     const auto nativeBuilding = [](double left, double top, double right, double bottom)
     {
          BuildingInstance building;
          building.buildingId = 1;
          building.pixelFootprint.outerRing = {
              {left, top}, {right, top}, {right, bottom}, {left, bottom}};
          return building;
     };
     BuildingCollection native;
     native.buildings.push_back(nativeBuilding(12, 12, 30, 28)); // under SAT
     native.buildings.push_back(nativeBuilding(45, 5, 55, 15));  // missed by SAT

     const std::size_t kept = Sat2Lod2Importer::appendUncoveredNative(
         result.buildings, native, scene.metadata);

     EXPECT_EQ(kept, 1U);
     ASSERT_EQ(result.buildings.buildings.size(), 3U);
     EXPECT_EQ(result.buildings.buildings.back().buildingId, 3U);
     EXPECT_DOUBLE_EQ(result.buildings.buildings.back().pixelFootprint.outerRing.front().column, 45.0);
}
