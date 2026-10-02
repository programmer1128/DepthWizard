#include "HeightService/BuildingQueryIndex.h"
#include "HeightService/DemAccuracy.h"
#include "HeightService/ScenePixel.h"
#include "BuildingReconstructionTestSupport.h"

#include <gtest/gtest.h>
#include <opencv2/imgcodecs.hpp>

#include <cmath>
#include <limits>

using namespace depthwizard::test;

namespace
{
RasterGrid<float> grid(int width, int height, float value)
{
     return makeConstantGrid(width, height, value);
}

float& at(RasterGrid<float>& g, int column, int row)
{
     return g.data[static_cast<std::size_t>(row) * g.width + column];
}
} // namespace

TEST(DemAccuracy, ReportsScriptMetricsExcludingAnomaliesAndEdges)
{
     // 30x30 with a 10 px edge buffer leaves the central 10x10 = 100 pixels.
     auto generated = grid(30, 30, 0.0F);
     auto reference = grid(30, 30, 0.0F);
     for (int row = 0; row < 30; ++row)
          for (int column = 0; column < 30; ++column)
          {
               at(reference, column, row) = 100.0F + column;      // sloping terrain
               at(generated, column, row) = 100.0F + column + 1.0F; // +1 m bias
          }
     at(generated, 12, 12) += 99.0F;  // one anomaly (+100 m error)
     at(generated, 0, 0) += 500.0F;   // inside the edge buffer: ignored

     const DemAccuracyReport report = DemAccuracy::evaluate(generated, reference);

     EXPECT_EQ(report.raw.pixelCount, 100U);
     EXPECT_EQ(report.anomalyPixelCount, 1U);
     EXPECT_DOUBLE_EQ(report.anomalyPercent, 1.0);
     EXPECT_DOUBLE_EQ(report.maxAbsoluteError, 100.0);
     EXPECT_EQ(report.cleaned.pixelCount, 99U);
     EXPECT_NEAR(report.cleaned.mae, 1.0, 1e-9);
     EXPECT_NEAR(report.cleaned.rmse, 1.0, 1e-9);
     EXPECT_NEAR(report.cleaned.medianAbsoluteError, 1.0, 1e-9);
     EXPECT_DOUBLE_EQ(report.cleaned.withinTolerancePercent, 100.0);
     ASSERT_TRUE(report.cleaned.pearson.has_value());
     EXPECT_NEAR(*report.cleaned.pearson, 1.0, 1e-9);
     // The raw block keeps the anomaly, so the exclusion stays visible.
     EXPECT_NEAR(report.raw.mae, (99.0 + 100.0) / 100.0, 1e-9);
     EXPECT_DOUBLE_EQ(report.generatedMin, 111.0);
     EXPECT_DOUBLE_EQ(report.referenceMax, 119.0);
}

TEST(DemAccuracy, SkipsNonFinitePixelsAndUsesEvenCountMedian)
{
     auto generated = grid(22, 21, 0.0F);
     auto reference = grid(22, 21, 0.0F);
     // Interior is 2 columns x 1 row: errors 1 and 3, median 2.
     at(generated, 10, 10) = 1.0F;
     at(generated, 11, 10) = 3.0F;
     const DemAccuracyReport report = DemAccuracy::evaluate(generated, reference);
     EXPECT_EQ(report.cleaned.pixelCount, 2U);
     EXPECT_NEAR(report.cleaned.medianAbsoluteError, 2.0, 1e-9);
     EXPECT_NEAR(report.cleaned.withinTolerancePercent, 50.0, 1e-9);
     EXPECT_FALSE(report.cleaned.pearson.has_value()); // flat reference

     at(generated, 11, 10) = std::numeric_limits<float>::quiet_NaN();
     EXPECT_EQ(DemAccuracy::evaluate(generated, reference).cleaned.pixelCount, 1U);

     at(generated, 10, 10) = std::numeric_limits<float>::quiet_NaN();
     EXPECT_THROW(DemAccuracy::evaluate(generated, reference), std::runtime_error);
}

