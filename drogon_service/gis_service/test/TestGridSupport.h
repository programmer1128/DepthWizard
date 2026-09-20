#pragma once

#include <gtest/gtest.h>

#include "structures/CommonTypes.h"

#include <chrono>
#include <cmath>
#include <format>
#include <functional>
#include <iostream>
#include <string_view>
#include <type_traits>
#include <utility>
#include <vector>

namespace depthwizard::test
{

template<typename T>
RasterGrid<T> makeGrid(int width, int height, std::vector<T> values)
{
    RasterGrid<T> grid;
    grid.width = width;
    grid.height = height;
    grid.data = std::move(values);
    return grid;
}

template<typename T>
RasterGrid<T> makeConstantGrid(int width, int height, const T& value)
{
    return makeGrid<T>(
        width,
        height,
        std::vector<T>(
            static_cast<std::size_t>(width) *
                static_cast<std::size_t>(height),
            value));
}

template<typename Callable>
decltype(auto) timedCall(std::string_view operation, Callable&& callable)
{
    const auto start = std::chrono::steady_clock::now();

    if constexpr (std::is_void_v<std::invoke_result_t<Callable>>)
    {
        std::invoke(std::forward<Callable>(callable));
        const auto elapsed = std::chrono::steady_clock::now() - start;
        std::cout << std::format(
            "[LATENCY] operation={} elapsed_us={:.3f}\n",
            operation,
            std::chrono::duration<double, std::micro>(elapsed).count());
    }
    else
    {
        auto result = std::invoke(std::forward<Callable>(callable));
        const auto elapsed = std::chrono::steady_clock::now() - start;
        std::cout << std::format(
            "[LATENCY] operation={} elapsed_us={:.3f}\n",
            operation,
            std::chrono::duration<double, std::micro>(elapsed).count());
        return result;
    }
}

inline void expectGridNear(
    const RasterGrid<float>& actual,
    int width,
    int height,
    const std::vector<float>& expected,
    float tolerance = 1.0e-6F)
{
    ASSERT_EQ(actual.width, width);
    ASSERT_EQ(actual.height, height);
    ASSERT_EQ(actual.data.size(), expected.size());

    for (std::size_t index = 0; index < expected.size(); ++index)
    {
        if (std::isnan(expected[index]))
        {
            EXPECT_TRUE(std::isnan(actual.data[index]))
                << "Expected NaN at flat index " << index;
        }
        else
        {
            EXPECT_NEAR(actual.data[index], expected[index], tolerance)
                << "Grid mismatch at flat index " << index;
        }
    }
}

template<typename T>
void expectGridEqual(
    const RasterGrid<T>& actual,
    int width,
    int height,
    const std::vector<T>& expected)
{
    ASSERT_EQ(actual.width, width);
    ASSERT_EQ(actual.height, height);
    ASSERT_EQ(actual.data.size(), expected.size());
    EXPECT_EQ(actual.data, expected);
}

} // namespace depthwizard::test
