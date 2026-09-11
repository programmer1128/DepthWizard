// performs the BFS traversal on the quad tree
// build the hash maps, calculate true geographic math for OGC format
// generates and uploads the tileset.json to MinIO

#include "OgcIndexer.h"
#include "../DataHandlers/MiniIOClient.h"
#include <queue>
#include <iostream>

#define PI 3.14159265358979323846

std::string OgcIndexer::buildAndUploadTileset(const QuadTreeGraph& graph, const SpatialMetadata& meta)
{
    /*  WE DO NOT NEED THE BFS AND HASH MAPS FOR OFFICIAL OGC 3D TILES FORMAT

    // major function that runs BFS, build hash maps, generates and uploads the tileset.json

    QuadTreeRegistry registry;
    std::queue<uint32_t> bfs_queue;

    // breadth first search (BFS)

    // push first node (id 0) into queue
    bfs_queue.push(0);

    // process till the bfs is empty
    while(!bfs_queue.empty())
    {
        // take the next node out of the queue
        uint32_t current_id = bfs_queue.front();
        bfs_queue.pop();

        const QuadNode& node = graph.nodes[current_id];

        // now populate the hash maps

        // <node_id, glb_url>
        registry.url_map[current_id] = node.glb_url;

        // <level, list of node IDs of nodes in that level>
        registry.level_map[node.level].push_back(current_id);

        // now we find its children using the CSR graph
        size_t start_idx = graph.edge_markers[current_id];
        size_t end_idx = graph.edge_markers[current_id + 1];

        // my assumption:
        // edges: [1,2,3,4,5,6,7,8,.....]
        // edge_markers: [0,4,8,......]

        // now we loop through the edges array to get the children
        for (size_t idx = start_idx; idx < end_idx; ++idx)  // we stop before end_idx
        {
            uint32_t child_id = graph.edges[idx];
            bfs_queue.push(child_id);
        }
    }
    */


    OGRSpatialReference sourceSRS;
    sourceSRS.importFromWkt(meta.projectionRef.c_str());

    OGRSpatialReference targetSRS;
    targetSRS.SetWellKnownGeogCS("WGS84");

    OGRCoordinateTransformation* coordTransform = 
        OGRCreateCoordinateTransformation(&sourceSRS, &targetSRS);

    // we write the json file
    Json::Value tileset;
    tileset["asset"]["version"] = "1.0"; // required by OGC standard

     // root node determines the max error for the whole map (Physical width of the root tile in meters)
     tileset["geometricError"] = graph.nodes[0].bounds.width * meta.geoTransform[1];

     // we build the nested tree structure using our recursive helper
     tileset["root"] = serializeNode(graph, 0, meta.geoTransform.data(), coordTransform);

     if (coordTransform) 
     {
         OGRCoordinateTransformation::DestroyCT(coordTransform);
     }

     // next we convert the C++ json object into a string
     Json::StreamWriterBuilder writer;
     std::string json_payload = Json::writeString(writer, tileset);
     std::vector<uint8_t> json_bytes(json_payload.begin(), json_payload.end());

     // now we upload the rulebook to MinIO
     std::string bucket = "terrain-assets";
     std::string json_key = "tileset.json";
     MinioClient::uploadBuffer(bucket, json_key, json_bytes, "application/json");
    
     // return the final link so drogon can send it to frontend
     return MinioClient::generatePresignedUrl(bucket, json_key);
}

// recursively builds the parent/child json structure
Json::Value OgcIndexer::serializeNode(const QuadTreeGraph& graph, uint32_t current_id, 
         const double* geoTransform, 
         OGRCoordinateTransformation* coordTransform)
{
    const QuadNode& node = graph.nodes[current_id];
    Json::Value tile;

    // convert pixels to real-world GPS boundaries
    tile["boundingVolume"] = calculateDynamicBounds(node, geoTransform,coordTransform);
    

     // to inform frontend how blurry this tile is allowed to get before swapping it (Physical width in meters)
     tile["geometricError"] = node.bounds.width * geoTransform[1];
    
    // inform frontend to completely swap out the parent when loading the children
    tile["refine"] = "REPLACE"; 
    
    // the MinIO link we generated earlier
    tile["content"]["uri"] = node.glb_url;

    // check the CSR graph to see if this node has children
    size_t start_idx = graph.edge_markers[current_id];
    size_t end_idx = graph.edge_markers[current_id + 1];
    
    // if start_idx < end_idx --> means children exist
    if (start_idx < end_idx) 
    {
        Json::Value children_array(Json::arrayValue);
        for (size_t idx = start_idx; idx < end_idx; ++idx) 
        {
            uint32_t child_id = graph.edges[idx];
            
            // recursion: call this function again for the child and add it to the array
            children_array.append(serializeNode(graph, child_id, geoTransform,coordTransform));
        }
        tile["children"] = children_array;
    }

    return tile;
}



