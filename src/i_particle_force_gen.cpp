#include "i_particle_force_gen.hpp"

namespace simphys {
namespace sim {

void ParticleForceRegistry::Add(Particle& particle, IParticleForceGen& fg)
{
    registration.push_back({&particle, &fg});
}

void ParticleForceRegistry::Remove(Particle& particle, IParticleForceGen& fg)
{
    for(auto it = registration.begin(); it != registration.end(); ++it)
    {
        if(it->particle == &particle && it->fg == &fg)
        {
            registration.erase(it);
            break;
        }
    }
}

void ParticleForceRegistry::Clear()
{
    registration.clear();
}

void ParticleForceRegistry::UpdateForces(double duration)
{
    for(auto& reg : registration)
    {
        reg.fg->UpdateForce(*reg.particle, duration);
    }
}

}
}
