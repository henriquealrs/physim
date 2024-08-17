#ifndef PARTICLELINK_HPP
#define PARTICLELINK_HPP

#include "particle_contact.hpp"
#include <vector>
#include <memory>

namespace simphys {
namespace sim {

using ParticleContactVector = std::vector<std::unique_ptr<ParticleContact>>;

class ParticleLink
{

protected:
    double CurrentLength() const noexcept;
    Particle *particles_[2];


public:
    ParticleLink() = delete;
    ParticleLink(const ParticleLink& other) = delete;
    ParticleLink& operator=(const ParticleLink& other) = delete;

    ParticleLink(Particle& p1, Particle& p2) noexcept :
        particles_{&p1, &p2}
    {}

    /**
    * Fills the given contact structure with the contact needed
    * to keep the link from violating its constraint. The contact
    * pointer should point to the first available contact in a
    * contact array, where limit is the maximum number of
    * contacts in the array that can be written to. The method
    * returns the number of contacts that have been written. This
    * format is common to contact-generating functions, but this
    * class can only generate a single contact, so the
    * pointer can be a pointer to a single element. The limit
    * parameter is assumed to be at least one (zero isn’t valid),
    * and the return value is either 0, if the cable wasn’t
    * overextended, or one if a contact was needed.
    */
    virtual ParticleContactVector::size_type FillContact(ParticleContactVector& contact) const noexcept = 0;
};

class ParticleCable : public ParticleLink
{
    double max_len_;
    double restitution_;

public:
    ParticleCable() = delete;
    ParticleCable(const ParticleCable& other) = delete;
    ParticleCable& operator=(const ParticleCable& other) = delete;
    ParticleCable(double max_len, double restitution, Particle& p1, Particle& p2);

    // ParticleLink interface
public:
    ParticleContactVector::size_type FillContact(ParticleContactVector &contact) const noexcept;
};

}
}

#endif // PARTICLELINK_HPP
