// Stage 4 of the vegetation overlay: deterministic individual-tree candidates
// (no geometry).

#include "BuildingReconstruction/BuildingReconstructionConfig.h"
#include "BuildingReconstructionTestSupport.h"
#include "MeshMapping/GeoTransformMapping.h"
#include "MeshMapping/LocalFrameTransformer.h"
#include "MeshMapping/TerrainSurfaceSampler.h"
#include "Vegetation/VegetationClassifier.h"
#include "Vegetation/VegetationExtractor.h"
#include "Vegetation/VegetationHeightSampler.h"
#include "Vegetation/VegetationTreeCandidateGenerator.h"
#include "Vegetation/VegetationTreeDiagnostics.h"

#include <gtest/gtest.h>

#include <algorithm>
#include <cmath>
#include <limits>
#include <random>

using namespace depthwizard::test;
namespace geo = depthwizard::geo;

namespace
{
struct Scene
{
    int width, height;
    SpatialMetadata metadata;
    SemanticScene semantics;
    GeoreferencedSurfaceBundle surface;
    RasterGrid<uint8_t> footprints;
    VegetationConfig config;
    TerrainMeshConfig terrain;

    Scene(int w, int h, double pixelX = 0.5, double pixelY = -0.5)
        : width(w), height(h), metadata(makeProjectedMetadata(w, h, pixelX, pixelY)),
          semantics(makeSemanticScene(w, h, SemanticClass::GROUND)), surface(makeSurface(w, h, 100.0F, 0.0F)),
          footprints(makeConstantGrid<uint8_t>(w, h, uint8_t{0}))
    {
        surface.spatialMetadata = metadata;
        semantics.groundProbability = makeConstantGrid(w, h, 0.9F);
        config.mode = VegetationMode::ON;
    }
    std::size_t index(int x, int y) const { return static_cast<std::size_t>(y) * width + x; }
    double spacingX() const { return geo::columnSpacing(metadata); }
    double spacingY() const { return geo::rowSpacing(metadata); }

    // A Gaussian crown: nDSM = height * exp(-d^2 / (2 sigma^2)), sigma = radius / 2,
    // labelled vegetation where it is at least 0.5 m.
    void crown(double cx, double cy, double radiusMetres, float heightMetres,
               SemanticClass cls = SemanticClass::VEGETATION, float probability = 0.9F)
    {
        const double sigma = radiusMetres / 2.0;
        for (int y = 0; y < height; ++y)
            for (int x = 0; x < width; ++x)
            {
                const double d = std::hypot((x + 0.5 - cx) * spacingX(), (y + 0.5 - cy) * spacingY());
                const float h = static_cast<float>(heightMetres * std::exp(-d * d / (2 * sigma * sigma)));
                if (h < 0.5F) continue;
                const std::size_t i = index(x, y);
                if (h <= surface.ndsm.data[i]) continue;
                surface.ndsm.data[i] = h;
                surface.dsm.data[i] = surface.dtm.data[i] + h;
                semantics.finalClassMap.data[i] = cls;
                semantics.vegetationProbability.data[i] = probability;
                semantics.groundProbability.data[i] = 0.05F;
            }
    }

    struct Run
    {
        VegetationMask mask;
        VegetationHeights heights;
        VegetationClassification classification;
        VegetationTreeCandidates trees;
        LocalSceneFrame frame;
    };
    Run run(ScenePresentation presentation = ScenePresentation::METRIC, float buildingScale = 2.25F) const
    {
        Run r;
        r.mask = VegetationExtractor::extract(semantics, surface, footprints, metadata, config);
        r.heights = VegetationHeightSampler::sample(r.mask, surface, config);
        r.classification = VegetationClassifier::classify(r.mask, config);
        r.frame = LocalFrameTransformer::create(metadata, surface);
        VegetationTreeInput input;
        input.mask = &r.mask;
        input.classification = &r.classification;
        input.heights = &r.heights;
        input.semantics = &semantics;
        input.surface = &surface;
        input.metadata = &metadata;
        input.frame = r.frame;
        input.terrainConfig = terrain;
        if (presentation == ScenePresentation::FLAT_URBAN)
            input.terrainConfig.elevationSource = TerrainElevationSource::FLAT_PRESENTATION;
        input.presentation = presentation;
        input.buildingDisplayHeightScale = buildingScale;
        input.config = config;
        r.trees = VegetationTreeCandidateGenerator::generate(input);
        return r;
    }
};

std::vector<const TreeCandidate*> ofCategory(const VegetationTreeCandidates& trees, TreeCandidateCategory category)
{
    std::vector<const TreeCandidate*> out;
    for (const auto& c : trees.candidates)
        if (c.category == category) out.push_back(&c);
    return out;
}
} // namespace

