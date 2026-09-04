#include "ransacCalibrator.h"
#include <cmath>
#include <random>
#include <algorithm>
#include <iostream>
#include <omp.h>

std::vector<int> RansacCalibrator::extractValidIndices(const std::vector<float>& srtmHeight) 
{
     std::vector<int> validIndices;
     size_t total_size = srtmHeight.size();
     if (total_size == 0) 
     {
         return validIndices;
     }

     validIndices.reserve(total_size);
     // Sequential single-direction pass gives optimal L1/L2 cache prefetching
     for (size_t i = 0; i < total_size; ++i) 
     {
         float val = srtmHeight[i];
         if (!std::isnan(val) && val > 0.0f) 
         {
             validIndices.push_back(static_cast<int>(i));
         }
     }
     return validIndices;
}


RansacCalibrator::RansacCalibrator(int iterations_count, double threshold) 
     : iterations(iterations_count), error_threshold(threshold) {}



//srtm height will contain quiet_NaN values for void, so before calling this function we need to do a sweep
//of the srtmHeight 1d flattened matrix to get validIndices and reduce load on rand num generator
CalibrationResult RansacCalibrator::calculateScaleAndOffset(
    const std::vector<float>& aiDepth, 
    const std::vector<float>& srtmHeight) 
{    
     CalibrationResult best_result = {1.0, 0.0, 0};
    
     //Extract valid points upfront into contiguous, flat arrays
     size_t total_size = srtmHeight.size();
     std::vector<float> compact_depth;
     std::vector<float> compact_srtm;
     compact_depth.reserve(total_size);
     compact_srtm.reserve(total_size);

     for (size_t i = 0; i < total_size; ++i) 
     {
         float h = srtmHeight[i];
         if (!std::isnan(h) && h > 0.0f) 
         {
             compact_depth.push_back(aiDepth[i]);
             compact_srtm.push_back(h);
         }
     }

     int num_valid = static_cast<int>(compact_depth.size());
     if (num_valid < 2) 
     {
         std::cerr << "Not enough valid points for RANSAC." << std::endl;
         return best_result;
     }

     // Direct pointers for SIMD auto-vectorization
     const float* d_ptr = compact_depth.data();
     const float* h_ptr = compact_srtm.data();
     const float thresh = static_cast<float>(error_threshold);

     //Parallelize across all CPU cores with OpenMP
     #pragma omp parallel
     {
         // Thread-safe, uniquely seeded RNG per thread (No locks/contention)
         std::random_device rd;
         std::mt19937 gen(rd() + omp_get_thread_num());
         std::uniform_int_distribution<int> distrib(0, num_valid - 1);

         CalibrationResult local_best = {1.0, 0.0, 0};

         // Distribute the iterations evenly across worker threads
         #pragma omp for nowait
         for (int i = 0; i < iterations; ++i) 
         {
             int idx1 = distrib(gen);
             int idx2 = distrib(gen);
            
             while (idx1 == idx2) 
             {
                 idx2 = distrib(gen);
             }

             float d1 = d_ptr[idx1];
             float h1 = h_ptr[idx1];
             float d2 = d_ptr[idx2];
             float h2 = h_ptr[idx2];

             if (std::abs(d2 - d1) < 1e-6f) 
             {
                 continue;
             }

             float current_scale = (h2 - h1) / (d2 - d1);
             float current_offset = h1 - current_scale * d1;

             //Inner Loop: Flat memory + SIMD vector reduction
             int current_inliers = 0;

             #pragma omp simd reduction(+:current_inliers)
             for (int j = 0; j < num_valid; ++j) 
             {
                 float predicted = current_scale * d_ptr[j] + current_offset;
                 float error = std::abs(h_ptr[j] - predicted);
                 if (error <= thresh) 
                 {
                     current_inliers++;
                 }
             }

             // Track thread-local best
             if (current_inliers > local_best.inliers_count) 
             {
                 local_best.inliers_count = current_inliers;
                 local_best.scale = static_cast<double>(current_scale);
                 local_best.offset = static_cast<double>(current_offset);
             }
         }

         //Merge results once per thread at the end
         #pragma omp critical
         {
             if (local_best.inliers_count > best_result.inliers_count) 
             {
                 best_result = local_best;
             }
         }
     }

     return best_result;
}

