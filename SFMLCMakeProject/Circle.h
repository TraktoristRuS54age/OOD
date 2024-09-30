#pragma once
#include "Library.h"
#include "Point.h"
#include "BaseShape.h"


class Circle : public BaseShape
{
public:
	explicit Circle(sf::Vector2f point1, float mRadius);

	virtual std::size_t getPointCount() const;
	virtual sf::Vector2f getPoint(std::size_t index) const;

	float GetRadius() const;
	float GetArea() const override;
	float GetPerimeter() const override;

	void setFillColor(const sf::Color& color);
private:
	sf::Vector2f center;
	float radius;
};