TEST(VegetationTreeCandidateTest, OneIsolatedCrownGivesOneCandidate)
{
    Scene s(100, 100);
    s.crown(50.0, 50.0, 4.0, 10.0F);
    const auto r = s.run();
    ASSERT_TRUE(r.trees.enabled) << r.trees.disabledReason;
    ASSERT_EQ(r.trees.candidates.size(), 1U);
    const TreeCandidate& c = r.trees.candidates[0];
    EXPECT_EQ(c.category, TreeCandidateCategory::ISOLATED_TREE);
    EXPECT_EQ(c.provenance, TreeProvenance::CONFIRMED);
    EXPECT_NEAR(c.pixelColumn, 50.0, 0.75);
    EXPECT_NEAR(c.pixelRow, 50.0, 0.75);
    EXPECT_GT(c.metricHeight, 8.5F);
    EXPECT_LE(c.metricHeight, 10.0F);
    EXPECT_GE(c.crownRadiusMetres, s.config.treeMinCrownRadiusMetres);
    EXPECT_LE(c.crownRadiusMetres, 5.0F);
    EXPECT_EQ(c.id, 1U);
    EXPECT_GT(c.confidence, 0.5F);
}

TEST(VegetationTreeCandidateTest, TwoSeparatedCrownsGiveTwoCandidates)
{
    Scene s(140, 100);
    s.crown(35.0, 50.0, 4.0, 10.0F);
    s.crown(105.0, 50.0, 4.0, 8.0F);
    const auto r = s.run();
    ASSERT_EQ(r.trees.candidates.size(), 2U);
    std::vector<double> columns{r.trees.candidates[0].pixelColumn, r.trees.candidates[1].pixelColumn};
    std::sort(columns.begin(), columns.end());
    EXPECT_NEAR(columns[0], 35.0, 0.75);
    EXPECT_NEAR(columns[1], 105.0, 0.75);
}

TEST(VegetationTreeCandidateTest, TwoOverlappingPeaksResolveDeterministically)
{
    Scene s(100, 100);
    s.crown(48.0, 50.0, 4.0, 10.0F);
    s.crown(52.0, 50.0, 4.0, 9.6F); // 2 m apart: one crown
    const auto first = s.run();
    const auto second = s.run();
    ASSERT_EQ(first.trees.candidates.size(), 1U);
    EXPECT_LT(first.trees.candidates[0].pixelColumn, 50.5); // The taller peak wins
    EXPECT_EQ(VegetationTreeDiagnostics::toJson(first.trees).toStyledString(),
              VegetationTreeDiagnostics::toJson(second.trees).toStyledString());
}

TEST(VegetationTreeCandidateTest, ABroadSmoothMoundDoesNotBecomeDozensOfTrees)
{
    // A 30 m x 30 m 8 m plateau with +-0.3 m deterministic ripple.
    Scene s(120, 120);
    std::mt19937 random(7);
    std::uniform_real_distribution<float> ripple(-0.3F, 0.3F);
    for (int y = 30; y < 90; ++y)
        for (int x = 30; x < 90; ++x)
        {
            const std::size_t i = s.index(x, y);
            s.semantics.finalClassMap.data[i] = SemanticClass::VEGETATION;
            s.semantics.vegetationProbability.data[i] = 0.9F;
            s.surface.ndsm.data[i] = 8.0F + ripple(random);
        }
    const auto r = s.run();
    EXPECT_LE(r.trees.candidates.size(), 10U);
    EXPECT_GT(r.trees.stats.count(TreeRejection::OVERLAP) + r.trees.stats.count(TreeRejection::PROMINENCE), 0U);
}

