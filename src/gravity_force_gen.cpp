#include "gravity_force_gen.hpp"
#include  "objects/particle.hpp"

namespace simphys {
namespace sim {


GravityParticleForceGen::GravityParticleForceGen(const math::Vec3 &g) : gravity_(g)
{}

void GravityParticleForceGen::UpdateForce(Particle& particle, double duration)
{
    if(!particle.HasFiniteMass()) return;

    particle.ApplyForce(gravity_ * particle.GetMass());
}

}
}
