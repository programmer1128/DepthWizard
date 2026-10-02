#include "HeightOrchestratorService.h"
#include "DemAccuracy.h"
#include "HeightRasterStore.h"
#include "ReferenceDemService.h"
#include "../RasterProcessor/RasterProcessor.h"

#include <cpl_vsi.h>
#include <drogon/utils/Utilities.h>
#include <gdal_priv.h>
#include <ogr_spatialref.h>

#include <algorithm>
#include <cmath>
#include <list>
#include <memory>
#include <mutex>

namespace
{
// Margin around the scene so the bilinear warp has reference data up to the
// scene edge (about 100 m).
constexpr double kReferenceMarginDegrees = 0.001;
constexpr std::size_t kCachedComparisons = 4;

std::optional<float> readOptional(const std::string& uuid, const std::string& product,
                                  RasterPixel pixel)
{
     try
     {
         GDALDatasetPtr dataset = HeightRasterStore::open(uuid, product);
         return HeightRasterStore::readPixel(*dataset, pixel);
     }
     catch (const HeightDataUnavailable&)
     {
         return std::nullopt;
     }
}

Json::Value pixelJson(RasterPixel pixel)
{
     Json::Value value(Json::objectValue);
     value["column"] = pixel.column;
     value["row"] = pixel.row;
     return value;
}

Json::Value optionalNumber(const std::optional<double>& value)
{
     return value && std::isfinite(*value) ? Json::Value(*value) : Json::Value(Json::nullValue);
}

GeoBounds sceneBounds(const SpatialMetadata& metadata)
{
     OGRSpatialReference source;
     if (source.SetFromUserInput(metadata.projectionRef.c_str()) != OGRERR_NONE)
         throw std::runtime_error("Height raster has an unreadable CRS");
     OGRSpatialReference target;
     target.importFromEPSG(4326);
     target.SetAxisMappingStrategy(OAMS_TRADITIONAL_GIS_ORDER); // x = lon, y = lat
     std::unique_ptr<OGRCoordinateTransformation, void (*)(OGRCoordinateTransformation*)>
         transform(OGRCreateCoordinateTransformation(&source, &target),
                   OGRCoordinateTransformation::DestroyCT);
     if (!transform)
         throw std::runtime_error("Cannot transform the scene extent to WGS84");

     const auto& gt = metadata.geoTransform;
     GeoBounds bounds{1e9, 1e9, -1e9, -1e9};
     for (const auto& [column, row] : {std::pair{0, 0}, {metadata.width, 0},
                                        {0, metadata.height}, {metadata.width, metadata.height}})
     {
         double x = gt[0] + column * gt[1] + row * gt[2];
         double y = gt[3] + column * gt[4] + row * gt[5];
         if (!transform->Transform(1, &x, &y))
             throw std::runtime_error("Cannot transform the scene extent to WGS84");
         bounds.minLon = std::min(bounds.minLon, x);
         bounds.maxLon = std::max(bounds.maxLon, x);
         bounds.minLat = std::min(bounds.minLat, y);
         bounds.maxLat = std::max(bounds.maxLat, y);
     }
     bounds.minLon -= kReferenceMarginDegrees;
     bounds.minLat -= kReferenceMarginDegrees;
     bounds.maxLon += kReferenceMarginDegrees;
     bounds.maxLat += kReferenceMarginDegrees;
     return bounds;
}

// Warps the downloaded reference onto the generated pixel grid (bilinear),
// like the validation script's rasterio.reproject.
RasterGrid<float> warpReference(const ReferenceDem& reference, const SpatialMetadata& metadata)
{
     const std::string path = "/vsimem/reference_" + drogon::utils::getUuid() + ".tif";
     VSILFILE* file = VSIFileFromMemBuffer(path.c_str(),
         const_cast<GByte*>(reference.bytes.data()), reference.bytes.size(), FALSE);
     if (!file) throw std::runtime_error("Cannot stage the reference DEM in memory");
     VSIFCloseL(file);
     try
     {
         GDALDatasetPtr dataset(static_cast<GDALDataset*>(GDALOpen(path.c_str(), GA_ReadOnly)));
         if (!dataset)
             throw ReferenceDemUnavailable(
                 reference.dataset + " response is not a GeoTIFF: " +
                 std::string(reference.bytes.begin(),
                             reference.bytes.begin() + std::min<std::size_t>(reference.bytes.size(), 200)));
         RasterGrid<float> warped = RasterProcessor::warpDemToScene(dataset, metadata);
         dataset.reset();
         VSIUnlink(path.c_str());
         return warped;
     }
     catch (...)
     {
         VSIUnlink(path.c_str());
         throw;
     }
}

// One scene compared against one reference dataset. Scene-wide metrics do
// not depend on the clicked point, so repeated clicks reuse them.
struct ComparisonScene
{
     SpatialMetadata metadata;
     RasterGrid<float> generated;
     RasterGrid<float> reference;
     DemAccuracyReport report;
     DemAccuracyOptions options;
     std::string dataset;
     std::string differencePngBase64;
     double differenceRange{0.0};
};

std::mutex cacheMutex;
std::list<std::pair<std::string, std::shared_ptr<const ComparisonScene>>> comparisonCache;

std::shared_ptr<const ComparisonScene> cachedComparison(const std::string& key)
{
     std::lock_guard lock(cacheMutex);
     for (auto entry = comparisonCache.begin(); entry != comparisonCache.end(); ++entry)
         if (entry->first == key)
         {
             comparisonCache.splice(comparisonCache.begin(), comparisonCache, entry);
             return entry->second;
         }
     return nullptr;
}

void storeComparison(const std::string& key, std::shared_ptr<const ComparisonScene> scene)
{
     std::lock_guard lock(cacheMutex);
     comparisonCache.emplace_front(key, std::move(scene));
     if (comparisonCache.size() > kCachedComparisons) comparisonCache.pop_back();
}

Json::Value statisticsJson(const DemErrorStatistics& statistics)
{
     Json::Value value(Json::objectValue);
     value["rmse"] = statistics.rmse;
     value["mae"] = statistics.mae;
     value["pearson_correlation"] = optionalNumber(statistics.pearson);
     value["median_absolute_error"] = statistics.medianAbsoluteError;
     value["accuracy_percentage"] = statistics.withinTolerancePercent;
     value["valid_pixels_count"] = static_cast<Json::UInt64>(statistics.pixelCount);
     return value;
}
} // namespace

