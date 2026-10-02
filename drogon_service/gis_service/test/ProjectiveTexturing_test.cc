#include <gtest/gtest.h>

#include "UVMapping/ProjectiveTexturingEngine.h"
#include "UVMapping/ProjectiveTexturingTypes.h"
#include "UVMapping/RpcCameraModel.h"
#include "UVMapping/SensorLookGeometry.h"
#include "structures/CommonTypes.h"
#include "structures/GeographicStructs.h"

#include <cmath>
#include <vector>
#include <array>
#include <optional>

SpatialMetadata createMockMetadata(
    int width = 1000,
    int height = 1000,
    double originX = 500000.0,
    double originY = 4000000.0,
    double pixelSize = 0.5) {

    SpatialMetadata meta;
    meta.width = width;
    meta.height = height;
    meta.pixelSizeX = pixelSize;
    meta.pixelSizeY = pixelSize;
    meta.gsd = pixelSize;
    meta.isGeoreferenced = true;
    // GeoTransform: [originX, pixelSize, 0, originY, 0, -pixelSize]
    meta.geoTransform = {originX, pixelSize, 0.0, originY, 0.0, -pixelSize};
    meta.projectionRef = "EPSG:32633"; // UTM 33N
    return meta;
}

BuildingInstance createSquareBuilding(
    uint32_t id,
    double minX,
    double minY,
    double size,
    float height,
    float baseElev = 10.0f) {

    BuildingInstance b;
    b.buildingId = id;
    b.representativeBaseElevation = baseElev;
    b.roofElevation = baseElev + height;
    b.heightAboveGround = height;
    b.footprintAreaSquareMetres = static_cast<float>(size * size);

    // CCW outer ring in projected coordinates
    b.projectedFootprint.outerRing = {
        {minX, minY},
        {minX + size, minY},
        {minX + size, minY + size},
        {minX, minY + size}
    };

    return b;
}

// -----------------------------------------------------------------------------
// Test Suite 1: Affine / RPC Fallback Selection
// -----------------------------------------------------------------------------
TEST(ProjectiveTexturingTest, FallbackSelection_ValidRpcSelected) {
    ProjectiveTexturingEngine engine;
    ProjectiveTexturingConfig config;

    SpatialMetadata meta = createMockMetadata();

    OGRSpatialReference utm;
    utm.SetFromUserInput(meta.projectionRef.c_str());
    OGRSpatialReference wgs84;
    wgs84.SetWellKnownGeogCS("WGS84");
    wgs84.SetAxisMappingStrategy(OAMS_TRADITIONAL_GIS_ORDER);
    auto* transform = OGRCreateCoordinateTransformation(&utm, &wgs84);
    double cx = meta.geoTransform[0] + meta.width * 0.5 * meta.pixelSizeX;
    double cy = meta.geoTransform[3] - meta.height * 0.5 * meta.pixelSizeY;
    double cz = 0.0;
    if (transform) {
        transform->Transform(1, &cx, &cy, &cz);
        OCTDestroyCoordinateTransformation(transform);
    }

    RpcCameraModel rpc = RpcCameraModel::createSyntheticModel(
        cx, cy, 10.0, meta.gsd, meta.width, meta.height, 45.0, 20.0);
    ASSERT_TRUE(rpc.isValid());

    EXPECT_EQ(engine.determineProjectionMode(rpc), ProjectionMode::RPC_PROJECTIVE);

    ProjectedPoint pt{meta.geoTransform[0] + 250.0, meta.geoTransform[3] - 250.0};
    ProjectedVertex v = engine.projectVertex(pt, 30.0, 20.0, meta, rpc, config);

    EXPECT_TRUE(v.isValid);
    EXPECT_EQ(v.provenance, MaterialProvenance::SOURCE_PROJECTIVE_RPC);
    EXPECT_GE(v.u, 0.0f);
    EXPECT_LE(v.u, 1.0f);
    EXPECT_GE(v.v, 0.0f);
    EXPECT_LE(v.v, 1.0f);
}

TEST(ProjectiveTexturingTest, FallbackSelection_MandatoryAffineFallbackWhenRpcMissing) {
    ProjectiveTexturingEngine engine;
    ProjectiveTexturingConfig config;

    SpatialMetadata meta = createMockMetadata();
    std::optional<RpcCameraModel> noRpc = std::nullopt;

    EXPECT_EQ(engine.determineProjectionMode(noRpc), ProjectionMode::AFFINE_FALLBACK);

    ProjectedPoint pt{meta.geoTransform[0] + 100.0, meta.geoTransform[3] - 100.0};
    ProjectedVertex v = engine.projectVertex(pt, 30.0, 20.0, meta, noRpc, config);

    EXPECT_TRUE(v.isValid);
    EXPECT_EQ(v.provenance, MaterialProvenance::SOURCE_PROJECTIVE_AFFINE);
    EXPECT_NEAR(v.pixelCol, 200.0, 1e-3);
    EXPECT_NEAR(v.pixelRow, 200.0, 1e-3);
    EXPECT_NEAR(v.u, 0.2f, 1e-3);
    EXPECT_NEAR(v.v, 0.2f, 1e-3);
}

