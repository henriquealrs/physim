#include "line.hpp"

namespace simphys
{
namespace math
{

class Ray : public Line
{
public:
    Ray() = delete;
    Ray(const UnitVec3& dir, const Point& origin) : Line(dir, origin) {}
};

}  // math
}  // simphys
