#ifndef DOG
#define DOG

#include "Animal.hpp"

class Dog : public Animal
{
public:
    Dog();
    Dog(const Dog &d);
    ~Dog();

    Dog &operator=(const Dog &a);

    void    makeSound() const;
};

#endif