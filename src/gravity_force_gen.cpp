#include "gravity_force_gen.hpp"
#include  "objects/particle.hpp"

namespace simphys {
namespace sim {


void GravityParticleForceGen::UpdateForce(Particle& particle, double duration)
{
    if(!particle.HasFiniteMass()) return;

    particle.ApplyForce(gravity_ * particle.GetMass());
}

}
}
