// Stage 5 of the vegetation overlay: tree prototypes, instance transforms,
// variants, chunking and determinism (GLB packaging is covered in the
// integration suites).

#include "Vegetation/VegetationTreeInstancer.h"
#include "Vegetation/VegetationTreePackaging.h"
#include "Vegetation/VegetationTreePrototypes.h"

#include <gtest/gtest.h>

#include <cmath>
#include <map>
#include <set>

namespace
{
TreeCandidate candidate(uint32_t id, TreeCandidateCategory category, double x, double z, float baseY, float metric,
                        float displayScale, float radius, float support = 0.9F, float compactness = 0.9F)
{
    TreeCandidate c;
    c.id = id;
    c.category = category;
    c.worldX = x;
    c.worldZ = z;
    c.baseY = baseY;
    c.metricHeight = metric;
    c.displayScale = displayScale;
    c.displayHeight = metric * displayScale;
    c.topY = baseY + c.displayHeight;
    c.crownRadiusMetres = radius;
    c.vegetationSupport = support;
    c.compactness = compactness;
    return c;
}

VegetationTreeCandidates candidates(std::vector<TreeCandidate> list)
{
    VegetationTreeCandidates result;
    result.enabled = true;
    result.candidates = std::move(list);
    return result;
}

LocalSceneFrame frame()
{
    LocalSceneFrame f;
    f.projectedOriginX = 585300.0;
    f.projectedOriginY = 4510800.0;
    return f;
}

VegetationConfig config()
{
    VegetationConfig c;
    c.mode = VegetationMode::ON;
    return c;
}
} // namespace

TEST(TreePrototypeTest, EveryPrototypeIsNormalisedValidAndLowPoly)
{
    const auto& provider = ProceduralTreePrototypeProvider::instance();
    for (int v = 0; v < kTreeVariantCount; ++v)
        for (int l = 0; l < 3; ++l)
        {
            const TreePrototype& p = provider.prototype(static_cast<TreeVisualVariant>(v), static_cast<TreeLod>(l));
            SCOPED_TRACE(p.name());
            float minY = 1e9F, maxY = -1e9F, radius = 0.0F;
            for (const TreePrototypePart* part : {&p.trunk, &p.crown})
            {
                ASSERT_EQ(part->positions.size(), part->normals.size());
                const std::size_t vertices = part->positions.size() / 3;
                for (std::size_t i = 0; i < vertices; ++i)
                {
                    const float* q = &part->positions[i * 3];
                    const float* n = &part->normals[i * 3];
                    ASSERT_TRUE(std::isfinite(q[0]) && std::isfinite(q[1]) && std::isfinite(q[2]));
                    ASSERT_NEAR(std::sqrt(n[0] * n[0] + n[1] * n[1] + n[2] * n[2]), 1.0F, 1e-4F);
                    minY = std::min(minY, q[1]);
                    maxY = std::max(maxY, q[1]);
                    if (part == &p.crown) radius = std::max(radius, std::hypot(q[0], q[2]));
                }
                for (std::size_t t = 0; t + 2 < part->indices.size(); t += 3)
                {
                    const uint32_t a = part->indices[t], b = part->indices[t + 1], c = part->indices[t + 2];
                    ASSERT_TRUE(a < vertices && b < vertices && c < vertices);
                    const float* pa = &part->positions[a * 3];
                    const float* pb = &part->positions[b * 3];
                    const float* pc = &part->positions[c * 3];
                    const double ux = pb[0] - pa[0], uy = pb[1] - pa[1], uz = pb[2] - pa[2];
                    const double vx = pc[0] - pa[0], vy = pc[1] - pa[1], vz = pc[2] - pa[2];
                    const double area = std::sqrt(std::pow(uy * vz - uz * vy, 2) + std::pow(uz * vx - ux * vz, 2) +
                                                  std::pow(ux * vy - uy * vx, 2));
                    ASSERT_GT(area, 1e-9) << "degenerate triangle " << t / 3;
                }
            }
            EXPECT_FLOAT_EQ(minY, 0.0F);   // Base on the ground point
            EXPECT_FLOAT_EQ(maxY, 1.0F);   // Top at displayHeight
            EXPECT_NEAR(radius, 1.0F, 1e-5F);
            const std::size_t triangles = p.triangles();
            if (l == 0) { EXPECT_GE(triangles, 100U); EXPECT_LE(triangles, 500U); }
            if (l == 1) { EXPECT_GE(triangles, 20U); EXPECT_LE(triangles, 100U); }
            if (l == 2) { EXPECT_LE(triangles, 30U); }
        }
    // The canopy-crown profile keeps its crown in the upper part.
    const TreePrototype& crown = provider.prototype(TreeVisualVariant::CANOPY_CROWN, TreeLod::NEAR);
    float crownBottom = 1.0F;
    for (std::size_t i = 1; i < crown.crown.positions.size(); i += 3) crownBottom = std::min(crownBottom, crown.crown.positions[i]);
    EXPECT_GT(crownBottom, 0.5F);
}

