#include "BuildingReconstructionService.h"
#include "BuildingMaskProcessor.h"
#include "BuildingInstanceExtractor.h"
#include "FootprintVectorizer.h"
#include "BuildingHeightEstimator.h"
#include <iostream>

BuildingCollection BuildingReconstructionService::reconstruct(
     const SemanticScene& semantics,
     const GeoreferencedSurfaceBundle& surface,
     const SpatialMetadata& metadata,
     const BuildingReconstructionConfig& config)
{
     BuildingCollection collection; // Initializes empty. Valid return state if no buildings exist.

     //Mask Cleanup
     BuildingMaskResult maskResult = BuildingMaskProcessor::createCleanMask(
         semantics, surface.validMask, metadata, config);
        
     if (!maskResult.success) 
     {
         std::cerr << "[Module 6] Mask processing failed: " << maskResult.errorMessage << "\n";
         return collection;
     }

     //Instance Extraction
     ComponentExtractionResult extractionResult = BuildingInstanceExtractor::extract(
         maskResult, semantics, metadata, config);
 
     if (!extractionResult.success || extractionResult.acceptedComponentCount == 0) 
     {
         // No buildings found in the scene. Return empty collection gracefully.
         return collection;
     }

     // Pre-allocate space to avoid vector reallocations
     collection.buildings.reserve(extractionResult.acceptedComponentCount);

     //Loop through extracted components and generate physical instances
     for (const ComponentStats& stats : extractionResult.components) 
     {
         BuildingInstance instance;
         instance.buildingId = stats.componentId;
         instance.footprintAreaSquareMetres = static_cast<float>(stats.physicalAreaSquareMetres);
         instance.semanticConfidence = stats.meanSemanticConfidence;

         //Footprint Vectorization
         FootprintVectorizationResult vectorResult = FootprintVectorizer::vectorize(
             stats, extractionResult.labelRaster, metadata, config);

         if (!vectorResult.success) 
         {
             std::cerr << "[Module 6] Vectorization failed for Building ID " 
                       << stats.componentId << ": " << vectorResult.errorMessage << "\n";
             continue; // Skip this building and move to the next
         }

         instance.pixelFootprint = std::move(vectorResult.pixelFootprint);
         instance.projectedFootprint = std::move(vectorResult.projectedFootprint);
        
         // Append any vectorization geometry warnings
         instance.geometryWarnings.insert(instance.geometryWarnings.end(), 
                                         vectorResult.warnings.begin(), 
                                         vectorResult.warnings.end());

         //Height Estimation
         BuildingHeightEstimate heightResult = BuildingHeightEstimator::estimate(
             instance.pixelFootprint, surface, semantics, metadata, config);

         if (!heightResult.success) 
         {
             std::cerr << "[Module 6] Height estimation failed for Building ID " 
                      << stats.componentId << ": " << heightResult.errorMessage << "\n";
             continue; // Skip rendering a building with corrupted physics
         }

         instance.baseModel = BaseElevationModel::FLAT; // Version 1 uses Flat representative bases
         instance.representativeBaseElevation = heightResult.representativeBaseElevation;
         instance.heightAboveGround = heightResult.heightAboveGround;
         instance.roofElevation = heightResult.roofElevation; // base + height
         instance.heightConfidence = heightResult.confidence;

         // Append any physics/height warnings
         instance.geometryWarnings.insert(instance.geometryWarnings.end(), 
                                         heightResult.warnings.begin(), 
                                         heightResult.warnings.end());

         //Finalize and Store the Building
         collection.buildings.push_back(std::move(instance));
     }

     return collection;
}