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
	shape.setFillColor(sf::Color::Red);
}

//Äëÿ Memento
Rectangle::Rectangle(const Rectangle& other) {
	shapeName = other.shapeName;
	shape = other.shape;
	points = other.points;
	m_isSelected = other.m_isSelected;
}
//

sf::Vector2f Rectangle::GetSize() const
{
	return shape.getSize();
}

std::string Rectangle::GetName() const
{
	return shapeName;
}

void Rectangle::SetFillColor(const sf::Color& color)
{
	shape.setFillColor(color);
}

void Rectangle::SetOutlineColor(const sf::Color& color)
{
	shape.setOutlineColor(color);
}

void Rectangle::SetOutlineThickness(float thickness)
{
	shape.setOutlineThickness(thickness);
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
