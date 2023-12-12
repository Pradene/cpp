#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    ScavTrap    c("Georges");

    c.attack("Vincent");
    c.takeDamage(5);
    c.beRepaired(5);
    c.takeDamage(100);
    c.beRepaired(5);

    ScavTrap    def;

    def.attack("John");

    return (0);
}