// Offline vegetation-mask report from a finished job's diagnostic rasters.
//
// Usage: vegetation_mask_report <diagnostics/uuid> <building-footprints.tif>
//                               <optical.tif> <output-dir> [flat_urban|metric]
//
// Inputs: final_semantic_class.tif, vegetation/building/road_probability.tif,
// dtm.tif and fused_ndsm.tif (surface.ndsm) from the job's diagnostics, the
// job's buildings_<uuid>.tif (footprint fill; GDAL path, /vsis3/ allowed) and
// the uploaded GeoTIFF for the overlay background. Water probability is not
// saved by the diagnostics, so water is excluded by class only, and the valid
// mask is the finite DTM (SurfaceFusionService writes NaN where invalid).
// Writes class4_only/ and with_recovery_pNN/ (the ablation; NN is the
// UNKNOWN probability threshold in percent) into the output dir.

#include "BuildingReconstruction/BuildingReconstructionConfig.h"
#include "MeshMapping/LocalFrameTransformer.h"
#include "Vegetation/VegetationCanopyBuilder.h"
#include "Vegetation/VegetationClassifier.h"
#include "Vegetation/VegetationDiagnostics.h"
#include "Vegetation/VegetationTreeCandidateGenerator.h"
#include "Vegetation/VegetationTreeDiagnostics.h"
#include "Vegetation/VegetationExtractor.h"
#include "Vegetation/VegetationHeightSampler.h"

#include <gdal_priv.h>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>

#include <chrono>
#include <fstream>
#include <cmath>
#include <filesystem>
#include <iostream>
#include <stdexcept>

namespace
{
template <typename T>
RasterGrid<T> readBand(const std::string& path, int band, GDALDataType type, SpatialMetadata* metadata = nullptr)
{
     GDALDataset* dataset = static_cast<GDALDataset*>(GDALOpen(path.c_str(), GA_ReadOnly));
     if (dataset == nullptr) throw std::runtime_error("cannot open " + path);
     RasterGrid<T> grid;
     grid.width = dataset->GetRasterXSize();
     grid.height = dataset->GetRasterYSize();
     grid.data.resize(static_cast<std::size_t>(grid.width) * grid.height);
     if (dataset->GetRasterBand(band)->RasterIO(GF_Read, 0, 0, grid.width, grid.height, grid.data.data(),
                                                grid.width, grid.height, type, 0, 0) != CE_None)
          throw std::runtime_error("cannot read " + path);
     if (metadata != nullptr)
     {
          metadata->width = grid.width;
          metadata->height = grid.height;
          dataset->GetGeoTransform(metadata->geoTransform.data());
          metadata->projectionRef = dataset->GetProjectionRef();
          metadata->isGeoreferenced = !metadata->projectionRef.empty();
          metadata->pixelSizeX = std::hypot(metadata->geoTransform[1], metadata->geoTransform[4]);
          metadata->pixelSizeY = std::hypot(metadata->geoTransform[2], metadata->geoTransform[5]);
     }
     GDALClose(dataset);
     return grid;
}
} // namespace

