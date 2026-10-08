#pragma once

#include "City3dTypes.h"
#include "../structures/SurfaceStructs.h"

#include <json/value.h>
#include <string>

class City3dOrchestrator
{
public:
     // Analyses every native building, routes at most config.maxBuildings
     // eligible non-flat ones (largest footprint first) through the local
     // worker, one at a time, and imports validated shells. It never changes
     // `buildings`; every failure leaves that building native.
     static City3dRunSummary run(
         const BuildingCollection& buildings,
         const RasterGrid<int32_t>& instanceLabels,
         const SemanticScene& semantics,
         const GeoreferencedSurfaceBundle& surface,
         const RasterGrid<float>& correctedMetricNdsm,
         const SpatialMetadata& metadata,
         float renderHeightScale,
         const City3dConfig& config,
         const std::string& jobId);

     // Attaches accepted shells to buildings with the same ID; returns how many.
     static std::size_t attachAcceptedShells(BuildingCollection& buildings, const City3dRunSummary& summary);

     static Json::Value toJson(const City3dRunSummary& summary);
};
