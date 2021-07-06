#pragma once
#include <cstdint>
#include <cmath>

#include <blitz/tinyvec2.h>

typedef int label;
typedef uint32_t dim;

namespace basic::math_constants
{
    constexpr double pi = M_PI;
    constexpr double half_pi = 0.5*M_PI;
    constexpr double two_pi = 2.0*M_PI;
    
    constexpr double e = M_E;
}