#include "Cure.hpp"

Cure::Cure()
{
    _type = "cure";
}

Cure::Cure(const Cure &c)
{
    *this = c;
}

Cure::~Cure()
{
    
}

Cure    &Cure::operator=(const Cure &c)
{
    _type = c._type;
    return (*this);
}

AMateria    *Cure::clone() const
{
    return (new Cure(*this));
}

void    Cure::use(ICharacter &target)
{
    std::cout << "Cure: \'* heals " \
    << target.getName() \
    << "'s wounds *\'" << std::endl;
}