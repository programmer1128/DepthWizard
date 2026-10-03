#pragma once

#include "City3dTypes.h"
#include "BuildingReconstructionConfig.h"
#include "../structures/SurfaceStructs.h"

#include <filesystem>
#include <string>

class City3dInputBuilder
{
public:
     // Gathers the monocular-derived pseudo point cloud of one native building
     // and decides eligibility. A point is one raster pixel centre whose exact
     // instance label is the building, that is interior (all 8 neighbours carry
     // the same label), valid, finite in DTM and corrected metric nDSM, at
     // least minimumRoofHeightMetres high and building-probable. Z is
     // DTM + corrected nDSM in metres (no render scale).
     static City3dCandidate analyse(
         const BuildingInstance& building,
         const RasterGrid<int32_t>& instanceLabels,
         const SemanticScene& semantics,
         const GeoreferencedSurfaceBundle& surface,
         const RasterGrid<float>& correctedMetricNdsm,
         const SpatialMetadata& metadata,
         const City3dConfig& config);

     // Writes roof_points.ply, footprint.obj and request.json into directory.
     // Coordinates are local to the candidate origin (X east, Y north, Z up).
     // The footprint uses pixel-edge coordinates (no half-pixel shift) at Z 0.
     static bool writeJob(
         const City3dCandidate& candidate,
         const BuildingInstance& building,
         const SpatialMetadata& metadata,
         const City3dConfig& config,
         const std::string& jobId,
         const std::filesystem::path& directory,
         std::string& error);

     // Raster pixel centre / pixel-edge vertex to projected coordinates.
     static ProjectedPoint pixelCentre(int column, int row, const SpatialMetadata& metadata);
     static ProjectedPoint pixelEdge(const PixelPoint& point, const SpatialMetadata& metadata);
};
