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

    std::cout << "Phone Number: ";
    std::cin >> s;
    _contact[_index].setPhoneNUmber(s);

    std::cout << "Secret: ";
    std::cin >> s;
    _contact[_index].setSecret(s);

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
    if (_contactNumber == 0 || index >= _contactNumber || index < 0)
        return ;
    std::cout << _contact[index].getFirstName() << std::endl;
    std::cout << _contact[index].getLastName() << std::endl;
    std::cout << _contact[index].getNickName() << std::endl;
    std::cout << _contact[index].getPhoneNumber() << std::endl;
    std::cout << _contact[index].getSecret() << std::endl;
    
}

void    PhoneBook::printContacts()
{
    for (int i = 0; i <_contactNumber; i++)
    {
        printFormattedString(std::to_string(i));
        std::cout << " | ";
        printFormattedString(_contact[i].getFirstName());
        std::cout << " | ";
        printFormattedString(_contact[i].getLastName());
        std::cout << " | ";
        printFormattedString(_contact[i].getNickName());
        std::cout << std::endl;
    }
}

void    PhoneBook::search()
{
    int n;

    printContacts();
    std::cout << "Choose the contact to print : ";
    std::cin >> n;
    printContact(n);
}

void    PhoneBook::quit()
{
    exit(EXIT_SUCCESS);
}
