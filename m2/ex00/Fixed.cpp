#include "Fixed.hpp"

Fixed::Fixed()
{
    if (DEBUG)
        std::cout << "Default constructor called" << std::endl;
    _rawBits = 0;
}

Fixed::Fixed(const Fixed &f)
{
    if (DEBUG)
        std::cout << "Copy constructor called" << std::endl;
    *this = f;
}

Fixed::~Fixed()
{
    if (DEBUG)
        std::cout << "Destructor called" << std::endl;
}

Fixed   &Fixed::operator=(const Fixed &f)
{
    if (DEBUG)
        std::cout << "Copy assignment operator called" << std::endl;
    _rawBits = f.getRawBits();
    return (*this);
}

int     Fixed::getRawBits() const
{
    if (DEBUG)
        std::cout << "getRawBits member function called" << std::endl;
    return (_rawBits);
}

void    Fixed::setRawBits(int const raw)
{
    if (DEBUG)
        std::cout << "setRawBits member function called" << std::endl;
    _rawBits = raw;
}
