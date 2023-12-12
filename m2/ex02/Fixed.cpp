#include "Fixed.hpp"

// CONSTRUCTOR
Fixed::Fixed()
{
    _rawBits = 0;
}

Fixed::Fixed(int const n)
{
    _rawBits = n << _bits;
}

Fixed::Fixed(float const f)
{
    _rawBits = roundf(f * (1 << _bits));
}

Fixed::Fixed(const Fixed &f)
{
    *this = f;
}



// DESTRUCTOR
Fixed::~Fixed()
{

}



// OPERATORS
Fixed   &Fixed::operator=(const Fixed &f)
{
    _rawBits = f.getRawBits();
    return (*this);
}

std::ostream    &operator<<(std::ostream& os, const Fixed &f)
{
    os << f.toFloat();
    return (os);
}



// COMPARASON OPERATORS
bool    operator==(const Fixed &a, const Fixed &b)
{
    return (a.toFloat() == b.toFloat());
}

bool    operator>=(const Fixed &a, const Fixed &b)
{
    return (a.toFloat() >= b.toFloat());
}

bool    operator<=(const Fixed &a, const Fixed &b)
{
    return (a.toFloat() <= b.toFloat());
}

bool    operator!=(const Fixed &a, const Fixed &b)
{
    return (a.toFloat() != b.toFloat());
}

bool    operator>(const Fixed &a, const Fixed &b)
{
    return (a.toFloat() > b.toFloat());
}

bool    operator<(const Fixed &a, const Fixed &b)
{
    return (a.toFloat() < b.toFloat());
}



// ARITHMETIC OPERATORS
Fixed   Fixed::operator+(const Fixed &f) const
{
    Fixed   nb(f.toFloat() + this->toFloat());
    return (nb);
}

Fixed   Fixed::operator-(const Fixed &f) const
{
    Fixed   nb(f.toFloat() - this->toFloat());
    return (nb);
}

Fixed   Fixed::operator*(const Fixed &f) const
{
    Fixed   nb(f.toFloat() * this->toFloat());
    return (nb);
}

Fixed   Fixed::operator/(const Fixed &f) const
{
    Fixed   nb(f.toFloat() / this->toFloat());
    return (nb);
}



// INCREMENTATION / DECREMENTATION OPERATORS
Fixed   &Fixed::operator++()
{
    _rawBits++;
    return (*this);
}

Fixed   &Fixed::operator--()
{
    _rawBits--;
    return (*this);
}

Fixed   Fixed::operator++(int)
{
    Fixed   f(*this);

    _rawBits++;
    return (f);
}

Fixed   Fixed::operator--(int)
{
    Fixed   f(*this);

    _rawBits--;
    return (f);
}



// MEMBER FUNCTION
int     Fixed::getRawBits() const
{
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

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    return ((a > b) ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    return ((a > b) ? a : b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    return ((a < b) ? a : b);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    return ((a < b) ? a : b);
}
