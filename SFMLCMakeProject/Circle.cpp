#include "Circle.h"


Circle::Circle(sf::Vector2f point1, float mRadius)
	:radius(mRadius),
	center(point1)
{
	update();
}

std::size_t Circle::getPointCount() const
{
	return 30;
}

sf::Vector2f Circle::getPoint(std::size_t index) const
{
	static const float pi = 3.141592654f;

	float angle = index * 2 * pi / getPointCount();
	float x = center.x + radius * std::cos(angle);
	float y = center.y + radius * std::sin(angle);

	return sf::Vector2f(x, y);
}

float Circle::GetRadius() const
{
	return radius;
}

float Circle::GetArea() const
{
	return 3.141592654f * GetRadius() * GetRadius();
}

float Circle::GetPerimeter() const
{
	return 2 * 3.141592654f * GetRadius();
}

void Circle::setFillColor(const sf::Color& color)
{
	sf::Shape::setFillColor(color);
}