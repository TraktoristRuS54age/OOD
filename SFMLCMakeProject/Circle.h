#pragma once
#include "Library.h"
#include "Point.h"
#include "BaseShape.h"
#include "BaseDecorator.h"


class Circle : public BaseDecorator
{
public:
	Circle(sf::Vector2f point1, float mRadius);

	float GetRadius() const;

	void draw(sf::RenderWindow& window) const override;
	void DrawSelection(sf::RenderWindow& window) const override;

	bool Contains(const sf::Vector2f& point) const override;
	void Select() override;
	void Deselect() override;
	void Move(const sf::Vector2f& offset) override;
	std::string GetName() const override;

	void setFillColor(const sf::Color& color);
private:
	sf::Vector2f center;
	sf::CircleShape shape;
	std::string shapeName;
};