TEST(ProjectiveTexturingTest, FallbackSelection_MandatoryAffineFallbackWhenRpcDegenerate) {
    ProjectiveTexturingEngine engine;
    ProjectiveTexturingConfig config;

    SpatialMetadata meta = createMockMetadata();
    RpcCameraModel degenerateRpc; // Uninitialized/invalid
    ASSERT_FALSE(degenerateRpc.isValid());

    EXPECT_EQ(engine.determineProjectionMode(degenerateRpc), ProjectionMode::AFFINE_FALLBACK);

    ProjectedPoint pt{meta.geoTransform[0] + 50.0, meta.geoTransform[3] - 50.0};
    ProjectedVertex v = engine.projectVertex(pt, 25.0, 15.0, meta, degenerateRpc, config);

    EXPECT_TRUE(v.isValid);
    EXPECT_EQ(v.provenance, MaterialProvenance::SOURCE_PROJECTIVE_AFFINE);
}

// -----------------------------------------------------------------------------
// Test Suite 2: Displacement Derivation & Sensor Look Geometry
// -----------------------------------------------------------------------------
TEST(ProjectiveTexturingTest, DisplacementDerivation_OffNadirCalculations) {
    // 30 degrees off-nadir, 90 degrees azimuth (due East)
    SensorLookGeometry geom = SensorLookGeometry::fromAzimuthAndOffNadir(90.0, 30.0);
    EXPECT_NEAR(geom.getAzimuthDegrees(), 90.0, 1e-4);
    EXPECT_NEAR(geom.getOffNadirDegrees(), 30.0, 1e-4);
    EXPECT_NEAR(geom.getElevationDegrees(), 60.0, 1e-4);

    const double height = 30.0;
    // Expected ground displacement: height * tan(30 deg) = 30 * 0.57735 = 17.3205 meters
    const double expectedMagnitude = height * std::tan(30.0 * M_PI / 180.0);
    Displacement2D groundDisp = geom.computeGroundDisplacement(height);

    EXPECT_NEAR(groundDisp.dx, expectedMagnitude, 1e-3); // Easting
    EXPECT_NEAR(groundDisp.dy, 0.0, 1e-3);               // Northing

    SpatialMetadata meta = createMockMetadata(1000, 1000, 0.0, 0.0, 0.5);
    Displacement2D pixelDisp = geom.computePixelDisplacement(height, meta);

    // GSD is 0.5 m/px, so pixel displacement should be 17.3205 / 0.5 = 34.641 px East
    EXPECT_NEAR(pixelDisp.dx, expectedMagnitude / 0.5, 1e-3);
    EXPECT_NEAR(pixelDisp.dy, 0.0, 1e-3);
}

TEST(ProjectiveTexturingTest, DisplacementDerivation_NadirHasZeroDisplacement) {
    SensorLookGeometry nadir = SensorLookGeometry::fromAzimuthAndOffNadir(0.0, 0.0);
    EXPECT_TRUE(nadir.isNadir());

    Displacement2D disp = nadir.computeGroundDisplacement(50.0);
    EXPECT_DOUBLE_EQ(disp.dx, 0.0);
    EXPECT_DOUBLE_EQ(disp.dy, 0.0);
}

// -----------------------------------------------------------------------------
// Test Suite 3: Occlusion Detection & Facade Recovery
// -----------------------------------------------------------------------------
TEST(ProjectiveTexturingTest, OcclusionDetection_FacingVsBackfacingWalls) {
    // Satellite is to the South (azimuth 180 deg) looking North, off-nadir 30 deg
    SensorLookGeometry geom = SensorLookGeometry::fromAzimuthAndOffNadir(180.0, 30.0);

    // CCW Square:
    // Bottom: (0,0)->(10,0) [Normal South (0, -1)]
    // Right: (10,0)->(10,10) [Normal East (1, 0)]
    // Top: (10,10)->(0,10) [Normal North (0, 1)]
    // Left: (0,10)->(0,0) [Normal West (-1, 0)]

    // Satellite at azimuth 180 (South). Sat vector = (sin 180, cos 180) = (0, -1).
    // Bottom wall outward normal is (0, -1). Dot product: (0)*(0) + (-1)*(-1) = 1.0 > 0.
    // -> Faces satellite!
    EXPECT_TRUE(geom.isWallFacingSensor(0.0, 0.0, 10.0, 0.0));

    // Top wall outward normal is (0, 1). Dot product: (0)*(0) + (1)*(-1) = -1.0 < 0.
    // -> Back-facing / hidden!
    EXPECT_FALSE(geom.isWallFacingSensor(10.0, 10.0, 0.0, 10.0));

    // East wall outward normal is (1, 0). Dot product = 0.
    // -> Edge-on / hidden!
    EXPECT_FALSE(geom.isWallFacingSensor(10.0, 0.0, 10.0, 10.0));

    // West wall outward normal is (-1, 0). Dot product = 0.
    // -> Edge-on / hidden!
    EXPECT_FALSE(geom.isWallFacingSensor(0.0, 10.0, 0.0, 0.0));
}

