#include "PhoneBook.hpp"

void    PhoneBook::add()
{
    std::string    s;

    if (_index >= 8)
        _index = 0;
    
    std::cout << "Firstname: ";
    std::cin >> s;
    _contact[_index].setFirstName(s);

    std::cout << "Lastmame: ";
    std::cin >> s;
    _contact[_index].setLastName(s);

    std::cout << "Nickname: ";
    std::cin >> s;
    _contact[_index].setNickName(s);

    _index += 1;
    _contactNumber = std::min(_contactNumber + 1, 8);
}

void    PhoneBook::printFormattedString(std::string s)
{
    int len;

    len = s.length();
    if (len >= 10)
    {
        for (int i = 0; i < 10 - 1; ++i)
            std::cout << s[i];
        std::cout << ".";
    }
    else
    {
        for (int i = 0; i < 10 - len; ++i)
            std::cout << " ";
        std::cout << s;
    }
}

void    PhoneBook::printContact(int index)
{
    if (index >= 8 || index < 0)
        return ;
    printFormattedString(std::to_string(index));
    std::cout << " | ";
    printFormattedString(_contact[index].getFirstName());
    std::cout << " | ";
    printFormattedString(_contact[index].getLastName());
    std::cout << " | ";
    printFormattedString(_contact[index].getNickName());
    std::cout << std::endl;
}

void    PhoneBook::search()
{
    int i;

    i = -1;
    while (++i < _contactNumber)
        printContact(i);
}

void    PhoneBook::quit()
{
    exit(EXIT_SUCCESS);
}
