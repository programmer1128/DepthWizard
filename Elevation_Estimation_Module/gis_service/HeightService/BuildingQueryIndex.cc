#include "BuildingQueryIndex.h"

#include <opencv2/imgproc.hpp>

#include <cmath>
#include <stdexcept>

namespace
{
constexpr const char* kSchemaId = "depthwizard.buildings.v1";

std::vector<cv::Point> toCvRing(const std::vector<PixelPoint>& ring)
{
     std::vector<cv::Point> points;
     points.reserve(ring.size());
     for (const PixelPoint& point : ring)
         points.emplace_back(static_cast<int>(std::lround(point.column)),
                             static_cast<int>(std::lround(point.row)));
     return points;
}
} // namespace

BuildingQueryIndex BuildingQueryIndex::build(const BuildingCollection& collection,
                                             const SpatialMetadata& metadata,
                                             float heightScaleMultiplier,
                                             std::string source)
{
     if (metadata.width <= 0 || metadata.height <= 0)
         throw std::invalid_argument("BuildingQueryIndex: invalid raster dimensions");
     if (!std::isfinite(heightScaleMultiplier) || heightScaleMultiplier <= 0.0f)
         throw std::invalid_argument("BuildingQueryIndex: invalid height scale");

     BuildingQueryIndex index;
     index.renderHeightScale = heightScaleMultiplier;
     index.source = std::move(source);
     index.labels.width = metadata.width;
     index.labels.height = metadata.height;
     index.labels.data.assign(static_cast<std::size_t>(metadata.width) * metadata.height, 0.0f);

     for (const BuildingInstance& building : collection.buildings)
     {
         BuildingQueryRecord record;
         record.id = building.buildingId;
         record.heightMeters = building.heightAboveGround / heightScaleMultiplier;
         record.baseElevationMeters = building.representativeBaseElevation;
         record.roofElevationMeters = record.baseElevationMeters + record.heightMeters;
         record.footprintAreaSquareMetres = building.footprintAreaSquareMetres;
         index.buildings[record.id] = record;

         // Rasterize each building on its own so a courtyard cannot erase a
         // neighbour, then stamp its ID where it covers the scene.
         cv::Mat mask(metadata.height, metadata.width, CV_8UC1, cv::Scalar(0));
         if (building.pixelFootprint.outerRing.size() >= 3)
         {
             cv::fillPoly(mask, std::vector<std::vector<cv::Point>>{
                 toCvRing(building.pixelFootprint.outerRing)}, cv::Scalar(1));
             for (const auto& hole : building.pixelFootprint.holes)
                 if (hole.size() >= 3)
                     cv::fillPoly(mask, std::vector<std::vector<cv::Point>>{toCvRing(hole)},
                                  cv::Scalar(0));
         }
         for (const auto& block : building.blocks)
             cv::fillPoly(mask, std::vector<std::vector<cv::Point>>{toCvRing(
                 std::vector<PixelPoint>(block.pixelCorners.begin(), block.pixelCorners.end()))},
                 cv::Scalar(1));

         const float label = static_cast<float>(record.id);
         for (int row = 0; row < mask.rows; ++row)
         {
             const uint8_t* source = mask.ptr<uint8_t>(row);
             float* target = index.labels.data.data() + static_cast<std::size_t>(row) * metadata.width;
             for (int column = 0; column < mask.cols; ++column)
                 if (source[column] != 0) target[column] = label;
         }
     }
     return index;
}

Json::Value BuildingQueryIndex::recordsToJson() const
{
     Json::Value document(Json::objectValue);
     document["schema"] = kSchemaId;
     document["render_height_scale"] = renderHeightScale;
     document["source"] = source;
     Json::Value list(Json::arrayValue);
     for (const auto& [id, record] : buildings)
     {
         Json::Value entry(Json::objectValue);
         entry["id"] = record.id;
         entry["height_m"] = record.heightMeters;
         entry["base_elevation_m"] = record.baseElevationMeters;
         entry["roof_elevation_m"] = record.roofElevationMeters;
         entry["footprint_area_m2"] = record.footprintAreaSquareMetres;
         list.append(entry);
     }
     document["buildings"] = std::move(list);
     return document;
}

BuildingQueryIndex BuildingQueryIndex::recordsFromJson(const Json::Value& document)
{
     if (!document.isObject() || document["schema"].asString() != kSchemaId ||
         !document["buildings"].isArray())
         throw std::runtime_error("BuildingQueryIndex: unsupported building index document");

     BuildingQueryIndex index;
     index.renderHeightScale = document["render_height_scale"].asFloat();
     index.source = document["source"].asString();
     for (const Json::Value& entry : document["buildings"])
     {
         BuildingQueryRecord record;
         record.id = entry["id"].asUInt();
         record.heightMeters = entry["height_m"].asFloat();
         record.baseElevationMeters = entry["base_elevation_m"].asFloat();
         record.roofElevationMeters = entry["roof_elevation_m"].asFloat();
         record.footprintAreaSquareMetres = entry["footprint_area_m2"].asFloat();
         index.buildings[record.id] = record;
     }
     return index;
}

const BuildingQueryRecord* BuildingQueryIndex::find(uint32_t id) const
{
     const auto found = buildings.find(id);
     return found == buildings.end() ? nullptr : &found->second;
}
