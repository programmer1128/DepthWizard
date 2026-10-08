// Stage 3 of the vegetation overlay: dense/isolated classification, the
// rendered-terrain sampler and the canopy mesh (no GLB packaging here).

#include "BuildingReconstruction/BuildingReconstructionConfig.h"
#include "BuildingReconstructionTestSupport.h"
#include "MeshMapping/GeoTransformMapping.h"
#include "MeshMapping/LocalFrameTransformer.h"
#include "MeshMapping/TerrainMesher.h"
#include "MeshMapping/TerrainSurfaceSampler.h"
#include "Vegetation/VegetationCanopyBuilder.h"
#include "Vegetation/VegetationClassifier.h"
#include "Vegetation/VegetationExtractor.h"
#include "Vegetation/VegetationHeightSampler.h"

#include <gtest/gtest.h>

#include <cmath>
#include <limits>

using namespace depthwizard::test;
namespace geo = depthwizard::geo;

namespace
{
struct Scene
{
    int width;
    int height;
    SpatialMetadata metadata;
    SemanticScene semantics;
    GeoreferencedSurfaceBundle surface;
    RasterGrid<uint8_t> footprints;
    VegetationConfig config;

    Scene(int w, int h, double pixelX, double pixelY)
        : width(w), height(h), metadata(makeProjectedMetadata(w, h, pixelX, pixelY)),
          semantics(makeSemanticScene(w, h, SemanticClass::GROUND)), surface(makeSurface(w, h, 100.0F, 0.0F)),
          footprints(makeConstantGrid<uint8_t>(w, h, uint8_t{0}))
    {
        surface.spatialMetadata = metadata;
        semantics.groundProbability = makeConstantGrid(w, h, 0.9F);
        config.mode = VegetationMode::ON;
    }
    std::size_t index(int x, int y) const { return static_cast<std::size_t>(y) * width + x; }
    void vegetation(int x0, int y0, int x1, int y1, float heightMetres)
    {
        fillRectangle(semantics.finalClassMap, x0, y0, x1, y1, SemanticClass::VEGETATION);
        fillRectangle(semantics.vegetationProbability, x0, y0, x1, y1, 0.9F);
        fillRectangle(surface.ndsm, x0, y0, x1, y1, heightMetres);
        for (int y = y0; y < y1; ++y)
            for (int x = x0; x < x1; ++x) surface.dsm.data[index(x, y)] = surface.dtm.data[index(x, y)] + heightMetres;
    }

    struct Result
    {
        VegetationMask mask;
        VegetationHeights heights;
        VegetationClassification classification;
        VegetationCanopyMesh canopy;
        LocalSceneFrame frame;
    };
    Result run(ScenePresentation presentation = ScenePresentation::METRIC, float buildingScale = 2.25F,
               TerrainMeshConfig terrain = TerrainMeshConfig()) const
    {
        Result result;
        result.mask = VegetationExtractor::extract(semantics, surface, footprints, metadata, config);
        result.heights = VegetationHeightSampler::sample(result.mask, surface, config);
        result.classification = VegetationClassifier::classify(result.mask, config);
        result.frame = LocalFrameTransformer::create(metadata, surface);
        VegetationCanopyInput input;
        input.mask = &result.mask;
        input.classification = &result.classification;
        input.heights = &result.heights;
        input.config = config;
        input.buildingDisplayHeightScale = buildingScale;
        if (presentation == ScenePresentation::FLAT_URBAN)
            terrain.elevationSource = TerrainElevationSource::FLAT_PRESENTATION;
        result.canopy = VegetationCanopyBuilder::build(input, surface, metadata, result.frame, terrain, presentation);
        return result;
    }
};

VegetationClass classAt(const Scene& s, const VegetationClassification& c, int x, int y)
{
    return static_cast<VegetationClass>(c.classes.data[s.index(x, y)]);
}

// Pixel-edge coordinate of canopy vertex `v` through its own UV.
std::pair<double, double> pixelOfUv(const Scene& s, const MeshPrimitive& p, std::size_t v)
{
    return {(*p.uvs)[v * 2] * s.width, (*p.uvs)[v * 2 + 1] * s.height};
}
} // namespace

