#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

# include "AMateria.hpp"

class IMateriaSource
{
public:
    virtual ~IMateriaSource() {};

    virtual void        learnMateria(AMateria *materia) = 0;
    virtual AMateria*   createMateria(std::string const & type) = 0;

protected:
    size_t      _slots = 4;
    AMateria    *_book[4];
};

#endif