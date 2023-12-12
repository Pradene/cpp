#ifndef DOG
# define DOG

# include "Animal.hpp"

class Dog : public Animal
{
public:
    Dog();
    Dog(const Dog &d);
    virtual ~Dog();

    Dog &operator=(const Dog &d);

    virtual void    makeSound() const;
};

#endif