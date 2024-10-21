#pragma once
#include "Decorator.h"
#include "Rectangle.h"

class RectangleDecorator : public Decorator 
{
public:
    RectangleDecorator(std::shared_ptr<Rectangle>rectangle);
protected:
    void ComputeArea() override;
    void ComputePerimeter() override;
};