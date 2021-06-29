#include "Primitives/Point.h"
#include <cmath>

Point::Point():
    x(0),
    y(0),
    z(0)
{}

Point::Point(double x_, double y_, double z_):
    x(x_),
    y(y_),
    z(z_)
{}

Point::Point(const Point& other):
    x(other.x),
    y(other.y),
    z(other.z)
{}

Point::Point(Point&& pt)
{
    *this = std::move(pt);
}

double Point::magnitude() const
{
    return std::sqrt(x*x + y*y + z*z);
}

Point Point::unitVector() const
{
    return *this/magnitude();
}

void Point::setTag(const label tag)
{
    _tag = tag;
}

void Point::translate(const Vec3d& translationVector)
{
    *this = *this + Point(translationVector.x, translationVector.y, translationVector.z);
}

void Point::scale(double factor)
{
    *this = *this * factor;
}

void Point::rotate(double angle, Vec3d axis)
{
    x = 
}

label Point::tag() const
{
    return _tag;
}

Point Point::operator= (const Point& pt)
{
    x = pt.x;
    y = pt.y;
    z = pt.z;

    return *this;
}

Point Point::operator= (Point&& pt)
{
    x = std::move(pt.x);
    y = std::move(pt.y);
    z = std::move(pt.z);

    return *this;
}

Point Point::operator+ (const Point& pt)
{
    return Point(x+pt.x, y+pt.y, z+pt.z);
}

Point Point::operator+ (double val) const
{
    return Point(x+val, y+val, z+val);
}

Point Point::operator- (const Point& pt)
{
    return Point(x-pt.x, y-pt.y, z-pt.z);
}

Point Point::operator- (double val) const
{
    return Point(x-val, y-val, z-val);
}

Point Point::operator* (double val) const
{
    return Point(x*val, y*val, z*val);
}

Point Point::operator/ (double val) const
{
    assert(val != 0);
    return Point(x/val, y/val, z/val);
}

bool Point::operator== (const Point& pt) const
{
    return (x == pt.x && y == pt.y) && z == pt.z;
}

bool Point::operator!= (const Point& pt) const
{
    return !(*this == pt);
}