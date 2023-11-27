#ifndef DOG
#define DOG

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
public:
    Dog();
    Dog(const Dog &d);
    ~Dog();

    Dog &operator=(const Dog &d);

    void    makeSound() const;

private:
    Brain   *_brain;
};

#endif