#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << "ClapTrap Default Constructor called" << std::endl;
    _name = "John";
    _hp = 10;
    _energy = 10;
    _damage = 0;
}

ClapTrap::ClapTrap(std::string name)
{
    std::cout << "ClapTrap Assignmemt Constructor called" << std::endl;
    _name = name;
    _hp = 10;
    _energy = 10;
    _damage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &c)
{
    std::cout << "ClapTrap Copy Constructor called" << std::endl;
    *this = c;
}



ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap Destructor called" << std::endl;
}



ClapTrap    &ClapTrap::operator=(const ClapTrap &c)
{
    _name = c._name;
    _energy = c._energy;
    _hp = c._hp;
    _damage = c._damage;
    return (*this);
}



bool    ClapTrap::canDoAction(void) const
{
    return (_energy > 0 && _hp > 0);
}

void    ClapTrap::attack(const std::string& target)
{
    if (_energy <= 0 || _hp <= 0)
    {
        std::cout << "ClapTrap " << _name \
        << " couldn't make this action" << std::endl;
        return ;
    }
    
    _energy--;
    std::cout << "ClapTrap " << _name << " attacks " \
    << target << ", causing " << _damage \
    << " points of damage!" << std::endl;
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    if (!this->canDoAction())
    {
        std::cout << "ClapTrap " << _name \
        << " couldn't make this action" << std::endl;
        return ;
    }
    _hp -= amount;
    std::cout << "Claptrap " << _name << " received " \
    << amount << " points of damage!" << std::endl;
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (!this->canDoAction())
    {
        std::cout << "ClapTrap " << _name \
        << " couldn't make this action" << std::endl;
        return ;
    }

    _energy--;
    _hp += amount;
    std::cout << "Claptrap " << _name << " healed " \
    << amount << " of health points" << std::endl;
}

