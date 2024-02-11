#include <cmath>
#include <gtest/gtest.h>
#include "particle_contact.hpp"

using simphys::sim::Particle;
using simphys::sim::ParticleContact;
using namespace simphys::math;

TEST(ParticleContact, TestInelasticColision)
{
    const auto null_vec = Vec3(0, 0, 0);
    const auto  v1 = Vec3(5, 0, 0);
    const double m1 = 5;
    auto p1 = Particle(null_vec, v1, m1);

    const auto  v2 = Vec3(0, 0, 0);
    const double m2 = 10;
    auto p2 = Particle(null_vec, v2, m2);

    auto collision = ParticleContact{{&p1, &p2}, 0, Vec3(-1, 0, 0)};
    collision.Resolve(0.1);

    const auto expected_vel = (m1 / (m1+m2))*v1;
    EXPECT_EQ(p1.GetVelocity(), expected_vel);
    EXPECT_EQ(p2.GetVelocity(), expected_vel);
}

TEST(ParticleContact, TestElasticColision)
{
    const auto null_vec = Vec3(0, 0, 0);
    const auto  v1 = Vec3(5, 0, 0);
    const double m1 = 5;
    auto p1 = Particle(null_vec, v1, m1);

    const auto  v2 = Vec3(0, 0, 0);
    const double m2 = 10;
    auto p2 = Particle(null_vec, v2, m2);

    auto collision = ParticleContact{{&p1, &p2}, 1, Vec3(-1, 0, 0)};
    collision.Resolve(0.1);

    const auto expected_vel_p1 = ((m1 - m2) / (m1 + m2)) * v1 + (2 * m2 / (m1 + m2)) * v2;
    const auto expected_vel_p2 = ((2 * m1) / (m1 + m2)) * v1 + ((m2 - m1)/(m1+m2))*v2;
    EXPECT_EQ(p1.GetVelocity(), expected_vel_p1);
    EXPECT_EQ(p2.GetVelocity(), expected_vel_p2);
}
