#include "Animal.hpp"

Animal::Animal()
{
    if (DEBUG)
        std::cout << "Default Animal constructor called" << std::endl;
    _type = "Buzz";
}

Animal::Animal(const Animal &a)
{
    if (DEBUG)
        std::cout << "Copy Animal constructor called" << std::endl;
    _type = a._type;
}

Animal::~Animal()
{
    if (DEBUG)
        std::cout << "Animal destructor called" << std::endl;
}

Animal  &Animal::operator=(const Animal &a)
{
    std::cout << "Ok" << std::endl;
    _type = a._type;
    return (*this);
}

const std::string   &Animal::getType() const
{
    return (_type);
}