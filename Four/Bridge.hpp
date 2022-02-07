#ifndef BRIDGE
#define BRIDGE

#include <iostream>

// Implementor
class DrawingImplementor {
public:
    virtual void drawRectangle(double) = 0;
 
    virtual ~DrawingImplementor() {
    }
};

class DrawingWithBrush : public DrawingImplementor
{
public:
    void drawRectangle(double size) override
    {
        std::cout << "Drawing with a brash, size: " << size << std::endl;
    }
};

class DrawingWithPencil : public DrawingImplementor
{
public:
    void drawRectangle(double size) override
    {
        std::cout << "Drawing with a pencil, size: " << size << std::endl;
    }
};

// Abstraction
class Shape {

public:
    virtual void draw(double pct)= 0; // low-level
    virtual void resize(double pct) = 0; // high-level
    virtual ~Shape() {
    }
};

class Rectangle: public Shape
{
private:
    DrawingImplementor* implementor;
public:
    Rectangle(DrawingImplementor* _implementor) : implementor(_implementor) {}
    void draw(double pct) override
    {
        implementor->drawRectangle(pct);
    }
    void resize(double pct) override
    {
        implementor->drawRectangle(pct);
    }
};

#endif