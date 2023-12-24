#include <cmath>
#include <gtest/gtest.h>
#include "math/vec3.hpp"

using Vec3 = simphys::math::Vec3;
using UnitVec = simphys::math::UnitVec3;

TEST(Vec3Tests, Mul)
{
	const Vec3 v1(1, 2, 3);
	const Vec3 v2(2, 4, 6);

	EXPECT_EQ(v1 * 2, v2);
}

TEST(Vec3Tests, CrossProd)
{
	const Vec3 v1(1, -20, 8 );

	EXPECT_NEAR((v1^(v1*7.5)).mag_sqr(), 0, 0.01);
}


TEST(Vec3Tests, DotProd)
{
	const Vec3 v1(2, 2, 2 * std::sqrt(2));
	const Vec3 v2(-2, -2, 2 * std::sqrt(2));

    EXPECT_NEAR(v1.dot(v2), 0, 0.01);
}

TEST(Vec3Tests, SumMulInPlace)
{
	Vec3 v1{1,2,3};
	Vec3 v2 = v1 * 2;

	EXPECT_EQ(v1*=2, v2);

	EXPECT_EQ(v1+=v2, 2*v2);

    Vec3 v3(3, 4, -5);
    EXPECT_EQ(v3*=3, Vec3(9, 12, -15));
    EXPECT_EQ(v3.mag(), (Vec3(3, 4, -5)*3).mag());
}

TEST(Vec3Tests, UnitVectorConstructAndCopy)
{
	Vec3 v1(1, 2, -3);
	UnitVec ut1(v1);
	UnitVec ut2(v1);
	UnitVec ut3(ut1);

	EXPECT_EQ(ut1, ut2);
	EXPECT_EQ(ut1, ut3);
}
