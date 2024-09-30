#pragma once
#include "Library.h"
#include "BaseShape.h"
#include "Point.h"
#include "Triangle.h"
#include "Circle.h"
#include "Rectangle.h"

class ShapeLoader {
public:
    ShapeLoader(const std::string& filename);
    std::vector<std::shared_ptr<BaseShape>> loadShapes();
private:
	std::string filename;
    std::vector<Point> extractPoints(const std::string& points);
};