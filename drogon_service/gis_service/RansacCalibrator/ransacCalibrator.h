#pragma once
#include <vector>
#include <cstdint>

struct CalibrationResult 
{
    double a{0.0}; // Quadratic term (lifts plateaued peaks)
    double b{1.0}; // Linear scale factor
    double c{0.0}; // Elevation offset
    int inliers_count{0};

    // Backward compatibility aliases
    double scale{1.0};  // Mirrors b
    double offset{0.0}; // Mirrors c
};

class RansacCalibrator 
{
     private:
     int iterations;
     double error_threshold;

     public:
     // Constructor to initialize the RANSAC parameters
     RansacCalibrator(int iterations_count = 500, double threshold = 15.0);

     //method to extract the valid indexes from the matrix, so that we perform random engine
     //on fewer indices for better performance
     std::vector<int> extractValidIndices(const std::vector<float>& srtmHeight);

     // Calculates the optimal global scale and offset using random sampling
     CalibrationResult calculateScaleAndOffset(const std::vector<float>& aiDepth, 
         const std::vector<float>& srtmHeight);

     // Primary quadratic calibration: a * D^2 + b * D + c
     std::vector<float> applyCalibration(
        const std::vector<float>& aiDepth, 
        double a, double b, double c);

    // Backward-compatible overload for linear calls: scale * D + offset
     std::vector<float> applyCalibration(
         const std::vector<float>& aiDepth, double scale,double offset);
};