#include "Triangle.h"


Triangle::Triangle(sf::Vector2f point1, sf::Vector2f point2, sf::Vector2f point3)
    :BaseShape("Triangle")
{
    shape.setPointCount(3);
    //std::vector<sf::Vector2f> points;
    points.push_back(point1);
    points.push_back(point2);
    points.push_back(point3);
    for (int i = 0; i < 3; i++)
    {
        shape.setPoint(i, points[i]);
    }
}

sf::Vector2f Triangle::GetPoint(int index)
{
    return shape.getPoint(index);
}

void Triangle::draw(sf::RenderWindow& window) const
{
    window.draw(shape);
}

void Triangle::setFillColor(const sf::Color& color)
{
    shape.setFillColor(color);
}