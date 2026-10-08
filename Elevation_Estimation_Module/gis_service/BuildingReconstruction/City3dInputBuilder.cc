#include "City3dInputBuilder.h"

#include <json/json.h>

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <sys/stat.h>

namespace fs = std::filesystem;

ProjectedPoint City3dInputBuilder::pixelCentre(int column, int row, const SpatialMetadata& metadata)
{
     // Raster samples describe pixel centres: (column + 0.5, row + 0.5).
     return pixelEdge(PixelPoint{column + 0.5, row + 0.5}, metadata);
}

ProjectedPoint City3dInputBuilder::pixelEdge(const PixelPoint& point, const SpatialMetadata& metadata)
{
     // Footprint vertices are pixel-edge coordinates: no half-pixel shift.
     const auto& gt = metadata.geoTransform;
     return {gt[0] + point.column * gt[1] + point.row * gt[2],
             gt[3] + point.column * gt[4] + point.row * gt[5]};
}

City3dCandidate City3dInputBuilder::analyse(
     const BuildingInstance& building,
     const RasterGrid<int32_t>& labels,
     const SemanticScene& semantics,
     const GeoreferencedSurfaceBundle& surface,
     const RasterGrid<float>& ndsm,
     const SpatialMetadata& metadata,
     const City3dConfig& config)
{
     City3dCandidate candidate;
     candidate.buildingId = building.buildingId;
     candidate.footprintAreaSquareMetres = building.footprintAreaSquareMetres;
     const auto reject = [&](const char* reason)
     {
          candidate.reason = reason;
          candidate.points.clear();
          return candidate;
     };

     const auto& gt = metadata.geoTransform;
     const double determinant = gt[1] * gt[5] - gt[2] * gt[4];
     if (!metadata.isGeoreferenced || metadata.projectionRef.empty() || !std::isfinite(determinant) ||
         determinant == 0.0)
          return reject("not_georeferenced");
     const auto sized = [&](const auto& grid)
     { return grid.width == metadata.width && grid.height == metadata.height && grid.isValid(); };
     if (!sized(labels) || !sized(surface.dtm) || !sized(ndsm) || !sized(surface.validMask))
          return reject("rasters_unavailable");
     if (building.pixelFootprint.outerRing.size() < 3) return reject("invalid_footprint");
     if (!building.pixelFootprint.holes.empty()) return reject("courtyard_unsupported");
     if (building.reconstructedShell) return reject("already_has_shell");
     if (building.footprintAreaSquareMetres < config.minimumFootprintAreaSquareMetres)
          return reject("too_small");
     if (building.footprintAreaSquareMetres > config.maximumFootprintAreaSquareMetres)
          return reject("too_large_for_budget");

     // Footprint centroid as the reversible local origin; ground = official base.
     double sumE = 0.0;
     double sumN = 0.0;
     double minColumn = 1e300, maxColumn = -1e300, minRow = 1e300, maxRow = -1e300;
     for (const PixelPoint& vertex : building.pixelFootprint.outerRing)
     {
          const ProjectedPoint projected = pixelEdge(vertex, metadata);
          sumE += projected.easting;
          sumN += projected.northing;
          minColumn = std::min(minColumn, vertex.column);
          maxColumn = std::max(maxColumn, vertex.column);
          minRow = std::min(minRow, vertex.row);
          maxRow = std::max(maxRow, vertex.row);
     }
     const double count = static_cast<double>(building.pixelFootprint.outerRing.size());
     candidate.originEasting = sumE / count;
     candidate.originNorthing = sumN / count;
     candidate.originElevation = building.representativeBaseElevation;

     const int width = metadata.width;
     const int height = metadata.height;
     const int firstColumn = std::max(1, static_cast<int>(std::floor(minColumn)));
     const int lastColumn = std::min(width - 2, static_cast<int>(std::ceil(maxColumn)));
     const int firstRow = std::max(1, static_cast<int>(std::floor(minRow)));
     const int lastRow = std::min(height - 2, static_cast<int>(std::ceil(maxRow)));
     const int32_t id = static_cast<int32_t>(building.buildingId);
     const bool hasProbability = sized(semantics.buildingProbability);
     const double columnSpacing = std::hypot(gt[1], gt[4]);
     const double rowSpacing = std::hypot(gt[2], gt[5]);

     std::vector<float> heights;
     for (int row = firstRow; row <= lastRow; ++row)
     {
          for (int column = firstColumn; column <= lastColumn; ++column)
          {
               const std::size_t index = static_cast<std::size_t>(row) * width + column;
               if (labels.data[index] != id) continue;
               bool interior = true; // One-pixel erosion: no mixed roof/wall/ground samples
               for (int dr = -1; dr <= 1 && interior; ++dr)
                    for (int dc = -1; dc <= 1 && interior; ++dc)
                         interior = labels.data[static_cast<std::size_t>(row + dr) * width + column + dc] == id;
               if (!interior || surface.validMask.data[index] == 0) continue;
               const float ground = surface.dtm.data[index];
               const float aboveGround = ndsm.data[index];
               if (!std::isfinite(ground) || !std::isfinite(aboveGround)) continue;
               if (aboveGround < config.minimumRoofHeightMetres) continue;
               if (hasProbability && semantics.buildingProbability.data[index] < config.minimumBuildingProbability)
                    continue;
               // Central-difference slope of the metric nDSM (interior pixels only).
               const float east = ndsm.data[index + 1], west = ndsm.data[index - 1];
               const float south = ndsm.data[index + width], north = ndsm.data[index - width];
               if (!std::isfinite(east) || !std::isfinite(west) || !std::isfinite(south) || !std::isfinite(north))
                    continue;
               const double gx = (east - west) / (2.0 * columnSpacing);
               const double gy = (south - north) / (2.0 * rowSpacing);
               if (std::hypot(gx, gy) > config.maximumPointSlope) continue;
               const ProjectedPoint centre = pixelCentre(column, row, metadata);
               candidate.points.push_back({centre.easting, centre.northing,
                                           static_cast<double>(ground) + aboveGround});
               heights.push_back(aboveGround);
          }
     }
     if (candidate.points.size() < config.minimumPoints) return reject("insufficient_points");
     if (candidate.points.size() > config.maximumPoints) return reject("too_large_for_budget");

     for (const ProjectedVertex3D& point : candidate.points)
          candidate.maximumLocalHeightMetres =
              std::max(candidate.maximumLocalHeightMetres, point.elevation - candidate.originElevation);
     std::sort(heights.begin(), heights.end());
     const auto percentile = [&](double fraction)
     { return heights[static_cast<std::size_t>(fraction * (heights.size() - 1))]; };
     candidate.heightSpreadMetres = percentile(0.9) - percentile(0.1);
     bool pitched = false;
     for (const auto& block : building.blocks) pitched = pitched || block.roof.type != RoofType::FLAT;
     if (!pitched && candidate.heightSpreadMetres < config.minimumHeightSpreadMetres)
          return reject("flat_roof");

     candidate.eligible = true;
     return candidate;
}

