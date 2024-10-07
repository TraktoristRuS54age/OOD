#include "Library.h"

#include "Point.h"
#include "Triangle.h"
#include "Circle.h"
#include "Rectangle.h"
#include "ShapeLoader.h"
#include "ShapeWriter.h"


//можно юзать адаптер вместо декоратора
int main()
{
    ShapeLoader loader("input.txt");
    auto shapes = loader.loadShapes();

    sf::RenderWindow window(sf::VideoMode(1000, 600), "Poject by Daniil Cherepov");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        for (const auto& shape : shapes)
        {
            window.draw(*shape);
        }
        window.display();
    }

    ShapeWriter writer("output.txt");
    writer.writeShapes(shapes);
    return 0;
}