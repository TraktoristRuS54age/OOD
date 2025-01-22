#include "Triangle.h"


Triangle::Triangle(sf::Vector2f point1, sf::Vector2f point2, sf::Vector2f point3)
{
    shape.setPointCount(3);
    points.push_back(point1);
    points.push_back(point2);
    points.push_back(point3);
    shapeName = "Triangle";
    for (int i = 0; i < 3; i++)
    {
        shape.setPoint(i, points[i]);
    }
    shape.setFillColor(sf::Color::Red);
}

//Äëÿ Memento
Triangle::Triangle(const Triangle& other) {
    shapeName = other.shapeName;
    shape = other.shape;
    points = other.points;
    m_isSelected = other.m_isSelected;
}
//

sf::Vector2f Triangle::GetPoint(int index)
{
    return shape.getPoint(index);
}

void Triangle::draw(sf::RenderWindow& window) const
{
    window.draw(shape);
}

void Triangle::DrawSelection(sf::RenderWindow& window) const
{
    if (m_isSelected) {
        sf::RectangleShape rect;
        shape.getGlobalBounds().getPosition();
        rect.setPosition(shape.getGlobalBounds().getPosition());
        rect.setSize(shape.getGlobalBounds().getSize());
        rect.setOutlineColor(sf::Color::Yellow);
        rect.setOutlineThickness(2);
        rect.setFillColor(sf::Color::Transparent);
        window.draw(rect);
    }
}

bool Triangle::Contains(const sf::Vector2f& point) const
{
    return shape.getGlobalBounds().contains(point);
}

void Triangle::Select()
{
    m_isSelected = true;
}

void Triangle::Deselect()
{
    m_isSelected = false;
}

void Triangle::Move(const sf::Vector2f& offset)
{
    shape.move(offset);
}

void Triangle::SetFillColor(const sf::Color& color)
{
    shape.setFillColor(color);
}

void Triangle::SetOutlineColor(const sf::Color& color)
{
    shape.setOutlineColor(color);
}

void Triangle::SetOutlineThickness(float thickness)
{
    shape.setOutlineThickness(thickness);
}

std::string Triangle::GetName() const
{
    return shapeName;
}
