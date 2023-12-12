#ifndef ANIMAL
# define ANIMAL

# define DEBUG 1

# include <string>
# include <iostream>

class Animal
{
public:
    Animal();
    Animal(const Animal &a);
    virtual ~Animal();

    Animal  &operator=(const Animal &a);

    virtual void        makeSound() const;
    const std::string   &getType() const;

protected:
    std::string _type;

};

#endif