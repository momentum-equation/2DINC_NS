#include <gtest/gtest.h>
#include "MeshGenerator/MeshGenerator.h"

using Geometry::MeshGenerator;

TEST(TestMeshGenerator, NoFile)
{
    MeshGenerator meshGenerator;
    EXPECT_STREQ(meshGenerator.header().c_str(), "");
}

TEST(gmsh, addPoint)
{
    
}

