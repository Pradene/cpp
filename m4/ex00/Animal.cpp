#include "Animal.hpp"

Animal::Animal()
{
    _type = "Buzz";
    std::cout << "Default Animal constructor called" << std::endl;
}

Animal::Animal(const Animal &a)
{
    *this = a;
    std::cout << "Copy Animal constructor called" << std::endl;
}

Animal::~Animal()
{
    std::cout << "Animal destructor called" << std::endl;
}

Animal  &Animal::operator=(const Animal &a)
{
    _type = a._type;
    return (*this);
}

void    Animal::makeSound() const
{
    std::cout << "A strange sound..." << std::endl;
}

std::string Animal::getType() const
{
    return (_type);
}