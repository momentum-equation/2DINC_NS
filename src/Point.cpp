#include "Primitives/Point.h"
#include <cmath>
#include <cassert>
#include <utility>

Point::Point()
:
    x(0), y(0), z(0)
{}

Point::Point(double _x, double _y, double _z)
:
    x(_x), y(_y), z(_z)
{}

Point::Point(const Point& pt)
:
    Point(pt.x, pt.y, pt.z)
{}

inline Point::Point(Point&& pt)
:
    x(std::move(pt.x)),
    y(std::move(pt.y)),
    z(std::move(pt.z))
{}

inline Point Point::operator= (const Point& pt)
{
    x = pt.x;
    y = pt.y;
    z = pt.z;
}

double Point::magnitude() const
{
    return std::sqrt(x*x + y*y + z*z);
}

Point Point::unitVector() const
{
    assert(magnitude() != 0);

    return (*this)/magnitude();
}

double Point::dot(const Point& U, const Point& V)
{
    return (U.x*V.x + U.y*V.y) + U.z*V.z;
}

inline Point Point::operator= (Point&& pt)
{
    x = std::move(pt.x);
    y = std::move(pt.y);
    z = std::move(pt.z);
}

inline Point Point::operator+ (const Point& pt)
{
    return Point(x+pt.x, y+pt.y, z+pt.z);
}

inline Point Point::operator+ (double val) const
{
    return Point(x+val, y+val, z+val);
}

inline Point Point::operator- (const Point& pt)
{
    return Point(x-pt.x, y-pt.y, z-pt.z);
}

inline Point Point::operator- (double val) const
{
    return Point(x-val, y-val, z-val);
}

inline Point Point::operator* (double val) const
{
    return Point(x*val, y*val, z*val);
}

inline Point Point::operator/ (double val) const
{
    assert(val != 0);
    return Point(x/val, y/val, z/val);
}

inline bool Point::operator== (const Point& pt) const
{
    return (x == pt.x && y == pt.y) && z == pt.z;
}

inline bool Point::operator!= (const Point& pt) const
{
    return !(*this == pt);
}
