#pragma once
#include "BuildingQueryIndex.h"
#include "ScenePixel.h"
#include "../utils/GisTypes.h"

#include <memory>
#include <optional>
#include <stdexcept>
#include <string>

// A query asked for data that does not exist yet: an unknown UUID, or
// rasters still being exported after the GLB was returned.
class HeightDataUnavailable : public std::runtime_error
{
     public:
     HeightDataUnavailable(const std::string& message, bool stillExporting)
         : std::runtime_error(message), stillExporting(stillExporting) {}
     bool stillExporting;
};

// Reads a job's exported rasters from MinIO for height queries.
class HeightRasterStore
{
     public:
     // product: "heights" (absolute DSM), "dtm", "ndsm" or "buildings".
     static GDALDatasetPtr open(const std::string& uuid, const std::string& product);
     static std::shared_ptr<const BuildingQueryIndex> buildingIndex(const std::string& uuid);

     static SpatialMetadata metadataOf(GDALDataset& dataset);
     static std::optional<RasterPixel> pixelAt(const SpatialMetadata& metadata,
                                               double eastMetres, double southMetres)
     {
          return scenePixelAt(metadata, eastMetres, southMetres);
     }
     static std::optional<float> readPixel(GDALDataset& dataset, RasterPixel pixel);
     static RasterGrid<float> readGrid(GDALDataset& dataset);
};
