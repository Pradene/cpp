#ifndef ANIMAL
#define ANIMAL

#include <string>
#include <iostream>

class Animal
{
public:
    Animal();
    Animal(const Animal &a);
    ~Animal();

    Animal  &operator=(const Animal &a);

    virtual void    makeSound() const;
    std::string     getType() const;

protected:
    std::string _type;

};

#endif