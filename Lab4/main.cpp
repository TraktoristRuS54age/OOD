#include "Library.h"

#include "Point.h"
#include ".\Shapes/Triangle\Triangle.h"
#include ".\Shapes/Circle\Circle.h"
#include ".\Shapes\Rectangle\Rectangle.h"
#include "ShapeLoader.h"
#include "ShapeWriter.h"
#include "Composite.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1500, 1000), "Poject by Daniil Cherepov");
    const std::string filenmae = "input.txt";
    ShapeLoader& operations = ShapeLoader::GetInstance(filenmae, window);
    auto shapes = operations.loadShapes();

    operations.mainS(shapes);

    ShapeWriter writer("output.txt");
    writer.writeShapes(shapes);
    return 0;
}