#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    if (DEBUG)
        std::cout << "ClapTrap Default Constructor called" << std::endl;
    _name = "John";
}

ClapTrap::ClapTrap(std::string name)
{
    if (DEBUG)
        std::cout << "ClapTrap Assignmemt Constructor called" << std::endl;
    _name = name;
}

ClapTrap::ClapTrap(const ClapTrap &c)
{
    if (DEBUG)
        std::cout << "ClapTrap Copy Constructor called" << std::endl;
    *this = c;
}



ClapTrap::~ClapTrap()
{
    if (DEBUG)
        std::cout << "ClapTrap Destructor of " << _name << " called" << std::endl;
}



ClapTrap    &ClapTrap::operator=(const ClapTrap &c)
{
    _name = c._name;
    _energy = c._energy;
    _hp = c._hp;
    _damage = c._damage;
    return (*this);
}


bool    ClapTrap::canDoAction(void)
{
    return (_energy > 0 && _hp > 0);
}

void    ClapTrap::couldntMakeAction(void)
{
    std::cout << _name \
    << " couldn't make this action because " \
    << (_hp > 0 ? "he has no energy" : "he's dead") \
    << std::endl;

    return ;
}

void    ClapTrap::attack(const std::string& target)
{
    if (!this->canDoAction())
    {
        this->couldntMakeAction();
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
        this->couldntMakeAction();
        return ;
    }

    _hp -= amount;
    std::cout << "ClapTrap " << _name << " received " \
    << amount << " points of damage!" << std::endl;
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (!this->canDoAction())
    {
        this->couldntMakeAction();
        return ;
    }

    _energy--;
    _hp += amount;
    std::cout << "ClapTrap " << _name << " healed " \
    << amount << " of health points" << std::endl;
}
