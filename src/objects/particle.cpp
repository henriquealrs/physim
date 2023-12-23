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


    accumulated_forces_ = Vec3(0, 0, 0);
}


}

math::Vec3 sim::Particle::GetPos() const noexcept
{
    return position_;
}

math::Vec3 sim::Particle::GetVelocity() const noexcept
{
    return velocity_;
}

void sim::Particle::ApplyForce(math::Vec3 force) noexcept
{
    accumulated_forces_ += force;
}

}
