#include "RpcCameraModel.h"

#include <gdal.h>
#include <gdal_priv.h>
#include <ogr_spatialref.h>
#include <cpl_string.h>

#include <cmath>
#include <numbers>
#include <algorithm>
#include <numeric>
#include <memory>

RpcCameraModel::RpcCameraModel(
    double lineOffset, double sampleOffset,
    double latOffset, double longOffset, double heightOffset,
    double lineScale, double sampleScale,
    double latScale, double longScale, double heightScale,
    const std::array<double, 20>& lineNumCoeff,
    const std::array<double, 20>& lineDenCoeff,
    const std::array<double, 20>& sampleNumCoeff,
    const std::array<double, 20>& sampleDenCoeff)
    : lineOffset_(lineOffset),
      sampleOffset_(sampleOffset),
      latOffset_(latOffset),
      longOffset_(longOffset),
      heightOffset_(heightOffset),
      lineScale_(lineScale),
      sampleScale_(sampleScale),
      latScale_(latScale),
      longScale_(longScale),
      heightScale_(heightScale),
      lineNumCoeff_(lineNumCoeff),
      lineDenCoeff_(lineDenCoeff),
      sampleNumCoeff_(sampleNumCoeff),
      sampleDenCoeff_(sampleDenCoeff),
      isInitialized_(true) {}

RpcCameraModel RpcCameraModel::fromGdalRpcInfo(const GDALRPCInfoV2& rpcInfo) {
    std::array<double, 20> lineNum{};
    std::array<double, 20> lineDen{};
    std::array<double, 20> sampNum{};
    std::array<double, 20> sampDen{};

    std::copy_n(rpcInfo.adfLINE_NUM_COEFF, 20, lineNum.begin());
    std::copy_n(rpcInfo.adfLINE_DEN_COEFF, 20, lineDen.begin());
    std::copy_n(rpcInfo.adfSAMP_NUM_COEFF, 20, sampNum.begin());
    std::copy_n(rpcInfo.adfSAMP_DEN_COEFF, 20, sampDen.begin());

    return RpcCameraModel(
        rpcInfo.dfLINE_OFF,
        rpcInfo.dfSAMP_OFF,
        rpcInfo.dfLAT_OFF,
        rpcInfo.dfLONG_OFF,
        rpcInfo.dfHEIGHT_OFF,
        rpcInfo.dfLINE_SCALE,
        rpcInfo.dfSAMP_SCALE,
        rpcInfo.dfLAT_SCALE,
        rpcInfo.dfLONG_SCALE,
        rpcInfo.dfHEIGHT_SCALE,
        lineNum,
        lineDen,
        sampNum,
        sampDen);
}

std::optional<RpcCameraModel> RpcCameraModel::fromGdalDataset(GDALDataset* poDS) {
    if (!poDS) {
        return std::nullopt;
    }

    char** papszRPC = poDS->GetMetadata("RPC");
    if (!papszRPC || CSLCount(papszRPC) == 0) {
        return std::nullopt;
    }

    return fromMetadata(papszRPC);
}

std::optional<RpcCameraModel> RpcCameraModel::fromMetadata(char** papszMD) {
    if (!papszMD) {
        return std::nullopt;
    }

    GDALRPCInfoV2 rpcInfo{};
    if (GDALExtractRPCInfoV2(papszMD, &rpcInfo) == FALSE) {
        return std::nullopt;
    }

    RpcCameraModel model = fromGdalRpcInfo(rpcInfo);
    if (!model.isValid()) {
        return std::nullopt;
    }

    return model;
}

RpcCameraModel RpcCameraModel::createSyntheticModel(
    double centerLon, double centerLat, double baseHeight,
    double gsdMeters, double imageWidth, double imageHeight,
    double azimuthDegrees, double offNadirDegrees) {

    const double degPerMeterLat = 1.0 / 111320.0;
    const double degPerMeterLon = 1.0 / (111320.0 * std::cos(centerLat * std::numbers::pi / 180.0));

    const double lineOff = imageHeight * 0.5;
    const double sampOff = imageWidth * 0.5;
    const double lineSc = imageHeight * 0.5;
    const double sampSc = imageWidth * 0.5;

    const double latSc = (imageHeight * 0.5 * gsdMeters) * degPerMeterLat;
    const double lonSc = (imageWidth * 0.5 * gsdMeters) * degPerMeterLon;
    const double heightSc = 1000.0;

    const double azRad = azimuthDegrees * std::numbers::pi / 180.0;
    const double offNadirRad = offNadirDegrees * std::numbers::pi / 180.0;

    const double tanOffNadir = std::tan(offNadirRad);
    const double dispXMetersPerUnit = heightSc * tanOffNadir * std::sin(azRad);
    const double dispYMetersPerUnit = heightSc * tanOffNadir * std::cos(azRad);

    const double sampCoeffH = dispXMetersPerUnit / (sampSc * gsdMeters);
    const double lineCoeffH = -dispYMetersPerUnit / (lineSc * gsdMeters);

    std::array<double, 20> lineNum{};
    std::array<double, 20> lineDen{};
    std::array<double, 20> sampNum{};
    std::array<double, 20> sampDen{};

    // RPC00B: line increases downwards (-latitude)
    lineNum[0] = 0.0;
    lineNum[1] = -1.0;            // Lat term (term 1)
    lineNum[3] = lineCoeffH;      // Height term (term 3)
    lineDen[0] = 1.0;

    // sample increases Eastwards (+longitude)
    sampNum[0] = 0.0;
    sampNum[2] = 1.0;             // Lon term (term 2)
    sampNum[3] = sampCoeffH;      // Height term (term 3)
    sampDen[0] = 1.0;

    return RpcCameraModel(
        lineOff, sampOff,
        centerLat, centerLon, baseHeight,
        lineSc, sampSc,
        latSc, lonSc, heightSc,
        lineNum, lineDen,
        sampNum, sampDen);
}

