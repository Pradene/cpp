#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    if (DEBUG)
        std::cout << "ScavTrap Default Constructor called" << std::endl;
    _name = "John";
    _hp = 100;
    _energy = 50;
    _damage = 20;
}

ScavTrap::ScavTrap(std::string name)
{
    if (DEBUG)
        std::cout << "ScavTrap Assignmemt Constructor called" << std::endl;
    _name = name;
    _hp = 100;
    _energy = 50;
    _damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &s)
{
    if (DEBUG)
        std::cout << "ScavTrap Copy Constructor called" << std::endl;
    *this = s;
}

ScavTrap::~ScavTrap()
{
    if (DEBUG)
        std::cout << "ScavTrap Destructor of " << _name << " called" << std::endl;
}

void    ScavTrap::attack(std::string target)
{
    if (!this->canDoAction())
    {
        this->couldntMakeAction();
        return ;
    }

    _energy--;
    std::cout << "ScavTrap " << _name << " attacks " \
    << target << ", causing " << _damage \
    << " points of damage!" << std::endl;
}

void    ScavTrap::guardGate(void)
{
    if (!this->canDoAction())
    {
        this->couldntMakeAction();
        return ;
    }

    std::cout << "ScavTrap " << _name \
    << " is now gate keeper" \
    << std::endl; 
}