#include "Cat.hpp"

Cat::Cat()
{
    _type = "Cat";
    std::cout << "Default Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &c)
{
    *this = c;
    std::cout << "Copy Cat constructor called" << std::endl;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &a)
{
    _type = a._type;
    return (*this);
}

void    Cat::makeSound() const
{
    std::cout << "Miaouuu..." << std::endl;
}