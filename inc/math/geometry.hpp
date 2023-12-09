#include "vec3.hpp"

namespace simphys {
namespace math {

class Geometry
{
	Point position_; //  Idealy, the center of mass
public:
	Geometry(const Point& position) : position_(position) {}

	virtual bool Hit(const Geometry& other) const noexcept = 0;

	virtual ~Geometry() = default;
};


}
}
