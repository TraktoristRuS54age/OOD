#pragma once
#include "Command.h"
#include "Toolbar.h"

class FillShapeCommand : public Command
{
public:
	FillShapeCommand(Toolbar* toolbar);
	void Execute() const override;
private:
	Toolbar* m_toolbar;
};