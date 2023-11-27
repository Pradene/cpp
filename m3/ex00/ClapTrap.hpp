#ifndef CLAPTRAP
#define CLAPTRAP

#include <iostream>
#include <string>

class ClapTrap
{
public:
    // CONSTRUCTORS
    ClapTrap();
    ClapTrap(std::string name);
    ClapTrap(const ClapTrap &c);
    
    // DESTRUCTOR
    ~ClapTrap();

    // OPERATORS
    ClapTrap    &operator=(const ClapTrap &c);

    // MEMBER FUNCTIONS
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