#pragma once
#include "Primitives/Elementary.h"
#include <string>
#include <vector>

namespace Geometry
{

class MeshGenerator
{
public:
    MeshGenerator();
    
    ~MeshGenerator();

    std::string header() const;

private:
    std::string _header;
    std::string _name;
    
};

}