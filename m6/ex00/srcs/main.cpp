#include "ScalarConverter.hpp"

int main(int ac, char *av[])
{
    std::string s;
    
    if (ac != 2)
        return (1);
    
    s = av[1];
    ScalarConverter::convert(s);
    return (0);
}
