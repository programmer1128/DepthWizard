#include "ProjectiveTexturingEngine.h"
#include "../MeshMapping/LocalFrameTransformer.h"

#include <cmath>
#include <algorithm>
#include <numeric>
#include <limits>

ProjectionMode ProjectiveTexturingEngine::determineProjectionMode(
    const std::optional<RpcCameraModel>& rpc) const {
    if (rpc.has_value() && rpc->isValid()) {
        return ProjectionMode::RPC_PROJECTIVE;
    }
    return ProjectionMode::AFFINE_FALLBACK;
}

bool ProjectiveTexturingEngine::checkStrictBounds(
    double col,
    double row,
    int width,
    int height,
    double guardBandPixels) const {

    if (width <= 0 || height <= 0) {
        return false;
    }

    const double minC = guardBandPixels;
    const double maxC = static_cast<double>(width - 1) - guardBandPixels;
    const double minR = guardBandPixels;
    const double maxR = static_cast<double>(height - 1) - guardBandPixels;

    return (col >= minC && col <= maxC && row >= minR && row <= maxR);
}

ProjectedVertex ProjectiveTexturingEngine::projectAffineFallback(
    const ProjectedPoint& pt,
    double elevation,
    const SpatialMetadata& metadata,
    const ProjectiveTexturingConfig& config) const {

    ProjectedVertex v;
    v.x = pt.easting;
    v.y = elevation;
    v.z = pt.northing;

    const auto& gt = metadata.geoTransform;
    const double det = gt[1] * gt[5] - gt[2] * gt[4];

    if (std::abs(det) < 1.0e-12) {
        v.isValid = false;
        v.provenance = MaterialProvenance::REJECTED_UNCERTAIN;
        v.rejectionReason = "Degenerate affine geotransform determinant.";
        return v;
    }

    const double invDet = 1.0 / det;
    const double col = ((pt.easting - gt[0]) * gt[5] - (pt.northing - gt[3]) * gt[2]) * invDet;
    const double row = ((pt.northing - gt[3]) * gt[1] - (pt.easting - gt[0]) * gt[4]) * invDet;

    v.pixelCol = col;
    v.pixelRow = row;

    if (!checkStrictBounds(col, row, metadata.width, metadata.height, config.guardBandPixels)) {
        v.isValid = false;
        v.provenance = MaterialProvenance::REJECTED_OUT_OF_BOUNDS;
        v.rejectionReason = "Projected coordinate fell outside source image bounds with guard band.";
        v.u = static_cast<float>(std::clamp(col / std::max(1, metadata.width), 0.0, 1.0));
        v.v = static_cast<float>(std::clamp(row / std::max(1, metadata.height), 0.0, 1.0));
        return v;
    }

    v.u = static_cast<float>(std::clamp(col / metadata.width, 0.0, 1.0));
    v.v = static_cast<float>(std::clamp(row / metadata.height, 0.0, 1.0));
    v.isValid = true;
    v.provenance = MaterialProvenance::SOURCE_PROJECTIVE_AFFINE;

    return v;
}

ProjectedVertex ProjectiveTexturingEngine::projectRpc(
    const ProjectedPoint& pt,
    double elevation,
    const SpatialMetadata& metadata,
    const RpcCameraModel& rpc,
    const ProjectiveTexturingConfig& config) const {

    ProjectedVertex v;
    v.x = pt.easting;
    v.y = elevation;
    v.z = pt.northing;

    double col = 0.0;
    double row = 0.0;

    if (!rpc.projectProjected(pt.easting, pt.northing, elevation, metadata.projectionRef, col, row)) {
        v.isValid = false;
        v.provenance = MaterialProvenance::REJECTED_UNCERTAIN;
        v.rejectionReason = "RPC projection failed or encountered numerical singularity.";
        return v;
    }

    v.pixelCol = col;
    v.pixelRow = row;

    if (!checkStrictBounds(col, row, metadata.width, metadata.height, config.guardBandPixels)) {
        v.isValid = false;
        v.provenance = MaterialProvenance::REJECTED_OUT_OF_BOUNDS;
        v.rejectionReason = "RPC projection fell outside source image bounds with guard band.";
        v.u = static_cast<float>(std::clamp(col / std::max(1, metadata.width), 0.0, 1.0));
        v.v = static_cast<float>(std::clamp(row / std::max(1, metadata.height), 0.0, 1.0));
        return v;
    }

    v.u = static_cast<float>(std::clamp(col / metadata.width, 0.0, 1.0));
    v.v = static_cast<float>(std::clamp(row / metadata.height, 0.0, 1.0));
    v.isValid = true;
    v.provenance = MaterialProvenance::SOURCE_PROJECTIVE_RPC;

    return v;
}

