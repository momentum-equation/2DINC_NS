#include <gtest/gtest.h>
#include "Geometry/Point.h"
#include "Primitives/VectorMath.h"
#include <iostream>
#include <vector>

typedef Point<3> Point3d;

int PointCount = 0;

TEST(Point, SimplePoint)
{
    Point3d pt1;
    EXPECT_DOUBLE_EQ(pt1[0], 0);
    EXPECT_DOUBLE_EQ(pt1[1], 0);
    EXPECT_DOUBLE_EQ(pt1[2], 0);
    EXPECT_EQ(pt1.tag(),++PointCount);

    Point3d pt2({3.2, 90.987113,2424.98213});
    EXPECT_DOUBLE_EQ(pt2[0], 3.2);
    EXPECT_DOUBLE_EQ(pt2[1], 90.987113);
    EXPECT_DOUBLE_EQ(pt2[2], 2424.98213);
    EXPECT_EQ(pt2.tag(),++PointCount);

    Point3d pt3({0.6, 0.9, 1.3});
    EXPECT_DOUBLE_EQ(pt3[0], 0.6);
    EXPECT_DOUBLE_EQ(pt3[1], 0.9);
    EXPECT_DOUBLE_EQ(pt3[2], 1.3);
    EXPECT_EQ(pt3.tag(),++PointCount);

    Point3d pt4(pt3);
    EXPECT_EQ(pt4.tag(),++PointCount);
    EXPECT_DOUBLE_EQ(pt3[0], pt4[0]);
    EXPECT_DOUBLE_EQ(pt3[1], pt4[1]);
    EXPECT_DOUBLE_EQ(pt3[2], pt4[2]);

    auto v1 = {1.014,2.718,1.62};
    Point3d pt5(v1);
    EXPECT_EQ(pt5.tag(),++PointCount);
    EXPECT_DOUBLE_EQ(pt5[0], 1.014);
    EXPECT_DOUBLE_EQ(pt5[1], 2.718);
    EXPECT_DOUBLE_EQ(pt5[2], 1.62);

    Point3d pt6({1.1, 2.4, 8.25});
    EXPECT_EQ(pt6.tag(),++PointCount);
    EXPECT_DOUBLE_EQ(pt6[0], 1.1);
    EXPECT_DOUBLE_EQ(pt6[1], 2.4);
    EXPECT_DOUBLE_EQ(pt6[2], 8.25);

}

