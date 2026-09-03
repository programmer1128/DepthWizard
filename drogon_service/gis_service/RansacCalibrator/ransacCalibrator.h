#pragma once
#include <vector>
#include <cstdint>

struct CalibrationResult 
{
    double scale;
    double offset;
    int inliers_count;
};

class RansacCalibrator 
{
     private:
     int iterations;
     double error_threshold;

     public:
     // Constructor to initialize the RANSAC parameters
     RansacCalibrator(int iterations_count = 500, double threshold = 5.0);

     //method to extract the valid indexes from the matrix, so that we perform random engine
     //on fewer indices for better performance
     std::vector<int> extractValidIndices(const std::vector<float>& srtmHeight);

     // Calculates the optimal global scale and offset using random sampling
     CalibrationResult calculateScaleAndOffset(const std::vector<float>& aiDepth, 
         const std::vector<float>& srtmHeight);

     // Applies the winning formula to the entire high-resolution matrix
     std::vector<float> applyCalibration(
         const std::vector<float>& aiDepth, double scale,double offset);
};