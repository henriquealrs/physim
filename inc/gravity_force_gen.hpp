#ifndef __GRAVITY_FORCE_GEN_HPP
#define __GRAVITY_FORCE_GEN_HPP

#include "i_particle_force_gen.hpp"
#include "math/vec3.hpp"
#include "objects/particle.hpp"

namespace simphys {
namespace sim {
    

class GravityParticleForceGen : public IParticleForceGen
{
    math::Vec3 gravity_;
public: 

    GravityParticleForceGen() = delete;
    GravityParticleForceGen(const math::Vec3& g) : gravity_(g)
    {}

    void UpdateForce(Particle& particle, double duration) override;
};
}
}

#endif

