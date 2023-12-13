#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    if (DEBUG)
        std::cout << "Default WrongAnimal constructor called" << std::endl;
    _type = "Bernard";
}

WrongAnimal::WrongAnimal(const WrongAnimal &a)
{
    if (DEBUG)
        std::cout << "Copy WrongAnimal constructor called" << std::endl;
    *this = a;
}

WrongAnimal::~WrongAnimal()
{
    if (DEBUG)
        std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal  &WrongAnimal::operator=(const WrongAnimal &a)
{
    if (this == &a)
        return (*this);
    _type = a._type;
    return (*this);
}

void    WrongAnimal::makeSound() const
{
    std::cout << "A weird sound..." << std::endl;
}

const std::string   &WrongAnimal::getType() const
{
    return (_type);
}