#include <cstdlib>
#include <cmath>
#include <functional>
#include <iostream>

namespace simphys
{
namespace math
{

class Vec3 
{
	double values[3];
	double mag_ {0};
	double mag_sqr_{0};
	static constexpr double MAX_ERR = 0.01;

public:
	Vec3() noexcept : Vec3 (0, 0, 0) {}

	Vec3(double x, double y, double z) noexcept : values{x, y, z}, mag_sqr_(x*x + y*y + z*z) { 
		mag_ = sqrtf64(mag_sqr_);
	}
	Vec3(const Vec3& v) = default;

	double x() const noexcept { return values[0]; }
	double y() const noexcept { return values[1]; }
	double z() const noexcept { return values[2]; }
	double mag() const noexcept { return mag_; }
	double mag_sqr() const noexcept { return mag_sqr_; }

	virtual ~Vec3() = default;

	Vec3 transform(std::function<double(double)> f) const noexcept {
		return Vec3{f(values[0]), f(values[1]), f(values[2])};
	}

	Vec3 operator+(const Vec3& v) const noexcept
	{
		return Vec3(
			x() + v.x(),
			y() + v.y(),
			z() + v.z()
		);
	}

	Vec3 operator-(const Vec3& v) const noexcept
	{
		return Vec3(
			x() - v.x(),
			y() - v.y(),
			z() - v.z()
		);
	}

	Vec3 operator*(const double s) const noexcept {
		return Vec3(
			x() * s,
			y() * s,
			z() * s);
	}
	
	double operator*(const Vec3& v) const noexcept {
		return x()*v.x() + y()*v.y() + z()*v.z();
	}

	Vec3 operator^(const Vec3& v) const noexcept {
		return Vec3(y() * v.z() - z() * v.y(),
			    z() * v.x() - x() * v.z(),
			    x() * v.y() - y() * v.x());
	}

	bool is_equal(const Vec3& v) const noexcept {
		return (std::abs(x() - v.x()) < MAX_ERR) && 
		 	(std::abs(y() - v.y()) < MAX_ERR) &&
			(std::abs(z() - v.z()) < MAX_ERR);
	}

	bool is_paralel(const Vec3& v) {
		return (((*this)^v).mag() - (this->mag() * v.mag())) < MAX_ERR;
	}

	bool operator==(const Vec3& v) const noexcept {
		return is_equal(v);
	}

	Vec3& operator*=(const double scalar) {
		values[0] *= scalar;
		values[1] *= scalar;
		values[2] *= scalar;
		return *this;
	}

	Vec3& operator-=(const Vec3& v) {
		values[0] -= v.x();
		values[1] -= v.y();
		values[2] -= v.z();
		return *this;
	}

	Vec3& operator+=(const Vec3& v) {
		values[0] += v.x();
		values[1] += v.y();
		values[2] += v.z();
		return *this;
	}

	friend Vec3 operator*(double scalar, const Vec3& v)
	{
		simphys::math::Vec3 re{v.x() * scalar, v.y()*scalar, v.z()*scalar};
		return re;
	}

	friend std::ostream& operator<<(std::ostream& os, const simphys::math::Vec3& v) {
		os << "(" << v.x() << ", " << v.y() << ", " << v.z() << ")";
		return os;
	} 
};





class UnitVec3 : public Vec3
{
public:
	UnitVec3() = delete;
	UnitVec3(const Vec3& v) : Vec3(v.x()/v.mag(), v.y()/v.mag(), v.z()/v.mag()) {
	}
};


using Point = Vec3;


}
}

