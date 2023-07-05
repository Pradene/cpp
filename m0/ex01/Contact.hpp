#ifndef CONTACT
#define CONTACT

#include <string>

class Contact
{
public:
    Contact() {};
    ~Contact() {};

    std::string    getFirstName();
    std::string    getLastName();
    std::string    getNickName();
    std::string    getPhoneNumber();
    std::string    getSecret();

    void    setFirstName(std::string s);
    void    setLastName(std::string s);
    void    setNickName(std::string s);
    void    setPhoneNUmber(std::string s);
    void    setSecret(std::string s);

private:
    std::string    _firstname;
    std::string    _lastname;
    std::string    _nickname;
    std::string    _phonenumber;
    std::string    _secret;
};

#endif