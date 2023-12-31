#include "Contact.hpp"

// CONSTRUCTOR / DESTRUCTOR
Contact::Contact()
{
    std::cout << "Contact Default constructor called" << std::endl;
}

Contact::~Contact()
{
    std::cout << "Contact Default destructor called" << std::endl;
}



// GETTERS
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

std::string    Contact::getPhoneNumber()
{
    return (_phonenumber);
}

std::string    Contact::getSecret()
{
    return (_secret);
}



// SETTERS
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

void    Contact::setPhoneNUmber(std::string s)
{
    _phonenumber = s;
}

void    Contact::setSecret(std::string s)
{
    _secret = s;
}
