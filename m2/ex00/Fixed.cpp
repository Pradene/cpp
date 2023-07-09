#include "Fixed.hpp"

Fixed::Fixed()
{
    _rawBits = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed &f)
{
    std::cout << "Copy constructor called" << std::endl;
    _rawBits = f.getRawBits();
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed   &Fixed::operator=(Fixed &f)
{
    std::cout << "Copy assignment operator called" << std::endl;
    _rawBits = f.getRawBits();
    return (*this);
}

int     Fixed::getRawBits()
{
    std::cout << "getRawBits member function called" << std::endl;
    return (_rawBits);
}

void    Fixed::setRawBits(int const raw)
{
    _rawBits = raw;
}
