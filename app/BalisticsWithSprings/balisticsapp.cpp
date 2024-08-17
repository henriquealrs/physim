#include "balisticsapp.hpp"
#include "gravity_force_gen.hpp"
#include "math/vec3.hpp"
#include "ogl_headers.h"
#include "pp_spring_force_gen.hpp"

#include "objects/particle.hpp"

using simphys::math::Vec3;
using simphys::math::Point;
using simphys::sim::Particle;
using simphys::sim::PPSpringForceGen;

namespace {
    double gravity = 10.0; 
}

struct Projectile
{
    Particle particle;
    Particle attached;

    Projectile(float mass) :
        particle(Vec3(0, 1.5, 0), Vec3(20, 30, 20), mass),
        attached(Vec3(0, 0, 0), Vec3(0,0,0), mass/2)
    {}
    Projectile() = delete;
    ~Projectile() = default;
    Projectile(const Projectile& p) = delete;
    Projectile(Projectile&& p) :
        particle(std::move(p.particle)),
        attached(std::move(p.attached))
    {}
    Projectile& operator=(Projectile&& p)
    {
        particle = std::move(p.particle);
        return *this;
    }
    
    Projectile& operator=(const Projectile& p) = delete;

    void Render() const
    {
        // Main particle
        const auto& pos = particle.GetPos();
        glColor3f(0, 0, 0);
        glPushMatrix();
        glTranslatef(pos.x(), pos.y(), pos.z());
        glutSolidSphere(0.6f, 5, 4);

        glColor3f(0.75, 0.75, 0.75);
        glPushMatrix();
        glTranslatef(pos.x(), 0, pos.z());
        glScalef(1, 0.1, 0.1);
        glutSolidSphere(0.6, 5, 4);
        glPopMatrix();

        // Attached particle
        const auto& att_pos = attached.GetPos();
        glColor3f(0, 0, 0);
        glPushMatrix();
        glTranslatef(att_pos.x(), att_pos.y(), att_pos.z());
        glutSolidSphere(0.3f, 5, 4);

        glColor3f(0.75, 0.75, 0.75);
        glPushMatrix();
        glTranslatef(att_pos.x(), 0, att_pos.z());
        glScalef(1, 0.1, 0.1);
        glutSolidSphere(0.6, 5, 4);
        glPopMatrix();

        // draw line representing string
        glColor3f(0.75f, 0.75f, 0.75f);
        glBegin(GL_LINES);
            glVertex3f(pos.x(), pos.y(), pos.z());
            glVertex3f(att_pos.x(), att_pos.y(), att_pos.z());
        glEnd();

    }
    void Update(float dt)
    {
        particle.Integrate(dt);
        attached.Integrate(dt);
    }

};

static void renderShot()
{
//    glColor3f(0, 0, 0);
//    glPushMatrix();
//    glTranslatef(position.x, position.y, position.z);
//    glutSolidSphere(0.3f, 5, 4);
//    glPopMatrix();

//    glColor3f(0.75, 0.75, 0.75);
//    glPushMatrix();
//    glTranslatef(position.x, 0, position.z);
//    glScalef(1.0f, 0.1f, 1.0f);
//    glutSolidSphere(0.6f, 5, 4);
//    glPopMatrix();
}

static int n = 1;

BallisticsApp::BallisticsApp() : gravity_gen_(Vec3(0, -gravity, 0)), forces_("Forces" + std::to_string(n))
{
    n++;
}

void BallisticsApp::display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(-25.0, 8.0, 5.0,  0.0, 5.0, 22.0,  0.0, 1.0, 0.0);

    // Draw a sphere at the firing point, and add a shadow projected
    // onto the ground plane.
    glColor3f(0.0f, 0.0f, 0.0f);
    glPushMatrix();
    glTranslatef(0.0f, 1.5f, 0.0f);
    glutSolidSphere(0.1f, 5, 5);
    glTranslatef(0.0f, -1.5f, 0.0f);
    glColor3f(0.75f, 0.75f, 0.75f);
    glScalef(1.0f, 0.1f, 1.0f);
    glutSolidSphere(0.1f, 5, 5);
    glPopMatrix();

    // Draw some scale lines
    glColor3f(0.75f, 0.75f, 0.75f);
    glBegin(GL_LINES);


    for (unsigned i = 0; i < 200; i += 10)
    {
        glVertex3f(-5.0f, 0.0f, i);
        glVertex3f(5.0f, 0.0f, i);
    }
    glEnd();

    for(const auto& proj : projectiles_)
    {
        proj->Render();
    }

    // Render the description
    glColor3f(0.0f, 0.0f, 0.0f);
    this->renderText(10.0f, 34.0f, "Click: Fire\n1-4: Select Ammo", nullptr);
}

void BallisticsApp::update(float dt)
{
    forces_.UpdateForces(dt);
    for(auto& proj : projectiles_)
    {
        proj->Update(dt);
    }
}

void BallisticsApp::mouse(int button, int state, int x, int y)
{
    if(button != GLUT_LEFT_BUTTON) return;

    if(mouse_prev_state_ == GLUT_DOWN && state == GLUT_UP)
    {
        this->shoot();
    }
    mouse_prev_state_ = state;
}

void BallisticsApp::shoot()
{
    auto new_proj = new Projectile(5);
    auto spring = new PPSpringForceGen(new_proj->particle, 5, 2);

    forces_.Add(new_proj->particle, gravity_gen_);
    forces_.Add(new_proj->attached, *spring);
    forces_.Add(new_proj->attached, gravity_gen_);

    this->projectiles_.push_back(new_proj);
}


static BallisticsApp app;
Application* GetApplication()
{
    return &app;
}
