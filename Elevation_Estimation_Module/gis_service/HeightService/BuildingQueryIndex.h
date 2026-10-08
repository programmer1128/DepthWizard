#pragma once
#include "../structures/CommonTypes.h"
#include "../structures/GeographicStructs.h"

#include <json/value.h>

#include <cstdint>
#include <string>
#include <unordered_map>

// What a height query answers for one building. IDs are the building IDs the
// GLB carries in _FEATURE_ID_0, so a clicked roof or wall maps straight here.
struct BuildingQueryRecord
{
     uint32_t id{0};
     // Height above ground from the nDSM, without the render exaggeration.
     float heightMeters{0.0f};
     float baseElevationMeters{0.0f};
     float roofElevationMeters{0.0f};
     float footprintAreaSquareMetres{0.0f};
};

// Per-job lookup for height queries: the building records, plus a raster of
// building IDs so a click can also be resolved from its position alone.
struct BuildingQueryIndex
{
     RasterGrid<float> labels; // building ID per pixel, 0 = no building
     std::unordered_map<uint32_t, BuildingQueryRecord> buildings;
     float renderHeightScale{1.0f};
     std::string source;

     // heightScaleMultiplier is the exaggeration baked into
     // BuildingInstance::heightAboveGround for rendering; it is removed here.
     static BuildingQueryIndex build(const BuildingCollection& collection,
                                     const SpatialMetadata& metadata,
                                     float heightScaleMultiplier,
                                     std::string source);

     Json::Value recordsToJson() const;
     // Restores the records only; labels stay empty.
     static BuildingQueryIndex recordsFromJson(const Json::Value& document);

     const BuildingQueryRecord* find(uint32_t id) const;
};
