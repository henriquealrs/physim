#include "balisticsapp.hpp"
#include "ogl_headers.h"


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

BalisticsApp::BalisticsApp()
{

}

void BalisticsApp::display()
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
}

void BalisticsApp::update()
{
    Application::update();
}


static BalisticsApp app;
Application* GetApplication()
{
    return &app;
}
