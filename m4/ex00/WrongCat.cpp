#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    if (DEBUG)
        std::cout << "Default WrongCat constructor called" << std::endl;
    _type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &c)
{
    if (DEBUG)
        std::cout << "Copy WrongCat constructor called" << std::endl;
    *this = c;
}

WrongCat::~WrongCat()
{
    if (DEBUG)
        std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &c)
{
    if (this == &c)
        return (*this);
    _type = c._type;
    return (*this);
}

void    WrongCat::makeSound() const
{
    std::cout << "Meow..." << std::endl;
}