#pragma once
#include "Decorator.h"
#include "Shapes\Rectangle\Rectangle.h"

class RectangleDecorator : public Decorator 
{
public:
    RectangleDecorator(std::shared_ptr<BaseDecorator>rectangle);
protected:
    void ComputeArea() override;
    void ComputePerimeter() override;
};