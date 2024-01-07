#ifndef APPLICATION_H
#define APPLICATION_H

#include <string>

class Application
{
    int width_, height_;

    void setView();
protected:
    void renderText(float x, float y, const std::string& text, void *font);
public:
    Application();

    virtual void display() = 0;
    virtual void update();
    virtual void mouse() {};
    virtual void reshape(int width, int height);

    virtual ~Application() = default;
    void InitGraphics();
};

Application* GetApplication();

#endif // APPLICATION_H
