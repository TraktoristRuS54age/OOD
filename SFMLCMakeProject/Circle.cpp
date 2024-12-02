#include "Circle.h"

Circle::Circle(sf::Vector2f point1, float mRadius)
{
	shapeName = "Circle";
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
	//center += offset;
	//shape.setPosition(center);
	shape.move(offset);
}

void Circle::setFillColor(const sf::Color& color)
{
	shape.setFillColor(color);
}

std::string Circle::GetName() const
{
	return shapeName;
}
