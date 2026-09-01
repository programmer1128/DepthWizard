#pragma once

#include <string>
#include <memory>
#include <drogon/drogon.h>
#include <drogon/utils/coroutine.h>
#include <gdal_priv.h>
#include "../utils/GisTypes.h"

// Struct to hold the extracted GeoTIFF spatial metadata
struct GpsBounds
{
    // Reference : x-axis -> Equator, y-axis -> Central Meridian
    // x -> longitude, y -> latitude
    double min_x{0.0};
    double min_y{0.0};
    double max_x{0.0};
    double max_y{0.0};
    int pixels_x{0};
    int pixels_y{0};
    std::string crs{"EPSG:4326"}; // Coordinate Reference System EPSG:4326 is the standard global identifier for WGS 84 (the coordinate system used by standard GPS for Latitude and Longitude mapping)
};

void initGDAL();

// Struct for the return type to Raster Processor
struct RasterDatasets
{
    GDALDatasetPtr hInputDS;
    GDALDatasetPtr hDemDS;
};

class SrtmExtractor
{
public:
    // Extracting spatial boundaries from the uploaded GeoTIFF
    static GpsBounds extractGpsBounds(const std::string &filePath); // when Spring Boot gateway receives the image it temporarily saves using this filePath
    static GpsBounds extractGpsBounds(GDALDataset *poDS);

    // Calculating the specific AWS tile URLs based on coordinates
    static std::string buildCopernicusUrl(double lat, double lon);
    static std::string buildSrtmUrl(double lat, double lon, int zoom = 12); // Zoom Level 12 is explicitly chosen to retrieve SRTM elevation data at a 30-meter physical resolution

    // method to process files and return the pair of datasets
    static RasterDatasets fetchTile(const std::string &filePath);
};