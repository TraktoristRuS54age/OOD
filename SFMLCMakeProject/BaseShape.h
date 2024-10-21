#pragma once
#include "Library.h"

class BaseShape
{
public:
    BaseShape(const std::string& name);
    virtual void draw(sf::RenderWindow& window) const = 0;
    virtual ~BaseShape() = default;
    std::string GetName();
protected:
    std::string shapeName;
};