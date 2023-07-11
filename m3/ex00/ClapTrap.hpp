#ifndef CLAPTRAP
#define CLAPTRAP

#include <iostream>
#include <string>

class ClapTrap
{
public:
    ClapTrap();
    ClapTrap(std::string name);
    ClapTrap(const ClapTrap &c);
    ~ClapTrap();

    ClapTrap    &operator=(const ClapTrap &c);

    bool    canDoAction(void);
    void    attack(const std::string& target);
    void    takeDamage(unsigned int amount);
    void    beRepaired(unsigned int amount);

private:
    std::string _name;
    int         _hp;
    int         _energy;
    int         _damage;

};

#endif