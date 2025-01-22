#pragma once
#include "Command.h"
#include "Toolbar.h"

class SetBlueColorCommand : public Command
{
public: 
	SetBlueColorCommand(Toolbar* toolbar);
	void Execute() const override;
private:
	Toolbar* m_toolbar;
};