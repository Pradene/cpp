#include "Point.hpp"

// CONSTRCUTORS
Point::Point()
{
    _x = 0;
    _y = 0;
}

Point::Point(float x, float y)
{
    _x = x;
    _y = y;
}

Point::Point(const Point &p)
{
    *this = p;
}



// DESTRUCTORS
Point::~Point()
{

}



// OPERATORS
Point   &Point::operator=(const Point &p)
{
    _x = p._x;
    _y = p._y;
    return (*this);
}



// MEMBER FUNCTIONS
float   Point::getX()
{
    return (_x.toFloat());
}

float   Point::getY()
{
    return (_y.toFloat());
}



// BSP
float sign(Point a, Point b, Point c)
{
    return (a.getX() - c.getX()) * (b.getY() - c.getY()) - (b.getX() - c.getX()) * (a.getY() - c.getY());
}

bool    bsp(Point const a, Point const b, Point const c, Point const point)
{
    float   d1, d2, d3;
    bool    has_neg, has_pos;

    d1 = sign(point, a, b);
    d2 = sign(point, b, c);
    d3 = sign(point, c, a);

    has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
    has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

    return !(has_neg && has_pos);
}
