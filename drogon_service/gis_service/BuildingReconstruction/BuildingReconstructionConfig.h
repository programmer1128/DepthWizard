#pragma once
#include <cmath>

struct BuildingReconstructionConfig
{
     //Mask Processor Thresholds
     float buildingProbabilityThreshold{0.40f};
     float minBuildingSemanticConfidence{0.40f};

     // Recovery path for roof pixels that have credible building evidence
     // and metric height but were marked UNKNOWN by the global softmax margin.
     // Recovery is deliberately weaker than the primary decision, but it
     // must still be real building evidence.  The former 0.05 threshold let
     // almost any elevated UNKNOWN/vegetation pixel join a nearby roof and
     // was a major source of block-scale blobs.
     float buildingRecoveryProbabilityThreshold{0.40f};
     float minRecoveryNdsmHeightMetres{1.8f};

     // A large opening kernel erased narrow urban buildings. Setting to 0.0f
     // preserves thin building wings, corridors, and pavilions.
     float openingRadiusMetres{0.0f};
     // Do not morphologically close urban masks by default. Even a nominal
     // 0.75 m radius becomes a 5x5 kernel at 0.5 m GSD and seals alleys and
     // party-wall gaps. Evidence-bounded recovery handles small occlusions.
     float closingRadiusMetres{0.0f};
     // Recovery may extend a strong roof by this distance, never create an
     // isolated low-confidence object or cross confidently non-building land.
     float recoveryDistanceMetres{1.5f};
     bool splitSupportedInstances{true};
     // Supported interior pixels become instance markers; the height-step
     // exclusion still separates adjacent roof levels.
     float instanceSeedProbability{0.48f};
     // Make the instance splitter highly sensitive to small height variations between attached buildings
     float instanceHeightStepMetres{1.5f};
     float minInstanceSeedAreaSquareMetres{25.0f};
     // Sparse cores around height noise are not enough evidence to split a
     // large, otherwise continuous building into many separate boxes.
     float minInstanceSeedCoverageRatio{0.50f};

     //Instance Extractor Thresholds
     // Pixel-edge polygons require edge-connected regions: diagonally
     // touching roofs must remain separate instances, not multipart rings.
     int connectivity{4};

     //Footprint Vectorizer Thresholds
     // Relax the minimum area so smaller standalone blocks still render
     float minBuildingAreaSquareMetres{20.0f};
     // Stop tiny 2x2 pixel noise from rendering as courtyard holes
     float minHoleAreaSquareMetres{30.0f};
     // STOP DESTROYING CORNERS: Lower RDP tolerance from 4.0m to 0.75m
     float footprintSimplificationToleranceMetres{0.75f};
     float footprintAreaDeviationTolerance{0.25f};       // Max 25% area deviation allowed
     // Fill ratio only nominates a rectangle: concavity, displacement and
     // area guards must also pass. Courtyards never become bounding boxes.
     bool regularizeRectangularFootprints{true};
     float minimumRectangleFillRatio{0.84f};
     bool regularizeSupportedEdges{true};
     // PREVENT CGAL WARPING: Restrict how far CGAL can drag a corner
     float maxCornerAdjustmentMetres{1.2f};
     // Measure the final polygon against the pixels of its own instance.
     // A regularized CAD box or simplified polygon typically achieves 80-88% IoU.
     float minimumFootprintMaskIoU{0.68f};

     // Turn OFF complex roof and block logic to guarantee clean LoD1 Prisms
     bool enableLod2BlockDecomposition{false};
     // Allow the Decomposer to accept cleaner, slightly smaller CAD boxes
     float minDecompositionCoverage{0.82f};
     float minDecompositionMaskIoU{0.75f};
     float decompositionResidualRatio{0.05f};
     float minDecomposedBlockAreaSquareMetres{16.0f};
     // L/T setbacks need two or three primitives. More pieces tend to turn
     // dense urban parcels into disconnected-looking rectangular fragments.
     int maxDecomposedBlocks{3};

     // DSM-driven parametric roof fitting. Weak or inconsistent evidence
     // always falls back to a flat block instead of inventing roof geometry.
     bool enableLod2RoofFitting{false};
     float roofBoundaryBandMetres{2.0f};
     float minRoofRiseMetres{1.5f};
     float maxRoofRiseMetres{15.0f};
     float minRoofFitConfidence{0.45f};
     float flatRoofPitchDegrees{15.0f};
     float minPitchedRoofDegrees{18.0f};
     float commercialFlatRoofAreaSquareMetres{250.0f};
     float minSetbackHeightStepMetres{3.0f};

     //Height Estimator Thresholds
     float groundBufferRadiusMetres{3.0f};               // How far out to search for ground
     float footprintErosionRadiusMetres{1.0f};           // How far in to erode to avoid edge-blur
     int minRequiredSamples{5};                          // Minimum pixels needed for robust median
     float minBuildingHeightMetres{1.5f};
     float maxBuildingHeightMetres{500.0f};
     // Robust 10th-to-90th percentile DTM relief permitted beneath one
     // footprint. This rejects long cliff/ridge components hallucinated as
     // buildings without letting one noisy DEM pixel reject a real building.
     float maxFootprintElevationDeltaMetres{75.0f};
     // Expanding every footprint by one raster cell creates the visible halo
     // around optical roofs and makes neighbouring buildings touch.
     float footprintDilationMetres{0.0f};
     // Boost height scaling to dramatically separate skyscrapers from mid-rises
     float heightScaleMultiplier{2.25f}; // Increased from 1.85f for distinct visual relief

