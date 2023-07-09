#include <iostream>
#include <string>

int main()
{
    std::string s = "HI THIS IS BRAIN";
    std::string *ptr = &s;
    std::string &ref = s;

    std::cout << "String: " << &s << std::endl;
    std::cout << "Pointer: " << ptr << std::endl;
    std::cout << "Reference: " << &ref << std::endl;

    std::cout << std::endl;

    std::cout << "String: " << s << std::endl;
    std::cout << "Pointer: " << *ptr << std::endl;
    std::cout << "Reference: " << ref << std::endl;

    return (0);
}
