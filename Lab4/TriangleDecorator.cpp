#include "TriangleDecorator.h"

TriangleDecorator::TriangleDecorator(std::shared_ptr<BaseDecorator> triangle)
	:Decorator(std::dynamic_pointer_cast<BaseDecorator>(triangle))
{
	ComputePerimeter();	
	ComputeArea();
}

void TriangleDecorator::ComputeArea()
{
	double p = GetPerimeter() / 2.0;

	sf::Vector2f p0 = std::dynamic_pointer_cast<Triangle>(shape)->GetPoint(0);
	sf::Vector2f p1 = std::dynamic_pointer_cast<Triangle>(shape)->GetPoint(1);
	sf::Vector2f p2 = std::dynamic_pointer_cast<Triangle>(shape)->GetPoint(2);

	SetArea(sqrt(p * ((p - abs(p1.y - p0.y)) * (p - abs(p2.x - p0.x)) * (p - abs(p1.y - p2.y)))));
}

void TriangleDecorator::ComputePerimeter()
{
	sf::Vector2f p0 = std::dynamic_pointer_cast<Triangle>(shape)->GetPoint(0);
	sf::Vector2f p1 = std::dynamic_pointer_cast<Triangle>(shape)->GetPoint(1);
	sf::Vector2f p2 = std::dynamic_pointer_cast<Triangle>(shape)->GetPoint(2);

	double side1 = sqrt(pow(abs(p1.x - p0.x), 2) + pow(abs(p1.y - p0.y), 2)); // ������� ����� points[0] � points[1]
	double side2 = sqrt(pow(abs(p2.x - p1.x), 2) + pow(abs(p2.y - p1.y), 2)); // ������� ����� points[1] � points[2]
	double side3 = sqrt(pow(abs(p2.x - p0.x), 2) + pow(abs(p2.y - p0.y), 2)); // ������� ����� points[0] � points[2]

	SetPerimeter(side1 + side2 + side3);
}
