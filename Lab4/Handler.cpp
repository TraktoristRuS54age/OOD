#include "Handler.h"

const float defaultX = 500;
const float defaultY = 400;

Handler::Handler(sf::RenderWindow& window) 
	: window(window)
{
}

void Handler::CreatingFigures(std::stringstream& ss)
{
	std::string figureType;
	ss >> figureType;

	if (figureType == "circle") {

		sf::Vector2f center;
		float radius;
		ss >> center.x >> center.y >> radius;
		auto circle = std::make_unique<Circle>(center, radius);
		m_figures.push_back(std::make_unique<Circle>(center, radius));
	}
	if (figureType == "rectangle") {
		std::vector<sf::Vector2f> points;
		points.resize(2);
		ss >> points[0].x >> points[0].y >> points[1].x >> points[1].y;
		m_figures.push_back(std::make_unique<Rectangle>(points[0], points[1]));
	}
	if (figureType == "triangle") {

		sf::Vector2f point1, point2, point3;
		ss >> point1.x >> point1.y >> point2.x >> point2.y >> point3.x >> point3.y;
		m_figures.push_back(std::make_unique<Triangle>(point1, point2, point3));
	}
}

void Handler::Draw()
{
	for (auto figure : m_figures) {
		figure->draw(window);
		figure->DrawSelection(window);
	}
}

void Handler::CreateCircle()
{
	sf::Vector2f center(defaultX, defaultY);
	float radius = 50;
	m_figures.push_back(std::make_unique<Circle>(center, radius));
}

void Handler::CreateRectangle()
{
	std::vector<sf::Vector2f> points;
	points.resize(2);
	points[0].x = 50;
	points[0].y = 50;
	points[1].x = 150;
	points[1].y = 150;
	m_figures.push_back(std::make_unique<Rectangle>(points[0], points[1]));
}

void Handler::CreateTriangle()
{
	sf::Vector2f point1(100, 10), point2, point3;
	point1 = sf::Vector2f(100, 10);
	point2 = sf::Vector2f(50, 110);
	point3 = sf::Vector2f(150, 110);
	m_figures.push_back(std::make_unique<Triangle>(point1, point2, point3));
}

void Handler::CopyFigures(std::vector<std::shared_ptr<BaseDecorator>> vecShapes)
{
	m_figures = vecShapes;
}

void Handler::SetCursorPosition(const sf::Vector2i& position)
{
	previousCursorPosition = cursorPosition;
	cursorPosition = position;
}

void Handler::SelectFigures()
{
	for (const auto& figure : m_figures) {
		sf::Vector2f cursorPositionFloat(cursorPosition);
		if (figure->Contains(cursorPositionFloat)) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
			{
				figure->Select();
			}
			else
			{
				for (auto& s : m_figures)
				{
					s->Deselect();
				}
				figure->Select();
				SaveState();
			}
		}
	}
}

void Handler::GroupFigures()
{
	SaveState();
	auto composite = std::make_shared<Composite>();
	for (auto& shape : m_figures)
	{
		if (shape->IsSelected())
		{
			composite->add(shape);
		}
	}
	m_figures.erase(std::remove_if(m_figures.begin(), m_figures.end(),
		[](const std::shared_ptr<BaseDecorator>& shape) { return shape->IsSelected(); }),
		m_figures.end());
	m_figures.push_back(composite);
}

void Handler::UngroupFigures()
{
	SaveState();
	std::vector<std::shared_ptr<BaseDecorator>> newShapes;
	for (auto& shape : m_figures)
	{
		if (auto composite = std::dynamic_pointer_cast<Composite>(shape))
		{
			for (auto& s : composite->GetShapes())
			{
				newShapes.push_back(s);
			}
		}
		else
		{
			newShapes.push_back(shape);
		}
	}
	m_figures = newShapes;
}

void Handler::Move()
{
	sf::Vector2i dragOffset;
	dragOffset = cursorPosition - previousCursorPosition;
	sf::Vector2f dragOffsetFloat(dragOffset);
	for (auto& shape : m_figures)
	{
		if (shape->IsSelected())
		{
			shape->Move(sf::Vector2f(dragOffsetFloat));
		}
	}
	previousCursorPosition = cursorPosition;
}

void Handler::SetFillColor(const sf::Color& color)
{
	SaveState();
	for (const auto& figure : m_figures) {
		if (figure->IsSelected()) {
			figure->SetFillColor(color);
		}
	}
}

void Handler::SetOutlineColor(const sf::Color& color)
{
	SaveState();//сам добавил
	for (const auto& figure : m_figures) {
		if (figure->IsSelected())
			figure->SetOutlineColor(color);
	}
}

void Handler::ChangeOutlineThickness(float thickness)
{
	if (globalFrame) {
		globalFrame->SetOutlineThickness(thickness);
	}
}

void Handler::SetThickness(const float& thickness)
{
	for (const auto& figure : m_figures) {
		if (figure->IsSelected()) {
			figure->SetOutlineThickness(thickness);
		}
	}
}

void Handler::SaveState()
{
	mementoStack.push_back(std::make_shared<Memento>(m_figures));
}

void Handler::Undo()
{
	if (!mementoStack.empty())
	{
		auto memento = mementoStack.back();
		mementoStack.pop_back();
		m_figures = memento->GetState();
	}
}
