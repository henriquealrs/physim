#include "objects/particle.hpp"

namespace simphys
{
namespace sim
{

using namespace math;

void Particle::Integrate(double duration) noexcept
{
    acceleration_ = inverse_mass_ * accumulated_forces_ + gravity_;
    position_ += duration * velocity_ +
                0.5 * duration * duration * acceleration_;
    velocity_ += duration * acceleration_;
}


}

math::Vec3 sim::Particle::GetPos()
{
    return position_;
}

}
