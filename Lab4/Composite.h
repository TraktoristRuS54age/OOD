#pragma once
#include "Library.h"
#include "./Shapes/BaseDecorator.h"

class Composite: public BaseDecorator
{
public:
    void add(std::shared_ptr<BaseDecorator> shape);
    void remove(std::shared_ptr<BaseDecorator> shape);

    void draw(sf::RenderWindow& window) const override;
    void DrawSelection(sf::RenderWindow& window) const override;

    bool Contains(const sf::Vector2f& point) const override;
    void Select() override;
    void Deselect() override;
    void Move(const sf::Vector2f& offset);
    virtual  std::string GetName() const;

    void SetFillColor(const sf::Color& color) override;
    void SetOutlineColor(const sf::Color& color) override;
    void SetOutlineThickness(float thickness) override;

    std::vector<std::shared_ptr<BaseDecorator>> GetShapes() const;

    //Äëÿ Memento
    std::shared_ptr<BaseDecorator> Clone() const override {
        auto cloned = std::make_shared<Composite>();
        for (const auto& shape : shapes) {
            cloned->add(shape->Clone());
        }
        cloned->m_isSelected = m_isSelected;
        return cloned;
    }
private:
    std::vector<std::shared_ptr<BaseDecorator>> shapes;
};