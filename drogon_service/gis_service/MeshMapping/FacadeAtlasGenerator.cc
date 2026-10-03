#include "FacadeAtlasGenerator.h"

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>

#include <algorithm>
#include <cmath>
#include <stdexcept>

namespace depthwizard
{

namespace
{

// lowbias32 (C. Wellons): a well-mixed, portable 32-bit integer hash.
uint32_t mix(uint32_t value)
{
    value ^= value >> 16;
    value *= 0x7feb352dU;
    value ^= value >> 15;
    value *= 0x846ca68bU;
    value ^= value >> 16;
    return value;
}

struct Palette
{
    cv::Scalar wall;       // BGR
    cv::Scalar slab;       // Floor band
    cv::Scalar glass;
    cv::Scalar frame;
    cv::Scalar groundWall;
    cv::Scalar groundGlass;
    int windowInsetX;      // Pixels from each side of a bay
    int windowTop;         // Pixels below the top of a floor
    int windowBottom;      // Pixels above the bottom of a floor
    bool windows;
};

Palette paletteFor(int variant)
{
    switch (variant)
    {
        case 0: // Light concrete office, punched windows
            return {cv::Scalar(178, 182, 186), cv::Scalar(150, 154, 158), cv::Scalar(92, 80, 70),
                    cv::Scalar(205, 208, 210), cv::Scalar(110, 112, 116), cv::Scalar(70, 62, 56),
                    6, 7, 9, true};
        case 1: // Warm stone, tall narrow windows
            return {cv::Scalar(150, 176, 196), cv::Scalar(128, 152, 172), cv::Scalar(78, 72, 66),
                    cv::Scalar(170, 192, 208), cv::Scalar(98, 116, 132), cv::Scalar(60, 56, 52),
                    9, 5, 7, true};
        case 2: // Glass curtain wall, thin mullions
            return {cv::Scalar(120, 106, 92), cv::Scalar(150, 142, 134), cv::Scalar(140, 118, 96),
                    cv::Scalar(170, 164, 158), cv::Scalar(86, 80, 74), cv::Scalar(96, 84, 72),
                    2, 3, 4, true};
        default: // Neutral concrete: floor lines only
            return {cv::Scalar(170, 170, 170), cv::Scalar(150, 150, 150), cv::Scalar(170, 170, 170),
                    cv::Scalar(170, 170, 170), cv::Scalar(132, 132, 132), cv::Scalar(132, 132, 132),
                    0, 0, 0, false};
    }
}

void drawBand(cv::Mat& atlas, int band, int variant)
{
    const Palette palette = paletteFor(variant);
    const int bandTop = band * FacadeAtlasGenerator::kBandHeight;
    const int bandBottom = bandTop + FacadeAtlasGenerator::kBandHeight;
    atlas(cv::Rect(0, bandTop, FacadeAtlasGenerator::kAtlasWidth, FacadeAtlasGenerator::kBandHeight))
        .setTo(palette.wall);

    constexpr int floorPx = FacadeAtlasGenerator::kFloorPixels;
    constexpr int bayPx = FacadeAtlasGenerator::kBayPixels;
    for (int floor = 0; floor < FacadeAtlasGenerator::kFloorsPerBand; ++floor)
    {
        const int top = bandBottom - (floor + 1) * floorPx;
        const bool ground = floor == 0;
        if (ground)
            atlas(cv::Rect(0, top, FacadeAtlasGenerator::kAtlasWidth, floorPx)).setTo(palette.groundWall);
        else
            atlas(cv::Rect(0, top + floorPx - 3, FacadeAtlasGenerator::kAtlasWidth, 3)).setTo(palette.slab);

        if (!palette.windows && !ground) continue;
        for (int bay = 0; bay < FacadeAtlasGenerator::kBaysPerTile; ++bay)
        {
            const int left = bay * bayPx;
            if (ground)
            {
                // Shopfront glazing on the ground floor of every variant
                // except neutral concrete, which keeps a plain plinth.
                if (!palette.windows) continue;
                atlas(cv::Rect(left + 3, top + 6, bayPx - 6, floorPx - 8)).setTo(palette.groundGlass);
                continue;
            }
            const cv::Rect window(left + palette.windowInsetX, top + palette.windowTop,
                                  bayPx - 2 * palette.windowInsetX,
                                  floorPx - palette.windowTop - palette.windowBottom);
            atlas(window).setTo(palette.glass);
            cv::rectangle(atlas, window, palette.frame, 1);
        }
    }
}

// Deterministic +-3 grey-level grain. Text, logos and recognizable marks
// are never drawn.
void addGrain(cv::Mat& atlas)
{
    for (int row = 0; row < atlas.rows; ++row)
    {
        auto* pixel = atlas.ptr<cv::Vec3b>(row);
        for (int column = 0; column < atlas.cols; ++column)
        {
            const int offset = static_cast<int>(mix(static_cast<uint32_t>(row * atlas.cols + column)) % 7U) - 3;
            for (int channel = 0; channel < 3; ++channel)
                pixel[column][channel] = cv::saturate_cast<uint8_t>(pixel[column][channel] + offset);
        }
    }
}

} // namespace

TextureAsset FacadeAtlasGenerator::generateAtlasPng(bool neutral)
{
    cv::Mat atlas(kAtlasHeight, kAtlasWidth, CV_8UC3);
    for (int band = 0; band < kVariantCount; ++band)
        drawBand(atlas, band, neutral ? kNeutralVariant : band);
    addGrain(atlas);

    TextureAsset output;
    output.mimeType = "image/png";
    output.semantic = TextureSemantic::FACADE_ATLAS;
    output.wrapS = TextureWrap::REPEAT;
    output.wrapT = TextureWrap::CLAMP_TO_EDGE;
    if (!cv::imencode(".png", atlas, output.bytes, {cv::IMWRITE_PNG_COMPRESSION, 9}))
        throw std::runtime_error("FacadeAtlasGenerator: failed to encode PNG atlas");
    return output;
}

int FacadeAtlasGenerator::variantFor(uint32_t buildingId, bool neutral)
{
    if (neutral) return kNeutralVariant;
    return static_cast<int>(mix(buildingId) % static_cast<uint32_t>(kVariantCount));
}

int FacadeAtlasGenerator::presentationFloors(double wallHeightMetres)
{
    if (!std::isfinite(wallHeightMetres)) return 1;
    const long floors = std::lround(wallHeightMetres / kFloorHeightMetres);
    return static_cast<int>(std::clamp<long>(floors, 1, kFloorsPerBand));
}

std::pair<float, float> FacadeAtlasGenerator::segmentU(double startDistanceMetres, double lengthMetres)
{
    const double start = startDistanceMetres / kTileWidthMetres;
    const double phase = start - std::floor(start);
    return {static_cast<float>(phase), static_cast<float>(phase + lengthMetres / kTileWidthMetres)};
}

float FacadeAtlasGenerator::v(int variant, int floors, double wallHeightMetres, double heightAboveGroundMetres)
{
    variant = std::clamp(variant, 0, kVariantCount - 1);
    floors = std::clamp(floors, 1, kFloorsPerBand);
    const double height = std::max(wallHeightMetres, 0.1);
    const double atlasFloors = std::clamp(heightAboveGroundMetres / height * floors,
                                          0.0, static_cast<double>(kFloorsPerBand));
    const double bandTop = static_cast<double>(variant) * kBandHeight;
    const double bandBottom = bandTop + kBandHeight;
    const double row = std::clamp(bandBottom - atlasFloors * kFloorPixels,
                                  bandTop + kBandMarginPixels, bandBottom - kBandMarginPixels);
    return static_cast<float>(row / kAtlasHeight);
}

} // namespace depthwizard
