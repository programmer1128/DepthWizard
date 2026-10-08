// implements the heavy mathematical classification (Softmax)
// uses raw pointers and OpenMP multi-threading to process millions of pixels instantly

#include "SemanticPostProcessor.h"
#include <cmath>
#include <algorithm>
#include <stdexcept>
#include <omp.h> // for multi-threading across all CPU cores
#include <array>
#include <iostream>

SemanticScene SemanticPostProcessor::buildScene(
    const SemanticLogits& logits,
    const RasterGrid<float>& confidence,
    const RasterGrid<uint8_t>& validMask)
{
    if (logits.classCount != 6)
    {
        throw std::invalid_argument(
            "SemanticPostProcessor: Expected exactly six semantic classes.");
    }

    if (logits.layout != TensorLayout::CHW)
    {
        throw std::invalid_argument(
            "SemanticPostProcessor: Expected CHW semantic-logit layout.");
    }

    if (!logits.otherLogits.isValid())
    {
        throw std::invalid_argument(
            "SemanticPostProcessor: Invalid other-logit grid.");
    }

    const int w = logits.otherLogits.width;
    const int h = logits.otherLogits.height;

    const auto matchesReferenceShape =
        [w, h](const auto& grid)
        {
            return grid.isValid() &&
                grid.width == w &&
                grid.height == h;
        };

    if (!matchesReferenceShape(logits.groundLogits) ||
        !matchesReferenceShape(logits.buildingLogits) ||
        !matchesReferenceShape(logits.lowVegetationLogits) ||
        !matchesReferenceShape(logits.roadLogits) ||
        !matchesReferenceShape(logits.waterLogits) ||
        !matchesReferenceShape(confidence) ||
        !matchesReferenceShape(validMask))
    {
        throw std::invalid_argument(
            "SemanticPostProcessor: Input raster dimensions are inconsistent.");
    }
    SemanticScene scene;
    
    // get the total number of pixels we need to process
    const size_t totalPixels =static_cast<size_t>(w) * static_cast<size_t>(h);

    // prepare the empty probability maps with the exact dimensions
    auto initGrid = [&](RasterGrid<float>& grid) {
        grid.width = w;
        grid.height = h;
        grid.data.resize(totalPixels, 0.0f);
    };

    initGrid(scene.groundProbability);
    initGrid(scene.buildingProbability);
    initGrid(scene.roadProbability);
    initGrid(scene.vegetationProbability);
    initGrid(scene.waterProbability);
    initGrid(scene.unknownProbability);
    initGrid(scene.semanticConfidence);

    // initialize the final class map
    scene.finalClassMap.width = w;
    scene.finalClassMap.height = h;
    scene.finalClassMap.data.resize(totalPixels, SemanticClass::UNKNOWN);



    // now execute the heavy Softmax mathematics
    applySoftmaxAndThresholding(logits, scene, totalPixels);



    // combine Semantic Confidence with Model Confidence
    // we only trust the classification if both the Softmax and the original AI model are confident
    float* semConfPtr = scene.semanticConfidence.data.data();
    const float* modConfPtr = confidence.data.data();
    const uint8_t* maskPtr = validMask.data.data();

    // fast multi-threaded loop to combine confidences
    #pragma omp parallel for simd schedule(static)
    for (size_t i = 0; i < totalPixels; ++i) 
    {
        if (maskPtr[i] == 1) 
        {
            // The current worker confidence is the maximum softmax
            // probability calculated from these same logits. Multiplication
            // would square one observation and incorrectly reject otherwise
            // reliable building pixels. Use the conservative minimum instead.
            semConfPtr[i] = std::min(semConfPtr[i], modConfPtr[i]);
        } 
        else 
        {
            // if the pixel is masked out (like cloud), confidence drops to zero
            semConfPtr[i] = 0.0f;
            scene.finalClassMap.data[i] = SemanticClass::UNKNOWN;
        }
    }

    std::array<std::size_t, 6> classCounts{};
    std::size_t invalidCount = 0;
    for (std::size_t i = 0; i < totalPixels; ++i)
    {
        if (maskPtr[i] == 0)
        {
            ++invalidCount;
            continue;
        }

        const std::size_t classIndex =
            static_cast<std::size_t>(scene.finalClassMap.data[i]);
        if (classIndex < classCounts.size())
        {
            ++classCounts[classIndex];
        }
    }

    std::clog << "[SemanticPostProcessor] Class pixels:"
              << " unknown=" << classCounts[static_cast<std::size_t>(SemanticClass::UNKNOWN)]
              << " ground=" << classCounts[static_cast<std::size_t>(SemanticClass::GROUND)]
              << " building=" << classCounts[static_cast<std::size_t>(SemanticClass::BUILDING)]
              << " road=" << classCounts[static_cast<std::size_t>(SemanticClass::ROAD)]
              << " vegetation=" << classCounts[static_cast<std::size_t>(SemanticClass::VEGETATION)]
              << " water=" << classCounts[static_cast<std::size_t>(SemanticClass::WATER)]
              << " invalid=" << invalidCount << '\n';

    return scene;
}

