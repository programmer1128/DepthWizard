#pragma once

#include <gdal.h>
#include <gdal_priv.h>

#include <array>
#include <optional>
#include <string>
#include <vector>

// uses Rational Polynomial Coefficients (a standard satellite imagery format) to project 3D geographic coordinates (Longitude, Latitude, Height) exactly into 2D image pixels

class RpcCameraModel {
public:
    RpcCameraModel() = default;

    RpcCameraModel(
        double lineOffset, double sampleOffset,
        double latOffset, double longOffset, double heightOffset,
        double lineScale, double sampleScale,
        double latScale, double longScale, double heightScale,
        const std::array<double, 20>& lineNumCoeff,
        const std::array<double, 20>& lineDenCoeff,
        const std::array<double, 20>& sampleNumCoeff,
        const std::array<double, 20>& sampleDenCoeff);

    static RpcCameraModel fromGdalRpcInfo(const GDALRPCInfoV2& rpcInfo);
    static std::optional<RpcCameraModel> fromGdalDataset(GDALDataset* poDS);
    static std::optional<RpcCameraModel> fromMetadata(char** papszMD);

    static RpcCameraModel createSyntheticModel(
        double centerLon, double centerLat, double baseHeight,
        double gsdMeters, double imageWidth, double imageHeight,
        double azimuthDegrees = 0.0, double offNadirDegrees = 0.0);

    bool isValid() const;

    static std::array<double, 20> computeTerms(double latNorm, double lonNorm, double heightNorm);

    bool projectGeodetic(
        double lonDegrees,
        double latDegrees,
        double heightMeters,
        double& outSampleCol,
        double& outLineRow) const;

    bool projectProjected(
        double easting,
        double northing,
        double heightMeters,
        const std::string& projectionRef,
        double& outSampleCol,
        double& outLineRow) const;

    bool computeHeightDerivative(
        double lonDegrees,
        double latDegrees,
        double heightMeters,
        double& outDcolDh,
        double& outDrowDh,
        double deltaHeightMeters = 1.0) const;

    double getLineOffset() const { return lineOffset_; }
    double getSampleOffset() const { return sampleOffset_; }
    double getLatOffset() const { return latOffset_; }
    double getLongOffset() const { return longOffset_; }
    double getHeightOffset() const { return heightOffset_; }

    double getLineScale() const { return lineScale_; }
    double getSampleScale() const { return sampleScale_; }
    double getLatScale() const { return latScale_; }
    double getLongScale() const { return longScale_; }
    double getHeightScale() const { return heightScale_; }

    const std::array<double, 20>& getLineNumCoeff() const { return lineNumCoeff_; }
    const std::array<double, 20>& getLineDenCoeff() const { return lineDenCoeff_; }
    const std::array<double, 20>& getSampleNumCoeff() const { return sampleNumCoeff_; }
    const std::array<double, 20>& getSampleDenCoeff() const { return sampleDenCoeff_; }

private:
    double lineOffset_{0.0};
    double sampleOffset_{0.0};
    double latOffset_{0.0};
    double longOffset_{0.0};
    double heightOffset_{0.0};

    double lineScale_{0.0};
    double sampleScale_{0.0};
    double latScale_{0.0};
    double longScale_{0.0};
    double heightScale_{0.0};

    std::array<double, 20> lineNumCoeff_{};
    std::array<double, 20> lineDenCoeff_{};
    std::array<double, 20> sampleNumCoeff_{};
    std::array<double, 20> sampleDenCoeff_{};

    bool isInitialized_{false};
};
