#include "TiffExporter.h"
#include <gdal_priv.h>
#include <iostream>
#include <cstring>
#include <limits>

bool TiffExporter::writeFloatTiff(
     const std::string& outputPath, 
     std::vector<float>& dsm_matrix, 
     int width, 
     int height,
     double* geoTransform,
     const char* projectionRef)
{ 
     GDALDriver *poDriver = GetGDALDriverManager()->GetDriverByName("GTiff");
     if (!poDriver) 
     {
         return false;
     }

     //create a 1-band, 32-bit Float TIFF
     GDALDataset *poDstDS = poDriver->Create(outputPath.c_str(), width, height, 1, GDT_Float32, NULL);
     if (!poDstDS) 
     {
         return false;
     }

     // Embed the real-world spatial coordinates
     if (geoTransform != nullptr) 
     {
         poDstDS->SetGeoTransform(geoTransform);
     }
     if (projectionRef != nullptr && strlen(projectionRef) > 0) 
     {
         poDstDS->SetProjection(projectionRef);
     }

     // Write the raw memory matrix directly to the file
     GDALRasterBand *poBand = poDstDS->GetRasterBand(1);
     poBand->SetNoDataValue(std::numeric_limits<double>::quiet_NaN());
     CPLErr err = poBand->RasterIO(GF_Write, 0, 0, width, height, 
                                  dsm_matrix.data(), width, height, GDT_Float32, 0, 0);

     GDALClose(poDstDS);
     return err == CE_None;
}


std::vector<uint8_t> TiffExporter::exportTiffToBuffer(
     const std::string& uuid,
     std::vector<float>& dsm_matrix, 
     int width, 
     int height,
     double* geoTransform,
     const char* projectionRef)
{ 
     GDALDriver *poDriver = GetGDALDriverManager()->GetDriverByName("GTiff");
     if (!poDriver) 
     {
         return {};
     }

     // Write directly to GDAL virtual RAM filesystem
     std::string vsi_path = "/vsimem/export_" + uuid + ".tif";

     GDALDataset *poDstDS = poDriver->Create(vsi_path.c_str(), width, height, 1, GDT_Float32, nullptr);
     if (!poDstDS) 
     {
         return {};
     }

     if (geoTransform != nullptr) 
     {
         poDstDS->SetGeoTransform(geoTransform);
     }
     if (projectionRef != nullptr && std::strlen(projectionRef) > 0) 
     {
         poDstDS->SetProjection(projectionRef);
     }

     GDALRasterBand *poBand = poDstDS->GetRasterBand(1);
     poBand->SetNoDataValue(std::numeric_limits<double>::quiet_NaN());
     CPLErr err = poBand->RasterIO(GF_Write, 0, 0, width, height, 
                                   dsm_matrix.data(), width, height, GDT_Float32, 0, 0);

     // GDALClose flushes all headers and blocks to the /vsimem/ buffer
     GDALClose(poDstDS);

     if (err != CE_None) 
     {
         VSIUnlink(vsi_path.c_str());
         return {};
     }

     // Extract the memory file buffer from /vsimem/
     vsi_l_offset dataLength = 0;
     GByte* pabyData = VSIGetMemFileBuffer(vsi_path.c_str(), &dataLength, FALSE);

     if (!pabyData || dataLength == 0) 
     {
         VSIUnlink(vsi_path.c_str());
         return {};
     }

     std::vector<uint8_t> tiffBytes(pabyData, pabyData + dataLength);

     // Release the virtual RAM file to prevent leaks
     VSIUnlink(vsi_path.c_str());

     return tiffBytes;
}
