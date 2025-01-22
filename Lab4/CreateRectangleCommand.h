#pragma once
#include "Command.h"
#include "Toolbar.h"

class CreateRectangleCommand : public Command
{
public:
	CreateRectangleCommand(Toolbar* toolbar);
	void Execute() const override;
private:
	Toolbar* m_toolbar;
};