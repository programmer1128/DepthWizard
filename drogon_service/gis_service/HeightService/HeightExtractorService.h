#pragma once
#include <string>
#include <vector>
#include <cstdint>

// Stores the un-warped Real-World Coordinates for the Reference APIs
struct GeoWindowContext {
    double minLon, maxLon, minLat, maxLat;
    int pixel_x, pixel_y;
    int width, height;
};

class HeightExtractorService {
public:
    // Flow 1: Extracts a single exact height point (returns elevation in meters)
    static float getExactElevation(const std::string& uuid, float x, float y);

    // Flow 2: Carves out a GDAL window and returns an in-memory .tif buffer
    static std::vector<uint8_t> extractWindowTiff(
        const std::string& uuid, 
        float x, float y, 
        int window_size, 
        GeoWindowContext& outContext);
};