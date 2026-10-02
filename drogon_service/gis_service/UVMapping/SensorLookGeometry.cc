#include "SensorLookGeometry.h"

#include <cmath>
#include <numbers>
#include <algorithm>

SensorLookGeometry::SensorLookGeometry(double azimuthDegrees, double offNadirDegrees)
    : azimuthDegrees_(std::fmod(azimuthDegrees, 360.0)),
      offNadirDegrees_(std::clamp(offNadirDegrees, 0.0, 89.9)) {
    if (azimuthDegrees_ < 0.0) {
        azimuthDegrees_ += 360.0;
    }
    elevationDegrees_ = 90.0 - offNadirDegrees_;
}

SensorLookGeometry SensorLookGeometry::fromAzimuthAndOffNadir(double azimuthDeg, double offNadirDeg) {
    return SensorLookGeometry(azimuthDeg, offNadirDeg);
}

SensorLookGeometry SensorLookGeometry::fromAzimuthAndElevation(double azimuthDeg, double elevationDeg) {
    const double offNadir = 90.0 - std::clamp(elevationDeg, 0.1, 90.0);
    return SensorLookGeometry(azimuthDeg, offNadir);
}

SensorLookGeometry SensorLookGeometry::deriveFromRpcModel(
    const RpcCameraModel& rpc,
    double sampleLon,
    double sampleLat,
    double baseElevMeters,
    const SpatialMetadata& metadata) {

    double dcolDh = 0.0;
    double drowDh = 0.0;

    if (!rpc.computeHeightDerivative(sampleLon, sampleLat, baseElevMeters, dcolDh, drowDh, 5.0)) {
        return SensorLookGeometry(0.0, 0.0);
    }

    return deriveFromImageDisplacement(dcolDh, drowDh, metadata);
}

SensorLookGeometry SensorLookGeometry::deriveFromImageDisplacement(
    double dcolDh,
    double drowDh,
    const SpatialMetadata& metadata) {

    // Transform (dcolDh, drowDh) in image pixels to (dxDh, dyDh) in projected meters via GeoTransform
    const auto& gt = metadata.geoTransform;
    const double dxDh = dcolDh * gt[1] + drowDh * gt[2];
    const double dyDh = dcolDh * gt[4] + drowDh * gt[5];

    const double horizRate = std::hypot(dxDh, dyDh);
    if (horizRate < 1.0e-7) {
        return SensorLookGeometry(0.0, 0.0); // Pure nadir
    }

    // horizRate = tan(offNadir)
    const double offNadirRad = std::atan(horizRate);
    const double offNadirDeg = offNadirRad * 180.0 / std::numbers::pi;

    // Azimuth: angle clockwise from North (+Y)
    double azRad = std::atan2(dxDh, dyDh);
    double azDeg = azRad * 180.0 / std::numbers::pi;
    if (azDeg < 0.0) {
        azDeg += 360.0;
    }

    return SensorLookGeometry(azDeg, offNadirDeg);
}

Displacement2D SensorLookGeometry::computeGroundDisplacement(double metricHeight) const {
    if (metricHeight <= 0.0 || offNadirDegrees_ < 1.0e-4) {
        return {0.0, 0.0};
    }

    const double azRad = azimuthDegrees_ * std::numbers::pi / 180.0;
    const double offNadirRad = offNadirDegrees_ * std::numbers::pi / 180.0;

    const double magnitudeMeters = metricHeight * std::tan(offNadirRad);

    const double dx = magnitudeMeters * std::sin(azRad);
    const double dy = magnitudeMeters * std::cos(azRad);

    return {dx, dy};
}

Displacement2D SensorLookGeometry::computePixelDisplacement(
    double metricHeight,
    const SpatialMetadata& metadata) const {

    const Displacement2D groundDisp = computeGroundDisplacement(metricHeight);

    const auto& gt = metadata.geoTransform;
    const double det = gt[1] * gt[5] - gt[2] * gt[4];
    if (std::abs(det) < 1.0e-12) {
        return {0.0, 0.0};
    }

    const double invDet = 1.0 / det;
    const double dCol = (groundDisp.dx * gt[5] - groundDisp.dy * gt[2]) * invDet;
    const double dRow = (groundDisp.dy * gt[1] - groundDisp.dx * gt[4]) * invDet;

    return {dCol, dRow};
}

