#ifndef PARTICLACONTACT_HPP
#define PARTICLACONTACT_HPP

#include "objects/particle.hpp"

namespace simphys {
namespace sim {


class ParticleContact
{
public:
    Particle *particles_[2]; // TODO: Modernize - change to fixed array of optionals
    const double restiturion_;
    const math::UnitVec3 normal_;
    const double penetration;

    void Resolve(double duration) noexcept;

protected:
    double CalculateSeparatingVelocity() const noexcept;

private:
    void ResolveVelocity(double duration) noexcept;
    void ResolveInterpenetration(double duration) noexcept;

public:
    ParticleContact() = delete;
    ParticleContact(const ParticleContact& other) = delete;
    ParticleContact operator=(const ParticleContact& other) = delete;
};

}
}

#endif // PARTICLACONTACT_HPP
