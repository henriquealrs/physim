#include <cmath>
#include <gtest/gtest.h>
#include "particle_contact.hpp"

using simphys::sim::Particle;
using simphys::sim::ParticleContact;
using namespace simphys::math;

//TEST(ParticleContact, TestColision)
//{
//    Particle p1(Vec3{0, 0, 0}, 20*Vec3(std::cos(M_PI/6), std::sin(M_PI/6), 0), 5);

//    Particle p2(Vec3{0, 0, 0}, 20*Vec3(0, 0, 0), INFINITY);  // TODO: Create wrapper for static objects
//    // TODO: Replace particle with static object/wall when we have it

//    ParticleContact contact{ {&p1, &p2}, 0.75,  Vec3(0, -1, 0)};
//    contact.Resolve(0.01);

//    const auto v1 = p1.GetVelocity();
//    EXPECT_EQ(v1, Vec3(-12.99, 10, 0));
//}