ProjectedVertex ProjectiveTexturingEngine::projectVertex(
    const ProjectedPoint& pt,
    double elevation,
    double heightAboveGround,
    const SpatialMetadata& metadata,
    const std::optional<RpcCameraModel>& rpc,
    const ProjectiveTexturingConfig& config) const {

    (void)heightAboveGround;
    const ProjectionMode mode = determineProjectionMode(rpc);

    if (mode == ProjectionMode::RPC_PROJECTIVE) {
        ProjectedVertex v = projectRpc(pt, elevation, metadata, *rpc, config);
        if (v.isValid) {
            return v;
        }
        // If RPC failed due to numerical uncertainty (and not out of bounds),
        // fall back to Affine UV mapping as mandatory fallback
        if (v.provenance == MaterialProvenance::REJECTED_UNCERTAIN) {
            ProjectedVertex fallback = projectAffineFallback(pt, elevation, metadata, config);
            if (fallback.isValid) {
                fallback.rejectionReason = "RPC projection uncertain; recovered via Affine fallback.";
                return fallback;
            }
        }
        return v;
    }

    return projectAffineFallback(pt, elevation, metadata, config);
}

Displacement2D ProjectiveTexturingEngine::deriveRoofDisplacement(
    double metricHeight,
    const SpatialMetadata& metadata,
    const std::optional<SensorLookGeometry>& lookGeom,
    const std::optional<RpcCameraModel>& rpc,
    double sampleEasting,
    double sampleNorthing,
    double baseElevation) const {

    if (metricHeight <= 0.0) {
        return {0.0, 0.0};
    }

    if (lookGeom.has_value()) {
        return lookGeom->computePixelDisplacement(metricHeight, metadata);
    }

    if (rpc.has_value() && rpc->isValid()) {
        double colBase = 0.0, rowBase = 0.0;
        double colRoof = 0.0, rowRoof = 0.0;
        if (rpc->projectProjected(sampleEasting, sampleNorthing, baseElevation, metadata.projectionRef, colBase, rowBase) &&
            rpc->projectProjected(sampleEasting, sampleNorthing, baseElevation + metricHeight, metadata.projectionRef, colRoof, rowRoof)) {
            return {colRoof - colBase, rowRoof - rowBase};
        }
    }

    return {0.0, 0.0};
}

static bool segmentsIntersect(
    double p0x, double p0y, double p1x, double p1y,
    double q0x, double q0y, double q1x, double q1y) {

    auto crossProduct = [](double ax, double ay, double bx, double by, double cx, double cy) {
        return (bx - ax) * (cy - ay) - (by - ay) * (cx - ax);
    };

    auto onSegment = [](double px, double py, double qx, double qy, double rx, double ry) {
        return qx <= std::max(px, rx) && qx >= std::min(px, rx) &&
               qy <= std::max(py, ry) && qy >= std::min(py, ry);
    };

    double cp1 = crossProduct(p0x, p0y, p1x, p1y, q0x, q0y);
    double cp2 = crossProduct(p0x, p0y, p1x, p1y, q1x, q1y);
    double cp3 = crossProduct(q0x, q0y, q1x, q1y, p0x, p0y);
    double cp4 = crossProduct(q0x, q0y, q1x, q1y, p1x, p1y);

    // Standard crossing intersection
    if (((cp1 > 0 && cp2 < 0) || (cp1 < 0 && cp2 > 0)) &&
        ((cp3 > 0 && cp4 < 0) || (cp3 < 0 && cp4 > 0))) {
        return true;
    }

    // Collinear and touching/overlapping checks
    const double eps = 1.0e-9;
    if (std::abs(cp1) < eps && onSegment(p0x, p0y, q0x, q0y, p1x, p1y)) return true;
    if (std::abs(cp2) < eps && onSegment(p0x, p0y, q1x, q1y, p1x, p1y)) return true;
    if (std::abs(cp3) < eps && onSegment(q0x, q0y, p0x, p0y, q1x, q1y)) return true;
    if (std::abs(cp4) < eps && onSegment(q0x, q0y, p1x, p1y, q1x, q1y)) return true;

    return false;
}

