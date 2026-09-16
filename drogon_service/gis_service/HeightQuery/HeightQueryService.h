#pragma once
#include <string>
#include <drogon/drogon.h>

struct HeightResult 
{
    bool success;
    float elevation;
    std::string error_message;
};

class HeightQueryService 
{
     public:
     
     //method to fetch the tile from the .tif and get the real height
     static HeightResult extractElevationFromMinIO(const std::string& uuid, float click_x, float click_z);
};