#ifndef CAT
#define CAT

#include "Animal.hpp"

class Cat : public Animal
{
public:
    Cat();
    Cat(const Cat &c);
    ~Cat();

    Cat &operator=(const Cat &a);

    void    makeSound() const;
};

#endif