#ifndef CAT
# define CAT

# include "Animal.hpp"

class Cat : public Animal
{
public:
    Cat();
    Cat(const Cat &c);
    virtual ~Cat();

    Cat &operator=(const Cat &c);

    virtual void    makeSound() const;
};

#endif