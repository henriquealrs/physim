#ifndef PPSPRINGFORCEGEN_HPP
#define PPSPRINGFORCEGEN_HPP

#include "i_particle_force_gen.hpp"

namespace simphys {
namespace sim {


class PPSpringForceGen : public IParticleForceGen
{
    Particle& anchor_;
    double k_;
    double rest_length_;

public:
    PPSpringForceGen() = delete;
    PPSpringForceGen(Particle& anchor, double k, double rest_len) :
        anchor_(anchor), k_(k), rest_length_(rest_len)
    {
    }

    // IParticleForceGen interface
public:
    virtual void UpdateForce(Particle &particle, double duration) override;
};


}
}

#endif // PPSPRINGFORCEGEN_HPP
