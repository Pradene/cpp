#include "Dog.hpp"

Dog::Dog()
{
    if (DEBUG)
        std::cout << "Default Dog constructor called" << std::endl;
    _type = "Dog";
}

Dog::Dog(const Dog &d)
{
    if (DEBUG)
        std::cout << "Copy Dog constructor called" << std::endl;
    _type = d._type;
}

Dog::~Dog()
{
    if (DEBUG)
        std::cout << "Dog destructor called" << std::endl;
}

Dog  &Dog::operator=(const Dog &d)
{
    _type = d._type;
    return (*this);
}

void    Dog::makeSound() const
{
    std::cout << "Ouaf Ouaf !" << std::endl;
}