TEST(ProjectiveTexturingTest, FacadeRecovery_RectifiesVisibleAndAppliesProceduralToHidden) {
    ProjectiveTexturingEngine engine;
    ProjectiveTexturingConfig config;
    config.enableFacadeRecovery = true;

    SpatialMetadata meta = createMockMetadata();
    // Satellite to South (180 deg), 25 deg off-nadir
    SensorLookGeometry geom = SensorLookGeometry::fromAzimuthAndOffNadir(180.0, 25.0);

    BuildingInstance bldg = createSquareBuilding(
        1, meta.geoTransform[0] + 100.0, meta.geoTransform[3] - 100.0, 20.0, 30.0);

    TexturingDiagnostics diag;
    std::vector<BuildingInstance> allBuildings = {bldg};

    auto facadeStrips = engine.recoverFacades(
        bldg, allBuildings, meta, std::nullopt, geom, config, diag);

    ASSERT_EQ(facadeStrips.size(), 4u);

    // Wall 0: Bottom wall (South-facing) should be rectified visible
    EXPECT_TRUE(facadeStrips[0].isVisibleToSensor);
    EXPECT_EQ(facadeStrips[0].provenance, MaterialProvenance::FACADE_RECTIFIED_VISIBLE);

    // Wall 2: Top wall (North-facing) should be hidden/back-facing and tagged procedural/neutral
    EXPECT_FALSE(facadeStrips[2].isVisibleToSensor);
    EXPECT_EQ(facadeStrips[2].provenance, MaterialProvenance::PROCEDURAL_NEUTRAL);

    // Verify diagnostics counts
    EXPECT_EQ(diag.visibleFacadesRectified, 1u);
    EXPECT_EQ(diag.hiddenFacadesProcedural, 3u);
}

TEST(ProjectiveTexturingTest, OcclusionDetection_NeighborOcclusionBlocksFacade) {
    ProjectiveTexturingEngine engine;
    ProjectiveTexturingConfig config;
    config.enableFacadeRecovery = true;
    config.enableNeighborOcclusionCheck = true;

    SpatialMetadata meta = createMockMetadata();
    // Satellite in South (180 deg) looking North
    SensorLookGeometry geom = SensorLookGeometry::fromAzimuthAndOffNadir(180.0, 30.0);

    // Building 1 (Short target building at Y = 200m)
    BuildingInstance bldg1 = createSquareBuilding(
        1, meta.geoTransform[0] + 100.0, meta.geoTransform[3] - 200.0, 20.0, 15.0, 0.0f);

    // Building 2 (Taller blocker building directly South at Y = 250m, between bldg1 and satellite)
    BuildingInstance bldg2 = createSquareBuilding(
        2, meta.geoTransform[0] + 100.0, meta.geoTransform[3] - 250.0, 20.0, 45.0, 0.0f);

    std::vector<BuildingInstance> allBuildings = {bldg1, bldg2};
    TexturingDiagnostics diag;

    auto strips = engine.recoverFacades(
        bldg1, allBuildings, meta, std::nullopt, geom, config, diag);

    ASSERT_EQ(strips.size(), 4u);
    // South wall of bldg1 would ordinarily face the sensor, but is occluded by bldg2
    EXPECT_FALSE(strips[0].isVisibleToSensor);
    EXPECT_TRUE(strips[0].isOccludedByNeighbor);
    EXPECT_EQ(strips[0].provenance, MaterialProvenance::OCCLUDED_BACKFACING);
}

// -----------------------------------------------------------------------------
// Test Suite 4: Strict Texture Bounding
// -----------------------------------------------------------------------------
TEST(ProjectiveTexturingTest, StrictBounding_AcceptsInteriorAndRejectsOutOfBounds) {
    ProjectiveTexturingEngine engine;

    // 1000x1000 raster with 2.0 pixel guard band
    EXPECT_TRUE(engine.checkStrictBounds(500.0, 500.0, 1000, 1000, 2.0));
    EXPECT_TRUE(engine.checkStrictBounds(2.5, 2.5, 1000, 1000, 2.0));
    EXPECT_TRUE(engine.checkStrictBounds(997.0, 997.0, 1000, 1000, 2.0));

    // Beyond outer edges
    EXPECT_FALSE(engine.checkStrictBounds(-1.0, 500.0, 1000, 1000, 2.0));
    EXPECT_FALSE(engine.checkStrictBounds(500.0, 1001.0, 1000, 1000, 2.0));

    // Inside image but inside guard band [0, 2.0]
    EXPECT_FALSE(engine.checkStrictBounds(1.0, 500.0, 1000, 1000, 2.0));
    EXPECT_FALSE(engine.checkStrictBounds(500.0, 998.5, 1000, 1000, 2.0));
}

