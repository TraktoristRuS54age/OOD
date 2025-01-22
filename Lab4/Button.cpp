#include "Button.h"


Button::Button(sf::Vector2f position, sf::Vector2f sizeRectangle, 
	sf::Color buttonColor, Command* command, std::string text, 
	int fontSize, sf::Shape* shape, sf::Color textColor
	) : m_command(command), m_shape(shape)
{
    m_rectangle.setPosition(position);
    m_rectangle.setSize(sizeRectangle);
    m_rectangle.setFillColor(buttonColor);

    if (m_font.loadFromFile("arial.ttf")) {
        m_text.setFont(m_font);
        m_text.setString(text);
        m_text.setFillColor(textColor);
        m_text.setCharacterSize(fontSize);
        m_text.setPosition(position);
    }
}

void Button::Draw(sf::RenderWindow& window)
{
    window.draw(m_rectangle);
    window.draw(m_text);
    window.draw(*m_shape);
}

void Button::SetCommand(Command* command)
{
    m_command = command;
}

bool Button::CursorInButton(sf::Vector2f cursorPos) const
{
    return m_rectangle.getGlobalBounds().contains(cursorPos);
}

void Button::PressButton()
{
    m_command->Execute();
}
