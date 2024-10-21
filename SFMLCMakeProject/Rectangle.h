#pragma once
#include "Library.h"
#include "Point.h"
#include "BaseShape.h"

class Rectangle : public BaseShape
{
public:
	Rectangle(sf::Vector2f point1, sf::Vector2f point2);

	sf::Vector2f GetSize() const;

	void draw(sf::RenderWindow& window) const override;
	void setFillColor(const sf::Color& color);
private:

	std::vector<sf::Vector2f> points;
	sf::RectangleShape shape;
};