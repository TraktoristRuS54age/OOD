#include "ShapeWriter.h"

ShapeWriter::ShapeWriter(const std::string& filename)
    :filename(filename)
{}

void ShapeWriter::writeShapes(const std::vector<std::shared_ptr<BaseDecorator>>& shapes) 
{
    std::fstream out(filename, std::ios::out);
    if (!out.is_open()) {
        std::cerr << "Не удалось открыть файл: " << filename << std::endl;
        return;
    }

    for (const auto& shape : shapes) {
        auto decorator = std::dynamic_pointer_cast<Decorator>(shape);
        if (decorator) {
            decorator->GetArea();
            decorator->GetPerimeter();
            out << decorator->GetName() << ": P=" << static_cast<int>(decorator->GetPerimeter()) << "; S=" << static_cast<int>(decorator->GetArea()) << "\n";
        }
    }

    out.close();
}