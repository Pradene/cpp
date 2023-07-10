#include "Fixed.hpp"

// CONSTRUCTOR
Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    _rawBits = 0;
}

Fixed::Fixed(int const n)
{
    std::cout << "Int constructor called" << std::endl;
    _rawBits = n << _bits;
}

Fixed::Fixed(float const f)
{
    std::cout << "Float constructor called" << std::endl;
    _rawBits = roundf(f * (1 << _bits));
}

Fixed::Fixed(const Fixed &f)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = f;
}



// DESTRUCTOR
Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}



// OPERATORS
Fixed   &Fixed::operator=(const Fixed &f)
{
    std::cout << "Copy assignment operator called" << std::endl;
    _rawBits = f._rawBits;
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
    std::cout << "getRawBits member function called" << std::endl;
    return (_rawBits);
}

void    Fixed::setRawBits(int const raw)
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
