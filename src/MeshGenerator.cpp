#include "MeshGenerator/MeshGenerator.h"
#include <gmsh/api/gmsh.h>

namespace Geometry
{

MeshGenerator::MeshGenerator()
{
    gmsh::initialize();
}

MeshGenerator::~MeshGenerator()
{
    gmsh::finalize();
}

std::string MeshGenerator::header() const
{
    return _header;
}

}
