#include <gtest/gtest.h>
#include "MeshMapping/ScenePresentationPolicy.h"
#include "MeshMapping/ScenePresentationSelector.h"

#include <cstdlib>
#include <optional>
#include <string>
#include "BuildingReconstructionTestSupport.h"

using namespace depthwizard::test;

namespace {
SemanticScene city(int n)
{
    auto s = makeSemanticScene(n, n, SemanticClass::ROAD);
    s.roadProbability = makeConstantGrid(n, n, .9F);
    for (int y = 0; y < n; ++y)
        for (int x = 0; x < n; x += 4) {
            const int i = y*n+x;
            s.finalClassMap.data[i] = SemanticClass::BUILDING;
            s.buildingProbability.data[i] = .95F;
            s.roadProbability.data[i] = 0;
        }
    return s;
}
BuildingCollection objects() { BuildingCollection b; b.buildings.resize(10); return b; }
}

TEST(ScenePresentationSelectorTest, DistributedUrbanBuildingsSelectFlatAutomatically)
{
    const auto result = ScenePresentationSelector::select(city(32), makeSurface(32, 32, 100, 10), objects());
    EXPECT_EQ(result.presentation, ScenePresentation::FLAT_URBAN);
    EXPECT_DOUBLE_EQ(result.strongBuildingFraction, .25);
    EXPECT_EQ(result.buildingQuadrants, 4);
    EXPECT_FALSE(result.reason.empty());
}

TEST(ScenePresentationSelectorTest, CityReferenceContaminationDoesNotForcePedestal)
{
    auto surface = makeSurface(32, 32, 3, 10);
    for (int y=0; y<32; ++y)
        for (int x=0; x<32; ++x) surface.dtm.data[y*32+x] += x * 1.5F;
    const auto result = ScenePresentationSelector::select(city(32), surface, objects());
    EXPECT_EQ(result.presentation, ScenePresentation::FLAT_URBAN);
    EXPECT_GT(result.groundReliefMetres, 30);
}

TEST(ScenePresentationSelectorTest, ForestAndMajorReliefRetainTerrain)
{
    auto s = city(32);
    auto surface = makeSurface(32, 32, 100, 10);
    s.vegetationProbability = makeConstantGrid(32, 32, .9F);
    EXPECT_EQ(ScenePresentationSelector::select(s, surface, objects()).presentation, ScenePresentation::METRIC);
    s.vegetationProbability.data.assign(32*32, 0);
    for (int y=0; y<32; ++y)
        for (int x=0; x<32; ++x) surface.dtm.data[y*32+x] += x * 10.0F;
    EXPECT_EQ(ScenePresentationSelector::select(s, surface, objects()).presentation, ScenePresentation::METRIC);
}

TEST(ScenePresentationSelectorTest, LocalizedBuildingsAndNoDataCannotFlattenScene)
{
    auto s = makeSemanticScene(32, 32);
    fillRectangle(s.finalClassMap, 0, 0, 14, 14, SemanticClass::BUILDING);
    fillRectangle(s.buildingProbability, 0, 0, 14, 14, .95F);
    auto surface = makeSurface(32, 32, 100, 10);
    EXPECT_EQ(ScenePresentationSelector::select(s, surface, objects()).presentation, ScenePresentation::METRIC);
    surface.validMask.data.assign(32*32, 0);
    EXPECT_EQ(ScenePresentationSelector::select(city(32), surface, objects()).presentation, ScenePresentation::METRIC);
    surface.dtm.width = 1;
    EXPECT_THROW(ScenePresentationSelector::select(s, surface, objects()), std::invalid_argument);
}

// --- Automatic urban-versus-natural presentation (DEPTHWIZARD_PRESENTATION) ---

namespace {
SemanticScene forest(int n)
{
    auto s = makeSemanticScene(n, n, SemanticClass::VEGETATION);
    s.vegetationProbability = makeConstantGrid(n, n, .9F);
    return s;
}
BuildingCollection count(std::size_t buildings) { BuildingCollection b; b.buildings.resize(buildings); return b; }
}

