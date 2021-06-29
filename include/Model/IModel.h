#pragma once
#include "Primitives/IEntity.h"

class IModel
{
public:
    virtual void addEntity(const IEntity& entity) = 0;
    

};
