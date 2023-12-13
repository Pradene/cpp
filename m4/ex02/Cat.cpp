#include "Cat.hpp"

Cat::Cat()
{
    if (DEBUG)
        std::cout << "Default Cat constructor called" << std::endl;
    _brain = new Brain();
    _type = "Cat";
}

Cat::Cat(const Cat &c)
    : _brain(nullptr)
{
    if (DEBUG)
        std::cout << "Copy Cat constructor called" << std::endl;
    *this = c;
}

Cat::~Cat()
{
    if (DEBUG)
        std::cout << "Cat destructor called" << std::endl;
    delete _brain;
}

Cat &Cat::operator=(const Cat &c)
{
    if (this == &c)
        return (*this);
    if (_brain != nullptr)
        delete _brain;
    _brain = new Brain(*c._brain);
    _type = c._type;
    return (*this);
}

void    Cat::makeSound() const
{
    std::cout << "Miaouuu..." << std::endl;
}

Brain   &Cat::getBrain() const
{
    std::cout << this << std::endl;
    return (*_brain);
}
