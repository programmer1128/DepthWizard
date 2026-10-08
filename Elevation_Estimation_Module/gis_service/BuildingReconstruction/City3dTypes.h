#pragma once

#include "../structures/GeographicStructs.h"

#include <chrono>
#include <cstddef>
#include <cstdint>
#include <filesystem>
#include <map>
#include <string>
#include <vector>

// Minimal City3D vertical slice: native candidates -> local city3d_worker
// process -> validated BuildingSurfaceShell. Every failure keeps the
// building's native geometry.
struct City3dConfig
{
     std::filesystem::path workerBinary;            // DEPTHWIZARD_CITY3D_BINARY
     std::filesystem::path workRoot{"city3d_jobs"}; // DEPTHWIZARD_CITY3D_WORKDIR
     std::chrono::milliseconds timeout{12000};      // DEPTHWIZARD_CITY3D_TIMEOUT_S (10-15)
     std::size_t maxBuildings{5};                   // DEPTHWIZARD_CITY3D_MAX_BUILDINGS (1-5)
     bool keepWorkDirectories{false};               // DEPTHWIZARD_CITY3D_KEEP_WORKDIR

     // Eligibility (simple non-flat footprints with enough support).
     double minimumFootprintAreaSquareMetres{40.0};
     // Larger instances (often merged city blocks) cannot finish within the
     // 10-15 s per-building budget; they stay native.
     double maximumFootprintAreaSquareMetres{2500.0};
     std::size_t minimumPoints{150};
     std::size_t maximumPoints{8000};
     double minimumHeightSpreadMetres{1.5};  // p90 - p10 of metric roof heights
     float minimumRoofHeightMetres{0.5f};    // metric nDSM of an accepted roof point
     float minimumBuildingProbability{0.3f};
     // A monocular nDSM blurs each height jump into a steep ramp; City3D fits
     // planes to such ramps that then cut through the ground. Pixels steeper
     // than this rise/run (0.6 ~ 31 degrees) are left out, so jumps become
     // City3D walls. Roofs steeper than this are not supported in the slice.
     double maximumPointSlope{0.6};

     // Worker parameters, tuned on real monocular inputs (NYC fixture):
     // City3D's defaults (40 points, 0.5 m, pixel = spacing) find 26-36
     // planes in nDSM noise and exceed the candidate limit.
     int minimumPlanePoints{300};
     double maximumPlaneDistanceMetres{0.8};
     double maximumPlaneAngleDegrees{30.0};
     double heightMapPixelSizeMetres{1.0};
     int maximumCandidateFaces{4000};

     // Import validation.
     double footprintOverflowMetres{1.0};       // vertex XY beyond the footprint box
     double heightToleranceMetres{2.5};         // Above the highest observed point
     double groundToleranceMetres{1.0};         // Below the official base
     double heightToleranceFraction{0.35};      // Roof top may undershoot the official height by this
     std::size_t maximumShellTriangles{10000};

     static City3dConfig fromEnvironment();
};

// Pseudo point cloud of one building, before any file is written.
struct City3dCandidate
{
     uint32_t buildingId{0};
     bool eligible{false};
     std::string reason;                  // Stable code when not eligible
     std::vector<ProjectedVertex3D> points; // Metric projected X, Y and Z = DTM + corrected nDSM
     double heightSpreadMetres{0.0};
     double maximumLocalHeightMetres{0.0}; // Highest point above the origin elevation
     double footprintAreaSquareMetres{0.0};
     double originEasting{0.0};
     double originNorthing{0.0};
     double originElevation{0.0};         // Representative base elevation
};

struct City3dBuildingOutcome
{
     uint32_t buildingId{0};
     std::string route;          // not_eligible, over_budget, attempted
     std::string reason;         // Why it was not attempted, or why it fell back
     std::string workerStatus;   // Worker manifest status, if any
     bool accepted{false};       // A validated shell exists for this building
     long long elapsedMs{0};
     std::size_t points{0};
     double heightSpreadMetres{0.0};
     std::size_t roofTriangles{0};
     std::size_t wallTriangles{0};
     std::string logTail;
};

struct City3dRunSummary
{
     std::string mode;
     std::vector<City3dBuildingOutcome> outcomes;
     std::map<uint32_t, BuildingSurfaceShell> acceptedShells;
     std::size_t eligibleCount{0};
     long long totalMs{0};
     std::string skippedReason;  // The whole run was skipped (e.g. SAT2LoD2 geometry)
};
