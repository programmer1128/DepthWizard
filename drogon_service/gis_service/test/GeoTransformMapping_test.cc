// The shared pixel/world/UV helper must reproduce exactly what TerrainMesher
// and BuildingMesher already do, so new layers cannot drift from them.

#include "BuildingReconstructionTestSupport.h"
#include "MeshMapping/BuildingMesher.h"
#include "MeshMapping/GeoTransformMapping.h"
#include "MeshMapping/LocalFrameTransformer.h"
#include "MeshMapping/TerrainMesher.h"

#include <gtest/gtest.h>

using namespace depthwizard::test;
namespace geo = depthwizard::geo;

namespace
{
constexpr int kWidth = 20;
constexpr int kHeight = 14;

// Rotated ~16 degrees with non-square 10 m x 12 m pixels: gt[2] != gt[4], so
// a transposed term, swapped u/v or V flip changes the result.
SpatialMetadata rotatedMetadata()
{
    SpatialMetadata metadata = makeProjectedMetadata(kWidth, kHeight, 10.0, -12.0);
    metadata.geoTransform = {8110000.0, 9.6, 3.36, 4120000.0, 2.8, -11.52};
    return metadata;
}

GeoreferencedSurfaceBundle surfaceFor(const SpatialMetadata& metadata)
{
    GeoreferencedSurfaceBundle surface = makeSurface(kWidth, kHeight, 1000.0F, 0.0F);
    surface.spatialMetadata = metadata;
    for (int row = 0; row < kHeight; ++row)
        for (int column = 0; column < kWidth; ++column)
            surface.dtm.data[static_cast<std::size_t>(row) * kWidth + column] += 2.0F * column + 3.0F * row;
    surface.dsm = surface.dtm;
    return surface;
}
} // namespace

TEST(GeoTransformMappingTest, MatchesTerrainMesherVertexPositionsAndUvsBitForBit)
{
    const SpatialMetadata metadata = rotatedMetadata();
    const GeoreferencedSurfaceBundle surface = surfaceFor(metadata);
    const LocalSceneFrame frame = LocalFrameTransformer::create(metadata, surface);
    TerrainMeshConfig config;
    config.generateSkirt = false;
    const TerrainMesh terrain = TerrainMesher::generate(surface, metadata, frame, config);
    const auto& positions = terrain.terrainPrimitive.positions;
    ASSERT_TRUE(terrain.terrainPrimitive.uvs.has_value());
    const auto& uvs = *terrain.terrainPrimitive.uvs;
    ASSERT_EQ(positions.size(), static_cast<std::size_t>(kWidth * kHeight * 3)); // stride 1, no skirt

    // Grid nodes: centres inside, the outer ring on the pixel edges 0 and W/H.
    for (int y = 0; y < kHeight; ++y)
        for (int x = 0; x < kWidth; ++x)
        {
            const double column = x == 0 ? 0.0 : (x == kWidth - 1 ? kWidth : x + 0.5);
            const double row = y == 0 ? 0.0 : (y == kHeight - 1 ? kHeight : y + 0.5);
            const std::size_t vertex = static_cast<std::size_t>(y) * kWidth + x;
            const LocalPoint local = geo::pixelEdgeToLocal(metadata, frame, column, row);
            const auto [u, v] = geo::pixelEdgeToUv(metadata, column, row);
            EXPECT_EQ(positions[vertex * 3], static_cast<float>(local.x)) << x << "," << y;
            EXPECT_EQ(positions[vertex * 3 + 2], static_cast<float>(local.z)) << x << "," << y;
            EXPECT_EQ(uvs[vertex * 2], u) << x << "," << y;
            EXPECT_EQ(uvs[vertex * 2 + 1], v) << x << "," << y;
        }
}

