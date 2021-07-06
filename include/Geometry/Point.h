#pragma once
#include <utility>
#include <cmath>
#include <numeric>

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

    Point(Point&& pt) noexcept:
        ObjectCount<Point>()
    {
        std::move(pt._vec.begin(), pt._vec.end(), _vec.begin());
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
    double& operator[] (const size_t index)
    {
        return _vec[index];
    }

    const double& operator[] (const size_t index) const
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

    friend Point operator* (double coeff, const Point<3>& pt)
    {
        Point out;
        std::transform(pt._vec.begin(), pt._vec.end(), out._vec.begin(), [coeff](double value){ return coeff*value; });
        return out;
    }

    friend Point operator/ (const Point<3>& pt, double coeff)
    {
        Point out;
        std::transform(pt._vec.begin(), pt._vec.end(), out._vec.begin(), [coeff](double value){ assert(coeff != 0); return value/coeff; });
        return out;
    }

    bool operator== (const Point& pt) const
    {
        return std::equal(_vec.begin(), _vec.end(), pt._vec.begin());
    }

    bool operator!= (const Point& pt) const
    {
        return !(*this == pt);
    }

    bool operator!= (const std::initializer_list<double> coordinates) const
    {
        return !(*this == coordinates);
    }

    Point operator- () const
    {
        Point p;
        std::transform(_vec.begin(), _vec.end(), p.begin(), [](double val){ return -val; });
        return p;
    }

public:
    using Iterator = typename blitz::TinyVector<double, nDim>::iterator;
    using ConstIterator = typename blitz::TinyVector<double, nDim>::const_iterator;

    Iterator begin()
    {
        return _vec.begin();
    }

    ConstIterator begin() const
    {
        return _vec.begin();
    }

    Iterator end()
    {
        return _vec.end();
    }

    ConstIterator end() const
    {
        return _vec.end();
    }

public:
    double magnitude() const
    {
        auto dot = [](double val) -> double 
        {
            return val*val;
        };

        blitz::TinyVector<double, nDim> out;
        std::transform(_vec.begin(), _vec.end(), out.begin(), dot);
        double magSqr = std::accumulate(out.begin(), out.end(), 0.);

        return std::sqrt(magSqr);
    }

public:
    label tag() const
    {
        return ObjectCount<Point>::Count();
    }

    Point unitVector() const
    {
        return *this/magnitude();
    }

    blitz::TinyVector<double, nDim> data() const
    {
        return _vec;
    }

private:
    blitz::TinyVector<double, nDim> _vec;
    std::unordered_map<label, blitz::TinyVector<double, nDim>> _hashTable; 
};