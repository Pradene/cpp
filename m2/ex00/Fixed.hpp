#ifndef FIXED
# define FIXED

# define DEBUG 1

# include <iostream>

class Fixed
{
public:
    Fixed();
    Fixed(const Fixed &f);
    ~Fixed();
    Fixed   &operator=(const Fixed &f);

    int     getRawBits() const;
    void    setRawBits(const int raw);
private:
    int                 _rawBits;
    const static int    _bits = 8;
};

#endif