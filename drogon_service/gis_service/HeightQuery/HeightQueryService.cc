#include "HeightQueryService.h"
#include <gdal_priv.h>
#include <cpl_vsi.h>
#include <cmath>

HeightResult HeightQueryService::extractElevationFromMinIO(const std::string& uuid, float click_x, float click_z)
{
    // 1. Configure GDAL for MinIO (S3-compatible)
    // NOTE: These should match your MinioClient credentials. 
    // In production, load these from your config.json or Environment Variables.
    CPLSetConfigOption("AWS_ACCESS_KEY_ID", "YOUR_MINIO_ACCESS_KEY");
    CPLSetConfigOption("AWS_SECRET_ACCESS_KEY", "YOUR_MINIO_SECRET_KEY");
    CPLSetConfigOption("AWS_S3_ENDPOINT", "127.0.0.1:9000"); // Or your MinIO IP/Domain
    CPLSetConfigOption("AWS_HTTPS", "NO"); // Change to YES if using SSL
    CPLSetConfigOption("AWS_VIRTUAL_HOSTING", "FALSE"); // Required for MinIO path-style access

    // 2. Construct the GDAL Virtual File System path
    // The /vsis3/ prefix tells GDAL to use network byte-range requests!
    std::string bucket_name = "terrain-assets";
    std::string s3_path = "/vsis3/" + bucket_name + "/heights_" + uuid + ".tif";

    GDALAllRegister();
    
    // Open the dataset in read-only mode over the network
    GDALDataset* poDataset = (GDALDataset*) GDALOpen(s3_path.c_str(), GA_ReadOnly);
    
    if (!poDataset) 
    {
        return HeightResult{false, 0.0f, "Failed to locate or open GeoTIFF in MinIO for UUID: " + uuid};
    }

    // 3. Translate 3D coordinates (X, Z) into 2D Image Pixels (Column, Row)
    // Because pixel_size = 1.0f, the translation is a direct 1:1 rounding
    int col = static_cast<int>(std::round(click_x));
    int row = static_cast<int>(std::round(click_z));

    int width = poDataset->GetRasterXSize();
    int height = poDataset->GetRasterYSize();

    // Boundary validation: Ensure the click wasn't off the edge of the map
    if (col < 0 || col >= width || row < 0 || row >= height) 
    {
        GDALClose(poDataset);
        return HeightResult{false, 0.0f, "Clicked coordinates are outside the terrain boundaries."};
    }

    // 4. Extract the exact single float from the network
    float extracted_elevation = 0.0f;
    GDALRasterBand* poBand = poDataset->GetRasterBand(1);

    // RasterIO reads exactly 1x1 pixel at the (col, row) offset directly from MinIO
    CPLErr err = poBand->RasterIO(GF_Read, col, row, 1, 1, 
                                  &extracted_elevation, 1, 1, 
                                  GDT_Float32, 0, 0);

    // Close the network handle
    GDALClose(poDataset);

    if (err != CE_None) 
    {
        return HeightResult{false, 0.0f, "GDAL network read failed during pixel extraction."};
    }

    // Return the successful real-world metric height!
    return HeightResult{true, extracted_elevation, ""};
}