#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
public:
    Ice();
    Ice(const Ice &i);
    virtual ~Ice();

    Ice &operator=(const Ice &i);

    virtual AMateria    *clone() const;
    virtual void        use(ICharacter &target);

private:

};

#endif