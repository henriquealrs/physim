#ifndef PHYSIM_INC_MATH_SPHERE_HPP
#define PHYSIM_INC_MATH_SPHERE_HPP

#include "geometry.hpp"

namespace simphys {
namespace math {

class Sphere : public Geometry
{
    double radius_;
public:
    Sphere(const Point& centre, double radius) : Geometry(centre), radius_(radius)
    {}

    bool Colision(const Geometry &other) const noexcept override;
    bool RayHit(const Ray &ray) const noexcept override;

    double Radius() const noexcept { return radius_; }
};


}
}


#endif  // PHYSIM_INC_MATH_SPHERE_HPP
