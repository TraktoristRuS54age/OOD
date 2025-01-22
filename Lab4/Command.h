#pragma once
#include "Library.h"

class Command
{
public:
	virtual void Execute() const = 0;
};