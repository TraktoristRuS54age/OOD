#pragma once
#include "Library.h"

class BaseDecorator
{
public:
    virtual void draw(sf::RenderWindow& window) const = 0;
    virtual void DrawSelection(sf::RenderWindow& window) const = 0;

    virtual bool Contains(const sf::Vector2f& point) const = 0;
    virtual void Select() = 0;
    virtual void Deselect() = 0;
    virtual void Move(const sf::Vector2f& offset) = 0;

    virtual  std::string GetName() const = 0;
    bool IsSelected() { return m_isSelected; };
protected:
    bool m_isSelected = false;
};