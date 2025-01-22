#pragma once
#include "Library.h"
#include "Point.h"
#include ".\Shapes/Triangle\Triangle.h"
#include ".\Shapes/Circle\Circle.h"
#include ".\Shapes\Rectangle\Rectangle.h"
#include "Decorator.h"
#include "./Shapes/BaseDecorator.h"
#include "Toolbar.h"

class ShapeLoader {
public:
    static ShapeLoader& GetInstance(const std::string& filename,sf::RenderWindow& window);
    std::vector<std::shared_ptr<BaseDecorator>> loadShapes();
    void mainS(std::vector<std::shared_ptr<BaseDecorator>>& bodies);
private:
    ShapeLoader(const std::string& filename,sf::RenderWindow& window);
    ShapeLoader(const ShapeLoader&) = delete;
    ShapeLoader& operator=(const ShapeLoader&) = delete;

    sf::RenderWindow& m_window;
	std::string filename;
    Toolbar* m_toolbar;
    Handler* m_handler;
    std::vector<Point> extractPoints(const std::string& points);
    void DrawHandler();
};