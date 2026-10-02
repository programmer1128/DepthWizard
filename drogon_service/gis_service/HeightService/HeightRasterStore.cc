#include "HeightRasterStore.h"
#include "../DataHandlers/MiniIOClient.h"
#include "../FileGenerators/BackgroundTiffExportService.h"

#include <cpl_conv.h>
#include <cpl_vsi.h>
#include <gdal_priv.h>
#include <json/reader.h>

#include <cmath>
#include <limits>
#include <list>
#include <mutex>
#include <sstream>
#include <utility>

namespace
{
constexpr const char* kBucket = "terrain-assets";
constexpr std::size_t kCachedBuildingIndexes = 8;

std::string objectKey(const std::string& uuid, const std::string& product)
{
     return product == "buildings_json" ? "buildings_" + uuid + ".json"
                                        : product + "_" + uuid + ".tif";
}

// Map a product to its export state, so a query made while the background
// worker is still uploading says so instead of failing obscurely.
void requireExported(const std::string& uuid, const std::string& product)
{
     const auto status = BackgroundTiffExportService::instance().getStatus(uuid);
     if (!status) return; // not in memory (e.g. after a restart): try MinIO
     JobStatus state = status->buildings;
     if (product == "heights") state = status->dsm;
     else if (product == "dtm") state = status->dtm;
     else if (product == "ndsm") state = status->ndsm;
     if (state == JobStatus::READY) return;
     if (state == JobStatus::FAILED)
         throw HeightDataUnavailable(product + " export failed for UUID " + uuid, false);
     throw HeightDataUnavailable(
         "Height rasters for this scene are still being exported; try again in a few seconds.",
         true);
}

std::string presignedVsiPath(const std::string& uuid, const std::string& product)
{
     static std::once_flag configured;
     std::call_once(configured, []
     {
         // Avoid a directory listing request before every object read.
         CPLSetConfigOption("GDAL_DISABLE_READDIR_ON_OPEN", "EMPTY_DIR");
     });
     const std::string url = MinioClient::generatePresignedUrl(kBucket, objectKey(uuid, product), 3600);
     if (url.empty())
         throw std::runtime_error("Cannot sign MinIO URL for " + objectKey(uuid, product));
     return "/vsicurl/" + url;
}
} // namespace

GDALDatasetPtr HeightRasterStore::open(const std::string& uuid, const std::string& product)
{
     requireExported(uuid, product);
     GDALDatasetPtr dataset(static_cast<GDALDataset*>(
         GDALOpen(presignedVsiPath(uuid, product).c_str(), GA_ReadOnly)));
     if (!dataset)
         throw HeightDataUnavailable("No " + product + " raster found for UUID " + uuid, false);
     return dataset;
}

std::shared_ptr<const BuildingQueryIndex> HeightRasterStore::buildingIndex(const std::string& uuid)
{
     static std::mutex mutex;
     static std::list<std::pair<std::string, std::shared_ptr<const BuildingQueryIndex>>> cache;
     {
         std::lock_guard lock(mutex);
         for (auto entry = cache.begin(); entry != cache.end(); ++entry)
             if (entry->first == uuid)
             {
                 cache.splice(cache.begin(), cache, entry);
                 return entry->second;
             }
     }

     requireExported(uuid, "buildings");
     // initGDAL() limits /vsicurl/ to .tif files process-wide; allow the JSON
     // index for this read only, on this thread.
     struct AllowJsonOverCurl
     {
         AllowJsonOverCurl() { CPLSetThreadLocalConfigOption("CPL_VSIL_CURL_ALLOWED_EXTENSIONS", "json"); }
         ~AllowJsonOverCurl() { CPLSetThreadLocalConfigOption("CPL_VSIL_CURL_ALLOWED_EXTENSIONS", nullptr); }
     } allowJson;
     VSILFILE* file = VSIFOpenL(presignedVsiPath(uuid, "buildings_json").c_str(), "rb");
     if (!file)
         throw HeightDataUnavailable("No building index found for UUID " + uuid, false);
     std::string text;
     char buffer[65536];
     for (std::size_t read; (read = VSIFReadL(buffer, 1, sizeof(buffer), file)) > 0;)
         text.append(buffer, read);
     VSIFCloseL(file);

     Json::CharReaderBuilder builder;
     Json::Value document;
     std::string errors;
     std::istringstream stream(text);
     if (!Json::parseFromStream(builder, stream, &document, &errors))
         throw std::runtime_error("Building index for " + uuid + " is not valid JSON: " + errors);
     auto index = std::make_shared<const BuildingQueryIndex>(
         BuildingQueryIndex::recordsFromJson(document));

     std::lock_guard lock(mutex);
     cache.emplace_front(uuid, index);
     if (cache.size() > kCachedBuildingIndexes) cache.pop_back();
     return index;
}

SpatialMetadata HeightRasterStore::metadataOf(GDALDataset& dataset)
{
     SpatialMetadata metadata;
     metadata.width = dataset.GetRasterXSize();
     metadata.height = dataset.GetRasterYSize();
     if (dataset.GetGeoTransform(metadata.geoTransform.data()) != CE_None)
         throw std::runtime_error("Height raster has no geotransform");
     metadata.projectionRef = dataset.GetProjectionRef();
     metadata.pixelSizeX = std::abs(metadata.geoTransform[1]);
     metadata.pixelSizeY = std::abs(metadata.geoTransform[5]);
     metadata.gsd = std::sqrt(metadata.pixelSizeX * metadata.pixelSizeY);
     metadata.isGeoreferenced = true;
     return metadata;
}

std::optional<float> HeightRasterStore::readPixel(GDALDataset& dataset, RasterPixel pixel)
{
     if (pixel.column < 0 || pixel.row < 0 ||
         pixel.column >= dataset.GetRasterXSize() || pixel.row >= dataset.GetRasterYSize())
         return std::nullopt;
     GDALRasterBand* band = dataset.GetRasterBand(1);
     float value = std::numeric_limits<float>::quiet_NaN();
     if (band->RasterIO(GF_Read, pixel.column, pixel.row, 1, 1, &value, 1, 1,
                        GDT_Float32, 0, 0) != CE_None)
         throw std::runtime_error("Height raster read failed");
     int hasNoData = 0;
     const double noData = band->GetNoDataValue(&hasNoData);
     if (!std::isfinite(value) || (hasNoData && value == static_cast<float>(noData)))
         return std::nullopt;
     return value;
}

RasterGrid<float> HeightRasterStore::readGrid(GDALDataset& dataset)
{
     RasterGrid<float> grid;
     grid.width = dataset.GetRasterXSize();
     grid.height = dataset.GetRasterYSize();
     grid.data.resize(static_cast<std::size_t>(grid.width) * grid.height);
     GDALRasterBand* band = dataset.GetRasterBand(1);
     if (band->RasterIO(GF_Read, 0, 0, grid.width, grid.height, grid.data.data(),
                        grid.width, grid.height, GDT_Float32, 0, 0) != CE_None)
         throw std::runtime_error("Height raster read failed");
     int hasNoData = 0;
     const double noData = band->GetNoDataValue(&hasNoData);
     if (hasNoData && std::isfinite(noData))
         for (float& value : grid.data)
             if (value == static_cast<float>(noData))
                 value = std::numeric_limits<float>::quiet_NaN();
     return grid;
}
