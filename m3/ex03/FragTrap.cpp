#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("")
{
    std::cout << "FragTrap Default Constructor called" << std::endl;
    _hp = 100;
    _energy = 100;
    _damage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    std::cout << "FragTrap Assignmemt Constructor called" << std::endl;
    _hp = 100;
    _energy = 100;
    _damage = 30;
}

FragTrap::FragTrap(const FragTrap &s)
{
    std::cout << "FragTrap Copy Constructor called" << std::endl;
    *this = s;
}



FragTrap::~FragTrap()
{
    std::cout << "FragTrap Destructor called" << std::endl;
}



void    FragTrap::highFivesGuys()
{
    if (!this->canDoAction())
    {
        std::cout << "FragTrap " << _name \
        << " couldn't make this action" << std::endl;
        return ;
    }

    std::cout << "FragTrap " << _name << " want a high five" << std::endl;
}