// --- Classification ---------------------------------------------------------

TEST(VegetationClassifierTest, LargeDenseRegionsAreCanopyAndCompactCrownsStayTrees)
{
    Scene s(200, 160, 0.5, -0.5);
    s.vegetation(10, 10, 90, 90, 12.0F);   // 40 m x 40 m park: 1600 m2
    s.vegetation(120, 20, 132, 32, 9.0F);  // 6 m crown: 36 m2
    s.vegetation(150, 100, 160, 110, 8.0F);// 5 m crown
    const auto r = s.run();
    EXPECT_TRUE(r.classification.stats.individualTreesResolvable);
    EXPECT_EQ(classAt(s, r.classification, 50, 50), VegetationClass::DENSE);
    EXPECT_EQ(classAt(s, r.classification, 11, 11), VegetationClass::DENSE); // Fringe joins its core
    EXPECT_EQ(classAt(s, r.classification, 126, 26), VegetationClass::ISOLATED);
    EXPECT_EQ(classAt(s, r.classification, 155, 105), VegetationClass::ISOLATED);
    EXPECT_EQ(r.classification.stats.denseComponents, 1U);
    EXPECT_EQ(r.classification.stats.isolatedComponents, 2U);
    // Every mask pixel has exactly one class.
    EXPECT_EQ(r.classification.stats.densePixels + r.classification.stats.isolatedPixels,
              r.mask.stats.cleanedPixels());
    EXPECT_EQ(r.classification.stats.denseConfirmed, 6400U);
}

TEST(VegetationClassifierTest, ALongNarrowRowOfCrownsIsNotDense)
{
    // A 4 m wide, 80 m long street-tree row: large area, but too narrow.
    Scene s(200, 60, 0.5, -0.5);
    s.vegetation(10, 20, 170, 28, 9.0F);
    const auto r = s.run();
    EXPECT_EQ(r.classification.stats.densePixels, 0U);
    EXPECT_EQ(r.classification.stats.isolatedPixels, r.mask.stats.cleanedPixels());
    EXPECT_GE(r.classification.stats.rejectedCores, 0U);
}

TEST(VegetationClassifierTest, CoarseImageryIsAllCanopyAndNeverTrees)
{
    Scene s(40, 30, 10.0, -10.0);  // Test8-like 10 m pixels
    s.vegetation(5, 5, 6, 6, 9.0F); // One isolated pixel: a 100 m2 patch
    s.vegetation(20, 10, 30, 20, 12.0F);
    const auto r = s.run();
    EXPECT_FALSE(r.classification.stats.individualTreesResolvable);
    EXPECT_EQ(r.classification.stats.isolatedPixels, 0U);
    EXPECT_EQ(r.classification.stats.densePixels, r.mask.stats.cleanedPixels());
    EXPECT_EQ(classAt(s, r.classification, 5, 5), VegetationClass::DENSE);
}

TEST(VegetationClassifierTest, ClassificationIsDeterministicAndSeedIndependent)
{
    Scene s(200, 160, 0.5, -0.5);
    s.vegetation(10, 10, 90, 90, 12.0F);
    s.vegetation(120, 20, 132, 32, 9.0F);
    const auto first = s.run();
    s.config.seed = 7;
    const auto second = s.run();
    EXPECT_EQ(first.classification.classes.data, second.classification.classes.data);
    EXPECT_EQ(first.canopy.primitive.positions, second.canopy.primitive.positions);
    EXPECT_EQ(first.canopy.primitive.indices, second.canopy.primitive.indices);
}

// --- Terrain sampler --------------------------------------------------------

