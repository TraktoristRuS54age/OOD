#pragma once
#include "Decorator.h"
#include "Triangle.h"

class TriangleDecorator : public Decorator {
public:
    TriangleDecorator(std::shared_ptr<Triangle>triangle);
protected:
    void ComputeArea() override;
    void ComputePerimeter() override;
};