bool SensorLookGeometry::isWallFacingSensor(double x1, double y1, double x2, double y2) const {
    if (offNadirDegrees_ < 1.0e-4) {
        return false; // Nadir view sees no vertical facade
    }

    const double edgeX = x2 - x1;
    const double edgeY = y2 - y1;
    const double len = std::hypot(edgeX, edgeY);
    if (len < 1.0e-6) {
        return false;
    }

    // Outward 2D normal for CCW polygon: (edgeY / len, -edgeX / len)
    const double nx = edgeY / len;
    const double ny = -edgeX / len;

    // Vector pointing towards satellite azimuth
    const double azRad = azimuthDegrees_ * std::numbers::pi / 180.0;
    const double satX = std::sin(azRad);
    const double satY = std::cos(azRad);

    const double dot = nx * satX + ny * satY;

    // Positive dot product means the outward normal points towards the satellite
    return dot > 1.0e-4;
}

bool SensorLookGeometry::isWallStripVisibleInPixelSpace(
    const PixelPoint& foot1,
    const PixelPoint& foot2,
    const PixelPoint& roof1,
    const PixelPoint& roof2) const {

    (void)roof2;
    // Edge vector along base
    const double eCol = foot2.column - foot1.column;
    const double eRow = foot2.row - foot1.row;

    // Lean displacement vector from footprint to roofprint
    const double dCol = roof1.column - foot1.column;
    const double dRow = roof1.row - foot1.row;

    // 2D cross product: determines whether the facade strip opens outward
    const double cross = eCol * dRow - eRow * dCol;

    return std::abs(cross) > 0.05;
}

static bool raySegmentIntersection(
    double ox, double oy, double dx, double dy,
    double x1, double y1, double x2, double y2,
    double& outT) {

    const double ex = x2 - x1;
    const double ey = y2 - y1;

    const double denom = dx * ey - dy * ex;
    if (std::abs(denom) < 1.0e-9) {
        return false;
    }

    const double qx = x1 - ox;
    const double qy = y1 - oy;

    const double t = (qx * ey - qy * ex) / denom;
    const double u = (qx * dy - qy * dx) / denom;

    if (t > 0.5 && u >= 0.0 && u <= 1.0) {
        outT = t;
        return true;
    }

    return false;
}

bool SensorLookGeometry::isOccludedByNeighbor(
    double wallMidX,
    double wallMidY,
    double wallBaseElevation,
    double wallRoofElevation,
    uint32_t currentBuildingId,
    const std::vector<BuildingInstance>& allBuildings,
    double searchDistanceMeters) const {

    if (offNadirDegrees_ < 1.0e-3) {
        return false;
    }

    (void)wallBaseElevation;
    const double azRad = azimuthDegrees_ * std::numbers::pi / 180.0;
    const double rayDirX = std::sin(azRad);
    const double rayDirY = std::cos(azRad);

    for (const auto& other : allBuildings) {
        if (other.buildingId == currentBuildingId) {
            continue;
        }

        // Shorter neighbors cannot occlude this wall
        if (other.roofElevation < wallRoofElevation - 0.5f) {
            continue;
        }

        const auto& ring = other.projectedFootprint.outerRing;
        if (ring.size() < 3) {
            continue;
        }

        for (std::size_t i = 0; i < ring.size(); ++i) {
            const auto& p1 = ring[i];
            const auto& p2 = ring[(i + 1) % ring.size()];

            double hitT = 0.0;
            if (raySegmentIntersection(
                    wallMidX, wallMidY, rayDirX, rayDirY,
                    p1.easting, p1.northing, p2.easting, p2.northing, hitT)) {
                if (hitT <= searchDistanceMeters) {
                    return true; // Occluded by neighbor along line of sight
                }
            }
        }
    }

    return false;
}
