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

CalibrationResult RansacCalibrator::calculateScaleAndOffset(
    const std::vector<float>& aiDepth, 
    const std::vector<float>& srtmHeight) 
{    
    CalibrationResult best_result = {0.0, 1.0, 0.0, 0, 1.0, 0.0};
    
    size_t total_size = srtmHeight.size();
    std::vector<float> compact_depth;
    std::vector<float> compact_srtm;
    compact_depth.reserve(total_size);
    compact_srtm.reserve(total_size);

    float min_d = 1e9f, max_d = -1e9f;

    for (size_t i = 0; i < total_size; ++i) 
    {
        float h = srtmHeight[i];
        float d = aiDepth[i];
        if (!std::isnan(h) && h > 0.0f && !std::isnan(d)) 
        {
            compact_depth.push_back(d);
            compact_srtm.push_back(h);
            if (d < min_d) min_d = d;
            if (d > max_d) max_d = d;
        }
    }

    int num_valid = static_cast<int>(compact_depth.size());
    if (num_valid < 3) 
    {
        std::cerr << "Not enough valid points for Quadratic RANSAC." << std::endl;
        return best_result;
    }

    // Cap RANSAC hypothesis evaluation to 30,000 representative points
    const int target_sample_size = 30000;
    int stride = std::max(1, num_valid / target_sample_size);
    int sample_size = num_valid / stride;

    std::vector<float> sample_depth(sample_size);
    std::vector<float> sample_srtm(sample_size);

    for (int i = 0; i < sample_size; ++i) 
    {
        sample_depth[i] = compact_depth[i * stride];
        sample_srtm[i]  = compact_srtm[i * stride];
    }

    const float* s_d_ptr = sample_depth.data();
    const float* s_h_ptr = sample_srtm.data();
    const float thresh   = static_cast<float>(error_threshold);
    const float min_delta_d = 0.03f * (max_d - min_d); // Require 3% dynamic range separation

    float best_hyp_a = 0.0f;
    float best_hyp_b = 1.0f;
    float best_hyp_c = 0.0f;
    int max_sample_inliers = 0;

    // Parallel hypothesis evaluation across CPU cores
    #pragma omp parallel
    {
        std::random_device rd;
        std::mt19937 gen(rd() + omp_get_thread_num());
        std::uniform_int_distribution<int> distrib(0, sample_size - 1);

        float thread_best_a = 0.0f;
        float thread_best_b = 1.0f;
        float thread_best_c = 0.0f;
        int thread_max_inliers = 0;

        #pragma omp for nowait
        for (int i = 0; i < iterations; ++i) 
        {
            int idx1 = distrib(gen);
            int idx2 = distrib(gen);
            int idx3 = distrib(gen);
            int retries = 0;

            // Reject triplets with poor depth distribution
            while (retries < 15) 
            {
                float d1 = s_d_ptr[idx1], d2 = s_d_ptr[idx2], d3 = s_d_ptr[idx3];
                if (std::abs(d1 - d2) >= min_delta_d &&
                    std::abs(d2 - d3) >= min_delta_d &&
                    std::abs(d1 - d3) >= min_delta_d) 
                {
                    break;
                }
                idx2 = distrib(gen);
                idx3 = distrib(gen);
                ++retries;
            }

            float d1 = s_d_ptr[idx1], h1 = s_h_ptr[idx1];
            float d2 = s_d_ptr[idx2], h2 = s_h_ptr[idx2];
            float d3 = s_d_ptr[idx3], h3 = s_h_ptr[idx3];

            float delta = (d1 - d2) * (d1 - d3) * (d2 - d3);
            if (std::abs(delta) < 1e-7f) continue;

            // Solve h = a*d^2 + b*d + c through the 3 sample points
            float a = (d1 * (h3 - h2) + d2 * (h1 - h3) + d3 * (h2 - h1)) / delta;
            float b = (d1 * d1 * (h2 - h3) + d2 * d2 * (h3 - h1) + d3 * d3 * (h1 - h2)) / (-delta);
            float c = h1 - a * d1 * d1 - b * d1;

            // Physical prior: terrain elevation must monotonically increase across the depth range
            // dh/dd = 2*a*d + b > 0 at both dynamic boundaries
            if ((2.0f * a * min_d + b <= 0.0f) || (2.0f * a * max_d + b <= 0.0f)) 
            {
                continue;
            }

            int current_inliers = 0;

            #pragma omp simd reduction(+:current_inliers)
            for (int j = 0; j < sample_size; ++j) 
            {
                float d = s_d_ptr[j];
                float predicted = a * d * d + b * d + c;
                if (std::abs(s_h_ptr[j] - predicted) <= thresh) 
                {
                    current_inliers++;
                }
            }

            if (current_inliers > thread_max_inliers) 
            {
                thread_max_inliers = current_inliers;
                thread_best_a = a;
                thread_best_b = b;
                thread_best_c = c;
            }
        }

        #pragma omp critical
        {
            if (thread_max_inliers > max_sample_inliers) 
            {
                max_sample_inliers = thread_max_inliers;
                best_hyp_a = thread_best_a;
                best_hyp_b = thread_best_b;
                best_hyp_c = thread_best_c;
            }
        }
    }

    // Stage 3: Analytical 3x3 OLS Solve on Full Inlier Set
    const float* d_ptr = compact_depth.data();
    const float* h_ptr = compact_srtm.data();

    double S4 = 0.0, S3 = 0.0, S2 = 0.0, S1 = 0.0;
    double T2 = 0.0, T1 = 0.0, T0 = 0.0;
    int total_inliers = 0;

    #pragma omp parallel for reduction(+:total_inliers, S4, S3, S2, S1, T2, T1, T0) schedule(static)
    for (int i = 0; i < num_valid; ++i) 
    {
        double d = static_cast<double>(d_ptr[i]);
        double h = static_cast<double>(h_ptr[i]);
        double predicted = best_hyp_a * d * d + best_hyp_b * d + best_hyp_c;

        if (std::abs(h - predicted) <= thresh) 
        {
            total_inliers++;
            double d2 = d * d;
            S4 += d2 * d2;
            S3 += d2 * d;
            S2 += d2;
            S1 += d;
            T2 += d2 * h;
            T1 += d * h;
            T0 += h;
        }
    }

    // Solve Normal Equations: A * [a, b, c]^T = B
    bool solved = false;
    double opt_a = 0.0, opt_b = 1.0, opt_c = 0.0;

    if (total_inliers >= 3) 
    {
        double M[3][4] = {
            {S4, S3, S2, T2},
            {S3, S2, S1, T1},
            {S2, S1, static_cast<double>(total_inliers), T0}
        };

        // Gaussian elimination with partial pivoting
        bool singular = false;
        for (int i = 0; i < 3; ++i) 
        {
            int max_row = i;
            double max_val = std::abs(M[i][i]);
            for (int k = i + 1; k < 3; ++k) 
            {
                if (std::abs(M[k][i]) > max_val) 
                {
                    max_val = std::abs(M[k][i]);
                    max_row = k;
                }
            }
            if (max_val < 1e-12) 
            {
                singular = true;
                break;
            }
            if (max_row != i) 
            {
                for (int c = i; c <= 3; ++c) std::swap(M[i][c], M[max_row][c]);
            }
            for (int k = i + 1; k < 3; ++k) 
            {
                double factor = M[k][i] / M[i][i];
                for (int c = i; c <= 3; ++c) 
                {
                    M[k][c] -= factor * M[i][c];
                }
            }
        }

        if (!singular) 
        {
            double sol[3] = {0.0, 0.0, 0.0};
            for (int i = 2; i >= 0; --i) 
            {
                double sum = M[i][3];
                for (int j = i + 1; j < 3; ++j) 
                {
                    sum -= M[i][j] * sol[j];
                }
                sol[i] = sum / M[i][i];
            }

            opt_a = sol[0];
            opt_b = sol[1];
            opt_c = sol[2];

            // Verify monotonicity on fitted solution
            if ((2.0 * opt_a * min_d + opt_b > 0.0) && (2.0 * opt_a * max_d + opt_b > 0.0)) 
            {
                solved = true;
            }
        }
    }

    if (solved) 
    {
        best_result.a = opt_a;
        best_result.b = opt_b;
        best_result.c = opt_c;
        best_result.scale = opt_b;
        best_result.offset = opt_c;
        best_result.inliers_count = total_inliers;
        return best_result;
    }

    // Fallback to sample hypothesis if numerical solve degenerate
    best_result.a = static_cast<double>(best_hyp_a);
    best_result.b = static_cast<double>(best_hyp_b);
    best_result.c = static_cast<double>(best_hyp_c);
    best_result.scale = static_cast<double>(best_hyp_b);
    best_result.offset = static_cast<double>(best_hyp_c);
    best_result.inliers_count = total_inliers;

    return best_result;
}


