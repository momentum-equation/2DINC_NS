#pragma once
#include <utility>
#include <cassert>

#include "Primitives/IEntity.h"

struct Point : public IEntity, public Vec3d
{
    Point();
    Point(double _x, double _y, double _z);
    Point(const Point& pt);

    Point(Point&& pt);

    double magnitude() const;
    Point unitVector() const;

    static double dot(const Vec3d& U, const Vec3d& V);

public:
    void setTag(const label tag) override;
    label tag() const override;

    // geometry transformation
    void translate(const Vec3d& translationVector) override;
    void rotate(double angle, Vec3d axis) override;
    void scale(double factor) override;

public:
    Point operator= (const Point& pt);
    Point operator= (Point&& pt);

    Point operator+ (const Point& pt);
    Point operator+ (double val) const;

    Point operator- (const Point& pt);
    Point operator- (double val) const;

    Point operator* (double val) const;
    Point operator/ (double val) const;

    bool operator== (const Point& pt) const;
    bool operator!= (const Point& pt) const;

public:
    double x;
    double y;
    double z;

private:
    label _tag;
};