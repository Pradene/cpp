#include <string>
#include <iostream>

class Zombie
{
public:
    Zombie();
    Zombie(std::string name);
    ~Zombie();

    void    setName(std::string name);
    void    announce(void);

private:
    std::string _name;
};

Zombie* zombieHorde( int N, std::string name );
