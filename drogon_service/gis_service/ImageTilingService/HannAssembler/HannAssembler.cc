#include "HannAssembler.h"
#include <Halide.h>
#include <cmath>
#include <limits>
#include <atomic>

#ifndef M_PI
#define M_PI 3.14159265358979323846f
#endif

// Constructor
HannAssembler::HannAssembler(int width, int height) : global_width(width), global_height(height)
{
    size_t total_size = static_cast<size_t>(width) * static_cast<size_t>(height);

    // memory allocation without initialisation
    elevationAccum.resize(total_size);
    weightAccum.resize(total_size);

    // parallel zero-filling to reduce latency for larger grids
#pragma omp parallel for simd
    for (size_t i = 0; i < total_size; ++i)
    {
        elevationAccum[i] = 0.0f;
        weightAccum[i] = 0.0f;
    }
}

void HannAssembler::loadTileBlueprints(std::vector<TileWindow> input_tiles) // from Satadru
{
    this->tileBlueprints = std::move(input_tiles);
}

void HannAssembler::processAndAccumulateTile(const TileWindow &win, const std::vector<float> &raw_depth, GlobalTransformations &transformations)
{
    // extracting the parameters directly from TileWindow struct
    int x_off = win.x_off;
    int y_off = win.y_off;
    int tile_w = win.x_size;
    int tile_h = win.y_size;

    float s_global = transformations.scale;
    float t_global = transformations.shift;

    Halide::Var x("x"), y("y"); // declaration of two symbolic placeholders (for cols and rows)

    // raw_depth -> Di(x,y) : received from OpenMP multithreaded orchestrator (chunk of uncalibrated elevation pixels)
    Halide::Buffer<const float> input_buf(raw_depth.data(), tile_w, tile_h); // takes the 1D C++ vector and maps it into a 2D spatial grid -> allowing Halide to access the depth values using geometric (x, y) coordinates instead of flat memory indices

    // PHASE 1: HALIDE PIPELINE DEFINITION
    Halide::Func tile_processor("tile_processor"); // placeholder to define the mathematical rule for output matrix

    // Expr (Expression) is a node in Halide's abstract syntax tree -> injecting a constant into Halide's symbolic math engine
    // 1D Hann Window Generation -> w(i) function [ w(i) = (1/2) * ( 1 - (cos ((2*pi*i)/overlap-1) ) ]
    Halide::Expr pi = static_cast<float>(M_PI);
    Halide::Expr hann_x = 0.5f * (1.0f - Halide::cos((2.0f * pi * x) / (tile_w - 1.0f)));
    Halide::Expr hann_y = 0.5f * (1.0f - Halide::cos((2.0f * pi * y) / (tile_h - 1.0f)));

    // 2D Alpha Mask Outer : Wi(x,y) = wx(x) * wy(y) -> to form a 2D dome-like alpha mask
    Halide::Expr weight = hann_x * hann_y;
    // Halide::Expr weight = Halide::max(hann_x * hann_y, 1e-6f); // ensures min wt is very little greater than 0 to avoid divide-by-zero crash

    // Matrix Transformation: D_aligned(x,y) = s_global * D(x,y) + t_global
    Halide::Expr d_aligned = (s_global * input_buf(x, y)) + t_global;

    // defines the final output of the Func -> the pipeline will output two distinct 2D matrices (pre-multiplied depth and the isolated weight) simultaneously in a single hardware pass
    tile_processor(x, y) = Halide::Tuple(weight * d_aligned, weight);

    // PHASE 2: HARDWARE SCHEDULING
    // SIMD vectorization across rows and parallelize execution (multithreading)
    tile_processor.compute_root()
        .vectorize(x, 8)
        .parallel(y);

    // PHASE 3: EXECUTION
    Halide::Buffer<float> local_weighted_depth(tile_w, tile_h);
    Halide::Buffer<float> local_weights(tile_w, tile_h);
    Halide::Realization realization({local_weighted_depth, local_weights});

    // triggers Halide's Just-In-Time (JIT) compiler -> compiles the algorithm into machine code, executes the SIMD/multithreaded operations, and fills the two local buffers with the results
    tile_processor.realize(realization);

    // PHASE 4: GLOBAL ACCUMULATION
    // for freezing current thread until the global memory is safe to access to prevent thread collisions
    // std::lock_guard<std::mutex> lock(accumMutex);

    const float *raw_weighted_depth = local_weighted_depth.data();
    const float *raw_weights = local_weights.data();

    for (int r = 0; r < tile_h; ++r)
    {
        int global_base_idx = (y_off + r) * global_width + x_off;
        int local_base_idx = r * tile_w;

        // contiguous memory accumulation
        for (int c = 0; c < tile_w; ++c)
        {
            // Thread-safe atomic addition on the exact memory addresses
            // std::atomic_ref<float>(elevationAccum[global_base_idx + c]) += raw_weighted_depth[local_base_idx + c];
            // std::atomic_ref<float>(weightAccum[global_base_idx + c]) += raw_weights[local_base_idx + c];

            // OpenMP atomics instead of std::atomic_ref to reduce cache-line contention overhead
#pragma omp atomic update
            elevationAccum[global_base_idx + c] += raw_weighted_depth[local_base_idx + c]; // sum(Di*Wi)
#pragma omp atomic update
            weightAccum[global_base_idx + c] += raw_weights[local_base_idx + c]; // sum(Wi)
        }
    }
}

std::vector<float> HannAssembler::finalizeMatrix()
{
    std::vector<float> final_matrix(global_width * global_height); // 1D contiguous block

    // Wraps Halide interfaces around your existing C++ raw memory pointers (.data())
    Halide::Buffer<const float> accum_buf(elevationAccum.data(), global_width * global_height);
    Halide::Buffer<const float> weight_buf(weightAccum.data(), global_width * global_height);
    Halide::Buffer<float> output_buf(final_matrix.data(), global_width * global_height);

    Halide::Var i("i");
    Halide::Func finalizer("finalizer");

    // D_final(x,y) = Numerator / Denominator
    Halide::Expr nan_val = Halide::cast<float>(std::numeric_limits<float>::quiet_NaN());
    finalizer(i) = Halide::select(weight_buf(i) > 0.0f, accum_buf(i) / weight_buf(i), nan_val);

    Halide::Var i_outer, i_inner;
    finalizer.compute_root()
        .split(i, i_outer, i_inner, 10000) // spliting into chunks of 10000
        .parallel(i_outer)                 // parallelization across the chunks
        .vectorize(i_inner, 16);           // vectorizing the inner chunk execution

    finalizer.realize(output_buf);

    return final_matrix;
}