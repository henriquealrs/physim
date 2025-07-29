#include "objects/sphere.hpp"

using simphys::sim::Sphere;
using simphys::sim::ObjectBase;
using simphys::math::Ray;

bool Sphere::ColidesWith(const ObjectBase& other)
{
    const auto* other_sphere = dynamic_cast<const Sphere*>(&other);
    if(other_sphere)
        return geometry_.Colision(other_sphere->geometry_);
    return false;
}

bool Sphere::RayHit(const Ray& ray)
{
    return geometry_.RayHit(ray);
}