TEST(TerrainSurfaceSamplerTest, MatchesTheRenderedTerrainIncludingDecimatedGrids)
{
    // Rotated, non-square pixels and a decimated grid (stride 3).
    SpatialMetadata metadata = makeProjectedMetadata(40, 31, 10.0, -12.0);
    metadata.geoTransform = {8110000.0, 9.6, 3.36, 4120000.0, 2.8, -11.52};
    GeoreferencedSurfaceBundle surface = makeSurface(40, 31, 0.0F, 0.0F);
    surface.spatialMetadata = metadata;
    for (int y = 0; y < 31; ++y)
        for (int x = 0; x < 40; ++x)
            surface.dtm.data[static_cast<std::size_t>(y) * 40 + x] =
                1500.0F + 30.0F * std::sin(0.4F * x) + 20.0F * std::cos(0.3F * y);
    surface.dsm = surface.dtm;
    const LocalSceneFrame frame = LocalFrameTransformer::create(metadata, surface);
    TerrainMeshConfig config;
    config.maxGridSize = 15;
    config.generateSkirt = false;
    const TerrainSurfaceSampler sampler(surface, metadata, frame, config);
    ASSERT_TRUE(sampler.supported());
    EXPECT_EQ(sampler.stride(), 3);
    const TerrainMesh terrain = TerrainMesher::generate(surface, metadata, frame, config);
    const auto& positions = terrain.terrainPrimitive.positions;
    const auto& uvs = *terrain.terrainPrimitive.uvs;
    const auto& indices = terrain.terrainPrimitive.indices;
    // Nodes: bit-identical to the rendered vertices.
    for (std::size_t v = 0; v < positions.size() / 3; ++v)
    {
        const auto height = sampler.localHeight(uvs[v * 2] * 40.0, uvs[v * 2 + 1] * 31.0);
        ASSERT_TRUE(height.has_value());
        EXPECT_NEAR(*height, positions[v * 3 + 1], 1e-4) << v;
    }
    // Inside every rendered triangle: the barycentric value of that triangle.
    for (std::size_t t = 0; t + 2 < indices.size(); t += 3)
    {
        double column = 0, row = 0, y = 0;
        for (int k = 0; k < 3; ++k)
        {
            column += uvs[indices[t + k] * 2] * 40.0 / 3.0;
            row += uvs[indices[t + k] * 2 + 1] * 31.0 / 3.0;
            y += positions[indices[t + k] * 3 + 1] / 3.0;
        }
        const auto height = sampler.localHeight(column, row);
        ASSERT_TRUE(height.has_value());
        EXPECT_NEAR(*height, y, 1e-3) << "triangle " << t / 3;
    }
}

// --- Canopy heights ---------------------------------------------------------

TEST(VegetationCanopyTest, MetricTopIsTerrainBasePlusNdsmNeverRawDsm)
{
    Scene s(120, 100, 0.5, -0.5);
    for (int y = 0; y < s.height; ++y)
        for (int x = 0; x < s.width; ++x) s.surface.dtm.data[s.index(x, y)] = 800.0F + 0.2F * x + 0.1F * y;
    s.surface.dsm = s.surface.dtm;
    s.vegetation(10, 10, 110, 90, 9.0F); // dsm ~ 820 m: never an object height
    const auto r = s.run(ScenePresentation::METRIC);
    ASSERT_FALSE(r.canopy.empty()) << r.canopy.stats.skippedReason;
    EXPECT_EQ(r.canopy.stats.presentationMode, "metric");
    EXPECT_FLOAT_EQ(r.canopy.stats.displayHeightScale, 1.0F);
    const auto& p = r.canopy.primitive;
    std::size_t interior = 0;
    for (std::size_t v = 0; v < p.positions.size() / 3; ++v)
    {
        const auto [column, row] = pixelOfUv(s, p, v);
        const int x = static_cast<int>(column), y = static_cast<int>(row);
        const float baseY = s.surface.dtm.data[s.index(x, y)] - static_cast<float>(r.frame.elevationOrigin);
        const float objectY = p.positions[v * 3 + 1] - baseY;
        EXPECT_LE(objectY, 9.0F + 1e-3F);
        EXPECT_GT(objectY, 0.0F);
        // Beyond the 45-degree edge ramp (8.7 m) plus the 3 m crown rounding.
        if (x >= 40 && x < 80 && y >= 40 && y < 60)
        {
            EXPECT_NEAR(objectY, 9.0F, 1e-3F) << x << "," << y;
            ++interior;
        }
    }
    EXPECT_GT(interior, 300U);
    EXPECT_NEAR(r.canopy.stats.metricHeightMax, 9.0F, 1e-3F);
}

