#include "particle_link.hpp"

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

    Particle& p0 = *particles_[0];
    Particle& p1 = *particles_[1];

    math::UnitVec3 normal(p1.GetPos() - p0.GetPos());
    contacts.push_back(
                ParticleContact{{&p0, &p1}, restitution_, normal, 0.0}
              );
    return 1;
}


double ParticleLink::CurrentLength() const noexcept
{
    Particle& p0 = *particles_[0];
    Particle& p1 = *particles_[1];

    return (p0.GetPos() - p1.GetPos()).mag();
}
