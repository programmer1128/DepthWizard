// implements the heavy mathematical classification (Softmax)
// uses raw pointers and OpenMP multi-threading to process millions of pixels instantly

#include "SemanticPostProcessor.h"
#include <cmath>
#include <algorithm>
#include <omp.h> // for multi-threading across all CPU cores

SemanticScene SemanticPostProcessor::buildScene(
    const SemanticLogits& logits,
    const RasterGrid<float>& confidence,
    const RasterGrid<uint8_t>& validMask)
{
    SemanticScene scene;
    
    // get the total number of pixels we need to process
    int w = logits.groundLogits.width;
    int h = logits.groundLogits.height;
    size_t totalPixels = static_cast<size_t>(w) * h;

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
            // multiply the two percentages (eg: 90% soft-max * 90% model = 81% total confidence)
            semConfPtr[i] = semConfPtr[i] * modConfPtr[i];
        } 
        else 
        {
            // if the pixel is masked out (like cloud), confidence drops to zero
            semConfPtr[i] = 0.0f;
            scene.finalClassMap.data[i] = SemanticClass::UNKNOWN;
        }
    }

    return scene;
}

// actual Softmax computation
void SemanticPostProcessor::applySoftmaxAndThresholding(
    const SemanticLogits& raw, 
    SemanticScene& scene, 
    size_t totalPixels)
{
    // extract raw pointers for the inputs (un-normalized scores)
    const float* in_unk = raw.unknownLogits.data.data();
    const float* in_gnd = raw.groundLogits.data.data();
    const float* in_bldg = raw.buildingLogits.data.data();
    const float* in_road = raw.roadLogits.data.data();
    const float* in_veg = raw.vegetationLogits.data.data();
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

    // multi-thread across all pixels
    #pragma omp parallel for schedule(static)
    for (size_t i = 0; i < totalPixels; ++i) 
    {
        // gather the 6 raw scores for this specific pixel
        float scores[6] = {
            in_unk[i], in_gnd[i], in_bldg[i], in_road[i], in_veg[i], in_wat[i]
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
        float highest_prob = -1.0f;
        float second_highest_prob = -1.0f;
        int winning_index = 0;

        for (int c = 0; c < 6; ++c) 
        {
            probs[c] = exps[c] / sum_exp;
            
            // track the winner and the runner-up
            if (probs[c] > highest_prob) 
            {
                second_highest_prob = highest_prob;
                highest_prob = probs[c];
                winning_index = c;
            } 
            else if (probs[c] > second_highest_prob) 
            {
                second_highest_prob = probs[c];
            }
        }

        // save the probabilities to the final output maps
        out_unk[i] = probs[0];
        out_gnd[i] = probs[1];
        out_bldg[i] = probs[2];
        out_road[i] = probs[3];
        out_veg[i] = probs[4];
        out_wat[i] = probs[5];

        
        // Entropy & Margin Thresholding Logic
        // if the winner didnt beat the runner-up by our safety margin -> force it to UNKNOWN
        if ((highest_prob - second_highest_prob) < CONFIDENCE_MARGIN) 
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