TEST(ProjectiveTexturingTest, StrictBounding_RejectsRoofPartiallyOutsideRaster) {
    ProjectiveTexturingEngine engine;
    ProjectiveTexturingConfig config;
    config.strictBounding = true;
    config.guardBandPixels = 2.0;

    SpatialMetadata meta = createMockMetadata(500, 500, 0.0, 0.0, 1.0);

    // Place building straddling the right image edge (columns 490 to 510)
    BuildingInstance edgeBldg = createSquareBuilding(1, 490.0, -100.0, 20.0, 20.0);

    TexturingDiagnostics diag;
    std::vector<BuildingInstance> allBuildings = {edgeBldg};

    TexturedBuilding tb = engine.processBuilding(
        edgeBldg, allBuildings, meta, std::nullopt, std::nullopt, config, diag);

    EXPECT_FALSE(tb.isTexturedSuccessfully);
    EXPECT_EQ(tb.roofProvenance, MaterialProvenance::REJECTED_OUT_OF_BOUNDS);
    EXPECT_EQ(diag.rejectedOutOfBounds, 1u);

    // Verify neutral procedural color was assigned
    ASSERT_FALSE(tb.roofColors.empty());
    EXPECT_FLOAT_EQ(tb.roofColors[0], config.neutralRoofColor[0]);
    EXPECT_FLOAT_EQ(tb.roofColors[1], config.neutralRoofColor[1]);
    EXPECT_FLOAT_EQ(tb.roofColors[2], config.neutralRoofColor[2]);
    EXPECT_FLOAT_EQ(tb.roofColors[3], config.neutralRoofColor[3]);
}

// -----------------------------------------------------------------------------
// Test Suite 5: Anti-Bleeding Verification & Inward Inset
// -----------------------------------------------------------------------------
TEST(ProjectiveTexturingTest, AntiBleeding_DetectsAndRejectsOverlappingRoofs) {
    ProjectiveTexturingEngine engine;
    ProjectiveTexturingConfig config;
    config.strictAntiBleeding = true;
    config.minAdjacentSeparationPixels = 1.0;

    SpatialMetadata meta = createMockMetadata(1000, 1000, 0.0, 0.0, 1.0);
    // Sensor look: 45 degrees azimuth, 35 degrees off-nadir (causes significant lean)
    SensorLookGeometry geom = SensorLookGeometry::fromAzimuthAndOffNadir(45.0, 35.0);

    // Building 1: Tall tower (height 60m) at (100, -100)
    BuildingInstance bldg1 = createSquareBuilding(1, 100.0, -100.0, 20.0, 60.0);

    // Building 2: Directly in the lean path of Building 1 at (130, -70)
    BuildingInstance bldg2 = createSquareBuilding(2, 130.0, -70.0, 20.0, 10.0);

    std::vector<BuildingInstance> allBuildings = {bldg1, bldg2};
    TexturingDiagnostics diag;

    // Building 1's roof projects into Building 2's area
    TexturedBuilding tb1 = engine.processBuilding(
        bldg1, allBuildings, meta, std::nullopt, geom, config, diag);

    EXPECT_FALSE(tb1.isTexturedSuccessfully);
    EXPECT_EQ(tb1.roofProvenance, MaterialProvenance::REJECTED_BLEED_RISK);
    EXPECT_EQ(diag.rejectedBleedRisk, 1u);
}

TEST(ProjectiveTexturingTest, AntiBleeding_InwardSafetyInsetContractsUvs) {
    ProjectiveTexturingEngine engine;
    SpatialMetadata meta = createMockMetadata(1000, 1000, 0.0, 0.0, 1.0);

    std::vector<ProjectedVertex> verts(4);
    verts[0].u = 0.1f; verts[0].v = 0.1f; // Top-left
    verts[1].u = 0.2f; verts[1].v = 0.1f; // Top-right
    verts[2].u = 0.2f; verts[2].v = 0.2f; // Bottom-right
    verts[3].u = 0.1f; verts[3].v = 0.2f; // Bottom-left

    // Apply 2-pixel inset
    auto insetVerts = engine.applyAntiBleedInset(verts, 2.0, meta.width, meta.height);

    ASSERT_EQ(insetVerts.size(), 4u);
    // Center is (0.15, 0.15)
    // Vert 0 should move towards center (+u, +v)
    EXPECT_GT(insetVerts[0].u, verts[0].u);
    EXPECT_GT(insetVerts[0].v, verts[0].v);

    // Vert 2 should move towards center (-u, -v)
    EXPECT_LT(insetVerts[2].u, verts[2].u);
    EXPECT_LT(insetVerts[2].v, verts[2].v);
}