std::vector<float> RansacCalibrator::applyCalibration(
    const std::vector<float>& aiDepth, 
    double a, 
    double b, 
    double c) 
{
    std::vector<float> absoluteDsm(aiDepth.size());

    float* out_ptr = absoluteDsm.data();
    const float* in_ptr = aiDepth.data();
    size_t total_size = aiDepth.size(); 

    const float fa = static_cast<float>(a);
    const float fb = static_cast<float>(b);
    const float fc = static_cast<float>(c);

    #pragma omp parallel for simd schedule(static)
    for (size_t i = 0; i < total_size; ++i) 
    {
        float d = in_ptr[i];
        out_ptr[i] = fa * d * d + fb * d + fc;
    }

    return absoluteDsm;
}


std::vector<float> RansacCalibrator::applyCalibration(
    const std::vector<float>& aiDepth, 
    double scale, 
    double offset) 
{
    return applyCalibration(aiDepth, 0.0, scale, offset);
}




// CalibrationResult RansacCalibrator::calculateScaleAndOffset(
//     const std::vector<float>& aiDepth, 
//     const std::vector<float>& srtmHeight) 
// {    
//     CalibrationResult best_result = {1.0, 0.0, 0};
    
//     size_t total_size = srtmHeight.size();
//     std::vector<float> compact_depth;
//     std::vector<float> compact_srtm;
//     compact_depth.reserve(total_size);
//     compact_srtm.reserve(total_size);

