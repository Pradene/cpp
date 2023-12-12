#include "Zombie.hpp"

int main()
{
    int n = 10;
    Zombie *z = zombieHorde(n, "Zoo");

    for (int i = 0; i < n; i++)
    {
        z[i].announce();
    }
    
    delete[] z;
    
    return (0);
}