TEST(TreeInstancerTest, TransformsKeepPositionBaseTopAndCrownRadius)
{
    const auto trees = VegetationTreeInstancer::build(
        candidates({candidate(1, TreeCandidateCategory::ISOLATED_TREE, 12.5, -40.25, 3.5F, 9.0F, 1.0F, 3.2F)}),
        frame(), config(), 650.0);
    ASSERT_EQ(trees.instances.size(), 1U);
    const TreeInstance& i = trees.instances[0];
    EXPECT_FLOAT_EQ(i.translation[0], 12.5F);
    EXPECT_FLOAT_EQ(i.translation[1], 3.5F);    // Base at the candidate's ground
    EXPECT_FLOAT_EQ(i.translation[2], -40.25F);
    EXPECT_FLOAT_EQ(i.translation[1] + i.scale[1] * 1.0F, 3.5F + 9.0F);   // Prototype top Y = 1
    EXPECT_LE(i.scale[0], 3.2F);
    EXPECT_GE(i.scale[0], 0.9F * 3.2F);
    EXPECT_FLOAT_EQ(i.scale[0], i.scale[2]);
    const auto& q = i.rotation;
    EXPECT_NEAR(q[0] * q[0] + q[1] * q[1] + q[2] * q[2] + q[3] * q[3], 1.0F, 1e-6F);
    EXPECT_FLOAT_EQ(q[0], 0.0F); // Yaw only: the tree stays upright
    EXPECT_FLOAT_EQ(q[2], 0.0F);
}

TEST(TreeInstancerTest, DisplayScaleFollowsThePresentationAndMetadataStaysMetric)
{
    const auto metric = VegetationTreeInstancer::build(
        candidates({candidate(1, TreeCandidateCategory::ISOLATED_TREE, 0, 0, 0.0F, 8.0F, 1.0F, 3.0F)}), frame(), config(), 500.0);
    const auto flat = VegetationTreeInstancer::build(
        candidates({candidate(1, TreeCandidateCategory::ISOLATED_TREE, 0, 0, 0.0F, 8.0F, 2.25F, 3.0F)}), frame(), config(), 500.0);
    EXPECT_FLOAT_EQ(metric.instances[0].scale[1], 8.0F);
    EXPECT_FLOAT_EQ(flat.instances[0].scale[1], 18.0F);
    EXPECT_FLOAT_EQ(flat.instances[0].metricHeight, 8.0F);
    EXPECT_FLOAT_EQ(flat.instances[0].displayHeight, 18.0F);
    EXPECT_FLOAT_EQ(flat.instances[0].scale[0], metric.instances[0].scale[0]); // Horizontal stays metric
}

TEST(TreeInstancerTest, CanopyCrownsAreGroundedAndTopAtTheMeasuredPeak)
{
    // Terrain base 4 m, measured crown top 4 + 14 x 2.25; the canopy surface
    // (wherever it is) is never added.
    const TreeCandidate dense = candidate(7, TreeCandidateCategory::DENSE_CANOPY_CROWN, 30, 30, 4.0F, 14.0F, 2.25F, 7.0F);
    const auto trees = VegetationTreeInstancer::build(candidates({dense}), frame(), config(), 650.0);
    const TreeInstance& i = trees.instances[0];
    EXPECT_EQ(i.variant, TreeVisualVariant::CANOPY_CROWN);
    EXPECT_FLOAT_EQ(i.translation[1], 4.0F);
    EXPECT_FLOAT_EQ(i.translation[1] + i.scale[1], dense.topY);
    // Canopy crowns have no far level (the canopy stays as the envelope).
    for (const TreeBatch& b : trees.batches) EXPECT_NE(b.lod, TreeLod::FAR);
}

