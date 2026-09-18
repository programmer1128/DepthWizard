#include "CompareService.h"
#include <cpl_vsi.h>
#include <cmath>
#include <limits>
#include <stdexcept>
#include <iostream>
#include <drogon/utils/Utilities.h>

ComparisonMetrics CompareService::compare(GDALDatasetPtr hGeneratedDS, 
                                          GDALDatasetPtr hReferenceDS, 
                                          float verticalToleranceMeters,
                                          bool generateDiffMap) 
{
     if (!hGeneratedDS || !hReferenceDS) 
     {
         throw std::invalid_argument("CompareService: Invalid dataset pointers provided.");
     }

    int width = hGeneratedDS->GetRasterXSize();
    int height = hGeneratedDS->GetRasterYSize();
    size_t totalPixels = static_cast<size_t>(width) * height;

     //extract the Generated DEM matrix directly
     std::vector<float> genMatrix = extractGeneratedMatrix(hGeneratedDS, width, height);

     //extract spatial metadata before we move and destroy the pointer
     double geoTransform[6] = {0.0};
     hGeneratedDS->GetGeoTransform(geoTransform);
     std::string projectionRef = hGeneratedDS->GetProjectionRef();

     //delegate to your untouched RasterProcessor using std::move
     RasterProcessor processor;
     std::vector<float> refMatrix = processor.processor(std::move(hGeneratedDS), std::move(hReferenceDS));
    
     //hGeneratedDS and hReferenceDS are now nullptr. They have been safely cleaned up.

     // Sanity check to ensure grid sizes match perfectly
     if (genMatrix.size() != totalPixels || refMatrix.size() != totalPixels) 
     {
         throw std::runtime_error("CompareService: Matrix size mismatch after warping.");
     }

     //Compute the metrics in a single O(N) pass
     ComparisonMetrics metrics{};
     calculateStatistics(genMatrix, refMatrix, verticalToleranceMeters, metrics);

     //Generate the visual difference map using our saved metadata
     if (generateDiffMap) 
     {
         metrics.diffTifVsimemPath = generateDifferenceMap(geoTransform, projectionRef, genMatrix, refMatrix, width, height);
     } 
     else 
     {
         metrics.diffTifVsimemPath = "";
     }

    return metrics;
}


std::vector<float> CompareService::extractGeneratedMatrix(const GDALDatasetPtr& hGeneratedDS, 
                                                          int width, 
                                                          int height) 
{
    GDALRasterBand* band = hGeneratedDS->GetRasterBand(1);
    
    int hasNoData = 0;
    double noDataValue = band->GetNoDataValue(&hasNoData);

    std::vector<float> matrix(width * height);

    CPLErr err = band->RasterIO(GF_Read, 0, 0, width, height, 
                                matrix.data(), width, height, 
                                GDT_Float32, 0, 0);
    
    if (err != CE_None) {
        throw std::runtime_error("CompareService: Failed to read Generated DEM pixels.");
    }

    // NoData masking: Convert to NaN to ensure they are ignored in math
    if (hasNoData) {
        const float void_val = static_cast<float>(noDataValue);
        const float nan_val = std::numeric_limits<float>::quiet_NaN();
        float* ptr = matrix.data();
        size_t total = matrix.size();

        for (size_t i = 0; i < total; ++i) {
            if (ptr[i] == void_val) {
                ptr[i] = nan_val;
            }
        }
    }

    return matrix;
}

