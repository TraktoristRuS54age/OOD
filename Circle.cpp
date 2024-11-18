#include "Circle.h"

Circle::Circle(sf::Vector2f point1, float mRadius)
	:BaseShape("Circle")
{
	shape.setRadius(mRadius);
	shape.setPosition(point1);
}


float Circle::GetRadius() const
{
	return shape.getRadius();
}

void Circle::draw(sf::RenderWindow& window) const
{
	window.draw(shape);
}

void Circle::setFillColor(const sf::Color& color)
{
	shape.setFillColor(color);
}