TEST(VegetationCanopyTest, FlatUrbanTopIsGroundPlusNdsmTimesTheBuildingScale)
{
    Scene s(200, 160, 0.5, -0.5);
    s.vegetation(10, 10, 190, 150, 8.0F);
    const float buildingScale = BuildingReconstructionConfig{}.heightScaleMultiplier;
    const auto r = s.run(ScenePresentation::FLAT_URBAN, buildingScale);
    ASSERT_FALSE(r.canopy.empty());
    EXPECT_EQ(r.canopy.stats.presentationMode, "flat_urban");
    EXPECT_FLOAT_EQ(r.canopy.stats.displayHeightScale, buildingScale);
    const auto& p = r.canopy.primitive;
    for (std::size_t v = 0; v < p.positions.size() / 3; ++v)
    {
        const auto [column, row] = pixelOfUv(s, p, v);
        if (column > 55 && column < 145 && row > 55 && row < 105) // Ramp 17.7 m + rounding 3 m
            EXPECT_NEAR(p.positions[v * 3 + 1], 8.0F * buildingScale, 1e-3F);
        EXPECT_GE(p.positions[v * 3 + 1], s.config.canopyLiftMetres - 1e-6F); // Clear of the Y = 0 ground
    }
    EXPECT_NEAR(r.canopy.stats.displayHeightMax, 8.0F * buildingScale, 1e-3F);
    EXPECT_NEAR(r.canopy.stats.metricHeightMax, 8.0F, 1e-3F);
}

// --- Boundaries and smoothing ----------------------------------------------

TEST(VegetationCanopyTest, NeverCrossesBuildingsRoadsWaterNoDataOrTheImageEdge)
{
    Scene s(160, 140, 0.5, -0.5);
    s.vegetation(0, 0, 160, 140, 10.0F); // Up to the image border
    fillRectangle(s.footprints, 60, 50, 90, 80, uint8_t{1});
    fillRectangle(s.semantics.finalClassMap, 60, 50, 90, 80, SemanticClass::BUILDING);
    fillRectangle(s.semantics.finalClassMap, 0, 110, 160, 114, SemanticClass::ROAD);
    fillRectangle(s.semantics.finalClassMap, 120, 10, 140, 30, SemanticClass::WATER);
    // One-pixel NoData and invalid lines on rows 21 and 43 (coprime, so any
    // stride above 1 places at least one strictly inside a cell).
    for (int x = 10; x < 50; ++x) s.surface.ndsm.data[s.index(x, 21)] = std::numeric_limits<float>::quiet_NaN();
    for (int x = 10; x < 50; ++x) s.surface.validMask.data[s.index(x, 43)] = 0;
    // Full resolution, then a forced coarse grid whose cells span interior
    // pixels (where the barrier-block rule, not the corner rule, decides).
    for (const int budget : {200000, 4000})
    {
    s.config.canopyMaxTriangles = budget;
    const auto r = s.run();
    ASSERT_FALSE(r.canopy.empty());
    const auto& p = r.canopy.primitive;
    const auto barrierAt = [&](int x, int y) { return r.mask.barrierMask.data[s.index(x, y)] != 0; };
    // Each triangle lies inside the pixel block of its corner pixels: no
    // barrier pixel may sit in that block.
    for (std::size_t t = 0; t + 2 < p.indices.size(); t += 3)
    {
        double minC = 1e9, maxC = -1e9, minR = 1e9, maxR = -1e9;
        for (int k = 0; k < 3; ++k)
        {
            const auto [column, row] = pixelOfUv(s, p, p.indices[t + k]);
            minC = std::min(minC, column); maxC = std::max(maxC, column);
            minR = std::min(minR, row); maxR = std::max(maxR, row);
        }
        ASSERT_GE(minC, 0.0); ASSERT_LE(maxC, s.width); ASSERT_GE(minR, 0.0); ASSERT_LE(maxR, s.height);
        for (int y = static_cast<int>(minR); y <= static_cast<int>(maxR) && y < s.height; ++y)
            for (int x = static_cast<int>(minC); x <= static_cast<int>(maxC) && x < s.width; ++x)
                ASSERT_FALSE(barrierAt(x, y)) << "triangle " << t / 3 << " covers barrier pixel " << x << "," << y;
    }
    if (budget == 4000)
    {
        EXPECT_GT(r.canopy.stats.stride, 1);
        EXPECT_GT(r.canopy.stats.rejectedBarrierCells, 0U);
    }
    }
}

