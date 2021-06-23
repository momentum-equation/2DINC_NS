#include <gtest/gtest.h>
#include "MeshGenerator/MeshGenerator.h"
#include <gmsh/api/gmsh.h>

namespace Geometry
{

TEST(TestMeshGenerator, NoFile)
{
    MeshGenerator meshGenerator;
    ASSERT_TRUE(meshGenerator.header() == "");
}

TEST(gmsh, addPoint)
{
    
}

}

// int main(int argc, char* argv[])
// {
//     ::testing::InitGoogleTest(&argc, argv);
//     return RUN_ALL_TESTS();
// }