drogon::Task<Json::Value> HeightOrchestratorService::processSingleHeight(
     const std::string& uuid, double x, double y, std::optional<uint32_t> featureId)
{
     GDALDatasetPtr heights = HeightRasterStore::open(uuid, "heights");
     const SpatialMetadata metadata = HeightRasterStore::metadataOf(*heights);
     const auto pixel = HeightRasterStore::pixelAt(metadata, x, y);
     if (!pixel)
         throw std::invalid_argument("The clicked point lies outside this scene.");

     Json::Value result(Json::objectValue);
     result["status"] = "success";
     result["uuid"] = uuid;
     result["pixel"] = pixelJson(*pixel);

     const std::optional<float> surface = HeightRasterStore::readPixel(*heights, *pixel);
     heights.reset();
     const std::optional<float> ground = readOptional(uuid, "dtm", *pixel);
     const std::optional<float> aboveGround = readOptional(uuid, "ndsm", *pixel);
     result["surface_elevation_meters"] = optionalNumber(surface);
     result["ground_elevation_meters"] = optionalNumber(ground);
     result["height_above_ground_meters"] = optionalNumber(aboveGround);

     // A clicked roof or wall names its building through _FEATURE_ID_0; a
     // click without one is resolved through the building label raster.
     const BuildingQueryRecord* building = nullptr;
     std::shared_ptr<const BuildingQueryIndex> index;
     try
     {
         index = HeightRasterStore::buildingIndex(uuid);
     }
     catch (const HeightDataUnavailable&)
     {
         result["building_lookup"] = "unavailable";
     }
     if (index)
     {
         result["render_height_scale"] = index->renderHeightScale;
         if (featureId) building = index->find(*featureId);
         if (!building)
         {
             const std::optional<float> label = readOptional(uuid, "buildings", *pixel);
             if (label && *label >= 1.0f)
                 building = index->find(static_cast<uint32_t>(std::lround(*label)));
         }
     }

     if (building)
     {
         result["kind"] = "building";
         result["building_id"] = building->id;
         result["building_height_meters"] = building->heightMeters;
         result["roof_elevation_meters"] = building->roofElevationMeters;
         result["base_elevation_meters"] = building->baseElevationMeters;
         result["footprint_area_m2"] = building->footprintAreaSquareMetres;
         result["elevation_meters"] = building->roofElevationMeters;
     }
     else
     {
         if (!surface)
             throw std::invalid_argument("No valid elevation at the clicked point.");
         result["kind"] = "terrain";
         result["elevation_meters"] = *surface;
     }
     co_return result;
}

