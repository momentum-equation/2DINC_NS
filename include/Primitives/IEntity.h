#pragma once
#include <vector>
#include "Elementary.h"

template<size_t nDim>
class IEntity
{
public:
    virtual label tag() const = 0;

    /**
     * @brief translate the entity
     * 
     * @param translationVector 
     */
    virtual void translate(const blitz::TinyVector<double, nDim>& translationVector) = 0;
    
    /**
     * @brief rotate entity based on angle of rotation
     * 
     * @param angle (in degrees) counterclockwise positive, clockwise negative
     * @param axis 
     */
    virtual void rotate(double angle, blitz::TinyVector<double, nDim> axis) = 0;
    
    /**
     * @brief scale entity 
     * 
     * @param factor factor to scale
     */
    virtual void scale(double factor) = 0;
};
