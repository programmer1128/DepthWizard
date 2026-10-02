#pragma once

#include "ProjectiveTexturingTypes.h"
#include "RpcCameraModel.h"
#include "SensorLookGeometry.h"
#include "../structures/CommonTypes.h"
#include "../structures/GeographicStructs.h"
#include "../structures/MeshStructs.h"

#include <optional>
#include <vector>

// calculates where every 3D roof and wall vertex should sample its texture from the 2D optical image

class ProjectiveTexturingEngine {
public:
    ProjectiveTexturingEngine() = default;

    // Determines projection mode: selects RPC projective mapping when valid RPC metadata exists; otherwise, selects Affine UV mapping as mandatory fallback.
    ProjectionMode determineProjectionMode(const std::optional<RpcCameraModel>& rpc) const;

    // Projects a 3D vertex into the source optical image to determine its exact source pixel and UV.
    ProjectedVertex projectVertex(
        const ProjectedPoint& pt,
        double elevation,
        double heightAboveGround,
        const SpatialMetadata& metadata,
        const std::optional<RpcCameraModel>& rpc,
        const ProjectiveTexturingConfig& config) const;

    // Mandatory fallback: Affine UV mapping when RPC metadata is absent or invalid
    ProjectedVertex projectAffineFallback(
        const ProjectedPoint& pt,
        double elevation,
        const SpatialMetadata& metadata,
        const ProjectiveTexturingConfig& config) const;

    // Rigorous RPC projection using Rational Polynomial Coefficients
    ProjectedVertex projectRpc(
        const ProjectedPoint& pt,
        double elevation,
        const SpatialMetadata& metadata,
        const RpcCameraModel& rpc,
        const ProjectiveTexturingConfig& config) const;

    // Derives roofprint-to-footprint displacement using fitted metric height and sensor look direction
    Displacement2D deriveRoofDisplacement(
        double metricHeight,
        const SpatialMetadata& metadata,
        const std::optional<SensorLookGeometry>& lookGeom,
        const std::optional<RpcCameraModel>& rpc,
        double sampleEasting = 0.0,
        double sampleNorthing = 0.0,
        double baseElevation = 0.0) const;

    // Strict image boundary validation: rejects any pixel within guard band or out-of-bounds
    bool checkStrictBounds(
        double col,
        double row,
        int width,
        int height,
        double guardBandPixels) const;

    // Anti-bleeding verification: strictly checks for overlap or encroachment between adjacent buildings to guarantee zero source-pixel bleeding between adjacent building roofs
    bool verifyAntiBleeding(
        const std::vector<PixelPoint>& candidateRoofprintPixels,
        uint32_t candidateBuildingId,
        const std::vector<BuildingInstance>& allBuildings,
        const SpatialMetadata& metadata,
        const std::optional<SensorLookGeometry>& lookGeom,
        const std::optional<RpcCameraModel>& rpc,
        const ProjectiveTexturingConfig& config) const;

    // Inward safety contraction to guarantee that bilinear texture sampling does not bleed neighbor pixels
    std::vector<ProjectedVertex> applyAntiBleedInset(
        const std::vector<ProjectedVertex>& vertices,
        double insetMarginPixels,
        int width,
        int height) const;

    // Recovers facades: detects visible vs hidden strips, rectifies visible strips, applies neutral/procedural materials to hidden/back-facing walls, and tags each with explicit provenance.
    std::vector<FacadeStrip> recoverFacades(
        const BuildingInstance& bldg,
        const std::vector<BuildingInstance>& allBuildings,
        const SpatialMetadata& metadata,
        const std::optional<RpcCameraModel>& rpc,
        const std::optional<SensorLookGeometry>& lookGeom,
        const ProjectiveTexturingConfig& config,
        TexturingDiagnostics& diagnostics) const;

    // Processes a single building instance
    TexturedBuilding processBuilding(
        const BuildingInstance& bldg,
        const std::vector<BuildingInstance>& allBuildings,
        const SpatialMetadata& metadata,
        const std::optional<RpcCameraModel>& rpc,
        const std::optional<SensorLookGeometry>& lookGeom,
        const ProjectiveTexturingConfig& config,
        TexturingDiagnostics& diagnostics) const;

    // Processes a collection of building instances, returning textured building records and diagnostics
    std::vector<TexturedBuilding> processBuildingCollection(
        const BuildingCollection& buildings,
        const SpatialMetadata& metadata,
        const std::optional<RpcCameraModel>& rpc,
        const std::optional<SensorLookGeometry>& lookGeom,
        const ProjectiveTexturingConfig& config,
        TexturingDiagnostics& diagnostics) const;

    // Integrates the computed projective UVs and materials into the final MeshPrimitive structures
    void applyToBuildingMesh(
        BuildingMesh& mesh,
        const std::vector<TexturedBuilding>& texturedBuildings,
        const LocalSceneFrame& frame,
        const ProjectiveTexturingConfig& config) const;
};
