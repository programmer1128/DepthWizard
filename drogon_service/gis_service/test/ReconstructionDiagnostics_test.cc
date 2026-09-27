#include <gtest/gtest.h>
#include "FileGenerators/ReconstructionDiagnosticsWriter.h"
#include "BuildingReconstructionTestSupport.h"
#include <gdal_priv.h>
#include <ogr_spatialref.h>
#include <json/json.h>
#include <fstream>
#include <cstdlib>

TEST(ReconstructionDiagnosticsTest, WritesGeoreferencedSnapshotsAndPhysicalHeights)
{
    using namespace depthwizard::test;
    GDALAllRegister();
    char name[] = "/tmp/depthwizard-diagnostics-XXXXXX";
    const char* created = mkdtemp(name);
    ASSERT_NE(created, nullptr);
    struct Cleanup { std::filesystem::path p; ~Cleanup() { std::filesystem::remove_all(p); } } cleanup{created};
    auto surface = makeSurface(4, 4, 100, 12);
    OGRSpatialReference srs; srs.importFromEPSG(32618);
    char* wkt = nullptr; srs.exportToWkt(&wkt);
    surface.spatialMetadata.projectionRef = wkt; CPLFree(wkt);
    ReconstructionDiagnosticPayload d;
    d.buildingProbability = makeConstantGrid(4, 4, 0.9F);
    d.rawNdsm = makeConstantGrid(4, 4, 12.0F);
    d.reconstructionNdsm = makeConstantGrid(4, 4, 11.75F);
    d.stages.candidateMask = makeConstantGrid<uint8_t>(4, 4, 255);
    d.stages.cleanedMask = makeConstantGrid<uint8_t>(4, 4, 1);
    d.stages.instanceLabels = makeConstantGrid<int32_t>(4, 4, 1);
    d.presentationMode = "flat_urban";
    BuildingInstance b; b.buildingId = 1; b.heightAboveGround = 12;
    b.representativeBaseElevation = 100; b.roofElevation = 112;
    DecomposedBuildingBlock block;
    block.footprintAreaSquareMetres = 20;
    block.roof.type = RoofType::GABLE;
    block.roof.eaveHeightAboveGround = 10;
    block.roof.ridgeHeightAboveGround = 12;
    block.roof.confidence = 0.8F;
    b.blocks.push_back(block);
    d.buildings.lod2BlockCount = 1;
    d.buildings.gableRoofBlockCount = 1;
    d.buildings.buildings.push_back(b); d.emittedBuildings = 1;
    const auto folder = ReconstructionDiagnosticsWriter::write(created, "abc-123", d, surface);
    Json::Value summary; std::ifstream input(folder / "summary.json"); input >> summary;
    EXPECT_EQ(summary["presentation_mode"].asString(), "flat_urban");
    EXPECT_FALSE(summary["scientific_rasters_flattened"].asBool());
    EXPECT_FLOAT_EQ(summary["buildings"][0]["height_agl_m"].asFloat(), 12);
    EXPECT_EQ(summary["lod2_blocks"].asUInt64(), 1U);
    EXPECT_EQ(summary["gable_roof_blocks"].asUInt64(), 1U);
    ASSERT_EQ(summary["buildings"][0]["lod2_blocks"].size(), 1U);
    EXPECT_EQ(summary["buildings"][0]["lod2_blocks"][0]["roof_type"].asString(), "gable");
    auto* ds = static_cast<GDALDataset*>(GDALOpen((folder / "dtm.tif").c_str(), GA_ReadOnly));
    ASSERT_NE(ds, nullptr);
    std::vector<float> values(16);
    EXPECT_EQ(ds->GetRasterBand(1)->RasterIO(GF_Read, 0, 0, 4, 4, values.data(), 4, 4, GDT_Float32, 0, 0), CE_None);
    EXPECT_EQ(values, std::vector<float>(16, 100));
    double transform[6]; EXPECT_EQ(ds->GetGeoTransform(transform), CE_None);
    EXPECT_DOUBLE_EQ(transform[0], surface.spatialMetadata.geoTransform[0]);
    GDALClose(ds);
    EXPECT_TRUE(std::filesystem::exists(folder / "instance_labels.tif"));
    ds = static_cast<GDALDataset*>(GDALOpen(
        (folder / "reconstruction_ndsm.tif").c_str(), GA_ReadOnly));
    ASSERT_NE(ds, nullptr);
    EXPECT_EQ(ds->GetRasterBand(1)->RasterIO(GF_Read, 0, 0, 4, 4,
        values.data(), 4, 4, GDT_Float32, 0, 0), CE_None);
    EXPECT_EQ(values, std::vector<float>(16, 11.75F));
    GDALClose(ds);
    EXPECT_THROW(ReconstructionDiagnosticsWriter::write(created, "../bad", d, surface), std::invalid_argument);
}
