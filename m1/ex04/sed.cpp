#include "sed.hpp"

int sed(std::string filename, std::string s1, std::string s2)
{
    std::ifstream   input;
    std::ofstream   output;
    std::string     line;

    input.open(filename);
    if (!input)
    {
        std::cout << "The file \"" << filename << "\" couldn't be opened" << std::endl;
        return (1);
    }

    output.open(filename.append(".replace"));
    if (!output)
    {
        std::cout << "The file \"" << filename << "\" couldn't be created" << std::endl;
        input.close();
        return (1);
    }

    while (input.is_open())
    {
        while (std::getline(input, line))
            output << ((line == s1) ? s2 : line) << std::endl;
        input.close();
    }

    return (0);
}
