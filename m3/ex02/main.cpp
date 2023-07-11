#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    ScavTrap    c("Georges");

    c.attack("Vincent");
    c.takeDamage(5);
    c.beRepaired(5);
    c.takeDamage(100);
    c.beRepaired(5);
    c.attack("Vincent");

    ScavTrap    def;

    def.attack("John");

    FragTrap    f("Wally");

    f.highFivesGuys();
    return (0);
}