#include "Triangle.h"


Triangle::Triangle(sf::Vector2f point1, sf::Vector2f point2, sf::Vector2f point3)
{
    points[0] = point1;
    points[1] = point2;
    points[2] = point3;
    update();
}

std::size_t Triangle::getPointCount() const
{
    return 3;
}

sf::Vector2f Triangle::getPoint(std::size_t index) const
{
    if (index < 3)
        return sf::Vector2f(points[index]);

    return sf::Vector2f();
}

float Triangle::GetArea() const
{
    float p = GetPerimeter() / 2;
    return sqrt(p * ((p - (points[1].y - points[0].y)) * (p - (points[2].x - points[0].x)) * (p - (points[1].y - points[2].y))));
}

float Triangle::GetPerimeter() const
{
    return ((points[1].y - points[0].y) + (points[2].x - points[0].x) + (points[1].y - points[2].y));
}

void Triangle::setFillColor(const sf::Color& color)
{
    sf::Shape::setFillColor(color);
}