TEST(VegetationTreeCandidateTest, DenseFineCanopyYieldsConservativeCrownPeaks)
{
    // 70 m x 70 m canopy (8 m) with nine crowns 20 m apart rising to 13-15 m.
    Scene s(160, 160);
    for (int y = 10; y < 150; ++y)
        for (int x = 10; x < 150; ++x)
        {
            const std::size_t i = s.index(x, y);
            s.semantics.finalClassMap.data[i] = SemanticClass::VEGETATION;
            s.semantics.vegetationProbability.data[i] = 0.9F;
            s.surface.ndsm.data[i] = 8.0F;
        }
    for (int gy = 0; gy < 3; ++gy)
        for (int gx = 0; gx < 3; ++gx)
        {
            const double cx = 40 + 40 * gx, cy = 40 + 40 * gy;
            const double sigma = 2.5;
            for (int y = 10; y < 150; ++y)
                for (int x = 10; x < 150; ++x)
                {
                    const double d = std::hypot((x + 0.5 - cx) * 0.5, (y + 0.5 - cy) * 0.5);
                    const float rise = static_cast<float>((5.0 + gx + gy * 0.5) * std::exp(-d * d / (2 * sigma * sigma)));
                    s.surface.ndsm.data[s.index(x, y)] = std::max(s.surface.ndsm.data[s.index(x, y)], 8.0F + rise);
                }
        }
    const auto r = s.run();
    const auto crowns = ofCategory(r.trees, TreeCandidateCategory::DENSE_CANOPY_CROWN);
    EXPECT_GE(crowns.size(), 6U);
    EXPECT_LE(crowns.size(), 9U); // Never more than the real crowns
    EXPECT_TRUE(ofCategory(r.trees, TreeCandidateCategory::ISOLATED_TREE).empty());
    for (std::size_t a = 0; a < crowns.size(); ++a)
        for (std::size_t b = a + 1; b < crowns.size(); ++b)
            EXPECT_GE(std::hypot((crowns[a]->pixelColumn - crowns[b]->pixelColumn) * 0.5,
                                 (crowns[a]->pixelRow - crowns[b]->pixelRow) * 0.5),
                      s.config.denseCrownMinSpacingMetres);
    for (const TreeCandidate* c : crowns)
    {
        EXPECT_GE(c->confidence, s.config.denseCrownMinConfidence);
        EXPECT_GE(c->prominenceMetres, s.config.denseCrownMinProminenceMetres);
        // The crown top is the measured nDSM peak (not canopy + tree).
        EXPECT_LE(c->metricHeight, 15.0F + 1e-3F);
        EXPECT_GT(c->metricHeight, 11.0F);
    }
}

TEST(VegetationTreeCandidateTest, CoarseImageryProducesNoIndividualCandidates)
{
    Scene s(60, 60, 10.0, -10.0);
    s.crown(30.0, 30.0, 40.0, 12.0F);
    const auto r = s.run();
    EXPECT_FALSE(r.trees.enabled);
    EXPECT_TRUE(r.trees.candidates.empty());
    EXPECT_NE(r.trees.disabledReason.find("exceeds DEPTHWIZARD_VEGETATION_INDIVIDUAL_TREE_MAX_GSD_M"), std::string::npos);
    // Anisotropic: the coarser axis decides.
    Scene a(100, 100, 0.5, -1.5);
    a.crown(50.0, 50.0, 6.0, 10.0F);
    EXPECT_FALSE(a.run().trees.enabled);
    Scene n(100, 100);
    n.metadata.isGeoreferenced = false;
    n.crown(50.0, 50.0, 4.0, 10.0F);
    const auto nr = n.run();
    EXPECT_FALSE(nr.trees.enabled);
    EXPECT_NE(nr.trees.disabledReason.find("not georeferenced"), std::string::npos);
}

