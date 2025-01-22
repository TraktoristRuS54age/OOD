#include "SetRedColorCommand.h"

SetRedColorCommand::SetRedColorCommand(Toolbar* toolbar)
	: m_toolbar(toolbar)
{
}

void SetRedColorCommand::Execute() const
{
	m_toolbar->SetColor(sf::Color::Red);
}
