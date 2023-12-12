#include "HumanB.hpp"

#include <iostream>

HumanB::HumanB(std::string name)
{
    std::cout << "HumanB constructor called" << std::endl;
    _name = name;
    _weapon = nullptr;
}

void    HumanB::setWeapon(Weapon &weapon)
{
    _weapon = &weapon;
}

void    HumanB::attack()
{
    if (_weapon)
        std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
    else
        std::cout << _name << " attacks with their hands" << std::endl;

}
