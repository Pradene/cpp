#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    _type = "WrongCat";
    std::cout << "Default WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &c)
{
    *this = c;
    std::cout << "Copy WrongCat constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &a)
{
    _type = a._type;
    return (*this);
}

void    WrongCat::makeSound() const
{
    std::cout << "Meow..." << std::endl;
}