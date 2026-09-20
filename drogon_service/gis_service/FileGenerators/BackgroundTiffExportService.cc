#include "BackgroundTiffExportService.h"

#include "TiffExporter.h"
#include "../DataHandlers/MiniIOClient.h"

#include <trantor/utils/Logger.h>

#include <stdexcept>
#include <utility>

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
    std::string jobId, GeoreferencedSurfaceBundle surface)
{
    std::lock_guard lock(mutex_);

    if (stopping_ || jobs_.size() >= kMaxQueuedJobs ||
        statusByJob_.contains(jobId))
        return false;

    // Start lazily. The worker waits on the same mutex until this job is queued.
    if (!worker_.joinable())
        worker_ = std::thread(&BackgroundTiffExportService::run, this);

    statusByJob_.emplace(jobId, RasterExportStatus{});
    jobs_.push_back(ExportJob{std::move(jobId), std::move(surface)});
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
