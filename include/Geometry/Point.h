#pragma once
#include <utility>
#include <cmath>
#include <initializer_list>
#include <unordered_map>

#include <algorithm>
#include <functional>

#include "Primitives/IEntity.h"
#include "Primitives/Elementary.h"
#include "Primitives/ObjectCount.h"

#include <blitz/tvecglobs.h>

template<size_t nDim>
struct Point :
    public IEntity<nDim>,
    public ObjectCount<Point<nDim>>
{
public:
    Point():
        ObjectCount<Point>()
    {
        std::fill(_vec.begin(), _vec.end(), 0.);
    }

    Point(const Point& pt):
        ObjectCount<Point>()
    {
        std::copy(pt._vec.begin(), pt._vec.end(), _vec.begin());
    }

    Point(const std::initializer_list<double>& argList):
        ObjectCount<Point>()
    {
        std::copy(argList.begin(), argList.end(), _vec.begin());
    }

    Point(std::initializer_list<double>&& argList) noexcept:
        ObjectCount<Point>()
    {
        std::move(argList.begin(), argList.end(), _vec.begin());
    }

public:
    double& operator[] (size_t index)
    {
        return _vec[index];
    }

    double& operator[] (size_t index) const
    {
        return _vec[index];
    }

    Point operator= (const Point& pt)
    {
        std::copy(pt._vec.begin(), pt._vec.end(), _vec.begin());
        return *this;
    }

    Point operator= (Point&& pt) noexcept
    {
        std::move(pt._vec.begin(), pt._vec.end(), _vec.begin());
        return *this;
    }

    Point operator+ (const Point& pt)
    {
        Point out;
        std::transform(_vec.begin(), _vec.end(), pt._vec.begin(), out._vec.begin(), std::plus<double>());
        return out;
    }

    Point& operator+= (const Point& pt)
    {
        std::transform(_vec.begin(), _vec.end(), pt._vec.begin(), _vec.begin(), std::plus<double>());
        return *this;
    }    

    Point operator- (const Point& pt)
    {
        Point out;
        std::transform(_vec.begin(), _vec.end(), pt._vec.begin(), out._vec.begin(), std::minus<double>());
        return out;
    }

    Point& operator-= (const Point& pt)
    {
        std::transform(_vec.begin(), _vec.end(), pt._vec.begin(), _vec.begin(), std::minus<double>());
        return *this;
    }

    bool operator== (const Point& pt) const
    {
        return std::equal(_vec.begin(), _vec.end(), pt._vec.begin());
    }

    bool operator!= (const Point& pt) const
    {
        return !(*this == pt);
    }

public:
    double magnitude() const
    {
        return std::transform(_vec.begin(), _vec.end(), std::plus<double>());
    }

    

public:
    label tag() const override
    {
        return ObjectCount<Point>::count;
    }

    // geometry transformation
    void translate(const blitz::TinyVector<double, nDim>& translationVector) override
    {
    }

    void rotate(double angle, blitz::TinyVector<double, nDim> axis) override
    {
    }

    void scale(double factor) override
    {
    }

    blitz::TinyVector<double, nDim> unitVector() const
    {
        return blitz::TinyVector<double, nDim>();
    }

private:
    blitz::TinyVector<double, nDim> _vec;
    std::unordered_map<label, blitz::TinyVector<double, nDim>> _hashTable; 
};