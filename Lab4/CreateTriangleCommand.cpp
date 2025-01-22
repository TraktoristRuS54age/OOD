#include "CreateTriangleCommand.h"

CreateTriangleCommand::CreateTriangleCommand(Toolbar* toolbar)
	:m_toolbar(toolbar)
{
}

void CreateTriangleCommand::Execute() const
{
	m_toolbar->CreateTriangle();
}
