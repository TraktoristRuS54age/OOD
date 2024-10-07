#include "ShapeWriter.h"

ShapeWriter::ShapeWriter(const std::string& filename)
    :filename(filename)
{}
void ShapeWriter::writeShapes(const std::vector<std::shared_ptr<BaseShape>>& shapes) 
{
    std::fstream out(filename, std::ios::out);
    if (!out.is_open()) {
        std::cerr << "Не удалось открыть файл: " << filename << std::endl;
        return;
    }

    for (const auto& shape : shapes) {
        std::string shapeType;
        if (dynamic_cast<Triangle*>(shape.get())) {
            shapeType = "TRIANGLE";
        }
        else if (dynamic_cast<Rectangle*>(shape.get())) {
            shapeType = "RECTANGLE";
        }
        else if (dynamic_cast<Circle*>(shape.get())) {
            shapeType = "CIRCLE";
        }
        out << shapeType << ": P=" << static_cast<int>(shape->GetPerimeter()) << "; S=" << static_cast<int>(shape->GetArea()) << "\n";
    }

    out.close();
}