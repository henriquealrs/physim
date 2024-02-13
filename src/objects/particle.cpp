#include "objects/particle.hpp"

namespace simphys
{
namespace sim
{

using namespace math;

void Particle::Integrate(double duration) noexcept
{
    acceleration_ = inverse_mass_ * accumulated_forces_;
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

void Particle::SetVelocity(const math::Vec3 &new_vel) noexcept
{
    velocity_ = new_vel;
}

void Particle::IncrementPosition(const math::Vec3 &dp) noexcept
{
    position_ += dp;
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

double Particle::GetInverseMass() const noexcept
{
    return inverse_mass_;
}

const Vec3& Particle::GetAceleration() const noexcept
{
    return acceleration_;
}

}
}
