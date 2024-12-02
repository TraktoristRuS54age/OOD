#pragma once
#include "Library.h"
#include "Triangle.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Decorator.h"
#include "BaseDecorator.h"

class ShapeWriter
{
public:
    ShapeWriter(const std::string& filename);
    void writeShapes(const std::vector<std::shared_ptr<BaseDecorator>>& shapes);
private:
    std::string filename;
};