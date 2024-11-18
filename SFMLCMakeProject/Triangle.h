#pragma once
#include "Library.h"
#include "Point.h"
#include "BaseShape.h"

class Triangle : public BaseShape
{
public:
    Triangle(sf::Vector2f point1, sf::Vector2f point2, sf::Vector2f point3);

    sf::Vector2f GetPoint(int index);

    void draw(sf::RenderWindow& window) const override;
    void setFillColor(const sf::Color& color);
private:
	std::vector<sf::Vector2f> points;
    sf::ConvexShape shape;
};