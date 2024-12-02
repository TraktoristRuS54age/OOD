#pragma once
#include "Library.h"
#include "BaseDecorator.h"

class BaseShape
{
public:
    virtual void draw(sf::RenderWindow& window) const = 0;
    virtual void DrawSelection(sf::RenderWindow& window) const = 0;

    virtual bool Contains(const sf::Vector2f& point) const = 0;
    virtual void Select() = 0;
    virtual void Deselect() = 0;
    virtual void Move(const sf::Vector2f& offset) = 0;

    virtual  std::string GetName() const = 0;
};