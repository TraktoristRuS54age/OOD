#include "Rectangle.h"

Rectangle::Rectangle(sf::Vector2f point1, sf::Vector2f point2)
{
	points[0] = point1;
	points[1] = sf::Vector2f(point2.x, point1.y);
	points[2] = point2;
	points[3] = sf::Vector2f(point1.x, point2.y);
	update();
}

std::size_t Rectangle::getPointCount() const
{
	return 4;
}
sf::Vector2f Rectangle::getPoint(std::size_t index) const
{
	if (index < 4)
		return sf::Vector2f(points[index]);

	return sf::Vector2f();
}

float Rectangle::GetSize() const
{
	return ((points[3].y - points[0].y) + (points[1].x - points[0].x));
}

float Rectangle::GetArea() const
{
	return ((points[3].y - points[0].y) * (points[1].x - points[0].x));
}

float Rectangle::GetPerimeter() const
{
	return 2 * GetSize();
}

void Rectangle::setFillColor(const sf::Color& color)
{
	sf::Shape::setFillColor(color);
}