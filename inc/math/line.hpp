#include "math/vec3.hpp"

#include <cmath>
#include <math.h>

namespace simphys
{
namespace math
{

class Line
{
	static constexpr double TOLERANCE = 0.0001;
	const UnitVec3 direction_;
	const Vec3 origin_;

public:
	Line(const UnitVec3& dir, const Vec3& ori) : 
		direction_ (dir), 
		origin_ (ori) 
	{}

	static Line FromTwoPoints(const Vec3& p1, const Vec3& p2) { 
		const auto direction = UnitVec3(p2 - p1); 
		return Line(direction, p1);
	}

	bool IsPointInLine(const Vec3& p) const noexcept {
		return DistanceFromPoint(p) < TOLERANCE;
	}

	double DistanceFromPoint(const Vec3& p) const noexcept {
		const double d = ((p - origin_)^direction_).mag();
		return d;
	}

	bool IsParallel(const Line& l2) const noexcept {
		return this->direction_ == l2.direction_;
	}
};

}
}

