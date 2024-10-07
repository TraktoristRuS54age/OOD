#pragma once
#include "Decorator.h"
#include "Circle.h"

class CircleDecorator : public Decorator {
public:
    explicit CircleDecorator(Circle* circle) : Decorator(circle) {}

    float GetArea() const override 
    {
        return static_cast<Circle*>(shape)->GetArea();
    }

    float GetPerimeter() const override 
    {
        return static_cast<Circle*>(shape)->GetPerimeter();
    }
};