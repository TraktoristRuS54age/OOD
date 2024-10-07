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
    float p = GetPerimeter() / 2.0f;
    return sqrt(p * ((p - abs(points[1].y - points[0].y)) * (p - abs(points[2].x - points[0].x)) * (p - abs(points[1].y - points[2].y))));
}

float Triangle::GetPerimeter() const
{
    float side1 = sqrt(pow(abs(points[1].x - points[0].x), 2) + pow(abs(points[1].y - points[0].y), 2)); // Сторона между points[0] и points[1]
    float side2 = sqrt(pow(abs(points[2].x - points[1].x), 2) + pow(abs(points[2].y - points[1].y), 2)); // Сторона между points[1] и points[2]
    float side3 = sqrt(pow(abs(points[2].x - points[0].x), 2) + pow(abs(points[2].y - points[0].y), 2)); // Сторона между points[0] и points[2]

    return side1 + side2 + side3;
}

void Triangle::setFillColor(const sf::Color& color)
{
    sf::Shape::setFillColor(color);
}