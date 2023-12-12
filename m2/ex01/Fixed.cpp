#include "Fixed.hpp"

// CONSTRUCTOR
Fixed::Fixed()
{
    if (DEBUG)
        std::cout << "Default constructor called" << std::endl;
    _rawBits = 0;
}

Fixed::Fixed(const int n)
{
    if (DEBUG)
        std::cout << "Int constructor called" << std::endl;
    _rawBits = n << _bits;
}

Fixed::Fixed(const float f)
{
    if (DEBUG)
        std::cout << "Float constructor called" << std::endl;
    _rawBits = roundf(f * (1 << _bits));
}

Fixed::Fixed(const Fixed &f)
{
    if (DEBUG)
        std::cout << "Copy constructor called" << std::endl;
    *this = f;
}



// DESTRUCTOR
Fixed::~Fixed()
{
    if (DEBUG)
        std::cout << "Destructor called" << std::endl;
}



// OPERATORS
Fixed   &Fixed::operator=(const Fixed &f)
{
    if (DEBUG)
        std::cout << "Copy assignment operator called" << std::endl;
    _rawBits = f.getRawBits();
    return (*this);
}

std::ostream    &operator<<(std::ostream& os, const Fixed &f)
{
    os << f.toFloat();
    return (os);
}



// MEMBER FUNCTION
int     Fixed::getRawBits() const
{
    return (_rawBits);
}

void    Fixed::setRawBits(const int raw)
{
    _rawBits = raw;
}

float   Fixed::toFloat(void) const
{        
    return (static_cast<float>(_rawBits) / static_cast<float>(1 << _bits));
}

int     Fixed::toInt(void) const
{        
    return (_rawBits >> _bits);
}
