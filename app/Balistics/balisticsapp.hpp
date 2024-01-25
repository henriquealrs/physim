#ifndef BALISTICSAPP_H
#define BALISTICSAPP_H

#include "application.hpp"
#include "i_particle_force_gen.hpp"
#include "gravity_force_gen.hpp"
#include "objects/particle.hpp"
#include <vector>

namespace simphys
{
namespace sim
{
class Particle;
class ParticleForceRegistry;
class GravityParticleForceGen;
}
}

class Projectile;

class BallisticsApp : public Application
{
public:
    BallisticsApp();

    // Application interface
public:
    void display() override;
    virtual void update(float dt) override;

private:
    void mouse(int button, int state, int x, int y) override;
    void shoot();

    int mouse_prev_state_;
    std::vector<Projectile*> projectiles_;
    simphys::sim::ParticleForceRegistry forces_;
    simphys::sim::GravityParticleForceGen gravity_gen_;
};

#endif // BALISTICSAPP_H
