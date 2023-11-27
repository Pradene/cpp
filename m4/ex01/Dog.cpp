#include "Dog.hpp"

Dog::Dog()
{
    _type = "Dog";
    _brain = new Brain();
    std::cout << "Default Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &d)
{
    *this = d;
    std::cout << "Copy Dog constructor called" << std::endl;
}

Dog::~Dog()
{
    delete _brain;
    std::cout << "Dog destructor called" << std::endl;
}

Dog  &Dog::operator=(const Dog &d)
{
    _brain = new Brain();
    *_brain = *(d._brain);
    _type = d._type;
    return (*this);
}

void    Dog::makeSound() const
{
    std::cout << "Ouaf Ouaf !" << std::endl;
}