static bool pointInPolygon(double px, double py, const std::vector<PixelPoint>& poly) {
    bool inside = false;
    const std::size_t n = poly.size();
    for (std::size_t i = 0, j = n - 1; i < n; j = i++) {
        if (((poly[i].row > py) != (poly[j].row > py)) &&
            (px < (poly[j].column - poly[i].column) * (py - poly[i].row) / (poly[j].row - poly[i].row) + poly[i].column)) {
            inside = !inside;
        }
    }
    return inside;
}

bool ProjectiveTexturingEngine::verifyAntiBleeding(
    const std::vector<PixelPoint>& candidateRoofprintPixels,
    uint32_t candidateBuildingId,
    const std::vector<BuildingInstance>& allBuildings,
    const SpatialMetadata& metadata,
    const std::optional<SensorLookGeometry>& lookGeom,
    const std::optional<RpcCameraModel>& rpc,
    const ProjectiveTexturingConfig& config) const {

    if (!config.strictAntiBleeding || candidateRoofprintPixels.size() < 3) {
        return true;
    }

    double minC = std::numeric_limits<double>::max();
    double maxC = std::numeric_limits<double>::lowest();
    double minR = std::numeric_limits<double>::max();
    double maxR = std::numeric_limits<double>::lowest();

    for (const auto& p : candidateRoofprintPixels) {
        minC = std::min(minC, p.column);
        maxC = std::max(maxC, p.column);
        minR = std::min(minR, p.row);
        maxR = std::max(maxR, p.row);
    }

    const double margin = config.minAdjacentSeparationPixels;

    for (const auto& other : allBuildings) {
        if (other.buildingId == candidateBuildingId) {
            continue;
        }

        std::vector<PixelPoint> otherFootprint;
        otherFootprint.reserve(other.projectedFootprint.outerRing.size());

        double oMinC = std::numeric_limits<double>::max();
        double oMaxC = std::numeric_limits<double>::lowest();
        double oMinR = std::numeric_limits<double>::max();
        double oMaxR = std::numeric_limits<double>::lowest();

        const auto& gt = metadata.geoTransform;
        const double det = gt[1] * gt[5] - gt[2] * gt[4];
        if (std::abs(det) < 1.0e-12) continue;
        const double invDet = 1.0 / det;

        for (const auto& pt : other.projectedFootprint.outerRing) {
            const double c = ((pt.easting - gt[0]) * gt[5] - (pt.northing - gt[3]) * gt[2]) * invDet;
            const double r = ((pt.northing - gt[3]) * gt[1] - (pt.easting - gt[0]) * gt[4]) * invDet;
            otherFootprint.push_back({c, r});

            oMinC = std::min(oMinC, c);
            oMaxC = std::max(oMaxC, c);
            oMinR = std::min(oMinR, r);
            oMaxR = std::max(oMaxR, r);
        }

        if (otherFootprint.size() < 3) continue;

        if (maxC + margin < oMinC || minC - margin > oMaxC ||
            maxR + margin < oMinR || minR - margin > oMaxR) {
            continue;
        }

        for (const auto& p : candidateRoofprintPixels) {
            if (pointInPolygon(p.column, p.row, otherFootprint)) {
                return false;
            }
        }

        for (const auto& op : otherFootprint) {
            if (pointInPolygon(op.column, op.row, candidateRoofprintPixels)) {
                return false;
            }
        }

        const std::size_t nCand = candidateRoofprintPixels.size();
        const std::size_t nOther = otherFootprint.size();
        for (std::size_t i = 0; i < nCand; ++i) {
            const auto& p0 = candidateRoofprintPixels[i];
            const auto& p1 = candidateRoofprintPixels[(i + 1) % nCand];
            for (std::size_t j = 0; j < nOther; ++j) {
                const auto& q0 = otherFootprint[j];
                const auto& q1 = otherFootprint[(j + 1) % nOther];
                if (segmentsIntersect(p0.column, p0.row, p1.column, p1.row,
                                      q0.column, q0.row, q1.column, q1.row)) {
                    return false;
                }
            }
        }

        Displacement2D otherDisp = deriveRoofDisplacement(
            other.heightAboveGround, metadata, lookGeom, rpc,
            other.projectedFootprint.outerRing[0].easting,
            other.projectedFootprint.outerRing[0].northing,
            other.representativeBaseElevation);

        if (std::abs(otherDisp.dx) > 0.1 || std::abs(otherDisp.dy) > 0.1) {
            std::vector<PixelPoint> otherRoofprint = otherFootprint;
            for (auto& op : otherRoofprint) {
                op.column += otherDisp.dx;
                op.row += otherDisp.dy;
            }

            for (const auto& p : candidateRoofprintPixels) {
                if (pointInPolygon(p.column, p.row, otherRoofprint)) {
                    return false;
                }
            }

            for (std::size_t i = 0; i < nCand; ++i) {
                const auto& p0 = candidateRoofprintPixels[i];
                const auto& p1 = candidateRoofprintPixels[(i + 1) % nCand];
                for (std::size_t j = 0; j < nOther; ++j) {
                    const auto& q0 = otherRoofprint[j];
                    const auto& q1 = otherRoofprint[(j + 1) % nOther];
                    if (segmentsIntersect(p0.column, p0.row, p1.column, p1.row,
                                          q0.column, q0.row, q1.column, q1.row)) {
                        return false;
                    }
                }
            }
        }
    }

    return true;
}

