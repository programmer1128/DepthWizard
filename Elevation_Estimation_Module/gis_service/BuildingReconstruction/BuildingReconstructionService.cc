#include "BuildingReconstructionService.h"
#include "BuildingMaskProcessor.h"
#include "BuildingInstanceExtractor.h"
#include "FootprintVectorizer.h"
#include "BuildingHeightEstimator.h"
#include "BuildingFootprintDecomposer.h"
#include "BuildingRoofModeler.h"
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <algorithm>
#include <cmath>
#include <iostream>

BuildingCollection BuildingReconstructionService::reconstruct(
     const SemanticScene& semantics,
     const GeoreferencedSurfaceBundle& surface,
     const SpatialMetadata& metadata,
     const BuildingReconstructionConfig& config,
     BuildingReconstructionDiagnostics* diagnostics,
     const RasterGrid<float>* reconstructionNdsm,
     const std::vector<uint8_t>* opticalImageBytes)
{
     return reconstructDetailed(semantics, surface, metadata, config, diagnostics,
                                reconstructionNdsm, opticalImageBytes).buildings;
}

BuildingReconstructionResult BuildingReconstructionService::reconstructDetailed(
     const SemanticScene& semantics,
     const GeoreferencedSurfaceBundle& surface,
     const SpatialMetadata& metadata,
     const BuildingReconstructionConfig& config,
     BuildingReconstructionDiagnostics* diagnostics,
     const RasterGrid<float>* reconstructionNdsm,
     const std::vector<uint8_t>* opticalImageBytes)
{
     if (diagnostics) *diagnostics = {};
     BuildingReconstructionResult result;
     BuildingCollection& collection = result.buildings; // Empty is a valid result.


     const RasterGrid<float>& evidenceNdsm = reconstructionNdsm != nullptr
         ? *reconstructionNdsm
         : surface.ndsm;

     // The orthophoto contains facade edges missing from a blurred semantic
     // mask. Detect its long line segments once for all building footprints.
     std::vector<cv::Vec4f> opticalLines;
     RasterGrid<uint8_t> opticalGray;
     if (opticalImageBytes != nullptr && !opticalImageBytes->empty())
     {
         const cv::Mat gray = cv::imdecode(
             *opticalImageBytes, cv::IMREAD_GRAYSCALE);
         if (gray.cols == metadata.width && gray.rows == metadata.height)
         {
             opticalGray.width = metadata.width;
             opticalGray.height = metadata.height;
             opticalGray.data.resize(
                 static_cast<std::size_t>(gray.cols) * gray.rows);
             for (int row = 0; row < gray.rows; ++row)
                 std::copy_n(gray.ptr<uint8_t>(row), gray.cols,
                     opticalGray.data.begin() +
                         static_cast<std::size_t>(row) * gray.cols);
             const auto detector = cv::createLineSegmentDetector(
                 cv::LSD_REFINE_STD);
             detector->detect(gray, opticalLines);
             std::erase_if(opticalLines, [](const cv::Vec4f& line)
             {
                 return std::hypot(line[2] - line[0],
                                   line[3] - line[1]) < 8.0;
             });
         }
     }

     // Recover long wall evidence from the reconstructed height field even
     // where the optical roof edge is obscured. LSD operates on a byte image;
     // confirm every proposed line against the original metric nDSM so that
     // quantization, no-data seams, and roof texture do not become facades.
     if (evidenceNdsm.isValid() &&
         evidenceNdsm.width == metadata.width &&
         evidenceNdsm.height == metadata.height)
     {
         cv::Mat depth8U(metadata.height, metadata.width, CV_8UC1,
                         cv::Scalar(0));
         for (std::size_t i = 0; i < evidenceNdsm.data.size(); ++i)
         {
             const float height = evidenceNdsm.data[i];
             if (std::isfinite(height) && height > 0.5f)
                 depth8U.ptr<uint8_t>()[i] =
                     cv::saturate_cast<uint8_t>(height * 8.0f);
         }
         std::vector<cv::Vec4f> ndsmLines;
         cv::createLineSegmentDetector(cv::LSD_REFINE_ADV)->detect(
             depth8U, ndsmLines);
         const auto supportsHeightCliff = [&](const cv::Vec4f& line)
         {
             const double dx = line[2] - line[0];
             const double dy = line[3] - line[1];
             const double length = std::hypot(dx, dy);
             if (length < 5.0) return false;
             const double nx = -dy / length;
             const double ny = dx / length;
             int supported = 0;
             for (double t : {0.25, 0.5, 0.75})
             {
                 const double px = line[0] + t * dx;
                 const double py = line[1] + t * dy;
                 const int ax = cvRound(px + 1.5 * nx);
                 const int ay = cvRound(py + 1.5 * ny);
                 const int bx = cvRound(px - 1.5 * nx);
                 const int by = cvRound(py - 1.5 * ny);
                 if (ax < 0 || bx < 0 || ay < 0 || by < 0 ||
                     ax >= metadata.width || bx >= metadata.width ||
                     ay >= metadata.height || by >= metadata.height)
                     continue;
                 const float a = evidenceNdsm.data[
                     static_cast<std::size_t>(ay) * metadata.width + ax];
                 const float b = evidenceNdsm.data[
                     static_cast<std::size_t>(by) * metadata.width + bx];
                 if (std::isfinite(a) && std::isfinite(b) &&
                     std::abs(a - b) * config.heightScaleMultiplier >
                         0.65f * config.instanceHeightStepMetres)
                     ++supported;
             }
             return supported >= 2;
         };
         for (const auto& line : ndsmLines)
             if (supportsHeightCliff(line)) opticalLines.push_back(line);
     }

     //Mask Cleanup
     BuildingMaskResult maskResult = BuildingMaskProcessor::createCleanMask(
         semantics, evidenceNdsm, surface.validMask, metadata, config);
        
     if (!maskResult.success) 
     {
         if (diagnostics) diagnostics->rejectionReasons.push_back(maskResult.errorMessage);
         std::cerr << "[Module 6] Mask processing failed: " << maskResult.errorMessage << "\n";
         return result;
     }

     collection.recoveredCandidatePixelCount =
         static_cast<std::size_t>(maskResult.recoveredCandidatePixelCount);

     //Instance Extraction
     ComponentExtractionResult extractionResult = BuildingInstanceExtractor::extract(
         maskResult, semantics, metadata, config, &evidenceNdsm,
         opticalGray.isValid() ? &opticalGray : nullptr);
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
         result.instanceLabels = std::move(extractionResult.labelRaster);
         return result;
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
             stats, extractionResult.labelRaster, metadata, config,
             opticalLines.empty() ? nullptr : &opticalLines);

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
             instance.pixelFootprint, surface, semantics, metadata, config,
             &evidenceNdsm, &extractionResult.labelRaster,
             stats.componentId);

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

         if (config.enableLod2BlockDecomposition)
         {
             FootprintDecompositionResult decomposition =
                 BuildingFootprintDecomposer::decompose(
                     instance.pixelFootprint, metadata, config);
             instance.geometryWarnings.insert(
                 instance.geometryWarnings.end(),
                 decomposition.warnings.begin(),
                 decomposition.warnings.end());
             if (decomposition.accepted)
             {
                 instance.blocks = std::move(decomposition.blocks);
                 BuildingRoofModeler::fit(
                     instance.blocks, evidenceNdsm, surface.validMask,
                     metadata, instance.heightAboveGround, config);
                 // The parcel-level median can describe a broad podium while
                 // missing a narrower supported tower. Use the highest fitted
                 // block as the building's overall height.
                 for (const auto& block : instance.blocks)
                     instance.heightAboveGround = std::max(
                         instance.heightAboveGround,
                         block.roof.ridgeHeightAboveGround);
                 instance.roofElevation =
                     instance.representativeBaseElevation +
                     instance.heightAboveGround;
                 collection.lod2BlockCount += instance.blocks.size();
                 for (const auto& block : instance.blocks)
                 {
                     switch (block.roof.type)
                     {
                         case RoofType::FLAT:
                             ++collection.flatRoofBlockCount;
                             break;
                         case RoofType::GABLE:
                             ++collection.gableRoofBlockCount;
                             break;
                         case RoofType::HIP:
                             ++collection.hipRoofBlockCount;
                             break;
                     }
                 }
             }
         }

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
     std::cerr << "[Module 6] LoD2 summary: blocks="
               << collection.lod2BlockCount
               << ", flat=" << collection.flatRoofBlockCount
               << ", gable=" << collection.gableRoofBlockCount
               << ", hip=" << collection.hipRoofBlockCount << "\n";

     result.instanceLabels = std::move(extractionResult.labelRaster);
     return result;
}
