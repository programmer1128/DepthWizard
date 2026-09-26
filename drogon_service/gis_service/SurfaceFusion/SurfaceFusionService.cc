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
    const SpatialMetadata& metadata)
{
    // Ensure all inputs are valid before processing
    if (!correctedNdsm.isValid())
    {
        throw std::invalid_argument(
            "SurfaceFusionService: Invalid corrected nDSM grid.");
    }

    const int w = correctedNdsm.width;
    const int h = correctedNdsm.height;

    // Helper to check if all grids match the exact same dimensions
    const auto matchesNdsmShape =
        [w, h](const auto& grid)
        {
            return grid.isValid() &&
                grid.width == w &&
                grid.height == h;
        };

    if (!matchesNdsmShape(reference.correctedTerrainPrior) ||
        !matchesNdsmShape(reference.confidence) ||
        !matchesNdsmShape(reference.validMask) ||
        !matchesNdsmShape(semantics.semanticConfidence) ||
        !matchesNdsmShape(semantics.finalClassMap) ||
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
   
    // Prepare the output grids with the correct size and default values
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

    // Extract raw memory pointers for maximum processing speed
    const float* in_ndsm = correctedNdsm.data.data();
    const float* in_dtm = reference.correctedTerrainPrior.data.data();
    const float* in_ai_conf = aiConfidence.data.data();
    const float* in_dem_conf = reference.confidence.data.data();
    const float* in_sem_conf = semantics.semanticConfidence.data.data();
    const SemanticClass* in_class = semantics.finalClassMap.data.data();
    const uint8_t* in_dem_mask = reference.validMask.data.data();
    
    float* out_dtm = bundle.dtm.data.data();
    float* out_ndsm = bundle.ndsm.data.data();
    float* out_dsm = bundle.dsm.data.data();
    float* out_conf = bundle.surfaceConfidence.data.data();
    uint8_t* out_mask = bundle.validMask.data.data();

    // Strict safety thresholds to prevent AI hallucinations
    const float THRESH_SEMANTIC_CONFIDENCE = 0.50f; // Must be 50% sure it's a building/tree
    const float THRESH_DTM_CONFIDENCE = 0.35f;      // Reject structures on steep cliffs

    // Process all pixels simultaneously across CPU cores
    #pragma omp parallel for simd schedule(static)
    for (size_t i = 0; i < totalPixels; ++i) 
    {
        // Skip pixels that have no satellite data or invalid math
        if (in_dem_mask[i] == 0 || std::isnan(in_dtm[i]) || std::isnan(in_ndsm[i])) 
        {
            out_mask[i] = 0;
            out_dtm[i] = std::numeric_limits<float>::quiet_NaN();
            out_ndsm[i] = std::numeric_limits<float>::quiet_NaN();
            out_dsm[i] = std::numeric_limits<float>::quiet_NaN();
            out_conf[i] = 0.0f;
            continue;
        }

        // Base terrain is always valid and carried over
        out_mask[i] = 1;
        out_dtm[i] = in_dtm[i];

        SemanticClass pixelClass = in_class[i];
        float semConf = in_sem_conf[i];
        float demConf = in_dem_conf[i];
        float rawNdsm = in_ndsm[i];

        bool permitStructure = false;

        // Flaw 1: Semantic Leakage. Only Trees and Buildings have physical height.
        if (pixelClass == SemanticClass::BUILDING || pixelClass == SemanticClass::VEGETATION)
        {
            // Flaw 2: Low-Confidence Hallucination Bleed. AI must be confident.
            if (semConf >= THRESH_SEMANTIC_CONFIDENCE)
            {
                // Flaw 3: Steep-Terrain Hallucination Rejection. Terrain must be stable.
                if (demConf >= THRESH_DTM_CONFIDENCE)
                {
                    permitStructure = true;
                }
            }
        }

        if (permitStructure)
        {
            // Flaw 4: Negative Trenching Guard. Prevent digging holes in the ground.
            out_ndsm[i] = std::max(0.0f, rawNdsm);
            
            // Compose the final absolute elevation
            out_dsm[i] = out_dtm[i] + out_ndsm[i];

            // Propagate uncertainty considering all three sources (AI depth, Terrain, Semantics)
            float err_ai = 1.0f - in_ai_conf[i];
            float err_dem = 1.0f - demConf;
            float err_sem = 1.0f - semConf;
            
            float combined_variance = (err_ai * err_ai) + (err_dem * err_dem) + (err_sem * err_sem);
            float total_uncertainty = std::min(1.0f, std::sqrt(combined_variance)); 
            out_conf[i] = 1.0f - total_uncertainty;
        }
        else
        {
            // Flaw 5: NaN Sabotage. Force pixel cleanly to bare-earth.
            out_ndsm[i] = 0.0f;
            out_dsm[i] = out_dtm[i]; // Flat DTM passes through cleanly

            // Flaw 6: RSS Uncertainty Corruption. Bypass AI depth uncertainty on flat ground.
            float err_dem = 1.0f - demConf;
            float err_sem = 1.0f - semConf;
            
            float combined_variance = (err_dem * err_dem) + (err_sem * err_sem);
            float total_uncertainty = std::min(1.0f, std::sqrt(combined_variance));
            out_conf[i] = 1.0f - total_uncertainty;
        }
    }

    return bundle;
}