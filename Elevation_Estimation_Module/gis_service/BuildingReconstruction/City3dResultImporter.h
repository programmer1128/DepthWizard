#pragma once

#include "City3dTypes.h"

#include <array>
#include <filesystem>
#include <string>
#include <vector>

struct City3dImportResult
{
     bool accepted{false};
     std::string reason;        // Stable code when rejected
     std::string workerStatus;  // Manifest status
     BuildingSurfaceShell shell;
     std::size_t degenerateTrianglesDropped{0};
     double roofTopMetres{0.0}; // Highest roof vertex above the base (metric)
};

class City3dResultImporter
{
public:
     // Reads <resultDirectory>/result.json and its grouped OBJ. Accepts only
     // a v1 success manifest for this job and building, whose mesh is
     // finite, indexes correctly, triangulates to non-degenerate roof and
     // wall triangles, stays within the footprint box (plus overflow), and
     // whose roof top agrees with the official metric height. The local
     // origin declared in the manifest is restored exactly once.
     static City3dImportResult import(
         const std::filesystem::path& resultDirectory,
         const std::string& expectedJobId,
         const BuildingInstance& building,
         const City3dCandidate& candidate,
         float renderHeightScale,
         const City3dConfig& config);

     // Ear-clipping triangulation of a planar polygon (any orientation);
     // empty when the polygon cannot be triangulated.
     static std::vector<std::array<std::size_t, 3>> triangulatePolygon(
         const std::vector<std::array<double, 3>>& polygon);
};
