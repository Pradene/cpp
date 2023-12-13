#include "Cat.hpp"

Cat::Cat()
{
    if (DEBUG)
        std::cout << "Default Cat constructor called" << std::endl;
    _type = "Cat";
}

Cat::Cat(const Cat &c)
{
    if (DEBUG)
        std::cout << "Copy Cat constructor called" << std::endl;
    *this = c;
}

Cat::~Cat()
{
    if (DEBUG)
        std::cout << "Cat destructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &c)
{
    if (this == &c)
        return (*this);
    _type = c._type;
    return (*this);
}

void    Cat::makeSound() const
{
    std::cout << "Miaouuu..." << std::endl;
}