#pragma once
#include "Library.h"
#include "Triangle.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Decorator.h"

class ShapeWriter
{
public:
    ShapeWriter(const std::string& filename);
    void writeShapes(const std::vector<std::unique_ptr<Decorator>>& shapes);
private:
    std::string filename;
};