#pragma once
#include <vector>
#include <InferenceStructs.h>

struct TiledInferencePayload
{
    int globalWidth;
    int globalHeight;
    std::vector<TileInferenceResult> allTiles;
};
