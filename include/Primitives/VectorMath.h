#pragma once
#include <cstdint>
#include <blitz/tinyvec2.h>

#include "Geometry/Point.h"

typedef int label;

typedef uint32_t dim;

namespace
{

/**
 * @brief Kronecker delta
 * 
 */
bool delta(int i, int j)
{
    return i == j;
}

int LeviCivita(unsigned int i, unsigned int j, unsigned int k)
{
    assert(i < 3 && j < 3 && k < 3);
    if(i==j || j==k || k==i) return 0;
    else if(j%(i+1) == 0 && k%(j+1) == 0 && i%(k+1) == 0)
    {
        // cyclic order
        return 1;
    }
    else return -1; // anticyclic order
}

Point<3> uHat(int dir)
{
    Point<3> unitVec;
    unitVec[dir] = 1;
    return unitVec;
}

} // namespace

namespace VectorMath
{

template<size_t nDim>
double dot(const Point<nDim>& U, const Point<nDim>& V)
{
    double sum = 0.;
    for(size_t i = 0; i != nDim; i++)
    {
        sum += U[i] * V[i];
    }
    return sum;
}

Point<3> cross(const Point<3>& U, const Point<3>& V)
{
    Point<3> out;
    for(size_t i = 0; i != 3; i++)
    {
        for(size_t j = 0; j != 3; j++)
        {
            for(size_t k = 0; k != 3; k++)
            {
                out += LeviCivita(i, j, k)*U[i]*V[j]*uHat(k);
            }
        }
    }

    return out;
}

} // namespace VectorMath
