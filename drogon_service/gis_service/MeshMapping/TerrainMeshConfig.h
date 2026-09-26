#pragma once

#include <cmath>

enum class TerrainElevationSource
{
     BARE_EARTH,
     SURFACE_PREVIEW,
     FLAT_PRESENTATION
};

struct TerrainMeshConfig 
{
     int maxGridSize{512};
     float skirtDepth{2.0f};
     bool generateSkirt{true};

     // A reconstructed scene uses DTM for its continuous ground mesh and
     // separate objects for buildings. DSM is available as an explicit
     // scientific surface preview, never a fallback for rejected buildings.
     TerrainElevationSource elevationSource{TerrainElevationSource::BARE_EARTH};

     // The analysis DSM remains untouched. For rendering only, accepted
     // building footprints are replaced by DTM samples so the textured
     // terrain does not contain a second, smooth copy of each building.
     // A small clearance absorbs semantic edge blur at roof boundaries.
     // Must cover at least one decimated terrain cell for common 0.5-1 m GSD
     // imagery, otherwise a terrain triangle can bridge across the footprint.
     float buildingTerrainClearanceMetres{3.0f};

     // Render-only optical repair around accepted extrusions. This hides a
     // narrow photographic roof fringe without removing distant roads or
     // changing the original imagery and metric raster products.
     float buildingTextureHaloMetres{1.0f};

     bool validate() const
     {
          return (elevationSource == TerrainElevationSource::BARE_EARTH ||
                  elevationSource == TerrainElevationSource::SURFACE_PREVIEW ||
                  elevationSource == TerrainElevationSource::FLAT_PRESENTATION) &&
               maxGridSize >= 2 &&
               std::isfinite(skirtDepth) && skirtDepth >= 0.0f &&
               std::isfinite(buildingTerrainClearanceMetres) &&
               buildingTerrainClearanceMetres >= 0.0f &&
               buildingTerrainClearanceMetres <= 10.0f &&
               std::isfinite(buildingTextureHaloMetres) &&
               buildingTextureHaloMetres >= 0.0f &&
               buildingTextureHaloMetres <= 3.0f;
     }
};
