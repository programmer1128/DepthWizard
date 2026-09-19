// implements the Multi-Criteria Boolean Gating logic
// heavily utilizes fast pointer arrays to apply strict rules to millions of pixels concurrently

#include "GroundSurfaceService.h"
#include <omp.h>

GroundMask GroundSurfaceService::buildGroundMask(
    const SemanticScene& semantics,
    const ImageQualityResult& imageQuality,
    const ReferenceTerrainBundle& reference)
{
    GroundMask result;
    
    int w = semantics.finalClassMap.width;
    int h = semantics.finalClassMap.height;
    size_t totalPixels = static_cast<size_t>(w) * h;

    // initialize our output grids
    result.isValidGround.width = w;
    result.isValidGround.height = h;
    result.isValidGround.data.resize(totalPixels, 0);

    result.weights.width = w;
    result.weights.height = h;
    result.weights.data.resize(totalPixels, 0.0f);

    // extract raw pointers for fast memory reads
    const float* p_gnd = semantics.groundProbability.data.data();
    const float* p_road = semantics.roadProbability.data.data();
    const float* p_bldg = semantics.buildingProbability.data.data();
    const float* p_veg = semantics.vegetationProbability.data.data();
    const float* p_sem_conf = semantics.semanticConfidence.data.data();

    // extract raw pointers for the physical safety masks
    const uint8_t* m_img_valid = imageQuality.validPixelMask.data.data();
    const uint8_t* m_dem_valid = reference.validMask.data.data();

    // output pointers
    uint8_t* out_mask = result.isValidGround.data.data();
    float* out_weights = result.weights.data.data();

    // we define the strict mathematical thresholds required to qualify as ground
    const float THRESH_GROUND_ROAD_MIN = 0.5f; // must be at least 50% sure its ground or road
    const float THRESH_BLDG_MAX = 0.1f;    // must be less than 10% sure its a building
    const float THRESH_VEG_MAX = 0.15f;     // must be less than 15% sure its vegetation

    size_t localCount = 0;

    // multi-thread the Boolean Gating logic across the entire image
    #pragma omp parallel for reduction(+:localCount) schedule(static)
    for (size_t i = 0; i < totalPixels; ++i) 
    {
        // check if pixel is safe or not (no clouds, shadows or satellite voids)
        if (m_img_valid[i] == 0 || m_dem_valid[i] == 0) 
        {
            continue; // skip this pixel entirely
        }


        // extract the probabilities
        float prob_ground = p_gnd[i];
        float prob_road = p_road[i];
        float prob_bldg = p_bldg[i];
        float prob_veg = p_veg[i];


        // the core Multi-Criteria Boolean Gating Equation:

        // GroundMask(x,y) = (P_ground > Tg OR P_road > Tr) AND (P_building < Tb) AND (P_veg < Tv)

        bool is_surface = (prob_ground > THRESH_GROUND_ROAD_MIN || prob_road > THRESH_GROUND_ROAD_MIN);
        bool is_not_structure = (prob_bldg < THRESH_BLDG_MAX && prob_veg < THRESH_VEG_MAX);

        if (is_surface && is_not_structure) 
        {
            // we found a pure dirt/road pixel
            out_mask[i] = 1;
            
            // weight its reliability based on the AI's semantic confidence
            out_weights[i] = p_sem_conf[i];
            
            localCount++;
        }
    }

    result.validGroundCount = localCount;
    return result;
}