std::vector<ProjectedVertex> ProjectiveTexturingEngine::applyAntiBleedInset(
    const std::vector<ProjectedVertex>& vertices,
    double insetMarginPixels,
    int width,
    int height) const {

    if (vertices.size() < 3 || insetMarginPixels <= 0.0 || width <= 0 || height <= 0) {
        return vertices;
    }

    double centerU = 0.0;
    double centerV = 0.0;
    for (const auto& v : vertices) {
        centerU += v.u;
        centerV += v.v;
    }
    centerU /= static_cast<double>(vertices.size());
    centerV /= static_cast<double>(vertices.size());

    std::vector<ProjectedVertex> insetVertices = vertices;

    for (auto& v : insetVertices) {
        const double du = centerU - v.u;
        const double dv = centerV - v.v;

        const double distPx = std::hypot(du * width, dv * height);
        if (distPx > 1.0e-3) {
            const double scale = std::min(0.20, insetMarginPixels / distPx);
            v.u = static_cast<float>(std::clamp(v.u + scale * du, 0.0, 1.0));
            v.v = static_cast<float>(std::clamp(v.v + scale * dv, 0.0, 1.0));
        }
    }

    return insetVertices;
}

std::vector<FacadeStrip> ProjectiveTexturingEngine::recoverFacades(
    const BuildingInstance& bldg,
    const std::vector<BuildingInstance>& allBuildings,
    const SpatialMetadata& metadata,
    const std::optional<RpcCameraModel>& rpc,
    const std::optional<SensorLookGeometry>& lookGeom,
    const ProjectiveTexturingConfig& config,
    TexturingDiagnostics& diagnostics) const {

    std::vector<FacadeStrip> strips;
    if (!config.enableFacadeRecovery) {
        return strips;
    }

    const auto& ring = bldg.projectedFootprint.outerRing;
    const std::size_t numVerts = ring.size();
    if (numVerts < 3) {
        return strips;
    }

    const float roofElevation = bldg.roofElevation;
    const float baseElevation = bldg.representativeBaseElevation;

    for (std::size_t i = 0; i < numVerts; ++i) {
        const auto& p1 = ring[i];
        const auto& p2 = ring[(i + 1) % numVerts];

        FacadeStrip strip;
        strip.wallIndex = static_cast<uint32_t>(i);

        const double edgeX = p2.easting - p1.easting;
        const double edgeY = p2.northing - p1.northing;
        const double edgeLen = std::hypot(edgeX, edgeY);

        if (edgeLen > 1.0e-6) {
            strip.outwardNormalX = edgeY / edgeLen;
            strip.outwardNormalY = -edgeX / edgeLen;
        }

        bool isFacing = false;
        if (lookGeom.has_value() && !lookGeom->isNadir()) {
            isFacing = lookGeom->isWallFacingSensor(p1.easting, p1.northing, p2.easting, p2.northing);
        }

        bool isNeighborOccluded = false;
        if (isFacing && config.enableNeighborOcclusionCheck && lookGeom.has_value()) {
            const double midX = 0.5 * (p1.easting + p2.easting);
            const double midY = 0.5 * (p1.northing + p2.northing);
            isNeighborOccluded = lookGeom->isOccludedByNeighbor(
                midX, midY, baseElevation, roofElevation, bldg.buildingId, allBuildings);
        }

        strip.isVisibleToSensor = isFacing && !isNeighborOccluded;
        strip.isOccludedByNeighbor = isNeighborOccluded;

        strip.corners[0] = projectVertex(p1, baseElevation, 0.0, metadata, rpc, config);
        strip.corners[1] = projectVertex(p2, baseElevation, 0.0, metadata, rpc, config);
        strip.corners[2] = projectVertex(p2, roofElevation, bldg.heightAboveGround, metadata, rpc, config);
        strip.corners[3] = projectVertex(p1, roofElevation, bldg.heightAboveGround, metadata, rpc, config);

        if (strip.isVisibleToSensor) {
            bool allValid = strip.corners[0].isValid && strip.corners[1].isValid &&
                            strip.corners[2].isValid && strip.corners[3].isValid;

            if (allValid) {
                strip.provenance = MaterialProvenance::FACADE_RECTIFIED_VISIBLE;
                for (auto& corner : strip.corners) {
                    corner.provenance = MaterialProvenance::FACADE_RECTIFIED_VISIBLE;
                }
                diagnostics.visibleFacadesRectified++;
            } else {
                strip.isVisibleToSensor = false;
                strip.provenance = MaterialProvenance::REJECTED_OUT_OF_BOUNDS;
                strip.proceduralColor = config.neutralWallColor;
                diagnostics.hiddenFacadesProcedural++;
            }
        } else {
            strip.provenance = isNeighborOccluded
                ? MaterialProvenance::OCCLUDED_BACKFACING
                : MaterialProvenance::PROCEDURAL_NEUTRAL;
            strip.proceduralColor = config.neutralWallColor;
            for (auto& corner : strip.corners) {
                corner.provenance = strip.provenance;
            }
            diagnostics.hiddenFacadesProcedural++;
        }

        strips.push_back(strip);
    }

    return strips;
}

