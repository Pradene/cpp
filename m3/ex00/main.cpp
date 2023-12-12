#include "ClapTrap.hpp"

int main()
{
    ClapTrap    c("Georges");

    c.attack("Vincent");
    c.takeDamage(5);
    c.beRepaired(5);
    c.takeDamage(100);
    c.beRepaired(5);

    ClapTrap    def;

    for (size_t i = 0; i < 10; i++) {
        def.attack("John");
    }
    
    def.attack("John");

    return (0);
}