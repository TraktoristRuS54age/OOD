#pragma once
#include "Command.h"
#include "Toolbar.h"

class CreateTriangleCommand : public Command
{
public:
	CreateTriangleCommand(Toolbar* toolbar);
	void Execute() const override;
private:
	Toolbar* m_toolbar;
};