#pragma once
#include "C:\Users\Daniil.CHerepov\Desktop\ProjectsC++\OOD\OOD\Lab-4\SFMLCMakeProject4\SFMLCMakeProject4\Library.h"

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

    virtual void SetFillColor(const sf::Color& color) = 0;
    virtual void SetOutlineColor(const sf::Color& color) = 0;
    virtual void SetOutlineThickness(float thickness) = 0;

    //для Memento
    virtual std::shared_ptr<BaseDecorator> Clone() const = 0;
protected:
    bool m_isSelected = false;
};