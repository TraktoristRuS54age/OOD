#pragma once
#include "Decorator.h"
#include "Rectangle.h"

class RectangleDecorator : public Decorator {
public:
    explicit RectangleDecorator(Rectangle* rectangle) : Decorator(rectangle) {}

    float GetArea() const override {
        return static_cast<Rectangle*>(shape)->GetArea();
    }

    float GetPerimeter() const override {
        return static_cast<Rectangle*>(shape)->GetPerimeter();
    }
};