     // Universal Configuration Validator
     bool validate() const
     {
         return std::isfinite(buildingProbabilityThreshold) && buildingProbabilityThreshold >= 0.0f && buildingProbabilityThreshold <= 1.0f &&
             std::isfinite(minBuildingSemanticConfidence) && minBuildingSemanticConfidence >= 0.0f && minBuildingSemanticConfidence <= 1.0f &&
             std::isfinite(buildingRecoveryProbabilityThreshold) && buildingRecoveryProbabilityThreshold >= 0.0f && buildingRecoveryProbabilityThreshold <= buildingProbabilityThreshold &&
             std::isfinite(minRecoveryNdsmHeightMetres) && minRecoveryNdsmHeightMetres >= 0.0f && minRecoveryNdsmHeightMetres <= maxBuildingHeightMetres &&
             std::isfinite(openingRadiusMetres) && openingRadiusMetres >= 0.0f &&
             std::isfinite(closingRadiusMetres) && closingRadiusMetres >= 0.0f &&
             std::isfinite(recoveryDistanceMetres) && recoveryDistanceMetres >= 0.0f && recoveryDistanceMetres <= 12.0f &&
             std::isfinite(instanceSeedProbability) && instanceSeedProbability >= buildingRecoveryProbabilityThreshold && instanceSeedProbability <= 1.0f &&
             std::isfinite(instanceHeightStepMetres) && instanceHeightStepMetres > 0.0f &&
             std::isfinite(minInstanceSeedAreaSquareMetres) && minInstanceSeedAreaSquareMetres > 0.0f &&
             std::isfinite(minInstanceSeedCoverageRatio) && minInstanceSeedCoverageRatio > 0.0f && minInstanceSeedCoverageRatio <= 1.0f &&
             (connectivity == 4 || connectivity == 8) &&
             std::isfinite(minBuildingAreaSquareMetres) && minBuildingAreaSquareMetres >= 0.0f &&
             std::isfinite(minHoleAreaSquareMetres) && minHoleAreaSquareMetres >= 0.0f &&
             std::isfinite(footprintSimplificationToleranceMetres) && footprintSimplificationToleranceMetres >= 0.0f &&
             std::isfinite(footprintAreaDeviationTolerance) && footprintAreaDeviationTolerance >= 0.0f &&
             std::isfinite(minimumRectangleFillRatio) && minimumRectangleFillRatio >= 0.70f && minimumRectangleFillRatio <= 1.0f &&
             std::isfinite(maxCornerAdjustmentMetres) && maxCornerAdjustmentMetres >= 0.0f && maxCornerAdjustmentMetres <= 3.0f &&
             std::isfinite(minimumFootprintMaskIoU) && minimumFootprintMaskIoU > 0.0f && minimumFootprintMaskIoU <= 1.0f &&
             std::isfinite(minDecompositionCoverage) && minDecompositionCoverage > 0.0f && minDecompositionCoverage <= 1.0f &&
             std::isfinite(minDecompositionMaskIoU) && minDecompositionMaskIoU > 0.0f && minDecompositionMaskIoU <= 1.0f &&
             std::isfinite(decompositionResidualRatio) && decompositionResidualRatio >= 0.0f && decompositionResidualRatio < 1.0f &&
             std::isfinite(minDecomposedBlockAreaSquareMetres) && minDecomposedBlockAreaSquareMetres > 0.0f &&
             maxDecomposedBlocks > 0 && maxDecomposedBlocks <= 128 &&
             std::isfinite(roofBoundaryBandMetres) && roofBoundaryBandMetres > 0.0f &&
             std::isfinite(minRoofRiseMetres) && minRoofRiseMetres >= 0.0f &&
             std::isfinite(maxRoofRiseMetres) && maxRoofRiseMetres >= minRoofRiseMetres &&
             std::isfinite(minRoofFitConfidence) && minRoofFitConfidence >= 0.0f && minRoofFitConfidence <= 1.0f &&
             std::isfinite(flatRoofPitchDegrees) && flatRoofPitchDegrees >= 0.0f && flatRoofPitchDegrees < minPitchedRoofDegrees &&
             std::isfinite(minPitchedRoofDegrees) && minPitchedRoofDegrees <= 45.0f &&
             std::isfinite(commercialFlatRoofAreaSquareMetres) && commercialFlatRoofAreaSquareMetres > 0.0f &&
             std::isfinite(minSetbackHeightStepMetres) && minSetbackHeightStepMetres > 0.0f &&
             std::isfinite(groundBufferRadiusMetres) && groundBufferRadiusMetres >= 0.0f &&
             std::isfinite(footprintErosionRadiusMetres) && footprintErosionRadiusMetres >= 0.0f &&
             minRequiredSamples > 0 &&
             std::isfinite(minBuildingHeightMetres) && minBuildingHeightMetres > 0.0f &&
             std::isfinite(maxBuildingHeightMetres) && maxBuildingHeightMetres >= minBuildingHeightMetres &&
             std::isfinite(maxFootprintElevationDeltaMetres) && maxFootprintElevationDeltaMetres > 0.0f &&
             std::isfinite(footprintDilationMetres) && footprintDilationMetres >= 0.0f &&
             std::isfinite(heightScaleMultiplier) && heightScaleMultiplier > 0.0f;
     }
};
