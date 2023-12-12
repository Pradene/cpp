#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <string>

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Character : public ICharacter
{
public:
    Character();
    Character(const std::string name);
    Character(const Character &c);
    virtual ~Character();

    Character   &operator=(const Character &c);

    virtual const std::string   &getName() const;
    virtual void                equip(AMateria* m);
    virtual void                unequip(int idx);
    virtual void                use(int idx, ICharacter& target);

private:

};

#endif