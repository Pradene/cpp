#include "AMateria.hpp"

AMateria::AMateria()
{
    if (DEBUG)
        std::cout << "Default AMateria constructor called" << std::endl;
    _type = "undefined";
}

AMateria::AMateria(const std::string &type)
{
    if (DEBUG)
        std::cout << "Assignement AMateria constructor called" << std::endl;
    _type = type;
}

AMateria::AMateria(const AMateria &a)
{
    if (DEBUG)
        std::cout << "Copy AMateria constructor called" << std::endl;
    *this = a;
}

AMateria::~AMateria()
{
    if (DEBUG)
        std::cout << "Default destructor called" << std::endl;
}

AMateria  &AMateria::operator=(const AMateria &a)
{
    if (this == &a)
        return (*this);
    _type = a._type;
    return (*this);
}

const std::string &AMateria::getType() const
{
    return (_type);
}

void    AMateria::use(ICharacter &target)
{
    return ;
}