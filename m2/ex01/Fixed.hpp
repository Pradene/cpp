#ifndef FIXED
# define FIXED

# define DEBUG 1

# include <iostream>
# include <math.h>

class Fixed
{
public:
    Fixed();
    Fixed(const int n);
    Fixed(const float f);
    Fixed(const Fixed &f);
    ~Fixed();

    Fixed   &operator=(const Fixed &f);

    int     getRawBits(void) const;
    void    setRawBits(const int raw);
    float   toFloat(void) const;
    int     toInt(void) const;

private:
    int                 _rawBits;
    const static int    _bits = 8;
};

std::ostream    &operator<<(std::ostream& os, const Fixed &f);

#endif