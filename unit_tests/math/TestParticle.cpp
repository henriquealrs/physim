#include <cmath>
#include <gtest/gtest.h>
#include "i_particle_force_gen.hpp"
#include "objects/particle.hpp"
#include "gravity_force_gen.hpp"
#include "fixed_point_spring_force_gen.hpp"
#include <iostream>

using namespace simphys::math;

TEST(ParticleTest, Integrator)
{
    double totalT = 5;
    double dT = 0.001;

    auto particle = simphys::sim::Particle(Vec3(0, 0, 0), Vec3(0, 0, -10), 5, 0.01);

    double t = 0;
    while(t < totalT)
    {
        particle.Integrate(dT);
        t += dT;
    }

    auto pos = particle.GetPos();

    EXPECT_NEAR(pos.z(), 1*totalT - .5 * 10 * totalT * totalT, 0.05);
    EXPECT_NEAR(pos.x(), 1 * 5, 0.05);
}

TEST(ParticleTest, ParticleHangingOnSpring)
{
    double totalT = 30000;
    double dT = 0.001;
    double m = 1.5;
    double rest_len = 0.5;
    double g = 10;
    double k = 2;

    auto particle = simphys::sim::Particle(Vec3(0, 0, -1), Vec3(0,0,0), m, 0.01);
    auto spring = simphys::sim::FixedPointSpringForceGen(Vec3(0, 0, 0), k, rest_len);
    auto gravity = simphys::sim::GravityParticleForceGen(Vec3(0, 0, -g));
    auto registry = simphys::sim::ParticleForceRegistry("Forces");
    registry.Add(particle, gravity);
    registry.Add(particle, spring);

    double t = 0;
    while(t < totalT)
    {
        registry.UpdateForces(dT);
        particle.Integrate(dT);
        t += dT;
    }

    const auto pos = particle.GetPos();
    EXPECT_EQ(pos, Vec3(0, 0, -rest_len  - m * g / k));
}

