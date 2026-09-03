#include "TiffExporter.h"
#include <gdal_priv.h>
#include <iostream>

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
     CPLErr err = poBand->RasterIO(GF_Write, 0, 0, width, height, 
                                  dsm_matrix.data(), width, height, GDT_Float32, 0, 0);

     GDALClose(poDstDS);
     return err == CE_None;
}