TEST(GeoTransformMappingTest, MatchesBuildingMesherRoofUvsIncludingRidgeVertices)
{
    const SpatialMetadata metadata = rotatedMetadata();
    const GeoreferencedSurfaceBundle surface = surfaceFor(metadata);
    const LocalSceneFrame frame = LocalFrameTransformer::create(metadata, surface);

    // A gable block inside the image, defined in pixel-edge coordinates.
    BuildingInstance building;
    building.buildingId = 7;
    building.heightAboveGround = 12.0F;
    building.representativeBaseElevation = 1010.0F;
    building.roofElevation = 1022.0F;
    DecomposedBuildingBlock block;
    block.pixelCorners = {{{4.0, 3.0}, {14.0, 3.0}, {14.0, 9.0}, {4.0, 9.0}}};
    for (std::size_t corner = 0; corner < 4; ++corner)
    {
        block.projectedCorners[corner] =
            geo::pixelEdgeToProjected(metadata, block.pixelCorners[corner].column, block.pixelCorners[corner].row);
        building.projectedFootprint.outerRing.push_back(block.projectedCorners[corner]);
    }
    block.roof.type = RoofType::GABLE;
    block.roof.eaveHeightAboveGround = 8.0F;
    block.roof.ridgeHeightAboveGround = 12.0F;
    block.roof.ridgeStartProjected = geo::pixelEdgeToProjected(metadata, 4.0, 6.0);
    block.roof.ridgeEndProjected = geo::pixelEdgeToProjected(metadata, 14.0, 6.0);
    building.blocks.push_back(block);
    BuildingCollection buildings;
    buildings.buildings.push_back(building);

    BuildingMeshConfig config;
    config.generateRoofUVs = true;
    const BuildingMesh mesh = BuildingMesher::generate(buildings, frame, config, &metadata);
    ASSERT_TRUE(mesh.roofPrimitive.uvs.has_value());
    const auto& positions = mesh.roofPrimitive.positions;
    ASSERT_GE(positions.size(), 12U);
    bool ridgeChecked = false;
    for (std::size_t vertex = 0; vertex < positions.size() / 3; ++vertex)
    {
        // BuildingMesher maps the double-precision local point; the stored
        // position is float, hence the 1e-6 (1e-5 px) tolerance.
        const auto [u, v] = geo::localToUv(metadata, frame, positions[vertex * 3], positions[vertex * 3 + 2]);
        EXPECT_NEAR((*mesh.roofPrimitive.uvs)[vertex * 2], u, 1e-6);
        EXPECT_NEAR((*mesh.roofPrimitive.uvs)[vertex * 2 + 1], v, 1e-6);
        ridgeChecked = ridgeChecked || positions[vertex * 3 + 1] > 1021.9F - static_cast<float>(frame.elevationOrigin);
    }
    EXPECT_TRUE(ridgeChecked);
}

TEST(GeoTransformMappingTest, ConventionsEdgesCentresUvOriginAndNorthIsMinusZ)
{
    const SpatialMetadata metadata = rotatedMetadata();
    const GeoreferencedSurfaceBundle surface = surfaceFor(metadata);
    const LocalSceneFrame frame = LocalFrameTransformer::create(metadata, surface);

    // Every geotransform term, in its own slot (a transposed b/c fails here).
    const ProjectedPoint corner = geo::pixelEdgeToProjected(metadata, 3.0, 5.0);
    EXPECT_DOUBLE_EQ(corner.easting, 8110000.0 + 3.0 * 9.6 + 5.0 * 3.36);
    EXPECT_DOUBLE_EQ(corner.northing, 4120000.0 + 3.0 * 2.8 + 5.0 * -11.52);
    // A raster sample is the pixel centre.
    const ProjectedPoint centre = geo::pixelCentreToProjected(metadata, 3, 5);
    const ProjectedPoint expectedCentre = geo::pixelEdgeToProjected(metadata, 3.5, 5.5);
    EXPECT_DOUBLE_EQ(centre.easting, expectedCentre.easting);
    EXPECT_DOUBLE_EQ(centre.northing, expectedCentre.northing);

    // Top-left UV origin, no V flip, u from columns and v from rows.
    EXPECT_EQ(geo::pixelEdgeToUv(metadata, 0.0, 0.0), std::make_pair(0.0F, 0.0F));
    EXPECT_EQ(geo::pixelEdgeToUv(metadata, kWidth, kHeight), std::make_pair(1.0F, 1.0F));
    EXPECT_EQ(geo::pixelEdgeToUv(metadata, 5.0, 0.0), std::make_pair(5.0F / kWidth, 0.0F));
    EXPECT_EQ(geo::pixelEdgeToUv(metadata, 0.0, 7.0), std::make_pair(0.0F, 0.5F));

    // Moving down the image goes south: northing falls, so local Z grows.
    const LocalPoint top = geo::pixelEdgeToLocal(metadata, frame, 5.0, 2.0);
    const LocalPoint lower = geo::pixelEdgeToLocal(metadata, frame, 5.0, 9.0);
    EXPECT_GT(lower.z, top.z);
    const ProjectedPoint topProjected = geo::pixelEdgeToProjected(metadata, 5.0, 2.0);
    EXPECT_DOUBLE_EQ(top.z, -(topProjected.northing - frame.projectedOriginY));
    EXPECT_DOUBLE_EQ(top.x, topProjected.easting - frame.projectedOriginX);

    // Inverse round trip through the local frame.
    for (const auto& [column, row] : std::vector<std::pair<double, double>>{{0, 0}, {3.5, 5.5}, {19.25, 13.75}})
    {
        const LocalPoint local = geo::pixelEdgeToLocal(metadata, frame, column, row);
        const auto [backColumn, backRow] = geo::localToPixelEdge(metadata, frame, local.x, local.z);
        EXPECT_NEAR(backColumn, column, 1e-9);
        EXPECT_NEAR(backRow, row, 1e-9);
    }

    // Per-axis spacing: |(9.6, 2.8)| = 10 m, |(3.36, -11.52)| = 12 m.
    EXPECT_NEAR(geo::columnSpacing(metadata), 10.0, 1e-12);
    EXPECT_NEAR(geo::rowSpacing(metadata), 12.0, 1e-12);
}
