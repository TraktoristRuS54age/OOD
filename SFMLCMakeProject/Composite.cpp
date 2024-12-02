#include "Composite.h"

void Composite::add(std::shared_ptr<BaseDecorator> shape)
{
	shapes.push_back(shape);
}

void Composite::remove(std::shared_ptr<BaseDecorator> shape)
{
    shapes.erase(std::remove(shapes.begin(), shapes.end(), shape), shapes.end());
}

void Composite::draw(sf::RenderWindow& window) const {
    for (const auto& shape : shapes) {
        shape->draw(window);
    }
}

bool Composite::Contains(const sf::Vector2f& point) const {
    for (const auto& shape : shapes) {
        if (shape->Contains(point)) {
            return true;
        }
    }
    return false;
}

void Composite::Select() {
    m_isSelected = true;
    for (auto& shape : shapes)
    {
        shape->Select();
        std::cout << shape->GetName() << " " << shape->IsSelected() << "; " << m_isSelected << "\n";
    }
}

void Composite::Deselect()
{
    m_isSelected = false;
    for (auto& shape : shapes)
    {
        shape->Deselect();
    }
}

void Composite::DrawSelection(sf::RenderWindow& window) const {
    if (m_isSelected) {
        for (const auto& shape : shapes) {
            shape->DrawSelection(window);
        }
    }
}

void Composite::Move(const sf::Vector2f& offset)
{
    for (auto& shape : shapes)
    {
        shape->Move(offset);
    }
}

std::string Composite::GetName() const
{
    return "Composite";
}

std::vector<std::shared_ptr<BaseDecorator>> Composite::GetShapes() const
{
    return shapes;
}