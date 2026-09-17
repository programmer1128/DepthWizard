#pragma once
#include "CommonTypes.h"
#include <vector>
#include <cstdint>
#include <optional>
#include "InferenceStructs.h"

struct GlbBuildResult 
{
     std::vector<uint8_t> compressedGlbByteBuffer;
     size_t vertexCount;
     size_t triangleCount;
     size_t buildingCount;
     double boundingBox[6]; // [minX, minY, minZ, maxX, maxY, maxZ]
     std::vector<std::string> geometryWarnings;
};

struct ArtifactStatus 
{
     JobStatus status;
     std::string url;
};

struct ArtifactManifest 
{
     ArtifactStatus glb;
     ArtifactStatus DSM;
     ArtifactStatus DTM;
     ArtifactStatus nDSM;
     ArtifactStatus slope;
     ArtifactStatus hillshade;
     ArtifactStatus confidence;
     std::optional<ArtifactStatus> canopyHeight;
};

struct QualityReport 
{
     std::string status; // "PASS", "WARN", "FAIL"
     float overallConfidence;
     bool safeForAbsoluteOutput;
     std::vector<std::string> violations;
     std::vector<std::string> userWarnings;
};

struct PipelineResult 
{
     std::string jobId;
     PipelineMode processingMode;
     std::string status;
     ArtifactManifest manifest;
     QualityReport qualityReport;
     ModelMetadata modelVersions;
     std::vector<std::string> warningsErrors;
};
