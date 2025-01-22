#pragma once
#include "Decorator.h"
#include "Shapes\Circle\Circle.h"

class CircleDecorator : public Decorator 
{
public:
    CircleDecorator(std::shared_ptr<BaseDecorator>circle);
protected:
    void ComputeArea() override;
    void ComputePerimeter() override;
};