//     float min_d = 1e9f, max_d = -1e9f;

//     for (size_t i = 0; i < total_size; ++i) 
//     {
//         float h = srtmHeight[i];
//         float d = aiDepth[i];
//         if (!std::isnan(h) && h > 0.0f && !std::isnan(d)) 
//         {
//             compact_depth.push_back(d);
//             compact_srtm.push_back(h);
//             if (d < min_d) min_d = d;
//             if (d > max_d) max_d = d;
//         }
//     }

//     int num_valid = static_cast<int>(compact_depth.size());
//     if (num_valid < 2) 
//     {
//         std::cerr << "Not enough valid points for RANSAC." << std::endl;
//         return best_result;
//     }

//      // Cap RANSAC hypothesis evaluation to 30,000 representative points.
//      const int target_sample_size = 30000;
//      int stride = std::max(1, num_valid / target_sample_size);
//      int sample_size = num_valid / stride;

//      std::vector<float> sample_depth(sample_size);
//      std::vector<float> sample_srtm(sample_size);

//      for (int i = 0; i < sample_size; ++i) 
//      {
//          sample_depth[i] = compact_depth[i * stride];
//          sample_srtm[i]  = compact_srtm[i * stride];
//      }

//      const float* s_d_ptr = sample_depth.data();
//      const float* s_h_ptr = sample_srtm.data();
//      const float thresh   = static_cast<float>(error_threshold);
//      const float min_delta_d = 0.03f * (max_d - min_d); // Require 3% dynamic range baseline

//      float best_hyp_scale  = 1.0f;
//      float best_hyp_offset = 0.0f;
//      int max_sample_inliers = 0;

//      //execute consensus search over the sub sample in parallel using all CPU cores
//      #pragma omp parallel
//      {
//          std::random_device rd;
//          std::mt19937 gen(rd() + omp_get_thread_num());
//          std::uniform_int_distribution<int> distrib(0, sample_size - 1);
 
//          float thread_best_scale  = 1.0f;
//          float thread_best_offset = 0.0f;
//          int thread_max_inliers   = 0;
 
//          #pragma omp for nowait
//          for (int i = 0; i < iterations; ++i) 
//          {
//              int idx1 = distrib(gen);
//              int idx2 = distrib(gen);
//              int retries = 0;
 
//              // Reject degenerate pairs with inadequate depth separation
//              while ((idx1 == idx2 || std::abs(s_d_ptr[idx2] - s_d_ptr[idx1]) < min_delta_d) && ++retries < 15) 
//              {
//                  idx2 = distrib(gen);
//              }

