#include "Fixed.hpp"
#include "Point.hpp"

int main(void)
{
    Point   p1(0, 0);
    Point   p2(1, 0);
    Point   p3(0, 1);

    Point   p(0.5, 0.5);

    std::cout << "x: " << p.getX() << ", y: " << p.getY() << std::endl;
    std::cout << "x: " << p1.getX() << ", y: " << p1.getY() << std::endl;
    std::cout << "x: " << p2.getX() << ", y: " << p2.getY() << std::endl;
    std::cout << "x: " << p3.getX() << ", y: " << p3.getY() << std::endl;

    std::cout << (bsp(p1, p2, p3, p) \
    ? "The point is inside the triangle" \
    : "The point is outside the triangle") \
    << std::endl;

    return (0);
}
