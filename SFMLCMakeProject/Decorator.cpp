#include "Decorator.h"

Decorator::Decorator(std::shared_ptr<BaseShape> shape)
	:BaseShape(shape->GetName()),
	shape(shape)
{
}

float Decorator::GetArea() const
{
	return area;
}

float Decorator::GetPerimeter() const
{
	return perimeter;
}

void Decorator::SetPerimeter(float value)
{
	perimeter = value;
}

void Decorator::SetArea(float value)
{
	area = value;
}

void Decorator::draw(sf::RenderWindow& window) const
{
	return shape->draw(window);
}