// -----------------------------------------------------------------------------
// Test Suite 6: Full Collection Processing & Provenance Accounting
// -----------------------------------------------------------------------------
TEST(ProjectiveTexturingTest, ProvenanceLogic_ComprehensiveAccounting) {
    ProjectiveTexturingEngine engine;
    ProjectiveTexturingConfig config;
    config.strictBounding = true;
    config.strictAntiBleeding = true;
    config.enableFacadeRecovery = true;

    SpatialMetadata meta = createMockMetadata(1000, 1000, 0.0, 0.0, 1.0);
    SensorLookGeometry geom = SensorLookGeometry::fromAzimuthAndOffNadir(180.0, 20.0);

    BuildingCollection collection;
    // Bldg 1: Normal clean building
    collection.buildings.push_back(createSquareBuilding(1, 200.0, -200.0, 30.0, 25.0));
    // Bldg 2: Out of bounds building (X = 990 to 1020)
    collection.buildings.push_back(createSquareBuilding(2, 990.0, -200.0, 30.0, 25.0));

    TexturingDiagnostics diag;
    auto textured = engine.processBuildingCollection(
        collection, meta, std::nullopt, geom, config, diag);

    ASSERT_EQ(textured.size(), 2u);

    // Bldg 1 should be textured with affine fallback
    EXPECT_TRUE(textured[0].isTexturedSuccessfully);
    EXPECT_EQ(textured[0].roofProvenance, MaterialProvenance::SOURCE_PROJECTIVE_AFFINE);

    // Bldg 2 should be rejected out-of-bounds
    EXPECT_FALSE(textured[1].isTexturedSuccessfully);
    EXPECT_EQ(textured[1].roofProvenance, MaterialProvenance::REJECTED_OUT_OF_BOUNDS);

    EXPECT_EQ(diag.totalBuildingsProcessed, 2u);
    EXPECT_EQ(diag.affineFallbackRoofs, 1u);
    EXPECT_EQ(diag.rejectedOutOfBounds, 1u);
    EXPECT_GT(diag.visibleFacadesRectified, 0u);
    EXPECT_GT(diag.hiddenFacadesProcedural, 0u);
}

TEST(ProjectiveTexturingTest, ProvenanceStrings_EnumConversions) {
    EXPECT_STREQ(toString(ProjectionMode::RPC_PROJECTIVE), "RPC_PROJECTIVE");
    EXPECT_STREQ(toString(ProjectionMode::AFFINE_FALLBACK), "AFFINE_FALLBACK");

    EXPECT_STREQ(toString(MaterialProvenance::SOURCE_PROJECTIVE_RPC), "SOURCE_PROJECTIVE_RPC");
    EXPECT_STREQ(toString(MaterialProvenance::SOURCE_PROJECTIVE_AFFINE), "SOURCE_PROJECTIVE_AFFINE");
    EXPECT_STREQ(toString(MaterialProvenance::FACADE_RECTIFIED_VISIBLE), "FACADE_RECTIFIED_VISIBLE");
    EXPECT_STREQ(toString(MaterialProvenance::PROCEDURAL_NEUTRAL), "PROCEDURAL_NEUTRAL");
    EXPECT_STREQ(toString(MaterialProvenance::OCCLUDED_BACKFACING), "OCCLUDED_BACKFACING");
    EXPECT_STREQ(toString(MaterialProvenance::REJECTED_OUT_OF_BOUNDS), "REJECTED_OUT_OF_BOUNDS");
    EXPECT_STREQ(toString(MaterialProvenance::REJECTED_UNCERTAIN), "REJECTED_UNCERTAIN");
    EXPECT_STREQ(toString(MaterialProvenance::REJECTED_BLEED_RISK), "REJECTED_BLEED_RISK");
}

// -----------------------------------------------------------------------------
// Test Suite 7: Strict Mathematical Edge Cases & Degenerate Geometry
// -----------------------------------------------------------------------------

