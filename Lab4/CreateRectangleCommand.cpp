#include "CreateRectangleCommand.h"

CreateRectangleCommand::CreateRectangleCommand(Toolbar* toolbar)
	: m_toolbar(toolbar)
{
}

void CreateRectangleCommand::Execute() const
{
	m_toolbar->CreateRectangle();
}