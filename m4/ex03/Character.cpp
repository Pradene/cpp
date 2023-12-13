# include "Character.hpp"

Character::Character()
{
    size_t  i;

    _name = "Unknown";
    for (i = 0; i < _slots; i++)
        _inventory[i] = nullptr;
}

Character::Character(const std::string name)
{
    size_t  i;

    _name = name;
    for (i = 0; i < _slots; i++)
        _inventory[i] = nullptr;
}

Character::Character(const Character &c)
{
    size_t  i;

    _name = c._name;
    for (i = 0; i < _slots; i++)
    {
        _inventory[i] = nullptr;
        if (c._inventory[i] != nullptr)
            _inventory[i] = c._inventory[i]->clone();
    }
}

Character::~Character()
{
    size_t  i;

    for (i = 0; i < _slots; i++)
    {
        if (_inventory[i] != nullptr)
            delete _inventory[i];
        _inventory[i] = nullptr;
    }
}

Character   &Character::operator=(const Character &c)
{
    size_t  i;

    if (this == &c)
        return (*this);
    _name = c._name;
    for (i = 0; i < _slots; i++)
    {
        if (_inventory[i] != nullptr)
            delete _inventory[i];
        _inventory[i] = nullptr;
        if (c._inventory[i] != nullptr)
            _inventory[i] = c._inventory[i]->clone();
    }
    return (*this);
}

const std::string   &Character::getName() const
{
    return (_name);
}

void    Character::equip(AMateria* m)
{
    size_t  i;

    for (i = 0; i < _slots; i++)
    {
        if (_inventory[i] == nullptr)
        {
            _inventory[i] = m;
            return ;
        }
    }
    std::cout << "Inventory is full, unequip an item to add another one" << std::endl;
}

void    Character::unequip(int index)
{
    if (index >= 0 && index < _slots && _inventory[index] != nullptr)
    {
        _inventory[index] = nullptr;
        return ;
    }
    std::cout << "Item doesn't exist at this index" << std::endl;
}

void    Character::use(int index, ICharacter& target)
{
    if (index >= 0 && index < _slots && _inventory[index] != nullptr)
    {
        _inventory[index]->use(target);
        return ;
    }
    std::cout << "Item doesn't exist at this index" << std::endl;
}