TEST(VegetationTreeCandidateTest, NeverInsideBuildingsRoadsWaterOrNoDataAndCrownsClearTheBuffer)
{
    Scene s(200, 160);
    // Crowns everywhere, some overlapping a building, a road and a pond.
    for (int k = 0; k < 6; ++k)
        for (int j = 0; j < 4; ++j) s.crown(20 + 32 * k, 20 + 38 * j, 3.5, 9.0F);
    fillRectangle(s.footprints, 50, 45, 90, 80, uint8_t{1});
    fillRectangle(s.semantics.finalClassMap, 50, 45, 90, 80, SemanticClass::BUILDING);
    fillRectangle(s.semantics.finalClassMap, 0, 110, 200, 118, SemanticClass::ROAD);
    fillRectangle(s.semantics.roadProbability, 0, 110, 200, 118, 0.9F);
    fillRectangle(s.semantics.finalClassMap, 140, 10, 175, 40, SemanticClass::WATER);
    fillRectangle(s.semantics.waterProbability, 140, 10, 175, 40, 0.9F);
    for (int x = 0; x < 200; ++x) s.surface.ndsm.data[s.index(x, 95)] = std::numeric_limits<float>::quiet_NaN();
    const auto r = s.run();
    ASSERT_FALSE(r.trees.candidates.empty());
    for (const TreeCandidate& c : r.trees.candidates)
    {
        const int cx = static_cast<int>(c.pixelColumn), cy = static_cast<int>(c.pixelRow);
        ASSERT_EQ(r.mask.barrierMask.data[s.index(cx, cy)], 0U) << "candidate " << c.id;
        const auto cls = s.semantics.finalClassMap.data[s.index(cx, cy)];
        ASSERT_TRUE(cls != SemanticClass::ROAD && cls != SemanticClass::WATER && cls != SemanticClass::BUILDING);
        // The whole crown disc stays off buffered building pixels.
        for (int y = 0; y < s.height; ++y)
            for (int x = 0; x < s.width; ++x)
                if (std::hypot((x + 0.5 - c.pixelColumn) * 0.5, (y + 0.5 - c.pixelRow) * 0.5) < c.crownRadiusMetres)
                    ASSERT_EQ(r.mask.protectedMask.data[s.index(x, y)], 0U)
                        << "crown " << c.id << " reaches the buffer at " << x << "," << y;
        EXPECT_LE(c.crownRadiusMetres, c.clearanceMetres + 1e-4F);
    }
}

TEST(VegetationTreeCandidateTest, BaseComesFromTheRenderedTerrainSurface)
{
    Scene s(120, 100);
    for (int y = 0; y < s.height; ++y)
        for (int x = 0; x < s.width; ++x)
            s.surface.dtm.data[s.index(x, y)] = 900.0F + 15.0F * std::sin(0.11F * x) * std::cos(0.07F * y);
    s.surface.dsm = s.surface.dtm;
    s.terrain.maxGridSize = 30; // Decimated terrain: the sampler, not a raw DTM pixel, defines the ground
    s.crown(40.0, 40.0, 4.0, 10.0F);
    s.crown(85.0, 60.0, 4.0, 9.0F);
    const auto r = s.run();
    ASSERT_EQ(r.trees.candidates.size(), 2U);
    const TerrainSurfaceSampler sampler(s.surface, s.metadata, r.frame, s.terrain);
    EXPECT_GT(sampler.stride(), 1);
    for (const TreeCandidate& c : r.trees.candidates)
    {
        const auto ground = sampler.localHeight(c.pixelColumn, c.pixelRow);
        ASSERT_TRUE(ground.has_value());
        EXPECT_FLOAT_EQ(c.baseY, *ground);
        EXPECT_FLOAT_EQ(c.topY, c.baseY + c.displayHeight);
    }
    EXPECT_EQ(r.trees.baseSource, "DTM");
}

TEST(VegetationTreeCandidateTest, HeightIsTheNdsmNeverRawDsm)
{
    Scene s(100, 100);
    for (std::size_t i = 0; i < s.surface.dtm.data.size(); ++i) s.surface.dtm.data[i] = 2500.0F;
    s.crown(50.0, 50.0, 4.0, 10.0F); // dsm ~ 2510
    const auto r = s.run();
    ASSERT_EQ(r.trees.candidates.size(), 1U);
    EXPECT_LE(r.trees.candidates[0].metricHeight, 10.0F);
    EXPECT_GT(r.trees.candidates[0].metricHeight, 8.5F);
    EXPECT_GT(s.surface.dsm.data[s.index(50, 50)], 2500.0F);
}

