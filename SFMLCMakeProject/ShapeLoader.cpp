#include "ShapeLoader.h"
#include "TriangleDecorator.h"
#include "RectangleDecorator.h"
#include "CircleDecoratorr.h"
#include "Composite.h"

ShapeLoader::ShapeLoader(const std::string& filename)
    : filename(filename)
{}

std::vector<std::shared_ptr<BaseDecorator>> ShapeLoader::loadShapes()
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Не удалось открыть файл: " << filename << std::endl;
        return {};
    }

    std::string line;
    std::vector<std::shared_ptr<BaseDecorator>> bodies;
    std::regex shapeRegex(R"((TRIANGLE|RECTANGLE|CIRCLE):\s*((?:P\d=\d+,\d+;\s*)*(?:P\d=\d+,\d+)?(?:C=\d+,\d+;\s*R=\d+)?)?)");
    std::smatch match;

    while (std::getline(file, line)) 
    {
        if (std::regex_search(line, match, shapeRegex)) 
        {
            std::string shapeType = match[1];
            std::string points = match[2];
            auto smallArray = extractPoints(points);

            if (shapeType == "TRIANGLE") {
                auto triangle = std::make_shared<Triangle>(
                    sf::Vector2f(smallArray[0].x, smallArray[0].y),
                    sf::Vector2f(smallArray[1].x, smallArray[1].y),
                    sf::Vector2f(smallArray[2].x, smallArray[2].y));
                triangle->setFillColor(sf::Color(255, 0, 0));

                std::shared_ptr<BaseDecorator> shape = std::make_shared<TriangleDecorator>(triangle);
                bodies.push_back(std::move(shape));
            }
            else if (shapeType == "RECTANGLE") {
                auto rectangle = std::make_shared<Rectangle>(
                    sf::Vector2f(smallArray[0].x, smallArray[0].y),
                    sf::Vector2f(smallArray[1].x, smallArray[1].y));
                rectangle->setFillColor(sf::Color(255, 117, 20));

                std::shared_ptr<BaseDecorator> shape = std::make_shared<RectangleDecorator>(rectangle);
                bodies.push_back(std::move(shape));
            }
            else if (shapeType == "CIRCLE") {
                auto circle = std::make_shared<Circle>(
                    sf::Vector2f(smallArray[0].x, smallArray[0].y),
                    smallArray[1].x);
                circle->setFillColor(sf::Color(237, 118, 14));

                std::shared_ptr<BaseDecorator> shape = std::make_shared<CircleDecorator>(circle);
                bodies.push_back(std::move(shape));
            }
        }
    }
    file.close();
    return bodies;
}

std::vector<Point> ShapeLoader::extractPoints(const std::string& points) {
    std::vector<Point> smallArray;
    std::istringstream pointsStream(points);
    std::string point;

    while (std::getline(pointsStream, point, ';')) 
    {
        if (point.empty()) continue; // Пропустить пустые строки

        std::regex pointRegex(R"((P\d=(\d+),\s*(\d+))|(C=(\d+),\s*(\d+))|(R=(\d+)))");
        std::smatch matchNumber;
        auto start = point.cbegin();

        while (std::regex_search(start, point.cend(), matchNumber, pointRegex)) 
        {
            Point p;
            if (matchNumber[2].matched) 
            { // RECTANGLE или TRIANGLE
                p.x = std::stoi(matchNumber[2].str());
                p.y = std::stoi(matchNumber[3].str());
            }
            else if (matchNumber[5].matched) 
            { // CIRCLE
                p.x = std::stoi(matchNumber[5].str());
                p.y = std::stoi(matchNumber[6].str());
            }
            else 
            { // RECTANGLE с R
                p.x = std::stoi(matchNumber[8].str());
                p.y = 0;
            }
            smallArray.push_back(p);
            start = matchNumber[0].second;
        }
    }
    return smallArray;
}

void ShapeLoader::mainS(std::vector<std::shared_ptr<BaseDecorator>>& shapes)
{
    sf::RenderWindow window(sf::VideoMode(1000, 600), "Poject by Daniil Cherepov");

    bool isDragging = false;
    sf::Vector2f dragStart;
    sf::Vector2f dragOffset;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2f mousePos = window.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y));
                    for (auto& shape : shapes)
                    {
                        if (shape->Contains(mousePos))
                        {
                            if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
                            {
                                shape->Select();
                                std::cout << "sel";
                            }
                            else
                            {
                                for (auto& s : shapes)
                                {
                                    s->Deselect();
                                }
                                shape->Select();
                                std::cout << shape->GetName() << " " << shape->IsSelected() << "; ";
                            }
                            isDragging = true;
                            dragStart = mousePos;
                            break;
                        }
                    }
                }
            }

            if (event.type == sf::Event::MouseButtonReleased)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    isDragging = false;
                }
            }

            if (event.type == sf::Event::MouseMoved)
            {
                if (isDragging)
                {
                    sf::Vector2f mousePos = window.mapPixelToCoords(sf::Vector2i(event.mouseMove.x, event.mouseMove.y));
                    dragOffset = mousePos - dragStart;
                    for (auto& shape : shapes)
                    {
                        if (shape->IsSelected())
                        {
                            shape->Move(dragOffset);
                            std::cout << "move";
                        }
                    }
                    dragStart = mousePos;
                }
            }

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::G && sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)) {
                    auto composite = std::make_shared<Composite>();
                    for (auto& shape : shapes)
                    {
                        if (shape->IsSelected())
                        {
                            composite->add(shape);
                        }
                    }
                    shapes.erase(std::remove_if(shapes.begin(), shapes.end(),
                        [](const std::shared_ptr<BaseDecorator>& shape) { return shape->IsSelected(); }),
                        shapes.end());
                    shapes.push_back(composite);
                }

                if (event.key.code == sf::Keyboard::U && sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)) {
                    std::vector<std::shared_ptr<BaseDecorator>> newShapes;
                    for (auto& shape : shapes) {
                        if (auto composite = std::dynamic_pointer_cast<Composite>(shape)) {
                            for (auto& s : composite->GetShapes()) {
                                newShapes.push_back(s);
                            }
                        }
                        else {
                            newShapes.push_back(shape);
                        }
                    }
                    shapes = newShapes;
                }
            }
        }
        window.clear();
        for (int i = 0; i < shapes.size(); i++)
        {
            shapes[i]->draw(window);
            if (shapes[i]->IsSelected()) {
                if (auto composite = dynamic_cast<const Composite*>(shapes[i].get())) {
                    composite->DrawSelection(window);
                }
                else {
                    shapes[i]->DrawSelection(window);
                }
            }
        }
        window.display();
    }
}