TEST(VegetationCanopyTest, SmoothingIsMaskNormalisedAndNeverBleeds)
{
    Scene s(300, 240, 0.5, -0.5);
    s.vegetation(10, 10, 290, 230, 10.0F);
    fillRectangle(s.surface.ndsm, 150, 10, 290, 230, 20.0F); // Taller half
    s.config.canopySmoothRadiusMetres = 2.0F;
    const auto r = s.run();
    ASSERT_FALSE(r.canopy.empty());
    const auto& p = r.canopy.primitive;
    for (std::size_t v = 0; v < p.positions.size() / 3; ++v)
    {
        const auto [column, row] = pixelOfUv(s, p, v);
        const int x = static_cast<int>(column), y = static_cast<int>(row);
        const float objectY = p.positions[v * 3 + 1] - (s.surface.dtm.data[s.index(x, y)] -
                                                        static_cast<float>(r.frame.elevationOrigin));
        // Only mask pixels carry canopy, and no value exceeds the local maximum.
        ASSERT_NE(r.mask.tier.data[s.index(x, y)], 0U);
        EXPECT_LE(objectY, 20.0F + 1e-3F);
        // Deep inside each half the bare surroundings do not pull the height
        // down (mask-normalised), and the halves only mix near their seam.
        if (y > 60 && y < 180 && x > 40 && x < 135) EXPECT_NEAR(objectY, 10.0F, 1e-3F);
        if (y > 60 && y < 180 && x > 165 && x < 240) EXPECT_NEAR(objectY, 20.0F, 1e-3F);
        if (y > 60 && y < 180 && x >= 146 && x <= 153) EXPECT_TRUE(objectY > 10.0F && objectY < 20.0F);
        // The edge profile never exceeds 45 degrees from the 0.3 m edge lift.
        const double edge = std::min({column, row, s.width - column, s.height - row}) - 10.0;
        EXPECT_LE(objectY, s.config.canopyLiftMetres + std::max(0.0, edge) * 0.5 + 0.5 + 1e-3);
    }
}

// --- Coordinates and validity ----------------------------------------------

