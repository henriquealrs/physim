#include "particle_link.hpp"
#include "particle_contact.hpp"
#include <memory>

using namespace simphys::sim;



ParticleCable::ParticleCable(double max_len, double restitution, Particle& p1, Particle& p2) :
    ParticleLink(p1, p2),
    max_len_(max_len),
    restitution_(restitution)
{}

ParticleContactVector::size_type ParticleCable::FillContact(ParticleContactVector &contacts) const noexcept
{
    const double len = CurrentLength();
    if(len < max_len_) {
        return 0;
    }

    const math::UnitVec3 normal(particles_[1]->GetPos() - particles_[0]->GetPos());
    Particle *parts[2] = {particles_[0], particles_[1]};
    contacts.push_back(
                std::make_unique<ParticleContact>(parts, restitution_, normal, 0.0)
              );
    return 1;
}


double ParticleLink::CurrentLength() const noexcept
{
    Particle& p0 = *particles_[0];
    Particle& p1 = *particles_[1];

    return (p0.GetPos() - p1.GetPos()).mag();
}
