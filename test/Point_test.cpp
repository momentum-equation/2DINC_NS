#include <gtest/gtest.h>
#include "Primitives/Point.h"

TEST(Point, SimplePoint)
{
    Point pt1;
    EXPECT_EQ(pt1.x, 0);
    EXPECT_EQ(pt1.y, 0);
    EXPECT_EQ(pt1.z, 0);

    Point pt2(3.2, 90.987113,2424.98213);
    EXPECT_EQ(pt2.x, 3.2);
    EXPECT_EQ(pt2.y, 90.987113);
    EXPECT_EQ(pt2.z, 2424.98213);

    Point pt3(0.6, 0.9, 1.3);
    Point pt4(pt3);
    EXPECT_EQ(pt3.x, pt4.x);
    EXPECT_EQ(pt3.y, pt4.y);
    EXPECT_EQ(pt3.z, pt4.z);
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}