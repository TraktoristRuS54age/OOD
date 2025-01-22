#pragma once
#include "C:\Users\Daniil.CHerepov\Desktop\ProjectsC++\OOD\OOD\Lab-4\SFMLCMakeProject4\SFMLCMakeProject4\Library.h"
#include "C:\Users\Daniil.CHerepov\Desktop\ProjectsC++\OOD\OOD\Lab-4\SFMLCMakeProject4\SFMLCMakeProject4\Point.h"
#include "C:\Users\Daniil.CHerepov\Desktop\ProjectsC++\OOD\OOD\Lab-4\SFMLCMakeProject4\SFMLCMakeProject4\Shapes\BaseDecorator.h"

class Rectangle : public BaseDecorator
{
public:
	Rectangle(sf::Vector2f point1, sf::Vector2f point2);
	Rectangle(const Rectangle& other);

	sf::Vector2f GetSize() const;

	void draw(sf::RenderWindow& window) const override;
	void DrawSelection(sf::RenderWindow& window) const override;

	bool Contains(const sf::Vector2f& point) const override;
	void Select() override;
	void Deselect() override;
	void Move(const sf::Vector2f& offset) override;
	std::string GetName() const override;

	void SetFillColor(const sf::Color& color) override;
	void SetOutlineColor(const sf::Color& color) override;
	void SetOutlineThickness(float thickness) override;

	//для Memento
	std::shared_ptr<BaseDecorator> Clone() const override
	{
		return std::make_shared<Rectangle>(*this);
	}
private:
	std::vector<sf::Vector2f> points;
	sf::RectangleShape shape;
	std::string shapeName;
};