bool City3dInputBuilder::writeJob(
     const City3dCandidate& candidate,
     const BuildingInstance& building,
     const SpatialMetadata& metadata,
     const City3dConfig& config,
     const std::string& jobId,
     const fs::path& directory,
     std::string& error)
{
     std::error_code code;
     fs::create_directories(directory, code);
     if (code || ::chmod(directory.c_str(), 0700) != 0)
     {
          error = "cannot create " + directory.string();
          return false;
     }

     char line[128];
     {
          std::ofstream ply(directory / "roof_points.ply");
          ply << "ply\nformat ascii 1.0\ncomment DepthWizard monocular-derived pseudo point cloud\n"
              << "element vertex " << candidate.points.size()
              << "\nproperty float x\nproperty float y\nproperty float z\nend_header\n";
          for (const ProjectedVertex3D& point : candidate.points)
          {
               std::snprintf(line, sizeof(line), "%.4f %.4f %.4f\n",
                             point.easting - candidate.originEasting,
                             point.northing - candidate.originNorthing,
                             point.elevation - candidate.originElevation);
               ply << line;
          }
          if (!ply) error = "cannot write the point cloud";
     }
     {
          std::ofstream obj(directory / "footprint.obj");
          obj << "# DepthWizard native footprint (pixel-edge vertices), local metres\n";
          for (const PixelPoint& vertex : building.pixelFootprint.outerRing)
          {
               const ProjectedPoint projected = pixelEdge(vertex, metadata);
               std::snprintf(line, sizeof(line), "v %.4f %.4f 0\n",
                             projected.easting - candidate.originEasting,
                             projected.northing - candidate.originNorthing);
               obj << line;
          }
          obj << "f";
          for (std::size_t index = 1; index <= building.pixelFootprint.outerRing.size(); ++index)
               obj << " " << index;
          obj << "\n";
          if (!obj) error = "cannot write the footprint";
     }
     if (!error.empty()) return false;

     const double spacing = std::hypot(metadata.geoTransform[1], metadata.geoTransform[4]);
     const double timeoutSeconds = config.timeout.count() / 1000.0;
     Json::Value request(Json::objectValue);
     request["schema"] = "depthwizard.city3d-request.v1";
     request["job_id"] = jobId + "-b" + std::to_string(building.buildingId);
     request["building_id"] = building.buildingId;
     request["point_cloud"] = "roof_points.ply";
     request["footprint"] = "footprint.obj";
     Json::Value& frame = request["coordinate_frame"];
     frame["origin_easting"] = candidate.originEasting;
     frame["origin_northing"] = candidate.originNorthing;
     frame["origin_elevation"] = candidate.originElevation;
     frame["horizontal_crs"] = metadata.projectionRef;
     frame["axis_convention"] = "X_EAST_Y_NORTH_Z_UP";
     Json::Value& provenance = request["input_provenance"];
     provenance["point_source"] = "monocular_derived_dsm";
     provenance["footprint_source"] = "depthwizard_native_semantics";
     provenance["external_lidar_used"] = false;
     provenance["external_building_database_used"] = false;
     Json::Value& worker = request["config"];
     worker["point_spacing_metres"] = spacing;
     worker["neighbour_radius_metres"] = std::max(1.0, 2.5 * spacing);
     worker["maximum_plane_distance_metres"] = config.maximumPlaneDistanceMetres;
     worker["maximum_plane_angle_degrees"] = config.maximumPlaneAngleDegrees;
     worker["height_map_pixel_size_metres"] = config.heightMapPixelSizeMetres;
     worker["minimum_plane_points"] = config.minimumPlanePoints;
     worker["maximum_candidate_faces"] = config.maximumCandidateFaces;
     worker["solver_timeout_seconds"] = std::max(1.0, 0.6 * timeoutSeconds);
     // The worker commits its own timeout manifest just before the hard kill.
     worker["job_timeout_seconds"] = std::max(1.0, timeoutSeconds - 1.0);
     Json::StreamWriterBuilder writer;
     writer["indentation"] = "  ";
     std::ofstream(directory / "request.json") << Json::writeString(writer, request) << "\n";
     return true;
}
