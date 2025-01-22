#pragma once
#include "Command.h"
#include "Toolbar.h"

class DragAndDropCommand : public Command
{
public:
	DragAndDropCommand(Toolbar* toolbar);
	void Execute() const override;
private: 
	Toolbar* m_toolbar;
};