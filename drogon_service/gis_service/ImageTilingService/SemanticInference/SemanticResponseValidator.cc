#include "SemanticResponseValidator.h"
#include <cmath>
#include <limits>
#include <span>

void SemanticResponseValidator::validateGridShape(
    int expectedWidth, int expectedHeight, size_t expectedSize, 
    int gridWidth, int gridHeight, size_t gridSize, 
    const std::string& gridName)
{
    if (gridWidth != expectedWidth || gridHeight != expectedHeight || gridSize != expectedSize) {
        throw std::runtime_error("SemanticValidator: Shape mismatch in " + gridName + ". " +
                                 "Expected " + std::to_string(expectedWidth) + "x" + std::to_string(expectedHeight) + 
                                 ", got " + std::to_string(gridWidth) + "x" + std::to_string(gridHeight));
    }
}

 void SemanticResponseValidator::validateAndNormalize(
    SemanticTileResult& result,
    std::span<const uint8_t> preprocessingMask)
{
    const int width = result.placement.paddedWidth;
    const int height = result.placement.paddedHeight;

    if (width <= 0 || height <= 0)
    {
        throw std::runtime_error(
            "SemanticValidator: Invalid tile dimensions.");
    }

    const size_t expectedSize =
        static_cast<size_t>(width) *
        static_cast<size_t>(height);

    if (preprocessingMask.size() != expectedSize)
    {
        throw std::runtime_error(
            "SemanticValidator: Preprocessing mask size mismatch.");
    }

    if (result.semanticLogits.classCount != 6 ||
        result.semanticLogits.layout != TensorLayout::CHW)
    {
        throw std::runtime_error(
            "SemanticValidator: Invalid semantic tensor contract.");
    }

    const auto& placement = result.placement;

    if (placement.validStartX < 0 ||
        placement.validStartY < 0 ||
        placement.validWidth <= 0 ||
        placement.validHeight <= 0 ||
        placement.validStartX + placement.validWidth > width ||
        placement.validStartY + placement.validHeight > height)
    {
        throw std::runtime_error(
            "SemanticValidator: Invalid tile valid region.");
    }

    const auto validateGrid =
        [width, height, expectedSize](const auto& grid, const char* name)
        {
            validateGridShape(
                width,
                height,
                expectedSize,
                grid.width,
                grid.height,
                grid.data.size(),
                name);
        };

    validateGrid(result.confidence, "confidence");
    validateGrid(result.validMask, "valid mask");
    validateGrid(result.semanticLogits.otherLogits, "other logits");
    validateGrid(result.semanticLogits.groundLogits, "ground logits");
    validateGrid(result.semanticLogits.lowVegetationLogits, "low vegetation logits");
    validateGrid(result.semanticLogits.buildingLogits, "building logits");
    validateGrid(result.semanticLogits.waterLogits, "water logits");
    validateGrid(result.semanticLogits.roadLogits, "road logits");

    float* confidence = result.confidence.data.data();
    uint8_t* workerMask = result.validMask.data.data();

    float* other =
        result.semanticLogits.otherLogits.data.data();
    float* ground =
        result.semanticLogits.groundLogits.data.data();
    float* lowVegetation =
        result.semanticLogits.lowVegetationLogits.data.data();
    float* building =
        result.semanticLogits.buildingLogits.data.data();
    float* road =
        result.semanticLogits.roadLogits.data.data();
    float* water =
        result.semanticLogits.waterLogits.data.data();

    for (int row = 0; row < height; ++row)
    {
        for (int column = 0; column < width; ++column)
        {
            const size_t index =
                static_cast<size_t>(row) * width + column;

            if (workerMask[index] != 0 &&
                workerMask[index] != 1)
            {
                throw std::runtime_error(
                    "SemanticValidator: Worker mask is not binary.");
            }

            if (preprocessingMask[index] != 0 &&
                preprocessingMask[index] != 1)
            {
                throw std::runtime_error(
                    "SemanticValidator: Preprocessing mask is not binary.");
            }

            const bool insideValidRegion =
                column >= placement.validStartX &&
                column < placement.validStartX + placement.validWidth &&
                row >= placement.validStartY &&
                row < placement.validStartY + placement.validHeight;

            const bool valid =
                insideValidRegion &&
                workerMask[index] == 1 &&
                preprocessingMask[index] == 1;

            workerMask[index] = static_cast<uint8_t>(valid);

            if (!valid)
            {
                confidence[index] = 0.0f;
                other[index] = 0.0f;
                ground[index] = 0.0f;
                lowVegetation[index] = 0.0f;
                building[index] = 0.0f;
                road[index] = 0.0f;
                water[index] = 0.0f;
                continue;
            }

            if (!std::isfinite(confidence[index]) ||
                confidence[index] < 0.0f ||
                confidence[index] > 1.0f)
            {
                throw std::runtime_error(
                    "SemanticValidator: Invalid confidence.");
            }

            if (!std::isfinite(other[index]) ||
                !std::isfinite(ground[index]) ||
                !std::isfinite(lowVegetation[index]) ||
                !std::isfinite(building[index]) ||
                !std::isfinite(road[index]) ||
                !std::isfinite(water[index]))
            {
                throw std::runtime_error(
                    "SemanticValidator: Non-finite semantic logit.");
            }
        }
    }
}
