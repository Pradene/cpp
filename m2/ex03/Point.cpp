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
    _x = p.getX();
    _y = p.getY();
    return (*this);
}



// MEMBER FUNCTIONS
float   Point::getX() const
{
    return (_x.toFloat());
}

float   Point::getY() const
{
    return (_y.toFloat());
}



// BSP

bool    bsp(Point a, Point b, Point c, Point p)
{
    float denominator = (b.getY() - c.getY()) * (a.getX() - c.getX()) + (c.getX() - b.getX()) * (a.getY() - c.getY());

    float alpha = ((b.getY() - c.getY()) * (p.getX() - c.getX()) + (c.getX() - b.getX()) * (p.getY() - c.getY())) / denominator;
    float beta = ((c.getY() - a.getY()) * (p.getX() - c.getX()) + (a.getX() - c.getX()) * (p.getY() - c.getY())) / denominator;
    float gamma = 1.0f - alpha - beta;

    // Check if the point is inside the triangle and not on any vertex
    return alpha > 0 && beta > 0 && gamma > 0 &&
           alpha < 1 && beta < 1 && gamma < 1;
}
