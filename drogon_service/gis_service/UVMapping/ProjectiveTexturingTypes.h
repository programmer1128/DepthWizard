#pragma once

#include "../structures/CommonTypes.h"
#include "../structures/GeographicStructs.h"
#include <array>
#include <cstdint>
#include <optional>
#include <string>
#include <vector>

enum class ProjectionMode {
    RPC_PROJECTIVE,
    AFFINE_FALLBACK,
    UNSPECIFIED
};

inline const char* toString(ProjectionMode mode) {
    switch (mode) {
        case ProjectionMode::RPC_PROJECTIVE: return "RPC_PROJECTIVE";
        case ProjectionMode::AFFINE_FALLBACK: return "AFFINE_FALLBACK";
        case ProjectionMode::UNSPECIFIED: return "UNSPECIFIED";
    }
    return "UNKNOWN";
}

enum class MaterialProvenance : uint8_t {
    UNKNOWN = 0,
    SOURCE_PROJECTIVE_RPC = 1,    // Projected directly from source optical image using RPC
    SOURCE_PROJECTIVE_AFFINE = 2, // Projected from source optical image using affine fallback
    FACADE_RECTIFIED_VISIBLE = 3, // Visible facade strip rectified from source image
    PROCEDURAL_NEUTRAL = 4,       // Neutral procedural material for hidden/back-facing walls
    OCCLUDED_BACKFACING = 5,      // Back-facing wall occluded from sensor line-of-sight
    REJECTED_OUT_OF_BOUNDS = 6,   // Rejected: projection fell outside valid image raster bounds
    REJECTED_UNCERTAIN = 7,       // Rejected: high projection uncertainty / grazing angle
    REJECTED_BLEED_RISK = 8       // Rejected: encroaches on adjacent building boundary
};

inline const char* toString(MaterialProvenance provenance) {
    switch (provenance) {
        case MaterialProvenance::UNKNOWN: return "UNKNOWN";
        case MaterialProvenance::SOURCE_PROJECTIVE_RPC: return "SOURCE_PROJECTIVE_RPC";
        case MaterialProvenance::SOURCE_PROJECTIVE_AFFINE: return "SOURCE_PROJECTIVE_AFFINE";
        case MaterialProvenance::FACADE_RECTIFIED_VISIBLE: return "FACADE_RECTIFIED_VISIBLE";
        case MaterialProvenance::PROCEDURAL_NEUTRAL: return "PROCEDURAL_NEUTRAL";
        case MaterialProvenance::OCCLUDED_BACKFACING: return "OCCLUDED_BACKFACING";
        case MaterialProvenance::REJECTED_OUT_OF_BOUNDS: return "REJECTED_OUT_OF_BOUNDS";
        case MaterialProvenance::REJECTED_UNCERTAIN: return "REJECTED_UNCERTAIN";
        case MaterialProvenance::REJECTED_BLEED_RISK: return "REJECTED_BLEED_RISK";
    }
    return "UNKNOWN";
}

struct ProjectedVertex {
    double x{0.0};          // 3D coordinate X (Projected Easting or Local X)
    double y{0.0};          // 3D coordinate Y (Elevation or Local Y)
    double z{0.0};          // 3D coordinate Z (Projected Northing or Local Z)
    double pixelCol{0.0};   // Exact image column (Sample)
    double pixelRow{0.0};   // Exact image row (Line)
    float u{0.0f};          // glTF normalized UV U [0.0, 1.0]
    float v{0.0f};          // glTF normalized UV V [0.0, 1.0]
    MaterialProvenance provenance{MaterialProvenance::UNKNOWN};
    bool isValid{false};
    std::string rejectionReason;
};

struct FacadeStrip {
    uint32_t wallIndex{0};
    // 4 corners of the quad in 3D:
    // [0]: base start (V_i at Z_base)
    // [1]: base end (V_{i+1} at Z_base)
    // [2]: roof end (V_{i+1} at Z_roof)
    // [3]: roof start (V_i at Z_roof)
    std::array<ProjectedVertex, 4> corners;
    double outwardNormalX{0.0};
    double outwardNormalY{0.0};
    bool isVisibleToSensor{false};
    bool isOccludedByNeighbor{false};
    MaterialProvenance provenance{MaterialProvenance::UNKNOWN};
    std::array<float, 4> proceduralColor{0.72f, 0.72f, 0.75f, 1.0f};
};

struct TexturedBuilding {
    uint32_t buildingId{0};
    ProjectionMode projectionMode{ProjectionMode::UNSPECIFIED};
    std::vector<ProjectedVertex> roofVertices;
    std::vector<uint32_t> roofIndices;
    std::vector<FacadeStrip> facadeStrips;

    // Packed UVs ready for MeshPrimitive ([u0, v0, u1, v1, ...])
    std::vector<float> roofUVs;
    std::vector<float> wallUVs;

    // Vertex colors for hypsometric/neutral/procedural shading ([r, g, b, a, ...])
    std::vector<float> roofColors;
    std::vector<float> wallColors;

    std::vector<MaterialProvenance> wallProvenancePerStrip;
    MaterialProvenance roofProvenance{MaterialProvenance::UNKNOWN};
    bool isTexturedSuccessfully{false};
    std::string diagnosticNotes;
};

struct ProjectiveTexturingConfig {
    // Guard band in pixels from image boundaries to reject boundary edge effects
    double guardBandPixels{1.0};

    // Anti-bleed inward safety margin in pixels (contracts UVs away from exterior boundary)
    double antiBleedMarginPixels{1.0};

    // Minimum distance in pixels required between roofs before triggering bleed rejection
    double minAdjacentSeparationPixels{0.5};

    // Maximum off-nadir angle permitted before tagging as uncertain (degrees)
    double maxOffNadirAngleDegrees{75.0};

    // Neutral architectural wall material tint (RGBA) applied to back-facing/hidden facades
    std::array<float, 4> neutralWallColor{0.72f, 0.72f, 0.75f, 1.0f};

    // Neutral procedural roof material tint (RGBA) applied when roof projection is rejected
    std::array<float, 4> neutralRoofColor{0.65f, 0.65f, 0.68f, 1.0f};

    // Whether off-nadir facade recovery and rectification are enabled
    bool enableFacadeRecovery{true};

    // Whether neighbor-on-neighbor line-of-sight occlusion testing is enabled
    bool enableNeighborOcclusionCheck{true};

    // Strictly reject any out-of-bounds projections
    bool strictBounding{true};

    // Strictly reject projections overlapping adjacent buildings
    bool strictAntiBleeding{true};
};

struct TexturingDiagnostics {
    std::size_t totalBuildingsProcessed{0};
    std::size_t rpcProjectedRoofs{0};
    std::size_t affineFallbackRoofs{0};
    std::size_t visibleFacadesRectified{0};
    std::size_t hiddenFacadesProcedural{0};
    std::size_t rejectedOutOfBounds{0};
    std::size_t rejectedUncertain{0};
    std::size_t rejectedBleedRisk{0};
    std::vector<std::string> warnings;
};
