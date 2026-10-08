// Stage 2 of the vegetation overlay: configuration, mask extraction,
// conservative UNKNOWN recovery, heights and diagnostics. No geometry.

#include "BuildingReconstruction/BuildingReconstructionConfig.h"
#include "BuildingReconstructionTestSupport.h"
#include "Vegetation/VegetationConfig.h"
#include "Vegetation/VegetationDiagnostics.h"
#include "Vegetation/VegetationExtractor.h"
#include "Vegetation/VegetationHeightSampler.h"

#include <gtest/gtest.h>

#include <cmath>
#include <cstdlib>
#include <limits>
#include <map>

using namespace depthwizard::test;

namespace
{
VegetationConfig parse(const std::map<std::string, std::string>& values)
{
    return VegetationConfig::parse([&](const std::string& name) -> std::optional<std::string>
    {
        const auto found = values.find(name);
        if (found == values.end()) return std::nullopt;
        return found->second;
    });
}

// A 0.5 m north-up scene of bare ground with valid DTM/nDSM everywhere.
struct Scene
{
    int width;
    int height;
    SpatialMetadata metadata;
    SemanticScene semantics;
    GeoreferencedSurfaceBundle surface;
    RasterGrid<uint8_t> footprints;
    VegetationConfig config;

    Scene(int w = 60, int h = 40, double pixelX = 0.5, double pixelY = -0.5)
        : width(w), height(h), metadata(makeProjectedMetadata(w, h, pixelX, pixelY)),
          semantics(makeSemanticScene(w, h, SemanticClass::GROUND)), surface(makeSurface(w, h, 100.0F, 0.0F)),
          footprints(makeConstantGrid<uint8_t>(w, h, uint8_t{0}))
    {
        surface.spatialMetadata = metadata;
        semantics.groundProbability = makeConstantGrid(w, h, 0.9F);
        config.mode = VegetationMode::ON;
    }

    std::size_t index(int x, int y) const { return static_cast<std::size_t>(y) * width + x; }

    // Pixel-index rectangle [x0, x1) x [y0, y1).
    void vegetation(int x0, int y0, int x1, int y1, float heightMetres)
    {
        fillRectangle(semantics.finalClassMap, x0, y0, x1, y1, SemanticClass::VEGETATION);
        fillRectangle(semantics.vegetationProbability, x0, y0, x1, y1, 0.9F);
        fillRectangle(semantics.groundProbability, x0, y0, x1, y1, 0.05F);
        setHeight(x0, y0, x1, y1, heightMetres);
    }
    void unknown(int x0, int y0, int x1, int y1, float vegetationProbability, float heightMetres)
    {
        fillRectangle(semantics.finalClassMap, x0, y0, x1, y1, SemanticClass::UNKNOWN);
        fillRectangle(semantics.vegetationProbability, x0, y0, x1, y1, vegetationProbability);
        fillRectangle(semantics.groundProbability, x0, y0, x1, y1, 0.05F);
        setHeight(x0, y0, x1, y1, heightMetres);
    }
    void setHeight(int x0, int y0, int x1, int y1, float heightMetres)
    {
        fillRectangle(surface.ndsm, x0, y0, x1, y1, heightMetres);
        for (int y = y0; y < y1; ++y)
            for (int x = x0; x < x1; ++x) surface.dsm.data[index(x, y)] = surface.dtm.data[index(x, y)] + heightMetres;
    }

    VegetationMask extract() const
    {
        return VegetationExtractor::extract(semantics, surface, footprints, metadata, config);
    }
    VegetationTier tier(const VegetationMask& mask, int x, int y) const
    {
        return static_cast<VegetationTier>(mask.tier.data[index(x, y)]);
    }
};

std::size_t countTier(const VegetationMask& mask, VegetationTier tier)
{
    return static_cast<std::size_t>(
        std::count(mask.tier.data.begin(), mask.tier.data.end(), static_cast<uint8_t>(tier)));
}
} // namespace

// --- Configuration ----------------------------------------------------------