TEST(VegetationCanopyTest, RotatedNonSquareCoordinatesAndUvsFollowTheValidatedMapping)
{
    Scene s(90, 70, 0.5, -0.6);
    s.metadata.geoTransform = {500000.0, 0.48, 0.168, 2000000.0, 0.14, -0.576};
    s.surface.spatialMetadata = s.metadata;
    s.vegetation(5, 5, 85, 65, 7.0F);
    const auto r = s.run();
    ASSERT_FALSE(r.canopy.empty());
    const auto& p = r.canopy.primitive;
    for (std::size_t v = 0; v < p.positions.size() / 3; ++v)
    {
        const auto [column, row] = pixelOfUv(s, p, v);
        // Nodes sit on pixel centres.
        EXPECT_NEAR(column - std::floor(column), 0.5, 1e-4);
        EXPECT_NEAR(row - std::floor(row), 0.5, 1e-4);
        const LocalPoint local = geo::pixelEdgeToLocal(s.metadata, r.frame, column, row);
        EXPECT_NEAR(p.positions[v * 3], local.x, 1e-3);
        EXPECT_NEAR(p.positions[v * 3 + 2], local.z, 1e-3);
        const auto [u, v2] = geo::localToUv(s.metadata, r.frame, p.positions[v * 3], p.positions[v * 3 + 2]);
        EXPECT_NEAR((*p.uvs)[v * 2], u, 1e-5);
        EXPECT_NEAR((*p.uvs)[v * 2 + 1], v2, 1e-5);
    }
}

TEST(VegetationCanopyTest, GeometryIsValidFiniteUpwardAndNonDegenerate)
{
    Scene s(150, 130, 0.5, -0.5);
    s.vegetation(10, 10, 140, 120, 11.0F);
    fillRectangle(s.semantics.finalClassMap, 60, 0, 64, 130, SemanticClass::ROAD); // Splits the region
    const auto r = s.run();
    ASSERT_FALSE(r.canopy.empty());
    const auto& p = r.canopy.primitive;
    const std::size_t vertices = p.positions.size() / 3;
    ASSERT_EQ(p.normals->size(), p.positions.size());
    ASSERT_EQ(p.uvs->size(), vertices * 2);
    EXPECT_EQ(p.materialRole, MaterialRole::VEGETATION_CANOPY);
    EXPECT_FALSE(p.featureIds.has_value()); // Never pickable as a building
    EXPECT_FALSE(p.colors.has_value());     // No vertex colours over the texture
    for (float value : p.positions) ASSERT_TRUE(std::isfinite(value));
    for (float value : *p.uvs) ASSERT_TRUE(std::isfinite(value) && value >= 0.0F && value <= 1.0F);
    for (std::size_t v = 0; v < vertices; ++v)
    {
        const float* n = p.normals->data() + v * 3;
        EXPECT_NEAR(std::sqrt(n[0] * n[0] + n[1] * n[1] + n[2] * n[2]), 1.0F, 1e-4F);
        EXPECT_GT(n[1], 0.0F);
    }
    for (std::size_t t = 0; t + 2 < p.indices.size(); t += 3)
    {
        const uint32_t a = p.indices[t], b = p.indices[t + 1], c = p.indices[t + 2];
        ASSERT_TRUE(a < vertices && b < vertices && c < vertices);
        ASSERT_TRUE(a != b && b != c && a != c);
        const float ux = p.positions[b * 3] - p.positions[a * 3], uz = p.positions[b * 3 + 2] - p.positions[a * 3 + 2];
        const float vx = p.positions[c * 3] - p.positions[a * 3], vz = p.positions[c * 3 + 2] - p.positions[a * 3 + 2];
        const float upward = uz * vx - ux * vz; // Y of (b - a) x (c - a): consistent winding, faces up
        EXPECT_GT(upward, 1e-6F) << "triangle " << t / 3;
    }
    EXPECT_EQ(r.canopy.stats.triangles, p.indices.size() / 3);
}

TEST(VegetationCanopyTest, TriangleBudgetRaisesTheStrideDeterministically)
{
    Scene s(400, 400, 0.5, -0.5);
    s.vegetation(0, 0, 400, 400, 10.0F);
    s.config.canopyMaxTriangles = 5000;
    const auto first = s.run();
    const auto second = s.run();
    ASSERT_FALSE(first.canopy.empty());
    EXPECT_LE(first.canopy.stats.triangles, 5000U);
    EXPECT_GT(first.canopy.stats.stride, 1);
    EXPECT_TRUE(first.canopy.stats.budgetLimited);
    EXPECT_GT(first.canopy.stats.triangles, 1000U); // Reduced, not truncated
    EXPECT_EQ(first.canopy.primitive.positions, second.canopy.primitive.positions);
    EXPECT_EQ(first.canopy.primitive.indices, second.canopy.primitive.indices);
    // The full-resolution canopy would need far more.
    s.config.canopyMaxTriangles = 5000000;
    EXPECT_GT(s.run().canopy.stats.triangles, 300000U);
}

