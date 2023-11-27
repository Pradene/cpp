#include "Weapon.hpp"

#include <iostream>

Weapon::Weapon(std::string type)
{
    std::cout << "Weapon constructor called" << std::endl;
    _type = type;
}

std::string &Weapon::getType()
{
    return (this->_type);
}

void        Weapon::setType(std::string type)
{
    getType() = type;
}