TexturedBuilding ProjectiveTexturingEngine::processBuilding(
    const BuildingInstance& bldg,
    const std::vector<BuildingInstance>& allBuildings,
    const SpatialMetadata& metadata,
    const std::optional<RpcCameraModel>& rpc,
    const std::optional<SensorLookGeometry>& lookGeom,
    const ProjectiveTexturingConfig& config,
    TexturingDiagnostics& diagnostics) const {

    TexturedBuilding result;
    result.buildingId = bldg.buildingId;
    result.projectionMode = determineProjectionMode(rpc);

    const auto& ring = bldg.projectedFootprint.outerRing;
    const std::size_t numVerts = ring.size();

    if (numVerts < 3) {
        result.isTexturedSuccessfully = false;
        result.roofProvenance = MaterialProvenance::REJECTED_UNCERTAIN;
        result.diagnosticNotes = "Building has fewer than 3 vertices.";
        return result;
    }

    std::vector<ProjectedVertex> projectedRoof;
    projectedRoof.reserve(numVerts);
    std::vector<PixelPoint> roofprintPixels;
    roofprintPixels.reserve(numVerts);

    bool allRoofValid = true;
    std::string rejectionReason;
    MaterialProvenance failureProvenance = MaterialProvenance::UNKNOWN;

    for (const auto& pt : ring) {
        ProjectedVertex pv = projectVertex(
            pt, bldg.roofElevation, bldg.heightAboveGround, metadata, rpc, config);

        if (!pv.isValid) {
            allRoofValid = false;
            rejectionReason = pv.rejectionReason;
            failureProvenance = pv.provenance;
        }

        roofprintPixels.push_back({pv.pixelCol, pv.pixelRow});
        projectedRoof.push_back(pv);
    }

    // If using Affine fallback and off-nadir sensor look geometry is provided,
    // derive the roofprint displacement and displace roof vertices accordingly
    Displacement2D roofDisp = deriveRoofDisplacement(
        bldg.heightAboveGround, metadata, lookGeom, rpc,
        ring[0].easting, ring[0].northing, bldg.representativeBaseElevation);

    const bool isAffine = (result.projectionMode == ProjectionMode::AFFINE_FALLBACK);
    if (isAffine && (std::abs(roofDisp.dx) > 1.0e-3 || std::abs(roofDisp.dy) > 1.0e-3)) {
        for (std::size_t i = 0; i < numVerts; ++i) {
            auto& pv = projectedRoof[i];
            pv.pixelCol += roofDisp.dx;
            pv.pixelRow += roofDisp.dy;
            pv.u = static_cast<float>(std::clamp(pv.pixelCol / std::max(1, metadata.width), 0.0, 1.0));
            pv.v = static_cast<float>(std::clamp(pv.pixelRow / std::max(1, metadata.height), 0.0, 1.0));
            roofprintPixels[i] = {pv.pixelCol, pv.pixelRow};

            if (!checkStrictBounds(pv.pixelCol, pv.pixelRow, metadata.width, metadata.height, config.guardBandPixels)) {
                pv.isValid = false;
                pv.provenance = MaterialProvenance::REJECTED_OUT_OF_BOUNDS;
                allRoofValid = false;
                failureProvenance = MaterialProvenance::REJECTED_OUT_OF_BOUNDS;
                rejectionReason = "Roof displacement pushed roof vertices out of image bounds.";
            }
        }
    }

    if (!allRoofValid && config.strictBounding) {
        result.isTexturedSuccessfully = false;
        result.roofProvenance = (failureProvenance != MaterialProvenance::UNKNOWN)
            ? failureProvenance
            : MaterialProvenance::REJECTED_OUT_OF_BOUNDS;
        result.diagnosticNotes = "Roof rejected by strict bounding: " + rejectionReason;

        if (result.roofProvenance == MaterialProvenance::REJECTED_OUT_OF_BOUNDS) {
            diagnostics.rejectedOutOfBounds++;
        } else {
            diagnostics.rejectedUncertain++;
        }

        result.roofVertices = projectedRoof;
        result.roofUVs.resize(numVerts * 2, 0.0f);
        result.roofColors.resize(numVerts * 4);
        for (std::size_t i = 0; i < numVerts; ++i) {
            result.roofColors[i * 4 + 0] = config.neutralRoofColor[0];
            result.roofColors[i * 4 + 1] = config.neutralRoofColor[1];
            result.roofColors[i * 4 + 2] = config.neutralRoofColor[2];
            result.roofColors[i * 4 + 3] = config.neutralRoofColor[3];
        }

        result.facadeStrips = recoverFacades(
            bldg, allBuildings, metadata, rpc, lookGeom, config, diagnostics);
        return result;
    }

    const bool bleedSafe = verifyAntiBleeding(
        roofprintPixels, bldg.buildingId, allBuildings, metadata, lookGeom, rpc, config);

    if (!bleedSafe && config.strictAntiBleeding) {
        result.isTexturedSuccessfully = false;
        result.roofProvenance = MaterialProvenance::REJECTED_BLEED_RISK;
        result.diagnosticNotes = "Roof rejected by anti-bleeding verification: encroachment on adjacent structure.";
        diagnostics.rejectedBleedRisk++;

        result.roofVertices = projectedRoof;
        result.roofUVs.resize(numVerts * 2, 0.0f);
        result.roofColors.resize(numVerts * 4);
        for (std::size_t i = 0; i < numVerts; ++i) {
            result.roofColors[i * 4 + 0] = config.neutralRoofColor[0];
            result.roofColors[i * 4 + 1] = config.neutralRoofColor[1];
            result.roofColors[i * 4 + 2] = config.neutralRoofColor[2];
            result.roofColors[i * 4 + 3] = config.neutralRoofColor[3];
        }

        result.facadeStrips = recoverFacades(
            bldg, allBuildings, metadata, rpc, lookGeom, config, diagnostics);
        return result;
    }

    std::vector<ProjectedVertex> finalRoof = applyAntiBleedInset(
        projectedRoof, config.antiBleedMarginPixels, metadata.width, metadata.height);

    result.roofVertices = finalRoof;
    result.isTexturedSuccessfully = true;

    if (result.projectionMode == ProjectionMode::RPC_PROJECTIVE) {
        result.roofProvenance = MaterialProvenance::SOURCE_PROJECTIVE_RPC;
        diagnostics.rpcProjectedRoofs++;
    } else {
        result.roofProvenance = MaterialProvenance::SOURCE_PROJECTIVE_AFFINE;
        diagnostics.affineFallbackRoofs++;
    }

    result.roofUVs.reserve(numVerts * 2);
    for (const auto& v : finalRoof) {
        result.roofUVs.push_back(v.u);
        result.roofUVs.push_back(v.v);
    }

    result.roofColors.resize(numVerts * 4, 1.0f);

    result.facadeStrips = recoverFacades(
        bldg, allBuildings, metadata, rpc, lookGeom, config, diagnostics);

    for (const auto& strip : result.facadeStrips) {
        result.wallProvenancePerStrip.push_back(strip.provenance);

        for (const auto& c : strip.corners) {
            result.wallUVs.push_back(c.u);
            result.wallUVs.push_back(c.v);

            if (strip.provenance == MaterialProvenance::FACADE_RECTIFIED_VISIBLE) {
                result.wallColors.push_back(1.0f);
                result.wallColors.push_back(1.0f);
                result.wallColors.push_back(1.0f);
                result.wallColors.push_back(1.0f);
            } else {
                result.wallColors.push_back(strip.proceduralColor[0]);
                result.wallColors.push_back(strip.proceduralColor[1]);
                result.wallColors.push_back(strip.proceduralColor[2]);
                result.wallColors.push_back(strip.proceduralColor[3]);
            }
        }
    }

    return result;
}