TEST(ProjectiveTexturingTest, AntiBleeding_PreventsInsideOutUVsOnTinyPolygons) {
    ProjectiveTexturingEngine engine;
    SpatialMetadata meta = createMockMetadata(1000, 1000, 0.0, 0.0, 1.0);

    // Create an extremely tiny polygon (e.g., 0.001 UV width, representing 1 pixel)
    std::vector<ProjectedVertex> tinyVerts(4);
    tinyVerts[0].u = 0.500f; tinyVerts[0].v = 0.500f;
    tinyVerts[1].u = 0.501f; tinyVerts[1].v = 0.500f;
    tinyVerts[2].u = 0.501f; tinyVerts[2].v = 0.501f;
    tinyVerts[3].u = 0.500f; tinyVerts[3].v = 0.501f;

    // Apply a massive 10-pixel inset. 
    // The engine's `std::min(0.20, insetMarginPixels / distPx)` should catch this
    // and prevent the UVs from crossing the center (turning inside out).
    auto insetVerts = engine.applyAntiBleedInset(tinyVerts, 10.0, meta.width, meta.height);

    ASSERT_EQ(insetVerts.size(), 4u);
    
    // UVs should contract, but the left vertex must still remain strictly to the left of the right vertex.
    EXPECT_LT(insetVerts[0].u, insetVerts[1].u); 
    EXPECT_LT(insetVerts[3].u, insetVerts[2].u);
    EXPECT_LT(insetVerts[0].v, insetVerts[3].v);
    
    // Ensure they actually moved inward
    EXPECT_GT(insetVerts[0].u, 0.500f);
    EXPECT_LT(insetVerts[1].u, 0.501f);
}

TEST(ProjectiveTexturingTest, Displacement_ExtremeOffNadirClamping) {
    // Attempt to instantiate a sensor with a 150-degree off-nadir angle (impossible looking straight up/backward).
    // The constructor clamps to 89.9 degrees to prevent std::tan() from reaching infinity.
    SensorLookGeometry geom = SensorLookGeometry::fromAzimuthAndOffNadir(90.0, 150.0);
    
    EXPECT_NEAR(geom.getOffNadirDegrees(), 89.9, 1e-4);
    
    // Displacement should be massive but finite, not NaN or Infinity
    Displacement2D groundDisp = geom.computeGroundDisplacement(50.0);
    
    EXPECT_TRUE(std::isfinite(groundDisp.dx));
    EXPECT_TRUE(std::isfinite(groundDisp.dy));
    EXPECT_GT(groundDisp.dx, 10000.0); // 50 * tan(89.9) is approx 28,644
}

TEST(ProjectiveTexturingTest, Occlusion_ShorterNeighborDoesNotOccludeTallFacade) {
    ProjectiveTexturingEngine engine;
    ProjectiveTexturingConfig config;
    config.enableFacadeRecovery = true;
    config.enableNeighborOcclusionCheck = true;

    SpatialMetadata meta = createMockMetadata();
    SensorLookGeometry geom = SensorLookGeometry::fromAzimuthAndOffNadir(180.0, 30.0); // South

    // Target Building: 60m tall tower
    BuildingInstance target = createSquareBuilding(
        1, meta.geoTransform[0] + 100.0, meta.geoTransform[3] - 200.0, 20.0, 60.0, 0.0f);

    // Neighbor: 20m tall podium directly in front of the tower
    // Because 20m < (60m - 0.5m), the `isOccludedByNeighbor` optimization should skip this neighbor entirely.
    BuildingInstance shortNeighbor = createSquareBuilding(
        2, meta.geoTransform[0] + 100.0, meta.geoTransform[3] - 250.0, 20.0, 20.0, 0.0f);

    std::vector<BuildingInstance> allBuildings = {target, shortNeighbor};
    TexturingDiagnostics diag;

    auto strips = engine.recoverFacades(
        target, allBuildings, meta, std::nullopt, geom, config, diag);

    ASSERT_EQ(strips.size(), 4u);
    
    // The South-facing wall should remain VISIBLE because the neighbor is too short to occlude the roof.
    EXPECT_TRUE(strips[0].isVisibleToSensor);
    EXPECT_FALSE(strips[0].isOccludedByNeighbor);
    EXPECT_EQ(strips[0].provenance, MaterialProvenance::FACADE_RECTIFIED_VISIBLE);
}

TEST(ProjectiveTexturingTest, ProjectVertex_DegenerateAffineTransform) {
    ProjectiveTexturingEngine engine;
    ProjectiveTexturingConfig config;

    SpatialMetadata meta = createMockMetadata();
    // Destroy the affine transform (determinant = 0)
    meta.geoTransform[1] = 0.0; // pixelSizeX
    meta.geoTransform[2] = 0.0;
    meta.geoTransform[4] = 0.0;
    meta.geoTransform[5] = 0.0; // pixelSizeY

    ProjectedPoint pt{meta.geoTransform[0] + 100.0, meta.geoTransform[3] - 100.0};
    
    // The engine must catch std::abs(det) < 1.0e-12 and safely reject rather than divide by zero.
    ProjectedVertex v = engine.projectVertex(pt, 30.0, 20.0, meta, std::nullopt, config);

    EXPECT_FALSE(v.isValid);
    EXPECT_EQ(v.provenance, MaterialProvenance::REJECTED_UNCERTAIN);
    EXPECT_NE(v.rejectionReason.find("Degenerate"), std::string::npos);
}

