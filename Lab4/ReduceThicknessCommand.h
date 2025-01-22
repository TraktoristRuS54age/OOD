#pragma once
#include "Command.h"
#include "Toolbar.h"

class ReduceThicknessCommand : public Command
{
public:
	ReduceThicknessCommand(Toolbar* toolbar);
	void Execute() const override;
private:
	Toolbar* m_toolbar;
};