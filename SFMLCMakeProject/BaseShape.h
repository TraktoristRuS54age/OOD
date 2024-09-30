#pragma once
#include "Library.h"

class BaseShape : public sf::Shape
{
public:
    virtual float GetArea() const = 0;
    virtual float GetPerimeter() const = 0;
    virtual ~BaseShape() {}
};