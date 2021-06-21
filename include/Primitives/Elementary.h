#pragma once
#include <array>

#ifdef SINGLE_PRECISION
    typedef float real;
#else
    typedef double real;
#endif

struct Point2D
{
    Point2D(real _x, real _y):
        x(_x), y(_y)
    {}

    real x;
    real y;
};


