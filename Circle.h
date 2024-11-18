#pragma once
#include "Library.h"
#include "Point.h"
#include "BaseShape.h"


class Circle : public BaseShape
{
public:
	Circle(sf::Vector2f point1, float mRadius);

	float GetRadius() const;
	void draw(sf::RenderWindow& window) const override;
	void setFillColor(const sf::Color& color);
private:
	sf::Vector2f center;
	sf::CircleShape shape;
};