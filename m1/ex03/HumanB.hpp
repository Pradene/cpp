#ifndef HUMANB
#define HUMANB

#include "Weapon.hpp"

#include <string>

class HumanB
{
public:
    HumanB(std::string name);

    void    setWeapon(Weapon &Weapon);
    void    attack();

private:
    std::string _name;
    Weapon      *_weapon;
};

#endif