#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    std::cout << "ScavTrap Default Constructor called" << std::endl;
    _name = "John";
    _hp = 100;
    _energy = 50;
    _damage = 20;
}

ScavTrap::ScavTrap(std::string name)
{
    std::cout << "ScavTrap Assignmemt Constructor called" << std::endl;
    _name = name;
    _hp = 100;
    _energy = 50;
    _damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &s)
{
    std::cout << "ScavTrap Copy Constructor called" << std::endl;
    *this = s;
}



ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap Destructor called" << std::endl;
}



bool    ScavTrap::canDoAction(void) const
{
    return (_energy > 0 && _hp > 0);
}

void    ScavTrap::attack(std::string target)
{
    if (!this->canDoAction())
    {
        std::cout << "ScavTrap " << _name \
        << " couldn't make this action" << std::endl;
        return ;
    }
    
    _energy--;
    std::cout << "ScavTrap " << _name << " attacks " \
    << target << ", causing " << _damage \
    << " points of damage!" << std::endl;
}