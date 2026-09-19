#pragma once
#include <vector>
#include <memory>
#include <cstdint>
#include "../structures/TileGraph.h"
#include "../structures/InferenceStructs.h"

// stores the zero copy AI output
// stores the details of each tile
// each tile is 518 * 518

struct TileMetadata 
{
    uint32_t tile_id; // unsigned 32 bit int, no -ve numbers, unique id to each tile

    // dimensions of the tile
    int width;
    int height;

    // displacement from top left of image
    // to know where the tile lies in the image
    int x_offset;
    int y_offset;

    // a topographical texture score
    // high: bumpy mountain ; low: flat lake
    float variance; 
    

    // std::shared_ptr guarantees we do not copy the massive float matrix in RAM
    // we just share the memory address of existing array
    std::shared_ptr<std::vector<float>> depth_matrix; 
};


// struct containing every single processed tile for the whole image
// to send to Hann assembler for stitching

struct TiledInferencePayload 
{
    int globalWidth;
    int globalHeight;
    std::vector<TileInferenceResult> allTiles;
};


// struct to hold one 518x518 square of the image ready to be sent to the model

struct TileRequest 
{
    uint32_t tileId;       // unique number for this square
    int xOffset;           // distance from the left edge of the main image
    int yOffset;           // distance from the top edge of the main image
    int width;             // always 518
    int height;            // always 518

    // we must track the valid area so the stitcher knows what to ignore
    int validWidth;        
    int validHeight;
    
    // normalized colors (RGB) for the model
    std::vector<float> normalizedRgbBytes;
    
    // the black-and-white safety map (1 = safe, 0 = cloud/shadow)
    std::vector<uint8_t> validMaskBytes;
};