#ifndef __DRAG_FORCE_GEN_HPP
#define __DRAG_FORCE_GEN_HPP


#include "i_particle_force_gen.hpp"


namespace simphys
{
namespace sim
{

class DragForceGen : public IParticleForceGen
{
    double drag_k1_;
    double drag_k2_;
public:
    DragForceGen() = delete;
    DragForceGen(double vel_drag, double vel_sqrare_drag) : 
        drag_k1_(vel_drag),
        drag_k2_(vel_sqrare_drag)
    {}


    // IParticleForceGen interface
public:
    virtual void UpdateForce(Particle &particle, double duration) override;
};

}
}


#endif  // __DRAG_FORCE_GEN_HPP
