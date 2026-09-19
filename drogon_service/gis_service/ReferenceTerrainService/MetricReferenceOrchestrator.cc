// connects SrtmExtractor, RasterProcessor and ReferenceDemPreprocessor

#include "MetricReferenceOrchestrator.h"
#include "../SrtmExtractor/SrtmExtractor.h"
#include "../RasterProcessor/RasterProcessor.h"
#include <trantor/utils/Logger.h>
#include <stdexcept>
#include <cpl_conv.h>

drogon::Task<ReferenceTerrainBundle> MetricReferenceOrchestrator::prepareReferenceTerrain(
    const SceneInput& scene)
{
    LOG_INFO << "MetricReferenceOrchestrator: Initiating Branch B (Terrain Preparation)...";

    if (!scene.spatialMetadata.has_value())
    {
        throw std::runtime_error("MetricReferenceOrchestrator: SceneInput is missing SpatialMetadata");
    }

    // fetch Copernicus/SRTM dataset using SrtmExtractor
    LOG_INFO << "MetricReferenceOrchestrator: Fetching reference DEM tiles via SrtmExtractor...";
    RasterDatasets datasets = SrtmExtractor::fetchTile(scene.inputPath);

    if (!datasets.hDemDS)
    {
        throw std::runtime_error("MetricReferenceOrchestrator: Failed to fetch reference DEM from remote storage");
    }

    // identify the DEM source by looking at the files bundled inside the VRT Mosaic
    std::string actualSource = "Unknown_DEM_30m";
    
    // GDAL GetFileList returns all the physical URLs used to build the virtual mosaic
    char** fileList = datasets.hDemDS->GetFileList();
    if (fileList)
    {
        for (int i = 0; fileList[i] != nullptr; ++i)
        {
            std::string file(fileList[i]);
            if (file.find("copernicus") != std::string::npos) 
            {
                actualSource = "Copernicus_30m_AWS";
                break;
            } 
            else if (file.find("elevation-tiles") != std::string::npos) 
            {
                actualSource = "SRTMGL1_30m_AWS";
                break;
            }
        }
        CSLDestroy(fileList); // free the memory allocated by GDAL
    }

    // warp and resample DEM directly onto the optical scene grid
    LOG_INFO << "MetricReferenceOrchestrator: Warping DEM to optical resolution and CRS...";
    RasterGrid<float> warpedDem = RasterProcessor::warpDemToScene(
        datasets.hDemDS, 
        *scene.spatialMetadata
    );

    // digitally clean artifacts, peel away buildings/trees and compute DTM prior
    LOG_INFO << "MetricReferenceOrchestrator: Applying adaptive morphological ground filter & IDW inpainting...";
    ReferenceTerrainBundle terrainBundle = ReferenceDemPreprocessor::process(
        warpedDem, 
        scene,
        actualSource
    );

    LOG_INFO << "MetricReferenceOrchestrator: Reference terrain prior successfully prepared";
    co_return terrainBundle;
}