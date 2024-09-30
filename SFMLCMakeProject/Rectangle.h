#pragma once
#include "Library.h"
#include "Point.h"
#include "BaseShape.h"

class Rectangle : public BaseShape
{
public:
	explicit Rectangle(sf::Vector2f point1, sf::Vector2f point2);
	virtual std::size_t getPointCount() const;
	virtual sf::Vector2f getPoint(std::size_t index) const;

	float GetSize()const;
	float GetArea() const override;
	float GetPerimeter() const override;

	void setFillColor(const sf::Color& color);
private:
	sf::Vector2f points[4];
};