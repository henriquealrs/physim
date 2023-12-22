#include "math/sphere.hpp"


using simphys::math::Sphere;
using simphys::math::Geometry;
using simphys::math::Ray;

bool Sphere::Colision(const Geometry &other) const noexcept
{
    return false;
}

bool Sphere::RayHit(const Ray &ray) const noexcept
{
    const auto distance = ray.DistanceFromPoint(this->position_);
    return distance <= radius_;
}
