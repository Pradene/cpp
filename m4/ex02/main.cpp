#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    // const Animal *a = new Animal();
    const Animal *dog = new Dog();
    const Cat *cat = new Cat();
    const Cat *c = new Cat();
    
    Cat c1;
    Cat c2;

    c1 = c2;

    std::cout << &cat->getBrain() << std::endl;
    std::cout << &c->getBrain() << std::endl;

    delete cat;
    delete c;
    delete dog;

    return (0);
}