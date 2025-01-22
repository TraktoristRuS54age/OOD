#pragma once
#include "./Shapes/BaseDecorator.h"

class Decorator : public BaseDecorator
{
public:
	Decorator(std::shared_ptr<BaseDecorator> shape);
	void draw(sf::RenderWindow& window) const override;
	void DrawSelection(sf::RenderWindow& window) const override;

	bool Contains(const sf::Vector2f& point) const override;
	void Select() override;
	void Deselect() override;
	void Move(const sf::Vector2f& offset) override;

	std::string GetName() const;

	double GetArea() const;
	double GetPerimeter() const;
protected:
	std::shared_ptr<BaseDecorator> shape;
	virtual void ComputeArea() = 0;
	virtual void ComputePerimeter() = 0;
	void SetPerimeter(double value);
	void SetArea(double value);
private:
	double perimeter = 0.0;
	double area = 0.0;
};