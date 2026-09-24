#pragma once
#include <cmath>

struct BuildingReconstructionConfig 
{
     //Mask Processor Thresholds
     float buildingProbabilityThreshold{0.50f};
     float minBuildingSemanticConfidence{0.50f};

     // Recovery path for roof pixels that have credible building evidence
     // and metric height but were marked UNKNOWN by the global softmax margin.
     float buildingRecoveryProbabilityThreshold{0.35f};
     float minRecoveryNdsmHeightMetres{2.0f};

     // A large opening kernel erased narrow urban buildings. Cleanup remains
     // metric-aware but is deliberately conservative.
     float openingRadiusMetres{0.5f};
     float closingRadiusMetres{1.5f};
    
     //Instance Extractor Thresholds
     int connectivity{8};
    
     //Footprint Vectorizer Thresholds
     float minBuildingAreaSquareMetres{12.0f};
     float minHoleAreaSquareMetres{5.0f};                // Preserves valid courtyards
     float footprintSimplificationToleranceMetres{0.5f}; // RDP mathematical epsilon
     float footprintAreaDeviationTolerance{0.2f};        // Max 20% area loss allowed

     //Height Estimator Thresholds
     float groundBufferRadiusMetres{3.0f};               // How far out to search for ground
     float footprintErosionRadiusMetres{1.0f};           // How far in to erode to avoid edge-blur
     int minRequiredSamples{5};                          // Minimum pixels needed for robust median
     float minBuildingHeightMetres{1.5f};
     float maxBuildingHeightMetres{500.0f};
     // Robust 10th-to-90th percentile DTM relief permitted beneath one
     // footprint. This rejects long cliff/ridge components hallucinated as
     // buildings without letting one noisy DEM pixel reject a real building.
     float maxFootprintElevationDeltaMetres{8.0f};

     // Universal Configuration Validator
     bool validate() const 
     {
         return std::isfinite(buildingProbabilityThreshold) && buildingProbabilityThreshold >= 0.0f && buildingProbabilityThreshold <= 1.0f &&
             std::isfinite(minBuildingSemanticConfidence) && minBuildingSemanticConfidence >= 0.0f && minBuildingSemanticConfidence <= 1.0f &&
             std::isfinite(buildingRecoveryProbabilityThreshold) && buildingRecoveryProbabilityThreshold >= 0.0f && buildingRecoveryProbabilityThreshold <= buildingProbabilityThreshold &&
             std::isfinite(minRecoveryNdsmHeightMetres) && minRecoveryNdsmHeightMetres >= 0.0f && minRecoveryNdsmHeightMetres <= maxBuildingHeightMetres &&
             std::isfinite(openingRadiusMetres) && openingRadiusMetres >= 0.0f &&
             std::isfinite(closingRadiusMetres) && closingRadiusMetres >= 0.0f &&
             (connectivity == 4 || connectivity == 8) &&
             std::isfinite(minBuildingAreaSquareMetres) && minBuildingAreaSquareMetres >= 0.0f &&
             std::isfinite(minHoleAreaSquareMetres) && minHoleAreaSquareMetres >= 0.0f &&
             std::isfinite(footprintSimplificationToleranceMetres) && footprintSimplificationToleranceMetres >= 0.0f &&
             std::isfinite(footprintAreaDeviationTolerance) && footprintAreaDeviationTolerance >= 0.0f &&
             std::isfinite(groundBufferRadiusMetres) && groundBufferRadiusMetres >= 0.0f &&
             std::isfinite(footprintErosionRadiusMetres) && footprintErosionRadiusMetres >= 0.0f &&
             minRequiredSamples > 0 &&
             std::isfinite(minBuildingHeightMetres) && minBuildingHeightMetres > 0.0f &&
             std::isfinite(maxBuildingHeightMetres) && maxBuildingHeightMetres >= minBuildingHeightMetres &&
             std::isfinite(maxFootprintElevationDeltaMetres) && maxFootprintElevationDeltaMetres > 0.0f;
     }
};
