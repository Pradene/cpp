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
    for (size_t i = 0; i < 100; i++)
    {
        _ideas[i] = b._ideas[i];
    }
}

Brain   &Brain::operator=(const Brain &b)
{
    for (size_t i = 0; i < 100; i++)
    {
        _ideas[i] = b._ideas[i];
    }
    return (*this);
}

Brain::~Brain()
{
    if (DEBUG)
        std::cout << "Brain Destructor called" << std::endl;
}