TEST(ScenePresentationPolicyTest, MissingOrEmptyValueIsAuto)
{
    for (const auto& value : {std::optional<std::string>(), std::optional<std::string>("")})
    {
        const auto setting = parseScenePresentationPolicy(value);
        EXPECT_EQ(setting.policy, ScenePresentationPolicy::AUTO);
        EXPECT_FALSE(setting.warning.has_value());
    }
}

TEST(ScenePresentationPolicyTest, AutoIsAnExplicitlyRecognisedValue)
{
    for (const char* value : {"auto", "AUTO", "Auto"})
    {
        const auto setting = parseScenePresentationPolicy(std::string(value));
        EXPECT_EQ(setting.policy, ScenePresentationPolicy::AUTO) << value;
        EXPECT_FALSE(setting.warning.has_value()) << value;
    }
}

TEST(ScenePresentationPolicyTest, FlatUrbanAndMetricAreOperatorOverrides)
{
    for (const char* value : {"flat_urban", "FLAT_URBAN"})
    {
        const auto setting = parseScenePresentationPolicy(std::string(value));
        EXPECT_EQ(setting.policy, ScenePresentationPolicy::FORCE_FLAT_URBAN) << value;
        EXPECT_FALSE(setting.warning.has_value());
    }
    for (const char* value : {"metric", "METRIC"})
    {
        const auto setting = parseScenePresentationPolicy(std::string(value));
        EXPECT_EQ(setting.policy, ScenePresentationPolicy::FORCE_METRIC) << value;
        EXPECT_FALSE(setting.warning.has_value());
    }
    EXPECT_STREQ(toString(ScenePresentationPolicy::AUTO), "auto");
    EXPECT_STREQ(toString(ScenePresentationPolicy::FORCE_FLAT_URBAN), "flat_urban");
    EXPECT_STREQ(toString(ScenePresentationPolicy::FORCE_METRIC), "metric");
}

TEST(ScenePresentationPolicyTest, InvalidValueWarnsAndFallsBackToAuto)
{
    // Includes the legacy undocumented "1"/"0": now reported, not guessed.
    for (const char* value : {"flat", "urban", "1", "0", "terrain"})
    {
        const auto setting = parseScenePresentationPolicy(std::string(value));
        EXPECT_EQ(setting.policy, ScenePresentationPolicy::AUTO) << value;
        ASSERT_TRUE(setting.warning.has_value()) << value;
        EXPECT_NE(setting.warning->find(std::string("'") + value + "'"), std::string::npos);
        EXPECT_NE(setting.warning->find("using auto"), std::string::npos);
    }
}

TEST(ScenePresentationPolicyTest, EnvironmentIsParsedThroughTheSameRules)
{
    ::unsetenv("DEPTHWIZARD_PRESENTATION");
    EXPECT_EQ(scenePresentationPolicyFromEnvironment().policy, ScenePresentationPolicy::AUTO);
    ::setenv("DEPTHWIZARD_PRESENTATION", "metric", 1);
    EXPECT_EQ(scenePresentationPolicyFromEnvironment().policy, ScenePresentationPolicy::FORCE_METRIC);
    ::setenv("DEPTHWIZARD_PRESENTATION", "bogus", 1);
    EXPECT_TRUE(scenePresentationPolicyFromEnvironment().warning.has_value());
    ::unsetenv("DEPTHWIZARD_PRESENTATION");
}

TEST(ScenePresentationPolicyTest, AutoIsAuthoritativeAndOverridesIgnoreTheSelector)
{
    ScenePresentationDecision metric;
    metric.presentation = ScenePresentation::METRIC;
    ScenePresentationDecision flat;
    flat.presentation = ScenePresentation::FLAT_URBAN;
    // AUTO never replaces a METRIC decision with FLAT_URBAN (or vice versa).
    EXPECT_EQ(resolveScenePresentation(ScenePresentationPolicy::AUTO, metric), ScenePresentation::METRIC);
    EXPECT_EQ(resolveScenePresentation(ScenePresentationPolicy::AUTO, flat), ScenePresentation::FLAT_URBAN);
    for (const auto* decision : {&metric, &flat})
    {
        EXPECT_EQ(resolveScenePresentation(ScenePresentationPolicy::FORCE_FLAT_URBAN, *decision),
                  ScenePresentation::FLAT_URBAN);
        EXPECT_EQ(resolveScenePresentation(ScenePresentationPolicy::FORCE_METRIC, *decision),
                  ScenePresentation::METRIC);
    }
}

