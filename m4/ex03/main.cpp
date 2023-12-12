#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"
#include "ICharacter.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

int main(void)
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    IMateriaSource* s = new MateriaSource(static_cast<const MateriaSource &>(*src));

    ICharacter* me = new Character("me");
    Character* you = new Character("you");
    AMateria* tmp;
    
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    
    tmp = src->createMateria("cure");
    you->equip(tmp);
    you->unequip(0);

    ICharacter* bob = new Character("bob");
    
    me->use(0, *bob);
    me->use(1, *bob);
    
    you->use(0, *me);
    you->use(-1, *me);
    
    delete tmp;
    delete bob;
    delete you;
    delete me;
    delete src;
    delete s;
    
    return (0);
}