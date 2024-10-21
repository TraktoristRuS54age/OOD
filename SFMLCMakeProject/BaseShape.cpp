#include "BaseShape.h"

BaseShape::BaseShape(const std::string& name)
	:shapeName(name)
{
}

std::string BaseShape::GetName()
{
	return shapeName;
}