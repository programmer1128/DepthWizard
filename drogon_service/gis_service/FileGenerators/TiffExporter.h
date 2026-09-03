#pragma once
#include <string>
#include <vector>

class TiffExporter {
public:
    static bool writeFloatTiff(
        const std::string& outputPath, 
        std::vector<float>& dsm_matrix, 
        int width, 
        int height,
        double* geoTransform, // Required to map pixels back to lat/lon on the frontend
        const char* projectionRef
    );
};