#include <cmath>
#include <gtest/gtest.h>
#include "objects/particle.hpp"
#include "gravity_force_gen.hpp"
#include "fixed_point_spring_force_gen.hpp"
#include "drag_force_gen.hpp"
#include "i_particle_force_gen.hpp"
#include <iostream>

using namespace simphys::math;

TEST(ParticleTest, Integrator)
{
    double totalT = 5;
    double dT = 0.001;

    auto particle = simphys::sim::Particle(Vec3(0, 0, 0), Vec3(1, 0, 1), 5, 0.0);
    simphys::sim::ParticleForceRegistry registry("integrationTest");
    simphys::sim::GravityParticleForceGen gravity(Vec3(0, 0, -10));
    registry.Add(particle, gravity);

    double t = 0;
    while(t < totalT)
    {
        registry.UpdateForces(dT);
        particle.Integrate(dT);
        t += dT;
    }

    auto pos = particle.GetPos();

    EXPECT_NEAR(pos.z(), 1*totalT - .5 * 10 * totalT * totalT, 0.05);
    EXPECT_NEAR(pos.x(), 1 * 5, 0.05);
}

TEST(ParticleTest, ParticleHangingOnSpring)
{
    double totalT = 3000;
    double dT = 0.001;
    double m = 1.5;
    double g = 10;
    double k = 2;

    auto particle = simphys::sim::Particle(Vec3(0, 0, -1),Vec3(0, 0, -g), m, 0.0);
    simphys::sim::ParticleForceRegistry registry("springTest");
    simphys::sim::GravityParticleForceGen gravity(Vec3(0,0,-g));
    simphys::sim::FixedPointSpringForceGen spring(Vec3(0,0,0), k, 0.0);
    simphys::sim::DragForceGen drag(0.1, 0.0);
    registry.Add(particle, gravity);
    registry.Add(particle, spring);
    registry.Add(particle, drag);

    double t = 0;
    while(t < totalT)
    {
        registry.UpdateForces(dT);
        particle.Integrate(dT);
        t += dT;
    }

    const auto pos = particle.GetPos();
    EXPECT_EQ(pos, Vec3(0, 0, - m * g / k));
}

