#pragma once
#include "Command.h"
#include "Toolbar.h"

class SetGreenColorCommand : public Command
{
public:
	SetGreenColorCommand(Toolbar* toolbar);
	void Execute() const override;
private:
	Toolbar* m_toolbar;
};