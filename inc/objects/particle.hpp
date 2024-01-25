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
    math::Vec3 gravity_;

    double damping_;
    const double inverse_mass_;

public:

    Particle(const math::Vec3& init_pos, const math::Vec3& init_vel, double mass, double damping, const math::Vec3& gravity) noexcept :
        position_(init_pos), velocity_(init_vel), inverse_mass_(1/mass), damping_(damping), gravity_(gravity)
    {
        std::cout << "New Particle Instance\n";
    }
    Particle() = delete;
    Particle(const Particle& p) : Particle(p.position_, p.velocity_, 1/p.inverse_mass_, p.damping_, p.gravity_) {
        std::cout << "New Particle Instance\n";
    };
//    Particle(Particle&& p) = default;
//    Particle& operator=(Particle&& p) = default;
//    Particle& operator=(const Particle& p) = delete;

    void Integrate(double duration) noexcept;
    math::Vec3 GetPos() const noexcept;
    math::Vec3 GetVelocity() const noexcept;
    void ApplyForce(math::Vec3 force) noexcept;
    bool HasFiniteMass() const noexcept;
    double GetMass() const noexcept;
};


}
}

#endif // PARTICLE_H
