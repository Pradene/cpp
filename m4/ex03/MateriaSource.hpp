#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "AMateria.hpp"
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
public:
    MateriaSource();
    MateriaSource(const MateriaSource &materia);
    virtual ~MateriaSource();

    MateriaSource   &operator=(const MateriaSource &materia);

    virtual void        learnMateria(AMateria *materia);
    virtual AMateria*   createMateria(std::string const &type);

};

#endif