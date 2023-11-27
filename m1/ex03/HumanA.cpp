#include "HumanA.hpp"

#include <iostream>

HumanA::HumanA(std::string name, Weapon &weapon)
{
    std::cout << "HumanA constructor called" << std::endl;
    _weapon = &weapon;
    _name = name;
}

void    HumanA::attack()
{
    std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}
