#ifndef I_PARTICLE_FORCE_GEN_H
#define I_PARTICLE_FORCE_GEN_H

#include <vector>
#include "objects/particle.hpp"

namespace simphys {
namespace sim {

class IParticleForceGen
{
public:
    IParticleForceGen() = default;

    virtual void UpdateForce(Particle& particle, double duration) = 0;
};

class ParticleForceRegistry
{
    std::string id_;
protected:
    struct ParticleForceRegistristration
    {
        Particle *particle;
        IParticleForceGen *fg;
    };
    using Registry = std::vector<ParticleForceRegistristration>;
    Registry registration;


public:
    ParticleForceRegistry() = delete;
    ParticleForceRegistry(const std::string& id) : id_(id) {}
    void Add(Particle& particle, IParticleForceGen& fg);
    void Remove(Particle& particle, IParticleForceGen& fg);
    void Clear();
    void UpdateForces(double duration);
};

}
}
#endif // I_PARTICLE_FORCE_GEN_H