TEST(TreeInstancerTest, VariantsComeFromMeasuredGeometryOnly)
{
    std::string reason;
    EXPECT_EQ(VegetationTreeInstancer::selectVariant(candidate(1, TreeCandidateCategory::ISOLATED_TREE, 0, 0, 0, 2.0F, 1, 2.0F), &reason),
              TreeVisualVariant::SHRUB);
    EXPECT_NE(reason.find("low"), std::string::npos);
    EXPECT_EQ(VegetationTreeInstancer::selectVariant(candidate(2, TreeCandidateCategory::ISOLATED_TREE, 0, 0, 0, 12.0F, 1, 2.5F)),
              TreeVisualVariant::TALL_NARROW);
    EXPECT_EQ(VegetationTreeInstancer::selectVariant(candidate(3, TreeCandidateCategory::ISOLATED_TREE, 0, 0, 0, 8.0F, 1, 4.0F, 0.6F)),
              TreeVisualVariant::DRY_SPARSE);
    EXPECT_EQ(VegetationTreeInstancer::selectVariant(candidate(4, TreeCandidateCategory::ISOLATED_TREE, 0, 0, 0, 8.0F, 1, 4.0F, 0.9F, 0.6F)),
              TreeVisualVariant::BROADLEAF_IRREGULAR);
    EXPECT_EQ(VegetationTreeInstancer::selectVariant(candidate(5, TreeCandidateCategory::ISOLATED_TREE, 0, 0, 0, 8.0F, 1, 4.0F)),
              TreeVisualVariant::BROADLEAF_ROUND);
}

TEST(TreeInstancerTest, CosmeticVariationIsDeterministicAndNeverMovesTrees)
{
    std::vector<TreeCandidate> list;
    for (uint32_t k = 1; k <= 40; ++k)
        list.push_back(candidate(k, k % 3 ? TreeCandidateCategory::ISOLATED_TREE : TreeCandidateCategory::DENSE_CANOPY_CROWN,
                                 -300.0 + 15.0 * k, 100.0 - 7.0 * k, 1.0F, 5.0F + k * 0.1F, 1.0F, 2.0F + 0.05F * k));
    const auto a = VegetationTreeInstancer::build(candidates(list), frame(), config(), 650.0);
    const auto b = VegetationTreeInstancer::build(candidates(list), frame(), config(), 650.0);
    VegetationConfig reseeded = config();
    reseeded.seed = 99;
    const auto c = VegetationTreeInstancer::build(candidates(list), frame(), reseeded, 650.0);
    bool rotationChanged = false;
    for (std::size_t k = 0; k < a.instances.size(); ++k)
    {
        EXPECT_EQ(a.instances[k].rotation, b.instances[k].rotation);
        EXPECT_EQ(a.instances[k].scale, b.instances[k].scale);
        EXPECT_EQ(a.instances[k].colourTint, b.instances[k].colourTint);
        // A new seed changes only cosmetic values, never position or total height.
        EXPECT_EQ(a.instances[k].translation, c.instances[k].translation);
        EXPECT_FLOAT_EQ(a.instances[k].scale[1], c.instances[k].scale[1]);
        rotationChanged = rotationChanged || a.instances[k].rotation != c.instances[k].rotation;
    }
    EXPECT_TRUE(rotationChanged);
    const auto packageA = VegetationTreePackaging::package(a, ProceduralTreePrototypeProvider::instance(), 1337);
    const auto packageB = VegetationTreePackaging::package(b, ProceduralTreePrototypeProvider::instance(), 1337);
    ASSERT_EQ(packageA.nodes.size(), packageB.nodes.size());
    for (std::size_t n = 0; n < packageA.nodes.size(); ++n)
    {
        EXPECT_EQ(packageA.nodes[n].name, packageB.nodes[n].name);
        EXPECT_EQ(packageA.nodes[n].translations, packageB.nodes[n].translations);
        EXPECT_EQ(packageA.nodes[n].rotations, packageB.nodes[n].rotations);
    }
}

