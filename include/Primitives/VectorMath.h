#pragma once
#include <cstdint>
#include <blitz/tinyvec2.h>

#include "Geometry/Point.h"
#include "Primitives/Elementary.h"

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

/**
 * @brief Levi-Civita tensor for calculating cross product
 * 
 * @param i 
 * @param j 
 * @param k 
 * @return int 
 */
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

double radian(double degrees)
{
    return (basic::math_constants::pi*degrees)/180.;
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

double cosTheta(const Point<3>& U, const Point<3>& V)
{
    return dot(U, V)/(U.magnitude()*V.magnitude());
}

double angle(const Point<3>& U, const Point<3>& V)
{
    return std::acos(cosTheta(U, V));
}

double sinTheta(const Point<3>& U, const Point<3>& V)
{
    return std::sin(angle(U, V));
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

/**
 * @brief translate given entity through the given 
 * 
 * @tparam Geometrical 
 * @param entity Any geometrical entity comprising of points
 * @param vector Vector to translate
 */
template<typename Geometrical>
void translate(Geometrical& entity, const Point<3>& vector)
{
    std::transform(entity.begin(), entity.end(), entity.begin(), [&vector](Point<3> point){ return point + vector; });
}

template<>
void translate<Point<3>>(Point<3>& entity, const Point<3>& vector)
{
    entity += vector;
}

/**
 * @brief Rotate given entity through "angleInDeg" about "axis"
 * 
 * @tparam Geometrical 
 * @param entity Any geometrical entity comprising of points
 * @param angleInDeg Angle of rotation in degrees (anticlockwise positive)
 * @param axis Axis of rotation
 * @param origin Anchor to rotate about
 */
template<typename Geometrical>
void rotate(Geometrical& entity, double angleInDeg, const Point<3>& axis, const Point<3>& origin = {0, 0, 0})
{
    assert(axis.magnitude() != 0);
    
    translate(entity, -origin);

    std::transform(entity.begin(), entity.end(), entity.begin(), 
    [&axis, angleInDeg](Point<3> point) -> Point<3>{
        auto axisUHat = axis.unitVector(); 
        return std::cos(radian(angleInDeg))*point + std::sin(radian(angleInDeg))*cross(axisUHat, point) + dot(axisUHat, point)*point;
    });

    translate(entity, origin);
}

template<>
void rotate<Point<3>>(Point<3>& entity, double angleInDeg, const Point<3>& axis, const Point<3>& origin)
{
    assert(axis.magnitude() != 0);
    assert(std::abs(dot(axis, origin)) <= 1e-15);

    translate(entity, -origin);

    auto axisUHat = axis.unitVector();
    entity = std::cos(radian(angleInDeg))*entity + std::sin(radian(angleInDeg))*cross(axisUHat, entity) + dot(axisUHat, entity)*entity;

    translate(entity, origin);
}

} // namespace VectorMath
