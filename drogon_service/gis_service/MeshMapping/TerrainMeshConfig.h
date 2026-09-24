#pragma once

#include <cmath>

struct TerrainMeshConfig 
{
     int maxGridSize{512};
     float skirtDepth{50.0f};

     // The analysis DSM remains untouched. For rendering only, accepted
     // building footprints are replaced by DTM samples so the textured
     // terrain does not contain a second, smooth copy of each building.
     // A small clearance absorbs semantic edge blur at roof boundaries.
     // Must cover at least one decimated terrain cell for common 0.5-1 m GSD
     // imagery, otherwise a terrain triangle can bridge across the footprint.
     float buildingTerrainClearanceMetres{3.0f};

     bool validate() const
     {
          return maxGridSize >= 2 &&
               std::isfinite(skirtDepth) && skirtDepth >= 0.0f &&
               std::isfinite(buildingTerrainClearanceMetres) &&
               buildingTerrainClearanceMetres >= 0.0f &&
               buildingTerrainClearanceMetres <= 10.0f;
     }
};