TEST(VegetationTreeCandidateTest, MetricAndFlatUrbanDisplayScales)
{
    Scene s(100, 100);
    s.crown(50.0, 50.0, 4.0, 10.0F);
    const float buildingScale = BuildingReconstructionConfig{}.heightScaleMultiplier;
    const auto metric = s.run(ScenePresentation::METRIC, buildingScale);
    const auto flat = s.run(ScenePresentation::FLAT_URBAN, buildingScale);
    ASSERT_EQ(metric.trees.candidates.size(), 1U);
    ASSERT_EQ(flat.trees.candidates.size(), 1U);
    const TreeCandidate& m = metric.trees.candidates[0];
    const TreeCandidate& f = flat.trees.candidates[0];
    EXPECT_FLOAT_EQ(m.displayScale, 1.0F);
    EXPECT_FLOAT_EQ(m.displayHeight, m.metricHeight);
    EXPECT_FLOAT_EQ(f.displayScale, buildingScale);
    EXPECT_FLOAT_EQ(f.metricHeight, m.metricHeight); // The measurement never changes
    EXPECT_FLOAT_EQ(f.displayHeight, f.metricHeight * buildingScale);
    EXPECT_FLOAT_EQ(f.baseY, 0.0F);
    EXPECT_FLOAT_EQ(f.topY, f.displayHeight);
    EXPECT_EQ(flat.trees.baseSource, "FLAT_URBAN_GROUND");
    EXPECT_EQ(flat.trees.presentationMode, "flat_urban");
}

TEST(VegetationTreeCandidateTest, RotatedNonSquarePositionsFollowTheValidatedMapping)
{
    Scene s(110, 90, 0.5, -0.6);
    s.metadata.geoTransform = {500000.0, 0.48, 0.168, 2000000.0, 0.14, -0.576};
    s.surface.spatialMetadata = s.metadata;
    s.crown(55.0, 45.0, 4.0, 10.0F);
    const auto r = s.run();
    ASSERT_EQ(r.trees.candidates.size(), 1U);
    const TreeCandidate& c = r.trees.candidates[0];
    EXPECT_NEAR(c.pixelColumn, 55.0, 0.75);
    EXPECT_NEAR(c.pixelRow, 45.0, 0.75);
    const LocalPoint local = geo::pixelEdgeToLocal(s.metadata, r.frame, c.pixelColumn, c.pixelRow);
    EXPECT_DOUBLE_EQ(c.worldX, local.x);
    EXPECT_DOUBLE_EQ(c.worldZ, local.z);
    const auto [column, row] = geo::localToPixelEdge(s.metadata, r.frame, c.worldX, c.worldZ);
    EXPECT_NEAR(column, c.pixelColumn, 1e-9);
    EXPECT_NEAR(row, c.pixelRow, 1e-9);
}

TEST(VegetationTreeCandidateTest, TheLimitKeepsTheHighestConfidenceCandidates)
{
    Scene s(240, 100);
    for (int k = 0; k < 6; ++k) s.crown(20 + 40 * k, 50.0, 3.0 + 0.4 * k, 6.0F + k);
    const auto all = s.run();
    ASSERT_EQ(all.trees.candidates.size(), 6U);
    s.config.maxInstances = 3;
    const auto limited = s.run();
    ASSERT_EQ(limited.trees.candidates.size(), 3U);
    EXPECT_EQ(limited.trees.stats.count(TreeRejection::LIMIT), 3U);
    for (std::size_t k = 0; k < 3; ++k)
    {
        EXPECT_EQ(limited.trees.candidates[k].peakColumn, all.trees.candidates[k].peakColumn);
        EXPECT_FLOAT_EQ(limited.trees.candidates[k].confidence, all.trees.candidates[k].confidence);
    }
    for (std::size_t k = 1; k < all.trees.candidates.size(); ++k)
        EXPECT_GE(all.trees.candidates[k - 1].confidence, all.trees.candidates[k].confidence);
}

