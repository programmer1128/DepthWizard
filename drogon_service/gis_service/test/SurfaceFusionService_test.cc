#include <gtest/gtest.h>

#include "SurfaceFusion/SurfaceFusionService.h"
#include "TestGridSupport.h"

#include <cmath>
#include <cstdint>
#include <limits>
#include <stdexcept>
#include <vector>

namespace
{
using namespace depthwizard::test;

ReferenceTerrainBundle makeReference(float dtm, float confidence)
{
    ReferenceTerrainBundle reference;
    reference.correctedTerrainPrior = makeConstantGrid(4, 4, dtm);
    reference.confidence = makeConstantGrid(4, 4, confidence);
    reference.validMask = makeConstantGrid<uint8_t>(4, 4, uint8_t{1});
    return reference;
}

SemanticScene makeSemantics(float confidence)
{
    SemanticScene semantics;
    semantics.semanticConfidence = makeConstantGrid(4, 4, confidence);
    return semantics;
}

SpatialMetadata makeMetadata()
{
    SpatialMetadata metadata;
    metadata.width = 4;
    metadata.height = 4;
    metadata.geoTransform = {100.0, 1.0, 0.0, 200.0, 0.0, -1.0};
    metadata.projectionRef = "EPSG:32645";
    metadata.isGeoreferenced = true;
    return metadata;
}

TEST(SurfaceFusionServiceTest, ComputesExactDsmAndRootSumSquareConfidenceOn4x4Grid)
{
    const RasterGrid<float> ndsm = makeConstantGrid(4, 4, 5.0F);
    const ReferenceTerrainBundle reference = makeReference(100.0F, 0.8F);
    const SemanticScene semantics = makeSemantics(0.7F);
    const RasterGrid<float> aiConfidence = makeConstantGrid(4, 4, 0.9F);
    const SpatialMetadata metadata = makeMetadata();

    const GeoreferencedSurfaceBundle result = timedCall(
        "SurfaceFusionService::composeMetricSurface 4x4",
        [&]
        {
            return SurfaceFusionService::composeMetricSurface(
                ndsm, reference, semantics, aiConfidence, metadata);
        });

    const float expectedConfidence =
        1.0F - std::sqrt(0.1F * 0.1F + 0.2F * 0.2F + 0.3F * 0.3F);

    expectGridNear(result.dtm, 4, 4, std::vector<float>(16, 100.0F));
    expectGridNear(result.ndsm, 4, 4, std::vector<float>(16, 5.0F));
    expectGridNear(result.dsm, 4, 4, std::vector<float>(16, 105.0F));
    expectGridNear(result.surfaceConfidence, 4, 4,
                   std::vector<float>(16, expectedConfidence));
    expectGridEqual<uint8_t>(result.validMask, 4, 4,
                             std::vector<uint8_t>(16, uint8_t{1}));
    EXPECT_EQ(result.elevationUnit, ElevationUnit::METERS);
    EXPECT_EQ(result.spatialMetadata.projectionRef, "EPSG:32645");
}

TEST(SurfaceFusionServiceTest, InvalidMaskOrNanInputsProduceNodataOutputs)
{
    const float nan = std::numeric_limits<float>::quiet_NaN();
    RasterGrid<float> ndsm = makeConstantGrid(4, 4, 5.0F);
    ReferenceTerrainBundle reference = makeReference(100.0F, 1.0F);
    const SemanticScene semantics = makeSemantics(1.0F);
    const RasterGrid<float> aiConfidence = makeConstantGrid(4, 4, 1.0F);

    reference.validMask.data[0] = 0;
    reference.correctedTerrainPrior.data[1] = nan;
    ndsm.data[2] = nan;

    const GeoreferencedSurfaceBundle result = timedCall(
        "SurfaceFusionService::composeMetricSurface nodata",
        [&]
        {
            return SurfaceFusionService::composeMetricSurface(
                ndsm, reference, semantics, aiConfidence, makeMetadata());
        });

    for (std::size_t index = 0; index < 3; ++index)
    {
        EXPECT_EQ(result.validMask.data[index], 0);
        EXPECT_TRUE(std::isnan(result.dtm.data[index]));
        EXPECT_TRUE(std::isnan(result.ndsm.data[index]));
        EXPECT_TRUE(std::isnan(result.dsm.data[index]));
        EXPECT_FLOAT_EQ(result.surfaceConfidence.data[index], 0.0F);
    }
    EXPECT_EQ(result.validMask.data[3], 1);
    EXPECT_FLOAT_EQ(result.dsm.data[3], 105.0F);
}

TEST(SurfaceFusionServiceTest, MaximumCombinedUncertaintyClampsConfidenceToZero)
{
    const RasterGrid<float> ndsm = makeConstantGrid(4, 4, 0.0F);
    const ReferenceTerrainBundle reference = makeReference(100.0F, 0.0F);
    const SemanticScene semantics = makeSemantics(0.0F);
    const RasterGrid<float> aiConfidence = makeConstantGrid(4, 4, 0.0F);

    const GeoreferencedSurfaceBundle result = timedCall(
        "SurfaceFusionService::composeMetricSurface max-uncertainty",
        [&]
        {
            return SurfaceFusionService::composeMetricSurface(
                ndsm, reference, semantics, aiConfidence, makeMetadata());
        });

    expectGridNear(result.surfaceConfidence, 4, 4,
                   std::vector<float>(16, 0.0F));
}

TEST(SurfaceFusionServiceTest, RejectsMismatchedInputGridShapes)
{
    const RasterGrid<float> ndsm = makeConstantGrid(4, 4, 5.0F);
    ReferenceTerrainBundle reference = makeReference(100.0F, 1.0F);
    const SemanticScene semantics = makeSemantics(1.0F);
    const RasterGrid<float> aiConfidence = makeConstantGrid(4, 4, 1.0F);
    reference.confidence.width = 3;

    EXPECT_THROW(
        static_cast<void>(timedCall(
            "SurfaceFusionService::composeMetricSurface malformed-input",
            [&]
            {
                return SurfaceFusionService::composeMetricSurface(
                    ndsm, reference, semantics, aiConfidence, makeMetadata());
            })),
        std::invalid_argument);
}

} // namespace
