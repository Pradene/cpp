#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    _type = "Bernard";
    std::cout << "Default WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &a)
{
    *this = a;
    std::cout << "Copy WrongAnimal constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal  &WrongAnimal::operator=(const WrongAnimal &a)
{
    _type = a._type;
    return (*this);
}

void    WrongAnimal::makeSound() const
{
    std::cout << "A weird sound..." << std::endl;
}

std::string WrongAnimal::getType() const
{
    return (_type);
}