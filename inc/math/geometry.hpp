#include "vec3.hpp"
#include "ray.hpp"

namespace simphys {
namespace math {

class Geometry
{
public:
	Geometry(const Point& position) : position_(position) {}

	virtual bool Colision(const Geometry& other) const noexcept = 0;
    virtual bool RayHit(const Ray& ray) const noexcept = 0;

	virtual ~Geometry() = default;
protected:
    Point position_; //  Idealy, the center of mass
};


}
}
