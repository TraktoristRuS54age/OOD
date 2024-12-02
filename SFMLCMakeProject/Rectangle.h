#pragma once
#include "Library.h"
#include "Point.h"
#include "BaseShape.h"
#include "BaseDecorator.h"

class Rectangle : public BaseDecorator
{
public:
	Rectangle(sf::Vector2f point1, sf::Vector2f point2);

	sf::Vector2f GetSize() const;

	void draw(sf::RenderWindow& window) const override;
	void DrawSelection(sf::RenderWindow& window) const override;

	bool Contains(const sf::Vector2f& point) const override;
	void Select() override;
	void Deselect() override;
	void Move(const sf::Vector2f& offset) override;
	std::string GetName() const override;

	void setFillColor(const sf::Color& color);
private:
	std::vector<sf::Vector2f> points;
	sf::RectangleShape shape;
	std::string shapeName;
};