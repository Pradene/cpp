#include "Brain.hpp"

Brain::Brain()
{
    if (DEBUG)
        std::cout << "Brain Default Constructor called" << std::endl;
}

Brain::Brain(const Brain &b)
{
    if (DEBUG)
        std::cout << "Brain Copy Constructor called" << std::endl;
    *this = b;
}

Brain   &Brain::operator=(const Brain &b)
{
    if (this == &b)
        return (*this);
    for (size_t i = 0; i < 100; i++)
        _ideas[i] = b._ideas[i];
    return (*this);
}

Brain::~Brain()
{
    if (DEBUG)
        std::cout << "Brain Destructor called" << std::endl;
}