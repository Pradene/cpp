#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    if (DEBUG)
        std::cout << "FragTrap Default Constructor called" << std::endl;
    _name = "John";
    _hp = 100;
    _energy = 100;
    _damage = 30;
}

FragTrap::FragTrap(std::string name)
{
    if (DEBUG)
        std::cout << "FragTrap Assignmemt Constructor called" << std::endl;
    _name = name;
    _hp = 100;
    _energy = 100;
    _damage = 30;
}

FragTrap::FragTrap(const FragTrap &s)
{
    if (DEBUG)
        std::cout << "FragTrap Copy Constructor called" << std::endl;
    *this = s;
}



FragTrap::~FragTrap()
{
    if (DEBUG)
        std::cout << "FragTrap Destructor of " << _name << " called" << std::endl;
}



void    FragTrap::highFivesGuys()
{
    if (!this->canDoAction())
    {
        this->couldntMakeAction();
        return ;
    }

    std::cout << "FragTrap " << _name << " want a high five" << std::endl;
}

