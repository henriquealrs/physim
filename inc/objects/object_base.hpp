#ifndef __OBJECTS_OBJECT_BASE_HPP
#define __OBJECTS_OBJECT_BASE_HPP

#include "math/geometry.hpp"
#include "math/ray.hpp"
#include "math/sphere.hpp"

namespace simphys {
namespace sim {

class ObjectBase
{
public:
    virtual ~ObjectBase() = default;
    virtual bool ColidesWith(const ObjectBase& other) = 0;
    virtual bool RayHit(const math::Ray& ray) = 0;
    virtual const math::Sphere& BoundingSphere() const noexcept = 0;
};

}
}

#endif  // __OBJECTS_OBJECT_BASE_HPP
