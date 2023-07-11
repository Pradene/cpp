#ifndef POINT
#define POINT

#include "Fixed.hpp"

class Point
{
public:
    Point();
    Point(float x, float y);
    Point(const Point &p);
    ~Point();

    Point   &operator=(const Point &p);

    float   getX();
    float   getY();

private:
    Fixed   _x;
    Fixed   _y;
};

bool    bsp(Point const a, Point const b, Point const c, Point const point);

#endif