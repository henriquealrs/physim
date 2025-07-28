#include <gtest/gtest.h>
#include "math/sphere.hpp"

using simphys::math::Sphere;
using simphys::math::Point;
using simphys::math::Geometry;

TEST(SphereCollisionTests, OverlappingSpheres)
{
    Sphere s1(Point(0, 0, 0), 1.0);
    Sphere s2(Point(1.0, 0, 0), 1.0);

    EXPECT_TRUE(s1.Colision(s2));
    EXPECT_TRUE(s2.Colision(s1));
}

TEST(SphereCollisionTests, TouchingSpheres)
{
    Sphere s1(Point(0, 0, 0), 1.0);
    Sphere s2(Point(2.0, 0, 0), 1.0);

    EXPECT_TRUE(s1.Colision(s2));
    EXPECT_TRUE(s2.Colision(s1));
}

TEST(SphereCollisionTests, SeparateSpheres)
{
    Sphere s1(Point(0, 0, 0), 1.0);
    Sphere s2(Point(3.0, 0, 0), 1.0);

    EXPECT_FALSE(s1.Colision(s2));
    EXPECT_FALSE(s2.Colision(s1));
}
