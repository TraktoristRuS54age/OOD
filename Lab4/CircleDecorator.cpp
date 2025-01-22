#include "CircleDecoratorr.h"
#define _USE_MATH_DEFINES
#include <math.h>

CircleDecorator::CircleDecorator(std::shared_ptr<BaseDecorator> circle)
    :Decorator(std::dynamic_pointer_cast<BaseDecorator>(circle))
{
    ComputePerimeter();
    ComputeArea();
}

void CircleDecorator::ComputeArea()
{
    double radius = std::dynamic_pointer_cast<Circle>(shape)->GetRadius();
    SetArea(M_PI * radius * radius);
}

void CircleDecorator::ComputePerimeter()
{
    double radius = std::dynamic_pointer_cast<Circle>(shape)->GetRadius();
    SetPerimeter(2 * M_PI * radius);
}