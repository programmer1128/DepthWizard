#pragma once
#include <cmath>

struct BuildingReconstructionConfig 
{
     // Mask Processor Thresholds
     float buildingProbabilityThreshold{0.40f}; // Lowered from 0.50f to capture ViT edge blur
     float minBuildingSemanticConfidence{0.50f};

     // Recovery path for pixels tagged UNKNOWN or high-elevation VEGETATION
     float buildingRecoveryProbabilityThreshold{0.25f}; // Lowered from 0.35f
     float minRecoveryNdsmHeightMetres{1.8f};           // Lowered from 2.0f
     float recoveryDistanceMetres{4.0f};                // Expanded to bridge 10-pixel halo

     // Morphology
     float openingRadiusMetres{0.5f};
     float closingRadiusMetres{1.5f};
    
     // Instance Extractor Thresholds
     int connectivity{8};
    
     // Footprint Vectorizer Thresholds
     float minBuildingAreaSquareMetres{12.0f};
     float minHoleAreaSquareMetres{5.0f};                
     float footprintSimplificationToleranceMetres{0.5f}; 
     float footprintAreaDeviationTolerance{0.25f};      // 25% deviation allowed before fallback
     
     // Rectangular Regularization Thresholds
     bool regularizeRectangularFootprints{true};
     float minimumFootprintMaskIoU{0.82f};              // Lowered from 0.93f to stop fallback to raw outer
     float maxCornerAdjustmentMetres{2.5f};             // Increased from 1.0f

     // Height Estimator Thresholds
     float groundBufferRadiusMetres{3.0f};               
     float footprintErosionRadiusMetres{1.0f};           
     int minRequiredSamples{5};                          
     float minBuildingHeightMetres{1.5f};
     float maxBuildingHeightMetres{500.0f};
     float maxFootprintElevationDeltaMetres{8.0f};
     float instanceHeightStepMetres{5.5f};              // Relaxed from 3.0f to prevent fractured rooftops

     bool validate() const 
     {
         return std::isfinite(buildingProbabilityThreshold) && buildingProbabilityThreshold >= 0.0f && buildingProbabilityThreshold <= 1.0f &&
             std::isfinite(minBuildingSemanticConfidence) && minBuildingSemanticConfidence >= 0.0f && minBuildingSemanticConfidence <= 1.0f &&
             std::isfinite(buildingRecoveryProbabilityThreshold) && buildingRecoveryProbabilityThreshold >= 0.0f && buildingRecoveryProbabilityThreshold <= buildingProbabilityThreshold &&
             std::isfinite(minRecoveryNdsmHeightMetres) && minRecoveryNdsmHeightMetres >= 0.0f && minRecoveryNdsmHeightMetres <= maxBuildingHeightMetres &&
             std::isfinite(recoveryDistanceMetres) && recoveryDistanceMetres >= 0.0f &&
             std::isfinite(openingRadiusMetres) && openingRadiusMetres >= 0.0f &&
             std::isfinite(closingRadiusMetres) && closingRadiusMetres >= 0.0f &&
             (connectivity == 4 || connectivity == 8) &&
             std::isfinite(minBuildingAreaSquareMetres) && minBuildingAreaSquareMetres >= 0.0f &&
             std::isfinite(minHoleAreaSquareMetres) && minHoleAreaSquareMetres >= 0.0f &&
             std::isfinite(footprintSimplificationToleranceMetres) && footprintSimplificationToleranceMetres >= 0.0f &&
             std::isfinite(footprintAreaDeviationTolerance) && footprintAreaDeviationTolerance >= 0.0f &&
             std::isfinite(minimumFootprintMaskIoU) && minimumFootprintMaskIoU >= 0.0f && minimumFootprintMaskIoU <= 1.0f &&
             std::isfinite(maxCornerAdjustmentMetres) && maxCornerAdjustmentMetres >= 0.0f &&
             std::isfinite(groundBufferRadiusMetres) && groundBufferRadiusMetres >= 0.0f &&
             std::isfinite(footprintErosionRadiusMetres) && footprintErosionRadiusMetres >= 0.0f &&
             minRequiredSamples > 0 &&
             std::isfinite(minBuildingHeightMetres) && minBuildingHeightMetres > 0.0f &&
             std::isfinite(maxBuildingHeightMetres) && maxBuildingHeightMetres >= minBuildingHeightMetres &&
             std::isfinite(maxFootprintElevationDeltaMetres) && maxFootprintElevationDeltaMetres > 0.0f &&
             std::isfinite(instanceHeightStepMetres) && instanceHeightStepMetres > 0.0f;
     }
};