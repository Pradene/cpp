#ifndef FIXED
#define FIXED

#include <iostream>
#include <math.h>

class Fixed
{
public:
    Fixed();
    Fixed(int const n);
    Fixed(float const f);
    Fixed(const Fixed &f);
    ~Fixed();

    Fixed   &operator=(const Fixed &f);

    int     getRawBits(void) const;
    void    setRawBits(int const raw);
    float   toFloat(void) const;
    int     toInt(void) const;

private:
    int                 _rawBits;
    static int const    _bits = 8;
};

std::ostream    &operator<<(std::ostream& os, const Fixed &f);

#endif