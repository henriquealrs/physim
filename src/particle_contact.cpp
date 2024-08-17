#include "particle_contact.hpp"
#include <algorithm>


using namespace simphys::sim;
using namespace simphys::math;

void ParticleContact::Resolve(double duration) noexcept
{
    ResolveVelocity(duration);
    ResolveInterpenetration(duration);
}

double ParticleContact::CalculateSeparatingVelocity() const noexcept
{
    const auto relative_vel = particles_[0]->GetVelocity() -
            ((particles_[1] == nullptr)?
                Vec3(0, 0, 0) :
                particles_[1]->GetVelocity());
    return relative_vel.dot(normal_);
}

void ParticleContact::ResolveVelocity(double duration) noexcept
{
    const double sep_vel = CalculateSeparatingVelocity();
    if(sep_vel > 0) {
        return;
    }

    double new_sep_vel = -sep_vel * restitution_;

    // Check the velocity build-up due to acceleration only
    const auto acc_cause_velocity = particles_[0]->GetAceleration() -
            ((particles_[1] == nullptr)? Vec3(0,0,0) : particles_[1]->GetAceleration());
    const double acc_caused_sep_vel = acc_cause_velocity.dot(normal_) * duration;
    // if closing velocity caused by acceleration build-up
    // remove it
    if(acc_caused_sep_vel < 0) {
        new_sep_vel += restitution_ * acc_caused_sep_vel;
        new_sep_vel = std::max(new_sep_vel, 0.0);
    }

    const double delta_vel = new_sep_vel - sep_vel;
    const double total_inverse_mass = particles_[0]->GetInverseMass() +
            (particles_[1] != nullptr? particles_[1]->GetInverseMass() : 0);

    if(total_inverse_mass <= 0) {
        return;
    }

    const double impulse = delta_vel / total_inverse_mass;
    const Vec3 impulse_per_i_mass = normal_ * impulse;
    particles_[0]->SetVelocity(particles_[0]->GetVelocity() + impulse_per_i_mass * particles_[0]->GetInverseMass());

    if(particles_[1] != nullptr) {
        particles_[1]->SetVelocity(
                    particles_[1]->GetVelocity() + impulse_per_i_mass * -particles_[1]->GetInverseMass()
        );
    }
}

void ParticleContact::ResolveInterpenetration(double duration) noexcept
{
    if(this->penetration_ < 0) {
        return;
    }

    const double total_inverse_mass = particles_[0]->GetInverseMass() +
            ((particles_[1] == nullptr)? 0 : particles_[1]->GetInverseMass());

    Vec3 move_per_i_mass = normal_ * (-penetration_ / total_inverse_mass);
    particles_[0]->IncrementPosition(move_per_i_mass * particles_[0]->GetInverseMass());
    if(particles_[1] != nullptr) {
        particles_[1]->IncrementPosition(move_per_i_mass * particles_[1]->GetInverseMass());
    }
}



void ParticleContactResolver::ResolveContacts(const std::vector<ParticleContact *> &contacts, double duration) noexcept
{
    auto iterations_left = iterations_allowed_;
    while(iterations_left > 0) {

        ParticleContact *max_contact = *std::max_element(
                    contacts.cbegin(),
                    contacts.cend(),
                    [](const ParticleContact *c1, const ParticleContact *c2) {
                        return c1->CalculateSeparatingVelocity() < c2->CalculateSeparatingVelocity();
        });

        max_contact->Resolve(duration);
        iterations_left--;
    }
}
