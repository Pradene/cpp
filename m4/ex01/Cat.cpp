#include "Cat.hpp"

Cat::Cat()
{
    _type = "Cat";
    _brain = new Brain();
    std::cout << "Default Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &c)
{
    *this = c;
    std::cout << "Copy Cat constructor called" << std::endl;
}

Cat::~Cat()
{
    delete _brain;
    std::cout << "Cat destructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &c)
{
    _brain = new Brain();
    *(_brain) = *(c._brain);
    _type = c._type;
    return (*this);
}

void    Cat::makeSound() const
{
    std::cout << "Miaouuu..." << std::endl;
}