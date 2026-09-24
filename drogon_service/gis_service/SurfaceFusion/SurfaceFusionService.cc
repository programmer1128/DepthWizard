// implements the absolute DSM addition (DSM = DTM + nDSM) and
// standard error uncertainty propagation using OpenMP for maximum execution speed

#include "SurfaceFusionService.h"
#include <cmath>
#include <algorithm>
#include <omp.h>
#include <limits>
#include <stdexcept>

GeoreferencedSurfaceBundle SurfaceFusionService::composeMetricSurface(
    const RasterGrid<float>& correctedNdsm,
    const ReferenceTerrainBundle& reference,
    const SemanticScene& semantics,
    const RasterGrid<float>& aiConfidence,
    const SpatialMetadata& metadata,
    const SurfaceFusionConfig& config)
{
    if (!correctedNdsm.isValid())
    {
        throw std::invalid_argument(
            "SurfaceFusionService: Invalid corrected nDSM grid.");
    }

    const int w = correctedNdsm.width;
    const int h = correctedNdsm.height;

    const auto matchesNdsmShape =
        [w, h](const auto& grid)
        {
            return grid.isValid() &&
                grid.width == w &&
                grid.height == h;
        };

    if (!config.validate() ||
        !matchesNdsmShape(reference.correctedTerrainPrior) ||
        !matchesNdsmShape(reference.confidence) ||
        !matchesNdsmShape(reference.validMask) ||
        !matchesNdsmShape(semantics.buildingProbability) ||
        !matchesNdsmShape(semantics.vegetationProbability) ||
        !matchesNdsmShape(semantics.finalClassMap) ||
        !matchesNdsmShape(semantics.semanticConfidence) ||
        !matchesNdsmShape(aiConfidence))
    {
        throw std::invalid_argument(
            "SurfaceFusionService: Input raster dimensions are inconsistent.");
    }

    if (metadata.width != w || metadata.height != h)
    {
        throw std::invalid_argument(
            "SurfaceFusionService: Spatial metadata dimensions do not match raster dimensions.");
    }

    GeoreferencedSurfaceBundle bundle;
    
     const size_t totalPixels =
        static_cast<size_t>(w) * static_cast<size_t>(h);

    bundle.spatialMetadata = metadata;
    bundle.elevationUnit = ElevationUnit::METERS;
   
    
    // allocate the fundamental grids
    bundle.dtm.width = w; 
    bundle.dtm.height = h;
    bundle.dtm.data.resize(totalPixels, 0.0f);

    bundle.ndsm.width = w; 
    bundle.ndsm.height = h;
    bundle.ndsm.data.resize(totalPixels, 0.0f);

    bundle.dsm.width = w; 
    bundle.dsm.height = h;
    bundle.dsm.data.resize(totalPixels, 0.0f);

    bundle.surfaceConfidence.width = w; 
    bundle.surfaceConfidence.height = h;
    bundle.surfaceConfidence.data.resize(totalPixels, 0.0f);

    bundle.validMask.width = w; 
    bundle.validMask.height = h;
    bundle.validMask.data.resize(totalPixels, 0);


    // extract fast read pointers
    const float* in_ndsm = correctedNdsm.data.data();
    const float* in_dtm = reference.correctedTerrainPrior.data.data();
    const float* in_ai_conf = aiConfidence.data.data();
    const float* in_dem_conf = reference.confidence.data.data();
    const float* in_sem_conf = semantics.semanticConfidence.data.data();
    const float* in_building_prob = semantics.buildingProbability.data.data();
    const float* in_vegetation_prob = semantics.vegetationProbability.data.data();
    const SemanticClass* in_class = semantics.finalClassMap.data.data();
    const uint8_t* in_dem_mask = reference.validMask.data.data();
    

    // extract fast write pointers
    float* out_dtm = bundle.dtm.data.data();
    float* out_ndsm = bundle.ndsm.data.data();
    float* out_dsm = bundle.dsm.data.data();
    float* out_conf = bundle.surfaceConfidence.data.data();
    uint8_t* out_mask = bundle.validMask.data.data();


    // multi-threaded Linear Surface Superposition and Uncertainty Propagation
    #pragma omp parallel for simd schedule(static)
    for (size_t i = 0; i < totalPixels; ++i) 
    {
        // check core spatial validity
        if (in_dem_mask[i] == 0 || !std::isfinite(in_dtm[i]))
        {
            out_mask[i] = 0;
            out_dtm[i] = std::numeric_limits<float>::quiet_NaN();
            out_ndsm[i] = std::numeric_limits<float>::quiet_NaN();
            out_dsm[i] = std::numeric_limits<float>::quiet_NaN();
            out_conf[i] = 0.0f;
            continue;
        }

        // Optical/model invalidity must not punch a hole through otherwise
        // valid reference terrain. Fall back to the aligned DTM, mark nDSM as
        // zero, and lower confidence to reflect the missing high-frequency AI
        // contribution. Semantic processing will still treat that pixel as
        // UNKNOWN, so it cannot create a building.
        if (!std::isfinite(in_ndsm[i]))
        {
            out_mask[i] = 1;
            out_dtm[i] = in_dtm[i];
            out_ndsm[i] = 0.0f;
            out_dsm[i] = in_dtm[i];
            out_conf[i] = std::isfinite(in_dem_conf[i])
                ? 0.5f * std::clamp(in_dem_conf[i], 0.0f, 1.0f)
                : 0.0f;
            continue;
        }

        // Decide whether this pixel may physically carry an above-ground
        // object. A metric nDSM is not ordinary terrain relief: roads, bare
        // ground and water must be zero even if the height model is noisy.
        float fusedNdsm = in_ndsm[i];
        if (config.clampNegativeNdsmToZero)
        {
            fusedNdsm = std::max(0.0F, fusedNdsm);
        }

        bool retainAboveGroundHeight = true;
        if (config.suppressGroundInfrastructureNdsm)
        {
            switch (in_class[i])
            {
                case SemanticClass::GROUND:
                case SemanticClass::ROAD:
                case SemanticClass::WATER:
                    retainAboveGroundHeight = false;
                    break;

                case SemanticClass::BUILDING:
                case SemanticClass::VEGETATION:
                    retainAboveGroundHeight = true;
                    break;

                case SemanticClass::UNKNOWN:
                    retainAboveGroundHeight =
                        std::max(in_building_prob[i], in_vegetation_prob[i]) >=
                        config.uncertainObjectProbabilityThreshold;
                    break;
            }
        }

        if (!retainAboveGroundHeight)
        {
            fusedNdsm = 0.0F;
        }

        // Pass 1: assign valid structural grids
        out_mask[i] = 1;
        out_dtm[i] = in_dtm[i];
        out_ndsm[i] = fusedNdsm;

        // Pass 2: the Core Geographic Addition -> DSM = DTM + nDSM
        out_dsm[i] = out_dtm[i] + out_ndsm[i];

        // Pass 3: Uncertainty Propagation (Root-Sum-Square estimation)
        // convert confidence (0.0->1.0) into uncertainty variance (1.0 - conf)
        float err_ai = 1.0f - in_ai_conf[i];
        float err_dem = 1.0f - in_dem_conf[i];
        float err_sem = 1.0f - in_sem_conf[i];

        // combine variances (squared error propagation: sigma = sqrt(a^2 + b^2 + c^2))
        float combined_variance = (err_ai * err_ai) + (err_dem * err_dem) + (err_sem * err_sem);
        
        // we cap the maximum uncertainty at 1.0 to prevent underflowing the confidence
        float total_uncertainty = std::min(1.0f, std::sqrt(combined_variance)); 

        // convert back to confidence (1.0 - uncertainty)
        out_conf[i] = 1.0f - total_uncertainty;
    }

    return bundle;
}