TEST(Point, Operators)
{
    PointCount = 0;
    Point3d pt0;
    EXPECT_EQ(pt0.tag(),++PointCount);

    Point3d pt1({13.36, 6.43, 9.52});
    EXPECT_DOUBLE_EQ(pt1[0], 13.36);
    EXPECT_DOUBLE_EQ(pt1[1], 6.43);
    EXPECT_DOUBLE_EQ(pt1[2], 9.52);
    EXPECT_EQ(pt1.tag(),++PointCount);

    Point3d pt2 = pt1;
    EXPECT_DOUBLE_EQ(pt2[0], 13.36);
    EXPECT_DOUBLE_EQ(pt2[1], 6.43);
    EXPECT_DOUBLE_EQ(pt2[2], 9.52);
    EXPECT_EQ(pt2.tag(), ++PointCount);

    EXPECT_TRUE(pt2 == pt1);
    EXPECT_FALSE(pt2 != pt1);

    Point3d pt3({3,7,1});
    EXPECT_EQ(pt3.tag(), ++PointCount);
    
    EXPECT_TRUE(pt3 != pt2);
    EXPECT_FALSE(pt3 == pt2);

    Point3d pt4 = pt3 + pt1;
    EXPECT_DOUBLE_EQ(pt4[0], 16.36);
    EXPECT_DOUBLE_EQ(pt4[1], 13.43);
    EXPECT_DOUBLE_EQ(pt4[2], 10.52);
    EXPECT_EQ(pt4.tag(), ++PointCount);

    pt2 = pt1 + pt0;
    EXPECT_DOUBLE_EQ(pt2[0], 13.36);
    EXPECT_DOUBLE_EQ(pt2[1], 6.43);
    EXPECT_DOUBLE_EQ(pt2[2], 9.52);
    EXPECT_EQ(pt2.tag(), PointCount);

    pt4 = pt4 + pt0;
    EXPECT_EQ(pt4.tag(), PointCount);

    pt2 += pt1;
    EXPECT_DOUBLE_EQ(pt2[0], 26.72);
    EXPECT_DOUBLE_EQ(pt2[1], 12.86);
    EXPECT_DOUBLE_EQ(pt2[2], 19.04);
    EXPECT_EQ(pt2.tag(),PointCount);

    Point3d pt5 = pt3 - pt1;
    EXPECT_DOUBLE_EQ(pt5[0], -10.36);
    EXPECT_DOUBLE_EQ(pt5[1], 0.57);
    EXPECT_DOUBLE_EQ(pt5[2], -8.52);
    EXPECT_EQ(pt5.tag(), ++PointCount);

    pt1 -= pt3;
    EXPECT_DOUBLE_EQ(pt1[0], 10.36);
    EXPECT_DOUBLE_EQ(pt1[1], -0.57);
    EXPECT_DOUBLE_EQ(pt1[2], 8.52);
    EXPECT_EQ(pt4.tag(),PointCount);

    Point3d pt6 = {1, 0, 0};
    EXPECT_DOUBLE_EQ(pt6[0], 1);
    EXPECT_DOUBLE_EQ(pt6[1], 0);
    EXPECT_DOUBLE_EQ(pt6[2], 0);
    EXPECT_EQ(pt6.tag(), ++PointCount);

    Point3d pt7 = Point3d({0,1,0});
    EXPECT_DOUBLE_EQ(pt7[0], 0);
    EXPECT_DOUBLE_EQ(pt7[1], 1);
    EXPECT_DOUBLE_EQ(pt7[2], 0);
    EXPECT_EQ(pt7.tag(), ++PointCount);

    Point3d pt8({1.1, 2.4, 8.25});
    EXPECT_EQ(pt8.tag(), ++PointCount);

    Point3d pt9 = 7*pt8;
    EXPECT_DOUBLE_EQ(pt9[0], 7.7);
    EXPECT_DOUBLE_EQ(pt9[1], 16.8);
    EXPECT_DOUBLE_EQ(pt9[2], 57.75);
    EXPECT_EQ(pt9.tag(), ++PointCount);

    Point3d pt10 = 4.1*pt8 - pt7;
    EXPECT_DOUBLE_EQ(pt10[0], 4.51);
    EXPECT_DOUBLE_EQ(pt10[1], 8.84);
    EXPECT_DOUBLE_EQ(pt10[2], 33.825);
    EXPECT_EQ(pt10.tag(), ++PointCount);

    Point3d pt11 = {3, 4, 5};
    EXPECT_EQ(pt11.tag(), ++PointCount);

    Point3d pt12 = -pt11;
    EXPECT_DOUBLE_EQ(pt12[0], -3);
    EXPECT_DOUBLE_EQ(pt12[1], -4);
    EXPECT_DOUBLE_EQ(pt12[2], -5);
    EXPECT_EQ(pt12.tag(), ++PointCount);
}

