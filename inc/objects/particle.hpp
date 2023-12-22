#ifndef PARTICLE_H
#define PARTICLE_H

#include "math/vec3.hpp"

namespace simphys
{
namespace Sim
{


class Particle
{

    math::Vec3 position_;
    math::Vec3 velocity_;
    math::Vec3 acceleration_;
    math::Vec3 gravity_;
    math::Vec3 accumulated_forces_;

    double damping_;
    double inverse_mass_;

public:

    Particle(const math::Vec3& init_pos, const math::Vec3& init_vel, double mass, double damping) :
        position_(init_pos), velocity_(init_vel), inverse_mass_(1/mass), damping_(damping)
    {}

    void Integrate(double duration) noexcept;
};


}
}

#endif // PARTICLE_H
