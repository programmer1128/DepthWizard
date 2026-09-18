#pragma once
#include <cmath>

struct BuildingReconstructionConfig 
{
     //Mask Processor Thresholds
     float buildingProbabilityThreshold{0.5f};
     float openingRadiusMetres{2.0f}; 
     float closingRadiusMetres{3.0f}; 
    
     //Instance Extractor Thresholds
     int connectivity{4}; 
    
     //Footprint Vectorizer Thresholds
     float minBuildingAreaSquareMetres{20.0f}; 
     float minHoleAreaSquareMetres{5.0f};                // Preserves valid courtyards
     float footprintSimplificationToleranceMetres{0.5f}; // RDP mathematical epsilon
     float footprintAreaDeviationTolerance{0.2f};        // Max 20% area loss allowed

     //Height Estimator Thresholds
     float groundBufferRadiusMetres{3.0f};               // How far out to search for ground
     float footprintErosionRadiusMetres{1.0f};           // How far in to erode to avoid edge-blur
     int minRequiredSamples{5};                          // Minimum pixels needed for robust median

     // Universal Configuration Validator
     bool validate() const 
     {
         return std::isfinite(buildingProbabilityThreshold) && buildingProbabilityThreshold >= 0.0f && buildingProbabilityThreshold <= 1.0f &&
             std::isfinite(openingRadiusMetres) && openingRadiusMetres >= 0.0f &&
             std::isfinite(closingRadiusMetres) && closingRadiusMetres >= 0.0f &&
             (connectivity == 4 || connectivity == 8) &&
             std::isfinite(minBuildingAreaSquareMetres) && minBuildingAreaSquareMetres >= 0.0f &&
             std::isfinite(minHoleAreaSquareMetres) && minHoleAreaSquareMetres >= 0.0f &&
             std::isfinite(footprintSimplificationToleranceMetres) && footprintSimplificationToleranceMetres >= 0.0f &&
             std::isfinite(footprintAreaDeviationTolerance) && footprintAreaDeviationTolerance >= 0.0f &&
             std::isfinite(groundBufferRadiusMetres) && groundBufferRadiusMetres >= 0.0f &&
             std::isfinite(footprintErosionRadiusMetres) && footprintErosionRadiusMetres >= 0.0f &&
             minRequiredSamples > 0;
     }
};