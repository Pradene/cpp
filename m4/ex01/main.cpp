#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#define N 10

int main()
{
    Cat c2;

    Cat c1 = c2;

    std::cout << &c1.getBrain() << std::endl;
    std::cout << &c2.getBrain() << std::endl;

    size_t  i;
    Animal  *animals[N];

    for (i = 0; i < N; i++)
    {
        if (i % 2)
            animals[i] = new Cat();
        else
            animals[i] = new Dog();
    }

    for (i = 0; i < N; i++)
    {
        delete animals[i];
    }

    return (0);
}