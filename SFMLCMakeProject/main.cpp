#include "Library.h"

#include "Point.h"
#include "Triangle.h"
#include "Circle.h"
#include "Rectangle.h"
#include "ShapeLoader.h"
#include "ShapeWriter.h"
#include "Composite.h"

int main()
{
    ShapeLoader loader("input.txt");
    auto shapes = loader.loadShapes();

    loader.mainS(shapes);

    ShapeWriter writer("output.txt");
    writer.writeShapes(shapes);
    return 0;
}