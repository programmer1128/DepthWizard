#include <gtest/gtest.h>
#include "MeshMapping/ScenePresentationSelector.h"
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
