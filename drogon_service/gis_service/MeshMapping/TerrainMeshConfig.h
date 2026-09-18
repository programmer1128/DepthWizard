#pragma once

struct TerrainMeshConfig 
{
     int maxGridSize{512};    // Dynamically calculates stride to prevent massive vertex counts
     float skirtDepth{50.0f}; // How far the pedestal drops below the lowest point[cite: 11]
};