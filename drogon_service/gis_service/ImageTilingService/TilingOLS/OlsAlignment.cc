#include "OlsAlignment.h"

#include <Eigen/Dense>   // eigen library that uses SIMD for massive matrix math
#include <algorithm>
#include <cmath>
#include <vector>

// mathematical function to align two overlapping tiles
OverlapEdge OlsAlignment::computeAlignment(
     uint32_t source_id, 
     uint32_t target_id, 
     std::span<const float> source_overlap, 
     std::span<const float> target_overlap,
     float no_data_value)
{
    // GeoTiff NoData masking
    // filter out invalid edges so that they do not skew the mean

    // two empty lists to store only the valid pixels
    // optimization: thread_local memory pool - create once, use forever
    thread_local std::vector<float> clean_source;
    thread_local std::vector<float> clean_target;

    // Clear out the old data from the last time this thread ran
    clean_source.clear();
    clean_target.clear();

    // optimization: we use .reserve() to avoid resizing latency
    clean_source.reserve(source_overlap.size());
    clean_target.reserve(target_overlap.size());

    for (size_t i = 0; i < source_overlap.size(); ++i) 
    {
        // only keep the pixel if both overlapping pixels are real terrain
        if (source_overlap[i] != no_data_value && target_overlap[i] != no_data_value) 
        {
            clean_source.push_back(source_overlap[i]);
            clean_target.push_back(target_overlap[i]);
        }
    }

    // if the entire overlapping strip was blank/NoData, return immediately
    // prevents arrA.mean() from dividing by zero and crashing the system
    if (clean_source.empty()) 
    {
        // return 1.0 scale, 0.0 shift and a maximum penalty of 1.0 (0 correlation)
        return OverlapEdge{source_id, target_id, 1.0f, 0.0f, 1.0f};
    }

    // instead of copying clean vectors into an Eigen Matrix
    // Eigen::Map points directly to the vectors we already made, treating them as hardware-accelerated math arrays
    Eigen::Map<const Eigen::ArrayXf> arrA(clean_source.data(), clean_source.size());
    Eigen::Map<const Eigen::ArrayXf> arrB(clean_target.data(), clean_target.size());

    // SIMD aggregation: mean calculation
    float meanA = arrA.mean();
    float meanB = arrB.mean();

    // calc how far every single pixel in tiles deviate from their own avg
    Eigen::ArrayXf diffA = arrA - meanA;
    Eigen::ArrayXf diffB = arrB - meanB;

    // variance: mul deviations by themselves & find avg
    float varA = (diffA * diffA).mean();
    float varB = (diffB * diffB).mean();

    // mathematical shortcut: sum is just mean*count
    float sum_sq_A = varA * diffA.size();
    float sum_sq_B = varB * diffB.size();

    float scale = 1.0f;
    float shift = 0.0f;
    const float TAU = 0.001f; // tiny threshold to decide if the terrain is flat

    // variance gate and boundary clamping
    if (varB < TAU) 
    {
        // flat terrain: bypass OLS scaling bcz dividing by 0 variance crashes the maths
        // we leave scale at 1.0 (no stretching) and just shift the height up or down to match tile A
        scale = 1.0f;
        shift = meanA - meanB;
    } 
    else 
    {
        // Vectorized Ordinary Least Squares - OLS
        
        // OLS numerator: sum of (tile B deviations * tile A deviations)
        float numerator = (diffB * diffA).sum();
        
        // OLS denominator: sum of (tile B deviations squared) 
        // add 1e-6f (a microscopic number) as a final safety net against division by zero
        float denominator = sum_sq_B + 1e-6f;

        // s multiplier
        scale = numerator / denominator;
        
        // Boundary Clamping
        // strictly limit the multiplier between 0.5 and 2.0
        // to prevent negative numbers from flipping mountains upside down into valleys
        scale = std::clamp(scale, 0.5f, 2.0f); 
        
        // t addition using clamped scale
        shift = meanA - (scale * meanB);
    }

    // Pearson correlation edge weight calc

    // pearson numerator: covariance of A and B
    float num_pearson = (diffA * diffB).sum();
    
    // pearson denominator: sq. root of the product of their individual variances
    float den_pearson = std::sqrt(sum_sq_A * sum_sq_B);

    // pearson correlation score (1.0 = perfect match, 0.0 = completely unrelated)
    float pearson = (den_pearson > 1e-6f) ? (num_pearson / den_pearson) : 0.0f;
    
    // conversion of correlation into penalty 
    // a high correlation (0.95) becomes a tiny penalty (0.05) 
    // graph will favor connections with tiny penalties
    float penalty = 1.0f - pearson;

    // final struct packaging
    return OverlapEdge{source_id, target_id, scale, shift, penalty};
}