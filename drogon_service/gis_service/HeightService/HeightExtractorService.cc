#include "HeightExtractorService.h"
#include "../DataHandlers/MiniIOClient.h"
#include <gdal_priv.h>
#include <cpl_vsi.h>
#include <stdexcept>
#include <cmath>
#include <algorithm>
#include <iostream> // FIX 1: Included for std::cout debugging

float HeightExtractorService::getExactElevation(const std::string& uuid, float x, float y) {
    std::string minioUrl = MinioClient::generatePresignedUrl("terrain-assets", "heights_" + uuid + ".tif", 3600);
    std::string vsiUrl = "/vsicurl/" + minioUrl;

    GDALDataset *poDS = (GDALDataset *) GDALOpen(vsiUrl.c_str(), GA_ReadOnly);
    if (!poDS) 
        throw std::runtime_error("Height extractor failed to stream MinIO TIF");

    int px = static_cast<int>(std::round(x));
    int py = static_cast<int>(std::round(y));

    float elevation = 0.0f;
    poDS->GetRasterBand(1)->RasterIO(GF_Read, px, py, 1, 1, &elevation, 1, 1, GDT_Float32, 0, 0);

    GDALClose(poDS);
    return elevation;
}

std::vector<uint8_t> HeightExtractorService::extractWindowTiff(
    const std::string& uuid, float x, float y, int window_size, GeoWindowContext& outContext) {
    
    std::string vsiUrl = "/vsicurl/" + MinioClient::generatePresignedUrl("terrain-assets", "heights_" + uuid + ".tif", 3600);
    GDALDataset *poDS = (GDALDataset *) GDALOpen(vsiUrl.c_str(), GA_ReadOnly);
    if (!poDS) throw std::runtime_error("Failed to stream MinIO TIF for window extraction");

    int px = static_cast<int>(std::round(x));
    int py = static_cast<int>(std::round(y));
    int half = window_size / 2;
    int startX = std::max(0, px - half);
    int startY = std::max(0, py - half);
    int readWidth = std::min(window_size, poDS->GetRasterXSize() - startX);
    int readHeight = std::min(window_size, poDS->GetRasterYSize() - startY);

    // 3. Mathematical Un-Warping in Native Coordinates
    double geoTransform[6];
    poDS->GetGeoTransform(geoTransform);

    // Keep native projected coordinates safe for outDS geotransform anchor
    double native_x1 = geoTransform[0] + startX * geoTransform[1] + startY * geoTransform[2];
    double native_y1 = geoTransform[3] + startX * geoTransform[4] + startY * geoTransform[5]; 
    double x2 = geoTransform[0] + (startX + readWidth) * geoTransform[1] + (startY + readHeight) * geoTransform[2];
    double y2 = geoTransform[3] + (startX + readWidth) * geoTransform[4] + (startY + readHeight) * geoTransform[5];

    // Set up coordinate transformation from dataset's native SRS to EPSG:4326 (Lat/Lon) for API bounding box
    OGRSpatialReference oSourceSRS;
    if (poDS->GetSpatialRef()) {
        oSourceSRS = *poDS->GetSpatialRef();
    } else {
        oSourceSRS.SetFromUserInput(poDS->GetProjectionRef());
    }

    OGRSpatialReference oTargetSRS;
    oTargetSRS.importFromEPSG(4326);
    oTargetSRS.SetAxisMappingStrategy(OAMS_TRADITIONAL_GIS_ORDER); // Forces X=Longitude, Y=Latitude

    OGRCoordinateTransformation *poCT = OGRCreateCoordinateTransformation(&oSourceSRS, &oTargetSRS);
    
    double lon1 = native_x1, lat1 = native_y1;
    double lon2 = x2, lat2 = y2;

    if (poCT) {
        poCT->Transform(1, &lon1, &lat1);
        poCT->Transform(1, &lon2, &lat2);
        OGRCoordinateTransformation::DestroyCT(poCT);
    } else {
        throw std::runtime_error("HeightExtractorService: Failed to create coordinate transformation pipeline to WGS84.");
    }

    const double EPSILON = 0.0001; 

    outContext.minLon = std::min(lon1, lon2) - EPSILON;
    outContext.maxLon = std::max(lon1, lon2) + EPSILON;
    outContext.minLat = std::min(lat1, lat2) - EPSILON;
    outContext.maxLat = std::max(lat1, lat2) + EPSILON;

    std::cout << "[DEBUG] Bounding Box -> MinLon: " << outContext.minLon 
              << ", MaxLon: " << outContext.maxLon 
              << ", MinLat: " << outContext.minLat 
              << ", MaxLat: " << outContext.maxLat << std::endl;

    // 4. Stream pixel window from cloud to RAM
    std::vector<float> buffer(readWidth * readHeight);
    poDS->GetRasterBand(1)->RasterIO(GF_Read, startX, startY, readWidth, readHeight, buffer.data(), readWidth, readHeight, GDT_Float32, 0, 0);

    // 5. Generate cropped memory .tif via /vsimem/
    std::string outVsi = "/vsimem/window_" + uuid + ".tif";
    GDALDriver *poDriver = GetGDALDriverManager()->GetDriverByName("GTiff");
    GDALDataset *outDS = poDriver->Create(outVsi.c_str(), readWidth, readHeight, 1, GDT_Float32, nullptr);
    
    // FIX 2: Use native projected coordinates (native_x1, native_y1) for the local window GeoTransform anchor!
    double newGeo[6];
    std::copy(std::begin(geoTransform), std::end(geoTransform), newGeo);
    newGeo[0] = native_x1;
    newGeo[3] = native_y1;
    outDS->SetGeoTransform(newGeo);
    outDS->SetProjection(poDS->GetProjectionRef());

    outDS->GetRasterBand(1)->RasterIO(GF_Write, 0, 0, readWidth, readHeight, buffer.data(), readWidth, readHeight, GDT_Float32, 0, 0);
    GDALClose(outDS); 
    GDALClose(poDS);

    vsi_l_offset dataLength = 0;
    GByte* pabyData = VSIGetMemFileBuffer(outVsi.c_str(), &dataLength, FALSE);
    std::vector<uint8_t> tiffBytes(pabyData, pabyData + dataLength);
    VSIUnlink(outVsi.c_str());

    return tiffBytes;
}