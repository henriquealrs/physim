#include "drag_force_gen.hpp"

using namespace simphys;
using namespace sim;

void DragForceGen::UpdateForce(Particle &particle, double duration)
{
    const auto& v = particle.GetVelocity();

    double drag_abs= v.mag() * drag_k1_ + v.mag_sqr() * drag_k2_;

    const auto drag = (-drag_abs) * math::UnitVec3(v);
    particle.ApplyForce(drag);
}
