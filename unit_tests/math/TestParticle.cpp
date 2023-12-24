#include <cmath>
#include <gtest/gtest.h>
#include "objects/particle.hpp"
#include <iostream>

using namespace simphys::math;

TEST(ParticleTest, Integrator)
{
    double totalT = 5;
    double dT = 0.001;

    auto particle = simphys::sim::Particle(Vec3(0, 0, 0), Vec3(1, 0, 1), Vec3(0, 0, -10), 5, 0.05);

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
    double totalT = 3000;
    double dT = 0.001;
    double m = 1.5;
    double g = 10;
    double k = 2;

    auto particle = simphys::sim::Particle(Vec3(0, 0, -1), Vec3(0, 0, -0.5), Vec3(0, 0, -g), m, 0.05);

    double t = 0;
    while(t < totalT)
    {
        const auto pos = particle.GetPos();

        const auto spring_force = (-k) * particle.GetPos();
        particle.ApplyForce(spring_force);
        particle.ApplyForce( (-0.1) * particle.GetVelocity());

        particle.Integrate(dT);
        t += dT;
        std::cout << pos.z() << "\n";
    }

    const auto pos = particle.GetPos();
    EXPECT_EQ(pos, Vec3(0, 0, - m * g / k));
}

