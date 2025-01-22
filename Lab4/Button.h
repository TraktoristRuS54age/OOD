#pragma once
#include "Library.h"
#include "Command.h"

class Button
{
public:
	Button(
		sf::Vector2f position, sf::Vector2f sizeRectangle,
		sf::Color buttonColor, Command* command, std::string text = "",
		int fontSize = 0,
		sf::Shape* shape = new sf::CircleShape,
		sf::Color textColor = sf::Color::Black
	);

	void Draw(sf::RenderWindow& window);
	void SetCommand(Command* command);
	bool CursorInButton(sf::Vector2f cursorPos) const;
	void PressButton();
private:
	sf::RectangleShape m_rectangle;
	sf::Text m_text;
	sf::Font m_font;
	sf::Shape* m_shape;
	Command* m_command;
};