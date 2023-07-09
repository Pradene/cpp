#ifndef PHONEBOOK
#define PHONEBOOK

#include <iostream>
#include <string>

#include "Contact.hpp"

class PhoneBook
{
public:
    PhoneBook();
    ~PhoneBook();
    
    void    quit();
    void    printFormattedString(std::string s);
    void    printContacts();
    void    printContact(int index);
    void    search();
    void    add();

private:
    Contact _contact[8];
    int     _index = 0;
    int     _contactNumber = 0;
};

#endif