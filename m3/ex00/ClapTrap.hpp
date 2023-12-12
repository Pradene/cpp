#ifndef CLAPTRAP
# define CLAPTRAP

# define DEBUG 1

# include <iostream>
# include <string>

class ClapTrap
{
public:
    // CONSTRUCTORS
    ClapTrap();
    ClapTrap(std::string name);
    ClapTrap(const ClapTrap &c);
    
    // DESTRUCTOR
    ~ClapTrap();

    // OPERATORS
    ClapTrap    &operator=(const ClapTrap &c);

    // MEMBER FUNCTIONS
    bool    canDoAction(void);
    void    couldntMakeAction(void);
    void    attack(const std::string& target);
    void    takeDamage(unsigned int amount);
    void    beRepaired(unsigned int amount);

private:
    std::string _name;
    int         _hp = 10;
    int         _energy = 10;
    int         _damage = 0;

};

#endif