drogon::Task<Json::Value> HeightOrchestratorService::processComparison(
     const std::string& uuid, const std::string& tag, double x, double y,
     const drogon::HttpFile* uploadedFile)
{
     // An uploaded reference is specific to the request; never cache it.
     const bool cacheable = tag != "upload";
     const std::string key = uuid + "|" + tag;
     std::shared_ptr<const ComparisonScene> scene = cacheable ? cachedComparison(key) : nullptr;

     if (!scene)
     {
         auto fresh = std::make_shared<ComparisonScene>();
         GDALDatasetPtr heights = HeightRasterStore::open(uuid, "heights");
         fresh->metadata = HeightRasterStore::metadataOf(*heights);
         fresh->generated = HeightRasterStore::readGrid(*heights);
         heights.reset();

         const ReferenceDem reference = co_await ReferenceDemService::fetchReference(
             tag, sceneBounds(fresh->metadata), uploadedFile);
         fresh->dataset = reference.dataset;
         fresh->reference = warpReference(reference, fresh->metadata);
         fresh->report = DemAccuracy::evaluate(fresh->generated, fresh->reference, fresh->options);
         fresh->differenceRange = DemAccuracy::suggestedDifferenceRange(
             fresh->generated, fresh->reference, fresh->options);
         const std::vector<uint8_t> png = DemAccuracy::renderDifferencePng(
             fresh->generated, fresh->reference, fresh->differenceRange);
         fresh->differencePngBase64 = drogon::utils::base64Encode(png.data(), png.size());
         scene = fresh;
         if (cacheable) storeComparison(key, scene);
     }

     const DemAccuracyReport& report = scene->report;
     Json::Value result(Json::objectValue);
     result["status"] = "success";
     result["uuid"] = uuid;
     result["tag"] = tag;
     result["reference_dataset"] = scene->dataset;

     // Headline metrics: anomalies beyond the threshold excluded, exactly as
     // in the validation script. The raw block reports all valid pixels.
     result["rmse"] = report.cleaned.rmse;
     result["mae"] = report.cleaned.mae;
     result["pearson_correlation"] = optionalNumber(report.cleaned.pearson);
     result["median_absolute_error"] = report.cleaned.medianAbsoluteError;
     result["accuracy_percentage"] = report.cleaned.withinTolerancePercent;
     result["tolerance_meters"] = scene->options.toleranceMeters;
     result["valid_pixels_count"] = static_cast<Json::UInt64>(report.cleaned.pixelCount);
     result["anomaly_pixels_count"] = static_cast<Json::UInt64>(report.anomalyPixelCount);
     result["anomaly_percentage"] = report.anomalyPercent;
     result["anomaly_threshold_meters"] = scene->options.anomalyThresholdMeters;
     result["edge_buffer_pixels"] = scene->options.edgeBufferPixels;
     result["max_absolute_error"] = report.maxAbsoluteError;
     result["raw"] = statisticsJson(report.raw);
     Json::Value generatedRange(Json::arrayValue);
     generatedRange.append(report.generatedMin);
     generatedRange.append(report.generatedMax);
     result["generated_range_meters"] = generatedRange;
     Json::Value referenceRange(Json::arrayValue);
     referenceRange.append(report.referenceMin);
     referenceRange.append(report.referenceMax);
     result["reference_range_meters"] = referenceRange;

     if (const auto pixel = HeightRasterStore::pixelAt(scene->metadata, x, y))
     {
         const std::size_t index =
             static_cast<std::size_t>(pixel->row) * scene->metadata.width + pixel->column;
         const float generated = scene->generated.data[index];
         const float reference = scene->reference.data[index];
         result["pixel"] = pixelJson(*pixel);
         result["original_height_meters"] = optionalNumber(generated);
         result["reference_height_meters"] = optionalNumber(reference);
         if (std::isfinite(generated) && std::isfinite(reference))
             result["difference_meters"] = static_cast<double>(generated) - reference;
     }

     result["diff_map_base64"] = scene->differencePngBase64;
     result["diff_map_range_meters"] = scene->differenceRange;
     result["diff_map_legend"] =
         "generated minus reference: blue = model lower, white = agree, red = model higher";
     co_return result;
}
