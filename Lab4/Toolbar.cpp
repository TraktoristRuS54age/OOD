#include "Library.h"
#include "Toolbar.h"
#include "State.h"
#include "Button.h"
#include "FillShapeState.h"
#include "DragAndDropState.h"
#include "FillOutlineState.h"
#include "CreateCircleCommand.h"
#include "CreateRectangleCommand.h"
#include "CreateTriangleCommand.h"
#include "DragAndDropCommand.h"
#include "FillShapeCommand.h"
#include "FillOutlineCommand.h"
#include "SetRedColorCommand.h"
#include "SetGreenColorCommand.h"
#include "SetBlueColorCommand.h"
#include "ReduceThicknessCommand.h"
#include "AddOutlineThicknessCommand.h"

const int BTN_WIDTHS = 20;
const int BTN_HEIGHTS = 80;
const int BTN_WIDTH = 36;
const int BTN_HEIGHT = 60;

Toolbar::Toolbar(State* state, sf::RenderWindow& window, Handler* figureHandler)
	:window(window), figureHandler(figureHandler), m_state(state)
{
    m_buttons.push_back(new Button(sf::Vector2f(643, 10), sf::Vector2f(BTN_HEIGHTS, BTN_WIDTHS), sf::Color::White, new DragAndDropCommand(this), "Drag&Drop", 20));
    m_buttons.push_back(new Button(sf::Vector2f(851, 10), sf::Vector2f(BTN_HEIGHTS, BTN_WIDTHS), sf::Color::White, new FillShapeCommand(this), "Fill shape", 20));
    m_buttons.push_back(new Button(sf::Vector2f(1064, 10), sf::Vector2f(BTN_HEIGHTS, BTN_WIDTHS), sf::Color::White, new FillOutlineCommand(this), "Fill outline", 20));
    //m_buttons.push_back(new Button(Vector2f(1287, 10), Vector2f(BTN_HEIGHTS, BTN_WIDTHS), Color::White, new ChangeOutlineThicknessCommand(this), "Change thickness", 20));

    m_buttons.push_back(new Button(sf::Vector2f(19, 68), sf::Vector2f(BTN_HEIGHT, BTN_WIDTH), sf::Color::Red, new SetRedColorCommand(this)));
    m_buttons.push_back(new Button(sf::Vector2f(143, 68), sf::Vector2f(BTN_HEIGHT, BTN_WIDTH), sf::Color::Green, new SetGreenColorCommand(this)));
    m_buttons.push_back(new Button(sf::Vector2f(267, 68), sf::Vector2f(BTN_HEIGHT, BTN_WIDTH), sf::Color::Blue, new SetBlueColorCommand(this)));

    m_buttons.push_back(new Button(sf::Vector2f(350, 68), sf::Vector2f(BTN_HEIGHT, BTN_WIDTH), sf::Color::White, new ReduceThicknessCommand(this)));
    m_buttons.push_back(new Button(sf::Vector2f(430, 68), sf::Vector2f(BTN_HEIGHT, BTN_WIDTH), sf::Color::White, new AddOutlineThicknessCommand(this)));

    m_buttons.push_back(new Button(sf::Vector2f(19, 10), sf::Vector2f(BTN_HEIGHTS, BTN_WIDTHS), sf::Color::White, new CreateCircleCommand(this), "Create Circle", 20));
    m_buttons.push_back(new Button(sf::Vector2f(435, 10), sf::Vector2f(BTN_HEIGHTS, BTN_WIDTHS), sf::Color::White, new CreateRectangleCommand(this), "Create Rectangle", 20));
    m_buttons.push_back(new Button(sf::Vector2f(227, 10), sf::Vector2f(BTN_HEIGHTS, BTN_WIDTHS), sf::Color::White, new CreateTriangleCommand(this), "Create Triangle", 20));
}

void Toolbar::SetCursorPosition(const sf::Vector2i& position)
{
    cursorPosition = position;
}

void Toolbar::AddOutlineThickness()
{
    outlineThickness++;
    figureHandler->SetThickness(outlineThickness);
}

void Toolbar::ReduceOutlineThickness()
{
    if (outlineThickness > 0.0f) {
        outlineThickness--;
    };
    figureHandler->SetThickness(outlineThickness);
}

void Toolbar::DragAndDrop()
{
    if (m_state) {
        m_state->DragAndDrop(this);
    }
}

void Toolbar::FillShape()
{
    if (m_state) {
        m_state->FillShape(this);
    }
}

void Toolbar::FillOutline()
{
    if (m_state) {
        m_state->FillOutline(this);
    }
}

void Toolbar::SetColor(const sf::Color& newColor)
{
    if (typeid(*m_state) == typeid(FillShapeState))
    {
        color = newColor;
        figureHandler->SetFillColor(color);
        std::cout << "Color set to: " << color.toInteger() << std::endl;
    }
    else if (typeid(*m_state) == typeid(FillOutlineState))
    {
        color = newColor;
        figureHandler->SetOutlineColor(color);
    }
}

void Toolbar::CreateRectangle()
{
    figureHandler->CreateRectangle();
}

void Toolbar::CreateTriangle()
{
    figureHandler->CreateTriangle();
}

void Toolbar::CreateCircle()
{
    figureHandler->CreateCircle();
}

void Toolbar::SetState(State* state)
{
    m_state = state;
}

State* Toolbar::GetState() const
{
    return m_state;
}

sf::Color Toolbar::GetColor() const
{
    return color;
}

float Toolbar::GetOutlineThickness() const
{
    return outlineThickness;
}

bool Toolbar::PressToolButton() const
{
    for (auto button : m_buttons) {
        sf::Vector2f cursorPositionFloat(cursorPosition);
        if (button->CursorInButton(cursorPositionFloat)) {
            button->PressButton();
            return true;
        }
    }

    return false;
}

void Toolbar::Draw()
{
    for (auto button : m_buttons) {
        button->Draw(window);
    }
}
