#ifndef DIAMONDTRAP
#define DIAMONDTRAP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
public:
    DiamondTrap();
    DiamondTrap(std::string name);
    DiamondTrap(const DiamondTrap &d);
    ~DiamondTrap();

    DiamondTrap &operator=(const DiamondTrap &d);

    void    whoAmI(void) const;

private:
    std::string _name;

};

#endif