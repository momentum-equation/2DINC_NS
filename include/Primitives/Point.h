#pragma once

struct Point
{
    Point();
    Point(double _x, double _y, double _z);
    Point(const Point& pt);
    Point(Point&& pt);

    double magnitude() const;
    Point unitVector() const;

    static double dot(const Point& U, const Point& V);

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
};