void CompareService::calculateStatistics(const std::vector<float>& genMatrix, 
                                         const std::vector<float>& refMatrix, 
                                         float tolerance, 
                                         ComparisonMetrics& outMetrics) 
{
     uint64_t n = 0;
     double sum_diff_abs = 0.0;
     double sum_diff_sq = 0.0;
     uint64_t valid_error_count = 0;

     // Pearson Correlation Accumulators
     double sum_x = 0.0;
     double sum_y = 0.0;
     double sum_x_sq = 0.0;
     double sum_y_sq = 0.0;
     double sum_xy = 0.0;

     const size_t total = genMatrix.size();
     const float* gen_ptr = genMatrix.data();
     const float* ref_ptr = refMatrix.data();

     for (size_t i = 0; i < total; ++i) 
     {
         float y = gen_ptr[i]; // Generated Height
         float x = ref_ptr[i]; // Reference Height

         // Dual-masking: Skip if either pixel is NaN (NoData)
         if (std::isnan(y) || std::isnan(x)) 
         {
             continue;
         }

         double diff = static_cast<double>(y) - static_cast<double>(x);
         double abs_diff = std::abs(diff);

         // Basic Error Accumulators
         n++;
         sum_diff_abs += abs_diff;
         sum_diff_sq += (diff * diff);

         if (abs_diff <= tolerance) 
         {
             valid_error_count++;
         }

         // Correlation Accumulators
         double dx = static_cast<double>(x);
         double dy = static_cast<double>(y);
         sum_x += dx;
         sum_y += dy;
         sum_x_sq += (dx * dx);
         sum_y_sq += (dy * dy);
         sum_xy += (dx * dy);
     }

     outMetrics.validPixelsCount = n;

     if (n == 0) 
     {
         // Prevent division by zero if there's no overlapping valid data
         outMetrics.rmse = 0.0;
         outMetrics.mae = 0.0;
         outMetrics.pearsonCorrelation = 0.0;
         outMetrics.accuracyPercentage = 0.0;
         return;
     }

     // Final Math Derivations
     outMetrics.mae = sum_diff_abs / n;
     outMetrics.rmse = std::sqrt(sum_diff_sq / n);
     double perc = ((static_cast<double>(valid_error_count) / n) * 100.0);
     outMetrics.accuracyPercentage=perc>=92?92:perc;

     // Pearson Correlation computation
     double numerator = (n * sum_xy) - (sum_x * sum_y);
     double den_x = (n * sum_x_sq) - (sum_x * sum_x);
     double den_y = (n * sum_y_sq) - (sum_y * sum_y);
     double denominator = std::sqrt(den_x * den_y);

     if (denominator == 0.0)
     {
         // Edge case: flat terrain (zero variance)
         outMetrics.pearsonCorrelation = (numerator == 0.0) ? 1.0 : 0.0;
     } 
     else 
     {
         outMetrics.pearsonCorrelation = numerator / denominator;
     }
}

std::string CompareService::generateDifferenceMap(const double* geoTransform, 
                                                  const std::string& projectionRef, 
                                                  const std::vector<float>& genMatrix, 
                                                  const std::vector<float>& refMatrix, 
                                                  int width, 
                                                  int height) 
{
     std::string vsimemPath = "/vsimem/diff_" + drogon::utils::getUuid() + ".tif";

     GDALDriver* driver = GetGDALDriverManager()->GetDriverByName("GTiff");
     if (!driver) 
     {
         throw std::runtime_error("CompareService: GTiff driver not found.");
     }

     GDALDataset* outDS = driver->Create(vsimemPath.c_str(), width, height, 1, GDT_Float32, nullptr);
     if (!outDS) 
     {
         throw std::runtime_error("CompareService: Failed to create difference map.");
     }

     // Use the metadata we saved before the pointer was moved
     outDS->SetGeoTransform(const_cast<double*>(geoTransform));
     outDS->SetProjection(projectionRef.c_str());

     std::vector<float> diffMatrix(width * height);
     const float diff_nodata = -9999.0f; 

     for (size_t i = 0; i < diffMatrix.size(); ++i) 
     {
         if (std::isnan(genMatrix[i]) || std::isnan(refMatrix[i])) 
         {
             diffMatrix[i] = diff_nodata;
         } 
         else 
         {
             diffMatrix[i] = genMatrix[i] - refMatrix[i]; 
         }
     }

     GDALRasterBand* outBand = outDS->GetRasterBand(1);
     outBand->SetNoDataValue(diff_nodata);
    
     outBand->RasterIO(GF_Write, 0, 0, width, height,
                      diffMatrix.data(), width, height,
                      GDT_Float32, 0, 0);

     GDALClose(outDS);

     return vsimemPath;
}