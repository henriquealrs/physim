#ifndef BALISTICSAPP_H
#define BALISTICSAPP_H

#include "application.hpp"

class BalisticsApp : public Application
{
public:
    BalisticsApp();

    // Application interface
public:
    void display() override;
    void update() override;
};

#endif // BALISTICSAPP_H
