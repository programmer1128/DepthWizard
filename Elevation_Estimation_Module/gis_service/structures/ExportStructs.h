#pragma once
#include "CommonTypes.h"
#include "InferenceStructs.h"
#include "MeshStructs.h"
#include <optional>

struct GlbBuildResult 
{
    std::vector<uint8_t> compressedGlbByteBuffer;
    size_t vertexCount{0};
    size_t triangleCount{0};
    size_t buildingCount{0};
    size_t terrainTriangleCount{0};
    size_t roofTriangleCount{0};
    size_t wallTriangleCount{0};
    AxisAlignedBounds boundingBox;        // Replaces double[6][cite: 8]
    LocalSceneFrame localOrigin;          
    std::vector<std::string> geometryWarnings;
};

struct ArtifactStatus 
{
    JobStatus status{JobStatus::QUEUED};
    std::optional<std::string> url;             // Optional for failed/queued states[cite: 8]
    std::string objectKey;
    std::optional<std::string> errorMessage;    
};

struct ArtifactManifest 
{
    ArtifactStatus glb;
    ArtifactStatus dsm;
    ArtifactStatus dtm;
    ArtifactStatus ndsm;
    ArtifactStatus slope;
    ArtifactStatus aspect;                      
    ArtifactStatus hillshade;
    ArtifactStatus confidence;
    std::optional<ArtifactStatus> canopyHeight;
};

struct QualityReport 
{
    QualityStatus status{QualityStatus::FAIL};  
    float overallConfidence{0.0f};
    bool safeForAbsoluteOutput{false};
    std::vector<std::string> violations;
    std::vector<std::string> userWarnings;
};

struct PipelineResult 
{
    std::string jobId;
    PipelineMode processingMode{PipelineMode::GEOREFERENCED};
    PipelineStatus status{PipelineStatus::FATAL_ERROR};
    ArtifactManifest manifest;
    QualityReport qualityReport;
    ModelCollection models;
    std::vector<std::string> errors;            // Explicitly separated[cite: 8]
    std::vector<std::string> warnings;
};
