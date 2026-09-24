// main model coordinator
// initiates window dispatching

#pragma once
#include <drogon/drogon.h>
#include <drogon/utils/coroutine.h>
#include "../structures/IngestionStructs.h"
#include "../structures/DualModelInferenceTypes.h"
#include "Tiling/TileDispatcher.h"

class TilingService 
{
    public:
    
    // initiates the tiling and dispatching process 
    // Hann Assembler stitching logic will later attach to this
    // inputs: scene & quality metrics
    // outputs: TiledInferencePayload - collection of raw AI tiles to be stitched

    static drogon::Task<DualModelInferenceBundle> generateStitchedInference(
        const SceneInput& scene, 
        const ImageQualityResult& quality);
};
