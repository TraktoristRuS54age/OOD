#include "SetGreenColorCommand.h"

SetGreenColorCommand::SetGreenColorCommand(Toolbar* toolbar)
	: m_toolbar(toolbar)
{
}

void SetGreenColorCommand::Execute() const
{
	m_toolbar->SetColor(sf::Color::Green);
}
