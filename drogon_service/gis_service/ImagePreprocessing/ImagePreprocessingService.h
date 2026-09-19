#pragma once
#include "../structures/IngestionStructs.h"

class ImagePreprocessingService
{
public:
    /**
     * @brief Normalizes the input optical RGB imagery for GAMUS Depth2Elevation
     *        and evaluates rule-based photometric quality masks.
     * @param scene Ingested SceneInput metadata containing the remote /vsicurl/ path.
     * @return ImageQualityResult Normalized tensor and boolean masks.
     */
    static ImageQualityResult process(const SceneInput &scene);

private:
    // ImageNet standard statistics used in GAMUS training
    static constexpr float MEAN_R = 0.485f;
    static constexpr float MEAN_G = 0.456f;
    static constexpr float MEAN_B = 0.406f;

    static constexpr float STD_R = 0.229f;
    static constexpr float STD_G = 0.224f;
    static constexpr float STD_B = 0.225f;
};