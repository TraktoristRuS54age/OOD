#pragma once
#include "Command.h"
#include "Toolbar.h"

class CreateCircleCommand : public Command
{
public:
	CreateCircleCommand(Toolbar* toolbar);
	void Execute() const override;
private:
	Toolbar* m_toolbar;
};