#include "particle_contact.hpp"


using namespace simphys::sim;
using namespace simphys::math;

void ParticleContact::Resolve(double duration) noexcept
{
    ResolveVelocity(duration);
}

double ParticleContact::CalculateSeparatingVelocity() const noexcept
{
    auto relative_vel = particles_[0]->GetVelocity();
    if(particles_[1] != nullptr) {
        relative_vel -= particles_[1]->GetVelocity();
    }
    return relative_vel.dot(normal_);
}

void ParticleContact::ResolveVelocity(double duration) noexcept
{
    const double sep_vel = CalculateSeparatingVelocity();
    if(sep_vel > 0) {
        return;
    }
    const double new_sep_vel = -sep_vel * restiturion_;
    const double delta_vel = new_sep_vel - sep_vel;
    const double total_inverse_mass = particles_[0]->GetInverseMass() +
            (particles_[1] != nullptr? particles_[1]->GetInverseMass() : 0);

    if(total_inverse_mass <= 0) {
        return;
    }

    double impulse = delta_vel / total_inverse_mass;
    Vec3 impulse_per_i_mass = normal_ * impulse;
    particles_[0]->SetVelocity(particles_[0]->GetVelocity() + impulse_per_i_mass * particles_[0]->GetInverseMass());

    if(particles_[1] != nullptr) {
        particles_[1]->SetVelocity(
                    particles_[1]->GetVelocity() + impulse_per_i_mass * -particles_[1]->GetInverseMass()
        );
    }
}


