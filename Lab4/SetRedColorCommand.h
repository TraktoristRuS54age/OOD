#pragma once
#include "Command.h"
#include "Toolbar.h"

class SetRedColorCommand :public Command
{
public: 
	SetRedColorCommand(Toolbar* toolbar);
	void Execute() const override;
private:
	Toolbar* m_toolbar;
};