#pragma once
#include "Library.h"
#include "BaseDecorator.h"

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

    std::vector<std::shared_ptr<BaseDecorator>> GetShapes() const;
private:
    std::vector<std::shared_ptr<BaseDecorator>> shapes;
};