#include "ransacCalibrator.h"
#include <cmath>
#include <random>
#include <algorithm>
#include <iostream>

RansacCalibrator::RansacCalibrator(int iterations_count, double threshold) 
    : iterations(iterations_count), error_threshold(threshold) {}

CalibrationResult RansacCalibrator::calculateScaleAndOffset(
     const std::vector<float>& aiDepth, 
     const std::vector<float>& srtmHeight, 
     const std::vector<int>& validIndices) 
{    
     CalibrationResult best_result = {1.0, 0.0, 0};
    
     int num_valid = validIndices.size();
     if (num_valid < 2) 
     {
         std::cerr << "Not enough valid points for RANSAC." << std::endl;
         return best_result;
     }

     //Mersenne Twister is used for random number generations  as it is more faster than normal
     //rand and allows most performance
     std::random_device rd;
     std::mt19937 gen(rd());
     std::uniform_int_distribution<> distrib(0, num_valid - 1);

     for (int i = 0; i < iterations; ++i) 
     {
         //random index points selected
         int idx1 = distrib(gen);
         int idx2 = distrib(gen);
        
         //this is done to make sure points are not same
         while (idx1 == idx2) 
         {
             idx2 = distrib(gen);
         }

         int real_idx1 = validIndices[idx1];
         int real_idx2 = validIndices[idx2];

         double d1 = aiDepth[real_idx1];
         double h1 = srtmHeight[real_idx1];
         double d2 = aiDepth[real_idx2];
         double h2 = srtmHeight[real_idx2];

         // Prevent division by zero if depth values are identical
         if (std::abs(d2 - d1) < 1e-6) 
         {
             continue;
         }

         //for the sample we need to calculate the scale and the offset factor which will
         //basically be the slope and intercept of y=mx+c
         double current_scale = (h2 - h1) / (d2 - d1);
         double current_offset = h1 - current_scale * d1;

         ///testing for the real data from dataset, we need to find a set with max inliers
         int current_inliers = 0;
         
         for (int valid_idx:validIndices) 
         {
             double d=aiDepth[valid_idx];
             double h=srtmHeight[valid_idx];
             //absolute error is calculated as there may be false results due to negatives
             double error = std::abs(h - (current_scale * d + current_offset));
            
             if (error <= error_threshold) 
             {
                 current_inliers++;
             }
         }
         //max inlier res is kept for best res
         if (current_inliers > best_result.inliers_count) 
         {
             best_result.inliers_count = current_inliers;
             best_result.scale = current_scale;
             best_result.offset = current_offset;
         }
     }

     return best_result;
}

std::vector<float> RansacCalibrator::applyCalibration(
     const std::vector<float>& aiDepth, 
     double scale, 
     double offset) {
    
     // Pre-allocate the exact memory size to prevent dynamic resizing overhead as vector in
     //c++ reallocates after size 8 based on power of 2 so every reallocation would do memcpy
     //increasing overhead
     std::vector<float> absoluteDsm;
     absoluteDsm.reserve(aiDepth.size());

     for (float relative_depth : aiDepth) 
     {
         absoluteDsm.emplace_back(static_cast<float>(scale * relative_depth + offset));
     }

     return absoluteDsm;
}