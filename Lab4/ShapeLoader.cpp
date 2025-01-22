#include "ShapeLoader.h"
#include "TriangleDecorator.h"
#include "RectangleDecorator.h"
#include "CircleDecoratorr.h"
#include "Composite.h"
#include "DragAndDropState.h"

ShapeLoader& ShapeLoader::GetInstance(const std::string& filename,sf::RenderWindow& window)
{
    static ShapeLoader instance(filename, window);
    return instance;
}

ShapeLoader::ShapeLoader(const std::string& filename,sf::RenderWindow& window)
    : filename(filename), m_window(window)
{
    m_handler = new Handler(window);
    m_toolbar = new Toolbar(new DragAndDropState(), window, m_handler);
}

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

                bodies.push_back(std::move(triangle));
            }
            else if (shapeType == "RECTANGLE") {
                auto rectangle = std::make_shared<Rectangle>(
                    sf::Vector2f(smallArray[0].x, smallArray[0].y),
                    sf::Vector2f(smallArray[1].x, smallArray[1].y));

                bodies.push_back(std::move(rectangle));
            }
            else if (shapeType == "CIRCLE") {
                auto circle = std::make_shared<Circle>(
                    sf::Vector2f(smallArray[0].x, smallArray[0].y),
                    smallArray[1].x);

                bodies.push_back(std::move(circle));
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
        if (point.empty()) continue;

        std::regex pointRegex(R"((P\d=(\d+),\s*(\d+))|(C=(\d+),\s*(\d+))|(R=(\d+)))");
        std::smatch matchNumber;
        auto start = point.cbegin();

        while (std::regex_search(start, point.cend(), matchNumber, pointRegex)) 
        {
            Point p;
            if (matchNumber[2].matched) 
            { // TRIANGLE
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
                p.y = 0.0;
            }
            smallArray.push_back(p);
            start = matchNumber[0].second;
        }
    }
    return smallArray;
}

void ShapeLoader::mainS(std::vector<std::shared_ptr<BaseDecorator>>& shapes)
{
    bool isDragging = false;
    sf::Vector2f dragStart;
    sf::Vector2f dragOffset;
    m_handler->CopyFigures(shapes);
    while (m_window.isOpen())
    {
        sf::Event event;
        while (m_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                m_window.close();

            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mousePos(event.mouseButton.x, event.mouseButton.y);
                    m_handler->SetCursorPosition(mousePos);
                    m_toolbar->SetCursorPosition(mousePos);
                    m_toolbar->PressToolButton();

                    if (typeid(*m_toolbar->GetState()) == typeid(DragAndDropState))
                    {
                        isDragging = true;
                        m_handler->SelectFigures();
                    }
                    else {
                        m_handler->SelectFigures();
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
                    sf::Vector2i mousePos(event.mouseMove.x, event.mouseMove.y);
                    m_handler->SetCursorPosition(mousePos);
                    m_handler->Move();
                }
            }

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::G && sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
                {
                    m_handler->GroupFigures();
                }

                if (event.key.code == sf::Keyboard::U && sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
                {
                    m_handler->UngroupFigures();
                }
            }

            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Z && sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
                {
                    std::cout << "lctrl + z" << std::endl;
                    m_handler->Undo();
                }
            }
        }
        m_window.clear();
        DrawHandler();
        m_window.display();
    }
}

void ShapeLoader::DrawHandler()
{
    m_handler->Draw();
    m_toolbar->Draw();
}