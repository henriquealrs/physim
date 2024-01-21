#ifndef APPLICATION_H
#define APPLICATION_H

#include <string>

#include "timehelper.h"

class Application
{
    int width_, height_;
    TimeHelper time_helper_;

    void setView();
    virtual void update(float dt) = 0;
protected:
    void renderText(float x, float y, const std::string& text, void *font);
public:
    Application();

    virtual void display() = 0;
    void update();
    virtual void mouse(int button, int state, int x, int y) {};
    virtual void reshape(int width, int height);

    virtual ~Application() = default;
    void InitGraphics();
};

Application* GetApplication();

#endif // APPLICATION_H
