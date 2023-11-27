#ifndef WRONGANIMAL
#define WRONGANIMAL

#include <string>
#include <iostream>

class WrongAnimal
{
public:
    WrongAnimal();
    WrongAnimal(const WrongAnimal &a);
    ~WrongAnimal();

    WrongAnimal  &operator=(const WrongAnimal &a);

    virtual void    makeSound() const;
    std::string     getType() const;

protected:
    std::string _type;

};

#endif