TEST(VegetationTreeCandidateTest, SameInputGivesByteIdenticalCandidateJson)
{
    Scene s(200, 160);
    for (int k = 0; k < 5; ++k) s.crown(25 + 36 * k, 40 + 15 * (k % 3), 3.0 + 0.3 * k, 7.0F + 0.5F * k);
    const auto first = s.run();
    const auto second = s.run();
    s.config.seed = 4242; // Positions and heights do not depend on the seed
    const auto reseeded = s.run();
    const std::string json = VegetationTreeDiagnostics::toJson(first.trees).toStyledString();
    EXPECT_EQ(json, VegetationTreeDiagnostics::toJson(second.trees).toStyledString());
    EXPECT_EQ(json, VegetationTreeDiagnostics::toJson(reseeded.trees).toStyledString());
    EXPECT_EQ(first.trees.crownLabels.data, second.trees.crownLabels.data);
}

TEST(VegetationTreeCandidateTest, RankingIsIndependentOfInsertionOrder)
{
    Scene s(240, 100);
    for (int k = 0; k < 6; ++k) s.crown(20 + 40 * k, 50.0, 3.0 + 0.4 * k, 6.0F + k);
    const auto r = s.run();
    std::vector<TreeCandidate> shuffled = r.trees.candidates;
    std::mt19937 random(99);
    for (int attempt = 0; attempt < 5; ++attempt)
    {
        std::shuffle(shuffled.begin(), shuffled.end(), random);
        const auto ranked = VegetationTreeCandidateGenerator::rankAndLimit(shuffled, 4);
        ASSERT_EQ(ranked.size(), 4U);
        for (std::size_t k = 0; k < 4; ++k)
        {
            EXPECT_EQ(ranked[k].peakColumn, r.trees.candidates[k].peakColumn);
            EXPECT_EQ(ranked[k].peakRow, r.trees.candidates[k].peakRow);
        }
    }
}

TEST(VegetationTreeCandidateTest, SinglePixelSpikesAreRejected)
{
    Scene s(100, 100);
    // Low vegetation with one implausible 9 m pixel.
    fillRectangle(s.semantics.finalClassMap, 30, 30, 50, 50, SemanticClass::VEGETATION);
    fillRectangle(s.semantics.vegetationProbability, 30, 30, 50, 50, 0.9F);
    fillRectangle(s.surface.ndsm, 30, 30, 50, 50, 1.6F);
    s.surface.ndsm.data[s.index(40, 40)] = 9.0F;
    // Default: the stage-2 robust ceiling already clamps the lone spike.
    const auto clamped = s.run();
    for (const TreeCandidate& c : clamped.trees.candidates) EXPECT_LT(c.metricHeight, 3.0F);
    // Without that clamp the tree rule itself rejects it.
    s.config.heightClampPercentile = 1.0F;
    const auto raw = s.run();
    for (const TreeCandidate& c : raw.trees.candidates) EXPECT_LT(c.metricHeight, 3.0F);
    EXPECT_GE(raw.trees.stats.count(TreeRejection::SPIKE), 1U);
}

TEST(VegetationTreeCandidateTest, ExperimentalLowConfidenceRecoveryIsOptInAndGated)
{
    Scene s(140, 100);
    s.crown(40.0, 50.0, 4.0, 9.0F, SemanticClass::UNKNOWN, 0.40F); // Below the stage-2 threshold
    s.crown(100.0, 50.0, 4.0, 9.0F, SemanticClass::UNKNOWN, 0.40F);
    // The second one sits on building evidence.
    for (int y = 0; y < s.height; ++y)
        for (int x = 80; x < 120; ++x) s.semantics.buildingProbability.data[s.index(x, y)] = 0.5F;
    const auto off = s.run();
    EXPECT_TRUE(off.trees.candidates.empty());
    s.config.treeRecoverLowConfidence = true;
    s.config.treeRecoveryMinConfidence = 0.4F;
    const auto on = s.run();
    ASSERT_EQ(on.trees.candidates.size(), 1U);
    EXPECT_EQ(on.trees.candidates[0].provenance, TreeProvenance::EXPERIMENTAL);
    EXPECT_NEAR(on.trees.candidates[0].pixelColumn, 40.0, 0.75);
    EXPECT_EQ(on.trees.stats.experimentalCandidates, 1U);
}