TEST(VegetationConfigTest, DefaultsAreOffAndConservative)
{
    const VegetationConfig config = parse({});
    EXPECT_EQ(config.mode, VegetationMode::OFF);
    EXPECT_FALSE(config.enabled());
    EXPECT_TRUE(config.canopy);
    EXPECT_TRUE(config.trees);
    EXPECT_FLOAT_EQ(config.minHeightMetres, 1.5F);
    EXPECT_FLOAT_EQ(config.maxHeightMetres, 45.0F);
    EXPECT_EQ(config.maxInstances, 3000);
    EXPECT_EQ(config.seed, 1337U);
    EXPECT_FALSE(config.diagnostics);
    EXPECT_TRUE(config.recoverUnknown);
    EXPECT_FLOAT_EQ(config.unknownProbability, 0.50F);
    EXPECT_FLOAT_EQ(config.denseMinAreaSquareMetres, 300.0F);
    EXPECT_FLOAT_EQ(config.denseLocalCoverage, 0.60F);
    EXPECT_FLOAT_EQ(config.individualTreeMaxGsdMetres, 1.0F);
    EXPECT_EQ(config.canopyMaxTriangles, 200000);
    EXPECT_FLOAT_EQ(config.canopySmoothRadiusMetres, 2.0F);
    EXPECT_TRUE(config.warnings.empty());
    ::unsetenv("DEPTHWIZARD_VEGETATION");
    EXPECT_EQ(VegetationConfig::fromEnvironment().mode, VegetationMode::OFF);
}

TEST(VegetationConfigTest, ReadsEveryVariable)
{
    const VegetationConfig config = parse({{"DEPTHWIZARD_VEGETATION", "auto"},
                                           {"DEPTHWIZARD_VEGETATION_CANOPY", "0"},
                                           {"DEPTHWIZARD_VEGETATION_TREES", "off"},
                                           {"DEPTHWIZARD_VEGETATION_MIN_HEIGHT_M", "2.5"},
                                           {"DEPTHWIZARD_VEGETATION_MAX_HEIGHT_M", "30"},
                                           {"DEPTHWIZARD_VEGETATION_MAX_INSTANCES", "500"},
                                           {"DEPTHWIZARD_VEGETATION_SEED", "42"},
                                           {"DEPTHWIZARD_VEGETATION_DIAGNOSTICS", "1"},
                                           {"DEPTHWIZARD_VEGETATION_RECOVER_UNKNOWN", "0"},
                                           {"DEPTHWIZARD_VEGETATION_UNKNOWN_PROBABILITY", "0.85"},
                                           {"DEPTHWIZARD_VEGETATION_DENSE_MIN_AREA_M2", "500"},
                                           {"DEPTHWIZARD_VEGETATION_DENSE_LOCAL_COVERAGE", "0.7"},
                                           {"DEPTHWIZARD_VEGETATION_INDIVIDUAL_TREE_MAX_GSD_M", "2"},
                                           {"DEPTHWIZARD_VEGETATION_CANOPY_MAX_TRIANGLES", "1000"},
                                           {"DEPTHWIZARD_VEGETATION_CANOPY_SMOOTH_RADIUS_M", "2.5"}});
    EXPECT_EQ(config.mode, VegetationMode::AUTO);
    EXPECT_FALSE(config.canopy);
    EXPECT_FALSE(config.trees);
    EXPECT_FLOAT_EQ(config.minHeightMetres, 2.5F);
    EXPECT_FLOAT_EQ(config.maxHeightMetres, 30.0F);
    EXPECT_EQ(config.maxInstances, 500);
    EXPECT_EQ(config.seed, 42U);
    EXPECT_TRUE(config.diagnostics);
    EXPECT_FALSE(config.recoverUnknown);
    EXPECT_FLOAT_EQ(config.unknownProbability, 0.85F);
    EXPECT_FLOAT_EQ(config.denseMinAreaSquareMetres, 500.0F);
    EXPECT_FLOAT_EQ(config.denseLocalCoverage, 0.7F);
    EXPECT_FLOAT_EQ(config.individualTreeMaxGsdMetres, 2.0F);
    EXPECT_EQ(config.canopyMaxTriangles, 1000);
    EXPECT_FLOAT_EQ(config.canopySmoothRadiusMetres, 2.5F);
    EXPECT_TRUE(config.warnings.empty());
    for (const char* on : {"1", "ON", "true"}) EXPECT_EQ(parse({{"DEPTHWIZARD_VEGETATION", on}}).mode, VegetationMode::ON);
    for (const char* off : {"0", "off", ""}) EXPECT_EQ(parse({{"DEPTHWIZARD_VEGETATION", off}}).mode, VegetationMode::OFF);
}

