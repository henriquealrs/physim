#include "pp_spring_force_gen.hpp"

using namespace simphys::sim;


void PPSpringForceGen::UpdateForce(Particle &particle, double duration)
{
    const auto d_vec = particle.GetPos() - anchor_.GetPos();
    const double force_mag = d_vec.mag() * k_;

    const auto force = (-force_mag) * math::UnitVec3(d_vec);
    particle.ApplyForce(force);
}
