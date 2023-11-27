#include "Dog.hpp"

Dog::Dog()
{
    _type = "Dog";
    std::cout << "Default Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &c)
{
    *this = c;
    std::cout << "Copy Dog constructor called" << std::endl;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
}

Dog  &Dog::operator=(const Dog &a)
{
    _type = a._type;
    return (*this);
}

void    Dog::makeSound() const
{
    std::cout << "Ouaf Ouaf !" << std::endl;
}