TEST(VegetationConfigTest, InvalidValuesWarnAndKeepDefaults)
{
    const VegetationConfig config = parse({{"DEPTHWIZARD_VEGETATION", "yes"},
                                           {"DEPTHWIZARD_VEGETATION_MIN_HEIGHT_M", "-1"},
                                           {"DEPTHWIZARD_VEGETATION_MAX_INSTANCES", "12.5"},
                                           {"DEPTHWIZARD_VEGETATION_SEED", "abc"},
                                           {"DEPTHWIZARD_VEGETATION_UNKNOWN_PROBABILITY", "0.3"},
                                           {"DEPTHWIZARD_VEGETATION_CANOPY", "maybe"}});
    EXPECT_EQ(config.mode, VegetationMode::OFF); // Never silently enabled
    EXPECT_FLOAT_EQ(config.minHeightMetres, 1.5F);
    EXPECT_EQ(config.maxInstances, 3000);
    EXPECT_EQ(config.seed, 1337U);
    EXPECT_FLOAT_EQ(config.unknownProbability, 0.50F); // Recovery stays conservative
    EXPECT_TRUE(config.canopy);
    EXPECT_EQ(config.warnings.size(), 6U);

    const VegetationConfig inverted =
        parse({{"DEPTHWIZARD_VEGETATION_MIN_HEIGHT_M", "10"}, {"DEPTHWIZARD_VEGETATION_MAX_HEIGHT_M", "5"}});
    EXPECT_FLOAT_EQ(inverted.minHeightMetres, 1.5F);
    EXPECT_FLOAT_EQ(inverted.maxHeightMetres, 45.0F);
    EXPECT_EQ(inverted.warnings.size(), 1U);
}

// --- Mask extraction --------------------------------------------------------

TEST(VegetationExtractorTest, ConfirmedVegetationNeedsValidHeightAboveTheMinimum)
{
    Scene s;
    s.vegetation(5, 5, 15, 15, 8.0F);   // Trees
    s.vegetation(30, 5, 40, 15, 0.4F);  // Grass: vegetation, but no object height
    const VegetationMask mask = s.extract();
    ASSERT_TRUE(mask.inputsAvailable);
    EXPECT_EQ(mask.stats.inputVegetationPixels, 200U);
    EXPECT_EQ(mask.stats.confirmedPixels, 100U);
    EXPECT_EQ(mask.stats.rejectedBelowMinHeight, 100U);
    EXPECT_EQ(s.tier(mask, 10, 10), VegetationTier::CONFIRMED);
    EXPECT_EQ(s.tier(mask, 35, 10), VegetationTier::NONE);
    EXPECT_EQ(mask.stats.components, 1U);
}

