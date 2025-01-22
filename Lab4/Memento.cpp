#include "Memento.h"

Memento::Memento(const std::vector<std::shared_ptr<BaseDecorator>>& state)
{
	for (const auto& figure : state)
	{
		this->state.push_back(figure -> Clone());
	}
}

std::vector<std::shared_ptr<BaseDecorator>> Memento::GetState() const
{
	return state;
}
