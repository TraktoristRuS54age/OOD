#include "DragAndDropCommand.h"

DragAndDropCommand::DragAndDropCommand(Toolbar* toolbar)
	: m_toolbar(toolbar)
{
}

void DragAndDropCommand::Execute() const
{
	m_toolbar->DragAndDrop();
}