bool RpcCameraModel::isValid() const {
    if (!isInitialized_) {
        return false;
    }

    if (lineScale_ <= 1.0e-5 || sampleScale_ <= 1.0e-5 ||
        latScale_ <= 1.0e-12 || longScale_ <= 1.0e-12 ||
        heightScale_ <= 1.0e-5) {
        return false;
    }

    if (!std::isfinite(lineOffset_) || !std::isfinite(sampleOffset_) ||
        !std::isfinite(latOffset_) || !std::isfinite(longOffset_) ||
        !std::isfinite(heightOffset_)) {
        return false;
    }

    // Constant denominator term must not be zero
    if (std::abs(lineDenCoeff_[0]) < 1.0e-7 || std::abs(sampleDenCoeff_[0]) < 1.0e-7) {
        return false;
    }

    return true;
}

std::array<double, 20> RpcCameraModel::computeTerms(double latNorm, double lonNorm, double heightNorm) {
    const double L = latNorm;
    const double P = lonNorm;
    const double H = heightNorm;

    std::array<double, 20> t{};
    t[0] = 1.0;
    t[1] = L;
    t[2] = P;
    t[3] = H;
    t[4] = L * P;
    t[5] = L * H;
    t[6] = P * H;
    t[7] = L * L;
    t[8] = P * P;
    t[9] = H * H;
    t[10] = P * L * H;
    t[11] = L * L * L;
    t[12] = L * P * P;
    t[13] = L * H * H;
    t[14] = L * L * P;
    t[15] = P * P * P;
    t[16] = P * H * H;
    t[17] = L * L * H;
    t[18] = P * P * H;
    t[19] = H * H * H;

    return t;
}

bool RpcCameraModel::projectGeodetic(
    double lonDegrees,
    double latDegrees,
    double heightMeters,
    double& outSampleCol,
    double& outLineRow) const {

    if (!isValid()) {
        return false;
    }

    const double latNorm = (latDegrees - latOffset_) / latScale_;
    const double lonNorm = (lonDegrees - longOffset_) / longScale_;
    const double hNorm = (heightMeters - heightOffset_) / heightScale_;

    const auto terms = computeTerms(latNorm, lonNorm, hNorm);

    double lineNum = 0.0;
    double lineDen = 0.0;
    double sampNum = 0.0;
    double sampDen = 0.0;

    for (int i = 0; i < 20; ++i) {
        lineNum += lineNumCoeff_[i] * terms[i];
        lineDen += lineDenCoeff_[i] * terms[i];
        sampNum += sampleNumCoeff_[i] * terms[i];
        sampDen += sampleDenCoeff_[i] * terms[i];
    }

    if (std::abs(lineDen) < 1.0e-7 || std::abs(sampDen) < 1.0e-7) {
        return false;
    }

    const double lineNorm = lineNum / lineDen;
    const double sampNorm = sampNum / sampDen;

    outLineRow = lineNorm * lineScale_ + lineOffset_;
    outSampleCol = sampNorm * sampleScale_ + sampleOffset_;

    return std::isfinite(outLineRow) && std::isfinite(outSampleCol);
}

bool RpcCameraModel::projectProjected(
    double easting,
    double northing,
    double heightMeters,
    const std::string& projectionRef,
    double& outSampleCol,
    double& outLineRow) const {

    if (!isValid()) {
        return false;
    }

    double lon = easting;
    double lat = northing;

    if (!projectionRef.empty()) {
        OGRSpatialReference srcSRS;
        if (srcSRS.SetFromUserInput(projectionRef.c_str()) == OGRERR_NONE) {
            if (!srcSRS.IsGeographic()) {
                OGRSpatialReference dstSRS;
                dstSRS.SetWellKnownGeogCS("WGS84");
                dstSRS.SetAxisMappingStrategy(OAMS_TRADITIONAL_GIS_ORDER);

                std::unique_ptr<OGRCoordinateTransformation> poTransform(
                    OGRCreateCoordinateTransformation(&srcSRS, &dstSRS));
                if (poTransform) {
                    double x = easting;
                    double y = northing;
                    double z = heightMeters;
                    if (poTransform->Transform(1, &x, &y, &z)) {
                        lon = x;
                        lat = y;
                    }
                }
            }
        }
    }

    return projectGeodetic(lon, lat, heightMeters, outSampleCol, outLineRow);
}

bool RpcCameraModel::computeHeightDerivative(
    double lonDegrees,
    double latDegrees,
    double heightMeters,
    double& outDcolDh,
    double& outDrowDh,
    double deltaHeightMeters) const {

    double c1 = 0.0, r1 = 0.0;
    double c2 = 0.0, r2 = 0.0;

    if (!projectGeodetic(lonDegrees, latDegrees, heightMeters, c1, r1)) {
        return false;
    }

    if (!projectGeodetic(lonDegrees, latDegrees, heightMeters + deltaHeightMeters, c2, r2)) {
        return false;
    }

    outDcolDh = (c2 - c1) / deltaHeightMeters;
    outDrowDh = (r2 - r1) / deltaHeightMeters;

    return true;
}
