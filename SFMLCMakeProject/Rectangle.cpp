#include "Rectangle.h"

Rectangle::Rectangle(sf::Vector2f point1, sf::Vector2f point2)
{
	shapeName = "Rectangle";
	points.push_back(point1);
	points.push_back(point2);
	sf::Vector2f position = sf::Vector2f(point1.x, point1.y);
	sf::Vector2f size = sf::Vector2f(point2.x - point1.x, point2.y - point1.y);

	shape.setPosition(position);
	shape.setSize(size);
}

sf::Vector2f Rectangle::GetSize() const
{
	return shape.getSize();
}

void Rectangle::setFillColor(const sf::Color& color)
{
	shape.setFillColor(color);
}

std::string Rectangle::GetName() const
{
	return shapeName;
}

void Rectangle::draw(sf::RenderWindow& window) const
{
	window.draw(shape);
}

void Rectangle::DrawSelection(sf::RenderWindow& window) const
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

bool Rectangle::Contains(const sf::Vector2f& point) const
{
	return shape.getGlobalBounds().contains(point);
}

void Rectangle::Select()
{
	m_isSelected = true;
}

void Rectangle::Deselect()
{
	m_isSelected = false;
}

void Rectangle::Move(const sf::Vector2f& offset)
{
	shape.move(offset);
}
