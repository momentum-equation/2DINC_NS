#pragma once
#include <vector>
#include "Elementary.h"

class IEntity
{
public:
    virtual void setTag (const label tag) = 0;

    virtual label tag() const = 0;

    /**
     * @brief translate the entity
     * 
     * @param translationVector 
     */
    virtual void translate(const Vec3d& translationVector) = 0;
    
    /**
     * @brief rotate entity based on angle of rotation
     * 
     * @param angle (in degrees) counterclockwise positive, clockwise negative
     * @param axis 
     */
    virtual void rotate(double angle, Vec3d axis) = 0;
    
    /**
     * @brief scale entity 
     * 
     * @param factor factor to scale
     */
    virtual void scale(double factor) = 0;

};
