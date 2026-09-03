#include "SrtmExtractor.h"
#include <trantor/utils/Logger.h>

#include <cmath>
#include <iomanip>
#include <sstream>
#include <cpl_conv.h>
#include <ogr_spatialref.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// GDAL initialization configuration

//previous GDAL function from Main branch
// void initGDAL()
// {
//     GDALAllRegister();                                               // Wakes up GDAL and loads all image format drivers
//     CPLSetConfigOption("GDAL_DISABLE_READDIR_ON_OPEN", "EMPTY_DIR"); // Stops GDAL from scanning entire AWS buckets (Latency hack)
//     CPLSetConfigOption("GDAL_HTTP_MULTIMAC", "YES");                 // Enables fast multi-threaded downloads
//     CPLSetConfigOption("VSI_CACHE", "TRUE");                         // Caches the downloaded chunks in RAM
// }

//adding optimisation layer GDAL function
void initGDAL()
{
     GDALAllRegister();
    
     // Stop GDAL from looking for sidecar metadata files over the internet
     //increases performance by reducing  query overload over the S3 bucket server
     CPLSetConfigOption("CPL_VSIL_CURL_ALLOWED_EXTENSIONS", "tif"); 
     CPLSetConfigOption("GDAL_DISABLE_READDIR_ON_OPEN", "EMPTY_DIR"); 
    
     // Enable fast multiplexed downloads and merge consecutive byte requests
     CPLSetConfigOption("GDAL_HTTP_MULTIPLEX", "YES");                 
     CPLSetConfigOption("GDAL_HTTP_MERGE_CONSECUTIVE_READS", "YES");                 
    
     // Cache the downloaded chunks in RAM
     CPLSetConfigOption("VSI_CACHE", "TRUE");                         
}

GpsBounds SrtmExtractor::extractGpsBounds(const std::string &filePath)
{
     GpsBounds bounds;

     // Opening the GeoTIFF in read-only mode to extract metadata headers
     // GDALDataset *poDS = static_cast<GDALDataset *>(GDALOpen(filePath.c_str(), GA_ReadOnly));
     GDALDatasetPtr poDS(static_cast<GDALDataset *>(GDALOpen(filePath.c_str(), GA_ReadOnly)));

     if (!poDS)
     {
         LOG_ERROR << "Failed to open GeoTIFF metadata from : " << filePath;
         return bounds;
     }

     return extractGpsBounds(poDS.get());
}

GpsBounds SrtmExtractor::extractGpsBounds(GDALDataset *poDS)
{
    GpsBounds bounds;
    if (!poDS)
        return bounds;

    // no of pixel of the image
    bounds.pixels_x = poDS->GetRasterXSize();
    bounds.pixels_y = poDS->GetRasterYSize();

    // The GeoTransform array holds the map coordinates : Affine Transformation Matrix
    // adfGeoTransform[0]: The Top-Left X coordinate, adfGeoTransform[3]: The Top-Left Y coordinate, adfGeoTransform[1]: The physical width of a single pixel, adfGeoTransform[5]: The physical height of a single pixel

    double adfGeoTransform[6];
    if (poDS->GetGeoTransform(adfGeoTransform) == CE_None)
    {
        // top-left coordinates
        bounds.min_x = adfGeoTransform[0];
        bounds.max_y = adfGeoTransform[3];

        // bottom-right boundaries
        bounds.max_x = bounds.min_x + (bounds.pixels_x * adfGeoTransform[1]);
        bounds.min_y = bounds.max_y + (bounds.pixels_y * adfGeoTransform[5]);
    }

    // Extracting map projection in CRS : WKT string
    const char *raw_crs = poDS->GetProjectionRef();
    if (raw_crs && strlen(raw_crs) > 0)
    {
        bounds.crs = raw_crs;
    }

    // GDALClose(poDS); // Close the file immediately
    return bounds;
}

std::string SrtmExtractor::buildCopernicusUrl(double lat, double lon)
{
    // Copernicus uses a 1x1 degree grid system (e.g., Copernicus_DSM_COG_10_N28_00_E077_00_DEM)
    // latitude : 2 digs, longitude : 3 digs
    // bottom-left (South-West) corner is the unique identifier for each tile
    int lat_floor = static_cast<int>(std::floor(lat));
    int lon_floor = static_cast<int>(std::floor(lon));

    char lat_hemi = (lat_floor >= 0) ? 'N' : 'S';
    char lon_hemi = (lon_floor >= 0) ? 'E' : 'W';

     std::ostringstream ss;
     ss << std::setfill('0');
     ss << "Copernicus_DSM_COG_10_" << lat_hemi << std::setw(2) << std::abs(lat_floor) << "_00_"
       << lon_hemi << std::setw(3) << std::abs(lon_floor) << "_00_DEM";

    std::string tile_name = ss.str();
    return "/vsicurl/https://copernicus-dem-30m.s3.eu-central-1.amazonaws.com/" + tile_name + "/" + tile_name + ".tif";
}

