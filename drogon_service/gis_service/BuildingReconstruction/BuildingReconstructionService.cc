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
     const BuildingReconstructionConfig& config,
     BuildingReconstructionDiagnostics* diagnostics)
{
     if (diagnostics) *diagnostics = {};
     BuildingCollection collection; // Initializes empty. Valid return state if no buildings exist.

     //Mask Cleanup
     BuildingMaskResult maskResult = BuildingMaskProcessor::createCleanMask(
         semantics, surface.ndsm, surface.validMask, metadata, config);
        
     if (!maskResult.success) 
     {
         if (diagnostics) diagnostics->rejectionReasons.push_back(maskResult.errorMessage);
         std::cerr << "[Module 6] Mask processing failed: " << maskResult.errorMessage << "\n";
         return collection;
     }

     collection.recoveredCandidatePixelCount =
         static_cast<std::size_t>(maskResult.recoveredCandidatePixelCount);

     //Instance Extraction
     ComponentExtractionResult extractionResult = BuildingInstanceExtractor::extract(
         maskResult, semantics, metadata, config, &surface.ndsm);
     if (diagnostics)
     {
         diagnostics->candidateMask = std::move(maskResult.candidateMask);
         diagnostics->cleanedMask = std::move(maskResult.cleanMask);
         diagnostics->instanceLabels = extractionResult.labelRaster;
         if (!extractionResult.success) diagnostics->rejectionReasons.push_back(extractionResult.errorMessage);
     }

     collection.semanticCandidateCount =
         static_cast<std::size_t>(extractionResult.acceptedComponentCount);
     collection.componentRejectedCount =
         static_cast<std::size_t>(extractionResult.rejectedComponentCount);
 
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
         // Store confidence in the building hypothesis itself. Recovered
         // UNKNOWN pixels intentionally have zero final-class confidence but
         // still carry a meaningful building probability.
         instance.semanticConfidence = stats.meanBuildingProbability;

         //Footprint Vectorization
         FootprintVectorizationResult vectorResult = FootprintVectorizer::vectorize(
             stats, extractionResult.labelRaster, metadata, config);

         if (!vectorResult.success) 
         {
             if (diagnostics) diagnostics->rejectionReasons.push_back(
                 "Building " + std::to_string(stats.componentId) + ": " + vectorResult.errorMessage);
             ++collection.vectorizationRejectedCount;
             std::cerr << "[Module 6] Rejected semantic candidate "
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
             if (diagnostics) diagnostics->rejectionReasons.push_back(
                 "Building " + std::to_string(stats.componentId) + ": " + heightResult.errorMessage);
             ++collection.physicsRejectedCount;
             std::cerr << "[Module 6] Rejected semantic candidate "
                      << stats.componentId << ": " << heightResult.errorMessage << "\n";
             continue; // Skip rendering a building with corrupted physics
         }

         instance.representativeBaseElevation = heightResult.representativeBaseElevation;
         instance.baseElevationPerVertex =
             std::move(heightResult.baseElevationPerOuterVertex);
         instance.baseModel =
             instance.baseElevationPerVertex.size() ==
                     instance.projectedFootprint.outerRing.size()
                 ? BaseElevationModel::PER_VERTEX
                 : BaseElevationModel::FLAT;
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

     std::cerr << "[Module 6] Reconstruction summary: semantic candidates="
               << extractionResult.acceptedComponentCount
               << ", accepted buildings=" << collection.buildings.size()
               << ", recovered candidate pixels="
               << collection.recoveredCandidatePixelCount
               << ", component rejected=" << collection.componentRejectedCount
               << ", vectorization rejected=" << collection.vectorizationRejectedCount
               << ", physics rejected=" << collection.physicsRejectedCount << "\n";

     return collection;
}
