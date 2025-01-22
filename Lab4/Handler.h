#pragma once
#include "Library.h"
#include "./Shapes/BaseDecorator.h"
#include ".\Shapes/Triangle\Triangle.h"
#include ".\Shapes/Circle\Circle.h"
#include ".\Shapes\Rectangle\Rectangle.h"
#include "Composite.h"
#include "Memento.h"

class Handler
{
public:
	Handler(sf::RenderWindow& window);
	void CreatingFigures(std::stringstream& ss);
	void Draw();
	void CreateCircle();
	void CreateRectangle();
	void CreateTriangle();
	void CopyFigures(std::vector<std::shared_ptr<BaseDecorator>> vecShapes);
	void SetCursorPosition(const sf::Vector2i& position);

	void SelectFigures();
	void GroupFigures();
	void UngroupFigures();

	void Move();
	void SetFillColor(const sf::Color& color);
	void SetOutlineColor(const sf::Color& color);
	void ChangeOutlineThickness(float thickness);
	void SetThickness(const float& thickness);

	std::vector<BaseDecorator*> GetFigures() const;

	//Методы для работы Undo
	void SaveState();
	void Undo();
private:
	std::vector<std::shared_ptr<BaseDecorator>> m_figures;
	std::shared_ptr<BaseDecorator> globalFrame = nullptr;
	sf::RenderWindow& window;
	sf::Vector2i cursorPosition, previousCursorPosition;

	//Стек для Undo
	std::vector<std::shared_ptr<Memento>> mementoStack;
};