std::string SrtmExtractor::buildSrtmUrl(double lat, double lon, int zoom)
{
    // uses Web Mercator projection (EPSG:3857)
    // at zoom level z earth is broken into (2^z)*(2^z) tiles
    int x_tile = static_cast<int>(std::floor((lon + 180.0) / 360.0 * std::pow(2.0, zoom))); // Longitude goes from -180 deg to +180 deg -> hence +180 shift

    double lat_rad = lat * M_PI / 180.0; // deg -> rad
    int y_tile = static_cast<int>(std::floor((1.0 - std::asinh(std::tan(lat_rad)) / M_PI) / 2.0 * std::pow(2.0, zoom)));
    // The Mercator stretch accounts for vertical distortion -> subtracting from 1 changes the convetion to match -> origin is considered at top-left corner(North-west corner or North Pole) -> (North:0, Equator:0.5, South:1)

    return "/vsicurl/https://elevation-tiles-prod.s3.amazonaws.com/geotiff/" + std::to_string(zoom) + "/" + std::to_string(x_tile) + "/" + std::to_string(y_tile) + ".tif";
}

RasterDatasets SrtmExtractor::fetchTile(const std::string &filePath)
{
    // Opening the file
    GDALDatasetPtr hInputDS(static_cast<GDALDataset *>(GDALOpen(filePath.c_str(), GA_ReadOnly)));
    if (!hInputDS)
    {
        LOG_ERROR << "Failed to open input GeoTIFF : " << filePath;
        return {nullptr, nullptr};
    }

    // .get() returns GDALDataset*
    GpsBounds bounds = extractGpsBounds(hInputDS.get());

    // center target (latitude, longitude) point
    double target_lon = (bounds.min_x + bounds.max_x) / 2.0;
    double target_lat = (bounds.min_y + bounds.max_y) / 2.0;

    // Converting the center coordinates of the input image to the EPSG:4326 system
    if (!bounds.crs.empty()) // if crs is not mentioned then it is considered to be in epsg:4326
    {
        // containers for the mathematical definitions of the coordinate systems
        OGRSpatialReference sourceSRS;
        OGRSpatialReference targetSRS;

        if (sourceSRS.SetFromUserInput(bounds.crs.c_str()) == OGRERR_NONE) // parsing the WKT string (crs system) extracted from the input image
        {
             targetSRS.SetWellKnownGeogCS("WGS84"); // Setting the target container to the WGS84 model (EPSG:4326)

             // To force GDAL 3.0+ to keep using the old (Longitude, Latitude) format
             #if GDAL_VERSION_MAJOR >= 3 // to make it backward compatible
             //added for geotiff order
             sourceSRS.SetAxisMappingStrategy(OAMS_TRADITIONAL_GIS_ORDER);
             targetSRS.SetAxisMappingStrategy(OAMS_TRADITIONAL_GIS_ORDER);
             #endif

             OGRCoordinateTransformation *poTransform = OGRCreateCoordinateTransformation(&sourceSRS, &targetSRS);
             if (poTransform)
             {
                 // Overwriting the raw center metrics with EPSG:4326 degrees
                 poTransform->Transform(1, &target_lon, &target_lat); // 1 represents the no. of points to be converted simultaneously
                 OGRCoordinateTransformation::DestroyCT(poTransform); // memory cleanup
             }
             else
             {
                 LOG_ERROR << "Failed to transform coordinates to EPSG:4326.";
                 return {std::move(hInputDS), nullptr};
             }
        }
    }

    // Copernicus DEM extraction
    std::string copernicusUrl = buildCopernicusUrl(target_lat, target_lon);
    GDALDatasetPtr hDemDS(static_cast<GDALDataset *>(GDALOpen(copernicusUrl.c_str(), GA_ReadOnly)));

    // Fallback SRTM DEM extraction
    if (!hDemDS)
    {
        LOG_WARN << "Copernicus DEM failed. Falling back to SRTM dataset.";
        std::string srtmUrl = buildSrtmUrl(target_lat, target_lon);
        hDemDS.reset(static_cast<GDALDataset *>(GDALOpen(srtmUrl.c_str(), GA_ReadOnly)));
    }

    if (!hDemDS)
    {
        LOG_ERROR << "Critical Failure: Both Copernicus and SRTM DEM fetches failed.";
        return {std::move(hInputDS), nullptr};
    }

    // Passing to Raster Processor
    return {std::move(hInputDS), std::move(hDemDS)};
}