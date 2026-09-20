#pragma once
#include <vector>
#include "../structures/InferenceStructs.h"

struct TiledInferencePayload
{
    int globalWidth;
    int globalHeight;
    std::vector<TileInferenceResult> allTiles;
};