TEST(DemAccuracy, RendersDiffMapAsTransparentAwarePng)
{
     auto generated = grid(4, 2, 0.0F);
     auto reference = grid(4, 2, 0.0F);
     at(generated, 0, 0) = 5.0F;   // model higher: red
     at(generated, 1, 0) = -5.0F;  // model lower: blue
     at(generated, 3, 1) = std::numeric_limits<float>::quiet_NaN();
     const std::vector<uint8_t> png = DemAccuracy::renderDifferencePng(generated, reference, 5.0);
     ASSERT_GT(png.size(), 8U);
     EXPECT_EQ(png[1], 'P'); EXPECT_EQ(png[2], 'N'); EXPECT_EQ(png[3], 'G');
     const cv::Mat image = cv::imdecode(png, cv::IMREAD_UNCHANGED);
     ASSERT_EQ(image.type(), CV_8UC4);
     EXPECT_EQ(image.at<cv::Vec4b>(0, 0), cv::Vec4b(0, 0, 255, 255));     // BGRA red
     EXPECT_EQ(image.at<cv::Vec4b>(0, 1), cv::Vec4b(255, 0, 0, 255));     // BGRA blue
     EXPECT_EQ(image.at<cv::Vec4b>(0, 2), cv::Vec4b(255, 255, 255, 255)); // agree: white
     EXPECT_EQ(image.at<cv::Vec4b>(1, 3)[3], 0);                          // invalid: transparent
}

TEST(ScenePixel, ConvertsMetresFromNorthWestCornerToPixels)
{
     const SpatialMetadata metadata = makeProjectedMetadata(100, 50, 0.5, -0.5);
     const auto centre = scenePixelAt(metadata, 25.0, 12.5);
     ASSERT_TRUE(centre);
     EXPECT_EQ(centre->column, 50);
     EXPECT_EQ(centre->row, 25);
     const auto corner = scenePixelAt(metadata, 50.0, 25.0); // exact far edge
     ASSERT_TRUE(corner);
     EXPECT_EQ(corner->column, 99);
     EXPECT_EQ(corner->row, 49);
     EXPECT_FALSE(scenePixelAt(metadata, 60.0, 10.0));
     EXPECT_FALSE(scenePixelAt(metadata, 10.0, -5.0));
}

TEST(BuildingQueryIndex, LabelsFootprintsAndRemovesRenderExaggeration)
{
     const SpatialMetadata metadata = makeProjectedMetadata(20, 20, 0.5, -0.5);
     BuildingInstance building;
     building.buildingId = 7;
     building.heightAboveGround = 45.0F; // rendered with a 2.25 multiplier
     building.representativeBaseElevation = 12.0F;
     building.footprintAreaSquareMetres = 25.0F;
     building.pixelFootprint.outerRing = {{5, 5}, {15, 5}, {15, 15}, {5, 15}};
     BuildingCollection collection;
     collection.buildings.push_back(building);

     const BuildingQueryIndex index =
         BuildingQueryIndex::build(collection, metadata, 2.25F, "sat2lod2");

     const BuildingQueryRecord* record = index.find(7);
     ASSERT_NE(record, nullptr);
     EXPECT_FLOAT_EQ(record->heightMeters, 20.0F);
     EXPECT_FLOAT_EQ(record->roofElevationMeters, 32.0F);
     EXPECT_FLOAT_EQ(index.labels.data[10 * 20 + 10], 7.0F);
     EXPECT_FLOAT_EQ(index.labels.data[2 * 20 + 2], 0.0F);
     EXPECT_EQ(index.find(8), nullptr);

     const BuildingQueryIndex restored = BuildingQueryIndex::recordsFromJson(index.recordsToJson());
     ASSERT_NE(restored.find(7), nullptr);
     EXPECT_FLOAT_EQ(restored.find(7)->heightMeters, 20.0F);
     EXPECT_FLOAT_EQ(restored.renderHeightScale, 2.25F);
     EXPECT_EQ(restored.source, "sat2lod2");
     EXPECT_THROW(BuildingQueryIndex::recordsFromJson(Json::Value(Json::objectValue)),
                  std::runtime_error);
}
