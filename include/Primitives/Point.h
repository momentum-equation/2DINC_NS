#pragma once
#include <utility>
#include <cmath>
#include <initializer_list>

#include <algorithm>
#include <functional>

#include "Primitives/IEntity.h"
#include "Primitives/Elementary.h"

#include <blitz/tvecglobs.h>

template<size_t nDim>
struct Point : public IEntity<nDim>
{
public:
    Point()
    {
        std::fill(_vec.begin(), _vec.end(), 0.);
        Point::_tag++;        
    }

    Point(const Point& pt)
    {
        std::copy(pt._vec.begin(), pt._vec.end(), _vec.begin());
        Point::_tag++;
    }

    Point(Point&& pt) noexcept
    {
        std::move(pt._vec.begin(), pt._vec.end(), _vec.begin());
        Point::_tag++;
    }

    Point(const std::initializer_list<double>& argList)
    {
        std::copy(argList.begin(), argList.end(), _vec.begin());
        Point::_tag++;
    }

    Point(std::initializer_list<double>&& argList) noexcept
    {
        std::move(argList.begin(), argList.end(), _vec.begin());
        Point::_tag++;
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
        if(pt != *this)
        {
            Point::_tag++;
        }

        return *this;
    }

    Point operator= (Point&& pt) noexcept
    {
        std::move(pt._vec.begin(), pt._vec.end(), _vec.begin());
        if(pt != *this)
        {
            Point::_tag++;
        }

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
        return _tag;
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
    }

private:
    static label _tag;
    blitz::TinyVector<double, nDim> _vec;
};

template<size_t nDim>
label Point<nDim>::_tag = 0;