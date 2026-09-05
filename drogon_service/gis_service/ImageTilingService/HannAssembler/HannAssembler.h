#pragma once
#include <vector>
#include <Halide.h>
#include <omp.h>
// #include <mutex>

// specification of each tile
struct TileWindow
{
    int id;
    int x_off;
    int y_off;
    int x_size;
    int y_size;
};

// resolved scaling and shifting factors from BFS
typedef struct GlobalTransformations
{
    float scale; // s
    float shift; // t
} GlobalTransformations;

class HannAssembler
{
private:
    // Absolute pixel dimensions of the final target matrix
    int global_width;  // M (Columns)
    int global_height; // N (Rows)

    std::vector<TileWindow> tileBlueprints; // storing the info of generated tiles

    // 1D vectors(N*M) for memory contiguity (reduced latency) -> to be used for weighted matrix accumulation
    std::vector<float> elevationAccum; // numerator accumulator -> sum(Di*Wi)
    std::vector<float> weightAccum;    // denominator accumulator -> sum(Wi)

    // std::mutex accumMutex;


    // Halide Pipeline State
    Halide::Func tile_processor;
    Halide::Param<float> s_param;
    Halide::Param<float> t_param;
    Halide::ImageParam input_param;

    std::vector<float> threadElevationAccum;
    std::vector<float> threadWeightAccum;
    
    int num_threads;
    size_t total_frame_size;

public:
    HannAssembler(int width, int height);

    void loadTileBlueprints(std::vector<TileWindow> input_tiles);

    // Executes the Halide JIT pipeline for a single tile using the TileWindow struct
    void processAndAccumulateTile(const TileWindow &win, const std::vector<float> &raw_depth, GlobalTransformations &transformations);

    // Executes a final Halide pass to divide accumulated depths by weights
    std::vector<float> finalizeMatrix();
};