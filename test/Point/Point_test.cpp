#include <gtest/gtest.h>
#include "Primitives/Point.h"

#include <iostream>

int PointCount = 0;

TEST(Point, SimplePoint)
{
    Point<3> pt1;
    EXPECT_DOUBLE_EQ(pt1[0], 0);
    EXPECT_DOUBLE_EQ(pt1[1], 0);
    EXPECT_DOUBLE_EQ(pt1[2], 0);
    EXPECT_DOUBLE_EQ(pt1.tag(),++PointCount);

    Point<3> pt2({3.2, 90.987113,2424.98213});
    EXPECT_DOUBLE_EQ(pt2[0], 3.2);
    EXPECT_DOUBLE_EQ(pt2[1], 90.987113);
    EXPECT_DOUBLE_EQ(pt2[2], 2424.98213);
    EXPECT_DOUBLE_EQ(pt2.tag(),++PointCount);

    Point<3> pt3({0.6, 0.9, 1.3});
    EXPECT_DOUBLE_EQ(pt3[0], 0.6);
    EXPECT_DOUBLE_EQ(pt3[1], 0.9);
    EXPECT_DOUBLE_EQ(pt3[2], 1.3);
    EXPECT_DOUBLE_EQ(pt3.tag(),++PointCount);

    Point<3> pt4(pt3);
    EXPECT_DOUBLE_EQ(pt4.tag(),++PointCount);
    EXPECT_DOUBLE_EQ(pt3[0], pt4[0]);
    EXPECT_DOUBLE_EQ(pt3[1], pt4[1]);
    EXPECT_DOUBLE_EQ(pt3[2], pt4[2]);

    auto v1 = {1.014,2.718,1.62};
    Point<3> pt5(v1);
    EXPECT_DOUBLE_EQ(pt5.tag(),++PointCount);
    EXPECT_DOUBLE_EQ(pt5[0], 1.014);
    EXPECT_DOUBLE_EQ(pt5[1], 2.718);
    EXPECT_DOUBLE_EQ(pt5[2], 1.62);

    Point<3> pt6({1.1, 2.4, 8.25});
    EXPECT_DOUBLE_EQ(pt6.tag(),++PointCount);
    EXPECT_DOUBLE_EQ(pt6[0], 1.1);
    EXPECT_DOUBLE_EQ(pt6[1], 2.4);
    EXPECT_DOUBLE_EQ(pt6[2], 8.25);
}

TEST(Point, Operators)
{
    Point<3> pt0;
    EXPECT_EQ(pt0.tag(),++PointCount);

    Point<3> pt1({13.36, 6.43, 9.52});
    EXPECT_DOUBLE_EQ(pt1[0], 13.36);
    EXPECT_DOUBLE_EQ(pt1[1], 6.43);
    EXPECT_DOUBLE_EQ(pt1[2], 9.52);
    EXPECT_EQ(pt1.tag(),++PointCount);

    Point<3> pt2 = pt1;
    EXPECT_DOUBLE_EQ(pt2[0], 13.36);
    EXPECT_DOUBLE_EQ(pt2[1], 6.43);
    EXPECT_DOUBLE_EQ(pt2[2], 9.52);

    EXPECT_TRUE(pt2 == pt1);
    EXPECT_FALSE(pt2 != pt1);

    EXPECT_EQ(pt2.tag(), ++PointCount);

    Point<3> pt3({3,7,1});
    EXPECT_EQ(pt3.tag(), ++PointCount);
    EXPECT_TRUE(pt3 != pt2);
    EXPECT_FALSE(pt3 == pt2);

    Point<3> pt4 = pt3 + pt1;
    EXPECT_DOUBLE_EQ(pt4[0], 16.36);
    EXPECT_DOUBLE_EQ(pt4[1], 13.43);
    EXPECT_DOUBLE_EQ(pt4[2], 10.52);

    pt4 = pt4 + pt0;
    EXPECT_EQ(pt4.tag(),++PointCount);

    pt2 += pt1;
    EXPECT_DOUBLE_EQ(pt2[0], 26.72);
    EXPECT_DOUBLE_EQ(pt2[1], 12.86);
    EXPECT_DOUBLE_EQ(pt2[2], 19.04);

    Point<3> pt5 = pt3 - pt1;
    EXPECT_DOUBLE_EQ(pt5[0], -10.36);
    EXPECT_DOUBLE_EQ(pt5[1], 0.57);
    EXPECT_DOUBLE_EQ(pt5[2], -8.52);
    EXPECT_EQ(pt5.tag(), ++PointCount);

    pt1 -= pt3;
    EXPECT_DOUBLE_EQ(pt1[0], 10.36);
    EXPECT_DOUBLE_EQ(pt1[1], -0.57);
    EXPECT_DOUBLE_EQ(pt1[2], 8.52);
}

TEST(Point, Transformations)
{
    
}