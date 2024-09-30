#pragma once
#include "Library.h"
#include "Triangle.h"
#include "Circle.h"
#include "Rectangle.h"

class ShapeWriter
{
public:
    ShapeWriter(const std::string& filename);
	//	:filename(filename)
	//{}
    void writeShapes(const std::vector<std::shared_ptr<BaseShape>>& shapes);
    //{
    //    std::fstream out(filename, std::ios::out);
    //    if (!out.is_open()) {
    //        std::cerr << "Не удалось открыть файл: " << filename << std::endl;
    //        return;
    //    }

    //    for (const auto& shape : shapes) {
    //        std::string shapeType;
    //        if (dynamic_cast<Triangle*>(shape.get())) {
    //            shapeType = "TRIANGLE";
    //        }
    //        else if (dynamic_cast<Rectangle*>(shape.get())) {
    //            shapeType = "RECTANGLE";
    //        }
    //        else if (dynamic_cast<Circle*>(shape.get())) {
    //            shapeType = "CIRCLE";
    //        }
    //        out << shapeType << ": P=" << shape->GetPerimeter() << "; S=" << shape->GetArea() << "\n";
    //    }

    //    out.close();
    //}
private:
    std::string filename;
};