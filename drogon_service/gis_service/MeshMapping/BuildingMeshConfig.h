#pragma once

#include <cmath>

struct BuildingMeshConfig 
{
     bool flatPresentation{false}; // Set centrally by SceneMeshService.
     bool generateRoofUVs{false}; 
     bool generateWallUVs{false};

     // Small overlap absorbs differences between the full-resolution DTM and
     // the decimated terrain mesh. This is deliberately not a deep 15 m plug.
     float wallTerrainEmbedDepthMetres{0.5f};

     bool validate() const
     {
          return std::isfinite(wallTerrainEmbedDepthMetres) &&
               wallTerrainEmbedDepthMetres >= 0.0f &&
               wallTerrainEmbedDepthMetres <= 5.0f;
     }
};
