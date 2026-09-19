// acts as the AI's brain decoder 
// takes the raw, unbounded mathematical scores (logits) produced by the neural network and 
// converts them into percentages (probabilities) 
// decides the final identity of every pixel

#pragma once

#include "../structures/InferenceStructs.h"
#include "../structures/GeographicStructs.h"

class SemanticPostProcessor 
{
    public:
    
    // main orchestrator function for classification
    // converts raw scores into probabilities
    // determines the winning class and calculates our confidence in that decision
    
    // logits: raw AI scores for all 6 classes (Ground, Building, Road, Veg, Water, Unknown)
    // confidence: AI's overall confidence raster
    // validMask: map telling us which pixels actually have data
 
    // SemanticScene: structured package containing the probability maps and the final class for each pixel
     
    static SemanticScene buildScene(
        const SemanticLogits& logits,
        const RasterGrid<float>& confidence,
        const RasterGrid<uint8_t>& validMask);


    // highly optimized math function
    // looks at the 6 scores for a pixel, turns them into percentages adding up to 100%
    // picks the winner
    
    // if AI is guessing (winner barely beats the runner-up) -> safely marks the pixel as UNKNOWN
    
    static void applySoftmaxAndThresholding(
        const SemanticLogits& rawLogits, 
        SemanticScene& sceneToPopulate, 
        size_t totalPixels);
};