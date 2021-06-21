#pragma once
#include "Elementary.h"
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
    
    std::vector<Triangle> _triangles;

    count_t _nTriangles;
};

}