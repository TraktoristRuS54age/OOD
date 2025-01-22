#pragma once
#include "Library.h"
#include ".\Shapes/Triangle\Triangle.h"
#include ".\Shapes/Circle\Circle.h"
#include ".\Shapes\Rectangle\Rectangle.h"
#include "Decorator.h"
#include "./Shapes/BaseDecorator.h"

class ShapeWriter
{
public:
    ShapeWriter(const std::string& filename);
    void writeShapes(const std::vector<std::shared_ptr<BaseDecorator>>& shapes);
private:
    std::string filename;
};