std::vector<TexturedBuilding> ProjectiveTexturingEngine::processBuildingCollection(
    const BuildingCollection& buildings,
    const SpatialMetadata& metadata,
    const std::optional<RpcCameraModel>& rpc,
    const std::optional<SensorLookGeometry>& lookGeom,
    const ProjectiveTexturingConfig& config,
    TexturingDiagnostics& diagnostics) const {

    std::vector<TexturedBuilding> results;
    results.reserve(buildings.buildings.size());

    diagnostics.totalBuildingsProcessed = buildings.buildings.size();

    for (const auto& bldg : buildings.buildings) {
        results.push_back(processBuilding(
            bldg, buildings.buildings, metadata, rpc, lookGeom, config, diagnostics));
    }

    return results;
}

void ProjectiveTexturingEngine::applyToBuildingMesh(
    BuildingMesh& mesh,
    const std::vector<TexturedBuilding>& texturedBuildings,
    const LocalSceneFrame& frame,
    const ProjectiveTexturingConfig& config) const {

    (void)frame;
    (void)config;

    std::vector<float> allRoofUVs;
    std::vector<float> allWallUVs;
    std::vector<float> allRoofColors;
    std::vector<float> allWallColors;

    for (const auto& tb : texturedBuildings) {
        allRoofUVs.insert(allRoofUVs.end(), tb.roofUVs.begin(), tb.roofUVs.end());
        allWallUVs.insert(allWallUVs.end(), tb.wallUVs.begin(), tb.wallUVs.end());
        allRoofColors.insert(allRoofColors.end(), tb.roofColors.begin(), tb.roofColors.end());
        allWallColors.insert(allWallColors.end(), tb.wallColors.begin(), tb.wallColors.end());
    }

    if (!allRoofUVs.empty() && allRoofUVs.size() == (mesh.roofPrimitive.positions.size() / 3) * 2) {
        mesh.roofPrimitive.uvs = std::move(allRoofUVs);
    }

    if (!allWallUVs.empty() && allWallUVs.size() == (mesh.wallPrimitive.positions.size() / 3) * 2) {
        mesh.wallPrimitive.uvs = std::move(allWallUVs);
    }

    if (!allRoofColors.empty() && allRoofColors.size() == (mesh.roofPrimitive.positions.size() / 3) * 4) {
        mesh.roofPrimitive.colors = std::move(allRoofColors);
    }

    if (!allWallColors.empty() && allWallColors.size() == (mesh.wallPrimitive.positions.size() / 3) * 4) {
        mesh.wallPrimitive.colors = std::move(allWallColors);
    }
}
