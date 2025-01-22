#include "FillOutlineCommand.h"

FillOutlineCommand::FillOutlineCommand(Toolbar* toolbar)
	: m_toolbar(toolbar)
{
}

void FillOutlineCommand::Execute() const
{
	m_toolbar->FillOutline();
}