// actual Softmax computation
void SemanticPostProcessor::applySoftmaxAndThresholding(
    const SemanticLogits& raw, 
    SemanticScene& scene, 
    size_t totalPixels)
{
    // extract raw pointers for the inputs (un-normalized scores)
    const float* in_other = raw.otherLogits.data.data();
    const float* in_gnd = raw.groundLogits.data.data();
    const float* in_low_veg = raw.lowVegetationLogits.data.data();
    const float* in_bldg = raw.buildingLogits.data.data();
    const float* in_road = raw.roadLogits.data.data();
    const float* in_wat = raw.waterLogits.data.data();

    // extract raw pointers for our outputs (the probabilities 0.0 to 1.0)
    float* out_unk = scene.unknownProbability.data.data();
    float* out_gnd = scene.groundProbability.data.data();
    float* out_bldg = scene.buildingProbability.data.data();
    float* out_road = scene.roadProbability.data.data();
    float* out_veg = scene.vegetationProbability.data.data();
    float* out_wat = scene.waterProbability.data.data();
    
    // output pointers for final decisions
    SemanticClass* out_class = scene.finalClassMap.data.data();
    float* out_conf = scene.semanticConfidence.data.data();

    // margin threshold:-
    // the winning class must beat the runner-up by at least 15% probability
    // if it doesnt, the AI is confused and we mark the pixel as UNKNOWN to be safe
    const float CONFIDENCE_MARGIN = 0.15f;
    const float MIN_CLASS_PROBABILITY = 0.50f;

    // multi-thread across all pixels
    #pragma omp parallel for schedule(static)
    for (size_t i = 0; i < totalPixels; ++i) 
    {
        // gather the 6 raw scores for this specific pixel
        // Exact deployed ONNX order. The checkpoint retained original GAMUS
        // labels 0..5; it did not remove OTHER or include TREE.
        float scores[6] = {
            in_other[i], in_gnd[i], in_low_veg[i],
            in_bldg[i], in_wat[i], in_road[i]
        };

        // Softmax Step 1: find the highest score (for numerical stability to prevent infinity errors)
        float max_score = scores[0];
        for (int c = 1; c < 6; ++c) 
        {
            if (scores[c] > max_score) 
                max_score = scores[c];
        }

        // Softmax Step 2: calculate exponentials and their total sum
        float sum_exp = 0.0f;
        float exps[6];
        for (int c = 0; c < 6; ++c) 
        {
            exps[c] = std::exp(scores[c] - max_score); // e^(score - max)
            sum_exp += exps[c];
        }

        // Softmax Step 3: divide by sum to get exact percentages
        float probs[6];
        for (int c = 0; c < 6; ++c) 
        {
            probs[c] = exps[c] / sum_exp;
        }

        out_unk[i] = probs[0];
        out_gnd[i] = probs[1];
        out_veg[i] = probs[2];
        out_bldg[i] = probs[3];
        out_wat[i] = probs[4];
        out_road[i] = probs[5];

        const float classProbabilities[6] = {
            out_unk[i],
            out_gnd[i],
            out_bldg[i],
            out_road[i],
            out_veg[i],
            out_wat[i]
        };

        float highest_prob = -1.0f;
        float second_highest_prob = -1.0f;
        int winning_index = static_cast<int>(SemanticClass::UNKNOWN);
        for (int semanticIndex = static_cast<int>(SemanticClass::UNKNOWN);
             semanticIndex <= static_cast<int>(SemanticClass::WATER);
             ++semanticIndex)
        {
            const float probability = classProbabilities[semanticIndex];
            if (probability > highest_prob)
            {
                second_highest_prob = highest_prob;
                highest_prob = probability;
                winning_index = semanticIndex;
            }
            else if (probability > second_highest_prob)
            {
                second_highest_prob = probability;
            }
        }

        
        // Entropy & Margin Thresholding Logic
        // if the winner didnt beat the runner-up by our safety margin -> force it to UNKNOWN
        if (winning_index == static_cast<int>(SemanticClass::UNKNOWN) ||
            highest_prob < MIN_CLASS_PROBABILITY ||
            (highest_prob - second_highest_prob) < CONFIDENCE_MARGIN)
        {
            out_class[i] = SemanticClass::UNKNOWN;
            out_conf[i] = 0.0f; // zero confidence because its a guessing game
        } 
        else 
        {
            // convert the winning index number into our strongly-typed SemanticClass Enum
            out_class[i] = static_cast<SemanticClass>(winning_index);
            out_conf[i] = highest_prob; // store the winning percentage as our confidence
        }
    }
}
