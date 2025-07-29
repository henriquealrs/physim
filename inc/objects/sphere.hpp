#include "math/sphere.hpp"
#include "object_base.hpp"

namespace simphys {
namespace sim {

class Sphere : public ObjectBase
{
    math::Sphere geometry_;
public:
    Sphere(const math::Point& centre, double radius) : geometry_(centre, radius) {}
    Sphere() = delete;

    bool ColidesWith(const ObjectBase& other) override;
    bool RayHit(const math::Ray& ray) override;
    const math::Sphere& BoundingSphere() const noexcept override { return geometry_; }
};
}
}