TEST(ScenePresentationSelectorTest, NoAcceptedBuildingsAlwaysSelectMetric)
{
    // Even dense urban-looking semantics cannot flatten a scene with nothing
    // accepted to seat on the ground plane.
    for (const SemanticScene& semantics : {city(32), forest(32), makeSemanticScene(32, 32)})
    {
        const auto result = ScenePresentationSelector::select(semantics, makeSurface(32, 32, 100, 10), count(0));
        EXPECT_EQ(result.presentation, ScenePresentation::METRIC);
        EXPECT_EQ(result.reason, "No accepted buildings; retaining metric terrain and skirts.");
    }
    // Fractions are still measured for the log.
    EXPECT_DOUBLE_EQ(ScenePresentationSelector::select(city(32), makeSurface(32, 32, 100, 10), count(0))
                         .strongBuildingFraction, .25);
}

TEST(ScenePresentationSelectorTest, VegetationDominantSceneSelectsMetric)
{
    auto semantics = city(32);
    semantics.vegetationProbability = makeConstantGrid(32, 32, .9F);
    const auto result = ScenePresentationSelector::select(semantics, makeSurface(32, 32, 100, 10), count(10));
    EXPECT_EQ(result.presentation, ScenePresentation::METRIC);
    EXPECT_NE(result.reason.find("Vegetation-dominant"), std::string::npos);
    EXPECT_GE(result.vegetationFraction, .55);
}

TEST(ScenePresentationSelectorTest, HighReliefSceneSelectsMetric)
{
    auto surface = makeSurface(32, 32, 1200, 0);
    for (int y = 0; y < 32; ++y)
        for (int x = 0; x < 32; ++x) surface.dtm.data[y * 32 + x] += 12.0F * x + 8.0F * y;
    const auto result = ScenePresentationSelector::select(city(32), surface, count(10));
    EXPECT_EQ(result.presentation, ScenePresentation::METRIC);
    EXPECT_NE(result.reason.find("Substantial supported ground relief"), std::string::npos);
    EXPECT_GT(result.groundReliefMetres, 80.0);
}

TEST(ScenePresentationSelectorTest, SparseLocalizedBuildingsSelectMetric)
{
    const auto surface = makeSurface(32, 32, 100, 10);
    // SAT2LoD2 returning one or two objects is not urban evidence, however
    // urban the semantics look.
    for (std::size_t objects : {1U, 2U})
    {
        const auto result = ScenePresentationSelector::select(city(32), surface, count(objects));
        EXPECT_EQ(result.presentation, ScenePresentation::METRIC) << objects;
        EXPECT_NE(result.reason.find("insufficient or localized"), std::string::npos);
    }
    // Many objects packed into one corner remain a localized settlement.
    auto village = makeSemanticScene(32, 32);
    fillRectangle(village.finalClassMap, 0, 0, 12, 12, SemanticClass::BUILDING);
    fillRectangle(village.buildingProbability, 0, 0, 12, 12, .95F);
    const auto result = ScenePresentationSelector::select(village, surface, count(10));
    EXPECT_EQ(result.presentation, ScenePresentation::METRIC);
    EXPECT_LT(result.buildingQuadrants, 3);
}

TEST(ScenePresentationSelectorTest, DistributedDenseUrbanSceneSelectsFlatUrban)
{
    const auto result = ScenePresentationSelector::select(city(32), makeSurface(32, 32, 100, 10), count(250));
    EXPECT_EQ(result.presentation, ScenePresentation::FLAT_URBAN);
    EXPECT_EQ(result.reason, "Distributed high-confidence urban structures; flat presentation without skirts.");
    EXPECT_EQ(result.buildingQuadrants, 4);
    EXPECT_EQ(resolveScenePresentation(ScenePresentationPolicy::AUTO, result), ScenePresentation::FLAT_URBAN);
}