TEST(VegetationExtractorTest, BuildingsBufferedFootprintsRoadsWaterAndNoDataAreExcluded)
{
    Scene s;
    s.vegetation(0, 0, 60, 40, 9.0F);
    // A building footprint inside the vegetation: 2 m buffer = 4 px at 0.5 m.
    fillRectangle(s.footprints, 20, 15, 30, 25, uint8_t{1});
    fillRectangle(s.semantics.finalClassMap, 20, 15, 30, 25, SemanticClass::BUILDING);
    // A one-pixel road and a water pond crossing the vegetation.
    fillRectangle(s.semantics.finalClassMap, 0, 35, 60, 36, SemanticClass::ROAD);
    fillRectangle(s.semantics.finalClassMap, 45, 2, 50, 7, SemanticClass::WATER);
    // NoData: NaN nDSM, and an invalid surface mask.
    s.surface.ndsm.data[s.index(5, 5)] = std::numeric_limits<float>::quiet_NaN();
    s.surface.validMask.data[s.index(6, 5)] = 0;
    s.surface.dtm.data[s.index(7, 5)] = std::numeric_limits<float>::infinity();

    const VegetationMask mask = s.extract();
    for (int y = 0; y < s.height; ++y)
        for (int x = 0; x < s.width; ++x)
        {
            const bool inBuffer = x >= 16 && x < 34 && y >= 11 && y < 29;
            const auto cls = s.semantics.finalClassMap.data[s.index(x, y)];
            if (cls == SemanticClass::BUILDING || cls == SemanticClass::ROAD || cls == SemanticClass::WATER)
                EXPECT_EQ(s.tier(mask, x, y), VegetationTier::NONE) << x << "," << y;
            // Protected ring: the elliptical buffer covers at least the 4 px
            // cross around the footprint.
            if ((x >= 16 && x < 34 && y >= 15 && y < 25) || (x >= 20 && x < 30 && y >= 11 && y < 29))
            {
                EXPECT_TRUE(inBuffer);
                EXPECT_EQ(s.tier(mask, x, y), VegetationTier::NONE) << x << "," << y;
                EXPECT_EQ(mask.protectedMask.data[s.index(x, y)], 1U);
            }
        }
    EXPECT_EQ(s.tier(mask, 5, 5), VegetationTier::NONE);
    EXPECT_EQ(s.tier(mask, 6, 5), VegetationTier::NONE);
    EXPECT_EQ(s.tier(mask, 7, 5), VegetationTier::NONE);
    EXPECT_EQ(mask.stats.rejectedInvalidHeight, 3U);
    EXPECT_GT(mask.stats.rejectedBuildingBuffer, 0U);
    // Outside the buffer the vegetation survives.
    EXPECT_EQ(s.tier(mask, 10, 10), VegetationTier::CONFIRMED);
    EXPECT_EQ(s.tier(mask, 35, 20), VegetationTier::CONFIRMED);
    // The road and pond are never closed over.
    EXPECT_EQ(mask.stats.gapPixels, 0U);
}

TEST(VegetationExtractorTest, BufferIsMetricPerAxisForNonSquarePixels)
{
    // 0.5 m columns, 1.0 m rows: a 2 m buffer is 4 px across and 2 px down.
    Scene s(60, 40, 0.5, -1.0);
    fillRectangle(s.footprints, 20, 15, 30, 25, uint8_t{1});
    const VegetationMask mask = s.extract();
    EXPECT_DOUBLE_EQ(mask.scale.columnSpacingMetres, 0.5);
    EXPECT_DOUBLE_EQ(mask.scale.rowSpacingMetres, 1.0);
    const auto protectedAt = [&](int x, int y) { return mask.protectedMask.data[s.index(x, y)] != 0; };
    EXPECT_TRUE(protectedAt(16, 20));
    EXPECT_FALSE(protectedAt(15, 20));
    EXPECT_TRUE(protectedAt(33, 20));
    EXPECT_FALSE(protectedAt(34, 20));
    EXPECT_TRUE(protectedAt(25, 13));
    EXPECT_FALSE(protectedAt(25, 12));
    EXPECT_TRUE(protectedAt(25, 26));
    EXPECT_FALSE(protectedAt(25, 27));
}

