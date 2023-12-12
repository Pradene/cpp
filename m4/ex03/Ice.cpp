#include "Ice.hpp"

Ice::Ice()
{
    _type = "ice";
}

Ice::Ice(const Ice &i)
{
    *this = i;
}

Ice::~Ice()
{

}

Ice    &Ice::operator=(const Ice &i)
{
    _type = i._type;
    return (*this);
}

AMateria    *Ice::clone() const
{
    return (new Ice(*this));
}

void    Ice::use(ICharacter &target)
{
    std::cout << "Ice: \'* shoots an ice bolt at " \
    << target.getName() \
    << " *\'" << std::endl;
}