TEST(TreeInstancerTest, ChunksAreStableCompleteAndBounded)
{
    std::vector<TreeCandidate> list;
    for (uint32_t k = 1; k <= 300; ++k)
        list.push_back(candidate(k, TreeCandidateCategory::ISOLATED_TREE, -500.0 + (k * 37 % 1000), -400.0 + (k * 53 % 800),
                                 0.5F, 6.0F, 1.0F, 2.5F));
    VegetationConfig c = config();
    c.treeChunkSizeMetres = 150.0F;
    const LocalSceneFrame f = frame();
    const auto trees = VegetationTreeInstancer::build(candidates(list), f, c, 1000.0);
    EXPECT_DOUBLE_EQ(trees.chunkSizeMetres, 150.0);
    for (const TreeInstance& i : trees.instances)
    {
        EXPECT_EQ(i.chunkX, static_cast<int>(std::floor((i.translation[0] + f.projectedOriginX) / 150.0)));
        EXPECT_EQ(i.chunkZ, static_cast<int>(std::floor((f.projectedOriginY - i.translation[2]) / 150.0)));
    }
    // Every candidate exactly once per level of detail; bounds contain its crown.
    std::map<TreeLod, std::multiset<uint32_t>> seen;
    for (const TreeBatch& b : trees.batches)
        for (std::size_t k : b.instances)
        {
            const TreeInstance& i = trees.instances[k];
            seen[b.lod].insert(i.candidateId);
            EXPECT_EQ(i.chunkIndex, b.chunkIndex);
            EXPECT_LE(b.boundsMin[0], i.translation[0] - i.scale[0] + 1e-6);
            EXPECT_GE(b.boundsMax[0], i.translation[0] + i.scale[0] - 1e-6);
            EXPECT_LE(b.boundsMin[1], i.translation[1] + 1e-6);
            EXPECT_GE(b.boundsMax[1], i.translation[1] + i.scale[1] - 1e-6);
        }
    for (TreeLod lod : {TreeLod::NEAR, TreeLod::MEDIUM, TreeLod::FAR})
    {
        ASSERT_EQ(seen[lod].size(), list.size()) << toString(lod);
        EXPECT_EQ(std::set<uint32_t>(seen[lod].begin(), seen[lod].end()).size(), list.size());
    }
    // Bounded: at most chunks x variants x levels.
    EXPECT_LE(trees.batches.size(), trees.chunks * kTreeVariantCount * 3);
    // Automatic chunk size: a quarter of the scene extent, clamped to 100-250 m.
    EXPECT_DOUBLE_EQ(VegetationTreeInstancer::chunkSize(config(), 650.0), 162.5);
    EXPECT_DOUBLE_EQ(VegetationTreeInstancer::chunkSize(config(), 200.0), 100.0);
    EXPECT_DOUBLE_EQ(VegetationTreeInstancer::chunkSize(config(), 12600.0), 250.0);
    // LOD off: near batches only.
    c.treeLod = false;
    for (const TreeBatch& b : VegetationTreeInstancer::build(candidates(list), f, c, 1000.0).batches)
        EXPECT_EQ(b.lod, TreeLod::NEAR);
}

TEST(TreeInstancerTest, AridScenesUseMutedPalettes)
{
    std::vector<TreeCandidate> desert, park;
    for (uint32_t k = 1; k <= 10; ++k)
    {
        desert.push_back(candidate(k, TreeCandidateCategory::ISOLATED_TREE, k * 10.0, 0, 0, 2.2F, 1.0F, 1.8F));
        park.push_back(candidate(k, TreeCandidateCategory::ISOLATED_TREE, k * 10.0, 0, 0, 9.0F, 1.0F, 4.0F));
    }
    EXPECT_EQ(VegetationTreeInstancer::build(candidates(desert), frame(), config(), 500.0).paletteFamily, "arid");
    EXPECT_EQ(VegetationTreeInstancer::build(candidates(park), frame(), config(), 500.0).paletteFamily, "temperate");
    // An urban park: a few short isolated shrubs beside a tall canopy is not scrubland.
    std::vector<TreeCandidate> urbanPark;
    for (uint32_t k = 1; k <= 10; ++k)
        urbanPark.push_back(k <= 3 ? candidate(k, TreeCandidateCategory::ISOLATED_TREE, k * 10.0, 0, 0, 2.2F, 1.0F, 1.8F)
                                   : candidate(k, TreeCandidateCategory::DENSE_CANOPY_CROWN, k * 10.0, 0, 0, 12.0F, 1.0F, 6.0F));
    EXPECT_EQ(VegetationTreeInstancer::build(candidates(urbanPark), frame(), config(), 500.0).paletteFamily, "temperate");
    // Muted: arid crowns are less saturated than temperate ones.
    const auto saturation = [](const std::array<double, 3>& c)
    { return (std::max({c[0], c[1], c[2]}) - std::min({c[0], c[1], c[2]})) / std::max({c[0], c[1], c[2]}); };
    EXPECT_LT(saturation(VegetationTreePackaging::crownColour("arid", TreeVisualVariant::BROADLEAF_ROUND)),
              saturation(VegetationTreePackaging::crownColour("temperate", TreeVisualVariant::BROADLEAF_ROUND)));
}

TEST(TreeInstancerTest, NoCandidatesMeansNoBatches)
{
    const auto trees = VegetationTreeInstancer::build(candidates({}), frame(), config(), 500.0);
    EXPECT_TRUE(trees.empty());
    EXPECT_TRUE(trees.batches.empty());
    EXPECT_TRUE(VegetationTreePackaging::package(trees, ProceduralTreePrototypeProvider::instance(), 1).empty());
}