//              float d1 = s_d_ptr[idx1], h1 = s_h_ptr[idx1];
//              float d2 = s_d_ptr[idx2], h2 = s_h_ptr[idx2];
//              float delta_d = d2 - d1;

//              if (std::abs(delta_d) < 1e-6f) continue;

//              float current_scale  = (h2 - h1) / delta_d;
//              float current_offset = h1 - current_scale * d1;

//              // Physical prior: scale must be positive
//              if (current_scale <= 0.0f) continue;

//              int current_inliers = 0;

//              #pragma omp simd reduction(+:current_inliers)
//              for (int j = 0; j < sample_size; ++j) 
//              {
//                  float predicted = current_scale * s_d_ptr[j] + current_offset;
//                  if (std::abs(s_h_ptr[j] - predicted) <= thresh) 
//                  {
//                      current_inliers++;
//                  }
//              }

//              if (current_inliers > thread_max_inliers) 
//              {
//                  thread_max_inliers   = current_inliers;
//                  thread_best_scale    = current_scale;
//                  thread_best_offset   = current_offset;
//              }
//          }

//          #pragma omp critical
//          {
//              if (thread_max_inliers > max_sample_inliers) 
//              {
//                  max_sample_inliers = thread_max_inliers;
//                  best_hyp_scale     = thread_best_scale;
//                  best_hyp_offset    = thread_best_offset;
//              }
//          }
//      }

//      //performing inlier on the full data set
//      // Closed-form analytical solve to minimize sum of squared elevation errors.
//      const float* d_ptr = compact_depth.data();
//      const float* h_ptr = compact_srtm.data();

//      double sum_d = 0.0, sum_h = 0.0, sum_dd = 0.0, sum_dh = 0.0;
//      int total_inliers = 0;

//      #pragma omp parallel for reduction(+:total_inliers, sum_d, sum_h, sum_dd, sum_dh) schedule(static)
//      for (int i = 0; i < num_valid; ++i) 
//      {
//          float d = d_ptr[i];
//          float h = h_ptr[i];
//          float predicted = best_hyp_scale * d + best_hyp_offset;

//          if (std::abs(h - predicted) <= thresh) 
//          {
//              total_inliers++;
//              sum_d  += static_cast<double>(d);
//              sum_h  += static_cast<double>(h);
//              sum_dd += static_cast<double>(d) * d;
//              sum_dh += static_cast<double>(d) * h;
//          }
//      }

//      // Solve Normal Equations: (X^T * X) * beta = X^T * y
//      double denominator = static_cast<double>(total_inliers) * sum_dd - sum_d * sum_d; 

//      if (total_inliers >= 2 && std::abs(denominator) > 1e-9)  
//      {
//          double optimal_scale = (static_cast<double>(total_inliers) * sum_dh - sum_d * sum_h) / denominator;
//          double optimal_offset = (sum_h - optimal_scale * sum_d) / static_cast<double>(total_inliers);

//          //check for physical validity
//          if (optimal_scale > 0.0) 
//          {
//              best_result.scale = optimal_scale;
//              best_result.offset = optimal_offset;
//              best_result.inliers_count = total_inliers;
//              return best_result;
//          }
//      }

//      // Fallback to sample hypothesis if OLS degenerate
//      best_result.scale = static_cast<double>(best_hyp_scale);
//      best_result.offset = static_cast<double>(best_hyp_offset);
//      best_result.inliers_count = total_inliers;

//      return best_result;
// }


// std::vector<int> RansacCalibrator::extractValidIndices(const std::vector<float>& srtmHeight) 
// {
//      std::vector<int> validIndices;
//      size_t total_size = srtmHeight.size();
//      if (total_size == 0) 
//      {
//          return validIndices;
//      }

//      validIndices.reserve(total_size);
//      // Sequential single-direction pass gives optimal L1/L2 cache prefetching
//      for (size_t i = 0; i < total_size; ++i) 
//      {
//          float val = srtmHeight[i];
//          if (!std::isnan(val) && val > 0.0f) 
//          {
//              validIndices.push_back(static_cast<int>(i));
//          }
//      }
//      return validIndices;
// }


// RansacCalibrator::RansacCalibrator(int iterations_count, double threshold) 
//      : iterations(iterations_count), error_threshold(threshold) {}



