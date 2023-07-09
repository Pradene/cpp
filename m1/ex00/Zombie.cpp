#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
    _name = name;
    std::cout << "Zombie " << _name << " came out of the ground" << std::endl;
}

Zombie::~Zombie()
{
    std::cout << "Zombie " << _name << " is dead" << std::endl;
}

void    Zombie::announce()
{
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
