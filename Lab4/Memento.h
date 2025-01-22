#pragma once
#include "Library.h"
#include "Shapes\BaseDecorator.h"

class Memento
{
public:
	Memento(const std::vector<std::shared_ptr<BaseDecorator>>& state);
	std::vector<std::shared_ptr<BaseDecorator>> GetState() const;
private:
	std::vector<std::shared_ptr<BaseDecorator>> state;
};