TEST(ProjectiveTexturingTest, AntiBleeding_GracefulHandlingOfCollinearPolygons) {
    ProjectiveTexturingEngine engine;
    ProjectiveTexturingConfig config;
    config.strictAntiBleeding = true;

    SpatialMetadata meta = createMockMetadata(1000, 1000, 0.0, 0.0, 1.0);
    SensorLookGeometry geom = SensorLookGeometry::fromAzimuthAndOffNadir(0.0, 0.0);

    // Target Building
    BuildingInstance bldg1 = createSquareBuilding(1, 100.0, -100.0, 20.0, 30.0);

    // Degenerate Neighbor: A straight line folded back on itself (0 area)
    BuildingInstance bldg2;
    bldg2.buildingId = 2;
    bldg2.heightAboveGround = 30.0;
    bldg2.projectedFootprint.outerRing = {
        {100.0, -100.0},
        {120.0, -100.0},
        {110.0, -100.0}, // Collinear
        {100.0, -100.0}
    };

    std::vector<BuildingInstance> allBuildings = {bldg1, bldg2};
    TexturingDiagnostics diag;

    // The cross-product math in `segmentsIntersect` and `pointInPolygon` must process the 
    // degenerate neighbor without triggering NaNs, floating point exceptions, or infinite loops.
    TexturedBuilding tb1 = engine.processBuilding(
        bldg1, allBuildings, meta, std::nullopt, geom, config, diag);

    // Whether it considers a flat line as "bleeding" or not is secondary to it surviving the pass cleanly.
    // Given they share the exact edge/coordinates, it should trigger the bleed rejection.
    EXPECT_FALSE(tb1.isTexturedSuccessfully);
    EXPECT_EQ(tb1.roofProvenance, MaterialProvenance::REJECTED_BLEED_RISK);
}


// -----------------------------------------------------------------------------
// Test Suite 8: Complex Geometry & Robustness Limits
// -----------------------------------------------------------------------------

TEST(ProjectiveTexturingTest, Bounds_ExactGuardBandThresholds) {
    ProjectiveTexturingEngine engine;
    
    // Raster: 100x100, Guard Band: 2.0
    // Valid range should be exactly [2.0, 97.0] inclusive.
    
    // Exact valid boundaries
    EXPECT_TRUE(engine.checkStrictBounds(2.0, 2.0, 100, 100, 2.0));
    EXPECT_TRUE(engine.checkStrictBounds(97.0, 97.0, 100, 100, 2.0));
    
    // Just outside by epsilon
    EXPECT_FALSE(engine.checkStrictBounds(1.9999, 50.0, 100, 100, 2.0));
    EXPECT_FALSE(engine.checkStrictBounds(50.0, 97.0001, 100, 100, 2.0));
    
    // Image edges (0 and 99) should be strictly rejected
    EXPECT_FALSE(engine.checkStrictBounds(0.0, 50.0, 100, 100, 2.0));
    EXPECT_FALSE(engine.checkStrictBounds(50.0, 99.0, 100, 100, 2.0));
}

TEST(ProjectiveTexturingTest, Displacement_RejectsNegativeMetricHeights) {
    ProjectiveTexturingEngine engine;
    SpatialMetadata meta = createMockMetadata();
    SensorLookGeometry geom = SensorLookGeometry::fromAzimuthAndOffNadir(90.0, 45.0);
    
    // Physically impossible negative height above ground
    Displacement2D disp = engine.deriveRoofDisplacement(
        -10.0, meta, geom, std::nullopt, 0.0, 0.0, 0.0);
        
    // The engine must bypass calculations and return {0.0, 0.0}
    EXPECT_DOUBLE_EQ(disp.dx, 0.0);
    EXPECT_DOUBLE_EQ(disp.dy, 0.0);
}

TEST(ProjectiveTexturingTest, AntiBleeding_HandlesZeroLengthEdges) {
    ProjectiveTexturingEngine engine;
    ProjectiveTexturingConfig config;
    config.strictAntiBleeding = true;

    SpatialMetadata meta = createMockMetadata(1000, 1000, 0.0, 0.0, 1.0);
    SensorLookGeometry geom = SensorLookGeometry::fromAzimuthAndOffNadir(0.0, 0.0);

    BuildingInstance bldg1 = createSquareBuilding(1, 100.0, -100.0, 20.0, 30.0);
    
    // Duplicate a vertex to create a zero-length edge (degenerate geometry)
    bldg1.projectedFootprint.outerRing.insert(
        bldg1.projectedFootprint.outerRing.begin() + 1, 
        bldg1.projectedFootprint.outerRing[1]);

    BuildingInstance bldg2 = createSquareBuilding(2, 500.0, -500.0, 20.0, 30.0); // Safely far away

    std::vector<BuildingInstance> allBuildings = {bldg1, bldg2};
    TexturingDiagnostics diag;

    // The cross-product and segment math must not divide by zero or NaN-out on the duplicate vertex
    TexturedBuilding tb1 = engine.processBuilding(
        bldg1, allBuildings, meta, std::nullopt, geom, config, diag);

    // It should survive the geometry pass and texture successfully since no neighbor overlap occurs
    EXPECT_TRUE(tb1.isTexturedSuccessfully);
    EXPECT_EQ(tb1.roofProvenance, MaterialProvenance::SOURCE_PROJECTIVE_AFFINE);
}

