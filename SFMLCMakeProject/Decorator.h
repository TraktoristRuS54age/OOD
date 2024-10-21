#pragma once
#include "BaseShape.h"

class Decorator :public BaseShape 
{
protected:
	std::shared_ptr<BaseShape> shape;
	virtual void ComputeArea() = 0;
	virtual void ComputePerimeter() = 0;
	void SetPerimeter(float value);
	void SetArea(float value);
public:
	Decorator(std::shared_ptr<BaseShape> shape);
	void draw(sf::RenderWindow& window) const override;
	float GetArea() const;
	float GetPerimeter() const;
private:
	float perimeter = 0.0;
	float area = 0.0;
};