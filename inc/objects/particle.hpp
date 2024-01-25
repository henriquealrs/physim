#ifndef PARTICLE_H
#define PARTICLE_H

#include "math/vec3.hpp"

namespace simphys
{
namespace sim
{


class Particle
{

    math::Vec3 position_;
    math::Vec3 velocity_;
    math::Vec3 acceleration_;
    math::Vec3 accumulated_forces_;

    double damping_;
    double inverse_mass_;

public:

    Particle(const math::Vec3& init_pos, const math::Vec3& init_vel, double mass, double damping) noexcept :
        position_(init_pos), velocity_(init_vel), inverse_mass_(1/mass), damping_(damping)
    {
        std::cout << "New Particle\n";
    }
    Particle() = delete;
    Particle(const Particle& p) = delete;
    Particle(Particle&& p) : position_(std::move(p.position_)),
                             velocity_(std::move(p.velocity_)),
                             inverse_mass_(p.inverse_mass_),
                             damping_(p.damping_)
    {
        std::cout << "Particle moved\n";
    }
    Particle& operator=(Particle&& p)
    {
        std::cout << "Particle move-assigned\n";
        position_ = std::move(p.position_);
        velocity_ = std::move(p.velocity_);
        inverse_mass_ = p.inverse_mass_;
        damping_ = p.damping_;
        return *this;
    }
    Particle& operator=(const Particle& p) = delete;

    void ApplyForce(const math::Vec3& force) noexcept;
    void Integrate(double duration) noexcept;
    [[nodiscard]] math::Vec3 GetPos() const noexcept;
    [[nodiscard]] math::Vec3 GetVelocity() const noexcept;
    [[nodiscard]] bool HasFiniteMass() const noexcept;
    [[nodiscard]] double GetMass() const noexcept;
};


}
}

#endif // PARTICLE_H
