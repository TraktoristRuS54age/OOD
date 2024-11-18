#include "ShapeWriter.h"

ShapeWriter::ShapeWriter(const std::string& filename)
    :filename(filename)
{}

void ShapeWriter::writeShapes(const std::vector<std::unique_ptr<Decorator>>& shapes) 
{
    std::fstream out(filename, std::ios::out);
    if (!out.is_open()) {
        std::cerr << "Не удалось открыть файл: " << filename << std::endl;
        return;
    }

    for (const auto& shape : shapes) {
        out << shape->GetName() << ": P=" << static_cast<int>(shape->GetPerimeter()) << "; S=" << static_cast<int>(shape->GetArea()) << "\n";
    }

    out.close();
}