TEST(ProjectiveTexturingTest, AntiBleeding_AllowsCollinearButDisjointPolygons) {
    ProjectiveTexturingEngine engine;
    ProjectiveTexturingConfig config;
    config.strictAntiBleeding = true;
    config.minAdjacentSeparationPixels = 1.0;

    SpatialMetadata meta = createMockMetadata(1000, 1000, 0.0, 0.0, 1.0);
    SensorLookGeometry geom = SensorLookGeometry::fromAzimuthAndOffNadir(0.0, 0.0);

    // Two buildings on the same Y-axis, separated by 10 units in X.
    // They are collinear but do not touch.
    BuildingInstance bldg1 = createSquareBuilding(1, 100.0, -100.0, 10.0, 30.0);
    BuildingInstance bldg2 = createSquareBuilding(2, 120.0, -100.0, 10.0, 30.0);

    std::vector<BuildingInstance> allBuildings = {bldg1, bldg2};
    TexturingDiagnostics diag;

    TexturedBuilding tb1 = engine.processBuilding(
        bldg1, allBuildings, meta, std::nullopt, geom, config, diag);

    // The updated segmentsIntersect function must recognize they are disjoint and allow texturing
    EXPECT_TRUE(tb1.isTexturedSuccessfully);
    EXPECT_EQ(tb1.roofProvenance, MaterialProvenance::SOURCE_PROJECTIVE_AFFINE);
}

TEST(ProjectiveTexturingTest, AntiBleeding_ConcaveUshapeIntersection) {
    ProjectiveTexturingEngine engine;
    ProjectiveTexturingConfig config;
    config.strictAntiBleeding = true;

    SpatialMetadata meta = createMockMetadata(1000, 1000, 0.0, 0.0, 1.0);
    SensorLookGeometry geom = SensorLookGeometry::fromAzimuthAndOffNadir(0.0, 0.0);

    // Building 1: A U-shaped concave polygon
    BuildingInstance uShape;
    uShape.buildingId = 1;
    uShape.representativeBaseElevation = 10.0;
    uShape.roofElevation = 40.0;
    uShape.heightAboveGround = 30.0;
    uShape.projectedFootprint.outerRing = {
        {100.0, -100.0}, {130.0, -100.0}, {130.0, -70.0}, {120.0, -70.0},
        {120.0, -90.0},  {110.0, -90.0},  {110.0, -70.0}, {100.0, -70.0}
    };

    // Building 2: A small block sitting precisely inside the opening of the "U", overlapping the arms
    BuildingInstance blocker = createSquareBuilding(2, 105.0, -85.0, 20.0, 30.0);

    std::vector<BuildingInstance> allBuildings = {uShape, blocker};
    TexturingDiagnostics diag;

    TexturedBuilding tbU = engine.processBuilding(
        uShape, allBuildings, meta, std::nullopt, geom, config, diag);

    // The segment intersection must trace the concave arms and correctly flag the collision inside the U
    EXPECT_FALSE(tbU.isTexturedSuccessfully);
    EXPECT_EQ(tbU.roofProvenance, MaterialProvenance::REJECTED_BLEED_RISK);
}

TEST(ProjectiveTexturingTest, Robustness_SelfIntersectingBowtiePolygon) {
    ProjectiveTexturingEngine engine;
    ProjectiveTexturingConfig config;

    SpatialMetadata meta = createMockMetadata(1000, 1000, 0.0, 0.0, 1.0);
    SensorLookGeometry geom = SensorLookGeometry::fromAzimuthAndOffNadir(0.0, 0.0);

    // A Bowtie polygon (self-intersecting)
    BuildingInstance bowtie;
    bowtie.buildingId = 1;
    bowtie.representativeBaseElevation = 10.0;
    bowtie.roofElevation = 40.0;
    bowtie.heightAboveGround = 30.0;
    bowtie.projectedFootprint.outerRing = {
        {100.0, -100.0}, {120.0, -80.0}, {100.0, -80.0}, {120.0, -100.0}
    };

    std::vector<BuildingInstance> allBuildings = {bowtie};
    TexturingDiagnostics diag;

    // The primary goal is that processBuilding does not hang, infinite-loop, or crash
    // when pointInPolygon ray-casting hits a self-intersecting boundary.
    TexturedBuilding tb = engine.processBuilding(
        bowtie, allBuildings, meta, std::nullopt, geom, config, diag);

    // Test passes if it completes execution. (It will likely texture it, as it doesn't overlap a neighbor).
    EXPECT_EQ(tb.buildingId, 1u);
}