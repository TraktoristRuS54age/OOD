#pragma once
#include "Command.h"
#include "Toolbar.h"

class FillOutlineCommand : public Command
{
public:
	FillOutlineCommand(Toolbar* toolbar);
	void Execute() const override;
private:
	Toolbar* m_toolbar;
};