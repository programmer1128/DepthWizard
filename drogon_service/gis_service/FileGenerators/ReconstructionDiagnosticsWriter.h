#pragma once
#include "../BuildingReconstruction/BuildingReconstructionTypes.h"
#include "../structures/SurfaceStructs.h"
#include <filesystem>

struct ReconstructionDiagnosticPayload
{
    RasterGrid<float> buildingProbability;
    RasterGrid<float> roadProbability;
    RasterGrid<float> vegetationProbability;
    RasterGrid<float> semanticConfidence;
    RasterGrid<uint8_t> finalClasses;
    RasterGrid<float> rawNdsm;
    RasterGrid<float> reconstructionNdsm;
    BuildingReconstructionDiagnostics stages;
    BuildingCollection buildings;
    std::string presentationMode;
    std::string presentationReason;
    double strongBuildingFraction{0};
    double vegetationFraction{0};
    double supportedGroundReliefMetres{0};
    std::vector<std::string> meshWarnings;
    std::size_t emittedBuildings{0};
};

// Called exclusively by the existing bounded background export worker.
// GeoTIFF snapshots retain CRS/affine and raw numeric values for comparison.
class ReconstructionDiagnosticsWriter
{
public:
    static std::filesystem::path write(
        const std::filesystem::path& root, const std::string& uuid,
        const ReconstructionDiagnosticPayload& diagnostics,
        const GeoreferencedSurfaceBundle& surface);
};
