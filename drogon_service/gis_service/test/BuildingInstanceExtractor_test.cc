#include <gtest/gtest.h>

#include "BuildingReconstruction/BuildingInstanceExtractor.h"
#include "BuildingReconstructionTestSupport.h"

#include <algorithm>
#include <cstdint>

namespace
{
using namespace depthwizard::test;

BuildingMaskResult makeSuccessfulMask(int width, int height)
{
    BuildingMaskResult result;
    result.success = true;
    result.cleanMask = makeConstantGrid<uint8_t>(width, height, uint8_t{0});
    return result;
}

TEST(BuildingInstanceExtractorTest, EmptyMaskReturnsSuccessfulEmptyExtraction)
{
    const BuildingMaskResult mask = makeSuccessfulMask(12, 12);
    const SemanticScene semantics = makeSemanticScene(12, 12);

    const ComponentExtractionResult result = timedCall(
        "BuildingInstanceExtractor::extract empty-mask",
        [&]
        {
            return BuildingInstanceExtractor::extract(
                mask,
                semantics,
                makeProjectedMetadata(12, 12),
                noMorphologyConfig());
        });

    ASSERT_TRUE(result.success) << result.errorMessage;
    EXPECT_EQ(result.acceptedComponentCount, 0);
    EXPECT_TRUE(result.components.empty());
    expectGridEqual<int32_t>(
        result.labelRaster,
        12,
        12,
        std::vector<int32_t>(144, 0));
}

TEST(BuildingInstanceExtractorTest, ExtractsTwoSeparatedBuildingsWithDeterministicIds)
{
    BuildingMaskResult mask = makeSuccessfulMask(24, 14);
    fillRectangle<uint8_t>(mask.cleanMask, 2, 3, 9, 11, uint8_t{1});
    fillRectangle<uint8_t>(mask.cleanMask, 15, 3, 22, 11, uint8_t{1});

    SemanticScene semantics = makeSemanticScene(24, 14);
    semantics.buildingProbability = makeConstantGrid(24, 14, 0.8F);
    semantics.semanticConfidence = makeConstantGrid(24, 14, 0.9F);

    BuildingReconstructionConfig config = noMorphologyConfig();
    config.connectivity = 4;

    const ComponentExtractionResult result = timedCall(
        "BuildingInstanceExtractor::extract two-buildings",
        [&]
        {
            return BuildingInstanceExtractor::extract(
                mask,
                semantics,
                makeProjectedMetadata(24, 14),
                config);
        });

    ASSERT_TRUE(result.success) << result.errorMessage;
    ASSERT_EQ(result.acceptedComponentCount, 2);
    ASSERT_EQ(result.components.size(), 2U);
    EXPECT_EQ(result.components[0].componentId, 1);
    EXPECT_EQ(result.components[1].componentId, 2);
    EXPECT_LT(result.components[0].pixelBoundingBox.x,
              result.components[1].pixelBoundingBox.x);

    for (const ComponentStats& component : result.components)
    {
        EXPECT_GT(component.pixelCount, 0);
        EXPECT_DOUBLE_EQ(
            component.physicalAreaSquareMetres,
            static_cast<double>(component.pixelCount));
        EXPECT_NEAR(component.meanBuildingProbability, 0.8F, 1.0e-6F);
        EXPECT_NEAR(component.meanSemanticConfidence, 0.9F, 1.0e-6F);
        EXPECT_NEAR(component.minSemanticConfidence, 0.9F, 1.0e-6F);
    }

    EXPECT_TRUE(std::any_of(
        result.labelRaster.data.begin(),
        result.labelRaster.data.end(),
        [](int32_t value) { return value == 1; }));
    EXPECT_TRUE(std::any_of(
        result.labelRaster.data.begin(),
        result.labelRaster.data.end(),
        [](int32_t value) { return value == 2; }));
}

TEST(BuildingInstanceExtractorTest, RejectsUnprojectedCoordinateSystem)
{
    BuildingMaskResult mask = makeSuccessfulMask(12, 12);
    fillRectangle<uint8_t>(mask.cleanMask, 2, 2, 10, 10, uint8_t{1});
    const SemanticScene semantics = makeSemanticScene(12, 12);
    SpatialMetadata metadata = makeProjectedMetadata(12, 12);
    metadata.projectionRef = "GEOGCS[\"WGS 84\"]";

    const ComponentExtractionResult result = BuildingInstanceExtractor::extract(
        mask,
        semantics,
        metadata,
        noMorphologyConfig());

    EXPECT_FALSE(result.success);
    EXPECT_FALSE(result.errorMessage.empty());
}

TEST(BuildingInstanceExtractorTest, RejectsMismatchedSemanticDimensions)
{
    const BuildingMaskResult mask = makeSuccessfulMask(12, 12);
    SemanticScene semantics = makeSemanticScene(12, 12);
    semantics.semanticConfidence.width = 11;

    const ComponentExtractionResult result = BuildingInstanceExtractor::extract(
        mask,
        semantics,
        makeProjectedMetadata(12, 12),
        noMorphologyConfig());

    EXPECT_FALSE(result.success);
    EXPECT_FALSE(result.errorMessage.empty());
}

} // namespace
