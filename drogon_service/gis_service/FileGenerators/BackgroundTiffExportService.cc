#include "BackgroundTiffExportService.h"

#include "TiffExporter.h"
#include "../DataHandlers/MiniIOClient.h"

#include <trantor/utils/Logger.h>

#include <algorithm>
#include <cstdlib>
#include <stdexcept>
#include <string>
#include <utility>

JobStatus RasterExportStatus::overall() const
{
    const JobStatus products[] = {dsm, dtm, ndsm, confidence, buildings};
    const auto any = [&](JobStatus state)
    { return std::find(std::begin(products), std::end(products), state) != std::end(products); };
    const auto all = [&](JobStatus state)
    { return std::all_of(std::begin(products), std::end(products),
                         [state](JobStatus product) { return product == state; }); };

    if (any(JobStatus::FAILED))
        return JobStatus::FAILED;
    if (all(JobStatus::READY))
        return JobStatus::READY;
    if (!all(JobStatus::QUEUED))
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
    std::optional<ReconstructionDiagnosticPayload> diagnostics,
    std::optional<BuildingQueryIndex> buildingIndex)
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
    jobs_.push_back(ExportJob{std::move(jobId), std::move(surface), std::move(diagnostics),
                              std::move(buildingIndex)});
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
    if (job.buildingIndex)
        exportBuildingIndex(job.jobId, *job.buildingIndex, metadata);
    else
        updateProduct(job.jobId, "buildings", JobStatus::FAILED, "no building index supplied");

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

void BackgroundTiffExportService::exportBuildingIndex(
    const std::string& jobId,
    BuildingQueryIndex& index,
    SpatialMetadata& metadata)
{
    updateProduct(jobId, "buildings", JobStatus::PROCESSING);
    try
    {
        if (!index.labels.isValid() || index.labels.width != metadata.width ||
            index.labels.height != metadata.height)
            throw std::runtime_error("building labels do not match spatial metadata");
        const std::vector<uint8_t> labels = TiffExporter::exportTiffToBuffer(
            jobId + "_buildings", index.labels.data, metadata.width, metadata.height,
            metadata.geoTransform.data(), metadata.projectionRef.c_str());
        if (labels.empty())
            throw std::runtime_error("GeoTIFF encoding failed");
        if (!MinioClient::uploadBuffer("terrain-assets", "buildings_" + jobId + ".tif",
                                       labels, "image/tiff"))
            throw std::runtime_error("MinIO upload failed");

        const std::string json = index.recordsToJson().toStyledString();
        if (!MinioClient::uploadBuffer("terrain-assets", "buildings_" + jobId + ".json",
                                       std::vector<uint8_t>(json.begin(), json.end()),
                                       "application/json"))
            throw std::runtime_error("MinIO upload failed");
        updateProduct(jobId, "buildings", JobStatus::READY);
    }
    catch (const std::exception& error)
    {
        updateProduct(jobId, "buildings", JobStatus::FAILED, error.what());
        LOG_ERROR << "BackgroundTiffExportService: building index for " << jobId
                  << " failed: " << error.what();
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
    else if (product == "buildings")
        status.buildings = state;
    else
        status.confidence = state;

    if (!error.empty())
        status.errors.push_back(product + ": " + error);
}
