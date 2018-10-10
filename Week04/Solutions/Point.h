#pragma once
#include <iostream>

class Point
{
public:
    Point();
    Point(int x, int y);
    int getX() const;
    int getY() const;
    void setX(int x);
    void setY(int y);
    bool operator<(const Point& rl);
    bool operator>(const Point& rl);
    bool operator==(const Point& rl);
    friend std::ostream& operator<<(std::ostream& os, Point point);
private:
    int x;
    int y;
};