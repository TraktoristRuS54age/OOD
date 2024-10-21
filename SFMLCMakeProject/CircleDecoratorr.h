#pragma once
#include "Decorator.h"
#include "Circle.h"

class CircleDecorator : public Decorator 
{
public:
    CircleDecorator(std::shared_ptr<Circle>circle);
protected:
    void ComputeArea() override;
    void ComputePerimeter() override;
};