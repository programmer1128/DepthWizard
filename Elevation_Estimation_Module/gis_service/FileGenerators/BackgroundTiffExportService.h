#pragma once

#include "../structures/SurfaceStructs.h"
#include "../HeightService/BuildingQueryIndex.h"
#include "ReconstructionDiagnosticsWriter.h"

#include <condition_variable>
#include <deque>
#include <mutex>
#include <optional>
#include <string>
#include <thread>
#include <unordered_map>
#include <vector>

// Progress for the four raster artifacts belonging to one reconstruction UUID.
// The status is held in memory; the GeoTIFFs themselves are stored in MinIO.
struct RasterExportStatus
{
    JobStatus dsm{JobStatus::QUEUED};
    JobStatus dtm{JobStatus::QUEUED};
    JobStatus ndsm{JobStatus::QUEUED};
    JobStatus confidence{JobStatus::QUEUED};
    // Building label raster and index JSON used by height queries.
    JobStatus buildings{JobStatus::QUEUED};
    std::vector<std::string> errors;
    std::string diagnosticsState{"disabled"};
    std::string diagnosticsDirectory;

    JobStatus overall() const;
};

// Owns one background thread so TIFF encoding and uploads do not hold open
// the HTTP request or create an unbounded number of detached threads.
class BackgroundTiffExportService
{
public:
    static BackgroundTiffExportService& instance();

    BackgroundTiffExportService(const BackgroundTiffExportService&) = delete;
    BackgroundTiffExportService& operator=(const BackgroundTiffExportService&) = delete;

    // Takes ownership of the surface matrices. Returns false when shutting down
    // or when the bounded queue is full; callers must not report TIFF success.
    bool enqueue(std::string jobId, GeoreferencedSurfaceBundle surface,
                 std::optional<ReconstructionDiagnosticPayload> diagnostics = std::nullopt,
                 std::optional<BuildingQueryIndex> buildingIndex = std::nullopt);

    std::optional<RasterExportStatus> getStatus(const std::string& jobId) const;

    // Drain accepted jobs before the GDAL and MinIO clients are shut down.
    void shutdown();

private:
    BackgroundTiffExportService() = default;
    ~BackgroundTiffExportService();

    struct ExportJob
    {
        std::string jobId;
        GeoreferencedSurfaceBundle surface;
        std::optional<ReconstructionDiagnosticPayload> diagnostics;
        std::optional<BuildingQueryIndex> buildingIndex;
    };

    void run();
    void processJob(ExportJob& job);
    void exportOne(const std::string& jobId,
                   const std::string& product,
                   RasterGrid<float>& grid,
                   SpatialMetadata& metadata);
    void exportBuildingIndex(const std::string& jobId,
                             BuildingQueryIndex& index,
                             SpatialMetadata& metadata);
    void updateProduct(const std::string& jobId,
                       const std::string& product,
                       JobStatus state,
                       const std::string& error = {});

    static constexpr size_t kMaxQueuedJobs = 4;

    mutable std::mutex mutex_;
    std::condition_variable available_;
    std::deque<ExportJob> jobs_;
    std::unordered_map<std::string, RasterExportStatus> statusByJob_;
    std::thread worker_;
    bool stopping_{false};
};
