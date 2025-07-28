#include "math/sphere.hpp"


using simphys::math::Sphere;
using simphys::math::Geometry;
using simphys::math::Ray;

bool Sphere::Colision(const Geometry &other) const noexcept
{
    const auto* other_sphere = dynamic_cast<const Sphere*>(&other);
    if(other_sphere)
    {
        const auto centre_dist = (this->position_ - other_sphere->position_).mag();
        return centre_dist <= (this->radius_ + other_sphere->radius_);
    }

    return false;
}

bool Sphere::RayHit(const Ray &ray) const noexcept
{
    const auto distance = ray.DistanceFromPoint(this->position_);
    return distance <= radius_;
}
