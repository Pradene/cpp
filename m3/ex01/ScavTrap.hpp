#ifndef SCAVTRAP
#define SCAVTRAP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
    ScavTrap();
    ScavTrap(std::string name);
    ScavTrap(const ScavTrap &c);
    ~ScavTrap();

    bool    canDoAction(void) const;
    void    attack(std::string name);
};

#endif