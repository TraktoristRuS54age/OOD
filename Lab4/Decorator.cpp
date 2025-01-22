#include "Decorator.h"

Decorator::Decorator(std::shared_ptr<BaseDecorator> shape)
	:shape(shape)
{
}

void Decorator::draw(sf::RenderWindow& window) const
{
	return shape->draw(window);
}

void Decorator::DrawSelection(sf::RenderWindow& window) const
{
	shape->DrawSelection(window);
}

bool Decorator::Contains(const sf::Vector2f& point) const
{
	return shape->Contains(point);
}

void Decorator::Select()
{
	m_isSelected = true;
	shape->Select();
}

void Decorator::Deselect()
{
	m_isSelected = false;
	shape->Deselect();
}

void Decorator::Move(const sf::Vector2f& offset)
{
	shape->Move(offset);
}

std::string Decorator::GetName() const
{
	return shape->GetName();
}

double Decorator::GetArea() const
{
	return area;
}

double Decorator::GetPerimeter() const
{
	return perimeter;
}

void Decorator::SetPerimeter(double value)
{
	perimeter = value;
}

void Decorator::SetArea(double value)
{
	area = value;
}