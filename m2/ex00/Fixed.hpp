#ifndef FIXED
#define FIXED

#include <iostream>

class Fixed
{
public:
    Fixed();
    Fixed(Fixed &f);
    ~Fixed();
    Fixed   &operator=(Fixed &f);

    int     getRawBits();
    void    setRawBits(int const raw);
private:
    int                 _rawBits;
    static int const    _bits = 8;
};

#endif