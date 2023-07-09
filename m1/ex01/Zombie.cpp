#include "Zombie.hpp"

Zombie::Zombie()
{
    _name = nullptr;
    std::cout << "A Zombie came out of the ground" << std::endl;
}

Zombie::Zombie(std::string name)
{
    _name = name;
    std::cout << "Zombie " << _name << " came out of the ground" << std::endl;
}

Zombie::~Zombie()
{
    std::cout << "Zombie " << _name << " is dead" << std::endl;
}

void    Zombie::setName(std::string name)
{
    _name = name;
}

void    Zombie::announce()
{
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
