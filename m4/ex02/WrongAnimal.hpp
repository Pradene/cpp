#ifndef WRONGANIMAL
# define WRONGANIMAL

# include "Animal.hpp"

# include <string>
# include <iostream>

class WrongAnimal
{
public:
    WrongAnimal();
    WrongAnimal(const WrongAnimal &a);
    ~WrongAnimal();

    WrongAnimal  &operator=(const WrongAnimal &a);

    void                makeSound() const;
    const std::string   &getType() const;

protected:
    std::string _type;

};

#endif