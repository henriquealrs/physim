#include <cmath>
#include <gtest/gtest.h>

#include "math/sphere.hpp"

//using Vec3 = simphys::math::Vec3;
//using Point = Vec3;
//using Line = simphys::math::Line;
//using simphys::math::UnitVec3;
//using Sphere = simphys::math::Sphere;
//using Ray = simphys::math::Ray;
//using Geometry = simphys::math::Geometry;

//TEST(GeometryTests, RayHit)
//{
//    Sphere sphere(Point(10, 0, 0), std::sqrt(5));

//    const auto ray_45_dg = Ray(Vec3(1, 1, 0), Point(0, 0, 0));
//    const auto ray_30_dg = Ray(Vec3(std::cos(M_PI/6), std::sin(M_PI/6), 0), Point(0, 0, 0));
//    const auto ray_60_dg = Ray(Vec3(std::cos(M_PI/3), std::sin(M_PI/3), 0), Point(0, 0, 0));

//    const Geometry& g = sphere;

//    EXPECT_TRUE(g.RayHit(ray_30_dg));
//    EXPECT_TRUE(g.RayHit(ray_45_dg));
//    EXPECT_FALSE(g.RayHit(ray_60_dg));
//}
