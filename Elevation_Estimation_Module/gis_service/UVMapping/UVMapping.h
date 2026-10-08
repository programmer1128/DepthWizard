#pragma once

#include <vector>
#include <stdexcept>

class UVMapping
{
    public:

    static std::vector<float> generateUV(int width, int height);

    // generates UV coordinates in row major order as one continuous array
    // width: pixel width, height: pixel height
    // std::vector<float> - formatted as [U0, V0, U1, V1, U2, V2, .....]
    // uses inverted V-axis so that the texture applies correctly without being upside-down
};