int main(int argc, char** argv)
{
     if (argc < 5)
     {
          std::cerr << "usage: vegetation_mask_report <diagnostics/uuid> <footprints.tif> <optical.tif> <out> "
                       "[flat_urban|metric]\n";
          return 2;
     }
     GDALAllRegister();
     const std::filesystem::path diagnostics = argv[1];
     const std::filesystem::path out = argv[4];
     const ScenePresentation presentation = argc > 5 && std::string(argv[5]) == "flat_urban"
         ? ScenePresentation::FLAT_URBAN : ScenePresentation::METRIC;
     try
     {
          SpatialMetadata metadata;
          const auto classes = readBand<uint8_t>((diagnostics / "final_semantic_class.tif").string(), 1, GDT_Byte, &metadata);
          const int width = metadata.width, height = metadata.height;
          SemanticScene semantics;
          semantics.finalClassMap.width = width;
          semantics.finalClassMap.height = height;
          for (uint8_t value : classes.data) semantics.finalClassMap.data.push_back(static_cast<SemanticClass>(value));
          semantics.vegetationProbability = readBand<float>((diagnostics / "vegetation_probability.tif").string(), 1, GDT_Float32);
          semantics.buildingProbability = readBand<float>((diagnostics / "building_probability.tif").string(), 1, GDT_Float32);
          semantics.roadProbability = readBand<float>((diagnostics / "road_probability.tif").string(), 1, GDT_Float32);
          semantics.waterProbability.width = width;
          semantics.waterProbability.height = height;
          semantics.waterProbability.data.assign(static_cast<std::size_t>(width) * height, 0.0f);

          GeoreferencedSurfaceBundle surface;
          surface.spatialMetadata = metadata;
          surface.dtm = readBand<float>((diagnostics / "dtm.tif").string(), 1, GDT_Float32);
          surface.ndsm = readBand<float>((diagnostics / "fused_ndsm.tif").string(), 1, GDT_Float32);
          surface.validMask.width = width;
          surface.validMask.height = height;
          for (float value : surface.dtm.data) surface.validMask.data.push_back(std::isfinite(value) ? 1 : 0);

          const auto labels = readBand<float>(argv[2], 1, GDT_Float32);
          RasterGrid<uint8_t> footprints;
          footprints.width = width;
          footprints.height = height;
          for (float value : labels.data) footprints.data.push_back(value > 0.0f ? 1 : 0);

          cv::Mat optical(height, width, CV_8UC3);
          {
               const auto red = readBand<uint8_t>(argv[3], 1, GDT_Byte);
               const auto green = readBand<uint8_t>(argv[3], 2, GDT_Byte);
               const auto blue = readBand<uint8_t>(argv[3], 3, GDT_Byte);
               for (std::size_t i = 0; i < red.data.size(); ++i)
                    optical.at<cv::Vec3b>(static_cast<int>(i / width), static_cast<int>(i % width)) =
                        cv::Vec3b(blue.data[i], green.data[i], red.data[i]);
          }

          const float buildingScale = BuildingReconstructionConfig{}.heightScaleMultiplier;
          for (const bool recover : {false, true})
          {
               // Thresholds come from the central parser (DEPTHWIZARD_VEGETATION_*).
               VegetationConfig config = VegetationConfig::fromEnvironment();
               for (const std::string& warning : config.warnings) std::cerr << "warning: " << warning << "\n";
               config.mode = VegetationMode::ON;
               config.recoverUnknown = recover;
               const auto started = std::chrono::steady_clock::now();
               const VegetationMask mask = VegetationExtractor::extract(semantics, surface, footprints, metadata, config);
               const VegetationHeights heights = VegetationHeightSampler::sample(mask, surface, config);
               const double ms = std::chrono::duration<double, std::milli>(std::chrono::steady_clock::now() - started).count();
               const std::string name = recover
                   ? "with_recovery_p" + std::to_string(static_cast<int>(std::lround(config.unknownProbability * 100)))
                   : "class4_only";
               std::cout << "== " << name << " (display_height_scale="
                         << VegetationHeightSampler::displayHeightScale(presentation, buildingScale) << ")\n";
               for (const std::string& line : VegetationDiagnostics::summaryLines(mask, heights, ms))
                    std::cout << line << "\n";
               if (!VegetationDiagnostics::write(out / name, config, semantics, mask, heights, optical, ms))
                    throw std::runtime_error("cannot write diagnostics to " + (out / name).string());
               if (!recover) continue;

               // Component measurements behind the dense/isolated defaults.
               cv::Mat binary(height, width, CV_8U);
               for (std::size_t i = 0; i < mask.tier.data.size(); ++i) binary.data[i] = mask.tier.data[i] ? 1 : 0;
               cv::Mat labels, stats, centroids, distance, coverage;
               const int count = cv::connectedComponentsWithStats(binary, labels, stats, centroids, 8, CV_32S);
               cv::distanceTransform(binary, distance, cv::DIST_L2, cv::DIST_MASK_PRECISE);
               const int rx = std::max(1, static_cast<int>(std::lround(config.denseCoverageRadiusMetres / mask.scale.columnSpacingMetres)));
               const int ry = std::max(1, static_cast<int>(std::lround(config.denseCoverageRadiusMetres / mask.scale.rowSpacingMetres)));
               cv::boxFilter(binary, coverage, CV_32F, cv::Size(2 * rx + 1, 2 * ry + 1), cv::Point(-1, -1), true,
                             cv::BORDER_CONSTANT);
               std::vector<double> maxDistance(count, 0.0), coverageSum(count, 0.0);
               for (int y = 0; y < height; ++y)
                    for (int x = 0; x < width; ++x)
                    {
                         const int label = labels.at<int>(y, x);
                         if (!label) continue;
                         maxDistance[label] = std::max(maxDistance[label], static_cast<double>(distance.at<float>(y, x)));
                         coverageSum[label] += coverage.at<float>(y, x);
                    }
               std::vector<int> order(static_cast<std::size_t>(count - 1));
               for (int label = 1; label < count; ++label) order[label - 1] = label;
               std::sort(order.begin(), order.end(), [&](int a, int b)
                         { return stats.at<int>(a, cv::CC_STAT_AREA) > stats.at<int>(b, cv::CC_STAT_AREA); });
               const double finer = std::min(mask.scale.columnSpacingMetres, mask.scale.rowSpacingMetres);
               std::cout << "[Components] " << count - 1 << " mask components (area m2, width m, mean coverage):";
               for (std::size_t k = 0; k < order.size() && k < 20; ++k)
               {
                    const int label = order[k];
                    const int area = stats.at<int>(label, cv::CC_STAT_AREA);
                    std::cout << " (" << std::lround(area * mask.scale.pixelAreaSquareMetres()) << ", "
                              << std::lround(2.0 * maxDistance[label] * finer * 10) / 10.0 << ", "
                              << std::lround(coverageSum[label] / area * 100) / 100.0 << ")";
               }
               std::cout << "\n";
               const VegetationClassification classes = VegetationClassifier::classify(mask, config);
               VegetationCanopyMesh noCanopy;
               for (const std::string& line : VegetationDiagnostics::canopyLines(classes, noCanopy))
                    if (line.find("dense_components") != std::string::npos) std::cout << line << "\n";
               cv::imwrite((out / name / "vegetation_classes.png").string(),
                           VegetationDiagnostics::classificationOverlay(classes, mask, optical));

               // Canopy, in the pipeline's local frame, as raw arrays for the
               // offline renderer (positions, normals, UVs, indices).
               VegetationCanopyInput input;
               input.mask = &mask;
               input.classification = &classes;
               input.heights = &heights;
               input.config = config;
               input.buildingDisplayHeightScale = buildingScale;
               TerrainMeshConfig terrainConfig;
               if (presentation == ScenePresentation::FLAT_URBAN)
                    terrainConfig.elevationSource = TerrainElevationSource::FLAT_PRESENTATION;
               const LocalSceneFrame frame = LocalFrameTransformer::create(metadata, surface);
               const VegetationCanopyMesh canopy =
                   VegetationCanopyBuilder::build(input, surface, metadata, frame, terrainConfig, presentation);
               for (const std::string& line : VegetationDiagnostics::canopyLines(classes, canopy))
                    if (line.find("canopy_vertices") != std::string::npos) std::cout << line << "\n";
               const auto dump = [&](const char* file, const void* data, std::size_t bytes)
               {
                    std::ofstream stream(out / name / file, std::ios::binary);
                    stream.write(static_cast<const char*>(data), static_cast<std::streamsize>(bytes));
               };
               // Stage 4 tree candidates (recovery nDSM: the job's corrected
               // nDSM before semantic suppression).
               RasterGrid<float> recoveryNdsm;
               if (std::filesystem::exists(diagnostics / "reconstruction_ndsm.tif"))
                    recoveryNdsm = readBand<float>((diagnostics / "reconstruction_ndsm.tif").string(), 1, GDT_Float32);
               VegetationTreeInput treeInput;
               treeInput.mask = &mask;
               treeInput.classification = &classes;
               treeInput.heights = &heights;
               treeInput.semantics = &semantics;
               treeInput.surface = &surface;
               treeInput.metadata = &metadata;
               treeInput.frame = frame;
               treeInput.terrainConfig = terrainConfig;
               treeInput.presentation = presentation;
               treeInput.buildingDisplayHeightScale = buildingScale;
               treeInput.config = config;
               treeInput.recoveryNdsm = recoveryNdsm.isValid() ? &recoveryNdsm : nullptr;
               const VegetationTreeCandidates trees = VegetationTreeCandidateGenerator::generate(treeInput);
               for (const std::string& line : VegetationTreeDiagnostics::summaryLines(trees)) std::cout << line << "\n";
               VegetationTreeDiagnostics::write(out / name, trees, mask.scale, surface.ndsm, heights.ceilingMetres, optical);
               if (!canopy.empty())
               {
                    const MeshPrimitive& p = canopy.primitive;
                    dump("canopy_pos.bin", p.positions.data(), p.positions.size() * sizeof(float));
                    dump("canopy_uv.bin", p.uvs->data(), p.uvs->size() * sizeof(float));
                    dump("canopy_idx.bin", p.indices.data(), p.indices.size() * sizeof(uint32_t));
               }
          }
     }
     catch (const std::exception& error)
     {
          std::cerr << "vegetation_mask_report: " << error.what() << "\n";
          return 1;
     }
     return 0;
}