TEST(Point, VectorProducts)
{
    Point3d p;
    EXPECT_DOUBLE_EQ(p.magnitude(), 0);

    Point3d q({1.2104, 4.336, 9.8795});
    EXPECT_DOUBLE_EQ(q.magnitude(), 10.8568174162597);

    Point3d pt;
    Point3d pt0;

    EXPECT_DOUBLE_EQ(VectorMath::dot(pt, pt0), 0.);

    Point3d pt1 = {1., 0., 0.};
    Point3d pt2 = {0., 1., 0.};

    EXPECT_DOUBLE_EQ(VectorMath::dot(pt1, pt2), 0.);

    Point3d pt3 = {3.2, 4.9, 0};
    Point3d pt4({1., 0., 0.});

    EXPECT_DOUBLE_EQ(VectorMath::dot(pt3, pt4), 3.2);
    EXPECT_DOUBLE_EQ(VectorMath::dot(pt3, pt4), VectorMath::dot(pt4, pt3));

    Point3d pt5({1.07, 1.9, 5.54});
    Point3d pt6 = {6.8, 2.3, 4.815};

    EXPECT_DOUBLE_EQ(VectorMath::dot(pt5, pt6), 38.3211);

    EXPECT_DOUBLE_EQ(VectorMath::dot(Point3d({4.5, 3, 10}), Point3d({2, 2.1, 3.2})), 47.3);

    Point3d pt7({1, 0, 0});
    Point3d pt8({0, 1, 0});
    Point3d pt9 = VectorMath::cross(pt7, pt8);
    EXPECT_DOUBLE_EQ(pt9[0], 0);
    EXPECT_DOUBLE_EQ(pt9[1], 0);
    EXPECT_DOUBLE_EQ(pt9[2], 1);

    Point3d pt10({3.11, 9.094, 0.44});
    Point3d pt11({1.462, 8, 4.66});
    Point3d pt12 = VectorMath::cross(pt10, pt11);
    EXPECT_DOUBLE_EQ(pt12[0], 38.85804);
    EXPECT_DOUBLE_EQ(pt12[1], -13.84932);
    EXPECT_DOUBLE_EQ(pt12[2], 11.584572);
}

TEST(Point, Transformations)
{
    Point3d p = {5, 0, 0};

    Point3d pt1 = {3.2, 87.44, 0};
    VectorMath::translate(pt1, p);
    EXPECT_DOUBLE_EQ(pt1[0], 8.2);
    EXPECT_NE(pt1[1], 92.44);
    EXPECT_NE(pt1[2], 5);

    std::vector<Point3d> triangle;
    triangle.push_back(Point3d({0, 0, 0}));
    triangle.push_back(Point3d({5.3, 0, 0}));
    triangle.push_back(Point3d({8, 7.2, 0}));

    VectorMath::translate(triangle, p);

    EXPECT_DOUBLE_EQ(triangle[0][0], 5);
    EXPECT_DOUBLE_EQ(triangle[1][0], 10.3);
    EXPECT_DOUBLE_EQ(triangle[2][0], 13);

    EXPECT_NE(triangle[0][1], 5);
    EXPECT_NE(triangle[0][2], 5);
    EXPECT_NE(triangle[1][1], 5);
    EXPECT_NE(triangle[1][2], 5);
    EXPECT_NE(triangle[2][1], 12.2);
    EXPECT_NE(triangle[2][2], 5);

    std::vector<Point3d> rightTriangle;
    rightTriangle.emplace_back(Point3d({0, 0, 0}));
    rightTriangle.emplace_back(Point3d({3, 0, 0}));
    rightTriangle.emplace_back(Point3d({0, 4, 0}));

    VectorMath::rotate(rightTriangle, 90., Point3d({0, 0, 1}));

    EXPECT_NEAR(rightTriangle[0][0], 0, 1e-15);
    EXPECT_NEAR(rightTriangle[0][1], 0, 1e-15);
    EXPECT_NEAR(rightTriangle[0][2], 0, 1e-15);

    EXPECT_NEAR(rightTriangle[1][0], 0, 1e-15);
    EXPECT_NEAR(rightTriangle[1][1], 3, 1e-15);
    EXPECT_NEAR(rightTriangle[1][2], 0, 1e-15);

    EXPECT_NEAR(rightTriangle[2][0], -4, 1e-15);
    EXPECT_NEAR(rightTriangle[2][1], 0, 1e-15);
    EXPECT_NEAR(rightTriangle[2][2], 0, 1e-15);

    std::vector<Point3d> segment;
    segment.emplace_back(Point3d({0, 0, 0}));
    segment.emplace_back(Point3d({2, 2, 0}));

    VectorMath::rotate(segment, -45, Point3d({0, 0, 1}), Point3d({1, 1, 0}));

    EXPECT_NEAR(segment[0][0], -0.4142135623730949, 1e-15);
    EXPECT_NEAR(segment[0][1], 1, 1e-15);
    EXPECT_NEAR(segment[0][2], 0, 1e-15);

    EXPECT_NEAR(segment[1][0], 2.4142135623730949, 1e-15);
    EXPECT_NEAR(segment[1][1], 1, 1e-15);
    EXPECT_NEAR(segment[1][2], 0, 1e-15);

}