std::vector<float> RansacCalibrator::applyCalibration(
     const std::vector<float>& aiDepth, 
     double scale, 
     double offset) 
{
     std::vector<float> absoluteDsm(aiDepth.size());

     float* out_ptr = absoluteDsm.data();
     const float* in_ptr = aiDepth.data();
     size_t total_size = aiDepth.size();

     const float s = static_cast<float>(scale);
     const float o = static_cast<float>(offset);

     #pragma omp parallel for simd
     for (size_t i = 0; i < total_size; ++i) 
     {
         out_ptr[i] = s * in_ptr[i] + o;
     }

     return absoluteDsm;
}



// CalibrationResult RansacCalibrator::calculateScaleAndOffset(
//      const std::vector<float>& aiDepth, 
//      const std::vector<float>& srtmHeight) 
// {    
//      CalibrationResult best_result = {1.0, 0.0, 0};
    
//      std::vector<int> validIndices = extractValidIndices(srtmHeight);
//      int num_valid = validIndices.size();
//      if (num_valid < 2) 
//      {
//          std::cerr << "Not enough valid points for RANSAC." << std::endl;
//          return best_result;
//      }

//      //Mersenne Twister is used for random number generations  as it is more faster than normal
//      //rand and allows most performance
//      std::random_device rd;
//      std::mt19937 gen(rd());
//      std::uniform_int_distribution<> distrib(0, num_valid - 1);

//      for (int i = 0; i < iterations; ++i) 
//      {
//          //random index points selected
//          int idx1 = distrib(gen);
//          int idx2 = distrib(gen);
        
//          //this is done to make sure points are not same
//          while (idx1 == idx2) 
//          {
//              idx2 = distrib(gen);
//          }

//          int real_idx1 = validIndices[idx1];
//          int real_idx2 = validIndices[idx2];

//          double d1 = aiDepth[real_idx1];
//          double h1 = srtmHeight[real_idx1];
//          double d2 = aiDepth[real_idx2];
//          double h2 = srtmHeight[real_idx2];

//          // Prevent division by zero if depth values are identical
//          if (std::abs(d2 - d1) < 1e-6) 
//          {
//              continue;
//          }

//          //for the sample we need to calculate the scale and the offset factor which will
//          //basically be the slope and intercept of y=mx+c
//          double current_scale = (h2 - h1) / (d2 - d1);
//          double current_offset = h1 - current_scale * d1;

//          ///testing for the real data from dataset, we need to find a set with max inliers
//          int current_inliers = 0;
         
//          for (int valid_idx:validIndices) 
//          {
//              double d=aiDepth[valid_idx];
//              double h=srtmHeight[valid_idx];
//              //absolute error is calculated as there may be false results due to negatives
//              double error = std::abs(h - (current_scale * d + current_offset));
            
//              if (error <= error_threshold) 
//              {
//                  current_inliers++;
//              }
//          }
//          //max inlier res is kept for best res
//          if (current_inliers > best_result.inliers_count) 
//          {
//              best_result.inliers_count = current_inliers;
//              best_result.scale = current_scale;
//              best_result.offset = current_offset;
//          }
//      }

//      return best_result;
// }

// std::vector<float> RansacCalibrator::applyCalibration(
//      const std::vector<float>& aiDepth, 
//      double scale, 
//      double offset) 
// {
//      std::vector<float> absoluteDsm;
//      // Use resize instead of reserve to hand memory allocation to the OS instantly
//      absoluteDsm.resize(aiDepth.size());

//      // Extract raw pointers
//      float* out_ptr = absoluteDsm.data();
//      const float* in_ptr = aiDepth.data();
//      size_t total_size = aiDepth.size();

//      // Flat memory contiguous loop (Auto-vectorized by the C++ compiler)
//      for (size_t i = 0; i < total_size; ++i) 
//      {
//          out_ptr[i] = static_cast<float>(scale * in_ptr[i] + offset);
//      }

//      return absoluteDsm;
// }