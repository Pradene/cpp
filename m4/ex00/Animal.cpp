#include "Animal.hpp"

Animal::Animal()
{
    if (DEBUG)
        std::cout << "Default Animal constructor called" << std::endl;
    _type = "undefined";
}

Animal::Animal(const Animal &a)
{
    if (DEBUG)
        std::cout << "Copy Animal constructor called" << std::endl;
    *this = a;
}

Animal::~Animal()
{
    if (DEBUG)
        std::cout << "Animal destructor called" << std::endl;
}

Animal  &Animal::operator=(const Animal &a)
{
    if (this == &a)
        return (*this);
    _type = a._type;
    return (*this);
}

void    Animal::makeSound() const
{
    std::cout << "A strange sound..." << std::endl;
}

const std::string &Animal::getType() const
{
    return (_type);
}