TEST(VegetationExtractorTest, UnknownRecoveryIsConservativeAndTracked)
{
    Scene s(80, 60);
    s.vegetation(5, 5, 20, 20, 8.0F);
    s.unknown(20, 5, 23, 20, 0.85F, 8.0F);    // Touches confirmed vegetation -> recovered
    s.unknown(40, 30, 52, 42, 0.85F, 7.0F);   // Compact 36 m2 region of its own -> recovered
    s.unknown(70, 5, 71, 6, 0.95F, 7.0F);     // Lone pixel, no support -> spatial rejection
    s.unknown(5, 40, 15, 50, 0.45F, 7.0F);    // Vegetation probability below the 0.50 threshold
    s.unknown(25, 40, 30, 50, 0.85F, 0.5F);   // Too low to be a tree
    s.unknown(60, 40, 70, 50, 0.85F, 7.0F);   // Building evidence
    fillRectangle(s.semantics.buildingProbability, 60, 40, 70, 50, 0.5F);
    s.unknown(5, 52, 15, 58, 0.85F, 7.0F);    // Road evidence
    fillRectangle(s.semantics.roadProbability, 5, 52, 15, 58, 0.4F);
    s.unknown(8, 20, 11, 23, 0.85F, 8.0F);    // Touches vegetation, but its centre is a height spike
    s.surface.ndsm.data[s.index(9, 21)] = 40.0F;

    const VegetationMask mask = s.extract();
    EXPECT_EQ(s.tier(mask, 21, 10), VegetationTier::RECOVERED_UNKNOWN);
    EXPECT_EQ(s.tier(mask, 45, 35), VegetationTier::RECOVERED_UNKNOWN);
    EXPECT_EQ(s.tier(mask, 70, 5), VegetationTier::NONE);
    EXPECT_EQ(s.tier(mask, 10, 45), VegetationTier::NONE);
    EXPECT_EQ(s.tier(mask, 27, 45), VegetationTier::NONE);
    EXPECT_EQ(s.tier(mask, 65, 45), VegetationTier::NONE);
    EXPECT_EQ(s.tier(mask, 10, 55), VegetationTier::NONE);
    EXPECT_EQ(s.tier(mask, 9, 21), VegetationTier::NONE);
    EXPECT_EQ(s.tier(mask, 8, 22), VegetationTier::RECOVERED_UNKNOWN);
    EXPECT_EQ(mask.stats.rejectedUnknownSpatialSupport, 1U);
    EXPECT_EQ(mask.stats.rejectedUnknownProbability, 100U);
    EXPECT_EQ(mask.stats.rejectedUnknownHeight, 50U + 1U);
    EXPECT_EQ(mask.stats.rejectedUnknownBuilding, 100U);
    EXPECT_EQ(mask.stats.rejectedUnknownRoadWater, 60U);
    EXPECT_EQ(mask.stats.recoveredUnknownPixels, 45U + 144U + 8U);
    EXPECT_EQ(mask.stats.recoveredPixels, mask.stats.recoveredUnknownPixels);
    EXPECT_EQ(mask.stats.confirmedPixels, 225U);
}

TEST(VegetationExtractorTest, UnknownInsideABufferedFootprintIsNeverRecovered)
{
    Scene s;
    s.vegetation(5, 5, 25, 25, 8.0F);
    s.unknown(25, 5, 35, 25, 0.95F, 8.0F);
    fillRectangle(s.footprints, 37, 5, 45, 25, uint8_t{1}); // Buffer reaches x >= 33
    const VegetationMask mask = s.extract();
    EXPECT_EQ(s.tier(mask, 30, 10), VegetationTier::RECOVERED_UNKNOWN);
    for (int x = 33; x < 35; ++x) EXPECT_EQ(s.tier(mask, x, 10), VegetationTier::NONE) << x;
    EXPECT_GT(mask.stats.rejectedUnknownBuilding, 0U);
}

