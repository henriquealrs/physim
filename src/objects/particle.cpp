#include "objects/particle.hpp"
#include "math/vec3.hpp"

namespace simphys
{
namespace sim
{

using namespace math;

void Particle::Integrate(double duration) noexcept
{
    accumulated_forces_ += (-damping_) * UnitVec3(velocity_); 
    acceleration_ = inverse_mass_ * accumulated_forces_ ;
    position_ += duration * velocity_ +
                0.5 * duration * duration * acceleration_;
    velocity_ += duration * acceleration_;


    accumulated_forces_ = Vec3(0, 0, 0);
}

const math::Vec3& Particle::GetPos() const noexcept
{
    return position_;
}

const math::Vec3& Particle::GetVelocity() const noexcept
{
    return velocity_;
}

void Particle::ApplyForce(const math::Vec3& force) noexcept
{
    accumulated_forces_ += force;
}

bool Particle::HasFiniteMass() const noexcept
{
    return inverse_mass_ > 0;
}
double Particle::GetMass() const noexcept
{
    return ((double)1.0)/inverse_mass_;
}

}
}
