#ifndef HUMANA
#define HUMANA

#include "Weapon.hpp"

#include <string>

class HumanA
{
public:
    HumanA(std::string name, Weapon &weapon);

    void    attack();

private:
    std::string _name;
    Weapon      *_weapon;
};

#endif