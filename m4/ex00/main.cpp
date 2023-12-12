#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* animal = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();
    const Animal* c = new Cat(static_cast<const Cat &>(*cat));

    std::cout << dog->getType() << std::endl;
    dog->makeSound();
    std::cout << cat->getType() << std::endl;
    cat->makeSound();
    std::cout << c->getType() << std::endl;
    c->makeSound();
    std::cout << animal->getType() << std::endl;
    animal->makeSound();

    delete animal;
    delete c;
    delete cat;
    delete dog;

    const WrongAnimal* wCat = new WrongCat();

    std::cout << wCat->getType() << std::endl;
    wCat->makeSound();
    
    delete wCat;

    return (0);
}