#pragma once
#include "BaseDecorator.h"

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

	float GetArea() const;
	float GetPerimeter() const;
protected:
	std::shared_ptr<BaseDecorator> shape;
	virtual void ComputeArea() = 0;
	virtual void ComputePerimeter() = 0;
	void SetPerimeter(float value);
	void SetArea(float value);
private:
	float perimeter = 0.0;
	float area = 0.0;
};