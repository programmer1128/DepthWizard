#pragma once

#include <cmath>
#include <optional>
#include "../UVMapping/ProjectiveTexturingTypes.h"
#include "../UVMapping/RpcCameraModel.h"
#include "../UVMapping/SensorLookGeometry.h"

struct BuildingMeshConfig 
{
     bool flatPresentation{false}; // Set centrally by SceneMeshService.
     bool generateRoofUVs{false}; 
     bool generateWallUVs{false};

     // Phase 8: Source-aware projective texturing and optional off-nadir facade recovery
     bool enableProjectiveTexturing{false};
     std::optional<RpcCameraModel> rpcModel;
     std::optional<SensorLookGeometry> sensorLook;
     ProjectiveTexturingConfig texturingConfig;
     std::optional<SpatialMetadata> spatialMetadata;

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
