#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap()
{
    if (DEBUG)
        std::cout << "DiamondTrap Default Constructor called" << std::endl;
    _name = ClapTrap::_name;
    this->ClapTrap::_name = _name + "_clap_name";
    _hp = FragTrap::_hp;
    _energy = ScavTrap::_energy;
    _damage = FragTrap::_damage;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), ScavTrap(name), FragTrap(name)
{
    if (DEBUG)
        std::cout << "DiamondTrap Assignement Constructor called" << std::endl;
    _name = name;
    this->ClapTrap::_name = name + "_clap_name";
    _hp = FragTrap::_hp;
    _energy = ScavTrap::_energy;
    _damage = FragTrap::_damage;
}

DiamondTrap::DiamondTrap(const DiamondTrap &d) : ClapTrap(d), ScavTrap(d), FragTrap(d)
{
    if (DEBUG)
        std::cout << "DiamondTrap Copy Constructor called" << std::endl;
    *this = d;
}



DiamondTrap::~DiamondTrap()
{
    if (DEBUG)
        std::cout << "DiamondTrap Default Constructor of " << _name << " called" << std::endl;
}



DiamondTrap &DiamondTrap::operator=(const DiamondTrap &d)
{
    _name = d._name;
    _hp = d._hp;
    _energy = d._energy;
    _damage = d._damage;
    return (*this);
}



void    DiamondTrap::whoAmI(void) const
{
    std::cout << "clapTrap name: " << ClapTrap::_name << std::endl \
    << "name: " << _name << std::endl \
    << "hp: " << _hp << std::endl \
    << "energy: " << _energy << std::endl \
    << "damage: " << _damage << std::endl;
}
