#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>
# include <iostream>

# include "ICharacter.hpp"

# define DEBUG 1

class ICharacter;

class AMateria
{
public:
    AMateria();
    AMateria(const std::string &type);
    AMateria(const AMateria &a);
    virtual ~AMateria();

    AMateria    &operator=(const AMateria &a);

    const std::string   &getType() const;
    virtual AMateria    *clone() const = 0;
    virtual void        use(ICharacter &target);

protected:
    std::string _type;
};

#endif