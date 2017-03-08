#include "Pesho.h"

Point::Point()
{
    x = 0;
    y = 0;
}

Point::Point(int newX, int newY) :x(newX)
{
    y = newY;
}

void Point::setX(int newX)
{
    x = newX;
}

void Point::setY(int newY)
{
    y = newY;
}

int Point::getX()
{
    return x;
}

int Point::getY()
{
    return y;
}
