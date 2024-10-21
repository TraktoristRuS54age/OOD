#include "CircleDecoratorr.h"
#define _USE_MATH_DEFINES
#include <math.h>

CircleDecorator::CircleDecorator(std::shared_ptr<Circle> circle)
    :Decorator(circle)
{
    ComputePerimeter();
    ComputeArea();
}

void CircleDecorator::ComputeArea()
{
    float radius = std::dynamic_pointer_cast<Circle>(shape)->GetRadius();
    SetArea(M_PI * radius * radius);
}

void CircleDecorator::ComputePerimeter()
{
    float radius = std::dynamic_pointer_cast<Circle>(shape)->GetRadius();
    SetPerimeter(2 * M_PI * radius);
}