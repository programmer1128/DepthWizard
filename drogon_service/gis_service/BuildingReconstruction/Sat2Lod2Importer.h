#pragma once
#include "BuildingReconstructionConfig.h"
#include "../structures/GeographicStructs.h"
#include "../structures/SurfaceStructs.h"

#include <json/value.h>

#include <string>
#include <vector>

struct Sat2Lod2ImportResult
{
     BuildingCollection buildings;
     std::size_t segmentCount{0};
     std::size_t irregularCount{0};
     std::size_t residualPartCount{0};
     std::size_t skippedSegmentCount{0};
     std::vector<std::string> warnings;
};

// Converts the SAT2LoD2 microservice's parametric output (buildings.json,
// schema depthwizard.sat2lod2.v1) into native building instances.
//
// SAT2LoD2 contributes only 2D geometry: each rectangle of its decomposition
// becomes one building part, separated from its neighbours, and a segment
// without rectangles is extruded from its regularized footprint. Every height
// and base elevation is measured from the backend's corrected nDSM and DTM by
// BuildingHeightEstimator, exactly as for natively reconstructed buildings,
// so both paths share one height scale.
class Sat2Lod2Importer
{
     public:
     static Sat2Lod2ImportResult import(
         const Json::Value& document,
         const SemanticScene& semantics,
         const GeoreferencedSurfaceBundle& surface,
         const SpatialMetadata& metadata,
         const BuildingReconstructionConfig& config,
         const RasterGrid<float>& reconstructionNdsm);

     static Sat2Lod2ImportResult importFile(
         const std::string& path,
         const SemanticScene& semantics,
         const GeoreferencedSurfaceBundle& surface,
         const SpatialMetadata& metadata,
         const BuildingReconstructionConfig& config,
         const RasterGrid<float>& reconstructionNdsm);

     // SAT2LoD2 drops small segments whose rectangle fit fails. Keep native
     // buildings that SAT2LoD2 footprints cover by at most
     // maxCoveredFraction of their area, renumbered after the SAT buildings.
     // Returns the number of native buildings kept.
     static std::size_t appendUncoveredNative(
         BuildingCollection& target,
         const BuildingCollection& native,
         const SpatialMetadata& metadata,
         float maxCoveredFraction = 0.10f);
};
