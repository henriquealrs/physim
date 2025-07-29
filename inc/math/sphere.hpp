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
