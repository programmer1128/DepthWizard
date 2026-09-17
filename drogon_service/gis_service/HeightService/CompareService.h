#pragma once

#include <string>
#include <vector>
#include <memory>
#include <cstdint>
// Include your existing processor. 
// We assume it defines GDALDatasetPtr (e.g., std::shared_ptr<GDALDataset>)
#include "../RasterProcessor/RasterProcessor.h"

/**
 * @struct ComparisonMetrics
 * @brief Encapsulates the results of the DEM statistical comparison.
 */
struct ComparisonMetrics {
    double rmse;                   // Root Mean Square Error (in meters)
    double mae;                    // Mean Absolute Error (in meters)
    double pearsonCorrelation;     // Linear correlation coefficient (-1.0 to 1.0)
    double accuracyPercentage;     // Percentage of pixels within the specified vertical tolerance
    uint64_t validPixelsCount;     // Total number of pixels successfully compared (excluding NoData/NaNs)
    std::string diffTifVsimemPath; // GDAL virtual memory path to the resulting difference map
};

/**
 * @class CompareService
 * @brief Service to mathematically compare a generated DEM against a reference DEM.
 * 
 * Utilizes the existing RasterProcessor to align and resample the reference DEM
 * to perfectly match the generated DEM's Coordinate Reference System (CRS) and grid.
 */
class CompareService {
public:
    CompareService() = default;
    ~CompareService() = default;

    /**
     * @brief The main orchestrator function to compare two DEMs.
     * 
     * @param hGeneratedDS The anchor dataset (your generated DEM).
     * @param hReferenceDS The target dataset (e.g., ISRO CartoDEM or COP30).
     * @param verticalToleranceMeters Acceptable vertical error limit to calculate Accuracy %.
     * @param generateDiffMap If true, writes a difference map (Generated - Reference) to /vsimem/.
     * @return ComparisonMetrics struct containing RMSE, MAE, Correlation, and Accuracy.
     */
    ComparisonMetrics compare(GDALDatasetPtr hGeneratedDS, 
                              GDALDatasetPtr hReferenceDS, 
                              float verticalToleranceMeters = 2.0f,
                              bool generateDiffMap = true);

private:
    /**
     * @brief Extracts pixel data from the generated DEM into a 1D float vector.
     * 
     * Since RasterProcessor's extraction is self-contained, this private helper 
     * reads the generated DEM, identifies its NoData value, and converts NoData to NaN.
     * 
     * @param hGeneratedDS Pointer to the generated dataset.
     * @param width The physical pixel width.
     * @param height The physical pixel height.
     * @return std::vector<float> Flat 1D array of elevation values.
     */
    std::vector<float> extractGeneratedMatrix(const GDALDatasetPtr& hGeneratedDS, 
                                              int width, 
                                              int height);

    /**
     * @brief Executes the single-pass O(N) statistical accumulation loop.
     * 
     * Iterates over both vectors simultaneously. Ignores index pairs where either 
     * value is NaN. Populates the metrics struct with the calculated results.
     * 
     * @param genMatrix The extracted generated DEM vector.
     * @param refMatrix The aligned reference DEM vector from RasterProcessor.
     * @param tolerance The acceptable error tolerance in meters.
     * @param outMetrics The struct to populate with results.
     */
    void calculateStatistics(const std::vector<float>& genMatrix, 
                             const std::vector<float>& refMatrix, 
                             float tolerance, 
                             ComparisonMetrics& outMetrics);

    /**
     * @brief Creates a new GeoTIFF representing (Generated Height - Reference Height).
     * 
     * Uses GDAL's MEM or GTiff driver to write a new raster directly into RAM (/vsimem/).
     * This dataset copies the geo-transform and CRS from the generated DEM.
     * 
     * @param hGeneratedDS The anchor dataset (used to copy CRS and spatial extents).
     * @param genMatrix The generated DEM vector.
     * @param refMatrix The aligned reference DEM vector.
     * @param width The physical pixel width.
     * @param height The physical pixel height.
     * @return std::string The /vsimem/ path where the difference map is stored.
     */
    std::string generateDifferenceMap(const double* geoTransform, 
                                      const std::string& projectionRef, 
                                      const std::vector<float>& genMatrix, 
                                      const std::vector<float>& refMatrix, 
                                      int width, 
                                      int height);
};