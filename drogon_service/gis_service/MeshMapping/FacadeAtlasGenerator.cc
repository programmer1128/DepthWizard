#include "FacadeAtlasGenerator.h"

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>

#include <algorithm>
#include <cmath>
#include <stdexcept>

namespace depthwizard
{

TextureAsset FacadeAtlasGenerator::generateAtlasPng(bool neutralOnly)
{
    cv::Mat atlas(kAtlasHeight, kAtlasWidth, CV_8UC3, cv::Scalar(170, 170, 170));

    const auto drawVariant0 = [](cv::Mat& cell)
    {
        // Variant 0: Modern Commercial / Steel & Glass Grid
        cell.setTo(cv::Scalar(85, 75, 65)); // Dark slate background
        // Ground floor plinth (bottom 40px)
        cv::rectangle(cell, cv::Rect(0, 216, 256, 40), cv::Scalar(50, 45, 40), -1);

        // 6 office floors
        const int floorHeight = 28;
        const int bayWidth = 28;
        for (int floor = 0; floor < 6; ++floor)
        {
            int y = 20 + floor * floorHeight;
            // Floor spandrel band
            cv::line(cell, cv::Point(0, y), cv::Point(256, y), cv::Scalar(140, 130, 120), 2);
            // Window bays
            for (int bay = 0; bay < 8; ++bay)
            {
                int x = 16 + bay * bayWidth;
                cv::rectangle(cell, cv::Rect(x, y + 4, bayWidth - 8, floorHeight - 8),
                             cv::Scalar(65, 50, 40), -1);
                // Window frame/mullion
                cv::rectangle(cell, cv::Rect(x, y + 4, bayWidth - 8, floorHeight - 8),
                             cv::Scalar(115, 105, 95), 1);
            }
        }
    };

    const auto drawVariant1 = [](cv::Mat& cell)
    {
        // Variant 1: Architectural Stone / Limestone
        cell.setTo(cv::Scalar(165, 175, 180)); // Warm limestone
        // Ground foundation
        cv::rectangle(cell, cv::Rect(0, 216, 256, 40), cv::Scalar(130, 135, 140), -1);

        // Horizontal ashlar stone joints every 20px
        for (int y = 16; y < 216; y += 20)
        {
            cv::line(cell, cv::Point(0, y), cv::Point(256, y), cv::Scalar(135, 145, 150), 1);
        }
        // Punched classical window openings
        const int floorHeight = 36;
        const int bayWidth = 32;
        for (int floor = 0; floor < 5; ++floor)
        {
            int y = 20 + floor * floorHeight;
            for (int bay = 0; bay < 7; ++bay)
            {
                int x = 18 + bay * bayWidth;
                // Window sill
                cv::line(cell, cv::Point(x - 2, y + floorHeight - 8),
                         cv::Point(x + bayWidth - 10, y + floorHeight - 8),
                         cv::Scalar(115, 120, 125), 2);
                // Glass pane
                cv::rectangle(cell, cv::Rect(x, y + 4, bayWidth - 12, floorHeight - 12),
                             cv::Scalar(60, 65, 70), -1);
            }
        }
    };

    const auto drawVariant2 = [](cv::Mat& cell)
    {
        // Variant 2: Clean Brick / Terracotta Masonry
        cell.setTo(cv::Scalar(75, 95, 165)); // Warm terracotta brick tone
        // Darker stone foundation
        cv::rectangle(cell, cv::Rect(0, 216, 256, 40), cv::Scalar(60, 70, 110), -1);

        // Horizontal mortar lines every 12px
        for (int y = 12; y < 216; y += 12)
        {
            cv::line(cell, cv::Point(0, y), cv::Point(256, y), cv::Scalar(140, 150, 180), 1);
        }
        // Windows
        const int floorHeight = 32;
        const int bayWidth = 30;
        for (int floor = 0; floor < 6; ++floor)
        {
            int y = 16 + floor * floorHeight;
            for (int bay = 0; bay < 7; ++bay)
            {
                int x = 16 + bay * bayWidth;
                cv::rectangle(cell, cv::Rect(x, y + 4, bayWidth - 10, floorHeight - 10),
                             cv::Scalar(45, 50, 55), -1);
                cv::rectangle(cell, cv::Rect(x, y + 4, bayWidth - 10, floorHeight - 10),
                             cv::Scalar(180, 185, 195), 1);
            }
        }
    };

    const auto drawVariant3 = [](cv::Mat& cell)
    {
        // Variant 3: Neutral Architectural Concrete (Defense / Scientific Mode)
        cell.setTo(cv::Scalar(170, 170, 170)); // Clean neutral grey
        // Ground plinth
        cv::rectangle(cell, cv::Rect(0, 216, 256, 40), cv::Scalar(125, 125, 125), -1);

        // Subtle structural panel seam lines every 48px
        for (int y = 48; y < 216; y += 48)
        {
            cv::line(cell, cv::Point(0, y), cv::Point(256, y), cv::Scalar(145, 145, 145), 1);
        }
        for (int x = 64; x < 256; x += 64)
        {
            cv::line(cell, cv::Point(x, 0), cv::Point(x, 216), cv::Scalar(145, 145, 145), 1);
        }
    };

    // Sub-regions
    cv::Mat cell00 = atlas(cv::Rect(0, 0, kCellWidth, kCellHeight));
    cv::Mat cell01 = atlas(cv::Rect(kCellWidth, 0, kCellWidth, kCellHeight));
    cv::Mat cell10 = atlas(cv::Rect(0, kCellHeight, kCellWidth, kCellHeight));
    cv::Mat cell11 = atlas(cv::Rect(kCellWidth, kCellHeight, kCellWidth, kCellHeight));

    if (neutralOnly)
    {
        drawVariant3(cell00);
        drawVariant3(cell01);
        drawVariant3(cell10);
        drawVariant3(cell11);
    }
    else
    {
        drawVariant0(cell00);
        drawVariant1(cell01);
        drawVariant2(cell10);
        drawVariant3(cell11);
    }

    TextureAsset output;
    output.mimeType = "image/png";
    output.semantic = TextureSemantic::FACADE_ATLAS;

    if (!cv::imencode(".png", atlas, output.bytes, {cv::IMWRITE_PNG_COMPRESSION, 3}))
    {
        throw std::runtime_error("FacadeAtlasGenerator: failed to encode PNG atlas");
    }

    return output;
}

void FacadeAtlasGenerator::computeWallUV(
    uint32_t buildingId,
    float cumulativeEdgeDist,
    float heightFromGround,
    float totalBuildingHeight,
    float& outU,
    float& outV,
    bool neutralOnly)
{
    const uint32_t variant = neutralOnly ? 3 : (hashBuildingId(buildingId) % kVariantCount);
    const int cellCol = static_cast<int>(variant % kGridCols);
    const int cellRow = static_cast<int>(variant / kGridCols);

    const float uMin = cellCol * 0.5f;
    const float vMin = cellRow * 0.5f;

    // Nominal tile width is 10.0m. Continuous cumulative edge distance maps across [0, 1].
    // Seamless continuous edge mapping without per-vertex fmod artifacts.
    const float safeEdgeDist = std::max(cumulativeEdgeDist, 0.0f);
    const float localU = std::clamp(safeEdgeDist / kNominalTileWidthMetres, 0.0f, 1.0f);

    // Presentation floor count derived from total building height per playbook Section 6.4:
    // round(height / 3.1 m), clamped to [1, 30].
    [[maybe_unused]] const int floorCount = computePresentationFloorCount(totalBuildingHeight);

    // Vertical wall fraction relative to total building height from ground.
    // For multi-tier / setback buildings, heightFromGround maps into the building's overall height,
    // ensuring setback walls do not render a ground plinth halfway up the structure.
    const float safeTotalHeight = std::max(totalBuildingHeight, 0.1f);
    const float vFraction = std::clamp(heightFromGround / safeTotalHeight, 0.0f, 1.0f);
    const float localV = 1.0f - vFraction;

    // 1-pixel margin inside cell boundaries to prevent clamp bleeding at borders
    const float margin = 1.0f / static_cast<float>(kAtlasWidth);
    outU = (uMin + margin) + localU * (0.5f - 2.0f * margin);
    outV = (vMin + margin) + localV * (0.5f - 2.0f * margin);
}

} // namespace depthwizard
