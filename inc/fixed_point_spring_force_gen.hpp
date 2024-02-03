#ifndef FIXEDPOINTSPRINGFORCEGEN_HPP
#define FIXEDPOINTSPRINGFORCEGEN_HPP

#include "i_particle_force_gen.hpp"

namespace simphys {
namespace sim {


class FixedPointSpringForceGen : public IParticleForceGen
{
    math::Vec3 point_;
    double k_;
    double rest_len_;
public:
    FixedPointSpringForceGen() = delete;
    FixedPointSpringForceGen(const math::Vec3& point, double k, double rest_len) :
        point_(point), k_(k), rest_len_(rest_len)
    {}

    // IParticleForceGen interface
public:
    virtual void UpdateForce(Particle &particle, double duration) override;
};


}
}

#endif // FIXEDPOINTSPRINGFORCEGEN_HPP
