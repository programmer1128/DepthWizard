#include "BackgroundTiffExportService.h"

#include "TiffExporter.h"
#include "../DataHandlers/MiniIOClient.h"

#include <trantor/utils/Logger.h>

#include <stdexcept>
#include <utility>
#include <cstdlib>

JobStatus RasterExportStatus::overall() const
{
    if (dsm == JobStatus::FAILED || dtm == JobStatus::FAILED ||
        ndsm == JobStatus::FAILED || confidence == JobStatus::FAILED)
        return JobStatus::FAILED;

    if (dsm == JobStatus::READY && dtm == JobStatus::READY &&
        ndsm == JobStatus::READY && confidence == JobStatus::READY)
        return JobStatus::READY;

    if (dsm != JobStatus::QUEUED || dtm != JobStatus::QUEUED ||
        ndsm != JobStatus::QUEUED || confidence != JobStatus::QUEUED)
        return JobStatus::PROCESSING;

    return JobStatus::QUEUED;
}

BackgroundTiffExportService& BackgroundTiffExportService::instance()
{
    static BackgroundTiffExportService service;
    return service;
}

BackgroundTiffExportService::~BackgroundTiffExportService()
{
    shutdown();
}

bool BackgroundTiffExportService::enqueue(
    std::string jobId, GeoreferencedSurfaceBundle surface,
    std::optional<ReconstructionDiagnosticPayload> diagnostics)
{
    std::lock_guard lock(mutex_);

    if (stopping_ || jobs_.size() >= kMaxQueuedJobs ||
        statusByJob_.contains(jobId))
        return false;

    // Start lazily. The worker waits on the same mutex until this job is queued.
    if (!worker_.joinable())
        worker_ = std::thread(&BackgroundTiffExportService::run, this);

    statusByJob_.emplace(jobId, RasterExportStatus{});
    if (diagnostics) statusByJob_.at(jobId).diagnosticsState = "queued";
    jobs_.push_back(ExportJob{std::move(jobId), std::move(surface), std::move(diagnostics)});
    available_.notify_one();
    return true;
}

std::optional<RasterExportStatus> BackgroundTiffExportService::getStatus(
    const std::string& jobId) const
{
    std::lock_guard lock(mutex_);
    auto found = statusByJob_.find(jobId);
    if (found == statusByJob_.end())
        return std::nullopt;

    return found->second;
}

void BackgroundTiffExportService::shutdown()
{
    {
        std::lock_guard lock(mutex_);
        stopping_ = true;
    }

    available_.notify_all();
    if (worker_.joinable())
        worker_.join();
}

void BackgroundTiffExportService::run()
{
    while (true)
    {
        ExportJob job;
        {
            std::unique_lock lock(mutex_);
            available_.wait(lock, [this] { return stopping_ || !jobs_.empty(); });

            if (jobs_.empty())
                return;

            job = std::move(jobs_.front());
            jobs_.pop_front();
        }

        processJob(job);
    }
}

void BackgroundTiffExportService::processJob(ExportJob& job)
{
    SpatialMetadata& metadata = job.surface.spatialMetadata;

    // Local debugging artifacts do not depend on MinIO being available and
    // do not block the initial GLB response. Failures are explicitly visible.
    if (job.diagnostics)
    {
        try
        {
            { std::lock_guard lock(mutex_); statusByJob_.at(job.jobId).diagnosticsState = "processing"; }
            const char* configured = std::getenv("DEPTHWIZARD_DIAGNOSTICS_DIR");
            const auto folder = ReconstructionDiagnosticsWriter::write(
                configured && *configured ? configured : "reconstruction_diagnostics",
                job.jobId, *job.diagnostics, job.surface);
            { std::lock_guard lock(mutex_);
              statusByJob_.at(job.jobId).diagnosticsState = "ready";
              statusByJob_.at(job.jobId).diagnosticsDirectory = folder.string(); }
            LOG_INFO << "Reconstruction diagnostics for " << job.jobId << ": " << folder.string();
        }
        catch (const std::exception& error)
        {
            std::lock_guard lock(mutex_);
            statusByJob_.at(job.jobId).diagnosticsState = "failed";
            statusByJob_.at(job.jobId).errors.push_back(std::string("diagnostics: ") + error.what());
            LOG_ERROR << "Diagnostics for " << job.jobId << ": " << error.what();
        }
    }

    // The DSM key keeps the existing UUID-based height-query API compatible.
    exportOne(job.jobId, "dsm", job.surface.dsm, metadata);
    exportOne(job.jobId, "dtm", job.surface.dtm, metadata);
    exportOne(job.jobId, "ndsm", job.surface.ndsm, metadata);
    exportOne(job.jobId, "confidence", job.surface.surfaceConfidence, metadata);

    LOG_INFO << "BackgroundTiffExportService: finished UUID " << job.jobId;
}

void BackgroundTiffExportService::exportOne(
    const std::string& jobId,
    const std::string& product,
    RasterGrid<float>& grid,
    SpatialMetadata& metadata)
{
    updateProduct(jobId, product, JobStatus::PROCESSING);

    try
    {
        if (!grid.isValid() || grid.width != metadata.width ||
            grid.height != metadata.height)
            throw std::runtime_error("raster dimensions do not match spatial metadata");

        std::vector<uint8_t> bytes = TiffExporter::exportTiffToBuffer(
            jobId + "_" + product, grid.data, metadata.width, metadata.height,
            metadata.geoTransform.data(), metadata.projectionRef.c_str());

        if (bytes.empty())
            throw std::runtime_error("GeoTIFF encoding failed");

        const std::string objectKey = product == "dsm"
            ? "heights_" + jobId + ".tif"
            : product + "_" + jobId + ".tif";

        if (!MinioClient::uploadBuffer("terrain-assets", objectKey, bytes,
                                       "image/tiff"))
            throw std::runtime_error("MinIO upload failed");

        updateProduct(jobId, product, JobStatus::READY);
    }
    catch (const std::exception& error)
    {
        updateProduct(jobId, product, JobStatus::FAILED, error.what());
        LOG_ERROR << "BackgroundTiffExportService: " << product << " for "
                  << jobId << " failed: " << error.what();
    }
}

void BackgroundTiffExportService::updateProduct(
    const std::string& jobId,
    const std::string& product,
    JobStatus state,
    const std::string& error)
{
    std::lock_guard lock(mutex_);
    RasterExportStatus& status = statusByJob_.at(jobId);

    if (product == "dsm")
        status.dsm = state;
    else if (product == "dtm")
        status.dtm = state;
    else if (product == "ndsm")
        status.ndsm = state;
    else
        status.confidence = state;

    if (!error.empty())
        status.errors.push_back(product + ": " + error);
}
