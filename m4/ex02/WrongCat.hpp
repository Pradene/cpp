#ifndef WRONGCAT
#define WRONGCAT

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
    WrongCat();
    WrongCat(const WrongCat &c);
    ~WrongCat();

    WrongCat &operator=(const WrongCat &a);

    void    makeSound() const;
};

#endif