TEST(VegetationExtractorTest, AblationClassFourOnlyVersusUnknownRecovery)
{
    Scene s(80, 60);
    s.vegetation(5, 5, 20, 20, 8.0F);
    s.unknown(20, 5, 26, 20, 0.85F, 8.0F);
    s.unknown(40, 30, 52, 42, 0.85F, 7.0F);

    s.config.recoverUnknown = false;
    const VegetationMask classFour = s.extract();
    s.config.recoverUnknown = true;
    const VegetationMask recovered = s.extract();

    EXPECT_EQ(classFour.stats.recoveredPixels, 0U);
    EXPECT_EQ(countTier(classFour, VegetationTier::RECOVERED_UNKNOWN), 0U);
    EXPECT_EQ(classFour.stats.confirmedPixels, recovered.stats.confirmedPixels); // Recovery never alters class 4
    EXPECT_EQ(recovered.stats.recoveredPixels, 90U + 144U);
    EXPECT_GT(recovered.stats.cleanedPixels(), classFour.stats.cleanedPixels());
    for (std::size_t i = 0; i < classFour.tier.data.size(); ++i)
        if (classFour.tier.data[i] == static_cast<uint8_t>(VegetationTier::CONFIRMED))
            ASSERT_EQ(recovered.tier.data[i], static_cast<uint8_t>(VegetationTier::CONFIRMED));
}

TEST(VegetationExtractorTest, SpecksAreRemovedAndOnlySmallValidGapsClose)
{
    Scene s;
    s.vegetation(2, 2, 4, 4, 6.0F);       // 1 m2 speck (< 4 m2)
    s.vegetation(10, 10, 20, 30, 8.0F);   // Two crowns split by a one-pixel ground gap
    s.vegetation(21, 10, 31, 30, 8.0F);
    s.vegetation(40, 10, 48, 30, 8.0F);   // Two crowns split by a one-pixel road
    s.vegetation(49, 10, 57, 30, 8.0F);
    fillRectangle(s.semantics.finalClassMap, 48, 10, 49, 30, SemanticClass::ROAD);

    const VegetationMask mask = s.extract();
    EXPECT_EQ(s.tier(mask, 2, 2), VegetationTier::NONE);
    EXPECT_EQ(mask.stats.removedSmallComponentPixels, 4U);
    EXPECT_EQ(s.tier(mask, 20, 20), VegetationTier::GAP_CLOSED);
    for (int y = 10; y < 30; ++y) EXPECT_EQ(s.tier(mask, 48, y), VegetationTier::NONE) << y;
    // Closing does not grow the outer boundary.
    EXPECT_EQ(s.tier(mask, 9, 20), VegetationTier::NONE);
    EXPECT_EQ(s.tier(mask, 31, 20), VegetationTier::NONE);
    EXPECT_EQ(s.tier(mask, 15, 9), VegetationTier::NONE);
}

TEST(VegetationExtractorTest, CoarsePixelsKeepSinglePixelPatchesButNeverLoneUnknowns)
{
    // 10 m pixels (Test8): a single vegetation pixel is 100 m2, no speck; a
    // lone UNKNOWN pixel still lacks support.
    Scene s(30, 20, 10.0, -10.0);
    s.vegetation(5, 5, 6, 6, 9.0F);
    s.unknown(20, 10, 21, 11, 0.95F, 9.0F);
    const VegetationMask mask = s.extract();
    EXPECT_EQ(s.tier(mask, 5, 5), VegetationTier::CONFIRMED);
    EXPECT_EQ(s.tier(mask, 20, 10), VegetationTier::NONE);
    EXPECT_EQ(mask.stats.rejectedUnknownSpatialSupport, 1U);
}

TEST(VegetationExtractorTest, NonGeoreferencedRasterUsesTheConservativeFallback)
{
    Scene s;
    s.metadata.isGeoreferenced = false;
    const VegetationMask mask = s.extract();
    EXPECT_FALSE(mask.scale.georeferenced);
    EXPECT_DOUBLE_EQ(mask.scale.columnSpacingMetres, s.config.fallbackPixelSizeMetres);
}

TEST(VegetationExtractorTest, MissingInputsProduceNoMask)
{
    Scene s;
    s.surface.ndsm.width = 1;
    const VegetationMask mask = s.extract();
    EXPECT_FALSE(mask.inputsAvailable);
    EXPECT_TRUE(mask.tier.data.empty());
}

