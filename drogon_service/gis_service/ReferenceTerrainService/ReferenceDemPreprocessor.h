// terrain cleaning 

// cleans and filters raw satellite DEMs (Copernicus/SRTM) to produce a pure bare earth Digital Terrain Model (DTM)
// removes non-terrain structures (forest canopies, roofs)
// using morphological filtering scaled to the scene's Ground Sample Distance (GSD)


#pragma once

#include <vector>
#include <string>
#include <cstdint>
#include "../structures/CommonTypes.h"
#include "../structures/IngestionStructs.h"


// encapsulates the processed bare-earth DTM prior along with its spatial validity and per-pixel confidence scores

struct ReferenceTerrainBundle 
{
    RasterGrid<float> rawWarpedDem;       // raw interpolated reference DEM
    RasterGrid<float> correctedTerrainPrior; // cleaned bare-earth DTM
    RasterGrid<uint8_t> validMask;       // 1 for valid terrain, 0 for unrecoverable NoData
    RasterGrid<float> confidence;      // terrain reliability score (0.0 to 1.0)
    std::string demSource;                 // "Copernicus_30m" or "SRTMGL1"
    float sourceResolutionMeters{30.0f};     // original sensor resolution
    std::vector<std::string> warnings;     // processing warnings
};

class ReferenceDemPreprocessor 
{
    public:
    
    // cleans the warped DEM, removes spikes, applies adaptive ground morphology,
    // inpaints small NoData voids with IDW and builds terrain confidence
    
    // warpedDem: Pixel-aligned raw DEM from RasterProcessor
    // scene: Contains image dimensions and SpatialMetadata for GSD computation
    // demSource: The detected origin of the DEM (Copernicus or SRTM)
    // ReferenceTerrainBundle: The finalized bare-earth terrain layer
    
    // main orchestrator function
    static ReferenceTerrainBundle process(
        const RasterGrid<float>& warpedDem, 
        const SceneInput& scene,
        const std::string& demSource);


    // Calculates the physical Ground Sample Distance (pixel size in meters)
    // from the Affine GeoTransform: sqrt(|GT[1] * GT[5]|)
    static float computeGsd(const SpatialMetadata& metadata);


    // Eliminates single-pixel high-frequency outliers that deviate drastically
    // from local 3x3 median elevation
    static void removeSpikes(
        RasterGrid<float>& demGrid, 
        float thresholdMeters = 35.0f);


    // Performs a morphological Opening operation (Erosion followed by Dilation)
    // using a structuring element radius dynamically scaled by GSD
    // Erosion scrapes away elevated roofs and tree canopies
    // dilation restores natural valley contours
    // multi threaded erosion and dilation
    static RasterGrid<float> applyAdaptiveGroundFilter(
        const RasterGrid<float>& inputGrid, 
        float gsdMeters);

    
    // Fills small NoData/NaN gaps using Inverse Distance Weighting (IDW) interpolation
    // within a localized search window
    static void inpaintVoidsIDW(
        RasterGrid<float>& demGrid, 
        RasterGrid<uint8_t>& validMask, 
        int searchRadius = 5);

    // Evaluates terrain confidence based on local slope gradients and proximity
    // to authentic (non-interpolated) satellite measurements
    static RasterGrid<float> computeTerrainConfidence(
        const RasterGrid<float>& dtmGrid, 
        const RasterGrid<uint8_t>& validMask);
};