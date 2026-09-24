#pragma once

#include "../../structures/SemanticInferenceTypes.h"
#include <string>
#include <stdexcept>
#include <span>

class SemanticResponseValidator 
{
public:
    // Mathematically validates the tensor outputs.
    // If a pixel is marked invalid (mask == 0), it normalizes the data to 
    // prevent downstream corruption during Hann window stitching.
  

    static void validateAndNormalize(
        SemanticTileResult& result,
        std::span<const uint8_t> preprocessingMask);

private:
    static void validateGridShape(int expectedWidth, int expectedHeight, size_t expectedSize, 
                                  int gridWidth, int gridHeight, size_t gridSize, 
                                  const std::string& gridName);
};