TEST(VegetationExtractorTest, ExtractionIsDeterministicAndReadOnly)
{
    Scene s(80, 60);
    s.vegetation(5, 5, 30, 30, 8.0F);
    s.unknown(30, 5, 35, 30, 0.85F, 8.0F);
    s.unknown(50, 30, 62, 42, 0.85F, 7.0F);
    fillRectangle(s.footprints, 12, 12, 18, 18, uint8_t{1});
    const auto classes = s.semantics.finalClassMap.data;
    const auto ndsm = s.surface.ndsm.data;
    const auto dtm = s.surface.dtm.data;

    const VegetationMask first = s.extract();
    const VegetationMask second = s.extract();
    EXPECT_EQ(first.tier.data, second.tier.data);
    EXPECT_EQ(first.protectedMask.data, second.protectedMask.data);
    EXPECT_EQ(VegetationDiagnostics::toJson(s.config, first, {}, 0.0).toStyledString(),
              VegetationDiagnostics::toJson(s.config, second, {}, 0.0).toStyledString());
    // The seed is cosmetic: it cannot move the mask.
    s.config.seed = 99;
    EXPECT_EQ(s.extract().tier.data, first.tier.data);
    EXPECT_EQ(s.semantics.finalClassMap.data, classes);
    EXPECT_EQ(s.surface.ndsm.data, ndsm);
    EXPECT_EQ(s.surface.dtm.data, dtm);
}

// --- Heights ----------------------------------------------------------------

TEST(VegetationHeightSamplerTest, ObjectHeightIsNdsmNeverRawDsmAndBaseIsDtm)
{
    Scene s;
    for (std::size_t i = 0; i < s.surface.dtm.data.size(); ++i) s.surface.dtm.data[i] = 2400.0F + 0.1F * i;
    s.vegetation(10, 10, 30, 30, 11.0F); // dsm = dtm + 11 (about 2400 m)
    const VegetationMask mask = s.extract();
    const VegetationHeights heights = VegetationHeightSampler::sample(mask, s.surface, s.config);
    const std::size_t i = s.index(20, 20);
    EXPECT_FLOAT_EQ(heights.metricHeight.data[i], 11.0F);
    EXPECT_GT(s.surface.dsm.data[i], 2400.0F);
    EXPECT_TRUE(std::isnan(heights.metricHeight.data[s.index(5, 5)])); // Outside the mask
    EXPECT_FLOAT_EQ(heights.p50, 11.0F);

    const VegetationHeightRecord record = VegetationHeightSampler::record(
        heights.metricHeight.data[i], s.surface.dtm.data[i], ScenePresentation::METRIC, 2.25F);
    EXPECT_FLOAT_EQ(record.baseElevation, s.surface.dtm.data[i]);
    EXPECT_FLOAT_EQ(record.metricHeight, 11.0F);
    EXPECT_FLOAT_EQ(record.displayHeight, 11.0F);
    EXPECT_EQ(record.presentationMode, "metric");
}

TEST(VegetationHeightSamplerTest, PhysicalAndPercentileClampingPrecedeTheDisplayScale)
{
    Scene s;
    s.vegetation(0, 0, 60, 40, 10.0F);
    s.setHeight(0, 0, 5, 2, 60.0F); // 10 implausible pixels above the 45 m limit
    const VegetationMask mask = s.extract();
    const VegetationHeights heights = VegetationHeightSampler::sample(mask, s.surface, s.config);
    EXPECT_LE(heights.ceilingMetres, s.config.maxHeightMetres);
    for (float value : heights.metricHeight.data)
        if (std::isfinite(value)) EXPECT_LE(value, heights.ceilingMetres);
    EXPECT_EQ(heights.clampedPixels, 10U);
    EXPECT_FLOAT_EQ(heights.p95, 10.0F);
}

