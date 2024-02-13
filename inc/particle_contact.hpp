#ifndef PARTICLACONTACT_HPP
#define PARTICLACONTACT_HPP

#include "objects/particle.hpp"
#include <vector>

namespace simphys {
namespace sim {


class ParticleContact
{
public:
    Particle *particles_[2]; // TODO: Modernize - change to fixed array of optionals
    const double restitution_;
    const math::UnitVec3 normal_;
    const double penetration;

    void Resolve(double duration) noexcept;
    double CalculateSeparatingVelocity() const noexcept;

private:
    void ResolveVelocity(double duration) noexcept;
    void ResolveInterpenetration(double duration) noexcept;

public:
    ParticleContact() = delete;
    ParticleContact(const ParticleContact& other) = delete;
    ParticleContact operator=(const ParticleContact& other) = delete;
};

class ParticleContactResolver
{
protected:
    unsigned iterations_allowed_;

public:
    ParticleContactResolver() = delete;
    ParticleContactResolver(const ParticleContactResolver& other) = delete;
    ParticleContactResolver operator=(const ParticleContactResolver& other) = delete;

    ParticleContactResolver(unsigned iterations) noexcept : iterations_allowed_(iterations){}

    void ResolveContacts(const std::vector<ParticleContact*>& contacts, double duration) noexcept;
};

}
}

#endif // PARTICLACONTACT_HPP
