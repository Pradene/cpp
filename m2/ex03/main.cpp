#include "Fixed.hpp"
#include "Point.hpp"

int main(void)
{
    Point   p1(0, 0);
    Point   p2(1, 0);
    Point   p3(0, 1);

    Point   p(1.01, 0);

    if (bsp(p1, p2, p3, p))
        std::cout << "The point is inside the triangle" << std::endl;
    else
        std::cout << "The point is outside the triangle" << std::endl;

    return (0);
}
