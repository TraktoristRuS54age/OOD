#pragma once
#include "BaseShape.h"

class Decorator :public BaseShape {
protected:
	BaseShape* shape;
public:
	explicit Decorator(BaseShape* shape) 
		:shape(shape)
	{}
	virtual ~Decorator() { delete shape;  }
};