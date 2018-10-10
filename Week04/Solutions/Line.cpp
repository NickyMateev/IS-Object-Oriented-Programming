#include "Line.h"

Line::Line()
{
    this -> x = Point();
    this -> y = Point();
}

Line::Line(Point p1, Point p2)
{
    this -> x = p1;
    this -> y = p2;
}

Point Line::getX() const
{
    return this -> x;
}

Point Line::getY() const
{
    return this -> y;
}

void Line::setX(Point p)
{
    this -> x = p;
}

void Line::setY(Point p)
{
    this -> y = p;
}

int Line::getLength()
{
    return std::sqrt((y.getX() - x.getX())*(y.getX() - x.getX()) + (y.getY() - x.getY())*(y.getY() - x.getY()));
}

bool Line::operator<(Line rl)
{
    return this -> getLength() < rl.getLength();
}

bool Line::operator>(Line rl)
{
    return this -> getLength() > rl.getLength();
}

bool Line::operator==(Line rl)
{
    return this -> getLength() == rl.getLength();
}

std::ostream& operator<<(std::ostream& os, Line l)
    {
        os << "X ("<<l.x.getX() << " , "<< l.x.getY() << ")" << std::endl;
        os << "Y ("<<l.y.getX() << " , "<< l.y.getY() << ")" << std::endl;
    }


int main()
{
    Point p1(1,2);
    Point p2(1,3);
    Line l(p1, p2);
    Line l2(l);
    std::cout << (l < l2);
    return 0;
}