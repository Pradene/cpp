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

    Fixed   operator+(const Fixed &a) const;
    Fixed   operator-(const Fixed &a) const;
    Fixed   operator*(const Fixed &a) const;
    Fixed   operator/(const Fixed &a) const;

    Fixed   &operator++();
    Fixed   &operator--();
    Fixed   operator++(int);
    Fixed   operator--(int);


    int     getRawBits(void) const;
    void    setRawBits(int const raw);
    float   toFloat(void) const;
    int     toInt(void) const;
    static Fixed    &max(Fixed &a, Fixed &b);
    const static Fixed    &max(const Fixed &a, const Fixed &b);
    static Fixed    &min(Fixed &a, Fixed &b);
    const static Fixed    &min(const Fixed &a, const Fixed &b);

private:
    int                 _rawBits;
    static int const    _bits = 8;
};

std::ostream    &operator<<(std::ostream& os, const Fixed &f);

bool    operator==(const Fixed &a, const Fixed &b);
bool    operator>=(const Fixed &a, const Fixed &b);
bool    operator<=(const Fixed &a, const Fixed &b);
bool    operator!=(const Fixed &a, const Fixed &b);
bool    operator>(const Fixed &a, const Fixed &b);
bool    operator<(const Fixed &a, const Fixed &b);

#endif