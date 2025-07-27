#include "math/sphere.hpp"


using simphys::math::Sphere;
using simphys::math::Geometry;
using simphys::math::Ray;

bool Sphere::Colision(const Geometry &other) const noexcept
{
    // try sphere-sphere collision first
    if(const auto* s = dynamic_cast<const Sphere*>(&other)) {
        const auto dist_sqr = (this->position_ - s->position_).mag_sqr();
        const auto radius_sum = this->radius_ + s->radius_;
        return dist_sqr <= radius_sum * radius_sum;
    }

    // Fallback to other's implementation for different shapes
    return other.Colision(*this);
}

bool Sphere::RayHit(const Ray &ray) const noexcept
{
    const auto distance = ray.DistanceFromPoint(this->position_);
    return distance <= radius_;
}
