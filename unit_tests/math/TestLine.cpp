#include <cmath>
#include <gtest/gtest.h>
#include "math/line.hpp"

using Vec3 = simphys::math::Vec3;
using Line = simphys::math::Line;
using simphys::math::UnitVec3;

TEST(LineTests, LineAndPoint)
{
	const Vec3 p1(0, 0, 0);
	const Vec3 p2(1, 1, 1);
	Line l = Line::FromTwoPoints(p2, p1);

	EXPECT_TRUE(l.IsPointInLine(Vec3(3, 3, 3)));
	EXPECT_EQ(l.DistanceFromPoint(Vec3(4, 4, 4)), 0.0);

	const Line l2 = Line(UnitVec3(Vec3(1, 0, 0)), Vec3(0, 0, 0));
	EXPECT_EQ(l2.DistanceFromPoint(Vec3(3, 2, 5)), std::sqrt(2*2 + 5*5));
}

TEST(LineTest, TwoLines)
{
	const Vec3 p1(1, 1, 1);
	const Vec3 dir1(1, 2, 3);
	const Line l1 (dir1, p1);


	const Vec3 p2(2, 2, 2);
	const Vec3 dir2(1, 2, 3);
	const Line l2(dir2, p2);


	EXPECT_TRUE(l2.IsParallel(l1));
}
