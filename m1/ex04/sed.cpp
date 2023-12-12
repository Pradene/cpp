#include "sed.hpp"

int sed(std::string filename, std::string s1, std::string s2)
{
    std::ifstream   input;
    std::ofstream   output;
    std::string     line;
    std::string     tmp;

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

    while (std::getline(input, tmp))
        line.append(tmp + "\n");

    size_t  pos;

    pos = line.find(s1);

    while (pos > 0 && pos < line.length()) {
        std::cout << pos << std::endl;
        line.replace(pos, s1.length(), s2);
        pos = line.find(s1);
    }

    output << line;
    
    input.close();
    output.close();

    return (0);
}