Json::Value OgcIndexer::calculateDynamicBounds(
    const QuadNode& node, 
    const double* geoTransform, 
    OGRCoordinateTransformation* coordTransform)
{
    const MatrixBounds& bounds = node.bounds;

    // 1. Teammate's original Affine math (Outputs Source CRS, e.g., UTM or Lat/Lon)
    double west_geo = geoTransform[0] + (bounds.x_offset * geoTransform[1]);
    double east_geo = geoTransform[0] + ((bounds.x_offset + bounds.width) * geoTransform[1]);
    double north_geo = geoTransform[3] + (bounds.y_offset * geoTransform[5]);
    double south_geo = geoTransform[3] + ((bounds.y_offset + bounds.height) * geoTransform[5]);

    //Apply GDAL Transform to guarantee WGS84
    double x[2] = {west_geo, east_geo};
    double y[2] = {north_geo, south_geo};
    
     if (coordTransform) 
     {
         coordTransform->Transform(2, x, y);
     }

     //Convert to Radians
     double rad_conv = PI / 180.0;
    
     //error for the 3d tiles format as shown by 3d-tiles testing 
     //The 'south' entry of the bounding region may not be larger than the 'north' entry,
     // but the south is 1.273522634791319 and the north is 1.2715418284680933
     //this part fixes that
     double true_west  = std::min(x[0], x[1]) * rad_conv;
     double true_east  = std::max(x[0], x[1]) * rad_conv;
     double true_south = std::min(y[0], y[1]) * rad_conv;
     double true_north = std::max(y[0], y[1]) * rad_conv;

     Json::Value region(Json::arrayValue);
     region.append(true_west);
     region.append(true_south);
     region.append(true_east);
     region.append(true_north);
    
     //Use the true heights calculated by the GlbFactory OpenMP loop
     region.append(node.volume.min_height); 
     region.append(node.volume.max_height); 

     Json::Value bv;
     bv["region"] = region;
     return bv;
}




// converts pixels to GPS Radians using GDAL's affine transform math
// Json::Value OgcIndexer::calculateDynamicBounds(const MatrixBounds& bounds, const double geoTransform[6])
// {
//     // GDAL geoTransform array breakdown:
//     // [0]: Top-Left X (Longitude)
//     // [1]: W-E pixel resolution (Pixel Width)
//     // [2]: Row rotation (typically 0)
//     // [3]: Top-Left Y (Latitude)
//     // [4]: Column rotation (typically 0)
//     // [5]: N-S pixel resolution (Pixel Height - usually a negative number)

//     // calculate Longitude (west and east) in degrees
//     double west_deg = geoTransform[0] + (bounds.x_offset * geoTransform[1]);
//     double east_deg = geoTransform[0] + ((bounds.x_offset + bounds.width) * geoTransform[1]);

//     // calculate Latitude (north and south) in degrees
//     double north_deg = geoTransform[3] + (bounds.y_offset * geoTransform[5]);
//     double south_deg = geoTransform[3] + ((bounds.y_offset + bounds.height) * geoTransform[5]);

//     // OGC requires radians not degrees
//     double rad_conv = PI / 180.0;
    
//     Json::Value region(Json::arrayValue);
//     region.append(west_deg * rad_conv);  // west
//     region.append(south_deg * rad_conv); // south
//     region.append(east_deg * rad_conv);  // east
//     region.append(north_deg * rad_conv); // north
//     region.append(0.0);                  // min height (meters)
//     region.append(8848.0);               // max height (meters) - roughly (Mt Everest)

//     Json::Value bv;
//     bv["region"] = region;
//     return bv;
// }