// //srtm height will contain quiet_NaN values for void, so before calling this function we need to do a sweep
// //of the srtmHeight 1d flattened matrix to get validIndices and reduce load on rand num generator
// CalibrationResult RansacCalibrator::calculateScaleAndOffset(
//     const std::vector<float>& aiDepth, 
//     const std::vector<float>& srtmHeight) 
// {    
//      CalibrationResult best_result = {1.0, 0.0, 0};
    
//      //Extract valid points upfront into contiguous, flat arrays
//      size_t total_size = srtmHeight.size();
//      std::vector<float> compact_depth;
//      std::vector<float> compact_srtm;
//      compact_depth.reserve(total_size);
//      compact_srtm.reserve(total_size);

//      for (size_t i = 0; i < total_size; ++i) 
//      {
//          float h = srtmHeight[i];
//          if (!std::isnan(h) && h > 0.0f) 
//          {
//              compact_depth.push_back(aiDepth[i]);
//              compact_srtm.push_back(h);
//          }
//      }

//      int num_valid = static_cast<int>(compact_depth.size());
//      if (num_valid < 2) 
//      {
//          std::cerr << "Not enough valid points for RANSAC." << std::endl;
//          return best_result;
//      }

//      // Direct pointers for SIMD auto-vectorization
//      const float* d_ptr = compact_depth.data();
//      const float* h_ptr = compact_srtm.data();
//      const float thresh = static_cast<float>(error_threshold);

//      //Parallelize across all CPU cores with OpenMP
//      #pragma omp parallel
//      {
//          // Thread-safe, uniquely seeded RNG per thread (No locks/contention)
//          std::random_device rd;
//          std::mt19937 gen(rd() + omp_get_thread_num());
//          std::uniform_int_distribution<int> distrib(0, num_valid - 1);

//          CalibrationResult local_best = {1.0, 0.0, 0};

//          // Distribute the iterations evenly across worker threads
//          #pragma omp for nowait
//          for (int i = 0; i < iterations; ++i) 
//          {
//              int idx1 = distrib(gen);
//              int idx2 = distrib(gen);
            
//              while (idx1 == idx2) 
//              {
//                  idx2 = distrib(gen);
//              }

//              float d1 = d_ptr[idx1];
//              float h1 = h_ptr[idx1];
//              float d2 = d_ptr[idx2];
//              float h2 = h_ptr[idx2];

//              if (std::abs(d2 - d1) < 1e-6f) 
//              {
//                  continue;
//              }

//              float current_scale = (h2 - h1) / (d2 - d1);
//              float current_offset = h1 - current_scale * d1;

//              //Inner Loop: Flat memory + SIMD vector reduction
//              int current_inliers = 0;

//              #pragma omp simd reduction(+:current_inliers)
//              for (int j = 0; j < num_valid; ++j) 
//              {
//                  float predicted = current_scale * d_ptr[j] + current_offset;
//                  float error = std::abs(h_ptr[j] - predicted);
//                  if (error <= thresh) 
//                  {
//                      current_inliers++;
//                  }
//              }

//              // Track thread-local best
//              if (current_inliers > local_best.inliers_count) 
//              {
//                  local_best.inliers_count = current_inliers;
//                  local_best.scale = static_cast<double>(current_scale);
//                  local_best.offset = static_cast<double>(current_offset);
//              }
//          }

//          //Merge results once per thread at the end
//          #pragma omp critical
//          {
//              if (local_best.inliers_count > best_result.inliers_count) 
//              {
//                  best_result = local_best;
//              }
//          }
//      }

//      return best_result;
// }

// std::vector<float> RansacCalibrator::applyCalibration(
//      const std::vector<float>& aiDepth, 
//      double scale, 
//      double offset) 
// {
//      std::vector<float> absoluteDsm(aiDepth.size());

//      float* out_ptr = absoluteDsm.data();
//      const float* in_ptr = aiDepth.data();
//      size_t total_size = aiDepth.size();

//      const float s = static_cast<float>(scale);
//      const float o = static_cast<float>(offset);

//      #pragma omp parallel for simd
//      for (size_t i = 0; i < total_size; ++i) 
//      {
//          out_ptr[i] = s * in_ptr[i] + o;
//      }

//      return absoluteDsm;
// }
