#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
public:
    Cure();
    Cure(const Cure &c);
    virtual ~Cure();

    Cure    &operator=(const Cure &c);

    virtual AMateria    *clone() const;
    virtual void        use(ICharacter &target);

private:

};

#endif