TEST(VegetationCanopyTest, NoDenseVegetationProducesNoCanopy)
{
    Scene s(200, 160, 0.5, -0.5);
    s.vegetation(120, 20, 132, 32, 9.0F); // Only an isolated crown
    const auto r = s.run();
    EXPECT_TRUE(r.canopy.empty());
    EXPECT_EQ(r.canopy.stats.skippedReason, "no dense vegetation");
}

TEST(VegetationCanopyTest, CanopyNeverDipsUnderADecimatedCurvedTerrain)
{
    // Curved terrain meshed at stride 4 (maxGridSize 40 on 120 px) under a
    // low 2 m canopy: canopy cells must coincide with terrain cells.
    Scene s(120, 100, 10.0, -10.0);
    for (int y = 0; y < s.height; ++y)
        for (int x = 0; x < s.width; ++x)
            s.surface.dtm.data[s.index(x, y)] = 1500.0F + 60.0F * std::sin(0.21F * x) * std::cos(0.17F * y);
    s.surface.dsm = s.surface.dtm;
    s.vegetation(0, 0, 120, 100, 2.0F);
    // A budget that alone would pick stride 3 against the terrain's 4: the
    // misaligned case (as on Test8) where flat canopy triangles cross creases.
    s.config.canopyMaxTriangles = 3000;
    TerrainMeshConfig terrain;
    terrain.maxGridSize = 40;
    const auto r = s.run(ScenePresentation::METRIC, 2.25F, terrain);
    ASSERT_FALSE(r.canopy.empty());
    const TerrainSurfaceSampler sampler(s.surface, s.metadata, r.frame, terrain);
    ASSERT_GT(sampler.stride(), 1); // TerrainMesher: (120 - 2) / 39 + 1 = 4
    EXPECT_TRUE(r.canopy.stats.terrainAligned);
    EXPECT_EQ(r.canopy.stats.stride % sampler.stride(), 0);
    const auto& p = r.canopy.primitive;
    std::size_t checked = 0;
    for (std::size_t t = 0; t + 2 < p.indices.size(); t += 3)
    {
        // Sample the triangle's interior (barycentric grid) against the terrain.
        for (const auto& [wa, wb] : std::vector<std::pair<double, double>>{{1 / 3., 1 / 3.}, {0.6, 0.2}, {0.2, 0.6}, {0.2, 0.2}, {0.45, 0.45}})
        {
            const double wc = 1.0 - wa - wb;
            double column = 0, row = 0, y = 0;
            const uint32_t idx[3] = {p.indices[t], p.indices[t + 1], p.indices[t + 2]};
            const double w[3] = {wa, wb, wc};
            for (int k = 0; k < 3; ++k)
            {
                column += w[k] * (*p.uvs)[idx[k] * 2] * s.width;
                row += w[k] * (*p.uvs)[idx[k] * 2 + 1] * s.height;
                y += w[k] * p.positions[idx[k] * 3 + 1];
            }
            // The outermost terrain cells run to the pixel edges; skip them.
            const double border = sampler.stride() + 0.5;
            if (column < border || row < border || column > s.width - border || row > s.height - border) continue;
            const auto ground = sampler.localHeight(column, row);
            ASSERT_TRUE(ground.has_value());
            ASSERT_GT(y - *ground, 1.0) << "triangle " << t / 3 << " at pixel " << column << "," << row;
            ++checked;
        }
    }
    EXPECT_GT(checked, 1000U);
}
