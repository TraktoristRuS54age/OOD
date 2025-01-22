#include "FillShapeCommand.h"

FillShapeCommand::FillShapeCommand(Toolbar* toolbar)
	: m_toolbar(toolbar)
{
}

void FillShapeCommand::Execute() const
{
	m_toolbar->FillShape();
}