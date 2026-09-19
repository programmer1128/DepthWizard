// top level coordinator for branch B (absolute terrain preparation)
// fetches remote reference datasets, reprojects them onto the scene's spatial grid
// and cleans them into a bare-earth DTM prior

#pragma once

#include <drogon/drogon.h>
#include <drogon/utils/coroutine.h>
#include "../structures/IngestionStructs.h"
#include "ReferenceDemPreprocessor.h"

class MetricReferenceOrchestrator 
{
    public:
    
    // orchestrates the entire Branch B workflow asynchronously
    // scene: contains the image file path and SpatialMetadata
    // ReferenceTerrainBundle: clean, georeferenced bare-earth DTM and confidence grid
    static drogon::Task<ReferenceTerrainBundle> prepareReferenceTerrain(
        const SceneInput& scene);
};