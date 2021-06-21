#pragma once
#include <string>

// interface currently created for 2d models

enum Shape
{
    Rectangle,
    Circle,
    Ellipse
};

class IShape
{
public:
    virtual void setShape(const Shape& shape) = 0;

    




};