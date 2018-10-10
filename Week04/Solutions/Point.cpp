#include <iostream>
#include "Point.h"

Point::Point()
{
    this -> x = 0;
    this -> y = 0;
}

Point::Point(int x, int y)
{
    this -> x = x;
    this -> y = y;
}

 int Point::getX() const
{
    return this -> x;
}

int Point::getY() const
{
    return this -> y;
}

void Point::setX(int x)
{
    this -> x = x;
}

void Point::setY(int y)
{
    this-> y = y;
}

bool Point::operator<(const Point& rl)
{
    return this -> x < rl.x && this ->y < rl.y;
}
bool Point::operator>(const Point& rl)
{
    return this -> x > rl.x && this -> y > rl.y;
}
bool Point::operator==(const Point& rl)
{
    return ! (*this < rl) && !(*this > rl);
}
std::ostream& operator<<(std::ostream& os, Point point)
{
    os << "(" << point.x << " , " << point.y << ")";
}
/*
int main()
{
    Point p1(1,2);
    Point p2(1,2);
    std::cout << p1;
    Point p3(3,6);
    std::cout << (p1 == p2)<<std::endl;
     std::cout << (p1 < p3)<<std::endl;
     std::cout << (p1 < p2)<<std::endl;
    return 0;
}*/