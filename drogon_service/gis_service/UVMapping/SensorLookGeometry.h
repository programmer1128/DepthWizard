#pragma once

#include "RpcCameraModel.h"
#include "../structures/CommonTypes.h"
#include "../structures/GeographicStructs.h"
#include <optional>
#include <vector>

struct Displacement2D {
    double dx{0.0}; // Offset in X (Easting or Column)
    double dy{0.0}; // Offset in Y (Northing or Row)
};

class SensorLookGeometry {
public:
    SensorLookGeometry() = default;

    SensorLookGeometry(double azimuthDegrees, double offNadirDegrees);

    // Factory methods
    static SensorLookGeometry fromAzimuthAndOffNadir(double azimuthDeg, double offNadirDeg);
    static SensorLookGeometry fromAzimuthAndElevation(double azimuthDeg, double elevationDeg);

    // Derives effective sensor look direction from RPC differential projection: (dCol/dh, dRow/dh)
    static SensorLookGeometry deriveFromRpcModel(
        const RpcCameraModel& rpc,
        double sampleLon,
        double sampleLat,
        double baseElevMeters,
        const SpatialMetadata& metadata);

    // Derives sensor look geometry from image-space height derivatives
    static SensorLookGeometry deriveFromImageDisplacement(
        double dcolDh,
        double drowDh,
        const SpatialMetadata& metadata);

    // Derives roofprint-to-footprint displacement in projected coordinates (Easting, Northing)
    // using fitted metric height and sensor look direction
    Displacement2D computeGroundDisplacement(double metricHeight) const;

    // Derives roofprint-to-footprint displacement in image pixel coordinates (Sample, Line)
    Displacement2D computePixelDisplacement(
        double metricHeight,
        const SpatialMetadata& metadata) const;

    // Tests whether a wall segment from (x1, y1) to (x2, y2) in CCW footprint order
    // faces the sensor (i.e. is front-facing and visible in the off-nadir optical view)
    bool isWallFacingSensor(double x1, double y1, double x2, double y2) const;

    // Tests whether a facade quad formed between footprint and roofprint vertices is visible in pixel space
    bool isWallStripVisibleInPixelSpace(
        const PixelPoint& foot1,
        const PixelPoint& foot2,
        const PixelPoint& roof1,
        const PixelPoint& roof2) const;

    // Tests whether a visible facade is occluded by a taller neighbor building along the sensor line-of-sight
    bool isOccludedByNeighbor(
        double wallMidX,
        double wallMidY,
        double wallBaseElevation,
        double wallRoofElevation,
        uint32_t currentBuildingId,
        const std::vector<BuildingInstance>& allBuildings,
        double searchDistanceMeters = 80.0) const;

    // Accessors
    double getAzimuthDegrees() const { return azimuthDegrees_; }
    double getElevationDegrees() const { return elevationDegrees_; }
    double getOffNadirDegrees() const { return offNadirDegrees_; }
    bool isNadir() const { return offNadirDegrees_ < 1.0e-3; }

private:
    double azimuthDegrees_{0.0};    // Sensor azimuth (0 = North, 90 = East, 180 = South, 270 = West)
    double elevationDegrees_{90.0}; // Elevation above horizon (90 = nadir)
    double offNadirDegrees_{0.0};   // Off-nadir angle (0 = nadir)
};
