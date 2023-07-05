#include "Contact.hpp" 

std::string    Contact::getFirstName()
{
    return (_firstname);
}

std::string    Contact::getLastName()
{
    return (_lastname);
}

std::string    Contact::getNickName()
{
    return (_nickname);
}

void    Contact::setFirstName(std::string s)
{
    _firstname = s;
}

void    Contact::setLastName(std::string s)
{
    _lastname = s;
}

void    Contact::setNickName(std::string s)
{
    _nickname = s;
}