TEST(VegetationHeightSamplerTest, RobustHeightIgnoresASingleNoisyPixel)
{
    Scene s;
    s.vegetation(10, 10, 30, 30, 8.0F);
    s.setHeight(20, 20, 21, 21, 30.0F);
    s.config.heightClampPercentile = 1.0F; // Keep the noisy pixel in the height grid
    const VegetationMask mask = s.extract();
    const VegetationHeights heights = VegetationHeightSampler::sample(mask, s.surface, s.config);
    EXPECT_FLOAT_EQ(heights.metricHeight.data[s.index(20, 20)], 30.0F);
    const auto robust = VegetationHeightSampler::robustHeight(mask, heights, 20, 20, 1.5);
    ASSERT_TRUE(robust.has_value());
    EXPECT_FLOAT_EQ(*robust, 8.0F);
    EXPECT_FALSE(VegetationHeightSampler::robustHeight(mask, heights, 2, 2, 0.5).has_value());
}

TEST(VegetationHeightSamplerTest, DisplayScaleFollowsThePresentationAndTheBuildingScale)
{
    const float buildingScale = BuildingReconstructionConfig{}.heightScaleMultiplier;
    EXPECT_FLOAT_EQ(VegetationHeightSampler::displayHeightScale(ScenePresentation::METRIC, buildingScale), 1.0F);
    EXPECT_FLOAT_EQ(VegetationHeightSampler::displayHeightScale(ScenePresentation::FLAT_URBAN, buildingScale),
                    buildingScale);
    const VegetationHeightRecord urban =
        VegetationHeightSampler::record(8.0F, 12.0F, ScenePresentation::FLAT_URBAN, buildingScale);
    EXPECT_FLOAT_EQ(urban.metricHeight, 8.0F);
    EXPECT_FLOAT_EQ(urban.displayHeight, 8.0F * buildingScale);
    EXPECT_FLOAT_EQ(urban.displayHeightScale, buildingScale);
    EXPECT_EQ(urban.presentationMode, "flat_urban");
}

// --- Diagnostics ------------------------------------------------------------

TEST(VegetationDiagnosticsTest, SummaryAndOverlaysReportEveryTier)
{
    Scene s(80, 60);
    s.vegetation(5, 5, 20, 20, 8.0F);
    s.unknown(20, 5, 23, 20, 0.85F, 8.0F);
    fillRectangle(s.footprints, 40, 40, 50, 50, uint8_t{1});
    const VegetationMask mask = s.extract();
    const VegetationHeights heights = VegetationHeightSampler::sample(mask, s.surface, s.config);
    const auto lines = VegetationDiagnostics::summaryLines(mask, heights, 1.0);
    ASSERT_EQ(lines.size(), 5U);
    for (const char* key : {"confirmed_vegetation_pixels=225", "recovered_unknown_pixels=45",
                            "rejected_unknown_spatial_support=", "height_p50=8.00"})
    {
        bool found = false;
        for (const auto& line : lines) found = found || line.find(key) != std::string::npos;
        EXPECT_TRUE(found) << key;
    }
    const Json::Value json = VegetationDiagnostics::toJson(s.config, mask, heights, 1.0);
    EXPECT_EQ(json["stats"]["confirmed_vegetation_pixels"].asUInt64(), 225U);
    EXPECT_EQ(json["height_metric_m"]["source"].asString(), "NDSM");
    EXPECT_FALSE(json["external_geographic_data_used"].asBool());

    const cv::Mat optical(s.height, s.width, CV_8UC3, cv::Scalar(100, 100, 100));
    const cv::Mat after = VegetationDiagnostics::maskOverlay(mask, optical);
    ASSERT_EQ(after.cols, s.width);
    EXPECT_NE(after.at<cv::Vec3b>(10, 10), after.at<cv::Vec3b>(10, 21));  // Confirmed vs recovered colour
    EXPECT_NE(after.at<cv::Vec3b>(45, 45), after.at<cv::Vec3b>(30, 70));  // Protected vs plain
    EXPECT_EQ(VegetationDiagnostics::semanticOverlay(s.semantics, optical).size(), optical.size());
}
