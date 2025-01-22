#pragma once
#include "Decorator.h"
#include "Shapes\Triangle\Triangle.h"

class TriangleDecorator : public Decorator {
public:
    TriangleDecorator(std::shared_ptr<BaseDecorator>triangle);
protected:
    void ComputeArea() override;
    void ComputePerimeter() override;
};