#include <gtest/gtest.h>

#include "BuildingReconstruction/BuildingReconstructionService.h"
#include "BuildingReconstructionTestSupport.h"

#include <cstdint>
#include <limits>

namespace
{
using namespace depthwizard::test;

TEST(BuildingReconstructionServiceTest, EmptySceneReturnsEmptyCollection)
{
    constexpr int width = 20;
    constexpr int height = 20;
    const SemanticScene semantics = makeSemanticScene(width, height);
    const GeoreferencedSurfaceBundle surface =
        makeSurface(width, height, 100.0F, 0.0F);

    const BuildingCollection collection = timedCall(
        "BuildingReconstructionService::reconstruct empty",
        [&]
        {
            return BuildingReconstructionService::reconstruct(
                semantics,
                surface,
                makeProjectedMetadata(width, height),
                noMorphologyConfig());
        });

    EXPECT_TRUE(collection.buildings.empty());
}

TEST(BuildingReconstructionServiceTest, ReconstructsBuildingFromSemanticMaskToPhysicalInstance)
{
    constexpr int width = 24;
    constexpr int height = 24;
    SemanticScene semantics = makeSemanticScene(width, height, SemanticClass::GROUND);
    GeoreferencedSurfaceBundle surface = makeSurface(width, height, 100.0F, 0.0F);

    fillRectangle<float>(semantics.buildingProbability, 6, 6, 18, 18, 0.95F);
    fillRectangle<float>(semantics.semanticConfidence, 6, 6, 18, 18, 0.90F);
    fillRectangle<SemanticClass>(
        semantics.finalClassMap,
        6,
        6,
        18,
        18,
        SemanticClass::BUILDING);
    fillRectangle<float>(surface.ndsm, 6, 6, 18, 18, 12.0F);
    surface.dsm = surface.dtm;
    fillRectangle<float>(surface.dsm, 6, 6, 18, 18, 112.0F);

    BuildingReconstructionConfig config = noMorphologyConfig();
    config.minBuildingAreaSquareMetres = 20.0F;
    config.groundBufferRadiusMetres = 2.0F;
    config.footprintErosionRadiusMetres = 1.0F;
    config.minRequiredSamples = 5;

    const BuildingCollection collection = timedCall(
        "BuildingReconstructionService::reconstruct one-building",
        [&]
        {
            return BuildingReconstructionService::reconstruct(
                semantics,
                surface,
                makeProjectedMetadata(width, height),
                config);
        });

    ASSERT_EQ(collection.buildings.size(), 1U);
    const BuildingInstance& building = collection.buildings.front();
    EXPECT_EQ(building.buildingId, 1U);
    EXPECT_EQ(building.baseModel, BaseElevationModel::PER_VERTEX);
    EXPECT_FLOAT_EQ(building.representativeBaseElevation, 100.0F);
    EXPECT_EQ(
        building.baseElevationPerVertex.size(),
        building.projectedFootprint.outerRing.size());
    EXPECT_FLOAT_EQ(building.heightAboveGround, 12.0F);
    EXPECT_FLOAT_EQ(building.roofElevation, 112.0F);
    EXPECT_GT(building.footprintAreaSquareMetres, 0.0F);
    EXPECT_NEAR(building.semanticConfidence, 0.95F, 1.0e-5F);
    EXPECT_GT(building.heightConfidence, 0.0F);
    EXPECT_GE(building.pixelFootprint.outerRing.size(), 4U);
    EXPECT_EQ(
        building.pixelFootprint.outerRing.size(),
        building.projectedFootprint.outerRing.size());
}

TEST(BuildingReconstructionServiceTest, InvalidConfigurationFailsClosedWithEmptyCollection)
{
    constexpr int width = 12;
    constexpr int height = 12;
    const SemanticScene semantics = makeSemanticScene(width, height);
    const GeoreferencedSurfaceBundle surface =
        makeSurface(width, height, 100.0F, 0.0F);
    BuildingReconstructionConfig config;
    config.connectivity = 7;

    const BuildingCollection collection = BuildingReconstructionService::reconstruct(
        semantics,
        surface,
        makeProjectedMetadata(width, height),
        config);

    EXPECT_TRUE(collection.buildings.empty());
}

} // namespace
