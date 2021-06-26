#include <gtest/gtest.h>
#include "MeshGenerator/MeshGenerator.h"

using Geometry::MeshGenerator;

TEST(TestMeshGenerator, NoFile)
{
    MeshGenerator meshGenerator;
    ASSERT_TRUE(meshGenerator.header() == "");
}

TEST(gmsh, addPoint)
{
    
}

