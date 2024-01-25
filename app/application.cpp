#include "application.hpp"
#include "ogl_headers.h"
#include <iostream>

Application::Application()
{
}

void Application::update()
{
    glutPostRedisplay();
    float dt = time_helper_.GetDt();
    this->update(dt);
//    std::cout << "dt = " << dt << "\n";
}

void Application::reshape(int width, int height)
{
    // Avoid the divide by zero.
    if (height_ <= 0) height_ = 1;

    // Set the internal variables and update the view
    width_ = width;
    height_ = height;
    glViewport(0, 0, width_, height_);
    setView();
}

// The following methods aren't intended to be overloaded
void Application::renderText(float x, float y, const std::string& text, void *font)
{
    glDisable(GL_DEPTH_TEST);

    // Temporarily set up the view in orthographic projection.
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    glOrtho(0.0, (double)width_, 0.0, (double)height_, -1.0, 1.0);

    // Move to modelview mode.
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();

    // Ensure we have a font
    if (font == NULL) {
        font = GLUT_BITMAP_HELVETICA_10;
    }

    // Loop through characters displaying them.
    size_t len = text.length();

    glRasterPos2f(x, y);
    for (const auto letter : text) {

        // If we meet a newline, then move down by the line-height
        // TODO: Make the line-height a function of the font
        if (letter == '\n') {
            y -= 12.0f;
            glRasterPos2f(x, y);
        }
        glutBitmapCharacter(font, letter);
    }

    // Pop the matrices to return to how we were before.
    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);

    glEnable(GL_DEPTH_TEST);
}


void Application::InitGraphics()
{
    glClearColor(0.9f, 0.95f, 1.0f, 1.0f);
    glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_SMOOTH);

    setView();
    time_helper_.Init();
}

void Application::setView()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (double)width_/(double)height_, 1.0, 500.0);
    glMatrixMode(GL_MODELVIEW);
}
