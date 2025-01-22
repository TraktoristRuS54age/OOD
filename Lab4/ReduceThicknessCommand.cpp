#include "ReduceThicknessCommand.h"

ReduceThicknessCommand::ReduceThicknessCommand(Toolbar* toolbar)
	: m_toolbar(toolbar)
{
}

void ReduceThicknessCommand::Execute() const
{
	m_toolbar->ReduceOutlineThickness();
}
