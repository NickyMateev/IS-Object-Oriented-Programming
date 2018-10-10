#pragma once 
#include <iostream>
#include "Point.h"
#include <cmath>

class Line{

private:
    Point x;
    Point y;
public:
    Line();
    Line(Point p1, Point p2);
    Point getX() const;
    Point getY() const;
    void setX(Point p);
    void setY(Point p);
    int getLength();

    friend std::ostream& operator<<(std::ostream& os, Line l);

    bool operator<(Line rl);
    bool operator>(Line rl);
    bool operator==(Line rl);
};