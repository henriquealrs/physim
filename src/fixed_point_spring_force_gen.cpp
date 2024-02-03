#include "fixed_point_spring_force_gen.hpp"

using namespace simphys::sim;
using simphys::math::Vec3;
using simphys::math::UnitVec3;


void simphys::sim::FixedPointSpringForceGen::UpdateForce(Particle &particle, double duration)
{
    const auto d = particle.GetPos() - point_;
    const double dist = d.mag();

    const auto force = (-1) * UnitVec3(d) * (dist - rest_len_) * k_;

    particle.ApplyForce(force);
}
