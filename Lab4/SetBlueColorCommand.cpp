#include "SetBlueColorCommand.h"

SetBlueColorCommand::SetBlueColorCommand(Toolbar* toolbar)
	: m_toolbar(toolbar)
{
}

void SetBlueColorCommand::Execute() const
{
	m_toolbar->SetColor(sf::Color::Blue);
}
