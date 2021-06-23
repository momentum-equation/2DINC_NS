#pragma once
#include <vector>
#include "Elementary.h"

class IEntity
{
public:
    virtual std::vector<label> collection() const = 0;
    virtual void set(const std::vector<label>& tags) = 0;

    virtual dim dimension() const = 0;
    virtual label tag() const = 0;

    virtual void translate(Vec3d )

};