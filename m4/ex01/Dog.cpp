#include "Dog.hpp"

Dog::Dog()
{
    if (DEBUG)
        std::cout << "Default Dog constructor called" << std::endl;
    _brain = new Brain();
    _type = "Dog";
}

Dog::Dog(const Dog &d)
    : _brain(nullptr)
{
    if (DEBUG)
        std::cout << "Copy Dog constructor called" << std::endl;
    *this = d;
}

Dog::~Dog()
{
    if (DEBUG)
        std::cout << "Dog destructor called" << std::endl;
    delete _brain;
}

Dog  &Dog::operator=(const Dog &d)
{
    if (this == &d)
        return (*this);
    if (_brain != nullptr)
        delete _brain;
    _brain = new Brain(*d._brain);
    _type = d._type;
    return (*this);
}

void    Dog::makeSound() const
{
    std::cout << "Ouaf Ouaf !" << std::endl;
}