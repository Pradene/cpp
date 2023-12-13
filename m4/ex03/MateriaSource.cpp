# include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    size_t  i;

    for (i = 0; i < _slots; i++)
        _book[i] = nullptr;
}

MateriaSource::MateriaSource(const MateriaSource &materia)
{
    size_t  i;

    for (i = 0; i < _slots; i++)
    {
        _book[i] = nullptr;
        if (materia._book[i] != nullptr)
            _book[i] = materia._book[i]->clone();
    }
}

MateriaSource::~MateriaSource()
{
    size_t  i;

    for (i = 0; i < _slots; i++)
    {
        if (_book[i] != nullptr)
            delete _book[i];
        _book[i] = nullptr;
    }
}

MateriaSource   &MateriaSource::operator=(const MateriaSource &materia)
{
    size_t  i;

    if (this == &materia)
        return (*this);
    for (i = 0; i < _slots; i++)
    {
        if (_book[i] != nullptr)
            delete _book[i];
        _book[i] = nullptr;
        if (materia._book[i] != nullptr)
            _book[i] = materia._book[i]->clone();
    }
    return (*this);
}

void        MateriaSource::learnMateria(AMateria *materia)
{
    size_t  i;

    for (i = 0; i < _slots; i++)
    {
        if (_book[i] == nullptr)
        {
            _book[i] = materia;
            return ;
        }
    }
    std::cout << "Couldn't learn more Materia, the book is full" << std::endl;
}

AMateria*   MateriaSource::createMateria(std::string const &type)
{
    size_t  i;

    for (i = 0; i < _slots; i++)
    {
        if (_book[i] != nullptr && _book[i]->getType() == type)
            return (_book[i]->clone());
    }
    std::cout << "Couldn't create this Materia" << std::endl;
    return (nullptr);
}
