#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap()
{
    _name = ClapTrap::_name;
    _hp = FragTrap::_hp;
    _energy = ScavTrap::_energy;
    _damage = FragTrap::_damage;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_trap")
{
    _name = name;
    _hp = FragTrap::_hp;
    _energy = ScavTrap::_energy;
    _damage = FragTrap::_damage;
}

DiamondTrap::DiamondTrap(const DiamondTrap &d) : ClapTrap(d)
{
    *this = d;
}



DiamondTrap::~DiamondTrap()
{

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
    std::cout << _name << " " << ClapTrap::_name << std::endl;

    std::cout << "name: " << _name << std::endl \
    << "hp: " << _hp << std::endl \
    << "energy: " << _energy << std::endl \
    << "damage: " << _damage << std::endl;
}
