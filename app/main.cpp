// Include appropriate OpenGL headers.
#include "ogl_headers.h"
#include <GL/freeglut_std.h>
#include "application.hpp"

static Application* app;

/**
 * Creates a window in which to display the scene.
 */
static void createWindow(const char* title)
{
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(640,320);
    glutInitWindowPosition(0,0);
    glutCreateWindow(title);
}


static void display()
{
    app->display();
}

static void update()
{
    app->update();
}


static void reshape(int width, int height)
{
    app->reshape(width, height);
}

int main(int argc, char** argv)
{
    // Set up GLUT and the timers
    glutInit(&argc, argv);

    // Create the application and its window
    createWindow("Example");
    glutDisplayFunc(display);
    glutIdleFunc(update);
    glutReshapeFunc(reshape);

    app = GetApplication();


    glutMainLoop();

    return 0;
}
