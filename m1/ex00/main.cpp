#include "Zombie.hpp"

int main()
{
    Zombie *z0 = newZombie("Carl");
    z0->announce();
    delete z0;
    
    Zombie z1("Dereck");
    z1.announce();
    
    randomChump("Crook");
    
    return (0);
}
