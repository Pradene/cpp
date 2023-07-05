#include "Contact.hpp"
#include "PhoneBook.hpp"

int main()
{
    PhoneBook   phoneBook;
    std::string s;

    while (1)
    {
        std::cout << "Enter an instruction : ";
        std::cin >> s;
        if (s == "")
            break ;
        if (!s.compare("ADD"))
            phoneBook.add();
        else if (!s.compare("SEARCH"))
            phoneBook.search();
        else if (!s.compare("EXIT"))
            phoneBook.quit();
        else
            std::cout << "Please enter a valid instruction" << std::endl;
        s.clear();
    }
    return (0);
}