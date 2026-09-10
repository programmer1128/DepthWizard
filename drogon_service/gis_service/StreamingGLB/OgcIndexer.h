#pragma once

#include "../utils/QuadTreeTypes.h"
#include <json/json.h>
#include <string>

class OgcIndexer 
{
    public:

    // takes the populated graph and the GDAL geoTransform array to calculate true GPS coordinates
    // generates the final tileset.json
    // uploads it to MinIO storage
    static std::string buildAndUploadTileset(const QuadTreeGraph& graph, const double geoTransform[6]);

    // recursive BFS helper function
    static Json::Value serializeNode(const QuadTreeGraph& graph, uint32_t current_id, const double geoTransform[6]);
    
    // dynamic math conversion from pixels to GPS radians
    // for OGC official format
    static Json::Value calculateDynamicBounds(const MatrixBounds& bounds, const double geoTransform[6]);
};