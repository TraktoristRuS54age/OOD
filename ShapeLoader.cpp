#include "ShapeLoader.h"
#include "TriangleDecorator.h"
#include "RectangleDecorator.h"
#include "CircleDecoratorr.h"

ShapeLoader::ShapeLoader(const std::string& filename)
    : filename(filename)
{}

std::vector<std::unique_ptr<Decorator>> ShapeLoader::loadShapes()
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Не удалось открыть файл: " << filename << std::endl;
        return {};
    }

    std::string line;
    std::vector<std::unique_ptr<Decorator>> bodies;
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

                std::unique_ptr<Decorator> shape = std::make_unique<TriangleDecorator>(triangle);
                bodies.push_back(std::move(shape));
            }
            else if (shapeType == "RECTANGLE") {
                auto rectangle = std::make_shared<Rectangle>(
                    sf::Vector2f(smallArray[0].x, smallArray[0].y),
                    sf::Vector2f(smallArray[1].x, smallArray[1].y));
                rectangle->setFillColor(sf::Color(255, 117, 20));

                std::unique_ptr<Decorator> shape = std::make_unique<RectangleDecorator>(rectangle);
                bodies.push_back(std::move(shape));
            }
            else if (shapeType == "CIRCLE") {
                auto circle = std::make_shared<Circle>(
                    sf::Vector2f(smallArray[0].x, smallArray[0].y),
                    smallArray[1].x);
                circle->setFillColor(sf::Color(237, 118, 14));

                std::unique_ptr<Decorator> shape = std::make_unique<CircleDecorator>(circle);
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