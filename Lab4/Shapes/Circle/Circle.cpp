#include "Circle.h"

Circle::Circle(sf::Vector2f point1, float mRadius)
{
	shapeName = "Circle";
	shape.setRadius(mRadius);
	shape.setPosition(point1);
	shape.setFillColor(sf::Color::Red);
}

//Äëÿ Memento
Circle::Circle(const Circle& other) {
	shapeName = other.shapeName;
	shape = other.shape;
	center = other.center;
	m_isSelected = other.m_isSelected;
}
//
float Circle::GetRadius() const
{
	return shape.getRadius();
}

void Circle::draw(sf::RenderWindow& window) const
{
	window.draw(shape);
}

void Circle::DrawSelection(sf::RenderWindow& window) const
{
	if (m_isSelected)
	{
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

bool Circle::Contains(const sf::Vector2f& point) const
{
	sf::FloatRect bounds = shape.getGlobalBounds();
	return bounds.contains(point);
}

void Circle::Select()
{
	m_isSelected = true;
}

void Circle::Deselect()
{
	m_isSelected = false;
}

void Circle::Move(const sf::Vector2f& offset)
{
	shape.move(offset);
}

void Circle::SetFillColor(const sf::Color& color)
{
	shape.setFillColor(color);
}

void Circle::SetOutlineColor(const sf::Color& color)
{
	shape.setOutlineColor(color);
}

void Circle::SetOutlineThickness(float thickness)
{
	shape.setOutlineThickness(thickness);
}

std::string Circle::GetName() const
{
	return shapeName;
}
