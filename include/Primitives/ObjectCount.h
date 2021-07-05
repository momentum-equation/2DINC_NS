#pragma once
#include "Primitives/Elementary.h"

/**
 * @brief Maintain count of objects currently in scope.
 * Implemented by using CRTP (Curiuously Recurring Template Pattern)
 * 
 * @tparam ObjectType : Achieve static polymorphism
 */

template<typename ObjectType>
class ObjectCount
{
private:
    static label count;

public:
    ObjectCount()
    {
        ++count;
    }

    ~ObjectCount()
    {
        --count;
    }
    
    static label Count()
    {
        return count;
    }
};

template<typename T>
label ObjectCount<T>::count = 0;