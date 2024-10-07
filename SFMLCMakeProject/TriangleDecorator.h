#pragma once
#include "Decorator.h"
#include "Triangle.h"

class TriangleDecorator : public Decorator {
public:
    explicit TriangleDecorator(Triangle* triangle) : Decorator(triangle) {}

    float GetArea() const override {
        return static_cast<Triangle*>(shape)->GetArea();
    }

    float GetPerimeter() const override {
        return static_cast<Triangle*>(shape)->GetPerimeter();
    }
};